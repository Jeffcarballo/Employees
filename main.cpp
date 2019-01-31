#include <iostream>
#include "Employee.h"
#include <iomanip>

using namespace std;

int main()
{

	Employee employee;
	int empID;
	string fname;
	string lname;
	int age;

	char choice;

	cout << setprecision(2) << fixed;
	do
	{

		employee.displayMenu();
		cin >> choice;

		while (toupper(choice) < 'A' || toupper(choice) > 'E')
		{
			cout << "Please make a choice in the range of A through E: ";
			cin >> choice;

		}

		switch (choice)
		{

		case 'a':
		case 'A': cout << "\nEnter Employee ID: ";
				  cin >> empID;
				  cout << "Enter First Name: ";
				  cin >> fname;
				  cout << "Enter Last name: ";
				  cin >> lname;
				  cout << "Enter Age: ";
				  cin >> age;
				  employee.addEmployee(empID, fname, lname, age);
				  break;

		case 'b':
		case 'B': cout << "\nEnter Employee ID: ";
				  cin >> empID;
				  employee.deleteEmployee(empID);
			      break;

		case 'c':
		case 'C': cout << "\nEnter Employee ID: ";
				  cin >> empID;
				  employee.editEmployee(empID);
				  break;

		case 'd': 
		case 'D': employee.displayEmployeeList();
				  break;

		case 'e':
		case 'E': employee.countEntries();
				  break;

		}
	
	} while (toupper(choice) != 'F');
	cout << "\nThank for visiting Carballo Store!" << endl;
	system("pause");
	return 0;
}