#include <iostream>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <stdio.h> 
#include <fcntl.h> 
#include <errno.h> 
#include <ctype.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
using namespace std;

#include "one.h"

int main(int argc, char* argv[]) {

    // ensure all args are there
    if(argc != 2) {
        perror("Please specify the file path!");
        exit(-1);
    }

    char* file_path = argv[1];


	// open files
	int fd = open(file_path, O_RDWR);

	// ensure files are opened properly
	if (fd == -1) 
    	printf("Error Number % d\n", errno); 


    // get the size of the file
    struct stat myStat = {};
    if (fstat(fd, &myStat)){
        printf("fstat error\n");
    }
    off_t size = myStat.st_size;

    // throw the file into the char buffer
    char * buffer = (char*) malloc (sizeof(char)*size);
    size_t result = read(fd,buffer,size);

    if (result < 0) {
        printf("READ ERROR!\n");
        exit(-1);
    }


    printf("OLD FILE:\n%s\n",buffer);

    // switch letters from uppercase to lowercase
    for (int i=0;i<size;++i) {
        // swap case
        char c=buffer[i];
        if (isupper(c)) 
            buffer[i] = tolower(c);
        else
            buffer[i] = toupper(c);
    }

    // reset seek and write the buffer in the file
    lseek(fd, 0, 0);
    write(fd,buffer,size);

 
	// close the file 
    if (close(fd) < 0)  
        exit(1); 

    // free the buffer
    free(buffer);

    printf("CLOSED THE FILE\n");
    return 0;
   
}

