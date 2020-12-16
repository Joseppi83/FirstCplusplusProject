#include <iostream>
#include <ios>
#include <iomanip>
#include <Windows.h>	//Package needed to capture key input and sleep for Windows
#include <unistd.h>		//Package needed to capture key input and sleep for Mac/Linux
#include <string>
using namespace std;

//InsertNewLine adds a newline character between old and new output
void InsertNewLine() {
	cout << '\n';
}

//GetTime called for both 12-Hour and 24-Hour clock output values
//In OutputTime, the 12-Hour clock output value is manipulated with if checks
//To Begin, all values filled with zeroes
void GetTime(int hours, int minutes, int seconds) {
	cout << setw(2) << setfill('0') << hours << ":";
	cout << setw(2) << setfill('0') << minutes << ":";
	cout << setw(2) << setfill('0') << seconds;
}

//Printed displays for time output
void OutputTime(int currentTime) {
	int timeValue, hourValue, minuteValue, secondValue;

	InsertNewLine();

	//86400 is number of seconds in one day
	timeValue = currentTime % 86400;
	if(timeValue < 0) {
		timeValue = 0;
	}

	hourValue = (timeValue / 3600) % 24;
	minuteValue = (timeValue / 60) % 60;
	secondValue = timeValue % 60;

	//Top line of 12-hour display
	cout << setw(27) << setfill('*') << "";
	//12-hour and 24-hour display separated by 3 spaces
	cout << "   ";
	//Top line of 24-hour display
	cout << setw(27) << setfill('*') << "";
	cout << endl;
	//Heading for 12 and 24-hour displays
	cout << "*      12-Hour Clock      *   *      24-Hour Clock      *" << endl;

	//Line to display 12-Hour time
	cout << "*       ";
	//Following if checks are for 12-Hour Clock output
	if(hourValue == 12) {
		GetTime(hourValue, minuteValue, secondValue);
		cout << " PM";
	}
	else if(hourValue > 12) {
		GetTime((hourValue - 12) , minuteValue, secondValue);
		cout << " PM";
	}
	//Manipulates the initial 0 value to 12 AM for midnight
	else if(hourValue == 0) {
		GetTime(12, minuteValue, secondValue);
		cout << " AM";
	}
	else {
		GetTime(hourValue, minuteValue, secondValue);
		cout << " AM";
	}

	//String separating 12 and 24 times
	cout << "       *   *         ";

	//GetTime for 24-Hour Clock output
	GetTime(hourValue, minuteValue, secondValue);
	cout << "        *" << endl;
	//Bottom most fill lines for 12 and 24-hour displays
	cout << setw(27) << setfill('*') << "";
	//Separated by 3 spaces
	cout << "   ";
	cout << setw(27) << setfill('*') << "";
	cout << endl;
}

//This function fires, when the user hits ESC
int OutputMenuOptions() {
	int selectedOption;

	InsertNewLine();

	cout << setw(27) << setfill('*') << " " << endl;
	cout << "* 1 - Add One Hour        *" << endl;
	cout << "* 2 - Add One Minute      *" << endl;
	cout << "* 3 - Add One Second      *" << endl;
	cout << "* 4 - Exit Program        *" << endl;
	cout << setw(27) << setfill('*') << " " << endl;

	cin >> selectedOption;

	//Exception handling runtim_error thrown if user enters something other than 1-4
	if((selectedOption < 1) || (selectedOption > 4)) {
		throw runtime_error("Invalid selection.");
	}

	return selectedOption;
}

//This function fires, when the user enters 1-3 from the output menu options
int AddTimeUnit(int currentTime, int timeUnitSelection) {
	int newTime = currentTime;

	switch(timeUnitSelection) {
	//Add hour adds 3600 seconds
	case 1:
		newTime += 3600;
		break;
	//Add minute adds 60 seconds
	case 2:
		newTime += 60;
		break;
	//Add second adds 1 second
	case 3:
		newTime += 1;
		break;
	default:
		break;
	}

	newTime %= 86400;

	if(newTime < 0) {
		newTime = 0;
	}

	return newTime;
}
