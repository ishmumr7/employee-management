#include "Person.h"
#include "Employee.h"
#include <bits/stdc++.h>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#define numOfEmp 100

using namespace std;


//Declaring necessary global variables
fstream appUsers("users.txt", ios::app);			//open file in append mode
Employee *emps = new Employee[numOfEmp];			//declaring out employee object as an array

int total = 0;										//number of records

//password check function
bool passCheck(string user, string pass);

//line printer
void line();

//Menu functions
void enterData();
void showData();
void searchData();
void updateData();
void deleteData();

//Function to print records in a file
void storeEmployees();

//Function to retrieve earlier records
void getData();

//Function to perform "press any key to continue"
void pressKeytoCont();

int main()
{
	string username, password;
	string enteredUsername, enteredPassword;

	//Retrieving previous data
	getData();

	//Initial Page
	initialScreen:
		
		line();
		cout << "\n\n\t\t\t\t\tEmployee Management System" << endl;
		line();
		cout << "\n\t\t\t\t\tPress: " << endl
			 << "\t\t\t\t\t1. Log in" << endl
			 << "\t\t\t\t\t2. Sign up" <<endl;
		
		char inp = _getch();
		system("CLS");

		switch (inp)
		{
		case '1':
			goto login;
			break;

		case '2':
			goto signup;
			break;

		default:
			cout << "\n\t\tInvalid Input!" << endl;
			goto initialScreen;
			break;
		}

	//Sign up page
	signup:
	
		line();
		cout << "\n\n\t\t\t\t\tEmployee Management System" << endl;
		line();
		cout << "\n\n\t\tSign Up" << endl;
		cout << "\n\t\tEnter Username: ";
		cin >> username;
		cout << "\n\t\tEnter Password: ";
		cin >> password;
		appUsers << username << "\t" << password << endl;
		cout << "\n\t\tCreating account. Please wait";

		//Displaying 3 dots in 1s interval
		for (int i = 0; i < 3; i++)
		{
			cout << ".";
			Sleep(1000);
		}
		cout << "\n\t\tAccount created successfully!" << endl;
		Sleep(1500);
		system("CLS");

	//Login page
	login:

		
		line();
		cout << "\n\n\t\t\t\t\tEmployee Management System" << endl;
		line();
		cout << "\n\n\t\tLog in" << endl;
		cout << "\n\t\tEnter Username: ";
		cin >> enteredUsername;
		cout << "\n\t\tEnter Password: ";
		cin >> enteredPassword;

		
		if (passCheck(enteredUsername, enteredPassword))
		{
			system("CLS");
			char inp;
			
			//Main Menu
			while (true)
			{
				cout << endl;
				line();
				cout << "\n\n\t\t\t\t\tEmployee Management System" << endl;
				line();
				cout << "\n\t\t\t\t\t\tMain Menu" << endl;
				line();
				cout << "\n\t\t\tPress: " << endl
					<< "\t\t\t1 to Enter Data" << endl
					<< "\t\t\t2 to Show Data" << endl
					<< "\t\t\t3 to Search Data" << endl
					<< "\t\t\t4 to Update Data" << endl
					<< "\t\t\t5 to Delete Data" << endl
					<< "\t\t\t6 to Log out" << endl
					<< "\t\t\t7 to Exit" << endl;

				inp = _getch();
				switch (inp)
				{
				case '1':
					enterData();
					system("CLS");
					break;

				case '2':
					showData();
					system("CLS");
					break;

				case '3':
					searchData();
					system("CLS");
					break;

				case '4':
					updateData();
					system("CLS");
					break;

				case '5':
					deleteData();
					system("CLS");
					break;

				case '6':
					goto initialScreen;
					break;

				case '7':
					exit(0);


				default:
					cout << "\aInvalid Input!" << endl;
					break;
				}
						
				

			}
		}
		else
		{
			cout << "Invalid username or password." << endl;
			Sleep(2000);
			system("CLS");
			goto initialScreen;
		}

	delete[] emps;
	return 0;
}



//Function definitions

bool passCheck(string user, string pass)
{
	bool check = false;
	string username, password;
	fstream inUsers("users.txt", ios::in);

	while (true)
	{
		int n = 0;
		if (inUsers.eof())
		{
			inUsers.close();
			break;
		}
		inUsers >> username >> password;
		if (user == username && pass == password)
		{
			return true;
		}
		else
		{
			check = false;
		}


	}
	return check;

}

void line()
{
	for (int i = 0; i < 120; i++)
	{
		cout << "-";
	}
	cout << endl;
}

