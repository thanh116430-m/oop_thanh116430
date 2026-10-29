#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;
class Xe {
private:
    int maXe;
    string loaiXe;
    int gioVao;
    int thoiGianDo;
    double phiDoXe;
    bool dangChiemCho;

public:
    Xe();
    Xe(int ma, const string& loai, int gio, int thoiLuong);

    int layMaXe() const;
    string layLoaiXe() const;
    int layGioVao() const;
    int layThoiGianDo() const;
    double layPhiDoXe() const;
    bool layDangChiemCho() const;

    void ganMaXe(int ma);
    void ganLoaiXe(const string& loai);
    void ganGioVao(int gio);
    void ganThoiLuongDo(int thoiLuong);
    void ganPhiDoXe(double phi);
    void ganDangChiemCho(bool trangThai);

    static string chuanHoaLoaiXe(const string& loai);
    static bool laLoaiXeHopLe(const string& loai);

    void tinhPhiDoXe();
    void hienThi() const;
};

Xe::Xe() {
    maXe = 0;
    loaiXe = "";
    gioVao = 0;
    thoiGianDo = 0;
    phiDoXe = 0;
    dangChiemCho = false;
}

Xe::Xe(int ma, const string& loai, int gio, int thoiLuong) {
    maXe = ma;
    loaiXe = chuanHoaLoaiXe(loai);
    gioVao = gio;
    thoiGianDo = thoiLuong;
    phiDoXe = 0;
    dangChiemCho = true;
    tinhPhiDoXe();
}

int Xe::layMaXe() const {
    return maXe;
}

string Xe::layLoaiXe() const {
    return loaiXe;
}

int Xe::layGioVao() const {
    return gioVao;
}

int Xe::layThoiGianDo() const {
    return thoiGianDo;
}

double Xe::layPhiDoXe() const {
    return phiDoXe;
}

bool Xe::layDangChiemCho() const {
    return dangChiemCho;
}

void Xe::ganMaXe(int ma) {
    maXe = ma;
}

void Xe::ganLoaiXe(const string& loai) {
    if (laLoaiXeHopLe(loai)) {
        loaiXe = chuanHoaLoaiXe(loai);
        tinhPhiDoXe();
    }
}

void Xe::ganGioVao(int gio) {
    if (gio >= 0 && gio <= 23 && gio + thoiGianDo <= 24) {
        gioVao = gio;
        tinhPhiDoXe();
    }
}

void Xe::ganThoiLuongDo(int thoiLuong) {
    if (thoiLuong >= 1 && thoiLuong <= 23
        && gioVao + thoiLuong <= 24) {
        thoiGianDo = thoiLuong;
        tinhPhiDoXe();
    }
}

void Xe::ganPhiDoXe(double phi) {
    if (phi >= 0) {
        phiDoXe = phi;
    }
}

void Xe::ganDangChiemCho(bool trangThai) {
    dangChiemCho = trangThai;
}

string Xe::chuanHoaLoaiXe(const string& loai) {
    string ketQua = loai;

    for (int i = 0; i < (int)ketQua.length(); i++) {
        ketQua[i] = tolower((unsigned char)ketQua[i]);
    }

    if (ketQua == "car") {
        return "Car";
    }

    if (ketQua == "motorcycle") {
        return "Motorcycle";
    }

    if (ketQua == "bicycle") {
        return "Bicycle";
    }

    return "";
}

bool Xe::laLoaiXeHopLe(const string& loai) {
    return chuanHoaLoaiXe(loai) != "";
}

