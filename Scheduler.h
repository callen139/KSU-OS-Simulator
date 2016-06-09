// This is the scheduler

#include <iostream>
using namespace std;

class Scheduler
{
	int NumberOfProcesses = 30;
	
	public:
		void FirstComeFirstServe();
		void GetPriority();
		void RunS();
};


void Scheduler::FirstComeFirstServe()
{
	cout << "This might work eventually" << endl;
	cout << NumberOfProcesses << endl;
}

void Scheduler::GetPriority()
{
	int Priorities [29]; 
	cout << "This could work too, we'll see" << endl;
}

void Scheduler::RunS()
{
	FirstComeFirstServe();
	GetPriority();
}

/*int main()
{
	Scheduler ScheduleTestObjectDontWorryTooMuchAboutIt;
	
	ScheduleTestObjectDontWorryTooMuchAboutIt.Run();
}*/