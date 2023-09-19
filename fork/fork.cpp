#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

int main() {
    cout << "Hi, Welcome to the demo on fork()" << endl;

    int child_pid = fork();
    int c_pid = fork();
    // int child_pid = rand() % 100;
    if(child_pid == -1) {
        cout<<"Error : Cannot fork()";
        return 0;
    }
    else if(c_pid == -1) {
        cout<<"Error : Cannot fork()";
        return 0;
    }
     else if(child_pid == 0 && c_pid == 0) {
        //child process code
        cout <<"c_pid "<<c_pid<<" "<<"from main process child_pid(return of fork)"<<child_pid <<" "<< " In the child process " << getpid() <<  " created by " << getppid() << " using fork" << endl;
    } else if (child_pid == 0 && c_pid != 0){
        cout <<"c_pid "<<c_pid<<" "<<"from main process child_pid(return of fork)"<<child_pid <<" "<< " In the child process of main " << getpid() <<  " created by " << getppid() << " using fork" << endl;
    } else if (child_pid != 0 && c_pid == 0){
        cout <<"c_pid "<<c_pid<<" "<<"from main process child_pid(return of fork)"<<child_pid <<" "<< " In the child process of main" << getpid() <<  " created by " << getppid() << " using fork" << endl;
    } else {
        cout <<"c_pid "<<c_pid<<" "<<"from main process child_pid(return of fork)"<<child_pid <<" "<< " In the parent process " << getpid() <<  " created by " << getppid() << " using fork" << endl;
    }
    return 0;
}