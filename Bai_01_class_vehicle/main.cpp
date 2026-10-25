#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Xe {
private:
    int maXe;                  // Mã định danh xe
    string loaiXe;             // "Car", "Motorcycle", "Bicycle"
    int gioVao;                // 0..23
    int thoiGianDo;           // 1..23
    double phiDoXe;            // VND
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
Xe::Xe(){
    maXe = 0;
    loaiXe = "";
    gioVao = 0;
    thoiGianDo = 0;
    phiDoXe=0;
    dangChiemCho = false;
}
Xe::Xe(int ma, const string& loai, int gio,int thoiLuong){
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
void Xe::ganMaXe(int ma){
    maXe = ma;

}
void Xe::ganLoaiXe(const string& loai){
    if(laLoaiXeHopLe(loai)){
        loaiXe=chuanHoaLoaiXe(loai);
        tinhPhiDoXe();
    }
}
void Xe::ganGioVao(int gio){
    if(gio>=0&&gio<=23){
        gioVao = gio;
        tinhPhiDoXe;
    }
}
void Xe::ganThoiLuongDo(int thoiLuong){
    if(thoiLuong>=1&&thoiLuong<=23&&(gioVao+thoiLuong)<=24 ){
        thoiGianDo = thoiLuong;
        tinhPhiDoXe():

    }

}
void Xe::ganPhiDoXe(double phi){
    if(phi>=0){
        phiDoXe = phi;
    }
}
void Xe::ganDangChiemCho(bool trangThai){
    dangChiemCho = trangThai;
}
string Xe::chuanHoaLoaiXe(const string& loai){
    string ketQua = loai;
    for(int i=0;i<(int)ketQua.length();i++){
        ketQua[i] = tolower(ketQua[i]);
    }
    if(ketQua == "car"){
        return "Car";
    }
    if(ketQua == "motorcycle"){
        return "Motocycle";
    }
    if(ketQua == "bicycle"){
        return "Bicycle";
    }
    return "";
}
bool Xe::laLoaiXeHopLe(const string& loai){
    return chuanHoaLoaiXe(loai) != "";
}
void Xe::tinhPhiDoXe(){
    phiDoXe=0;
    double donGia;
    if(loaiXe == "Car"){
        donGia = 6;    }
    else if(loaiXe == "Motocycle"){
        donGia = 4;
    }
    else if(loaiXe == "Bicycle"){
        donGia =2;

    }
    else{
        return;
    }
    bool gioCaoDiem = (gioVao>=6&& gioVao<10)||(gioVao>=15&&gioVao<19);
    for(int i=1;i<thoiGianDo;i++){
        if(i<=2){
            if(gioCaoDiem){
                phiDoXe += donGia * 1.3;
            }
            else{
                phiDoXe += donGia * 0.95;
            }
        }
        else{
            phiDoXe += donGia *0.9;
        }
    }
}
void Xe:hienThi() const{
    cout<<"Ma xe: "<<maXe<<endl;
    cout<<"Loai xe: "<<loaiXe<<endl;
    cout<<"Gio vao: "<<gioVao<<endl;
    cout<<"Thoi gian do: "<<thoiGianDo<<endl;
    cout<<"Phi do xe: "<<phiDoXe<<endl;
    cout<<"Trang thai: ";
    if(dangChiemCho){
        cout<<"Dang chiem cho";
    }
    else{
        cout<<"Khong chiem cho";

    }
    
}