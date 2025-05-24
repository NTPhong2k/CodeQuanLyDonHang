#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
    string productID;
    string name;
    double price;

public:
    Product() : productID(""), name(""), price(0.0) {}
    Product(string id, string n, double p)
        : productID(id), name(n), price(p) {}
    virtual ~Product() {}

    virtual void input() {
        cout << "Nhap ma san pham: ";
        cin >> productID;
        cin.ignore();
        cout << "Nhap ten san pham: ";
        getline(cin, name);
        cout << "Nhap gia: ";
        cin >> price;
    }

    virtual void output() const {
        cout << "Ma: " << productID << " | Ten: " << name << " | Gia: " << price;
    }

    virtual double getPrice() const {
        return price;
    }

    bool operator>(const Product& other) const {
        return price > other.price;
    }
};

class ElectronicProduct : public Product {
private:
    int warrantyMonths;

public:
    ElectronicProduct() : Product(), warrantyMonths(0) {}
    ElectronicProduct(string id, string n, double p, int wm)
        : Product(id, n, p), warrantyMonths(wm) {}

    void input() override {
        Product::input();
        cout << "Nhap so thang bao hanh: ";
        cin >> warrantyMonths;
    }

    void output() const override {
        Product::output();
        cout << " | Bao hanh: " << warrantyMonths << " thang" << endl;
    }

    double getPrice() const override {
        return price + (warrantyMonths * 10);
    }
};

#endif
