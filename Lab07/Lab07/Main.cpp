//Drew Childs, Lab07
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
using namespace std;

double GetMiles() {			//get miles function, pretty self explanitory
	double miles_traveled;
	cout << endl << "Enter the miles traveled for this trip --> ";
	cin >> miles_traveled;

	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw runtime_error("Invalid input recieved, you must enter a decimal number.");
	}

	if (miles_traveled <= 0) {
		throw runtime_error("Miles cannot be less than 0.");
	}

	return miles_traveled;
}

double GetGallons() {			//get gallons function, pretty self explanitory
	double gallons_used;
	cout << "Enter the gallons used for this trip --> ";
	cin >> gallons_used;

	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw runtime_error("Invalid input recieved, you must enter a decimal number.");
	}

	if (gallons_used <= 0) {
		throw runtime_error("Gallons cannot be less than 0.");
	}

	return gallons_used;
}

double GetMPG(vector<double> miles, vector<double> gallons) {
	double sum_miles = 0, sum_gallons = 0;

	if (miles.size() == 0 || gallons.size() == 0) {
		throw runtime_error("No values recorded. MPG is nan.");
	}

	for (unsigned i = 0; i < miles.size(); i++) {		//sums up all values
		sum_miles += miles.at(i);
		sum_gallons += gallons.at(i);
	}

	return (sum_miles / sum_gallons);		//calculating mpg
}

int main() {
	vector<double> total_miles;
	vector<double> total_gallons;
	double current_miles, current_gallons, mpg;
	char keep_going = 'a';

	cout << "MPG Calculator:" << endl;

	do {
		try {
			current_miles = GetMiles();			//gathering input and putting them in the vector
			current_gallons = GetGallons();
			total_miles.push_back(current_miles);
			total_gallons.push_back(current_gallons);
			cout << endl << "Press any key to add another tank or N to stop --> ";
			cin >> keep_going;

			if (cin.fail()) {		//throws exception if something wack happens
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw runtime_error("Invalid input recieved, enter only a single character.");
			}
		}
		catch (runtime_error &exception) {		//catches all errors and tells user to try again
			cout << exception.what() << endl;
			cout << "Try again." << endl;
		}
	} while (toupper(keep_going) != 'N');
	
	try {
		mpg = GetMPG(total_miles, total_gallons);		//calculating mpg
	}
	catch (runtime_error &exception) {
		cout << exception.what() << endl;
	}

	cout << endl << "Your fuel economy for this trip was --> " << mpg << endl << endl;

	return 0;
}