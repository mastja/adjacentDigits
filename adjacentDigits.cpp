/*  Project Name : Adjacent Digits Integers Problem
    Date: 06/07/2020
    Programmer: Jacob Mast
    Description: This program to executes user interface and algorithm solution 
                to the common Google interview question:
                Given a number N, write a code to print all positive numbers
                less than N in which all adjacent digits differ by 1.
*/

#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

// function drives the Adjacent Digits Algorithm, see further description below
void adjacentDigits();

// function drives the main menu, see further description below
int mainMenu();


int main(){

    // title of program
    cout << "************************************************************************\n"
        << "***********\t ADACENT DIGITS INTEGERS TESTING PROGRAM \t***********\n"
        << "************************************************************************\n\n";

    // main menu, 1 is play, 2 is quit
    int mainChoice = mainMenu();
	if (mainChoice == 2) {
		cout << "\nThe program will now quit.\n\n";
		return 0;
	}

	// loop so long as the user does not choose to quit at the end of the turn
	while (mainChoice != 2){
        
        // call program to determine list and write to console
        adjacentDigits();

        // after test program runs, call main menu to see if user wants to keep playing or not
        mainChoice = mainMenu();

    }

    // user has chosen to exit the program
	if (mainChoice == 2) {
		cout << "\nThe program will now quit.\n\n";
		return 0;
	}

    return 0;

}


/* The adjacentDigits() function executes the algorithm answer to the common 
    Google interview question:
        Given a number N, write a code to print all positive numbers
        less than N in which all adjacent digits differ by 1.

passed: nothing
returns: nothing
*/

void adjacentDigits() { 
    
    // prompt user for input
	cout << "*****\t Enter an Integer to run the adjacent digits integers simulation on: \t*****\n";

    // record user input
    int inputNum;
    cin >> inputNum;

    // User response
    cout << "\n*****\t Program Output: \t*****\n\t";


    // for values less than 11 and less than the input value, all values satisfy the conditions
    for (int i=0; i < 11; i++){
        if (i < inputNum){
            if(i == 0){
                cout << i;
            }
            else{
                cout << ", " << i;
            }
        }
    }

    // starting at 12, the next number greater than 11 that satisfies the conditions
    if (inputNum > 12){

        // declare variables for use in the test below
        string testStr;
        int temp1, temp2, j;
        string temp1Str, temp2Str;

        // for numbers 12 up to all numbers less than the input test value
        for (j=12; j < inputNum; j ++){

            bool flag = true;

            testStr = to_string(j);

            int k;

            for (k=0; ((k + 1) < testStr.length()); k++){

                // set temps to two consecutive digits up to test string length and test string length - 1
                temp1Str = testStr.at(k);
                temp2Str = testStr.at(k+1);

                // change consecutive digit strings to integers
                temp1 = stoi(temp1Str);
                temp2 = stoi(temp2Str);

                // test if consecutive digits differ by 1, if not set bool flag to false
                if ((temp1 - temp2) != 1 && (temp2 - temp1) != 1){
                    flag = false;
                } 
            }

            // if flag has not been changed to false, the current j value satisfies the conditions
            if (flag == true){
                cout << ", " << j;
            }
        }

        cout << "\n" << endl;
    }

    return; 
} 


/* The mainMenu() function is the Start menu function, 
    this function presents the menu options and takes user input.
    Validates user input and returns menu choice as an integer.

passed: nothing
returns: int, main menu choice, 1 is run test, 2 is quit. 

source: my hw submission in CS162
*/

int mainMenu(){ 

// prompt user for input
	cout << "*****\t What would you like to do? \t*****\n"
	<< "Enter 1 to run the adjacent integers test on your number.\n"
	<< "Enter 2 to quit.\n";



//validate user input, must be a 1 or 2
// declare variables for validation below

	string choice;
	const string choice1 = "1", choice2 = "2";
	int returnChoice = 0;

// the below verifies input did not fail and is exactly 1 or 2 else asks for user
// to re-enter
	cin >> choice;
	while (cin.fail() || (choice != choice1 &&
		choice != choice2)){
		cout << "Not a valid choice.  Please enter an integer in range.\n"
			<< "Enter 1 to run the adjacent integers test on your number.\n"
	        << "Enter 2 to quit.\n";
		cin.clear();
		cin.ignore(180, '\n');
		cin >> choice;
	};

// return user input as integer start menu choice

	if (choice == choice1) {
		returnChoice = 1;
	};

	if (choice == choice2) {
		returnChoice = 2;
	};

	cout << endl;

	return returnChoice;

} 