#include <iostream>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <stdio.h> 
#include <fcntl.h> 
#include <errno.h> 
#include <ctype.h>
#include <stdlib.h>
using namespace std;

#include "two.h"

int main(int argc, char* argv[]) {

	// ensure all args are there
    if(argc != 2) {
        perror("Please specify the file path!");
        exit(-1);
    }

    char* file_path = argv[1];

	// open files
	FILE * fd;
    fd = fopen (file_path,"rw+");

    // to store the entire file
	char * buffer;

    // get size of the file
    fseek (fd , 0 , SEEK_END);
    long size = ftell(fd);
    rewind(fd);

    // allocate memory for buffer as size of file
    buffer = (char*) malloc (sizeof(char)*size);

    // dump file into the buffer
    size_t result = fread (buffer,1,size,fd);

    if (result < 0) {
        printf("READ ERROR!\n");
        exit(-1);
    }

    printf("OLD FILE:\n%s\n",buffer);

    // switch letters from uppercase to lowercase
    for (int i=0;i<size;++i) {
        char c=buffer[i];
        if (isupper(c)) 
            buffer[i] = tolower(c);
        else
            buffer[i] = toupper(c);
    }

    // back to the beginning
    fseek (fd,0,SEEK_SET );
    // write to output file
    fwrite (buffer , sizeof(char), sizeof(char)*size, fd);

    // close the files
    fclose(fd);
 
    // free memory
    free(buffer);

    printf("CLOSED THE FILE\n");
    return 0;
   
}

