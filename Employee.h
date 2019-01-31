#pragma once
#include <string>

using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee
{
private:
	struct ListNode
	{
		int empID;
		string first_name;
		string last_name;
		int Age;

		struct ListNode *next;
	};

	ListNode *head;

public:
	Employee();

	~Employee();

	void displayMenu() const;
	void addEmployee(int, string, string, int);
	void deleteEmployee(int);
	void editEmployee(int);
	void displayEmployeeList() const;
	void countEntries();
};




#endif
