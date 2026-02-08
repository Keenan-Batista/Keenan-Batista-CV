#include <iostream>
#include <fstream>
using namespace std;

int main() {
	//Constants and variables are declared
	const double DISCOUNT_RATE = 0.05;
	const double DISCOUNT_THRESHOLD = 200.00;

	const double COFFEE_PRICE = 15.00;
	const double SANDWICH_PRICE = 30.00;
	const double SALAD_PRICE = 25.00;
	const double JUICE_PRICE = 10.00;
	const double MUFFIN_PRICE = 20.00;
	const double PIZZA_PRICE = 35.00;
	const double SOUP_PRICE = 18.00;
	const double BURGER_PRICE = 40.00;

	string name, surname;
	int option, numItems;
	double totalSum, finalSum, price;
	bool shopping = true;
	ofstream cartFile;

	//Information is gathered from the user
	cout << "Enter your name please: ";
	cin >> name;
	cout << endl;
	cout << "Enter your surname please: ";
	cin >> surname;
	cout << endl;

	cout << "Online Shopping Menu:\n\n";
	cout << "1. Coffee - " << COFFEE_PRICE << endl;
	cout << "2. Sandwich - " << SANDWICH_PRICE << endl;
	cout << "3. Salad - " << SALAD_PRICE << endl;
	cout << "4. Juice - " << JUICE_PRICE << endl;
	cout << "5. Muffin - " << MUFFIN_PRICE << endl;
	cout << "6. Pizza slice - " << PIZZA_PRICE << endl;
	cout << "7. Soup - " << SOUP_PRICE << endl;
	cout << "8. Burger - " << BURGER_PRICE << endl << endl;
	cout << "9. Go to cart" << endl;

	totalSum = 0;
	//All purchase options will keep being asked until the user chooses option 9 to end the loop and calculate the final bill
	while (shopping == true) {
		cout << "\nSelect the option that you would like to choose (1-9):";
		cin >> option;

		switch (option) {
		case 1:
			cout << "\nEnter the amount of coffees that you want to buy: ";
			cin >> numItems;
			price = COFFEE_PRICE * numItems;
			break;
		case 2:
			cout << "\nEnter the amount of sandwiches that you want to buy: ";
			cin >> numItems;
			price = SANDWICH_PRICE * numItems;
			break;
		case 3:
			cout << "\nEnter the amount of salads that you want to buy: ";
			cin >> numItems;
			price = SALAD_PRICE * numItems;
			break;
		case 4:
			cout << "\nEnter the amount of juices that you want to buy: ";
			cin >> numItems;
			price = JUICE_PRICE * numItems;
			break;
		case 5:
			cout << "\nEnter the amount of muffins that you want to buy: ";
			cin >> numItems;
			price = MUFFIN_PRICE * numItems;
			break;
		case 6:
			cout << "\nEnter the amount of pizza slices that you want to buy: ";
			cin >> numItems;
			price = PIZZA_PRICE * numItems;
			break;
		case 7:
			cout << "\nEnter the amount of soups that you want to buy: ";
			cin >> numItems;
			price = SOUP_PRICE * numItems;
			break;
		case 8:
			cout << "\nEnter the amount of burgers that you want to buy: ";
			cin >> numItems;
			price = BURGER_PRICE * numItems;
			break;
		case 9:
			shopping = false;
			price = 0;
			break;
		default:
			cout << "\nInvalid option. Try again please.";
			price = 0;
			break;
		}

		//The total is calculated
		totalSum = totalSum + price;
	}

	//A discount is applied to the final sum if the total is more than R200
	cout << "\n\nTotal bill: R" << totalSum;
	if (totalSum > DISCOUNT_THRESHOLD) {
		finalSum = totalSum - (totalSum * DISCOUNT_RATE);
		cout << "\nA discount was applied.\n";
	}
	else {
		finalSum = totalSum;
		cout << "\nNo discount was applied.\n";
	}
	cout << "\nFinal bill: R" << finalSum << endl;

	//User information is sent to the file, OnlineCartBill.txt
	cartFile.open("OnlineCartBill.txt", ios::trunc);
	if (cartFile.is_open()) {
		cartFile << "Name: " << name << endl;
		cartFile << "Surname: " << surname << endl;
		cartFile << "Final bill: R" << finalSum << endl;
		cartFile.close();
		cout << "The bill has been written to OnlineCartBill.txt.\n";
	}
	else {
		cout << "OnlineCartBill.txt could not be opened.\n";
	}
}