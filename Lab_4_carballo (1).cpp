#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

bool file = true; // checks to see if file exist or not
ifstream inputFile_Names; // file that holds monkey names
ifstream inputFile_Pounds; // file that holds food intake
const int NUM_MONKEYS = 3; // amount of rows or index
const int NUM_DAYS = 7; // amount of columns
void get_monkey_info_from_file(string[], int[][NUM_DAYS], int); // gets the information of each monkey
void display_monkey_info(const string[], const int[][NUM_DAYS], int); // displays the information in a chart
void calc_display_avg_intake(const string[], const int[][NUM_DAYS], int); // calculates and displays the average of food each monkey has eaten 
void monkey_who_ate_less(const string[], const int[][NUM_DAYS], int); // determine which monkey has eaten the less food usiing a for-loop
void monkey_who_ate_more(const string[], const int[][NUM_DAYS], int); // determine which monkey has eaten the most food usiing a for-loop

int main() {

	string monkey_name[NUM_MONKEYS] = { "NONE" }; // initialized it to none
	int amount_pounds[NUM_MONKEYS][NUM_DAYS] = { 0 }; // initialized to 0

	get_monkey_info_from_file(monkey_name, amount_pounds, NUM_MONKEYS); // function call to get monkey information from file

	display_monkey_info(monkey_name, amount_pounds, NUM_MONKEYS); // function call the display monkey info

	if (file == true) { // if files are there proceed with each funtion call
		calc_display_avg_intake(monkey_name, amount_pounds, NUM_MONKEYS); // function call to display average intake

		monkey_who_ate_less(monkey_name, amount_pounds, NUM_MONKEYS); // function call to display the monkey who ate less

		monkey_who_ate_more(monkey_name, amount_pounds, NUM_MONKEYS); // function call to display the monkey who ate most
	}
	else { // else can't present the calculation properly
		cout << "Can't calculate chart without data from file" << endl;
	}

	cout << endl;

	return 0; // end of main

}

// function that gathers the information of each monkey
void get_monkey_info_from_file(string monkey_n[], int amount_pounds[][NUM_DAYS], int rows) {

	inputFile_Names.open("monkey_names.txt"); // file name for monkey names
	inputFile_Pounds.open("monkey_pounds_eaten.txt"); // file name for food intake

	if (inputFile_Names) { // opens file if exist

		int index = 0;

		while (index < rows && inputFile_Names >> monkey_n[index])
			index++;
		
		inputFile_Names.close(); // Close the file.
	}

	else {
		cout << "Error: File not Found 'monkey_names.txt'\n" << endl; // error message
	}

	if (inputFile_Pounds) {


		for (int index1 = 0; index1 < rows; index1++)
		{
			for (int index2 = 0; index2 < NUM_DAYS; index2++)
			{
				inputFile_Pounds >> amount_pounds[index1][index2]; // inputs the data from file into the food intake array
			}
		}
	}

	else {
		cout << "Error: File not Found 'monkey_pounds_eaten.txt'\n" << endl; // error message
		file = false; // file will now = false

	}

}
// function that displays the data chart of the monkeys

void display_monkey_info(const string monkey_n[], const int amount_pounds[][NUM_DAYS], int rows) { // used constant arrays to use the same data stored already

	cout << fixed; // fixes any disorientation

	cout << "Name:  " << setw(12) << right;

	for (int days = 1; days <= NUM_DAYS; days++) {
		cout << "Day_" << days << "   " << setw(6) << right; // displays each day
	}

	cout << endl;


	for (int idx1 = 0; idx1 < rows; idx1++)
	{
		cout << setw(10) << left << monkey_n[idx1]; // used setw and left/right for nice presentation of the chart

		for (int idx2 = 0; idx2 < NUM_DAYS; idx2++)
		{
			cout << setw(9) << right << amount_pounds[idx1][idx2] << " "; // displays the array
		}

		cout << endl; // new line
	}

	cout << endl << endl; // double new line
}

// function that calculates and displays the average intake each monkey has consumed
void calc_display_avg_intake(const string monkey_n[], const int amount_pounds[][NUM_DAYS], int rows) {

	double average;

	cout << fixed;

	cout << "Name:  " << setw(36)
		<< "Average_Daily_Intake_In_Pounds" << endl;

	// Get each student's average score. 
	for (int index = 0; index < rows; index++) {
		 
		double total = 0; // Set the accumulator.
		 
		for (int index2 = 0; index2 < NUM_DAYS; index2++)
			total += amount_pounds[index][index2]; // Sum a row.
		
		average = total / NUM_DAYS; // Get the average. 
		
		cout << setw(25) << left << setprecision(1) << monkey_n[index] << average << endl; // Displays the average for each monkey and sets one decimal point
	}

	cout << endl << endl;

}

// function that gets the monkey who ate less
void monkey_who_ate_less(const string monkey_n[], const int amount_pounds[][NUM_DAYS], int rows) {

	int lowest = amount_pounds[0][0]; // initialized 
	string monkey_name = monkey_n[0]; // initialized
	int day; 

	for (int index1 = 0; index1 < rows; index1++)
	{
		for (int index2 = 0; index2 < NUM_DAYS; index2++)
		{
			if (amount_pounds[index1][index2] < lowest) {
				lowest = amount_pounds[index1][index2]; // gets the lowest number
				monkey_name = monkey_n[index1]; // gets the monkey name who ate less
				day = index2 + 1; // gets the correct day 
			}
		}
	}
	cout << "Least amount of food: " << monkey_name << " ate " << lowest << " pounds on Day# " << day << endl; // displays the monkey who ate less

}

// function that gets the monkey who ate the most
void monkey_who_ate_more(const string monkey_n[], const int amount_pounds[][NUM_DAYS], int rows) {

	int highest = amount_pounds[0][0]; // initialized
	string monkey_name = monkey_n[0]; // initialized
	int day;

	for (int index1 = 0; index1 < rows; index1++)
	{
		for (int index2 = 0; index2 < NUM_DAYS; index2++)
		{
			if (amount_pounds[index1][index2] > highest) {
				highest = amount_pounds[index1][index2]; //gets the highest number
				monkey_name = monkey_n[index1]; // gets the monkey name who ate more
				day = index2 + 1; // gets the correct day
			}
		}
	}
	cout << "Most amount of food: " << monkey_name << " ate " << highest << " pounds on Day# " << day << endl; // displays the monkey who ate more

}

// end of code
