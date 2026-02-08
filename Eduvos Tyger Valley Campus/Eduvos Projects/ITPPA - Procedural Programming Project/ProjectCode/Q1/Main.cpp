#include <iostream>
#include <fstream>
using namespace std;

int main() {
	//Constants and variables are declared
	const double DISCOUNT_RATE = 0.10;
	const double DISCOUNT_THRESHOLD = 100.00;

	const double COFFEE_PRICE = 15.00;
	const double SANDWICH_PRICE = 30.00;
	const double SALAD_PRICE = 25.00;
	const double JUICE_PRICE = 10.00;
	const double MUFFIN_PRICE = 20.00;
	const double PIZZA_PRICE = 35.00;
	const double SOUP_PRICE = 18.00;
	const double BURGER_PRICE = 40.00;

	string name, surname;
	int item, numItems;
	double totalSum, finalSum, price;
	ofstream cafeteriaFile;

	//Information is gathered from the user
	cout << "Enter your name please: ";
	cin >> name;
	cout << endl;
	cout << "Enter your surname please: ";
	cin >> surname;
	cout << endl;
	cout << "How many items would you like to order (up to a maximum of 8)?: ";
	cin >> numItems;
	cout << endl << endl;

	cout << "Cafeteria Menu:\n";
	cout << "1. Coffee - " << COFFEE_PRICE << endl;
	cout << "2. Sandwich - " << SANDWICH_PRICE << endl;
	cout << "3. Salad - " << SALAD_PRICE << endl;
	cout << "4. Juice - " << JUICE_PRICE << endl;
	cout << "5. Muffin - " << MUFFIN_PRICE << endl;
	cout << "6. Pizza slice - " << PIZZA_PRICE << endl;
	cout << "7. Soup - " << SOUP_PRICE << endl;
	cout << "8. Burger - " << BURGER_PRICE << endl;

	totalSum = 0;
	price = 0;
	//The user picks the item that they would like to buy and its price is added to the total
	for (int i = 1; i <= numItems; i++) {
		cout << "\nSelect what order " << i << " should be (1-8):";
		cin >> item;

		switch (item) {
		case 1:
			price = COFFEE_PRICE;
			break;
		case 2:
			price = SANDWICH_PRICE;
			break;
		case 3:
			price = SALAD_PRICE;
			break;
		case 4:
			price = JUICE_PRICE;
			break;
		case 5:
			price = MUFFIN_PRICE;
			break;
		case 6:
			price = PIZZA_PRICE;
			break;
		case 7:
			price = SOUP_PRICE;
			break;
		case 8:
			price = BURGER_PRICE;
			break;
		}

		totalSum = totalSum + price;
	}

	//A discount is applied to the final sum if the total is more than R100
	cout << "\n\nTotal Bill: R" << totalSum;
	if (totalSum > DISCOUNT_THRESHOLD) {
		finalSum = totalSum - (totalSum * DISCOUNT_RATE);
		cout << "\nA discount was applied.\n";
	}
	else {
		finalSum = totalSum;
		cout << "\nNo discount was applied.\n";
	}

	cout << "\nFinal Bill: R" << finalSum << endl;

	//User information is sent to the file, CafeteriaBill.txt
	cafeteriaFile.open("CafeteriaBill.txt", ios::trunc);
	if (cafeteriaFile.is_open()) {
		cafeteriaFile << "Name: " << name << endl;
		cafeteriaFile << "Surname: " << surname << endl;
		cafeteriaFile << "Final bill: R" << finalSum << endl;
		cafeteriaFile.close();
		cout << "The bill has been written to CafeteriaBill.txt.\n";
	}
	else {
		cout << "CafeteriaBill.txt could not be opened.\n";
	}
}