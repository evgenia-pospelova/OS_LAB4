#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


using namespace std;


int child(void *args){
    cout << "Дочерний идентификатор: " << getpid() << endl;
    cout << "Родительский идентификатор: " << getppid() << endl;
    char *const arg2[] = {(char*)"OS_LAB4_2",(char*) "arg1", (char*) "arg2", 0};
    execvpe("OS_LAB4_2",arg2, NULL);

    return 0;
}

int main(int argc, char* argv[])
{
    char* stack = (char*)malloc(16553);
    char* arguments[] = {(char*)"OS_LAB4_2",(char*) "arg1", (char*) "arg2", nullptr};
    int child_processId = clone(child, stack, SIGCHLD, arguments);
    int status;

    cout << "Идентификатор: " << getpid() << endl;


    while(waitpid(child_processId,&status,WNOHANG) == 0){
            usleep(500000);
        }
    if (WIFEXITED(status)){
            cout << "Status of OS_LAB4_3: " << WEXITSTATUS(status) << endl;
        } else {
            cout << "Status of OS_LAB4_3: ERROR!";
        }


    return 0;

}

