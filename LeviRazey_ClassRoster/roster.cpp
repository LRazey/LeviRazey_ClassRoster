#include "roster.h"
#include "student.h"
#include <iostream>
#include <string>

using namespace std;

int Roster::rosterLoc = 0;

//CONSTRUCTOR

Roster::Roster() {
}

// MEMBER FUNCTIONS

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
	classRosterArray[rosterLoc] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);
	rosterLoc++;
}

void Roster::remove(string studentID) {
	bool found = false;
	// LOOP THROUGH ROSTER TO FIND studentID
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->GetStudentID() == studentID) {
			found = true;
			// SLIDE ELEMENTS DOWN THE ARRAY
			for (i; i < 4; i++) {
				classRosterArray[i] = classRosterArray[i + 1];
			}
			// LAST ELEMENT BECOMES EMPTY
			classRosterArray[4] = new Student();
			rosterLoc = 4;
			cout << "Student " << studentID << " has been removed" << endl;
			break;
		}
	}
	if (!found) {
		cout << "Student ID not found" << endl;
	}
}

void Roster::printAll() {
	for (int i = 0; i < 5; i++) {
		// DOES NOT PRINT IF IS EMPTY STUDENT ELEMENT
		if (classRosterArray[i]->GetStudentID() != "") {
			classRosterArray[i]->PrintRecord();
		}
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	bool found = false;
	// LOOP THROUGH ARRAY TO FIND studentID
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->GetStudentID() == studentID) {
			found = true;
			cout << "Student ID: " << studentID << ", average days in course: " << (classRosterArray[i]->GetCourseDays1() + classRosterArray[i]->GetCourseDays2() + classRosterArray[i]->GetCourseDays3()) / 3 << endl;
			break;
		}
	}
	if (!found) {
		cout << "Student ID not found" << endl;
	}
}

void Roster::printInvalidEmails() {
	bool hasAt = false;
	bool hasPeriod = false;
	bool hasSpace = false;
	string currStr;
	// LOOP THROUGH ARRAY
	for (int i = 0; i < 5; i++) {
		// ASSIGN EMAIL TO currStr FOR SIMPLER STRING OPERATION
		currStr = classRosterArray[i]->GetEmail();
		for (int j = 0; j < currStr.size(); j++) {
			if (currStr.at(j) == '@') {
				hasAt = true;
			}
			if (currStr.at(j) == '.') {
				hasPeriod = true;
			}
			if (isspace(currStr.at(j))) {
				hasSpace = true;
			}
		}
		if (!hasAt || !hasPeriod || hasSpace) {
			cout << currStr << " is not a valid email." << endl;
		}
		// RESET BOOLEANS TO FALSE
		hasAt = false;
		hasPeriod = false;
		hasSpace = false;
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->GetDegree() == degreeProgram) {
			classRosterArray[i]->PrintRecord();
		}
	}
}

// DESTRUCTOR

Roster::~Roster() {
	// LOOP THROUGH ARRAY AND DELETE EACH ELEMENT
	for (int i = 0; i < 5; i++) {
		delete classRosterArray[i];
	}
	cout << "Releasing memory" << endl;
}
