#include <iostream>
#include <fstream>
using namespace std;

ifstream InputInfo;
ofstream OutputInfo;

class Dispacher
{
    
    int Job1 = 0;
    int Job2 = 0;
    int Job3 = 0;
    int Job4 = 0;
    int Job5 = 0;
    string PCBHex = "";
    int LineNumberD;
    int count = 0;
    
    public:
        void ReadInfo();
        void GetAtt();
        void ContextSwitch();
        void PopulateBuffer(int JobNumber);
        void RunD();
      
};

void Dispacher::ReadInfo()
{
    string line;
    InputInfo.open("PCB.txt");
    if(InputInfo.is_open()) 
    {
        int PCBArray[29];
        
        cout << "Arrays have been created" << endl;
        while(getline(InputInfo, line))
        {
            if(count == LineNumberD)
            {
                if(line.substr(0,1) != " ")
                {
                    PCBHex = line.substr(0,2);
                    break;
                }
                else
                {
                    PCBHex = line.substr(1,3);
                    break;
                }
            }
        }
        for( int x = 0; x <= 29; x++)
        {
            cout << x << endl;
        }
    }
}

void Dispacher::GetAtt()
{
    
}

void Dispacher::ContextSwitch()
{
    for( int i = 0; i <=20; i++ )
    {
        if(i == 1)
        {
            //Job1.Run();
        }
        else if(i == 2)
        {
            //Job1.terminate();
            //Job2.Run();
            cout << "Job 1 is finished" << endl;
   
        }
        else if(i == 3)
        {
            //Job2.terminate();
            // Job3.Run();
            cout << "Job 2 is finished" << endl;
 
        }
        else if(i == 4)
        {
            //Job3.terminate();
            // Job4.Run();
            cout << "Job 3 is finished" << endl;
          
        }
        else if(i == 5)
        {
            //Job4.terminate();
            //Job5.Run();
            cout << "Job 4 is finished" << endl;
            
        }
        else if(i == 6)
        {
            //Job5.terminate();
            //Job6.Run();
            cout << "Job 5 is finished" << endl;
            
        }
        else if(i == 7)
        {
            //Job6.terminate();
            //Job7.Run();
            cout << "Job 6 is finished" << endl;
            
        }
        else if(i == 8)
        {
            //Job7.terminate();
            //Job6.Run();
            cout << "Job 7 is finished" << endl;
            
        }
        else if(i == 9)
        {
            //Job8.terminate();
            //Job9.Run();
            cout << "Job 8 is finished" << endl;
            
        }
        else if(i == 10)
        {
            //Job9.terminate();
            //Job10.Run();
            cout << "Job 9 is finished" << endl;
            
        }
        else if(i == 11)
        {
            //Job10.terminate();
            //Job11.Run();
            cout << "Job 10 is finished" << endl;
            
        }
        else if(i == 12)
        {
            //Job11.terminate();
            //Job12.Run();
            cout << "Job 11 is finished" << endl;
            
        }
        else if(i == 13)
        {
            //Job12.terminate();
            //Job13.Run();
            cout << "Job 12 is finished" << endl;
            
        }
        else if(i == 14)
        {
            //Job13.terminate();
            //Job14.Run();
            cout << "Job 13 is finished" << endl;
            
        }
        else if(i == 15)
        {
            //Job14.terminate();
            //Job15.Run();
            cout << "Job 14 is finished" << endl;
            
        }
        else if(i == 16)
        {
            //Job15.terminate();
            //Job16.Run();
            cout << "Job 15 is finished" << endl;
            
        }
        else if(i == 17)
        {
            //Job16.terminate();
            //Job17.Run();
            cout << "Job 16 is finished" << endl;
            
        }
        else if(i == 18)
        {
            //Job17.terminate();
            //Job18.Run();
            cout << "Job 17 is finished" << endl;
            
        }
        else if(i == 19)
        {
            //Job18.terminate();
            //Job19.Run();
            cout << "Job 18 is finished" << endl;
            
        }
        else if(i == 20)
        {
            //Job19.terminate();
            //Job20.Run();
            cout << "Job 19 is finished" << endl;
            
        }
        
    }
} 

void Dispacher::PopulateBuffer(int JobNumber)
{
    
}

void Dispacher::RunD()
{
    ReadInfo();
    ContextSwitch();
}

/*int main()
{
    Dispatcher Go;
    Go.RunD();
   
}*/