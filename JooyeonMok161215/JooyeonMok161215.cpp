//Jooyeon Mok 12/15/2016
//Section 2 - customer management application


#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

struct Person
{
	string f_name;
	string l_name;
}name, temp_name;

struct Phone
{
	int reg_code;
	int home_code;
}phonenumber, temp_phonenumber;

struct customer
{
	int cust_number;
	Person name;
	string email;
	Phone phonenumber;
}client[10],temp_client;

void intro(); 
Person getting_temp_name();
Phone getting_temp_phonenumber();
customer temp(int c_num); 
int google(customer client[], int number_of_add, int target); 
void show_google(int temp_index); 
void list(customer client[], int i);


int main()
{
	int choice, c_num = 16001, number_of_add(0);

	do {
	intro();
	cin  >> choice;

		switch (choice)
		{
			case 1 :
				{
					int size(10), fin(1); 
					while((size > 0)&&(fin != 0))
					{	
						cout << "*** " << size << " Customers can be entered. ***" <<endl; 
						

						getting_temp_name();
						getting_temp_phonenumber();
						
						
						temp(c_num); 
					
						client[number_of_add] = temp_client;

						
						c_num = c_num + 1; 
						cout << "To keep adding customers, please enter 1. To quit, enter 0." <<endl;
						cin  >> fin;
						number_of_add = number_of_add + 1; 
						size = size - 1; 

						if (size == 0) 
							{
								cout << "You have reached the maximum number that you can enter." <<endl
									 << "Going back to the main menu" <<endl;
								number_of_add = number_of_add - 1; 
										system ("pause");
										system ("cls");
							}
						else {
							if (fin == 0) 
							{
								cout << "Going back to the main menu" <<endl;
								number_of_add = number_of_add - 1;
								system ("pause");
								system ("cls");
							}}}}
			break;

			case 2 : 
				{
					int fin(1), temp_index; 
					do
					{
						int target; 

						cout << "Search for a customer by the customer number." <<endl
							 << "The customer numbers are started from 16001"<<endl
							 << "Enter the customer number : ";
						cin  >> target;

						google(client, number_of_add, target); 

						if(google(client, number_of_add, target) == -1) 
						{
							cout << "There is no result. Please search it again." <<endl;
						}
						else 
						{
							temp_index = google(client, number_of_add, target); 
							 show_google(temp_index); 
							 cin >> fin;
						}
					}while(fin != 0);
				}


			break;

			case 3 :
				{
					cout <<" Customer number " << "           Name           " << "         Email        " <<" Phone number " <<endl
						 <<"-----------------" << "--------------------------" << "----------------------" <<"--------------" <<endl;

					for (int i=0; i<=number_of_add; i++)
						{
							list(client, i);
					    }

					system("pause");
				}

			break;

			case 4 : 
				{ 
					cout << "Have a good day!" <<endl;
					choice = 4;
					system ("pause");
				}
			break;

			default: 
				{
					system ("cls");
					cout << "You have entered a wrong number" <<endl
						 << "To finish the program, please enter 4."<<endl
						 << "To go back to the main menu, please enter any other number." <<endl;
					cin  >> choice;
					
				}



	
		}}while(choice != 4);

	return 0;
}

void intro()
{
		system ("cls");
		cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * " <<endl
		     << "* * * *         Customer Management Application       * * * * " <<endl
			 << "*                                                           * " <<endl;
		cout << "*           1 : Create and add a Customer                   * " <<endl
			 << "*           2 : Search for a customer by number             * " <<endl
			 << "*           3 : Display the customer list                   * " <<endl
			 << "*           4 : Exit the application                        * " <<endl
 			 << "*                                                           * " <<endl
			 << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * " <<endl
			 << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * " <<endl;
}


Person getting_temp_name()
{
	cout << "Last   name					   : " ;
	cin.ignore();
	getline(cin, temp_name.l_name);
	cout << "First  name					   : " ;
	cin.ignore();
	getline(cin, temp_name.f_name);

	return temp_name;
}


Phone getting_temp_phonenumber()
{
	cout << "Phone regional code (3 digits)			 : " ;
	cin >> temp_phonenumber.reg_code;
	cout << "Phone regional code (7 digits)			 : " ;
	cin >> temp_phonenumber.home_code;

	return temp_phonenumber;
}


customer temp(int c_num) 
{
	int index = 0; 
	cin.clear();
	cout << "Email address					   : " ;
	cin.ignore();
	getline(cin, temp_client.email);
	cout << "<< The customer number is automatically generated >>" <<endl;
	cout << "Customer number                   : " << c_num <<endl; 
	temp_client.cust_number = c_num;
	temp_client.name = temp_name;
	temp_client.phonenumber = temp_phonenumber;
	
	
	return temp_client;
}

int google(customer client[], int number_of_add, int target)
{
	int index = 0;
	bool found = false; 
	while((found==false)&&(index <= number_of_add))
	{
		if (target == client[index].cust_number)
			{found = true;} 
				else {index++;} 
	}
	
	if (found == true) 
	{return index;} 
	else
	{return -1;}
}

void show_google(int temp_index)
{
	cout << "Result            : " << client[temp_index].name.f_name << " " << client[temp_index].name.l_name << "\n\n\n";
	cout << "Name              : " << client[temp_index].name.f_name << " " << client[temp_index].name.l_name << endl;
	cout << "client  number    : " << client[temp_index].cust_number<<endl;
	cout << "email             : " << client[temp_index].email<<endl;
	cout << "Phone Number      : " << client[temp_index].phonenumber.reg_code<< " " << client[temp_index].phonenumber.home_code <<endl; 
	cout << "To go back to the main menu, enter 0.\nTo keep searching, enter 1."<<endl; 
}


void list(customer client[], int i) 
{
	cout.width(17);
	cout <<left << client[i].cust_number;
	cout.width(27);
	cout <<left << client[i].name.f_name <<" "<< client[i].name.l_name;
	cout.width(22);
	cout <<left << client[i].email; 
	cout.width(14);
	cout <<left << client[i].phonenumber.reg_code<<"-"<<phonenumber.home_code;
}