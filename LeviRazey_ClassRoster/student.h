#ifndef STUDENTH
#define STUDENTH
#include "degree.h"
#include <vector>
#include <string>

using namespace std;

class Student {
public:
	// CONSTRUCTORS
	Student();
	Student(string sID, string inFirstName, string inLastName, string inEmail, int inAge, int courseDays1, int courseDays2, int courseDays3, DegreeProgram inProgram);
	
	// MUTATORS
	void SetStudentID(string studentID);
	void SetFirstName(string firstName);
	void SetLastName(string lastName);
	void SetEmail(string email);
	void SetAge(int age);
	void SetCourseDays(int days1, int days2, int days3);
	void SetDegree(DegreeProgram programIn);
	
	// ACCESSORS
	string GetStudentID() const;
	string GetFirstName() const;
	string GetLastName() const;
	string GetEmail() const;
	int GetAge() const;
	int GetCourseDays1() const;
	int GetCourseDays2() const;
	int GetCourseDays3() const;
	DegreeProgram GetDegree() const;
	
	// PRINTERS FOR SPECIFIC STUDENT DATA
	void PrintStudentID();
	void PrintFirstName();
	void PrintLastName();
	void PrintEmail();
	void PrintAge();
	void PrintCourseDays1();
	void PrintCourseDays2();
	void PrintCourseDays3();
	void PrintDegree();

	// PRINTS STUDENT FULL RECORD IN REQUIRED FORMAT
	void PrintRecord();

private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	vector<int> courseDays;
	DegreeProgram program;

};

#endif // !STUDENTH