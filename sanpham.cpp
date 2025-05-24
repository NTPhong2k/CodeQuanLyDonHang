#define PRODUCT_H
#include <iostream>
#include <string>
using namespace std;
class Product {
protected:
    string productID;
    string name;
    int quantity;
    double unitPrice;
public:
    Product() : productID(""), name(""), quantity(0), unitPrice(0.0) {}
    Product(string id, string n, int q, double price)
        : productID(id), name(n), quantity(q), unitPrice(price) {
    }
    virtual ~Product() {}
    // Nhap tt sp
    virtual void input() {
        cout << "Nhap ma san pham: ";
        cin >> productID;
        cin.ignore();
        cout << "Nhap ten san pham: ";
        getline(cin, name);
        cout << "Nhap so luong: ";
        cin >> quantity;
        cout << "Nhap don gia: ";
        cin >> unitPrice;
    }
    // Xuat tt sp
    virtual void output() const {
        cout << "Ma SP: " << productID << " | Ten: " << name
            << " | SL: " << quantity << " | Don gia: " << unitPrice
            << " | Thanh tien: " << totalPrice() << endl;
    }
    // Tinh thanh tien
    virtual double totalPrice() const {
        return quantity * unitPrice;
    }
    // Toan tu so sanh gia
    bool operator>(const Product& other) const {
        return totalPrice() > other.totalPrice();
    }
};
// Lop ke thua sp dien tu
class ElectronicProduct : public Product {
private:
    int warrantyMonths;
public:
    ElectronicProduct() : Product(), warrantyMonths(0) {}
    ElectronicProduct(string id, string n, int q, double price, int wm)
        : Product(id, n, q, price), warrantyMonths(wm) {
    }
    void input() override {
        Product::input();
        cout << "Nhap thoi gian bao hanh (thang): ";
        cin >> warrantyMonths;
    }
    void output() const override {
        Product::output();
        cout << " | Bao hanh: " << warrantyMonths << " thang" << endl;
    }
};
int main() {
    int n;
    cout << "Nhap so luong san pham: ";
    cin >> n;
    Product** list = new Product * [n];
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin san pham thu " << i + 1 << ":\n";
        int type;
        cout << "Chon loai san pham (1. Thuong, 2. Dien tu): ";
        cin >> type;
        if (type == 2)
            list[i] = new ElectronicProduct();
        else
            list[i] = new Product();
        list[i]->input();
    }
    cout << "\n=== Danh sach san pham ===\n";
    for (int i = 0; i < n; i++) {
        list[i]->output();
    }
    // So sanh sp
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (*list[i] > *list[maxIndex])
            maxIndex = i;
    }
    cout << "\nSan pham co gia tri cao nhat:\n";
    list[maxIndex]->output();
    for (int i = 0; i < n; i++)
        delete list[i];
    delete[] list;
    return 0;
}
