
using namespace std;
class SystemInterface {
private:
    BaiDo baiDo1;
    BaiDo baiDo2;
    BaiDo baiDo3;
    bool coBaiDo1;
    bool coBaiDo2;
    bool coBaiDo3;
public:
    SystemInterface();
    void runMenu();
};
SystemInterface::SystemInterface() {
    coBaiDo1 = false;
    coBaiDo2 = false;
    coBaiDo3 = false;
}
void SystemInterface::runMenu() {
    int luaChon;
    do {
        cout << "\n===== QUAN LY BAI DO XE =====" << endl;
        cout << "1. Tao bai do" << endl;
        cout << "2. Them xe vao bai do" << endl;
        cout << "3. Xoa bai do" << endl;
        cout << "4. Xoa xe khoi bai do" << endl;
        cout << "5. Hien thi tat ca bai do" << endl;
        cout << "6. Hien thi xe theo bai do" << endl;
        cout << "7. Liet ke xe theo loai" << endl;
        cout << "8. Thong ke phi do xe" << endl;
        cout << "9. Thoat" << endl;
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        switch (luaChon) {
            case 1:
                cout << "Chuc nang tao bai do." << endl;
                break;
            case 2:
                cout << "Chuc nang them xe." << endl;
                break;
            case 3:
                cout << "Chuc nang xoa bai do." << endl;
                break;
            case 4:
                cout << "Chuc nang xoa xe." << endl;
                break;
            case 5:
                if (coBaiDo1) baiDo1.hienThiThongTin();
                if (coBaiDo2) baiDo2.hienThiThongTin();
                if (coBaiDo3) baiDo3.hienThiThongTin();

                if (!coBaiDo1 && !coBaiDo2 && !coBaiDo3) {
                    cout << "Chua co bai do nao!" << endl;
                }
                break;
            case 6:
                cout << "Chuc nang hien thi xe theo bai do." << endl;
                break;
            case 7:
                cout << "Chuc nang liet ke xe theo loai." << endl;
                break;
            case 8:
                cout << "Chuc nang thong ke phi do xe." << endl;
                break;
            case 9:
                cout << "Ket thuc chuong trinh!" << endl;
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
        }

    } while (luaChon != 9);
}