void enterData()
{
	system("CLS");
	line();
	cout << "\n\n\t\t\t\t\tEmployee Management System" << endl;
	line();
	cout << "\n\t\t\t\t\tRegister Employee" << endl;
	line();


	string fn, ln, id, add, contact;
	double salary;
	int numRecords;
	cout << "\n\t\t\tEnter number of records to be added: ";
	cin >> numRecords;

	for (int i = total; i < total + numRecords; i++)
	{
		cout << "\n\n\t\t\tEnter Data of Employee " << i + 1 << endl <<endl;
		cout << "\t\t\tFirst Name: ";
		cin.ignore(1, '\n');
		getline(cin, fn, '\n');
		cout << "\t\t\tLast Name: ";
		getline(cin, ln, '\n');
		emps[i].setName(fn, ln);
		

		cout << "\t\t\tID: ";
		cin >> id;
		emps[i].setID(id);
		

		cout << "\t\t\tAddress: ";
		cin.ignore(1, '\n');
		getline(cin, add);
		emps[i].setAddress(add);
		

		cout << "\t\t\tContact no: +60 ";
		cin >> contact;
		emps[i].setContact(contact);
		

		cout << "\t\t\tSalary: ";
		cin >> salary;
		emps[i].setSalary(salary);
		
	}
	total += numRecords;
	storeEmployees();
	line();
	cout << "\n\t\t\t" << numRecords << " Record(s) added successfully!" << endl;
	Sleep(2000);

}
void showData()
{
	system("CLS");
	line();
	cout << "\n\n\t\t\t\t\tEmployee Management System" << endl;
	line();
	cout << "\n\n\t\t\t\t\tEmployee information" <<endl;
	line();
	cout << endl << endl;

	if (total != 0)
	{
		cout <<"\n\n\n";
		cout << left << setw(10) << "Sl no.";
		cout << left << setw(30) << "Name";
		cout << left << setw(12) << "ID";
		cout << left << setw(40) << "      Address";
		cout << left << setw(18) << "Contact";
		cout << left << setw(12) << "Salary" << endl;
		line();
		cout << endl;

		for (int i = 0; i < total; i++)
		{
			cout << left << setw(10) << i + 1;
			cout << left << setw(30) << emps[i].getName();
			cout << left << setw(12) << emps[i].getID();
			cout << left << setw(40) << emps[i].getAddress();
			cout << left << setw(18) << emps[i].getContact();
			cout << left << setw(12) <<fixed << setprecision(2) << emps[i].getSalary() << endl;
		}
		pressKeytoCont();
		
	}
	else
	{
		cout << "\a\n\t\t\tRecord is empty!" << endl;
		Sleep(3000);
	}
}
void searchData()
{
	system("CLS");
	line();
	cout << "\n\n\t\t\t\t\tEmployee Management System" << endl;
	line();
	cout << "\n\n\t\t\t\t\tSearch" <<endl;
	line();
	cout << endl << endl;
	for (int i = 0; i < 117; i++)
	{
		cout << '-';
	}

	if (total != 0)
	{
		string id;
		cout << "\n\t\t\tEnter ID of employee: ";
		cin >> id;
		for (int i = 0; i < total; i++)
		{
			if (emps[i].getID() == id)
			{
				cout << "\n\n\t\t\tData of Employee " << i + 1 << endl << endl;
				cout << "\t\t\tName: " << emps[i].getName() << endl;
				cout << "\t\t\tID: " << emps[i].getID() << endl;
				cout << "\t\t\tAddress: " << emps[i].getAddress() << endl;
				cout << "\t\t\tContact no: +60 " << emps[i].getContact() << endl;
				cout << "\t\t\tSalary: " << emps[i].getSalary() << endl;
				pressKeytoCont();
				break;
			}
			if (i == total - 1)	
			{
				cout << "\n\t\t\tNo such record found." << endl;
				Sleep(2500);
			}
		}
	}
	else
	{
		cout << "\a\n\t\t\tRecord is empty!" << endl;
		Sleep(2500);
	}
}
void updateData()
{
	system("CLS");
	line();
	cout << "\n\n\t\t\t\t\tEmployee Management System" << endl;
	line();
	cout << "\n\n\t\t\t\t\tUpdate Employee information" << endl;
	line();
	cout << endl << endl;
	if (total != 0)
	{
		string id;
		cout << "\n\t\t\tEnter ID of employee: ";
		cin >> id;
		for (int i = 0; i < total; i++)
		{
			if (emps[i].getID() == id)
			{
				cout << "\n\t\t\tCurrent Record: ";
				cout << "\n\n\t\t\tData of Employee " << i + 1 << endl << endl;
				cout << "\t\t\tName: " << emps[i].getName() << endl;
				cout << "\t\t\tID: " << emps[i].getID() << endl;
				cout << "\t\t\tAddress: " << emps[i].getAddress() << endl;
				cout << "\t\t\tContact no: +60 " << emps[i].getContact() << endl;
				cout << "\t\t\tSalary: " << emps[i].getSalary() << endl;

				string fn, ln, id, add, contact;
				double salary;
				cout << "\n\n\t\t\t Enter new record: ";
				cout << "\n\n\t\t\tFirst Name: ";
				cin.ignore(1, '\n');
				getline(cin, fn, '\n');
				cout << "\t\t\tLast Name: ";
				getline(cin, ln, '\n');
				emps[i].setName(fn, ln);
				

				cout << "\t\t\tID: ";
				cin >> id;
				emps[i].setID(id);
				

				cout << "\t\t\tAddress: ";
				cin.ignore(1, '\n');
				getline(cin, add);
				emps[i].setAddress(add);
				

				cout << "\t\t\tContact no: +60 ";
				cin >> contact;
				emps[i].setContact(contact);
				

				cout << "\t\t\tSalary: ";
				cin >> salary;
				emps[i].setSalary(salary);
				
				storeEmployees();

				cout << "\n\t\t\tData Updated Successfully!" << endl;
				Sleep(2500);

				break;
			}
			if (i == total - 1)
			{
				cout << "\n\t\t\tNo such record found." << endl;
				Sleep(2500);
			}
		}
	}
	else
	{
		cout << "\a\n\t\t\tRecord is empty!" << endl;
		Sleep(2500);
	}
}
void deleteData()
{
	system("CLS");
	line();
	cout << "\n\n\t\t\t\t\tEmployee Management System" << endl;
	line();
	cout << "\n\n\t\t\t\t\tDelete Employee information" << endl;
	line();
	cout << endl << endl;

	if (total != 0)
	{
		char inp;
		cout << "\n\n\t\tPress:"
			<< "\n\t\t\t1 to delete all records"
			<< "\n\t\t\t2 to delete a specific record" << endl;
		inp = _getch();

		if (inp == '1')
		{
			total = 0;
			cout << "\t\t\tAll records deleted! " << endl;
			Sleep(2500);
		}
		else if (inp == '2')
		{
			string id;
			cout << "\n\t\t\tEnter ID of employee: ";
			cin >> id;

			for (int i = 0; i < total; i++)
			{
				if (emps[i].getID() == id)
				{
					for (int j = 0; j < total; j++)
					{
						emps[j].setName(emps[j + 1].getFirstName(), emps[j + 1].getLastName());
						emps[j].setID(emps[j + 1].getID());
						emps[j].setAddress(emps[j + 1].getAddress());
						emps[j].setContact(emps[j + 1].getContact());
						emps[j].setSalary(emps[j + 1].getSalary());
						total--;
						storeEmployees();
						cout << "\n\t\t\tEmployee information deleted successfully!" << endl;
						Sleep(2500);
						break;
					}
					if (i == total - 1)
					{
						cout << "\n\t\t\tNo such record found." << endl;
						Sleep(2500);
					}
				}
			}
		}
		else
		{
			cout << "\t\t\tInvalid Input!" << endl;
			Sleep(2500);
		}
	}
	else
	{
		cout << "\a\n\t\t\tRecord is empty!" << endl;
		Sleep(2500);
	}

}

