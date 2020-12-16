/*
 * main.cpp
 *
 *  Created on: Nov 11, 2020
 *      Author: Joseph Collett
 */

#include <iostream>
#include <ios>
#include <iomanip>
#include <Windows.h>	//Package needed to capture key input and sleep for Windows
#include <unistd.h>		//Package needed to capture key input and sleep for Mac/Linux
#include <string>

#include "ClockFunctions.h"

using namespace std;

int main() {
	//User Input assigned to 0 to begin while loop
	int userInput = 0;
	//Current time assigned to midnight
	int currTime = 0;

	cout << "Press ESC to display menu options." << endl;
	//Sleep causes the one second delay in output
	sleep(1);

	OutputTime(currTime);

	while(userInput != 4) {
		//Async function to capture if user hits ESC key
		if(GetAsyncKeyState(VK_ESCAPE)) {
			//Exception handling specified in OutputMenuOptions function
			try {
				userInput = OutputMenuOptions();
				currTime = AddTimeUnit(currTime, userInput);
			}
			catch(runtime_error & excpt) {
				//If exception is caught, print invalid input and reassign userInput to 0 to restart while loop
				cout << "Invalid input. Try again." << endl;
				userInput = 0;
			}
			//If user enters 4, end program
			if(userInput == 4) {
				cout << "Program ended." << endl;
				break;
			}
		}
		//As long as user does not hit ESC, continuously add one second and sleep one second to delay output
		else {
			currTime = AddTimeUnit(currTime, 3);
			//Sleep causes one second delay of output
			sleep(1);
		}
		//Continuously output time to console with one second delay in output from above sleep method
		OutputTime(currTime);
	}

	return 0;
}


