#ifndef Included_StudentInfo_H
#define Included_StudentInfo_H

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;


class StudentInfo
{
    public:
            StudentInfo(){} //Constructor
            
            void set_StudentInfo(string, string, float, int);
            //Function to set all student info
            void set_StudentName(string);
            //Function to set student's name
            void set_StudentMatric(string);
            //Function to set student's matric number
            void set_Student_CGPA(float);
            //Function to set student's CGPA
            void set_StudentYear(int);
            //Function to set student's year of study
            
            //void get_StudentInfo(string, string, float, int);
            //Function to return all student info
            string get_StudentName();
            //Function to return student's name
            string get_StudentMatric();
            //Function to return student's matric number
            float get_Student_CGPA();
            //Function to return student's CGPA
            int get_StudentYear();
            //Function to return student's year of study
            
            void print_StudentInfo() const;
            //Display student info
            
            ~StudentInfo(); //Destructor;
            
    private:
    		string studentName;
    		string studentMatric;
    		float studentCGPA;
    		int studentYear;
};

void StudentInfo::set_StudentInfo(string n, string m, float c, int y)
{
	studentName = n;
	studentMatric = m;
	studentCGPA = c;
	studentYear = y;
}

void StudentInfo::set_StudentName(string n)
{
	studentName = n;
}

void StudentInfo::set_StudentMatric(string m)
{
	studentMatric = m;
}

void StudentInfo::set_Student_CGPA(float c)
{
	studentCGPA = c;
}

void StudentInfo::set_StudentYear(int y)
{
	studentYear = y;
}            

string StudentInfo::get_StudentName()
{
	return studentName;
}

string StudentInfo::get_StudentMatric()
{
	return studentMatric;
}

float StudentInfo::get_Student_CGPA()
{
	return studentCGPA;
}

int StudentInfo::get_StudentYear()
{
	return studentYear;
}

            
void StudentInfo::print_StudentInfo() const
{
	cout << left;
    cout << "\t" << setw(32) << studentName ;
    cout << "  " << setw(21) << studentMatric ;
    cout << "  " << setw(10) << studentYear ;
    cout << "  " << setw(8) << fixed << setprecision(2) << studentCGPA << endl;
}

StudentInfo::~StudentInfo()
{
	studentName = "";
	studentMatric = "";
	studentCGPA = 0.00;
	studentYear = 0;
}

#endif
