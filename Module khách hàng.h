#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Lop Nguoi
class Nguoi {
protected:
    string ten;
    string diaChi;
public:
    Nguoi() : ten(""), diaChi("") {}
    Nguoi(string t, string dc) : ten(t), diaChi(dc) {}

    virtual void nhap() {
        cout << "Nhap ten: ";
        getline(cin, ten);
        cout << "Nhap dia chi: ";
        getline(cin, diaChi);
    }

    virtual void xuat() const {
        cout << "Ten: " << ten << " | Dia chi: " << diaChi;
    }

    virtual ~Nguoi() {}
};

// Lop KhachHang ke thua tu Nguoi
class KhachHang : public Nguoi {
private:
    string maKH;
public:
    KhachHang() : Nguoi(), maKH("") {}
    KhachHang(string mkh, string t, string dc) : Nguoi(t, dc), maKH(mkh) {}

    void nhap() override {
        cout << "Nhap ma khach hang: ";
        getline(cin, maKH);
        Nguoi::nhap();
    }

    void xuat() const override {
        cout << "Ma KH: " << maKH << " | ";
        Nguoi::xuat();
        cout << endl;
    }

    string layMaKH() const {
        return maKH;
    }

    void capNhatDiaChi(const string& moi) {
        diaChi = moi;
    }
};

int main() {
    vector<KhachHang> danhSach;
    int n;

    cout << "Nhap so luong khach hang: ";
    cin >> n;
    cin.ignore(); // Xoa ky tu '\n' sau cin

    for (int i = 0; i < n; ++i) {
        cout << "\nNhap thong tin khach hang thu " << i + 1 << ":\n";
        KhachHang kh;
        kh.nhap();
        danhSach.push_back(kh);
    }

    cout << "\n=== Danh sach khach hang ===\n";
    for (size_t i = 0; i < danhSach.size(); ++i) {
        danhSach[i].xuat();
}
    // Tim kiem theo ma
    string maTim;
    cout << "\nNhap ma khach hang can tim: ";
    getline(cin, maTim);

    bool timThay = false;
   for (size_t i = 0; i < danhSach.size(); ++i) {
       if (danhSach[i].layMaKH() == maTim) {
            cout << "\nKhach hang tim thay:\n";
            danhSach[i].xuat();

            string diaChiMoi;
            cout << "\nNhap dia chi moi: ";
            getline(cin, diaChiMoi);
          danhSach[i].capNhatDiaChi(diaChiMoi);

            cout << "Thong tin sau cap nhat:\n";
             danhSach[i].xuat();

            timThay = true;
            break;
        }
    }

    if (!timThay) {
        cout << "Khong tim thay khach hang co ma: " << maTim << endl;
    }

    return 0;
}
