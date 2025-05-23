#pragma once
#include <iostream>
#include <string>
using namespace std;

// Lớp cơ sở trừu tượng để thể hiện tính đa hình
class PaymentBase {
protected:
    double amount;
    string status;
public:
    PaymentBase(double amt = 0.0, string st = "Pending") : amount(amt), status(st) {}
    virtual ~PaymentBase() {}
    virtual void display() const = 0; // Hàm ảo thuần túy
    virtual void updateStatus(string newStatus) {
        status = newStatus;
        cout << "Status updated to: " << status << endl;
    }
    double getAmount() const { return amount; }
};

// Lớp Payment kế thừa từ PaymentBase
class Payment : public PaymentBase {
private:
    string method; // Phương thức thanh toán (Cash, Card, Online)
    string* notes; // Mảng động để lưu ghi chú
    int noteCount; // Số lượng ghi chú
    int maxNotes;  // Kích thước tối đa của mảng ghi chú
public:
    // Hàm tạo
    Payment(double amt = 0.0, string meth = "Cash", string st = "Pending")
        : PaymentBase(amt, st), method(meth), noteCount(0), maxNotes(5) {
        notes = new string[maxNotes]; // Cấp phát động
    }

    // Hàm huỷ
    ~Payment() {
        delete[] notes; // Giải phóng bộ nhớ động
    }

    // Ghi đè hàm display (overriding)
    void display() const override {
        cout << "Payment Details:" << endl;
        cout << "Amount: $" << amount << endl;
        cout << "Method: " << method << endl;
        cout << "Status: " << status << endl;
        cout << "Notes: ";
        if (noteCount == 0) cout << "None";
        else {
            for (int i = 0; i < noteCount; i++) {
                cout << notes[i] << (i < noteCount - 1 ? ", " : "");
            }
        }
        cout << endl;
    }

    // Tính năng: Thêm ghi chú
    void addNote(string note) {
        if (noteCount < maxNotes) {
            notes[noteCount++] = note;
            cout << "Note added: " << note << endl;
        } else {
            cout << "Cannot add more notes. Storage full." << endl;
        }
    }

    // Tính năng: Cập nhật phương thức thanh toán
    void updateMethod(string newMethod) {
        method = newMethod;
        cout << "Payment method updated to: " << method << endl;
    }

    // Quá tải toán tử << để in thông tin
    friend ostream& operator<<(ostream& os, const Payment& p) {
        p.display();
        return os;
    }

    // Quá tải toán tử + để cộng dồn số tiền
    Payment operator+(const Payment& other) const {
        Payment result(amount + other.amount, method, status);
        return result;
    }
};