#include <iostream>
using namespace std;
class BaiDo {
private:
    int maBaiDo;
    char kichThuoc;
    Xe xe1;
    Xe xe2;
    Xe xe3;
    bool coXe1;
    bool coXe2;
    bool coXe3;
public:
    BaiDo();
    BaiDo(int ma, char size);
    bool themXe(const Xe& xe);
    bool xoaXe(int maXe);
    void hienThiThongTin() const;
};
BaiDo::BaiDo() {
    maBaiDo = 0;
    kichThuoc = 'S';

    coXe1 = false;
    coXe2 = false;
    coXe3 = false;
}
BaiDo::BaiDo(int ma, char size) {
    maBaiDo = ma;
    if (size >= 'a' && size <= 'z') {
        size = size - 32;
    }
    if (size == 'S' || size == 'M' || size == 'L') {
        kichThuoc = size;
    }
    else {
        kichThuoc = 'S';
    }
    coXe1 = false;
    coXe2 = false;
    coXe3 = false;
}
bool BaiDo::themXe(const Xe& xe) {
    if (xe.layMaXe() <= 0 || xe.layLoaiXe() == "") {
        return false;
    }
    if (coXe1 && xe1.layMaXe() == xe.layMaXe()) {
        return false;
    }
    if (coXe2 && xe2.layMaXe() == xe.layMaXe()) {
        return false;
    }
    if (coXe3 && xe3.layMaXe() == xe.layMaXe()) {
        return false;
    }
    if (kichThuoc == 'S') {
        if (!coXe1) {
            xe1 = xe;
            xe1.ganDangChiemCho(true);
            coXe1 = true;
            return true;
        }
    }
    else if (kichThuoc == 'M') {
        if (!coXe1) {
            xe1 = xe;
            xe1.ganDangChiemCho(true);
            coXe1 = true;
            return true;
        }

        if (!coXe2) {
            xe2 = xe;
            xe2.ganDangChiemCho(true);
            coXe2 = true;
            return true;
        }
    }
    else if (kichThuoc == 'L') {
        if (!coXe1) {
            xe1 = xe;
            xe1.ganDangChiemCho(true);
            coXe1 = true;
            return true;
        }

        if (!coXe2) {
            xe2 = xe;
            xe2.ganDangChiemCho(true);
            coXe2 = true;
            return true;
        }

        if (!coXe3) {
            xe3 = xe;
            xe3.ganDangChiemCho(true);
            coXe3 = true;
            return true;
        }
    }
    return false;
}
bool BaiDo::xoaXe(int maXe) {
    if (coXe1 && xe1.layMaXe() == maXe) {
        xe1 = Xe();
        coXe1 = false;
        return true;
    }

    if (coXe2 && xe2.layMaXe() == maXe) {
        xe2 = Xe();
        coXe2 = false;
        return true;
    }

    if (coXe3 && xe3.layMaXe() == maXe) {
        xe3 = Xe();
        coXe3 = false;
        return true;
    }
    return false;
}
void BaiDo::hienThiThongTin() const {
    cout << "\n===== THONG TIN BAI DO =====" << endl;
    cout << "Ma bai do: " << maBaiDo << endl;
    cout << "Kich thuoc: " << kichThuoc << endl;

    cout << "Suc chua: ";

    if (kichThuoc == 'S') {
        cout << "1 xe" << endl;
    }
    else if (kichThuoc == 'M') {
        cout << "2 xe" << endl;
    }
    else {
        cout << "3 xe" << endl;
    }

    cout << "\nDanh sach xe:" << endl;

    if (coXe1) {
        cout << "\nVi tri 1:" << endl;
        xe1.hienThi();
    }

    if (coXe2) {
        cout << "\nVi tri 2:" << endl;
        xe2.hienThi();
    }

    if (coXe3) {
        cout << "\nVi tri 3:" << endl;
        xe3.hienThi();
    }

    if (!coXe1 && !coXe2 && !coXe3) {
        cout << "Bai do dang trong." << endl;
    }
}

