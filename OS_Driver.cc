// This is the OS Driver

#include <iostream>
#include "Scheduler.h"
#include "Loader.h"
//#include "CPU.h"
#include "Dispacher.h"
using namespace std;

int terminal = 0;

void loader()
{
    cout << "This is the loader" << endl;    
    Loader loader1;
    loader1.RunL();
}

void scheduler()
{
    cout << "Scheduler" << endl;
    Scheduler scheduler1;
    scheduler1.RunS();
}

void dispacher()
{
    cout << "Dispacher" << endl;
    Dispacher dispatcher1;
    dispatcher1.RunD();
}

void CPU()
{
    cout << "CPU" << endl;
    //CPU cpu1;
    //cpu1.RunC();
}

void waitforinterrupt()
{
    cout << "Wait For Interrupt" << endl;
    cout << "Enter 1 to kill program, or enter another int to repeat" << endl;
    
    cin >> terminal;
    
    if (terminal == 1)
    {
        cout << "Goodbye!" << endl;
    }
    
    else
    {
        cout << "One more time!" << endl;
    }
}

int main()
{
    loader();
    
    while (terminal != 1)
    {
        scheduler();
        dispacher();
        //CPU();
        waitforinterrupt();
    }
    
    return 0;
}