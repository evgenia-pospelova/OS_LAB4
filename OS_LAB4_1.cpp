// OS_LAB4_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char* argv[])
{
    cout << "There are " << argc << " arguments:\n";

    for (int count = 0; count < argc; count++){
        cout << count << ". " << argv[count] << '\n';
        cout.flush();
        Sleep(1);
    }

    cout << endl << "Labs id: " << getpit() << endl;
    cout << "Labs parent id: " << getppid() << endl;
    exit(31);
}
