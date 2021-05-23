
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


using namespace std;

int child(void *args){
    char** arg = (char**) args;
    execvpe(arg[0], arg, NULL);
    return 0;

}

int main(int argc, char* argv[], char *envp[])
{
    char* stack = (char*)malloc(1048576);
    char* arguments[] = {(char*)"OS_LAB4_2",(char*) "arg1", (char*) "arg2", nullptr};
    int child_processId = clone(child, stack, SIGCHLD, arguments);
    int status;
    if(child_processId == 0){
        cout << "Labs child id: " << getpid() << endl;
        execvpe("OS_LAB4_2",arguments, envp);
    } else {
        cout << endl << "Labs id: " << getpid() << endl;
        cout << "Labs parent id: " << getppid() << endl;
        cout << "Labs child id: " << child_processId << endl;


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
