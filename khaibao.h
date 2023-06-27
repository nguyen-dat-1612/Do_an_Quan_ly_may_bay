#include <iostream>
#include <string>
#include <cstdlib>

const int MAX_MAYBAY = 300;
const int DANG_HOAT_DONG = 1;
const int KHONG_HOAT_DONG = 0;
const int MAC_DINH = 0;
const int MD_TTCB = 1;
const int HUY_CHUYEN = 0;
const int CON_VE = 1;
const int HET_VE = 2;
const int HOANTAT_CB = 3;
const int MAX_KH = 100000;
const bool DA_DAT = true;
const bool TRONG = false;
const int MAX_VE = 100;
const int ChuNormal = 1;
const int ChuNoSpace = 2;
const int So = 3;
const int SoVaChu = 4;
const int SoVaChuKyTuSpace = 5;


using namespace std;

struct MayBay {
    char soHieu[16], loai[41];
    int soDay, soDong, soChoNgoi;
    int trangThai = KHONG_HOAT_DONG;
    int sl_Bay = MAC_DINH;
};
typedef struct MayBay MB;

struct danhsachmaybay {
    MB *data[MAX_MAYBAY];
    int soMB = MAC_DINH;
};
typedef struct danhsachmaybay DSMB;

struct danhsachmaybay2 {
    MB *data2[MAX_MAYBAY];
    int soMB2 = MAC_DINH;
};
typedef struct danhsachmaybay DSMB2;

// Khai bao khach hang
struct Khach_Hang {
    char CMND[13];
    char Ho[10];
    char Ten[30];
    bool gioiTinh; // true:nam, false:nu
};
typedef struct Khach_Hang KH;

struct nodeKH{
    KH data;
    int soKH = MAC_DINH;
    struct nodeKH *left = NULL;
    struct nodeKH *right = NULL;
};
typedef struct nodeKH* TREE; //Thay thế nodeKH* bằng TREE

// CHUYEN BAY
struct Thoi_gian {
    int phut, gio, ngay, thang, nam;
};
typedef struct Thoi_gian TIME;

struct Ve {
    char Ghe_so[4];
    char CMND[13];
    bool ttVe = TRONG;
};
typedef struct Ve VE;

struct Chuyen_Bay {
    char maCB[16];
    TIME time_xp;
    char noiDi[16];
    char noiDen[16];
    int Trang_thai = MD_TTCB;
    char soHieuMB[16];
    int soLuongVe;
    int soLuongDatVe = MAC_DINH;
    VE *ve[MAX_VE];
};
typedef struct Chuyen_Bay CB;

struct nodeCB { 
    CB cb;
    int socb;
    struct nodeCB* next = NULL;
};
typedef struct nodeCB* NODECBPTR;
NODECBPTR First;
NODECBPTR p;