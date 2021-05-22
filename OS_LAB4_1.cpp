
#include <iostream>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[])
{
    cout << "There are " << argc << " arguments:\n";

    for (int count = 0; count < argc; count++){
        cout << count << ". " << argv[count] << '\n';
        cout.flush();
        sleep(1);
    }

    cout << endl << "Labs id: " << getpid() << endl;
    cout << "Labs parent id: " << getppid() << endl;
    exit(31);
}
