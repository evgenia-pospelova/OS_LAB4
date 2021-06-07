#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


using namespace std;

int main(int argc, char* argv[])
{

    int status;
    char *const arg[] = {(char*)"OS_LAB4_2",(char*) "arg1", (char*) "arg2", 0};

    cout << "Идентификатор: " << getpid() << endl;
    int child_processId = fork();

    if(child_processId == 0){
        cout << "Дочерний идентификатор: " << getpid() << endl;
        cout << "Родительский идентификатор: " << getppid() << endl;
        execvpe("OS_LAB4_2",arg, NULL);
    } else {

        while(waitpid(child_processId,&status,WNOHANG) == 0){
            usleep(500000);
        }
        if (WIFEXITED(status)){
            cout << "Status of OS_LAB4_2: " << WEXITSTATUS(status) << endl;
        } else {
            cout << "Status of OS_LAB4_2: ERROR!";
        }
    }
    return 0;

}
