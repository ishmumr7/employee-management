#include "Employee.h"
#include<bits/stdc++.h>
using namespace std;

Employee::Employee()
{
	ID = "";
}

Employee::Employee(string fn, string ln, string id, string add, string contact, double sal)
	: Person(fn, ln, add, contact)
{
	ID = id;
	salary = sal;
}

void Employee::setID(string id) 
{
	ID = id;
}

void Employee::setSalary(double sal)
{
	salary = sal;
}

string Employee::getID()
{
	return ID;
}

double Employee::getSalary()
{
	return salary;
}