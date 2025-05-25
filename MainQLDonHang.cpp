#include <iostream>
#include <vector>
#include <memory>
#include "KhachHang.h"
#include "OrderModule.h"
#include "Employee.h"
#include "sanpham.h"
#include "Payment.h"

using namespace std;

int main() {
    vector<KhachHang> dsKhach;
    OrderManager dsDon;
    vector<unique_ptr<Employee>> dsNhanVien;
    vector<unique_ptr<Product>> dsSanPham;
    vector<Payment> dsThanhToan;

    int choice;
    do {
        cout << "\n===== MENU CHINH =====\n";
        cout << "1. Quan ly Khach Hang\n";
        cout << "2. Quan ly Don Hang\n";
        cout << "3. Quan ly Nhan Vien\n";
        cout << "4. Quan ly San Pham\n";
        cout << "5. Quan ly Thanh Toan\n";
        cout << "0. Thoat\n";
        cout << "Lua chon: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            int ch;
            cout << "\n-- KHACH HANG --\n1. Them\n2. Xoa\n3. Sua\n4. Hien thi\nLua chon: ";
            cin >> ch; cin.ignore();
            if (ch == 1) {
                KhachHang kh;
                kh.nhap();
                dsKhach.push_back(kh);
            } else if (ch == 2) {
                string ma;
                cout << "Nhap ma KH can xoa: ";
                getline(cin, ma);
                dsKhach.erase(remove_if(dsKhach.begin(), dsKhach.end(), [&ma](KhachHang& k) {
                    return k.layMaKH() == ma;
                }), dsKhach.end());
            } else if (ch == 3) {
                string ma;
                cout << "Nhap ma KH can sua: ";
                getline(cin, ma);
                for (auto& k : dsKhach) {
                    if (k.layMaKH() == ma) {
                        string dc;
                        cout << "Nhap dia chi moi: "; getline(cin, dc);
                        k.capNhatDiaChi(dc);
                    }
                }
            } else {
                for (auto& k : dsKhach) k.xuat();
            }

        } else if (choice == 2) {
            int ch;
            cout << "\n-- DON HANG --\n1. Them\n2. Xoa\n3. Sua\n4. Hien thi\nLua chon: ";
            cin >> ch; cin.ignore();
            if (ch == 1) {
                int loai;
                cout << "1. Normal\n2. Express\n3. Online\nLoai don: ";
                cin >> loai; cin.ignore();
                OrderBase* don = nullptr;
                if (loai == 1) don = new NormalOrder();
                else if (loai == 2) don = new ExpressOrder();
                else don = new OnlineOrder();
                don->NhapDon();
                dsDon.ThemDon(don);
            } else if (ch == 2) {
                string id;
                cout << "Nhap ID can xoa: "; getline(cin, id);
                dsDon.XoaDon(id);
            } else if (ch == 3) {
                string id;
                cout << "Nhap ID can sua: "; getline(cin, id);
                dsDon.SuaDon(id);
            } else {
                dsDon.HienThiTatCa();
            }

        } else if (choice == 3) {
            int ch;
            cout << "\n-- NHAN VIEN --\n1. Them\n2. Hien thi\nLua chon: ";
            cin >> ch; cin.ignore();
            if (ch == 1) {
                int loai;
                cout << "1. Fulltime\n2. Parttime\nLoai: ";
                cin >> loai; cin.ignore();
                string ten, vitri;
                int id;
                cout << "Ten: "; getline(cin, ten);
                cout << "ID: "; cin >> id; cin.ignore();
                cout << "Vi tri: "; getline(cin, vitri);

                if (loai == 1) {
                    double luong;
                    cout << "Luong co ban: "; cin >> luong;
                    dsNhanVien.push_back(make_unique<FullTimeEmployee>(ten, id, vitri, luong));
                } else {
                    int gio;
                    double rate;
                    cout << "So gio: "; cin >> gio;
                    cout << "Luong/gio: "; cin >> rate;
                    dsNhanVien.push_back(make_unique<PartTimeEmployee>(ten, id, vitri, gio, rate));
                }
            } else {
                for (auto& nv : dsNhanVien) {
                    nv->displayInfo();
                    cout << "Luong: " << nv->calcSalary() << endl;
                }
            }

        } else if (choice == 4) {
            int ch;
            cout << "\n-- SAN PHAM --\n1. Them\n2. Hien thi\nLua chon: ";
            cin >> ch; cin.ignore();
            if (ch == 1) {
                int loai;
                cout << "1. Thuong\n2. Dien tu\nLoai: ";
                cin >> loai; cin.ignore();
                Product* p;
                if (loai == 2) p = new ElectronicProduct();
                else p = new Product();
                p->input();
                dsSanPham.push_back(unique_ptr<Product>(p));
            } else {
                for (auto& p : dsSanPham) p->output(), cout << endl;
            }

        } else if (choice == 5) {
            int ch;
            cout << "\n-- THANH TOAN --\n1. Them\n2. Hien thi\nLua chon: ";
            cin >> ch; cin.ignore();
            if (ch == 1) {
                double amt;
                string meth;
                cout << "So tien: "; cin >> amt;
                cout << "Phuong thuc (Cash/Card/Online): "; cin >> meth;
                Payment p(amt, meth);
                dsThanhToan.push_back(p);
            } else {
                for (auto& p : dsThanhToan) p.display();
            }
        }
    } while (choice != 0);

    return 0;
}
