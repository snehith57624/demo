#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>  // Include this for strlen
#include <sys/wait.h>  // Include this for wait

int main() {
    int pipefd[2];
    char buffer[20];
    
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    // Create a child process
    pid_t pid = fork();


    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        // Child process: Close the write end of the pipe
        close(pipefd[1]);

        // Read from the pipe
        ssize_t bytes_read = read(pipefd[0], buffer, sizeof(buffer));
        if (bytes_read > 0) {
            printf("Child received: %.*s\n", (int)bytes_read, buffer);
        }

        // Close the read end of the pipe
        close(pipefd[0]);
        exit(0);
    } else {
        // Parent process: Close the read end of the pipe
        close(pipefd[0]);

        // Write to the pipe
        const char* message = "Hello, child!";
        write(pipefd[1], message, strlen(message));

        // Close the write end of the pipe
        close(pipefd[1]);

        // Wait for the child to finish
        wait(NULL);
    }

    return 0;
}
