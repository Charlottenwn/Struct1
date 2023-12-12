#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

struct ItemType {
	int order_Num;
	float price = 0;
	int quantity = 0; // New field for quantity
};

ItemType menuList[8];
int Number;
class Rest {

public:
	int i = 0;

	void getData() { //gets data from user input
		int selection;
		cout << "Do you want to make a selection? 1 - Y; 2 - N: " << endl;
		cin >> selection;
		while (selection == 1) {
			int quantity; // Variable to store quantity
			cout << "Enter item number: ";
			cin >> Number;
			cout << "Enter quantity: ";
			cin >> quantity;

			menuList[i].order_Num = Number;
			menuList[i].quantity = quantity;

			switch (Number) {
			case 1:
				menuList[i].price = 1.45; // Omlet price
				break;
			case 2:
				menuList[i].price = 2.45; // Bacon with cooked egg price
				break;
			case 3:
				menuList[i].price = 0.99; // Cupcake with cherry price
				break;
			case 4:
				menuList[i].price = 1.99; // French croutons price
				break;
			case 5:
				menuList[i].price = 2.49; // Fruit salad price
				break;
			case 6:
				menuList[i].price = 0.69; // Cereal price
				break;
			case 7:
				menuList[i].price = 0.50; // Coffee price
				break;
			case 8:
				menuList[i].price = 0.75; // Tea price
				break;
			default:
				cout << "Select a valid option" << endl;
				i--;
				break;
			}
			cout << "Continue with selection? 1 - Y; 2 - N " << endl;
			cin >> selection;
			i++;
		}
	}

	void showMenu() { //shows menu to terminal

		cout << "Welcome to the Cafe" << endl;

		for (int x = 0; x < i; x++) {
			switch (menuList[x].order_Num) {
			case 1:
				cout << menuList[x].quantity << "x Omlet €" << menuList[x].price << endl;
				break;
			case 2:
				cout << menuList[x].quantity << "x Bacon with cooked egg €" << menuList[x].price << endl;
				break;
			case 3:
				cout << menuList[x].quantity << "x Cupcake with cherry €" << menuList[x].price << endl;
				break;
			case 4:
				cout << menuList[x].quantity << "x French croutons €" << menuList[x].price << endl;
				break;
			case 5:
				cout << menuList[x].quantity << "x Fruit salad €" << menuList[x].price << endl;
				break;
			case 6:
				cout << menuList[x].quantity << "x Cereal €" << menuList[x].price << endl;
				break;
			case 7:
				cout << menuList[x].quantity << "x Coffee €" << menuList[x].price << endl;
				break;
			case 8:
				cout << menuList[x].quantity << "x Tea €" << menuList[x].price << endl;
				break;
			}
		}
	}

	void printCheck() { // print receipt function
		ofstream file("check.txt");
		float totalAmount = 0;

		file << "Welcome to the Cafe" << endl;
		file << "Receipt:" << endl;
		file << "" << endl;

		for (int x = 0; x < i; x++) {  //variable list to pick from
			switch (menuList[x].order_Num) {
			case 1:
				file << menuList[x].quantity << "x Omlet €" << (menuList[x].price * menuList[x].quantity) << endl;
				break;
			case 2:
				file << menuList[x].quantity << "x Bacon with cooked egg €" << (menuList[x].price * menuList[x].quantity) << endl;
				break;
			case 3:
				file << menuList[x].quantity << "x Cupcake with cherry €" << (menuList[x].price * menuList[x].quantity) << endl;
				break;
			case 4:
				file << menuList[x].quantity << "x French croutons €" << (menuList[x].price * menuList[x].quantity) << endl;
				break;
			case 5:
				file << menuList[x].quantity << "x Fruit salad €" << (menuList[x].price * menuList[x].quantity) << endl;
				break;
			case 6:
				file << menuList[x].quantity << "x Cereal €" << (menuList[x].price * menuList[x].quantity) << endl;
				break;
			case 7:
				file << menuList[x].quantity << "x Coffee €" << (menuList[x].price * menuList[x].quantity) << endl;
				break;
			case 8:
				file << menuList[x].quantity << "x Tea €" << (menuList[x].price * menuList[x].quantity) << endl;
				break;
			}

			totalAmount += menuList[x].price * menuList[x].quantity; // prints by 1 
		}
		file << "" << endl;
		file << "Tax € " << setprecision(2) << (totalAmount * 0.09) << endl;
		file << "Amount due € " << setprecision(2) << (totalAmount + totalAmount * 0.09) << endl;

		file.close();
	}
};
int main() {

	Rest r;

	cout << "Menu" << endl;
	cout << "1: Omlet 1.45€" << endl;
	cout << "2: Bacon with egg " << "2.45€" << left << endl;
	cout << "3: Cupcake with cherry 0.99€" << endl;
	cout << "4: French Crouton 1.99€" << endl;
	cout << "5: Fruit Salad 2.49€" << endl;
	cout << "6: Cereal 0.69€" << endl;
	cout << "7: Coffee 0.50€" << endl;
	cout << "8: Tea 0.75€" << endl;
	cout << "You can make up to 8 order selections (single)" << endl;
	r.getData();
	r.showMenu();
	r.printCheck();

	cout << "Receipt in check.txt" << endl;

	return 0;
}
