#ifndef Employee_h
#define Employee_h
#include <bits/stdc++.h>
#include "Person.h"
using namespace std;

class Employee : public Person
{
	private:
		string ID;
		double salary;

	public:
		Employee();
		Employee(string fn, string ln, string id, string add, string contact, double sal);

		void setID(string id);
		void setSalary(double sal);

		string getID();
		double getSalary();

};

#endif // !Employee_h