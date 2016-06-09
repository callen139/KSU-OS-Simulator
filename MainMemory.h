#include <iostream>

using namespace std;

class MainMemory
{
    public:
      void RAM();
      void RunR();
};

void RAM()
{
    int k =1024;
    int memoryarray[k];
    //memoryarray={populate RAM};
    for(int i=0; i<k; i++)
    {
        memoryarray[i] = i;
        cout << memoryarray[i] << endl;    
    }
}

void RunR()
{
    cout << "RAM() is being called now" << endl;
    RAM();
    cout << "RAM() completed" << endl;
}