void Xe::tinhPhiDoXe() {
    phiDoXe = 0;

    double donGia = 0;

    if (loaiXe == "Car") {
        donGia = 6000;
    }
    else if (loaiXe == "Motorcycle") {
        donGia = 4000;
    }
    else if (loaiXe == "Bicycle") {
        donGia = 2000;
    }
    else {
        return;
    }

    bool gioCaoDiem =
        (gioVao >= 6 && gioVao < 10)
        || (gioVao >= 15 && gioVao < 19);

    for (int i = 1; i <= thoiGianDo; i++) {
        if (i <= 2) {
            if (gioCaoDiem) {
                phiDoXe += donGia * 1.30;
            }
            else {
                phiDoXe += donGia * 0.95;
            }
        }
        else {
            phiDoXe += donGia * 0.90;
        }
    }
}

void Xe::hienThi() const {
    cout << "Ma xe: " << maXe << endl;
    cout << "Loai xe: " << loaiXe << endl;
    cout << "Gio vao: " << gioVao << endl;
    cout << "Thoi gian do: " << thoiGianDo << " gio" << endl;
    cout << fixed << setprecision(0);
    cout << "Phi do xe: " << phiDoXe << " VND" << endl;

    cout << "Trang thai: ";

    if (dangChiemCho) {
        cout << "Dang chiem cho";
    }
    else {
        cout << "Khong chiem cho";
    }

    cout << endl;
}
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

    int layMaBaiDo() const;
    char layKichThuoc() const;

    bool themXe(const Xe& xe);
    bool xoaXe(int maXe);
    void hienThiThongTin() const;

    bool coXeTaiViTri(int viTri) const;
    Xe layXeTaiViTri(int viTri) const;

    int demSoXe() const;
    double tongPhi() const;
    int demXeTheoLoai(const string& loai) const;
    double tongPhiTheoLoai(const string& loai) const;
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

int BaiDo::layMaBaiDo() const {
    return maBaiDo;
}

