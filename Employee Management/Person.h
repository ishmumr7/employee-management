#ifndef Person_h
#define Person_h
#include <bits/stdc++.h>
using namespace std;

class Person
{
	private:
		string firstName;
		string lastName;
		string address;
		string contact;

	public:
		Person();
		Person(string fn, string ln, string add, string contact);
		
		void setName(string fn, string ln);
		void setAddress(string add);
		void setContact(string contact);

		string getName();
		string getFirstName();
		string getLastName();
		string getAddress();
		string getContact();
		
};

#endif // !Person_h