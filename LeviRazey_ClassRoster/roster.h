#ifndef ROSTERH
#define ROSTERH
#include "student.h"
#include <iostream>

using namespace std;

class Roster {

public:
	// ARRAY OF POINTERS
	Student* classRosterArray[5];

	// DEFAULT CONSTRUCTOR
	Roster();

	// MEMBER FUNCTIONS
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);

	// DESTRUCTOR
	~Roster();

private:
	// KEEP TRACK OF WHERE TO ADD STUDENT IN ROSTER
	static int rosterLoc;
};

#endif // !ROSTERH