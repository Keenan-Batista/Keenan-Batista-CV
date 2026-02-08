#include <iostream>
#include <sstream>
#include <locale>
using namespace std;

bool createAccount(string &name, int &accountNumber, double &balance) {
	//Variable declaration
	string userName, userNumber, strDeposit;
	bool validAccount = false, validDeposit = false;
	int validNum = 0, decimalsFound = 0;
	double initialDeposit;
	
	cout << "Enter your name: ";
	getline(cin >> ws, userName);
	cout << endl;

	cout << "Enter your account number (it is 5 numbers in length): ";
	getline(cin >> ws, userNumber);
	cout << endl;

	//Determine if the account number doesn't have any letters and is five characters long
	if (userNumber.length() == 5) {
		for (int i = 0; i <= userNumber.length(); i++) {
			if ((userNumber[i] >= '0' && userNumber[i] <= '9')) {
				validNum++;
			}
		}
		if (validNum == userNumber.length()) {
			validAccount = true;
		}
	}

	if (validAccount == true) {
		cout << "Enter your initial deposit (it must be more than R0.00): R";
		getline(cin >> ws, strDeposit);
		cout << endl;

		validNum = 0;
		//Determine if the deposit value doesn't have any letters and an incorrect amount of decimal points
		for (int i = 0; i <= strDeposit.length(); i++) {
			if ((strDeposit[i] >= '0' && strDeposit[i] <= '9') || (strDeposit[i] == '.')) {
				validNum++;
				if (strDeposit[i] == '.') {
					decimalsFound++;
				}
			}
		}

		//If each character in the deposit value is correct and the decimal points found are less than 2, change the deposit value from a string to a double
		if (validNum == strDeposit.length() && decimalsFound < 2) {
			initialDeposit = stod(strDeposit);
			//Determine if the deposit is more than 0
			if (initialDeposit > 0) {
				validDeposit = true;
			}
		}

		//If all the required information is valid, then create the account
		if (validDeposit == true) {
			//Determines if the deposit will create an overflow
			if (initialDeposit < numeric_limits<unsigned int>::max()) {
				cout << "Account created successfully!\n";
				name = userName;
				istringstream(userNumber) >> accountNumber;
				balance = initialDeposit;
				return(true);
			}
			else {
				cout << "Initial deposit is too big, it will create an overflow.\n";
			}
		}
		else {
			cout << "Invalid initial deposit.\n";
		}
	}
	else {
		cout << "Invalid account number.\n";
	}
}

void depositMoney(double &balance) {
	//Variable declaration
	double deposit, balanceTest = balance;
	string strDeposit;
	int validNum = 0, decimalsFound = 0;
	bool validDeposit = false;

	cout << "Enter your deposit: R";
	getline(cin >> ws, strDeposit);
	cout << endl;

	//Determine if the deposit value doesn't have any letters and an incorrect amount of decimal points
	for (int i = 0; i <= strDeposit.length(); i++) {
		if ((strDeposit[i] >= '0' && strDeposit[i] <= '9') || (strDeposit[i] == '.')) {
			validNum++;
			if (strDeposit[i] == '.') {
				decimalsFound++;
			}
		}
	}

	//If each character in the deposit value is correct and the decimal points found are less than 2, change the deposit value from a string to a double
	if (validNum == strDeposit.length() && decimalsFound < 2) {
		deposit = stod(strDeposit);
		//Determine if the deposit is more than 0
		if (deposit > 0) {
			validDeposit = true;
		}
	}

	//If the deposit value is valid, then process the deposit
	if (validDeposit == true) {
		//Determines if an overflow will happen
		balanceTest = balance + deposit;
		if (balanceTest < numeric_limits<unsigned int>::max()) {
			balance = balance + deposit;
			cout << "Deposit completed!\n";
		}
		else {
			cout << "The deposit is too big, it will create an overflow.\n";
		}
	}
	else {
		cout << "Invalid deposit.\n";
	}
}

void withdrawMoney(double &balance) {
	//Variable declaration
	double withdraw;
	string strWithdraw;
	int validNum = 0, decimalsFound = 0;
	bool validWithdraw = false;

	cout << "Enter your withdraw: R";
	getline(cin >> ws, strWithdraw);
	cout << endl;

	//Determine if the withdraw value doesn't have any letters and an incorrect amount of decimal points
	for (int i = 0; i <= strWithdraw.length(); i++) {
		if ((strWithdraw[i] >= '0' && strWithdraw[i] <= '9') || (strWithdraw[i] == '.')) {
			validNum++;
			if (strWithdraw[i] == '.') {
				decimalsFound++;
			}
		}
	}

	//If each character in the withdraw value is correct and the decimal points found are less than 2, change the withdraw value from a string to a double
	if (validNum == strWithdraw.length() && decimalsFound < 2) {
		withdraw = stod(strWithdraw);
		//Determine if the withdraw is less than the balance
		if (withdraw < balance) {
			validWithdraw = true;
		}
	}

	//If the withdraw value is valid, then process the withdraw
	if (validWithdraw == true) {
		balance = balance - withdraw;
		cout << "Withdraw completed!\n";
	}
	else {
		cout << "Invalid withdraw.\n";
	}
}

void checkBalance(const double &balance) {
	//Display the balance
	cout << "Current balance: R" << balance << endl;
}

void displayAccountDetails(const string &name, const int &accountNumber, const double &balance) {
	//Display all account details
	cout << "Account holder: " << name << endl;
	cout << "Account number: " << accountNumber << endl;
	cout << "Current balance: R" << balance << endl;
}

int menu() {
	//Variable declaration
	int choice;

	//Display the menu and receive input from the user
	cout << "--- Bank Account Management System ---\n";

	cout << "1. Create account\n";
	cout << "2. Deposit money\n";
	cout << "3. Withdraw money\n";
	cout << "4. Check balance\n";
	cout << "5. Display account details\n";
	cout << "6. Exit\n\n";

	cout << "Enter your choice (1-6):";
	cin >> choice;
	return choice;
}

int main() {
	//Variable declaration
	string name;
	int accountNumber, choice;
	double balance;
	bool exitSystem = false, accountCreated = false;

	//Loops through the options until the user chooses option 6 that ends the loop and exits the program
	while (exitSystem == false) {
		choice = menu();

		switch (choice) {
		case 1: //Create an account
			accountCreated = createAccount(name, accountNumber, balance);
			break;
		case 2: //Deposit money into the account
			if (accountCreated == true) {
				depositMoney(balance);
			}
			else {
				cout << "An account must first be created!\n";
			}
			break;
		case 3: //Withdraw money from the account
			if (accountCreated == true) {
				withdrawMoney(balance);
			}
			else {
				cout << "An account must first be created!\n";
			}
			break;
		case 4: //Display the balance
			if (accountCreated == true) {
				checkBalance(balance);
			}
			else {
				cout << "An account must first be created!\n";
			}
			break;
		case 5: //Display all account details
			if (accountCreated == true) {
				displayAccountDetails(name, accountNumber, balance);
			}
			else {
				cout << "An account must first be created!\n";
			}
			break;
		case 6: //Exit program
			exitSystem = true;
			cout << "Exiting the system. Goodbye!";
			break;
		default:
			cout << "Invalid choice. Try again!";
			break;
		}

		cout << endl;
	}

	return 0;
}