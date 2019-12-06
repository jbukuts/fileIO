#include <iostream>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <stdio.h> 
#include <fcntl.h> 
#include <errno.h> 
#include <ctype.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/stat.h>
#include <sys/mman.h>
using namespace std;

#include "three.h"

int main(int argc, char* argv[]) {

    // ensure all args are there
    if(argc != 2) {
        perror("Please specify the file path!");
        exit(-1);
    }

    char* file_path = argv[1];

    // open the file
	int fd = open(file_path, O_RDWR);
    size_t size = lseek(fd, 0, SEEK_END);

    // map file to char array
    char *file = (char *)mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);

    // ensure no fail
    if (file == MAP_FAILED){
        printf("mmap error\n");
    }

    // show the old file
    printf("OLD FILE:\n%s\n",file);

    // edit the file
    for (size_t i=0;i<size;++i) {
        // swap case
        char c=file[i];
        if (isupper(c)) 
            file[i] = tolower(c);
        else
            file[i] = toupper(c);
    }

    // print current file status
    // printf("NEW FILE:\n%s\n",file);

    // unmap and close the file
    munmap(file, size);
    close(fd);
    printf("CLOSED THE FILE\n");

    return 0;
}

