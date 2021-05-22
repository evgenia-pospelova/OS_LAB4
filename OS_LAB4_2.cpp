
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


using namespace std;

int main(int argc, char* argv[], char *envp[])
{
    int child_processId = fork();
    int status;
    char *const arg[] = {(char*)"OS_LAB4_2",(char*) "arg1", (char*) "arg2", nullptr};

    if(child_processId == 0){
        cout << "Labs child id: " << getpid() << endl;
        execvpe("OS_LAB4_2",arg, envp);
    } else {
        cout << endl << "Labs id: " << getpid() << endl;
        cout << "Labs parent id: " << getppid() << endl;

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
