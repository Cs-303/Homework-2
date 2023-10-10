#pragma once
#include <iostream>
using namespace std;


//abstract class for employee
class Employee{
protected:
	string fullName;

public:
	//base class constructor
	Employee() { fullName = ""; };
	Employee(string fullName) { this->fullName = fullName; };

	//three virtual functions
	string name() { return fullName; };
	virtual double calculateWeeklySalary() = 0;
	virtual double calculateHealthCareContributions() = 0;
	virtual int calculateVacationDays() = 0;
};



//derived class for professional
class Professional : public Employee {
private:
	int monthlySalary;

public:
	//sub class constructor
	Professional(string fullName, int monthlySalary) : Employee(fullName) { this->monthlySalary = monthlySalary; };

	double calculateWeeklySalary() { return monthlySalary / 4; }; //return weekly salary done by 4 full weeks within a month. 
	double calculateHealthCareContributions() { return monthlySalary * .05; }; //calculates monthly salary * health care Contribution Rate (5%)
	int calculateVacationDays() { return 14; }; //professional usually get 2 weeks of vacation, so return 14 days
};



//derived class for nonProfessional
class nonProfessional : public Employee {
private:
	int hoursWorked;
	double hourlyRate;

public:
	//sub class constructor
	nonProfessional(string fullName, int hoursWorked, double hourlyRate) : Employee(fullName) {
		this->hoursWorked = hoursWorked;
		this->hourlyRate = hourlyRate;
	};

	double calculateWeeklySalary() { return hoursWorked * hourlyRate; }; //return weekly salary done by hours worked * hourly rate
	double calculateHealthCareContributions() { return (hoursWorked * hourlyRate) * .05; }; //calculates weekly salary * health care Contribution Rate (5%)
	int calculateVacationDays() { return hoursWorked / 36; }; //for every 36 hours worked, you get 1 day off
};