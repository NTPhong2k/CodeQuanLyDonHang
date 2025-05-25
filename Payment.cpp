#include "Payment.h"
#include <limits>

int main() {
    double amount;
    int choice;
    std::string cardNumber;

    std::cout << "===== QUAN LY THANH TOAN =====" << std::endl;

    // Nhập số tiền
    std::cout << "Nhap so tien can thanh toan (VND): ";
    while (!(std::cin >> amount) || amount < 0) {
        std::cout << "So tien khong hop le. Vui long nhap lai: ";
        std::cin.clear(); // clear error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
    }

    // Chọn phương thức
    std::cout << "Chon phuong thuc thanh toan:\n1. Tien mat\n2. The tin dung\nLua chon: ";
    while (!(std::cin >> choice) || (choice != 1 && choice != 2)) {
        std::cout << "Lua chon khong hop le. Vui long nhap 1 hoac 2: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    PaymentMethod* method = nullptr;
    if (choice == 1) {
        method = new Cash();
    } else {
        std::cout << "Nhap so the: ";
        std::cin.ignore(); // xóa newline còn sót
        std::getline(std::cin, cardNumber);
        method = new CreditCard(cardNumber);
    }

    // Tạo và hiển thị đơn thanh toán
    Payment payment(amount, method);
    std::cout << "\n===== THONG TIN THANH TOAN =====\n";
    payment.display();

    return 0;
}
