#include <iostream>
#include <sstream>
#include <string>
#include "roster.h"
#include "student.h"

using namespace std;

int main() {
	// COURSE TITLE, PROGRAMMING LANGUAGE, WGU STUDENT ID, NAME
	cout << "Scripting and Programming - Applications - C867" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: #*********" << endl;
	cout << "Name: Levi Razey" << endl;
	cout << endl;

	// STUDENT DATA TABLE
	const string studentData[] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Levi,Razey,fakeemail@fake.com,29,13,30,42,SOFTWARE"};

	Roster classRoster;

	// PARSE STUDENT DATA TABLE AND ADD TO ROSTER
	for (int i = 0; i < 5; i++) {
		istringstream inSS(studentData[i]);
		string sID;
		string fName;
		string lName;
		string email;
		string strAge;
		string strDays1;
		string strDays2;
		string strDays3;
		string strDegree;
		DegreeProgram degree;

		getline(inSS, sID, ',');
		getline(inSS, fName, ',');
		getline(inSS, lName, ',');
		getline(inSS, email, ',');
		getline(inSS, strAge, ',');
		getline(inSS, strDays1, ',');
		getline(inSS, strDays2, ',');
		getline(inSS, strDays3, ',');
		getline(inSS, strDegree);

		// CONVERT STRING TO INT
		int age = stoi(strAge);
		int days1 = stoi(strDays1);
		int days2 = stoi(strDays2);
		int days3 = stoi(strDays3);

		// CONVERT STRING TO DEGREEPROGRAM
		if (strDegree == "SECURITY") {
			degree = DegreeProgram::SECURITY;
		}
		else if (strDegree == "NETWORK") {
			degree = DegreeProgram::NETWORK;
		}
		else if (strDegree == "SOFTWARE") {
			degree = DegreeProgram::SOFTWARE;
		}

		// ADD STUDENT TO ROSTER
		classRoster.add(sID, fName, lName, email, age, days1, days2, days3, degree);
	}

	// PRINT ALL STUDENTS
	cout << "All Students:" << endl;
	classRoster.printAll();
	cout << endl;

	// PRINT INVALID EMAILS
	cout << "Invalid emails:" << endl;
	classRoster.printInvalidEmails();
	cout << endl;

	// PRINT EACH STUDENT'S AVERAGE DAYS IN COURSES
	cout << "Display each student's average days in courses:" << endl;
	for (int i = 0; i < 5; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentID());
	}
	cout << endl;

	// PRINT STUDENTS BY DEGREE
	cout << "Students by degree:" << endl;
	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
	cout << endl;

	// REMOVE STUDENT A3
	cout << "Removing student A3" << endl;
	classRoster.remove("A3");
	cout << endl;

	// PRINT ALL STUDENTS
	cout << "Printing all students" << endl;
	classRoster.printAll();
	cout << endl;

	// TRY TO REMOVE A3 AGAIN
	cout << "Removing student A3 again" << endl;
	classRoster.remove("A3");
	cout << endl;

}
