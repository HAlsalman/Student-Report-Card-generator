//HASSAN ALSALMAN
//============================ HEADER FILES ============================
//======================================================================
#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>               //time clock object.
#include <vector>
#pragma warning(disable:4996) //disable error C4996 regarding local time function (asctime).
							  //reference:docs.microsoft/warning pragma.

using namespace std;

void intro();
void main_menu();
void time();
void clrscr();
void pause();

//==================== CLASS USED IN THE PROJECT =======================
//======================================================================
class student{
private:
	int IDnum;                                          //student ID number.
	string name;                                        //student name.
	double p_grade, c_grade, m_grade, e_grade, cs_grade;//variables to hold grades value.
	double average;                                     //student's average grade.
	char LetterGrade;                                   //student's letter grade.        
	void calculate(){                                 //calculate average from all grades.
		average = (p_grade + c_grade + m_grade + e_grade + cs_grade) / 5.0; 
		if (average >= 90)
			LetterGrade = 'A';
		else if (average >= 80 && average < 90)
			LetterGrade = 'B';
		else if (average >= 70 && average < 80)
			LetterGrade = 'C';
		else if (average >= 60 && average < 70)
			LetterGrade = 'D';
		else
			LetterGrade = 'F';
	}
public:
	void getdata(){
		cout << "\nEnter The ID number of the student: ";
		cin >> IDnum;
		cout << "\nEnter The Name of the student: ";
		cin >> name;
		cout << "\nEnter The grade in physics: ";
		cin >> p_grade;
		cout << "\nEnter The grade in chemistry: ";
		cin >> c_grade;
		cout << "\nEnter The grade in maths: ";
		cin >> m_grade;
		cout << "\nEnter The grade in english: ";
		cin >> e_grade;
		cout << "\nEnter The grade in computer science: ";
		cin >> cs_grade;
		calculate();                    //call function to calculate the average grade.
		cout << endl << endl << name << "'s grades have been recorded successfully." << endl << endl;
	pause();
	main_menu();
	}

	void showdata(){
		cout << "\nID number of the student: " << IDnum;
		cout << "\nName of student: " << name;
		cout << "\ngrade in Physics: " << p_grade;
		cout << "\ngrade in Chemistry: " << c_grade;
		cout << "\ngrade in Maths: " << m_grade;
		cout << "\ngrade in English: " << e_grade;
		cout << "\ngrade in Computer Science: " << cs_grade;
		cout << "\nAverage grade for " << name << " is: " << setprecision(2) << average;
		cout << "\nLetter Grade of " << name << " is: " << LetterGrade << endl << endl;
	pause();
	main_menu();
	}

	void show_report(){               //to show the grades in rows for all students.
		cout << IDnum << setw(12) << name << setw(10) << p_grade 
			<< setw(3) << c_grade << setw(3) << m_grade << setw(3) 
			<< e_grade << setw(3) << cs_grade << setw(6) << setprecision(3) 
			<< average << "   " << LetterGrade << endl;
	}

	int  getIDnum(){
		return IDnum;
	}
};                          //class ends here.

//======================== GLOBAL DECLIRATIONS =========================
//======================================================================
student pupil; //class object.

//==================== MAIN FUNCTION OF THE PROGRAM ====================
//======================================================================
/**************************************************************************************************************/
int main() {
	intro();
	main_menu();
}
/**************************************************************************************************************/

void clrscr() { //clear screen.
	system("cls");
}
void pause() { //press any key to continue...
	system("pause");
}
void time() {
	time_t t = time(NULL);                             //current date and time based on current system.
	cout << "Current time & date: \n" << asctime(localtime(&t)); //reference: en.cppreference.com/w/c/chrono/localtime
}

//=========================== WELCOME SCREEN ===========================
//======================================================================
void intro() {
	clrscr();
	cout << "\n\n\n\tSTUDENT ";
	cout << "REPORT CARD ";
	cout << "PROJECT." << endl << endl;
	cout << "\n\n\tMADE BY : Hassan ALsalman." << endl;
	cout << endl << endl << " \n\t";
	pause();
	main_menu();
}

//============================= MAIN MENU ==============================
//======================================================================
void main_menu() {
	clrscr();
	char ch2;
	time();
	cout << "\n\n\n\tMAIN MENU";
	cout << "\n\n\t1.CREATE NEW STUDENT RECORD";
	cout << "\n\n\t2.DISPLAY STUDENT RECORD";
	cout << "\n\n\t3.BACK TO WELCOME SCREEN";
	cout << "\n\n\tPlease Enter Your Choice (1-3) ";
	cin >> ch2;
	switch (ch2) {
	case '1':
		pupil.getdata();
		break;
	case '2':
		pupil.showdata();
		break;
	case '3':
		intro();
		break;
	default:
		cout << "\a";
		main_menu();
	}
}

//========================= END OF THE PROJECT =========================
//======================================================================