#include "student.h"
#include "degree.h"
#include <iostream>
#include <vector>

using namespace std;

// CONSTRUCTORS

Student::Student() {
	studentID = "";
	firstName = "";
	lastName = "";
	email = "";
	age = 0;
}

Student::Student(string sID, string inFirstName, string inLastName, string inEmail, int inAge, int courseDays1, int courseDays2, int courseDays3, DegreeProgram inProgram) {
	studentID = sID;
	firstName = inFirstName;
	lastName = inLastName;
	email = inEmail;
	age = inAge;
	courseDays.push_back(courseDays1);
	courseDays.push_back(courseDays2);
	courseDays.push_back(courseDays3);
	SetDegree(inProgram);
}

// MUTATORS

void Student::SetStudentID(string studentID) {
	this->studentID = studentID;
}

void Student::SetFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::SetLastName(string lastName) {
	this->lastName = lastName;
}

void Student::SetEmail(string email) {
	this->email = email;
}

void Student::SetAge(int age) {
	this->age = age;
}

void Student::SetCourseDays(int days1, int days2, int days3) {
	courseDays[0] = days1;
	courseDays[1] = days2;
	courseDays[2] = days3;
}

void Student::SetDegree(DegreeProgram programIn) {
	program = programIn;
}

// ACCESSORS

string Student::GetStudentID() const {
	return studentID;
}

string Student::GetFirstName() const {
	return firstName;
}

string Student::GetLastName() const {
	return lastName;
}

string Student::GetEmail() const {
	return email;
}

int Student::GetAge() const {
	return age;
}

int Student::GetCourseDays1() const {
	return courseDays[0];
}

int Student::GetCourseDays2() const {
	return courseDays[1];
}

int Student::GetCourseDays3() const {
	return courseDays[2];
}

DegreeProgram Student::GetDegree() const {
	return program;
}

// PRINTERS FOR SPECIFIC STUDENT DATA

void Student::PrintStudentID() {
	cout << studentID << endl;
}

void Student::PrintFirstName() {
	cout << firstName << endl;
}

void Student::PrintLastName() {
	cout << lastName << endl;
}

void Student::PrintEmail() {
	cout << email << endl;
}

void Student::PrintAge() {
	cout << age << endl;
}

void Student::PrintCourseDays1() {
	cout << courseDays[0] << endl;
}

void Student::PrintCourseDays2() {
	cout << courseDays[1] << endl;
}

void Student::PrintCourseDays3() {
	cout << courseDays[2] << endl;
}

void Student::PrintDegree() {
	// CONVERT DegreeProgram TO STRING FOR PRINTING
	string strProgram;
	if (program == DegreeProgram::SECURITY) {
		strProgram = "SECURITY";
	}
	else if (program == DegreeProgram::NETWORK) {
		strProgram = "NETWORK";
	}
	else if (program == DegreeProgram::SOFTWARE) {
		strProgram = "SOFTWARE";
	}
	cout << strProgram << endl;
}

// PRINTS STUDENT FULL RECORD

void Student::PrintRecord() {
	cout << studentID << "\t" << "First Name: " << firstName << "\t" << "Last Name: " << lastName << "\t" << "Age: " << age << "\t" << "daysInCourse: " << "{" << courseDays[0] << ", " << courseDays[1] << ", " << courseDays[2] << "} Degree Program: ";
	PrintDegree();
}
