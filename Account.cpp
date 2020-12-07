#include "Account.h"
#include <iostream>

// A static int for generating unique id for each account
static int customer_unique_id = 30;

// Constructor for creating new account using user input.
Account::Account() : id(customer_unique_id++)
{
	std::string f, l;
	double b;
	std::cout << "Enter information for creating account\n";
	std::cout << "Enter first name and last name: ";
	std::cin >> f >> l;
	name = f + " " + l;

	std::cout << "Enter initial account balance.";
	std::cin >> b;

	balance = b;
	std::cout << "Account with id " << id << " successfully created!!!\n";
}

// Parameterized constructor
Account::Account(int i, std::string n, double b)
	: id(i), name(n), balance(b) {};

void Account::display()
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Customer Id: " << id << std::endl;
	std::cout << "Balance " << balance << std::endl;
}

// getter for id
int Account::get_id()
{
	return id;
}


// Operator overloading useful in linked list implementation
bool operator==(int target_id, Account acc)
{
	return target_id == acc.id;
}