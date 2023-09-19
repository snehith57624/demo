// CPP program to illustrate dup()
#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	// open() returns a file descriptor file_desc to a
	// the file "dup.txt" here"

	int file_desc = open("sample.txt", O_WRONLY | O_APPEND);
	
	if(file_desc < 0)
		printf("Error opening the file\n");
	
	// dup() will create the copy of file_desc as the copy_desc
	// then both can be used interchangeably.
    int filefd[2];
    if (pipe(filefd) == -1){
        // error handling
    }

    // dup2(standard output, file_desc)


    // parent and a child
    // pid = fork()
        // if pid == 0 // child process
            // c_pid = fork() // new child (grand child for parent)
            // filefd[0] -> read and filefd[1] -> read
            // we gonna run ls -al for the first process
            // pass all the output of first process from standard output to file descriptor specified
            // tr a-z A-Z
            // will use the file descriptor to read the file and use as the input and generates the output
            
        // another q


	// int copy_desc = dup(file_desc);
    // int copy_desc = file_desc;
		
	// write() will write the given string into the file
	// referred by the file descriptors
    int pid = fork();
    if(pid == 0){
        write(file_desc,"This will be output to the file named dup.txt\n", 46);
    } else if (pid == -1){
        printf("error");

    } else{
        write(file_desc,"This will also be output to the file named dup.txt\n", 51);
    }

	// write(copy_desc,"This will be output to the file named dup.txt\n", 46);
		
	// write(file_desc,"This will also be output to the file named dup.txt\n", 51);
	
	return 0;
}