void storeEmployees()
{
	fstream empData("Employees.txt", ios::out);
	fstream storeDat("EmpDat.dat", ios::out);		//File to store and retrieve data when restarting the program

	storeDat << total << endl;

	//Printing captions
	empData << "\n\n\n";
	empData << left << setw(10) << "Sl no.";
	empData << left << setw(30) << "Name";
	empData << left << setw(12) << "ID";
	empData << left << setw(40) << "Address";
	empData << left << setw(18) << "Contact";
	empData << left << setw(12) << "Salary" << endl;
	for (int i = 0; i < 120; i++)
	{
		empData << '-';
	}
	empData << endl;

	if (total != 0)
	{
		for (int i = 0; i < total; i++)
		{
			empData << left << setw(10) << i + 1;
			empData << left << setw(30) << emps[i].getName();
			empData << left << setw(12) << emps[i].getID();
			empData << left << setw(40) << emps[i].getAddress();
			empData << left << setw(18) << emps[i].getContact();
			empData << left << setw(12) << fixed << setprecision(2) << emps[i].getSalary() << endl;

			storeDat << endl;
			storeDat << emps[i].getFirstName() <<endl;
			storeDat << emps[i].getLastName() << endl;
			storeDat << emps[i].getID() << endl;
			storeDat << emps[i].getAddress() << endl;
			storeDat << emps[i].getContact() << endl;
			storeDat << fixed << setprecision(2) << emps[i].getSalary() << endl;
		}
	}
	else 
	{
		empData << "";
	}
}

void getData()
{
	fstream getDat("EmpDat.dat", ios::in);
	string fn, ln, id, add, contact;
	double salary;
	int totEmps;

	getDat >> totEmps;

	for (int i = 0; i < totEmps; i++)
	{
		//if (getDat.eof())
		//{
		//	break;
		//}
		getDat.ignore();
		getDat >> fn;
		getDat >> ln;
		emps[i].setName(fn, ln);

		getDat >> id;
		emps[i].setID(id);

		getDat.ignore();
		getline(getDat, add);
		emps[i].setAddress(add);

		getDat >> contact;
		emps[i].setContact(contact);

		getDat >> salary;
		emps[i].setSalary(salary);
		getDat.ignore();

		total++;
	}
}

void pressKeytoCont()
{
	cout << "\n\n\t\t\t";
	system("pause");
}