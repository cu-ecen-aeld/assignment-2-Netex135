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
	if(argc != 2){
		//throw usage arnning 
		syslog(LOG_ERR, "ERROR WRONG NUMBER OF ARGS EXPECTED 2 GOT: %i\n", argc);
		return(1);
	}
  
	printf("here line 20");
	syslog(LOG_DEBUG, "Writing %s to %s", argv[0], argv[1]);
	fd = fopen(argv[0], "w+b");
	int nr = fprintf(fd,"%s\n", argv[1]);
	
	printf("here line 25");
	if (nr == 0){ 
			syslog(LOG_ERR,"ERROR: file not made %s\n", strerror( errno ));
			return(1);	
			}
	printf("here line 30"):
	fclose(fd);
	return(0);
}