char BaiDo::layKichThuoc() const {
    return kichThuoc;
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

bool BaiDo::coXeTaiViTri(int viTri) const {
    if (viTri == 1) return coXe1;
    if (viTri == 2) return coXe2;
    if (viTri == 3) return coXe3;

    return false;
}

Xe BaiDo::layXeTaiViTri(int viTri) const {
    if (viTri == 1) return xe1;
    if (viTri == 2) return xe2;
    return xe3;
}

int BaiDo::demSoXe() const {
    int dem = 0;

    if (coXe1) dem++;
    if (coXe2) dem++;
    if (coXe3) dem++;

    return dem;
}

double BaiDo::tongPhi() const {
    double tong = 0;

    if (coXe1) tong += xe1.layPhiDoXe();
    if (coXe2) tong += xe2.layPhiDoXe();
    if (coXe3) tong += xe3.layPhiDoXe();

    return tong;
}

int BaiDo::demXeTheoLoai(const string& loai) const {
    int dem = 0;
    string loaiChuan = Xe::chuanHoaLoaiXe(loai);

    if (coXe1 && xe1.layLoaiXe() == loaiChuan) dem++;
    if (coXe2 && xe2.layLoaiXe() == loaiChuan) dem++;
    if (coXe3 && xe3.layLoaiXe() == loaiChuan) dem++;

    return dem;
}

double BaiDo::tongPhiTheoLoai(const string& loai) const {
    double tong = 0;
    string loaiChuan = Xe::chuanHoaLoaiXe(loai);

    if (coXe1 && xe1.layLoaiXe() == loaiChuan) {
        tong += xe1.layPhiDoXe();
    }

    if (coXe2 && xe2.layLoaiXe() == loaiChuan) {
        tong += xe2.layPhiDoXe();
    }

    if (coXe3 && xe3.layLoaiXe() == loaiChuan) {
        tong += xe3.layPhiDoXe();
    }

    return tong;
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

    cout << "So xe hien co: " << demSoXe() << endl;
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
class SystemInterface {
private:
    BaiDo baiDo1;
    BaiDo baiDo2;
    BaiDo baiDo3;

    bool coBaiDo1;
    bool coBaiDo2;
    bool coBaiDo3;

    bool maXeDaTonTai(int maXe) const;
    BaiDo* timBaiDo(int maBaiDo);
    void taoBaiDo();
    void themXeVaoBaiDo();
    void xoaBaiDo();
    void layXeRa();
    void hienThiTatCaBaiDo() const;
    void hienThiXeTheoBaiDo() const;
    void lietKeXeTheoLoai() const;
    void thongKePhiDoXe() const;

public:
    SystemInterface();
    void runMenu();
};

SystemInterface::SystemInterface() {
    coBaiDo1 = false;
    coBaiDo2 = false;
    coBaiDo3 = false;
}

bool SystemInterface::maXeDaTonTai(int maXe) const {
    if (coBaiDo1) {
        for (int i = 1; i <= 3; i++) {
            if (baiDo1.coXeTaiViTri(i)
                && baiDo1.layXeTaiViTri(i).layMaXe() == maXe) {
                return true;
            }
        }
    }

    if (coBaiDo2) {
        for (int i = 1; i <= 3; i++) {
            if (baiDo2.coXeTaiViTri(i)
                && baiDo2.layXeTaiViTri(i).layMaXe() == maXe) {
                return true;
            }
        }
    }

    if (coBaiDo3) {
        for (int i = 1; i <= 3; i++) {
            if (baiDo3.coXeTaiViTri(i)
                && baiDo3.layXeTaiViTri(i).layMaXe() == maXe) {
                return true;
            }
        }
    }

    return false;
}

BaiDo* SystemInterface::timBaiDo(int maBaiDo) {
    if (coBaiDo1 && baiDo1.layMaBaiDo() == maBaiDo) {
        return &baiDo1;
    }

    if (coBaiDo2 && baiDo2.layMaBaiDo() == maBaiDo) {
        return &baiDo2;
    }

    if (coBaiDo3 && baiDo3.layMaBaiDo() == maBaiDo) {
        return &baiDo3;
    }

    return nullptr;
}

void SystemInterface::taoBaiDo() {
    int ma;
    char kichThuoc;

    cout << "Nhap ma bai do: ";
    cin >> ma;

    if (ma <= 0) {
        cout << "Ma bai do phai lon hon 0!" << endl;
        return;
    }

    if (timBaiDo(ma) != nullptr) {
        cout << "Ma bai do da ton tai!" << endl;
        return;
    }

    cout << "Nhap kich thuoc S, M hoac L: ";
    cin >> kichThuoc;

    if (kichThuoc >= 'a' && kichThuoc <= 'z') {
        kichThuoc = kichThuoc - 32;
    }

    if (kichThuoc != 'S' && kichThuoc != 'M' && kichThuoc != 'L') {
        cout << "Kich thuoc khong hop le!" << endl;
        return;
    }

    if (!coBaiDo1) {
        baiDo1 = BaiDo(ma, kichThuoc);
        coBaiDo1 = true;
    }
    else if (!coBaiDo2) {
        baiDo2 = BaiDo(ma, kichThuoc);
        coBaiDo2 = true;
    }
    else if (!coBaiDo3) {
        baiDo3 = BaiDo(ma, kichThuoc);
        coBaiDo3 = true;
    }
    else {
        cout << "He thong da co toi da 3 bai do!" << endl;
        return;
    }

    cout << "Tao bai do thanh cong!" << endl;
}

void SystemInterface::themXeVaoBaiDo() {
    int maBaiDo, maXe, gio, thoiLuong;
    string loaiXe;

    cout << "Nhap ma bai do: ";
    cin >> maBaiDo;

    BaiDo* baiDo = timBaiDo(maBaiDo);

    if (baiDo == nullptr) {
        cout << "Khong tim thay bai do!" << endl;
        return;
    }

    cout << "Nhap ma xe: ";
    cin >> maXe;

    if (maXe <= 0 || maXeDaTonTai(maXe)) {
        cout << "Ma xe khong hop le hoac da ton tai!" << endl;
        return;
    }

    cout << "Nhap loai xe (Car/Motorcycle/Bicycle): ";
    cin >> loaiXe;

    if (!Xe::laLoaiXeHopLe(loaiXe)) {
        cout << "Loai xe khong hop le!" << endl;
        return;
    }

    cout << "Nhap gio vao (0-23): ";
    cin >> gio;

    if (gio < 0 || gio > 23) {
        cout << "Gio vao khong hop le!" << endl;
        return;
    }

    cout << "Nhap thoi gian do (1-23 gio): ";
    cin >> thoiLuong;

    if (thoiLuong < 1 || thoiLuong > 23 || gio + thoiLuong > 24) {
        cout << "Thoi gian do khong hop le!" << endl;
        return;
    }

    Xe xe(maXe, loaiXe, gio, thoiLuong);

    if (baiDo->themXe(xe)) {
        cout << "Them xe thanh cong!" << endl;
        cout << "Phi do xe: " << fixed << setprecision(0)
             << xe.layPhiDoXe() << " VND" << endl;
    }
    else {
        cout << "Bai do da day, khong the them xe!" << endl;
    }
}

void SystemInterface::xoaBaiDo() {
    int ma;
    cout << "Nhap ma bai do can xoa: ";
    cin >> ma;

    if (coBaiDo1 && baiDo1.layMaBaiDo() == ma) {
        baiDo1 = BaiDo();
        coBaiDo1 = false;
        cout << "Da xoa bai do!" << endl;
        return;
    }

    if (coBaiDo2 && baiDo2.layMaBaiDo() == ma) {
        baiDo2 = BaiDo();
        coBaiDo2 = false;
        cout << "Da xoa bai do!" << endl;
        return;
    }

    if (coBaiDo3 && baiDo3.layMaBaiDo() == ma) {
        baiDo3 = BaiDo();
        coBaiDo3 = false;
        cout << "Da xoa bai do!" << endl;
        return;
    }

    cout << "Khong tim thay bai do!" << endl;
}

void SystemInterface::layXeRa() {
    int maBaiDo, maXe;

    cout << "Nhap ma bai do: ";
    cin >> maBaiDo;

    BaiDo* baiDo = timBaiDo(maBaiDo);

    if (baiDo == nullptr) {
        cout << "Khong tim thay bai do!" << endl;
        return;
    }

    cout << "Nhap ma xe can lay ra: ";
    cin >> maXe;

    if (baiDo->xoaXe(maXe)) {
        cout << "Da lay xe ra khoi bai!" << endl;
    }
    else {
        cout << "Khong tim thay xe trong bai do nay!" << endl;
    }
}

void SystemInterface::hienThiTatCaBaiDo() const {
    if (!coBaiDo1 && !coBaiDo2 && !coBaiDo3) {
        cout << "Chua co bai do nao!" << endl;
        return;
    }

    if (coBaiDo1) baiDo1.hienThiThongTin();
    if (coBaiDo2) baiDo2.hienThiThongTin();
    if (coBaiDo3) baiDo3.hienThiThongTin();
}

void SystemInterface::hienThiXeTheoBaiDo() const {
    int ma;

    cout << "Nhap ma bai do: ";
    cin >> ma;

    if (coBaiDo1 && baiDo1.layMaBaiDo() == ma) {
        baiDo1.hienThiThongTin();
        return;
    }

    if (coBaiDo2 && baiDo2.layMaBaiDo() == ma) {
        baiDo2.hienThiThongTin();
        return;
    }

    if (coBaiDo3 && baiDo3.layMaBaiDo() == ma) {
        baiDo3.hienThiThongTin();
        return;
    }

    cout << "Khong tim thay bai do!" << endl;
}

void SystemInterface::lietKeXeTheoLoai() const {
    string loai;

    cout << "Nhap loai xe (Car/Motorcycle/Bicycle): ";
    cin >> loai;

    loai = Xe::chuanHoaLoaiXe(loai);

    if (loai == "") {
        cout << "Loai xe khong hop le!" << endl;
        return;
    }

    bool timThay = false;

    if (coBaiDo1) {
        for (int i = 1; i <= 3; i++) {
            if (baiDo1.coXeTaiViTri(i)) {
                Xe xe = baiDo1.layXeTaiViTri(i);

                if (xe.layLoaiXe() == loai) {
                    cout << "\nBai do " << baiDo1.layMaBaiDo()
                         << ", vi tri " << i << ":" << endl;
                    xe.hienThi();
                    timThay = true;
                }
            }
        }
    }

    if (coBaiDo2) {
        for (int i = 1; i <= 3; i++) {
            if (baiDo2.coXeTaiViTri(i)) {
                Xe xe = baiDo2.layXeTaiViTri(i);

                if (xe.layLoaiXe() == loai) {
                    cout << "\nBai do " << baiDo2.layMaBaiDo()
                         << ", vi tri " << i << ":" << endl;
                    xe.hienThi();
                    timThay = true;
                }
            }
        }
    }

    if (coBaiDo3) {
        for (int i = 1; i <= 3; i++) {
            if (baiDo3.coXeTaiViTri(i)) {
                Xe xe = baiDo3.layXeTaiViTri(i);

                if (xe.layLoaiXe() == loai) {
                    cout << "\nBai do " << baiDo3.layMaBaiDo()
                         << ", vi tri " << i << ":" << endl;
                    xe.hienThi();
                    timThay = true;
                }
            }
        }
    }

    if (!timThay) {
        cout << "Khong co xe thuoc loai nay!" << endl;
    }
}

void SystemInterface::thongKePhiDoXe() const {
    string loai;
    int soXe;
    double tongPhi;

    cout << "\n===== THONG KE PHI DO XE =====" << endl;

    cout << fixed << setprecision(0);

    cout << "\n1. Thong ke theo loai xe:" << endl;

    cout << "\nCar:" << endl;
    soXe = 0;
    tongPhi = 0;

    if (coBaiDo1) {
        soXe += baiDo1.demXeTheoLoai("Car");
        tongPhi += baiDo1.tongPhiTheoLoai("Car");
    }

    if (coBaiDo2) {
        soXe += baiDo2.demXeTheoLoai("Car");
        tongPhi += baiDo2.tongPhiTheoLoai("Car");
    }

    if (coBaiDo3) {
        soXe += baiDo3.demXeTheoLoai("Car");
        tongPhi += baiDo3.tongPhiTheoLoai("Car");
    }

    cout << "So xe: " << soXe << endl;
    cout << "Tong phi: " << tongPhi << " VND" << endl;

    if (soXe > 0) {
        cout << "Phi trung binh: " << tongPhi / soXe << " VND" << endl;
    }
    else {
        cout << "Chua co xe loai nay." << endl;
    }

    cout << "\nMotorcycle:" << endl;
    soXe = 0;
    tongPhi = 0;

    if (coBaiDo1) {
        soXe += baiDo1.demXeTheoLoai("Motorcycle");
        tongPhi += baiDo1.tongPhiTheoLoai("Motorcycle");
    }

    if (coBaiDo2) {
        soXe += baiDo2.demXeTheoLoai("Motorcycle");
        tongPhi += baiDo2.tongPhiTheoLoai("Motorcycle");
    }

    if (coBaiDo3) {
        soXe += baiDo3.demXeTheoLoai("Motorcycle");
        tongPhi += baiDo3.tongPhiTheoLoai("Motorcycle");
    }

    cout << "So xe: " << soXe << endl;
    cout << "Tong phi: " << tongPhi << " VND" << endl;

    if (soXe > 0) {
        cout << "Phi trung binh: " << tongPhi / soXe << " VND" << endl;
    }
    else {
        cout << "Chua co xe loai nay." << endl;
    }

    cout << "\nBicycle:" << endl;
    soXe = 0;
    tongPhi = 0;

    if (coBaiDo1) {
        soXe += baiDo1.demXeTheoLoai("Bicycle");
        tongPhi += baiDo1.tongPhiTheoLoai("Bicycle");
    }

    if (coBaiDo2) {
        soXe += baiDo2.demXeTheoLoai("Bicycle");
        tongPhi += baiDo2.tongPhiTheoLoai("Bicycle");
    }

    if (coBaiDo3) {
        soXe += baiDo3.demXeTheoLoai("Bicycle");
        tongPhi += baiDo3.tongPhiTheoLoai("Bicycle");
    }

    cout << "So xe: " << soXe << endl;
    cout << "Tong phi: " << tongPhi << " VND" << endl;

    if (soXe > 0) {
        cout << "Phi trung binh: " << tongPhi / soXe << " VND" << endl;
    }
    else {
        cout << "Chua co xe loai nay." << endl;
    }

    cout << "\n2. Chi tiet tung bai do:" << endl;

    if (coBaiDo1) {
        cout << "\nBai do " << baiDo1.layMaBaiDo() << endl;
        cout << "So xe: " << baiDo1.demSoXe() << endl;
        cout << "Tong phi: " << baiDo1.tongPhi() << " VND" << endl;

        if (baiDo1.demSoXe() > 0) {
            cout << "Phi trung binh: "
                 << baiDo1.tongPhi() / baiDo1.demSoXe()
                 << " VND" << endl;
        }
    }

    if (coBaiDo2) {
        cout << "\nBai do " << baiDo2.layMaBaiDo() << endl;
        cout << "So xe: " << baiDo2.demSoXe() << endl;
        cout << "Tong phi: " << baiDo2.tongPhi() << " VND" << endl;

        if (baiDo2.demSoXe() > 0) {
            cout << "Phi trung binh: "
                 << baiDo2.tongPhi() / baiDo2.demSoXe()
                 << " VND" << endl;
        }
    }

    if (coBaiDo3) {
        cout << "\nBai do " << baiDo3.layMaBaiDo() << endl;
        cout << "So xe: " << baiDo3.demSoXe() << endl;
        cout << "Tong phi: " << baiDo3.tongPhi() << " VND" << endl;

        if (baiDo3.demSoXe() > 0) {
            cout << "Phi trung binh: "
                 << baiDo3.tongPhi() / baiDo3.demSoXe()
                 << " VND" << endl;
        }
    }

    if (!coBaiDo1 && !coBaiDo2 && !coBaiDo3) {
        cout << "Chua co bai do nao de thong ke." << endl;
    }
}

void SystemInterface::runMenu() {
    int luaChon;

    do {
        cout << "\n===== QUAN LY BAI DO XE =====" << endl;
        cout << "1. Tao bai do moi" << endl;
        cout << "2. Them xe vao bai do" << endl;
        cout << "3. Xoa bai do" << endl;
        cout << "4. Lay xe ra khoi bai do" << endl;
        cout << "5. Hien thi tat ca bai do" << endl;
        cout << "6. Hien thi xe theo bai do" << endl;
        cout << "7. Liet ke xe theo loai" << endl;
        cout << "8. Thong ke phi do xe" << endl;
        cout << "9. Thoat chuong trinh" << endl;
        cout << "Nhap lua chon: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                taoBaiDo();
                break;

            case 2:
                themXeVaoBaiDo();
                break;

            case 3:
                xoaBaiDo();
                break;

            case 4:
                layXeRa();
                break;

            case 5:
                hienThiTatCaBaiDo();
                break;

            case 6:
                hienThiXeTheoBaiDo();
                break;

            case 7:
                lietKeXeTheoLoai();
                break;

            case 8:
                thongKePhiDoXe();
                break;

            case 9:
                cout << "Ket thuc chuong trinh!" << endl;
                break;

            default:
                cout << "Lua chon khong hop le!" << endl;
        }

    } while (luaChon != 9);
}
int main() {
    SystemInterface heThong;
    heThong.runMenu();

    return 0;
}
