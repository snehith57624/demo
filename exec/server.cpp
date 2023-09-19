#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

int main() {
    
    cout << "Hi I am server" << endl;
    
    // Print the PID and PPID
    cout << "server PID: " << getpid() << " server PPID: " << getppid() << endl;
    
}