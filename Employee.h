// Employee.h
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

class Employee {
protected:
    std::string name;
    int id;
    std::string position;

public:
    Employee(std::string name, int id, std::string position)
        : name(name), id(id), position(position) {}

    virtual void displayInfo() const {
        std::cout << "Ten: " << name << "\n";
        std::cout << "MSNV: " << id << "\n";
        std::cout << "Vi tri: " << position << "\n";
    }

    // ThĂªm hĂ m getId() á»Ÿ Ä‘Ă¢y
    int getId() const {
        return id;
    }

    virtual double calcSalary() const = 0; // Pure virtual function

    virtual ~Employee() {} // Virtual destructor
};

class FullTimeEmployee : public Employee {
private:
    double baseSalary;

public:
    FullTimeEmployee(std::string name, int id, std::string position, double baseSalary)
        : Employee(name, id, position), baseSalary(baseSalary) {}

    void displayInfo() const override {
        std::cout << "Loai: Nhan vien Full-time\n";
        Employee::displayInfo();
    }

    double calcSalary() const override {
        return baseSalary;
    }
};

class PartTimeEmployee : public Employee {
private:
    int hoursWorked;
    double hourlyRate;

public:
    PartTimeEmployee(std::string name, int id, std::string position, int hoursWorked, double hourlyRate)
        : Employee(name, id, position), hoursWorked(hoursWorked), hourlyRate(hourlyRate) {}

    void displayInfo() const override {
        std::cout << "Loai: Nhan vien Part-time\n";
        Employee::displayInfo();
    }

    double calcSalary() const override {
        return hoursWorked * hourlyRate;
    }
};

#endif
