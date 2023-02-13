/*Le Thanh Hoang
2274801030052*/
// Xây dựng chương trình quản lý Lớp học tại một trung tâm tin học
// Một lớp học tại một trung tâm tin học gồm có các thông tin sau: Mã lớp học, tên lớp học, tổng số
// giờ học, học phí, số học viên. Hãy viết chương trình cho phép:
// − Nhập 1 danh sách lớp học từ bàn phím
// − Nhập danh sách lớp học từ file text (.txt)
// − Xuất danh sách lớp học.
// − Tính tổng số giờ học của các lớp học có trong danh sách
// − Tính tổng số học viên theo học các lớp học
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define KTM 100

struct LopHoc
{
    string maLop;
    string tenLop;
    float tongGioHoc;
    long hocPhi;
    int soHocVien;
};

void menu();
void nhapLopHoc(LopHoc &lh);
void xuatLopHoc(LopHoc lh);
void nhapDanhSachLopHoc(LopHoc arrLH[], int &slh);
void xuatDanhSachLopHoc(LopHoc arrLH[], int slh);
void nhapDanhSachLopHocTuFile(string myFile, LopHoc arrLH[], LopHoc &lh, int &slh);
float tinhTongSoGioHoc(LopHoc arrLH[], int slh);
int tinhTongSoHocVien(LopHoc arrLH[], int slh);
void sapXepHocPhi(LopHoc arrLH[], int slh);
int tongDoanhThu(LopHoc arrLH[], int slh);
void hocVienNhieuNhat(LopHoc arrLH[], int slh);
void hocVienLonHonMuoi(LopHoc arrLH[], int slh);
void timLop(LopHoc arrLH[], int slh);
void kiemTra(LopHoc arrLH[], int slh);
int main()
{
    menu();
    return 0;
}

void menu()
{
    int slh, chon;
    LopHoc lh, arrLH[KTM];
    LopHoc hocPhi;
    do
    {
        cout << endl
             << "========= Chuong trinh quan ly lop hoc tai Trung tam tin hoc ========" << endl
             << "0.Thoat" << endl
             << "1.Nhap danh sach lop hoc tu ban phim" << endl
             << "2.Tai du lieu danh sach lop hoc tu file(.txt)" << endl
             << "3.Xuat danh sach lop hoc" << endl
             << "4.Tinh tong so gio hoc cua cac lop hoc co trong danh sach" << endl
             << "5.Tinh tong so hoc vien theo hoc tai cac lop" << endl
             << "6.Sap xep danh sach lop hoc theo hoc phi giam dan" << endl
             << "7.Tinh tong doanh thu cua cac lop hoc" << endl
             << "8.Danh sach cac lop co so hoc vien nhieu nhat" << endl
             << "9.Dach sach cac lop hoc co so hoc vien > 10" << endl
             << "10.Tim kiem lop hoc theo ten lop hoc" << endl
             << "11.Kiem tra danh sach cac lop hoc co duoc sap xep theo so hoc vien giam dan hay khong" << endl
             << "Vui long chon: ";
        cin >> chon;
        switch (chon)
        {
        case 1:
            nhapDanhSachLopHoc(arrLH, slh);
            break;
        case 2:
            nhapDanhSachLopHocTuFile("danhSachLopHoc.txt", arrLH, lh, slh);
            break;
        case 3:
            xuatDanhSachLopHoc(arrLH, slh);
            break;
        case 4:
        {
            cout << endl
                 << "Tong gio hoc cua cac lop hoc co trong danh sach la " << tinhTongSoGioHoc(arrLH, slh) << endl;
        }
        break;
        case 5:
        {
            cout << endl
                 << "Tong so hoc vien theo hoc tai cac lop la " << tinhTongSoHocVien(arrLH, slh) << endl;
        }
        break;
        case 6:
        {
            cout << endl
                 << "Lop hoc sau khi sap xep la: ";
            sapXepHocPhi(arrLH, slh);
        }
        break;
        case 7:
        {
            cout << endl
                 << "Tong doanh thu cua cac lop la " << tongDoanhThu(arrLH, slh) << endl;
        }
        break;
        case 8:
            cout << endl
                 << "Lop hoc co hoc vien nhieu nhat la: ";
            hocVienNhieuNhat(arrLH, slh);
            break;
        case 9:
            cout << endl
                 << "Lop hoc co hoc vien > 10 la: ";
            hocVienLonHonMuoi(arrLH, slh);
            break;
        case 10:
            timLop(arrLH, slh);
            break;
        case 11:
            kiemTra(arrLH, slh);
            break;
        default:
            break;
        }
    } while (chon > 0 && chon < 12);
}

int tinhTongSoHocVien(LopHoc arrLH[], int slh)
{
    int tong = 0;
    for (int i = 0; i < slh; i++)
    {
        tong += arrLH[i].soHocVien;
    }
    return tong;
}

float tinhTongSoGioHoc(LopHoc arrLH[], int slh)
{
    float tong = 0;
    for (int i = 0; i < slh; i++)
    {
        tong += arrLH[i].tongGioHoc;
    }
    return tong;
}

