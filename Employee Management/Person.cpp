#include "Person.h"
#include <bits/stdc++.h>

using namespace std;

Person::Person()
{
	firstName = "";
	lastName = "";
	address = "";
	contact = "";
}

Person::Person(string fn, string ln, string add, string contact)
{
	firstName = fn;
	lastName = ln;
	address = add;
	this->contact = contact;
}

void Person::setName(string fn, string ln)
{
	firstName = fn;
	lastName = ln;
}

void Person::setAddress(string add)
{
	address = add;
}

void Person::setContact(string contact)
{
	this->contact = contact;
}

string Person::getName()
{
	return firstName + " " + lastName;
}

string Person::getFirstName()
{
	return firstName;
}

string Person::getLastName()
{
	return lastName;
}

string Person::getAddress()
{
	return address;
}

string Person::getContact()
{
	return contact;
}