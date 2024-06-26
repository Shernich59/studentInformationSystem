
#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
#include "Linkedlist.h"
#include "StudentInfo.h"

using namespace std;

void header();
void printMenu();
//Function to show menu

int main()
{
	StudentInfo HomoSapien;
	orderedLinkedList<StudentInfo> OrderedLL;
	unorderedLinkedList<StudentInfo> UnorderedLL;
	
	bool isSystemOn = true;
	int choice;
	string n,m;
	float c;
	int y;

	while(isSystemOn)
	{
		header();
		printMenu();
		cout << endl;
		cout << "\tChoice: ";
		cin >> choice;
		
		switch(choice)
		{
			case 1: //Add information
					{
						cin.clear();
						cin.ignore(1000,'\n');
						
						system("cls");
						header();
						
						cout << "\tAdd Student Information: " << endl;
						cout << "=========================================================================================" << endl;
						cout << "\n\t-> Name: ";
						getline(cin, n);
						
						cout << "\t-> Matric Number: ";
						getline(cin, m);
						
						cout << "\t-> CGPA: ";
						cin >> c;
						while ((c < 0.00) || (c>4.00) || cin.fail())
						{
								cin.clear();
								cin.ignore(1000,'\n');
								cout << "\t   Invalid CGPA..." << endl;
								cout << "\t   Re-enter CGPA: ";
								cin >> c;
						}
						
						cin.clear();
						cin.ignore(1000,'\n');
						cout << "\t-> Year of study: ";
						cin >> y;
						while ((y < 1) || (y>5) || cin.fail())
						{
							cin.clear();
							cin.ignore(1000,'\n');
							cout << "\t   Invalid Year of Study..." << endl;
							cout << "\t   Re-enter Year of Study: ";
							cin >> y;
						}
						
						HomoSapien.set_StudentInfo(n,m,c,y);												
						UnorderedLL.insertFirst(HomoSapien);
						OrderedLL.insert(HomoSapien);
						system("pause");				
						system("cls");
						break;
					}	
		
			case 2: //Delete information
					{
						system("cls");
						header();
						
						cout << "\n";	
						OrderedLL.print(); //To display the student data list
						cout << "\n";
						
						cout << endl << endl << endl;
						cout << "\tDelete Student Information: " << endl;
						cout << "=========================================================================================" << endl;
						cin.clear();
						cin.ignore(1000,'\n');
						
						cout << "\tMatric number: ";
						getline(cin, m);
											
						UnorderedLL.deleteNode(m);
						OrderedLL.deleteNode(m);	
						system("pause");	
						system("cls");
						break;
					}
					
			case 3: //Search information
					{
						system("cls");
						header();
						
						cout << "\tSearch Student Information: " << endl;
						cout << "=========================================================================================" << endl;
						
						cin.clear();
						cin.ignore(1000,'\n');
						
						cout << "\tMatric number: ";
						getline(cin, m);
						
						cout << endl << endl << endl;
						UnorderedLL.search(m);
						cout << endl << endl << endl;
						
						OrderedLL.search(m);
						cout << endl << endl << endl;
						
						system("pause");	
						system("cls");
						break;
					}
					
			case 4: //Display Student Information
					{
						cin.clear();
						cin.ignore(1000,'\n');
						system("cls");
						header();
						
						cout << "\tDisplay Student Information: " << endl;
						cout << "=========================================================================================" << endl;
						
						cout << "\n\tPrint Student Information using Ordered Linked List" << endl;
						OrderedLL.print();
						
						cout << "\n\n\tPrint Student Information using Unordered Linked List" << endl;
						UnorderedLL.print();
						system("pause");	
						system("cls");
						break;
					}
			
			case 5: 
					{
						system("cls");
						header();
						cout << "\t\t\t     < Closing the Program >" << endl << endl;
						system("pause");
						return 0;
					}
					
			default: 
					{
						system("cls");
						header();
						cout << "\tInvalid input..." << endl << endl;
						cout << "\tPlease enter 1 to 5 ONLY" << endl << endl;
						cout << "\tPress \"Enter\" to return to Menu..." << endl << endl;
						
						cin.clear();
						cin.ignore(1000,'\n');
						system("pause");	
						system("cls");
						break;
					}
			
		}
	}
}

void header()
{
	cout << "\n\n\n";
	cout << "\t\t\tWELCOME TO UNIVERSITI SAINS MALAYSIA\n";
	cout << "\t\t\t    Student Information System\n\n";
	cout << endl << endl;
}

void printMenu()
{

	cout << "\tThis program is to store and organize students' information " << endl;
	cout << "=========================================================================================" << endl;
	cout << "\n        Student's Information: " << endl;
	cout << "\n         # Add --------------------------------------------------------- Enter '1'" << endl;
	cout << "\n         # Delete ------------------------------------------------------ Enter '2'" << endl;
	cout << "\n         # Search & Display -------------------------------------------- Enter '3'" << endl;
	cout << "\n         # Display Full Information List ------------------------------- Enter '4'" << endl;
	cout << "\n         # Exit Program ------------------------------------------------ Enter '5'" << endl;
	cout << endl;
	cout << "=========================================================================================" << endl;
}