void nhapDanhSachLopHocTuFile(string myFile, LopHoc arrLH[], LopHoc &lh, int &slh)
{
    slh = 0;
    fstream myData(myFile);
    while (myData >> lh.maLop >> lh.tenLop >> lh.tongGioHoc >> lh.hocPhi >> lh.soHocVien)
    {
        arrLH[slh] = lh;
        slh++;
    }
    myData.close();
}

void xuatDanhSachLopHoc(LopHoc arrLH[], int slh)
{
    if (slh == 0)
    {
        cout << "=======Danh sach lop hoc chua duoc nhap=======" << endl;
    }
    else
    {
        for (int i = 0; i < slh; i++)
        {
            cout << endl
                 << "========= Lop hoc thu " << i + 1 << " ========" << endl;
            xuatLopHoc(arrLH[i]);
        }
    }
}

void nhapDanhSachLopHoc(LopHoc arrLH[], int &slh)
{
    LopHoc lh;
    do
    {
        cout << "Nhap so lop hoc can nhap : " << endl;
        cin >> slh;
    } while (slh <= 0);
    for (int i = 0; i < slh; i++)
    {
        cout << endl
             << "======== Nhap lop hoc thu " << i + 1 << " ========";
        nhapLopHoc(lh);
        arrLH[i] = lh;
    }
}

void xuatLopHoc(LopHoc lh)
{
    cout << endl
         << "Ma lop hoc : " << lh.maLop << endl
         << "Ten lop hoc : " << lh.tenLop << endl
         << "Tong gio hoc : " << lh.tongGioHoc << endl
         << "Hoc phi : " << lh.hocPhi << endl
         << "So hoc vien : " << lh.soHocVien << endl;
}

void nhapLopHoc(LopHoc &lh)
{
    cout << endl
         << "Nhap ma lop hoc : " << endl;
    rewind(stdin);
    getline(cin, lh.maLop);
    cout << "Nhap ten lop hoc : " << endl;
    getline(cin, lh.tenLop);
    cout << "Nhap tong gio hoc : " << endl;
    cin >> lh.tongGioHoc;
    cout << "Nhap hoc phi : " << endl;
    cin >> lh.hocPhi;
    cout << "Nhap so hoc vien : " << endl;
    cin >> lh.soHocVien;
}

// Bùi An Ninh - 2274801030107
// Thực hiện:
// − Sắp xếp danh sách lớp học theo học phí giảm dần
// − Tính tổng doanh thu của các lớp học có trong danh sách
// − In ra danh sách các lớp học có số học viên nhiều nhất
// − In ra danh sách các lớp học có số học viên > 10.
// − Cho phép tìm kiếm lớp học khi biết tên lớp.
// − Cho biết danh sách các lớp học có được sắp xếp theo số học viên giảm dần hay không?

void sapXepHocPhi(LopHoc arrLH[], int slh)
{
    LopHoc lh;
    for (int i = 0; i < slh - 1; i++)
    {
        for (int j = i + 1; j < slh; j++)
        {
            if (arrLH[i].hocPhi < arrLH[j].hocPhi)
            {
                lh = arrLH[i];
                arrLH[i] = arrLH[j];
                arrLH[j] = lh;
            }
        }
    }
    xuatDanhSachLopHoc(arrLH, slh);
}

int tongDoanhThu(LopHoc arrLH[], int slh)
{
    long tong = 0;
    for (int i = 0; i < slh; i++)
    {
        tong += arrLH[i].soHocVien * arrLH[i].hocPhi;
    }
    return tong;
}

void hocVienNhieuNhat(LopHoc arrLH[], int slh)
{
    LopHoc max = arrLH[0];
    for (int i = 1; i < slh; i++)
    {
        if (arrLH[i].soHocVien > max.soHocVien)
        {
            max = arrLH[i];
        }
    }
    for (int j = 0; j < slh; j++)
    {
        if (arrLH[j].soHocVien == max.soHocVien)
        {
            xuatLopHoc(arrLH[j]);
        }
    }
}

void hocVienLonHonMuoi(LopHoc arrLH[], int slh)
{
    for (int i = 0; i < slh; i++)
    {
        if (arrLH[i].soHocVien > 10)
        {
            xuatLopHoc(arrLH[i]);
        }
    }
}

void timLop(LopHoc arrLH[], int slh)
{
    string tim;
    cout << "Vui Long nhap lop can tim: ";
    rewind(stdin);
    getline(cin, tim);
    cout << "Lop hoc can tim la: ";
    for (int i = 0; i < slh; i++)
    {
        if (arrLH[i].tenLop == tim)
        {
            xuatLopHoc(arrLH[i]);
        }
    }
}
void kiemTra(LopHoc arrLH[], int slh)
{
    bool chuyen = false;
    for (int i = 0; i < slh; i++)
    {
        if (arrLH[i].soHocVien < arrLH[i + 1].soHocVien)
        {
            chuyen = true;
            break;
        }
    }
    if (chuyen)
    {
        cout << "Danh sach cac lop hoc co duoc sap xep theo so hoc vien giam dan" << endl;
        }
    else
    {
        cout << "Danh sach cac lop hoc khong duoc sap xep theo so hoc vien giam dan" << endl;
    }
}