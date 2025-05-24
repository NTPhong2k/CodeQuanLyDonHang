#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;
class Employee {
protected:
    string name;
    int id;
    string position;

public:
    Employee(const string& name = "", int id = 0, const string& position = "")
        : name(name), id(id), position(position) {}

    virtual void displayInfo() const {
        cout << "Nhan vien: " << name << ", ID: " << id << ", Vi tri: " << position << endl;
    }

    virtual double calcSalary() const = 0; 

    virtual ~Employee() {}
};


class FullTimeEmployee : public Employee {
    double baseSalary;

public:
    FullTimeEmployee(const string& name = "", int id = 0, const string& position = "", double baseSalary = 0)
        : Employee(name, id, position), baseSalary(baseSalary) {}

    void displayInfo() const override {
        Employee::displayInfo();
        cout << "Loai: Toan thoi gian, Luong co ban: " << baseSalary << endl;
    }

    double calcSalary() const override {
        return baseSalary;
    }
};

class PartTimeEmployee : public Employee {
    int hoursWorked;
    double hourlyRate;

public:
    PartTimeEmployee(const string& name = "", int id = 0, const string& position = "", int hoursWorked = 0, double hourlyRate = 0)
        : Employee(name, id, position), hoursWorked(hoursWorked), hourlyRate(hourlyRate) {}

    void displayInfo() const override {
        Employee::displayInfo();
        cout << "Loai: Ban thoi gian, So gio lam: " << hoursWorked << ", Muc luong moi gio: " << hourlyRate << endl;
    }

    double calcSalary() const override {
        return hoursWorked * hourlyRate;
    }

    PartTimeEmployee& operator+=(int hours) {
        hoursWorked += hours;
        return *this;
    }
};

#endif
