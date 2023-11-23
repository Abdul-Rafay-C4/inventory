#include <iostream>
#include <conio.h>
#include <string>
#include <limits>

using namespace std;

	int main()
	{
		int price[600], upn[600], i = 1, bubble, size = 600;
		char choice;
		bool ch;
		string* proname = new string[size];
		for (int j = 1; j < 600; ++j)
		{
			upn[j] = 0;
			price[j] = 0;
		}
		do {
			cout << "\n0 to Add Product ";
			cout << "\n1 to Remove Product ";
			cout << "\n2 to List all products ";
			cout << "\n3 to Exit ";
			cout << "\n\tEnter your choice: ";
			choice = getche();

			if (choice == '0') // add a product
			{
				cout << "\n\tEnter the Details:";
				do
				{
					cout << "\n\t\t\tEnter the Unique Product Number: ";
					if (cin >> i)
					{
						ch = true;
						if (i <= 1 && i >= 600)
						{
							ch = false;
							cout << "\n\t\t\tyou can only give input within range (0-600)" << endl;
							cin.clear();
						}

					}
					else
					{
						ch = false;
						cerr << "\n\t\t\tYou enter invalid UPN Please renter." << endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize> ::max(), '\n');
					}
				} while (ch == false);
				bubble = i;
				upn[i] = bubble;
				cout << "\n\t\t\tEnter the Product Name: ";
				cin.ignore();
				getline(cin, proname[i]);
				do
				{
					cout << "\n\t\t\tEnter the Product Price: ";
					if (cin >> price[i])
					{
						ch = true;
					}
					else
					{
						ch = false;
						cerr << "\n\t\t\tYou enter invalid price.";
						cin.clear();
						cin.ignore(numeric_limits<streamsize> ::max(), '\n');
					}
				} while (ch == false);
				i = 0;
			}
			else if (choice == '1') // remove the product
			{
				do
				{
					cout << "\n\tEnter the Unique Product Number: ";
					if (cin >> i)
					{
						ch = true;
						if (i < 1 && i > 600)
						{
							ch = false;
							cout << "you can only give input within range (0-600)";
							i = 0;
						}
					}
					else
					{
						ch = false;
						cerr << "\n\t\t\tYou enter invalid UPN Please renter." << endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize> ::max(), '\n');
					}
				} while (ch == false);
				bubble = i;
				upn[i] = bubble;
				cout << "\n\t\t\tDetails: ";
				cout << "\n\t\t\t\tProduct ID: " << proname[i];
				cout << "\n\t\t\t\tPrice: " << price[i];
				upn[i] = 0;
				price[i] = 0;
				cout << "\n\t\t\t\tRemoved.";
				i = 0;
			}
			else if (choice == '2') //List the products
			{
				for (int k = 1; k < 600; ++k)
				{
					if (upn[k] >= 1 && upn[k] <= 600)
					{
						if (price[k] != 0)
						{
							cout << "\n\t\t\tProduct UPN: " << upn[k];
							cout << "\n\t\t\tProduct ID:" << proname[k];
							cout << "\n\t\t\tPrice: " << price[k];
						}
					}
				}
			}
		} while (choice != '3');
		return 0;
	}