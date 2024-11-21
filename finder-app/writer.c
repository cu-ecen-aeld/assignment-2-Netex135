#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <syslog.h>
#include <string.h>

int main(int argc, char *argv[]) { 
	openlog(NULL,0,LOG_USER);
	FILE *fd;

	//open file here 
	if(argc != 3){
		//throw usage arnning 
		syslog(LOG_ERR, "ERROR WRONG NUMBER OF ARGS EXPECTED 2 GOT: %i\n", argc);
		closelog();
		return(1);
	}

	syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);
	fd = fopen(argv[1], "w+b");
	if (fd == NULL){
		syslog(LOG_ERR, "ERROR: could not write or open file: '%s'", argv[1]);
		closelog();
		return(1);

	}
	int nr = fprintf(fd,"%s\n", argv[2]);
	
	if (nr == 0){ 
			syslog(LOG_ERR,"ERROR: file not made %s\n", strerror( errno ));
			closelog();
			fclose(fd);
			return(1);	
			}

	closelog();
	fclose(fd);
	return(0);

}
