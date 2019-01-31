#include <iostream>
#include "Employee.h"
#include <iomanip>

Employee::Employee()
{
	head = nullptr;
}

Employee::~Employee()
{
}

void Employee::displayMenu() const
{
	
		cout << "\n                 MENU\n";
		cout << "-----------------------------------------\n";
		cout << "A) Add Employee\n";
		cout << "B) Delete Employee\n";
		cout << "C) Edit Employee Info\n";
		cout << "D) Display a list of all Employee\n";
		cout << "E) Count Employee Entries\n";
		cout << "F) EXIT\n";
		cout << "Enter your choice: ";
	
}

void Employee::addEmployee(int id, string fname, string lname, int age)
{
	ListNode *newNode;
	ListNode *nodePtr;
	ListNode *previousNode = nullptr;

	newNode = new ListNode;
	newNode->empID = id;
	newNode->first_name = fname;
	newNode->last_name = lname;
	newNode->Age = age;


	if (!head)
	{
		head = newNode;
		newNode->next = nullptr;
		cout << "NEW EMPLOYEE SUCCESSFULLY ADDED!" << endl;
	}

	else
	{
		nodePtr = head;
		previousNode = nullptr;

		while (nodePtr != nullptr && nodePtr->first_name < fname)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (previousNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
			cout << "NEW EMPLOYEE SUCCESSFULLY ADDED!" << endl;
		}

		else
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
			cout << "NEW EMPLOYEE SUCCESSFULLY ADDED!" << endl;
		}

	}
}

void Employee::deleteEmployee(int empID)
{
	ListNode *nodePtr;
	ListNode *previousNode = nullptr;

	if (!head)
		return;

	if (head->empID == empID)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
		cout << "SUCCESSFULLY DELETED!" << endl;
	}

	else 
	{
		nodePtr = head;

		while (nodePtr != nullptr && nodePtr->empID != empID)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
			cout << "SUCCESSFULLY DELETED!" << endl;
		}
		else
		{
			cout << "EMPLOYEE ID DOES NOT EXIST." << endl;
		}
	}
}

void Employee::editEmployee(int empID)
{
	ListNode *nodePtr = nullptr;
	ListNode *previousNode = nullptr;
	
	string fname;
	string lname;
	int age;

	if (!head)
		return;

	if (head->empID == empID)
	{
		cout << "Enter First Name: ";
		cin >> fname;
		
		cout << "Enter Last name: ";
		cin >> lname;
		
		cout << "Enter Age: ";
		cin >> age;

		nodePtr->first_name = fname;
		nodePtr->last_name = lname;
		nodePtr->Age = age;

		cout << "\nID: " << empID << " HAS BEEN UPDATED SUCCESSFULLY!" << endl;
	}

	else
	{
		nodePtr = head;

		while (nodePtr != nullptr && nodePtr->empID != empID)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (nodePtr)
		{
			cout << "Enter First Name: ";
			cin >> fname;

			cout << "Enter Last name: ";
			cin >> lname;

			cout << "Enter Age: ";
			cin >> age;

			nodePtr->first_name = fname;
			nodePtr->last_name = lname;
			nodePtr->Age = age;

			cout << "\nID: " << empID << " HAS BEEN UPDATED SUCCESSFULLY!" << endl;
		}
		
		else
		{
			cout << "EMPLOYEE ID DOES NOT EXIST!" << endl;
		}
	}
}

void Employee::displayEmployeeList() const
{
	ListNode *nodePtr;

	nodePtr = head;

	cout << "\n                   List of Employees\n";
	cout << "------------------------------------------------------\n";
	cout << "EMP_ID:	    First_Name:	      Last_Name:	  Age: \n";
	cout << "------------------------------------------------------\n";


	while (nodePtr)
	{
		cout << left << setw(13) << nodePtr->empID
			<< left << setw(18) << nodePtr->first_name
			<< setw(20) << left << nodePtr->last_name
			<< nodePtr->Age << endl;

		nodePtr = nodePtr->next;
	}
}

void Employee::countEntries()
{
	int count = 0;

	ListNode *nodePtr;
	nodePtr = head;

	if (!nodePtr)
	{
		cout << "\nJEFFREY CARBALLO HAS NO LINKED LIST" << endl;
	}

	else 
	{
		while (nodePtr->next)
		{
			count++;
			nodePtr = nodePtr->next;
		}

		cout << "\nJEFFREY CARBALLO HAS A LINKED LIST OF " << count << " ENTRIES!" << endl;
	}

}