#include <iostream>
#include <vector>
#include "KhachHang.h"
int main() {
    vector<KhachHang> danhSachKhachHang;
    int luaChon;

    do {
        cout << "\n====== MENU QUAN LY DON HANG ======\n";
        cout << "1. Them khach hang\n";
        cout << "2. Hien thi danh sach khach hang\n";
        cout << "3. Tim va cap nhat dia chi khach hang\n";
        cout << "0. Thoat\n";
        cout << "Lua chon cua ban: ";
        cin >> luaChon;
        cin.ignore();

        switch (luaChon) {
            case 1: {
                KhachHang kh;
                kh.nhap();
                danhSachKhachHang.push_back(kh);
                break;
            }
            case 2: {
                cout << "\n=== Danh sach khach hang ===\n";
                for (const auto& kh : danhSachKhachHang)
                    kh.xuat();
                break;
            }
            case 3: {
                string maTim;
                cout << "Nhap ma khach hang can tim: ";
                getline(cin, maTim);

                bool timThay = false;
                for (auto& kh : danhSachKhachHang) {
                    if (kh.layMaKH() == maTim) {
                        cout << "Khach hang tim thay:\n";
                        kh.xuat();

                        string diaChiMoi;
                        cout << "\nNhap dia chi moi: ";
                        getline(cin, diaChiMoi);

                        kh.capNhatDiaChi(diaChiMoi);
                        cout << "Cap nhat thanh cong!\nThong tin moi:\n";
                        kh.xuat();

                        timThay = true;
                        break;
                    }
                }
                if (!timThay)
                    cout << "Khong tim thay khach hang co ma: " << maTim << endl;
                break;
            }
            case 0:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }

    } while (luaChon != 0);

    return 0;
}
