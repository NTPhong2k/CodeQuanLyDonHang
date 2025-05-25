#ifndef PAYMENT_H
#define PAYMENT_H

#include <iostream>
#include <string>

// Lớp cha trừu tượng (đa hình)
class PaymentMethod {
protected:
    std::string methodName;

public:
    PaymentMethod(const std::string& name) : methodName(name) {}
    virtual ~PaymentMethod() {}

    virtual void printMethod() const = 0; // Hàm thuần ảo
};

// Lớp con: tiền mặt
class Cash : public PaymentMethod {
public:
    Cash() : PaymentMethod("Tien mat") {}

    void printMethod() const override {
        std::cout << "Phuong thuc thanh toan: " << methodName << std::endl;
    }
};

// Lớp con: thẻ ngân hàng
class CreditCard : public PaymentMethod {
private:
    std::string cardNumber;

public:
    CreditCard(const std::string& number)
        : PaymentMethod("The tin dung"), cardNumber(number) {}

    void printMethod() const override {
        std::cout << "Phuong thuc thanh toan: " << methodName
                  << " (So the: " << cardNumber << ")" << std::endl;
    }
};

// Lớp Payment chính
class Payment {
private:
    double amount;
    PaymentMethod* method; // con trỏ đa hình

public:
    Payment(double amt, PaymentMethod* mtd)
        : amount(amt), method(mtd) {}

    ~Payment() {
        delete method; // giải phóng bộ nhớ (cấp phát động)
    }

    // In thông tin thanh toán
    void display() const {
        std::cout << "So tien thanh toan: " << amount << " VND" << std::endl;
        method->printMethod(); // gọi đúng lớp con
    }

    // Toán tử so sánh
    bool operator>(const Payment& other) const {
        return amount > other.amount;
    }
};

#endif
