#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>  // Include this for strlen
#include <sys/wait.h>  // Include this for wait
#include <fcntl.h> 


int main() {
    int file_descriptor = open("sample.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    
    if (file_descriptor == -1) {
        perror("open");
        return 1;
    }
    
    // Duplicate file_descriptor to stdout (file descriptor 1)
    if (dup2(file_descriptor, 1) == -1) {
        perror("dup2");
        return 1;
    }

    // Now, anything written to stdout will be written to "sample.txt"
    printf("This will be written to sample.txt\n");
    
    close(file_descriptor);
    
    return 0;
}
