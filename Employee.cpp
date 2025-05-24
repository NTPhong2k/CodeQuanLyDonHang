#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;
int main () {
class Employee {
protected:
    string name;
    int id;
    string position;

public:
    Employee(const string& name, int id, const string& position)
        : name(name), id(id), position(position) {}

    virtual void displayInfo() const {
        cout << "Nhan vien: " << name << ", ID: " << id << ", Vi tri: " << position << endl;
    }

    virtual double calcSalary() const = 0; // Ham ao thuan tuy cho da hinh

    virtual ~Employee() {}
};

class FullTimeEmployee : public Employee {
    double baseSalary;

public:
    FullTimeEmployee(const string& name, int id, const string& position, double baseSalary)
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
    PartTimeEmployee(const string& name, int id, const string& position, int hoursWorked, double hourlyRate)
        : Employee(name, id, position), hoursWorked(hoursWorked), hourlyRate(hourlyRate) {}

    void displayInfo() const override {
        Employee::displayInfo();
        cout << "Loai: Ban thoi gian, So gio lam: " << hoursWorked << ", Muc luong moi gio: " << hourlyRate << endl;
    }

    double calcSalary() const override {
        return hoursWorked * hourlyRate;
    }

    // Qua tai toan tu: tang so gio lam
    PartTimeEmployee& operator+=(int hours) {
        hoursWorked += hours;
        return *this;
    }
};

#endif
