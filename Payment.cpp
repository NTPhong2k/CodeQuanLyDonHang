#include <iostream>
#include "Payment.h"
using namespace std;

int main() {
    // Tạo hai đối tượng thanh toán
    Payment p1(100.50, "Cash", "Pending");
    Payment p2(200.75, "Card", "Completed");

    // Hiển thị thông tin thanh toán
    cout << "Payment 1:" << endl;
    cout << p1 << endl;

    cout << "Payment 2:" << endl;
    cout << p2 << endl;

    // Sử dụng các tính năng của module
    p1.updateStatus("Completed");
    p1.updateMethod("Online");
    p1.addNote("Paid via bank transfer");

    // Hiển thị lại thông tin sau khi cập nhật
    cout << "\nUpdated Payment 1:" << endl;
    cout << p1 << endl;

    // Sử dụng toán tử + để cộng dồn số tiền
    Payment p3 = p1 + p2;
    cout << "\nCombined Payment (P1 + P2):" << endl;
    cout << p3 << endl;

    return 0;
}