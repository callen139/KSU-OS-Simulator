// This is the Loader

#include <iostream>
#include <fstream>
using namespace std;

ifstream InputFile;
ofstream OutputFile;
int JobInstructionLengths[30];
int JobNumber;
int DataLength = 44;

class Loader
{
    public: 
        void RunL();
        void ReadInputFileAndPopulateOutputFile();
        void GetAttributesFromJobsInDiskAndPopulateRAM();
        void PopulateJobInstructionLengthsArray();
        void InsertHexFromDiskToRAM();
        int GetJobInstructionLength(int JobNumber);
        int GetJobInstructionLengthAndDataLength(int JobNumber);
        int GetLineNumberOfJobStartInRAM(int JobNumber);
        int GetLineNumberOfJobDataStartInRAM(int JobNumber);
};

void Loader::ReadInputFileAndPopulateOutputFile()
{
    string line;
    InputFile.open("Instructions.txt");
	if (InputFile.is_open())
	{
	    OutputFile.open("Disk.txt");
	    if (OutputFile.is_open())
	    {
    	    cout << "It opened the Disk.txt file" << endl;
    	    while (getline (InputFile, line))
    	    {
    	        OutputFile << line << "\n";
    	    }
    	    InputFile.close();
    	    OutputFile.close();
	    }
	}
}

void Loader::GetAttributesFromJobsInDiskAndPopulateRAM()
{
    string line;
    InputFile.open("Disk.txt");
    if (InputFile.is_open())
    {
        OutputFile.open("PCB.txt");
        if (OutputFile.is_open())
        {
            cout << "GetAttributes is starting" << endl;
        	while (getline (InputFile, line))
            {
                if (line.substr(0, 4) == "// J")
                {
                    OutputFile << line.substr(9) << "\n";
                }
                
            }
            cout << "The while loop ends at this point" << endl;
        }
        InputFile.close();
    	OutputFile.close();
    }
}

int FindJobProcessNumber(int LineNumber)
{
    string line;
    int count = 0;
    int inbuff = 20;
    int outbuff =12;
    int tempbuff = 12;
    string InstructionAmountHex = "";
    InputFile.open("PCB.txt");
    if (InputFile.is_open())
    {
        cout << "PCB.txt is open" << endl;
        while (getline (InputFile, line))
        {
            //cout << count << endl;
            //cout << LineNumber << endl;
            if (count == LineNumber)
            {
                if (line.substr(0,1) != " ")
                {
                    InstructionAmountHex = line.substr(0,2);
                    break;
                }
                else
                {
                    InstructionAmountHex = line.substr(1,3);
                    break;
                }
            }
            count++; 
        }
        cout << InstructionAmountHex << endl;
        unsigned int InstructionAmountDec = strtoul(InstructionAmountHex.c_str(), NULL, 16);
        cout << InstructionAmountDec << endl;
        cout << inbuff << endl;
        cout << outbuff << endl;
        cout << tempbuff << endl;
        cout << "------------ End of FindJobProcessNumber ----------" << endl;
        
        InputFile.close();
        return InstructionAmountDec;
    }
}

void Loader::PopulateJobInstructionLengthsArray()
{
    for (int ProcessNumber = 0; ProcessNumber < 30; ProcessNumber++)
    {
        JobInstructionLengths[ProcessNumber] = FindJobProcessNumber(ProcessNumber);
        cout << ProcessNumber + 1 << endl;
        cout << JobInstructionLengths[ProcessNumber] << endl;
    }
    cout << "------------- End of PopulateJobInstructionLengthsArray -------------" << endl;
}

void Loader::InsertHexFromDiskToRAM()
{
    string line;
    InputFile.open("Disk.txt");
	if (InputFile.is_open())
	{
	    OutputFile.open("RAM.txt");
	    if (OutputFile.is_open())
	    {
    	    cout << "It opened the RAM.txt file" << endl;
    	    while (getline (InputFile, line))
    	    {
    	        if(line.substr(0,2) != "//")
    	        {
    	            OutputFile << line.substr(2) << "\n";
    	        }
    	    }
    	    InputFile.close();
    	    OutputFile.close();
	    }
	}
	cout << "------------- End of InsertHex ---------" << endl;
}

int Loader::GetJobInstructionLength(int JobNumber)
{
    return JobInstructionLengths[JobNumber];
}

int Loader::GetJobInstructionLengthAndDataLength(int JobNumber)
{
    return JobInstructionLengths[JobNumber] + DataLength;
}

int Loader::GetLineNumberOfJobStartInRAM(int JobNumber)
{
    int lineCount = 0;
    if (JobNumber < 30)
    {
        for (int CurrentJob = 0; CurrentJob < JobNumber - 1; CurrentJob++)
        {
            lineCount += GetJobInstructionLengthAndDataLength(CurrentJob);
        }
        return lineCount;
    }
    else
    {
        return lineCount + 1;
    }
}

int Loader::GetLineNumberOfJobDataStartInRAM(int JobNumber)
{
    int lineCount = 0;
    if (JobNumber < 30)
    {
        for (int CurrentJob = 0; CurrentJob < JobNumber - 1; CurrentJob++)
        {
            lineCount += GetJobInstructionLengthAndDataLength(CurrentJob);
        }
        return lineCount + JobInstructionLengths[JobNumber];
    }
    else
    {
        return JobInstructionLengths[0];
    }
}

void Loader::RunL()
{
    Loader load;
    cout << "This is something" << endl;
    
    load.ReadInputFileAndPopulateOutputFile();
    
    cout << "ReadFile() Worked!" << endl;
    
    cout << "GetAttributes is called" << endl;
    
    load.GetAttributesFromJobsInDiskAndPopulateRAM();
    
    cout << "GetAttributes Worked!!!!" << endl;
    
    cout << "PopulateJobInstructionLengthsArray started" << endl;
    
    load.PopulateJobInstructionLengthsArray();
    
    cout << "PopulateJobInstructionLengthsArray completed" << endl;
    
    cout << "InsertHex Started" << endl;
    
    load.InsertHexFromDiskToRAM();
    
    cout << "InsertHex completed" << endl;
    
    cout << "This is the JobInstructionLength for Job 3: " << load.GetJobInstructionLength(2) << endl;
    
    cout << "This is the JobInstructionLengthAndDataLength for job 3: " << load.GetJobInstructionLengthAndDataLength(2) << endl;
}