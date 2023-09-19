#include <string>
using namespace std;

int main(int argc, char *argv[]) {

    printf("The program name is: %s\n", argv[0]);
    
    printf("Number of arguments (argc): %d\n", argc);
    
    // Loop through the command-line arguments (starting from argv[1])
    for (int i = 1; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }

    return 0;
}