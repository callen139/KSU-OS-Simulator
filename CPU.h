// This is the CPU

//#include <ofstream>
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
using namespace std;

ifstream bluefile;
ofstream redfile;

class CPU
{
    public:
        void DMAChannel();
        void ComputeOnly();
        string hex2bin();
        void RunC();
};

void CPU::DMAChannel()
{
    


}


void CPU::ComputeOnly()
{


    
}

string hex2bin(string hexString){
   
    int i=0;
    char *hexaDecimal[8];
    string *binArray[8];
    string endBinary;
    int finalInt;
    
    unsigned int InstructionDec = strtoul(hexString.c_str(), NULL, 16);
    
    strcpy(hexaDecimal,hexString.c_str());

    //sound logic, flawed implimentation

    while(hexaDecimal[i])
    {
         switch(hexaDecimal[i])
         {
             case '0': binArray[i] = {"0000"}; cout<<"0000"; break;
             case '1': binArray[i] = {"0001"}; cout<<"0001"; break;
             case '2': binArray[i] = {"0010"}; cout<<"0010"; break;
             case '3': binArray[i] = {"0011"}; cout<<"0011"; break;
             case '4': binArray[i] = {"0100"}; cout<<"0100"; break;
             case '5': binArray[i] = {"0101"}; cout<<"0101"; break;
             case '6': binArray[i] = {"0110"}; cout<<"0110"; break;
             case '7': binArray[i] = {"0111"}; cout<<"0111"; break;
             case '8': binArray[i] = {"1000"}; cout<<"1000"; break;
             case '9': binArray[i] = {"1001"}; cout<<"1001"; break;
             case 'A': binArray[i] = {"1010"}; cout<<"1010"; break;
             case 'B': binArray[i] = {"1011"}; cout<<"1011"; break;
             case 'C': binArray[i] = {"1100"}; cout<<"1100"; break;
             case 'D': binArray[i] = {"1101"}; cout<<"1101"; break;
             case 'E': binArray[i] = {"1110"}; cout<<"1110"; break;
             case 'F': binArray[i] = {"1111"}; cout<<"1111"; break;
             case 'a': binArray[i] = {"1010"}; cout<<"1010"; break;
             case 'b': binArray[i] = {"1011"}; cout<<"1011"; break;
             case 'c': binArray[i] = {"1100"}; cout<<"1100"; break;
             case 'd': binArray[i] = {"1101"}; cout<<"1101"; break;
             case 'e': binArray[i] = {"1110"}; cout<<"1110"; break;
             case 'f': binArray[i] = {"1111"}; cout<<"1111"; break;
             default:  cout<<"nInvalid hexadecimal digit "<<hexaDecimal[i];
         }
         
         i++;
    }
    endBinary = binArray[0]+binArray[1]+binArray[2]+binArray[3]
                +binArray[4]+binArray[5]+binArray[6]+binArray[7];
                
    //sound logic, flawed implementation
    
    return endBinary;
}

void CPU::RunC()
{
    CPU load;
    string DMA;
    string line;
    string binCode;
    bluefile.open("RAM.txt");
    
    if (bluefile.is_open())
    {
        redfile.open("IObintemp.txt");
        if (redfile.is_open()){
        while (getline(bluefile, line))
        {
            //hex to binary conversion    
           binCode = hex2bin(line);
          
            //flawed logic; rewrite to read hex2bin conversion
            redfile << binCode << "\n";
            if(binCode.substr(0,1)=="11")
            {
                load.DMAChannel();
            }
            else{
                load.ComputeOnly();
            }
            
        }
        }
        bluefile.close();
        redfile.close();
    }
}