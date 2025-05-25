#include <iostream>
#include <vector>
#include <string>
#include "Employee.h"

using namespace std;

vector<Employee*> employees;

void addEmployee() {
    int type;
    cout << "\n1. FullTime | 2. PartTime\nChon loai nhan vien: ";
    cin >> type;
    cin.ignore();

    string name, position;
    int id;
    cout << "Nhap ten: "; getline(cin, name);
    cout << "Nhap MSNV: "; cin >> id;
    cin.ignore();
    cout << "Nhap vi tri: "; getline(cin, position);

    if (type == 1) {
        double salary;
        cout << "Nhap luong co ban: "; cin >> salary;
        employees.push_back(new FullTimeEmployee(name, id, position, salary));
    } else if (type == 2) {
        int hours; double rate;
        cout << "Nhap so gio lam: "; cin >> hours;
        cout << "Nhap muc luong/gio: "; cin >> rate;
        employees.push_back(new PartTimeEmployee(name, id, position, hours, rate));
    }
    cout << "\nDa them nhan vien!\n";
}

void displayAll() {
    cout << "\n=== Danh sach nhan vien ===\n";
    for (int i = 0; i < employees.size(); ++i) {
        employees[i]->displayInfo();
        cout << "Luong: " << employees[i]->calcSalary() << "\n\n";
    }
}

void deleteEmployee() {
    int id;
    cout << "Nhap MSNV can xoa: ";
    cin >> id;
    for (int i = 0; i < employees.size(); ++i) {
        if (employees[i]->getId() == id) {
            delete employees[i];
            employees.erase(employees.begin() + i);
            cout << "Da xoa nhan vien.\n";
            return;
        }
    }
    cout << "Khong tim thay nhan vien.\n";
}

int main() {
    int choice;
    do {
        cout << "\n1. Them\n2. Hien thi\n3. Xoa\n0. Thoat\nChon: ";
        cin >> choice;
        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayAll(); break;
            case 3: deleteEmployee(); break;
            case 0: break;
            default: cout << "Lua chon sai.\n";
        }
    } while (choice != 0);

    for (int i = 0; i < employees.size(); ++i) delete employees[i];
    employees.clear();
    return 0;
}
