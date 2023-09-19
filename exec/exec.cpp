#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

int main() {
    cout << "Hi I am exec" << endl;

    char *program_name = (char*) "./server"; // The program to execute
    char *args[] = {program_name, NULL}; // Command-line arguments

    // int ret = 0;
    int ret = execvp(program_name, args);

    // Execute the program
    if (ret == -1) {
        perror("execvp");
        exit(EXIT_FAILURE);
    }

    // This code is never reached if execvp is successful
    cout << "This will not be printed\n" << endl;
    return 0;
}