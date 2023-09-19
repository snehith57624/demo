#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

int main() {
    cout << "Hi I am client" << endl;
    
    // Print the PID and PPID
    cout << "client PID: " << getpid() << " client PPID: " << getppid() << endl;
}