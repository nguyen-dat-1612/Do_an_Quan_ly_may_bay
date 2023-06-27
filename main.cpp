#include "khaibao.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <conio.h>
#include <graphics.h>
#include <windows.h>
#include "1Maybay.h"
#include "2Chuyenbay.h"
#include "3Khachhang.h"


const char text[] = "TRINH QUAN LY CHUYEN BAY";
const char MAYBAY[] = "MAY BAY";
const char CHUYENBAY[] = "CHUYEN BAY";
const char HANHKHACH[] = "HANH KHACH";
const char DATHUYVE[] = "DAT VE/HUY VE";
const char text5[] = "STT";
const char text6[] = "SO HIEU";
const char text7[] = "LOAI";
const char text8[] = "SO DAY";
const char text9[] = "SO DONG";
const char text10[] = "SO GHE";
const char text11[] = "TRANG THAI";
const char text12[] = "SO LAN BAY";
const char text13[] = "Con ve";
const char text14[] = "Het ve";
const char text15[] = "Hoan tat";
const char text16[] = "Huy chuyen";
const char text17[] = "MA CB";
const char text18[] = "NOI DI";
const char text19[] = "NOI DEN";
const char text20[] = "THOI GIAN";
const char text21[] = "VE";
const char text22[] = "TRANG THAI";
const char text23[] = "DANH SACH KHACH HANG THUOC CHUYEN BAY";
const char text24[] = "Ngay gio khoi hanh: ";
const char text25[] = "Noi den: ";
const char text26[] = "STT";
const char text27[] = "SO VE";
const char text28[] = "SO CMND";
const char text29[] = "HO TEN";
const char text30[] = "PHAI";
const char text31[] = "NGAY DI";
const char Nam[] = "Nam";
const char Nu[] = "Nu";
const char DATVE[] = "DAT VE";
const char HUYVE[] = "HUY VE";
const char text32[] = "Nhap CMND";
const char text33[] = "THONG TIN CHUYEN BAY";

const char THEM[] = "ADD";
const char EDIT[] = "EDIT";
const char XOA[] = "DEL";
const char SAVE[] = "SAVE";
const char SEARCH[] = "SEARCH";
const char THONGKE[] = "THONG KE";
const char ESC[] = "ESC";
const char UPDATE[] = "UPDATE";
const char CANCEL[] = "CANCEL";
const char LIST[] = "LIST";

const int LIGHTPINK = RGB (247, 168, 184);
const int LIGHTYELLOW = RGB(250, 250, 210);

using namespace std;

// can giua chuoi ki tu
void CENTER(int& x, int& y, char str[], int x1, int y1, int x2, int y2) {
    int textWidth = textwidth(str);
    int textHeight = textheight(str);

    x = (x1 + x2 - textWidth) / 2;
    y = (y1 + y2 - textHeight) / 2;
}

// doi mau cho khung
void Doimau(int Mau1, int Mau2, int Mau3, int Mau4){
    char MAYBAY[] = "MAY BAY";
    char CHUYENBAY[] = "CHUYEN BAY";
    char HANHKHACH[] = "HANH KHACH";
    char DATHUYVE[] = "DAT VE/HUY VE";
    char SAVE[] = "SAVE";
    int a,b;
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);

    setfillstyle(SOLID_FILL, Mau1);
    setcolor(Mau1);
    rectangle(20, 100, 355, 150);
    bar(21, 101, 354, 149);
    setcolor(WHITE);
    setbkcolor(Mau1);
    CENTER(a,b,MAYBAY, 20, 100, 355, 150);
    outtextxy(a, b, MAYBAY);

    setfillstyle(SOLID_FILL, Mau2);
    setcolor(Mau2);
    rectangle(375 + 20, 100, 730, 150);
    bar(396, 101, 729, 149);
    CENTER(a,b, CHUYENBAY, 375+20, 100, 730, 150);
    setcolor(WHITE);
    setbkcolor(Mau2);
    outtextxy(a, b, CHUYENBAY);
    
    setfillstyle(SOLID_FILL, Mau3);
    setcolor(Mau3);
    rectangle(770, 100, 1105, 150);
    bar(771, 101, 1104, 149);
    CENTER(a,b, HANHKHACH, 770, 100, 1105, 150);
    setcolor(WHITE);
    setbkcolor(Mau3);;
    outtextxy(a, b , HANHKHACH);

    setfillstyle(SOLID_FILL, Mau4);
    setcolor(Mau4);
    rectangle(1145, 100, 1480, 150);
    bar(1146, 101, 1479, 149);
    CENTER(a,b, DATHUYVE, 1145, 100, 1480, 150);
    setcolor(WHITE);
    setbkcolor(Mau4);
    outtextxy(a, b, DATHUYVE);

    setfillstyle(SOLID_FILL, LIGHTYELLOW);
    setcolor(BLACK);
    bar(1320, 20, 1420, 60);
    rectangle(1320, 20, 1420, 60);
    CENTER(a,b, SAVE, 1320, 20, 1420, 60);
    setbkcolor(LIGHTYELLOW);
    outtextxy(a, b, SAVE);

    int LIGHTRED = RGB (255, 100, 100);
    setfillstyle(SOLID_FILL, LIGHTRED);
    bar(1440, 20, 1480, 60);
    rectangle(1440, 20, 1480, 60);
    line(1440, 20, 1480, 60);
    line(1440, 60 , 1480, 20);

}
// in may bay
void inMB(DSMB& dsMB, int i, int n){
    char EDIT[] = "EDIT";
    char XOA[] = "DEL";
    int LIGHTPINK = RGB (247, 168, 184);
    int m;
    i = 9 * (i - 1);
    m = i + 9;
    int x = 0;
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    setcolor(WHITE);
    for (int k = i; k < m && k < dsMB.soMB;k++) {
        int a, b;
        if (k != n) {
            setfillstyle(SOLID_FILL, LIGHTGRAY);
            setbkcolor(LIGHTGRAY);
            setcolor(WHITE);
        }
        else {
            setfillstyle(SOLID_FILL, LIGHTPINK);
            setbkcolor(LIGHTPINK);
            setcolor(BLACK);
            
        }
        bar(41, 231 + x, 1459, 279 + x);
        if (k < dsMB.soMB) {
            CENTER(a,b, dsMB.data[k]->soHieu, 40, 230 + x, 170, 280 + x);
            outtextxy(a, b, dsMB.data[k]->soHieu);

            CENTER(a,b, dsMB.data[k]->loai, 170, 230 + x, 430, 280 + x);
            outtextxy(a, b, dsMB.data[k]->loai);

            char SoDay[3];
            sprintf(SoDay, "%d", dsMB.data[k]->soDay);
            CENTER(a,b, SoDay, 430, 230 + x, 560, 280 + x);
            outtextxy(a, b, SoDay);

            char SoDong[3];
            sprintf(SoDong, "%d", dsMB.data[k]->soDong);
            CENTER(a,b, SoDong, 560, 230 + x, 690, 280 + x);
            outtextxy(a, b, SoDong);


            char SoGhe[3];
            sprintf(SoGhe, "%d", dsMB.data[k]->soChoNgoi);
            CENTER(a,b, SoGhe, 690, 230 + x, 820, 280 + x);
            outtextxy(a, b, SoGhe);

            if (dsMB.data[k]->trangThai == 1)
            {
                char HD[] = "Dang hoat dong";
                CENTER(a,b, HD, 820, 230 + x, 1080, 280 + x);
                outtextxy(a, b, HD);
            }
            else {
                char KD[] = "Khong hoat dong";
                CENTER(a,b, KD, 820, 230 + x, 1080, 280 + x);
                outtextxy(a, b, KD);
            }
            char soLB[100];
            sprintf(soLB, "%d", dsMB.data[k]->sl_Bay);
            CENTER(a,b, soLB, 1080, 230 + x, 1210 ,280 + x);
            outtextxy(a, b, soLB);
        }
        if (k != n) {
            setfillstyle(SOLID_FILL, LIGHTGRAY);
            setbkcolor(LIGHTGRAY);
            setcolor(WHITE);
            bar(1225, 240 + x, 1325, 270 + x);
            rectangle(1225, 240 + x, 1325, 270 + x);
            CENTER(a,b, EDIT, 1225, 240 + x, 1325, 270 + x);
            outtextxy(a, b, EDIT);

            bar(1345, 240 + x, 1445, 270 + x);
            rectangle(1345, 240 + x, 1445, 270 + x);
            CENTER(a,b, XOA, 1345, 240 + x, 1445, 270 + x);
            outtextxy(a, b, XOA);
        }
        else {
            setfillstyle(SOLID_FILL, LIGHTYELLOW);
            setbkcolor(LIGHTYELLOW);
            setcolor(BLACK);
            bar(1225, 240 + x, 1325, 270 + x);
            rectangle(1225, 240 + x, 1325, 270 + x);
            CENTER(a,b, EDIT, 1225, 240 + x, 1325, 270 + x);
            outtextxy(a, b, EDIT);
            
            setfillstyle(SOLID_FILL, LIGHTRED);
            setbkcolor(LIGHTRED);
            setcolor(BLACK);

            bar(1345, 240 + x, 1445, 270 + x);
            rectangle(1345, 240 + x, 1445, 270 + x);
            CENTER(a,b, XOA, 1345, 240 + x, 1445, 270 + x);
            outtextxy(a, b, XOA);
        }
        x = x + 50;
    }
}
// khung in dsmb
void khungindsMB() { 
    char text6[] = "SO HIEU";
    char text7[] = "LOAI";
    char text8[] = "SO DAY";
    char text9[] = "SO DONG";
    char text10[] = "SO GHE";
    char text11[] = "TRANG THAI";
    char text12[] = "SO LAN BAY";
    char THEM[] = "ADD";
    char SAVE[] = "SAVE";
    char STATISTIC[] = "STATISTIC";
    int a, b;
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    setcolor(BLACK);
    rectangle(20,160, 1480, 740);
    bar(21, 161, 1479, 739);

    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar (40,180,1460,230);

    setcolor(BLACK);
    rectangle(40,180, 1460, 680);

    int k = 0;
    for (int i = 0; i <= 9 ; i++) {
        line(40,180 + k,1460, 180 + k);
        k = k + 50;
    }
    
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    setcolor(WHITE);
    setbkcolor(LIGHTBLUE);

    CENTER(a,b, text6, 40, 180, 170, 230);
    outtextxy(a, b, text6);

    CENTER(a,b, text7, 170, 180, 430, 230);
    outtextxy(a, b, text7);

    CENTER(a,b, text8, 430, 180, 560, 230);
    outtextxy(a, b, text8);

    CENTER(a,b, text9, 560, 180, 690, 230);
    outtextxy(a, b, text9);

    CENTER(a,b, text10, 690, 180, 820, 230);
    outtextxy(a, b, text10);

    CENTER(a,b, text11, 820, 180, 1080, 230);
    outtextxy(a, b, text11);

    CENTER(a,b, text12, 1080, 180, 1210 , 230);
    outtextxy(a, b, text12);

    setcolor(BLACK);
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    setfillstyle(SOLID_FILL, LIGHTGRAY);

    // ve nut them 
    rectangle(40, 700, 190, 730);
    setcolor(BLACK);
    setbkcolor(LIGHTGRAY);
    CENTER(a,b, THEM, 40, 700, 190, 730);
    outtextxy(a, b, THEM);

    //ve nut luu
    rectangle(190, 700, 340, 730);
    setcolor(BLACK);
    setbkcolor(LIGHTGRAY);
    CENTER(a,b, STATISTIC , 190, 700, 340, 730);
    outtextxy(a, b, STATISTIC);

}
// in thong ke
void inthongke(DSMB q, int i, int n){ 
    int LIGHTPINK = RGB (247, 168, 184);
    int m;
    i = 9 * (i - 1);
    m = i + 9;
    int x = 0;
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    setcolor(WHITE);
    for (int k = i; k < m;k++) {
        int a, b;
        if (k != n) {
            setfillstyle(SOLID_FILL, LIGHTGRAY);
            setbkcolor(LIGHTGRAY);
            setcolor(WHITE);
        }
        else {
            setfillstyle(SOLID_FILL, LIGHTPINK);
            setbkcolor(LIGHTPINK);
            setcolor(BLACK);
        }
        bar(156, 231 + x, 1344, 279 + x);

        if (k < q.soMB) {
            CENTER(a,b, q.data[k]->soHieu, 155, 230 + x, 285, 280 + x);
            outtextxy(a, b, q.data[k]->soHieu);

            CENTER(a,b, q.data[k]->loai, 285, 230 + x, 545, 280 + x);
            outtextxy(a, b, q.data[k]->loai);

            char SoDay[3];
            sprintf(SoDay, "%d", q.data[k]->soDay);
            CENTER(a,b, SoDay, 545, 230 + x, 675, 280 + x);
            outtextxy(a, b, SoDay);

            char SoDong[3];
            sprintf(SoDong, "%d", q.data[k]->soDong);
            CENTER(a,b, SoDong, 675, 230 + x, 805, 280 + x);
            outtextxy(a, b, SoDong);


            char SoGhe[3];
            sprintf(SoGhe, "%d", q.data[k]->soChoNgoi);
            CENTER(a,b, SoGhe, 805, 230 + x, 935, 280 + x);
            outtextxy(a, b, SoGhe);

            if (q.data[k]->trangThai == true)
            {
                char HD[] = "Dang hoat dong";
                CENTER(a,b, HD, 935 , 230 + x, 1195, 280 + x);
                outtextxy(a, b, HD);
            }
            else {
                char KD[] = "Khong hoat dong";
                CENTER(a,b, KD, 935, 230 + x, 1195, 280 + x);
                outtextxy(a, b, KD);
            }
            char soLB[100];
            sprintf(soLB, "%d", q.data[k]->sl_Bay);
            CENTER(a,b, soLB, 1195, 230 + x, 1345,280 + x);
            outtextxy(a, b, soLB);
        }
        x = x + 50;
    }
}
// khung in thong ke
void khungthongke() { 
    char text6[] = "SO HIEU";
    char text7[] = "LOAI";
    char text8[] = "SO DAY";
    char text9[] = "SO DONG";
    char text10[] = "SO GHE";
    char text11[] = "TRANG THAI";
    char text12[] = "SO LAN BAY";
    char ESC[] = "ESC";
    int a, b;
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    setcolor(BLACK);
    rectangle(20,160, 1480, 740);
    bar(21, 161, 1479, 739);

    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar (155,180,1345,230);

    setcolor(BLACK);
    rectangle(155,180, 1345, 680);

    int k = 0;
    for (int i = 0; i <= 9 ; i++) {
        line(155 ,180 + k,1345 , 180 + k);
        k = k + 50;
    }
    
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    setcolor(WHITE);
    setbkcolor(LIGHTBLUE);

    CENTER(a,b, text6, 155, 180, 285, 230);
    outtextxy(a, b, text6);

    CENTER(a,b, text7, 285, 180, 545, 230);
    outtextxy(a, b, text7);

    CENTER(a,b, text8, 545, 180, 675, 230);
    outtextxy(a, b, text8);

    CENTER(a,b, text9, 675, 180, 805, 230);
    outtextxy(a, b, text9);

    CENTER(a,b, text10, 805, 180, 935, 230);
    outtextxy(a, b, text10);

    CENTER(a,b, text11, 935, 180, 1195, 230);
    outtextxy(a, b, text11);

    CENTER(a,b, text12, 1195, 180, 1345 , 230);
    outtextxy(a, b, text12);

    setcolor(BLACK);
    setfillstyle(SOLID_FILL, LIGHTRED);
    setbkcolor(LIGHTRED);
    bar(60,200, 130, 250);
    rectangle(60,200, 130, 250);
    CENTER(a, b, ESC, 60, 200, 130, 250);
    outtextxy(a, b, ESC);

}
// thong ke may bay
void thongkeMB(DSMB q) { 
    int itemsPerPage = 9;

    // Tổng số trang
    int currentPage = 1;
    bool thoat = true;
    while (thoat == true) {
        int numPages;
        if (q.soMB % itemsPerPage != 0 )
        {
            numPages = q.soMB / itemsPerPage + 1;
        } else {
            numPages = q.soMB / itemsPerPage;
        }
        char trong[] = "";
        setcolor(BLACK);
        // Vẽ danh sách phần tử của trang hiện tại
        int startIndex = (currentPage - 1) * itemsPerPage;
        khungthongke();
        inthongke(q, currentPage, -1);
        int a, b;
        char stt[4];
        sprintf(stt, "%d", currentPage, numPages);
        rectangle(1250, 700, 1300, 730);
        CENTER(a, b, stt, 1250, 700, 1300, 730);
        outtextxy(a,b, stt);
        int i;
        int m;
        i = 9 * (currentPage - 1);
        m = i + 9;
        // Vẽ nút điều hướng
        if (currentPage > 1) {
            char trai[] = "<";
            rectangle(1200, 700, 1250, 730);
            CENTER(a, b, trai, 1200, 700, 1250, 730);
            outtextxy(a, b, trai);
        }
        if (currentPage < numPages) {
            char phai[] = ">";
            rectangle(1300, 700, 1350, 730);
            CENTER(a, b, phai, 1300, 700, 1350, 730);
            outtextxy(a, b, phai);
        }
        // Chờ sự kiện nhấn nút
        int x = mousex();
        int y = mousey();
        while (!ismouseclick(WM_LBUTTONDOWN)) {
            delay(100);
        }
        getmouseclick(WM_LBUTTONDOWN, x, y);
        // Xử lý sự kiện
        if (x >= 1200 && x <= 1250 && y >= 700 && y <= 750 && currentPage > 1) {
            currentPage--;
        } else if (x >= 1300 && x <= 1350 && y >= 700 && y <= 750 && currentPage < numPages) {
            currentPage++;
        } else if ((y >= 200 && y <= 250 && x >= 60 && x <= 130)) {
            thoat = false;
            break;
        }

    }
}
// check chuoi nhap 
bool ktrKyTu(char &a, bool space, bool chu, bool so, bool kyTu){ 
	//if(space&&a==' ') return true;
    static int dem = 0; 
    if (space && a == ' ') {
        if (dem > 0) {
            return false; // Đã gặp khoảng trắng trước đó, không chấp nhận ký tự khoảng trắng này
        } else {
            dem++;
            return true;
        }
    } else {
        dem = 0; // Không phải là khoảng trắng, đặt dem về 0
    }
	if(chu){
		for(char i='a'; i<='z'; i++){
			if(a==i){
				a -= 32;// chu thuong in thanh chu in hoa
				return true;
			}
		}
		for(char i='A'; i<='Z'; i++){
			if(a==i)
			return true;
		}
	}
	if(so){
		for(char i = '0'; i<='9'; i++){
			if(a==i) return true;
		}
	}
    if(kyTu){
        if (char i = 45){
            if (a==i)
            return true;
        }
    }
	return false;
}
// khung nhap chuoi ki tu
void khungText (int x1, int y1, int x2, int y2, int max, int loai, char textTD[], char textNhap[], int x, int y){ 
    setbkcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL, WHITE);
    bar(x1 + 1, y1 +1, x2 - 1, y2 - 1);
    setcolor(BLACK);
    rectangle(x1, y1, x2, y2);
    char nhap[2] = "_";
    char temp[50]= "";
    int a = strlen(textNhap);
    int i;
    if (a == 0) {
        i = 0;
        temp[i] = '_';
        temp[i+1] = '\0';
    }
    else {
        i = strlen(textNhap);
        strcpy(temp, textNhap);
        strcat(temp, nhap);
    }
    setbkcolor(WHITE);
    outtextxy(x1 + 10, y1+ 15, temp);
    int m1,n1;
    switch (loai){
        case ChuNormal:{
            while (true) {
                if (kbhit()){
                    if(ismouseclick(WM_LBUTTONDOWN)){
                        getmouseclick(WM_LBUTTONDOWN, m1, n1);
                        m1=0; n1=0;
                    }
                    char c = getch();
                    if (c == 8 && i >= 1) {
                        i--;
                        temp[i] = 95;
                        temp[i+1] = '\0';
                        setfillstyle(1,15);
                        bar(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
                        setbkcolor(WHITE);
                        outtextxy(x1+ 10, y1+ 15, temp);
                }   
                else if (ktrKyTu(c, true, true, false, false) && i < max ) {
                        temp[i] = c;
                        i++;
                        temp[i] = 95;
                        temp[i+1] = '\0';
                        setfillstyle(1,15);
                        bar(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
                        setbkcolor(WHITE);
                        outtextxy(x1+ 10, y1+ 15, temp);
                    }
                if (i < 1){
                    setbkcolor(LIGHTGRAY);
			        char gh[20]="*Vui long nhap";
                    setfillstyle(1,7);
                    bar(x1, y2 + 5, x1+230, y2+40);
			        outtextxy(x1 + 10, y2 + 10,gh);
                    setbkcolor(WHITE);
			        outtextxy(x1 + 10, y1 + 15,temp);
                } else {
                    setfillstyle(1, 7);
                    bar(x1, y2 + 5, x1+230, y2+40);
                }
                    if (c == 13) {
                        setbkcolor(LIGHTGRAY);
                        if (temp[0] == ' '){
                            for (int j = 0; j <strlen(temp); j++){
                                temp[j] = temp[j+1];
                            }
                            i--;
                        }
                        temp[i] = '\0';
                        if (temp[i-1] == ' '){
                            temp[i-1] ='\0';
                        } 
                        setfillstyle(1,7);
                        bar(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
                        outtextxy(x1+ 10, y1+ 15, temp);
                        strcpy(textNhap, temp);
                        break;
                }
            }
        }
    } break;
    case ChuNoSpace:{
            while (true) {
                if (kbhit()){
                    if(ismouseclick(WM_LBUTTONDOWN)){
                        getmouseclick(WM_LBUTTONDOWN, m1, n1);
                        m1=0; n1=0;
                    }
                    char c = getch();
                    if (c == 8 && i >= 1) {
                        i--;
                        temp[i] = 95;
                        temp[i+1] = '\0';
                        setfillstyle(1,15);
                        bar(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
                        setbkcolor(WHITE);
                        outtextxy(x1+ 10, y1+ 15, temp);
                }   
                else if (ktrKyTu(c, false, true, false, false) && i < max ) {
                        temp[i] = c;
                        i++;
                        temp[i] = 95;
                        temp[i+1] = '\0';
                        setfillstyle(1,15);
                        bar(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
                        setbkcolor(WHITE);
                        outtextxy(x1+ 10, y1+ 15, temp);
                    }
                if (i < 1){
                    setbkcolor(LIGHTGRAY);
			        char gh[20]="*Vui long nhap";
                    setfillstyle(1,7);
                    bar(x1, y2 + 5, x1+230, y2+40);
			        outtextxy(x1 + 10, y2+10,gh);
                    setbkcolor(WHITE);
			        outtextxy(x1 + 10, y1 + 15,temp);
                } else {
                    setfillstyle(1, 7);
                    bar(x1, y2 + 5, x1+230, y2+40);
                }
                    if (c == 13) {
                        setbkcolor(7);
                        temp[i] = '\0';
                        setfillstyle(1,7);
                        bar(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
                        outtextxy(x1 + 10, y1+ 15, temp);
                        strcpy(textNhap, temp);
                        break;
                }
            }
        }
    } break;
    case So:{
            while (true) {
                if (kbhit()){
                    if(ismouseclick(WM_LBUTTONDOWN)){
                        getmouseclick(WM_LBUTTONDOWN, m1, n1);
                        m1=0; n1=0;
                    }
                    char c = getch();
                    if (c == 8 && i >= 1) {
                        i--;
                        temp[i] = 95;
                        temp[i+1] = '\0';
                        setfillstyle(1,15);
                        bar(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
                        setbkcolor(WHITE);
                        outtextxy(x1+ 10, y1+ 15, temp);
                }   
                else if (ktrKyTu(c, false, false, true, false) && i < max ) {
                        temp[i] = c;
                        i++;
                        temp[i] = 95;
                        temp[i+1] = '\0';
                        setfillstyle(1,15);
                        bar(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
                        setbkcolor(WHITE);
                        outtextxy(x1+ 10, y1+ 15, temp);
                    }
                if (i < 1){
                    setbkcolor(LIGHTGRAY);
			        char gh[20]="*Vui long nhap";
                    setfillstyle(1,7);
                    bar(x1, y2 + 5, x1+230, y2+40);
			        outtextxy(x1 + 10, y2+10,gh);
                    setbkcolor(WHITE);
			        outtextxy(x1 + 10, y1 + 15,temp);
                } else {
                    setfillstyle(1, 7);
                    bar(x1, y2 + 5, x1+230, y2+40);
                }
                    if (c == 13) {
                        setbkcolor(7);
                        temp[i] = '\0';
                        setfillstyle(1,7);
                        bar(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
                        outtextxy(x1+ 10, y1+ 15, temp);
                        strcpy(textNhap, temp);
                        break;
                }
            }
        }
    }break;
    case SoVaChu:{
            while (true) {
                if (kbhit()){
                    if(ismouseclick(WM_LBUTTONDOWN)){
                        getmouseclick(WM_LBUTTONDOWN, m1, n1);
                        m1=0; n1=0;
                    }
                    char c = getch();
                    if (c == 8 && i >= 1) {
                        i--;
                        temp[i] = 95;
                        temp[i+1] = '\0';
                        setfillstyle(1,15);
                        bar(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
                        setbkcolor(WHITE);
                        outtextxy(x1+ 10, y1+ 15, temp);
                }   
                else if (ktrKyTu(c, false, true, true, false) && i < max ) {
                        temp[i] = c;
                        i++;
                        temp[i] = 95;
                        temp[i+1] = '\0';
                        setfillstyle(1,15);
                        bar(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
                        setbkcolor(WHITE);
                        outtextxy(x1+ 10, y1+ 15, temp);
                    }
                if (i < 1){
                    setbkcolor(LIGHTGRAY);
			        char gh[20]="*Vui long nhap";
                    setfillstyle(1,7);
                    bar(x1, y2 + 5, x1+230, y2+40);
			        outtextxy(x1 + 10, y2+10,gh);
                    setbkcolor(WHITE);
			        outtextxy(x1 + 10, y1 + 15,temp);
                } else {
                    setfillstyle(1, 7);
                    bar(x1, y2 + 5, x1+230, y2+40);
                }
                    if (c == 13) {
                        setbkcolor(7);
                        temp[i] = '\0';
                        setfillstyle(1,7);
                        bar(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
                        outtextxy(x1+ 10, y1+ 15, temp);
                        strcpy(textNhap, temp);
                        break;
                }
            }
        }
    }break;
    case SoVaChuKyTuSpace:{
            while (true) {
                if (kbhit()){
                    if(ismouseclick(WM_LBUTTONDOWN)){
                        getmouseclick(WM_LBUTTONDOWN, m1, n1);
                        m1=0; n1=0;
                    }
                    char c = getch();
                    if (c == 8 && i >= 1) {
                        i--;
                        temp[i] = 95;
                        temp[i+1] = '\0';
                        setfillstyle(1,15);
                        bar(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
                        setbkcolor(WHITE);
                        outtextxy(x1+ 10, y1+ 15, temp);
                }   
                else if (ktrKyTu(c, true, true, true, true) && i < max ) {
                        temp[i] = c;
                        i++;
                        temp[i] = 95;
                        temp[i+1] = '\0';
                        setfillstyle(1,15);
                        bar(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
                        setbkcolor(WHITE);
                        outtextxy(x1+ 10, y1+ 15, temp);
                    }
                if (i < 1){
                    setbkcolor(LIGHTGRAY);
			        char gh[20]="*Vui long nhap";
                    setfillstyle(1,7);
                    bar(x1, y2 + 5, x1+230, y2+40);
			        outtextxy(x1 + 10, y2+10,gh);
                    setbkcolor(WHITE);
			        outtextxy(x1 + 10, y1 + 15,temp);
                } else {
                    setfillstyle(1, 7);
                    bar(x1, y2 + 5, x1+230, y2+40);
                }
                    if (c == 13) {
                        setbkcolor(7);
                        if (temp[0] == ' '){
                            for (int j = 0; j <strlen(temp); j++){
                                temp[j] = temp[j+1];
                            }
                            i--;
                        }
                        temp[i] = '\0';
                        if (temp[i-1] == ' '){
                            temp[i-1] ='\0';
                        } 
                        setfillstyle(1,7);
                        bar(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
                        outtextxy(x1+ 10, y1+ 15, temp);
                        strcpy(textNhap, temp);
                        break;
                }
            }
        }
    }break;
        
    }
}
// them may bay
void THEMMBMOI(DSMB& dsMB, MB mb, int LIGHTPINK) { 
    char TIEUDE[] = "THEM MB MOI";
    char text6[] = "SO HIEU";
    char text7[] = "LOAI";
    char text8[] = "SO DAY";
    char text9[] = "SO DONG";
    char ESC[] = "ESC";
    char SAVE[] = "SAVE";

    int chiso;
    int a, b;

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    setcolor(BLACK);
    rectangle(20,160, 1480, 740);
    bar(21, 161, 1479, 739);


    setcolor(BLACK);
    rectangle(40,180, 1460, 680);

    setcolor(BLACK);
    setbkcolor(LIGHTGRAY);
    CENTER(a, b, TIEUDE, 40,200, 1460, 230);
    outtextxy(a, b, TIEUDE);
    outtextxy(400, 280, text6);
    outtextxy(400, 380, text7);
    outtextxy(400, 480, text8);
    outtextxy(400, 580, text9);
    setfillstyle(SOLID_FILL, WHITE);
    rectangle(600,260, 1000, 310);
    rectangle(600,360, 1000, 410);
    rectangle(600,460, 1000, 510);
    rectangle(600,560, 1000, 610);

    //vẽ nút nhấn esc
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, LIGHTRED);
    setbkcolor(LIGHTRED);
    bar(60,200, 130, 250);
    rectangle(60,200, 130, 250);
    CENTER(a, b, ESC, 60, 200, 130,250);
    outtextxy(a, b, ESC);

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    setcolor(BLACK);
    setbkcolor(LIGHTGRAY);
    // vẽ nút nhấn save
    rectangle(1350,610, 1440, 660);
    CENTER(a, b, SAVE, 1350,610, 1440, 660);
    outtextxy(a, b, SAVE);
    char ho[7];
    char soHieu[16] = "";
    char loai[41] = "";
    char soday[3] ="";
    char sodong[3] = "";

    bool testsoHieu = false;
    bool testloai = false;
    bool testsodong = false;
    bool testsoday = false;

    char trong[] = "";

    while(true){
        int x = mousex();
        int y = mousey();
        while (!ismouseclick(WM_LBUTTONDOWN)) {
            delay(100);
        }

        getmouseclick(WM_LBUTTONDOWN, x, y);
        if (y >= 260 && y <= 310 && x >= 600 && x <= 1000) {
            //getmouseclick(WM_LBUTTONDOWN, x, y);
            //nhap(600, 260, 1000, 310, 7, 0, Ho, ho, x, y);
            setfillstyle(1,7);
            bar(600, 260+60, 1000+70, 310+47);
            khungText(600, 260, 1000, 310, 16, SoVaChu, text6, soHieu, x, y);
            if (strcmp(soHieu, trong) != 0 && checkMB(dsMB, soHieu, chiso) == false)  {
                strcpy(mb.soHieu, soHieu);
                testsoHieu = true;
            } else if (checkMB(dsMB, soHieu, chiso) == true) {
                char loi[] = "*So hieu may bay da ton tai!";
                    setfillstyle(1,7);
                    bar(600, 260+60, 1000+70, 310+47);
                    outtextxy(600+10, 260+60, loi);
                testsoHieu = false;

            } else {
                testsoHieu = false;
            }
        }
        else if (y >= 360 && y <= 410 && x >= 600 && x <= 1000) {
           // getmouseclick(WM_LBUTTONDOWN, x, y);
            khungText(600, 360, 1000, 410, 41, SoVaChuKyTuSpace, text7, loai, x, y);
            if (strcmp(loai, trong) != 0) {
                strcpy(mb.loai, loai);
                testloai = true;
            }
            else {
                testloai = false;
            }
        }
        else if (y >= 460 && y <= 510 && x >= 600 && x <= 1000){
            //getmouseclick(WM_LBUTTONDOWN, x, y);
            setfillstyle(1,7);
            bar(600, 460+60, 1000+70, 510+47);
            khungText(600, 460, 1000, 510, 1, So, text8, soday, x, y);
            if (strcmp(soday, trong) != 0) {
                if (stoi(soday) < 1 || stoi(soday) > 5){
                    setbkcolor(LIGHTGRAY);
                    char gh[40] = "*So khong nam trong khoang 1-5";
                    setfillstyle(1,7);
                    bar(600, 460+60, 1000+70, 510+47);
                    outtextxy(600+10, 460+60, gh);
                    testsoday = false;
                }
                else{
                    setfillstyle(1, 7);
                    bar(600, 460+60, 1000+70, 510+47);
                    mb.soDay = stoi(soday);
                    testsoday = true;
                }
            } else {
                testsoday = false;
            }
        }
        else if (y >= 560 && y <= 610 && x >= 600 && x <= 1000){
           // getmouseclick(WM_LBUTTONDOWN, x, y);
           setfillstyle(1,7);
            bar(600, 560+60, 1000+70, 610+47);
            khungText(600, 560, 1000, 610, 2, So, text9, sodong, x, y);
            if (strcmp(sodong, trong) != 0) {
                if (stoi(sodong) < 1 || stoi(sodong) > 20){
                    setbkcolor(LIGHTGRAY);
                    char gh[40] = "*So khong nam trong khoang 1-20";
                    setfillstyle(1,7);
                    bar(600, 560+60, 1000+70, 610+47);
                    outtextxy(600+10, 560+60, gh);
                    testsodong = false;
                }
                else{
                    setfillstyle(1, 7);
                    bar(600, 560+60, 1000+70, 610+47);
                    testsodong = true;
                    mb.soDong = stoi(sodong);
                }
            }
            else {
                testsodong = false;
            }
        }
        else if ((y >= 610 && y <= 660 && x >= 1350 && x <= 1440) && (testloai == true &&  testsoday == true &&  testsodong == true &&  testsoHieu == true) && (y >= 610 && y <= 660 && x >= 1350 && x <= 1440)) {  
            mb.soChoNgoi = mb.soDay * mb.soDong;
            addMB(dsMB,mb.soHieu,mb.loai,mb.soDay,mb.soDong,mb.soChoNgoi, chiso);
            getmouseclick(WM_LBUTTONDOWN, x, y); 
            break;
        }
        else if ((y >= 100 && y <= 150 && x >= 395 && x <= 730) || (y >= 100 && y <= 150 && x >= 770 && x <= 1105) || 
                (y >= 100 && y <= 150 && x >= 1145 && x <= 1480) || (y >= 200 && y <= 250 && x >= 60 && x <= 130)) {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            break;
        }
    }
    Quick_Sort(dsMB.data, 0, dsMB.soMB - 1, 0);
}
// hieu chinh may bay
void HIEUCHINHMB(DSMB& dsMB, MB mb, int LIGHTPINK, int chiso, NODECBPTR& First, CB cb){
    char TIEUDE[] = "SUA MAY BAY";
    int a, b;
    char text6[] = "SO HIEU";
    char text7[] = "LOAI";
    char text8[] = "SO DAY";
    char text9[] = "SO DONG";
    char ESC[] = "ESC";
    char UPDATE[] = "UPDATE";

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    setcolor(BLACK);
    rectangle(20,160, 1480, 740);
    bar(21, 161, 1479, 739);


    setcolor(BLACK);
    rectangle(40,180, 1460, 680);

    setcolor(BLACK);
    setbkcolor(LIGHTGRAY);
    CENTER(a, b, TIEUDE, 40,200, 1460, 230);
    outtextxy(a, b, TIEUDE);
    outtextxy(400, 280, text6);
    outtextxy(400, 380, text7);
    outtextxy(400, 480, text8);
    outtextxy(400, 580, text9);
    setfillstyle(SOLID_FILL, WHITE);
    rectangle(600,260, 1000, 310);
    rectangle(600,360, 1000, 410);
    rectangle(600,460, 1000, 510);
    rectangle(600,560, 1000, 610);

    setcolor(BLACK);
    setfillstyle(SOLID_FILL, LIGHTRED);
    setbkcolor(LIGHTRED);
    bar(60,200, 130, 250);
    rectangle(60,200, 130, 250);
    CENTER(a, b, ESC, 60, 200, 130,250);
    outtextxy(a, b, ESC);

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    setcolor(BLACK);
    setbkcolor(LIGHTGRAY);
    // vẽ nút nhấn save
    rectangle(1350,610, 1440, 660);
    CENTER(a, b, UPDATE, 1350,610, 1440, 660);
    outtextxy(a, b, UPDATE);

    char ho[7];
    char soHieu[16] = "";
    char soHieuCu[16] = "";
    char loai[41] = "";
    char soday[3] ="";
    char sodong[3] = "";

    bool testsoHieu = true;
    bool testloai = true;
    bool testsodong = true;
    bool testsoday = true;

    char trong[] = ""; 
    setcolor(BLACK);
    outtextxy(600 + 10, 260 + 15, dsMB.data[chiso]->soHieu);
    outtextxy(600 + 10, 360 + 15, dsMB.data[chiso]->loai);
    sprintf(soday, "%d", dsMB.data[chiso]->soDay); 
    outtextxy(600 + 10, 460 + 15, soday);
    sprintf(sodong, "%d", dsMB.data[chiso]->soDong);
    outtextxy(600 + 10, 560 + 15, sodong);
    strcpy(soHieu, dsMB.data[chiso]->soHieu);
    strcpy(soHieuCu, dsMB.data[chiso]->soHieu);
    strcpy(loai, dsMB.data[chiso]->loai);
    sprintf(sodong, "%d", dsMB.data[chiso]->soDong);
    while(true){
        int x = mousex();
        int y = mousey();
        while (!ismouseclick(WM_LBUTTONDOWN)) {
            delay(100);
        }
        getmouseclick(WM_LBUTTONDOWN, x, y);
        if (y >= 260 && y <= 310 && x >= 600 && x <= 1000) {
            //getmouseclick(WM_LBUTTONDOWN, x, y);
            //nhap(600, 260, 1000, 310, 7, 0, Ho, ho, x, y);
            setfillstyle(1,7);
            bar(600, 260+60, 1000+70, 310+47);
            khungText(600, 260, 1000, 310, 16, SoVaChu, text6, soHieu, x, y);
            if (strcmp(soHieu, trong) != 0 && checkMBngoaichiso (dsMB, soHieu, chiso) == false)  {
                testsoHieu = true;
            } 
            if (strcmp(soHieu, trong) != 0 && checkMBngoaichiso(dsMB, soHieu, chiso) == true) {
                char loi[] = "*So hieu may bay da ton tai!";
                setfillstyle(1,7);
                bar(600, 260+60, 1000+70, 310+47);
                outtextxy(600+10, 260+60, loi);
                testsoHieu = false;

            } 
            if (strcmp(soHieu,trong) == 0) {
                testsoHieu = false;
            }
        }
        else if (y >= 360 && y <= 410 && x >= 600 && x <= 1000) {
           // getmouseclick(WM_LBUTTONDOWN, x, y);
            khungText(600, 360, 1000, 410, 41, SoVaChuKyTuSpace, text7, loai, x, y);
            if (strcmp(loai, trong) != 0) {
                testloai = true;
            }
            else {
                testloai = false;
            }
        }
        else if (y >= 460 && y <= 510 && x >= 600 && x <= 1000){
            //getmouseclick(WM_LBUTTONDOWN, x, y);
            setfillstyle(1,7);
            bar(600, 460+60, 1000+70, 510+47);
            khungText(600, 460, 1000, 510, 1, So, text8, soday, x, y);
            if (strcmp(soday, trong) != 0) {
                if (stoi(soday) < 1 || stoi(soday) > 5){
                    setbkcolor(LIGHTGRAY);
                    char gh[40] = "*So khong nam trong khoang 1-5";
                    setfillstyle(1,7);
                    bar(600, 460+60, 1000+70, 510+47);
                    outtextxy(600+10, 460+60, gh);
                    testsoday = false;
                }
                else{
                    setfillstyle(1, 7);
                    bar(600, 460+60, 1000+70, 510+47);
                    testsoday = true;
                }
            } else {
                testsoday = false;
            }
        }
        else if (y >= 560 && y <= 610 && x >= 600 && x <= 1000){
           // getmouseclick(WM_LBUTTONDOWN, x, y);
           setfillstyle(1,7);
            bar(600, 560+60, 1000+70, 610+47);
            khungText(600, 560, 1000, 610, 2, So,text9, sodong, x, y);
            if (strcmp(sodong, trong) != 0) {
                if (stoi(sodong) < 1 || stoi(sodong) > 20){
                    setbkcolor(LIGHTGRAY);
                    char gh[40] = "*So khong nam trong khoang 1-20";
                    setfillstyle(1,7);
                    bar(600, 560+60, 1000+70, 610+47);
                    outtextxy(600+10, 560+60, gh);
                    testsodong = false;
                }
                else{
                    setfillstyle(1, 7);
                    bar(600, 560+60, 1000+70, 610+47);
                    testsodong = true;
                }
            }
            else {
                testsodong = false;
            }
        }
        else if((y >= 610 && y <= 660 && x >= 1350 && x <= 1440) && testloai == true && testsoday == true && testsodong == true && testsoHieu == true) {
            if (checkcbonMB(dsMB,First,chiso) == false) {
                char baoloi[] = "May bay dang co chuyen bay chua hoan tat, khong the hieu chinh! Vui long thoat !";
                CENTER(a, b, baoloi, 40, 610, 1460, 690);
                outtextxy(a,b, baoloi);
            } else {
                UpdateMB(dsMB, soHieu, loai, stoi(soday), stoi(sodong), stoi(soday) * stoi(sodong), chiso);
                updatehcmb(dsMB, First, chiso, soHieu, soHieuCu,cb);
            break;
            }

        }
        else if ((y >= 100 && y <= 150 && x >= 395 && x <= 730) || (y >= 100 && y <= 150 && x >= 770 && x <= 1105) || 
                (y >= 100 && y <= 150 && x >= 1145 && x <= 1480) || (y >= 200 && y <= 250 && x >= 60 && x <= 130)) {
            break;
        }
    }
    Quick_Sort(dsMB.data, 0, dsMB.soMB - 1, 0);
}
// in chuyen bay
void inCB(NODECBPTR& First, CB cb, int i, int numPages) {
    char text13[] = "Con ve";
    char text14[] = "Het ve";
    char text15[] = "Hoan tat";
    char text16[] = "Huy chuyen";
    char LIST[] = "LIST";
    char UPDATE[] = "UPDATE";
    char CANCEL[] = "CANCEL";
    int x = 50;;
    NODECBPTR q = First;
    
    int startIdx = 9 * (numPages - 1);
    int endIdx = startIdx + 9;
    
    // Di chuyển con trỏ q đến vị trí bắt đầu của trang hiện tại
    for (int idx = 0; idx < startIdx && q != NULL; idx++) {
        q = q->next;
    }
    settextstyle(BOLD_FONT, HORIZ_DIR, 1);
    // In ra tối đa 9 chuyến bay trên trang hiện tại
    for (int idx = startIdx; idx < endIdx && q != NULL; idx++) {
        if (idx != i) {
            setfillstyle(SOLID_FILL, LIGHTGRAY);
            setcolor(WHITE);
            setbkcolor(LIGHTGRAY);
        }
        else {
            setfillstyle(SOLID_FILL, LIGHTPINK);
            setcolor(BLACK);
            setbkcolor(LIGHTPINK);
        }
        int a, b;
        bar(41, 181 + x, 1460, 229 + x);
        if (q != NULL) {

            CENTER(a, b, q->cb.maCB, 40, 180 + x, 130, 230 + x);
            outtextxy(a, b, q->cb.maCB);

            CENTER(a, b, q->cb.noiDi, 130 , 180 + x, 310, 230 + x);
            outtextxy(a, b, q->cb.noiDi);

            CENTER(a, b, q->cb.noiDen, 310, 180 + x, 490, 230 + x);
            outtextxy(a, b, q->cb.noiDen);

            char thoigian[50];
            char c[6];
            sprintf(c, "%d", q->cb.time_xp.ngay);
            strcpy(thoigian, c);
            strcat(thoigian, "/");

            sprintf(c, "%d", q->cb.time_xp.thang);
            strcat(thoigian, c);
            strcat(thoigian, "/");

            sprintf(c, "%d", q->cb.time_xp.nam);
            strcat(thoigian, c);
            strcat(thoigian, "  ");

            sprintf(c, "%d", q->cb.time_xp.gio);
            strcat(thoigian, c);
            strcat(thoigian, ":");

            sprintf(c, "%d", q->cb.time_xp.phut);
            strcat(thoigian, c);

            CENTER(a, b, thoigian, 490, 180 + x, 670, 230 + x);
            outtextxy(a, b, thoigian);

            sprintf(c, "%d", q->cb.soLuongDatVe);
            strcpy(thoigian, c);
            strcat(thoigian, "/");

            sprintf(c, "%d", q->cb.soLuongVe);
            strcat(thoigian, c);

            CENTER(a, b, thoigian, 670, 180 + x, 740, 230 + x);
            outtextxy(a, b, thoigian);

            if (q->cb.Trang_thai == CON_VE) {
                CENTER(a, b, text13, 740, 180 + x, 920, 230 + x);
                outtextxy(a, b, text13);
            }
            else if (q->cb.Trang_thai == HET_VE) {
                CENTER(a, b, text14,  740, 180 + x, 920, 230 + x);
                outtextxy(a, b, text14);
            }
            else if (q->cb.Trang_thai == HOANTAT_CB) {
                CENTER(a, b, text15,  740, 180 + x, 920, 230 + x);
                outtextxy(a, b, text15);
            }
            else if (q->cb.Trang_thai == HUY_CHUYEN) {
                CENTER(a, b, text16,  740, 180 + x, 920, 230 + x);
                outtextxy(a, b, text16);
            }
            CENTER(a, b, q->cb.soHieuMB, 920, 180 + x, 1010, 230 + x);
            outtextxy(a, b, q->cb.soHieuMB);
            
            bar(1105, 190 + x, 1205,  220 + x);
            bar(1225, 190 + x, 1325,  220 + x);
            bar(1345, 190 + x, 1445,  220 + x);
            rectangle(1105, 190 + x, 1205,  220 + x);
            rectangle(1225, 190 + x, 1325,  220 + x);
            rectangle(1345, 190 + x, 1445,  220 + x);
            CENTER(a,b, LIST, 1105, 190 + x, 1205,  220 + x);
            outtextxy(a, b, LIST);
            CENTER(a,b, UPDATE, 1225, 190 + x, 1325,  220 + x);
            outtextxy(a, b, UPDATE);
            CENTER(a,b, CANCEL, 1345, 190 + x, 1445,  220 + x);
            outtextxy(a, b, CANCEL);
        }
        if (idx != i) {

            setfillstyle(SOLID_FILL, LIGHTGRAY);
            setcolor(WHITE);
            setbkcolor(LIGHTGRAY);
            bar(1105, 190 + x, 1205,  220 + x);
            bar(1225, 190 + x, 1325,  220 + x);
            rectangle(1105, 190 + x, 1205,  220 + x);
            rectangle(1225, 190 + x, 1325,  220 + x);
            CENTER(a,b, LIST, 1105, 190 + x, 1205,  220 + x);
            outtextxy(a, b, LIST);
            CENTER(a,b, UPDATE, 1225, 190 + x, 1325,  220 + x);
            outtextxy(a, b, UPDATE);

            bar(1345, 190 + x, 1445,  220 + x);
            rectangle(1345, 190 + x, 1445,  220 + x);
            CENTER(a,b, CANCEL, 1345, 190 + x, 1445,  220 + x);
            outtextxy(a, b, CANCEL);
        }
        else {
            setfillstyle(SOLID_FILL, LIGHTYELLOW);
            setcolor(BLACK);
            setbkcolor(LIGHTYELLOW);

            bar(1105, 190 + x, 1205,  220 + x);
            bar(1225, 190 + x, 1325,  220 + x);
            rectangle(1105, 190 + x, 1205,  220 + x);
            rectangle(1225, 190 + x, 1325,  220 + x);
            CENTER(a,b, LIST, 1105, 190 + x, 1205,  220 + x);
            outtextxy(a, b, LIST);
            CENTER(a,b, UPDATE, 1225, 190 + x, 1325,  220 + x);
            outtextxy(a, b, UPDATE);

            setfillstyle(SOLID_FILL, LIGHTRED);
            setcolor(BLACK);
            setbkcolor(LIGHTRED);
            bar(1345, 190 + x, 1445,  220 + x);
            rectangle(1345, 190 + x, 1445,  220 + x);
            CENTER(a,b, CANCEL, 1345, 190 + x, 1445,  220 + x);
            outtextxy(a, b, CANCEL);
        }
        x = x + 50;
        q = q->next;
    }
}
// in chuyen bay con ve hoac het ve trong thơi diem tim kiem
void inCBconVe(NODECBPTR& First, int i, int numPages, char* ngay, char* thang, char* nam, char* noidi, char* noiden) {
    char text13[] = "Con ve";
    char text14[] = "Het ve";
    char DATVE[] = "DAT VE";
    char HUYVE[] = "HUY VE";

    int x = 50;
    int k = 0;
    settextstyle(BOLD_FONT, HORIZ_DIR, 1);
    for (int m = 0; m < 7 ; m++) {
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        setcolor(BLACK);
        setbkcolor(LIGHTGRAY); 
        line(40,280 + k,1460, 280 + k);
        k = k + 50;
        bar(41, 281 + k, 1460, 329 + k);
    }

    NODECBPTR q;
    q  = First;

    int dem = 0;
    for (q; q != NULL && dem < (numPages - 1) * 7; q = q->next) {
        if (strcmp(q->cb.noiDi, noidi) == 0 && strcmp(q->cb.noiDen, noiden) == 0
        && q->cb.time_xp.ngay == stoi(ngay) && q->cb.time_xp.thang == stoi(thang) && q->cb.time_xp.nam == stoi(nam) && (q->cb.Trang_thai == CON_VE || q->cb.Trang_thai == HET_VE)) {
            dem = dem + 1;
        }
    }
        dem = (numPages - 1) * 7;
    for (q ; q != NULL && dem < numPages * 7; q = q->next) {
        if (dem != i) {
            setfillstyle(SOLID_FILL, LIGHTGRAY);
            setcolor(WHITE);
            setbkcolor(LIGHTGRAY);
        }
        else {
            setfillstyle(SOLID_FILL, LIGHTPINK);
            setcolor(BLACK);
            setbkcolor(LIGHTPINK);
            bar(41, 281 + x, 1460, 329 + x);
        }
        int a, b;
        if (strcmp(q->cb.noiDi, noidi) == 0 && strcmp(q->cb.noiDen, noiden) == 0
        && q->cb.time_xp.ngay == stoi(ngay) && q->cb.time_xp.thang == stoi(thang) && q->cb.time_xp.nam == stoi(nam) && (q->cb.Trang_thai == CON_VE || q->cb.Trang_thai == HET_VE)) {

            CENTER(a, b, q->cb.maCB, 40, 280 + x, 130, 330 + x);
            outtextxy(a, b, q->cb.maCB);

            CENTER(a, b, q->cb.noiDi, 130 , 280 + x, 380, 330 + x);
            outtextxy(a, b, q->cb.noiDi);

            CENTER(a, b, q->cb.noiDen, 380, 280 + x, 630, 330 + x);
            outtextxy(a, b, q->cb.noiDen);

            char thoigian[50];
            char c[6];
            sprintf(c, "%d", q->cb.time_xp.ngay);
            strcpy(thoigian, c);
            strcat(thoigian, "/");

            sprintf(c, "%d", q->cb.time_xp.thang);
            strcat(thoigian, c);
            strcat(thoigian, "/");

            sprintf(c, "%d", q->cb.time_xp.nam);
            strcat(thoigian, c);
            strcat(thoigian, "  ");

            sprintf(c, "%d", q->cb.time_xp.gio);
            strcat(thoigian, c);
            strcat(thoigian, ":");

            sprintf(c, "%d", q->cb.time_xp.phut);
            strcat(thoigian, c);

            CENTER(a, b, thoigian, 630, 280 + x, 880, 330 + x);
            outtextxy(a, b, thoigian);

            sprintf(c, "%d", q->cb.soLuongDatVe);
            strcpy(thoigian, c);
            strcat(thoigian, "/");

            sprintf(c, "%d", q->cb.soLuongVe);
            strcat(thoigian, c);

            CENTER(a, b, thoigian, 880, 280 + x, 970, 330 + x);
            outtextxy(a, b, thoigian);
            if (q->cb.Trang_thai == CON_VE) {
                CENTER(a, b, text13, 970, 280 + x, 1150, 330 + x);
                outtextxy(a, b, text13);
            }
            if (q->cb.Trang_thai == HET_VE) {
                CENTER(a, b, text14, 970, 280 + x, 1150, 330 + x);
                outtextxy(a, b, text14);
            }
            
            CENTER(a, b, q->cb.soHieuMB, 1150, 280 + x, 1240, 330 + x);
            outtextxy(a, b, q->cb.soHieuMB);
            if (dem == i) {

                if (q->cb.Trang_thai == HET_VE) {
                    setfillstyle(SOLID_FILL, LIGHTGRAY);
                    setbkcolor(LIGHTGRAY);
                    setcolor(BLACK);
                    bar(1260, 290 + x, 1340,  320 + x);
                    rectangle(1260, 290 + x, 1340,  320 + x);
                    CENTER(a,b, DATVE, 1260, 290 + x, 1340, 320 + x);
                    outtextxy(a, b, DATVE);
                } else {
                    setfillstyle(SOLID_FILL, LIGHTYELLOW);
                    setbkcolor(LIGHTYELLOW);
                    setcolor(BLACK);
                    bar(1260, 290 + x, 1340,  320 + x);
                    rectangle(1260, 290 + x, 1340,  320 + x);
                    CENTER(a,b, DATVE, 1260, 290 + x, 1340, 320 + x);
                    outtextxy(a, b, DATVE);
                }

                setfillstyle(SOLID_FILL, LIGHTRED);
                setbkcolor(LIGHTRED);
                setcolor(BLACK);
                bar(1360, 290 + x, 1440,  320 + x);
                rectangle(1360, 290 + x, 1440,  320 + x);
                CENTER(a,b, HUYVE, 1360, 290 + x, 1440, 320 + x);
                outtextxy(a, b, HUYVE);
            } else {
                setfillstyle(SOLID_FILL, LIGHTGRAY);
                setbkcolor(LIGHTGRAY);
                setcolor(WHITE);
                bar(1260, 290 + x, 1340,  320 + x);
                rectangle(1260, 290 + x, 1340,  320 + x);
                CENTER(a,b, DATVE, 1260, 290 + x, 1340, 320 + x);
                outtextxy(a, b, DATVE);
                bar(1360, 290 + x, 1440,  320 + x);
                rectangle(1360, 290 + x, 1440,  320 + x);
                CENTER(a,b, HUYVE, 1360, 290 + x, 1440, 320 + x);
                outtextxy(a, b, HUYVE);      
            }
            x = x + 50;
            dem = dem + 1;
        }
    }
}
// khung in ds chuyen bay
void khungindsCB() {
    char text17[] = "MA CB";
    char text18[] = "NOI DI";
    char text19[] = "NOI DEN";
    char text20[] = "THOI GIAN";
    char text21[] = "VE";
    char text22[] = "TRANG THAI";
    char MAYBAY[] = "MAY BAY";
    char THEM[] = "ADD";
    char SAVE[] = "SAVE";
    int a, b;
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    setcolor(BLACK);
    rectangle(20,160, 1480, 740);
    bar(21, 161, 1479, 739);

    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar (40,180,1460,230);

    setcolor(BLACK);
    rectangle(40,180, 1460, 680);

    int k = 0;
    for (int i = 0; i < 10 ; i++) {
        line(40,180 + k,1460, 180 + k);
        k = k + 50;
    }
    settextstyle(BOLD_FONT, HORIZ_DIR, 1);
    setcolor(WHITE);
    setbkcolor(LIGHTBLUE);

    CENTER(a,b, text17, 40, 180, 130, 230);
    outtextxy(a, b, text17);

    CENTER(a,b, text18, 130, 180, 310, 230);
    outtextxy(a, b, text18);

    CENTER(a,b, text19, 310, 180, 490, 230);
    outtextxy(a, b, text19);

    CENTER(a,b, text20, 490, 180, 670, 230);
    outtextxy(a, b, text20);

    CENTER(a,b, text21, 670, 180, 740, 230);
    outtextxy(a, b, text21);

    CENTER(a,b, text22, 740, 180, 920, 230);
    outtextxy(a, b, text22);

    CENTER(a,b, MAYBAY, 920, 180, 1010, 230);
    outtextxy(a, b, MAYBAY);
    
    settextstyle(BOLD_FONT, HORIZ_DIR, 1);
    setfillstyle(SOLID_FILL, LIGHTGRAY);

    setcolor(BLACK);
    setbkcolor(LIGHTGRAY);
     // ve nut them 
    rectangle(40, 700, 190, 730);
    CENTER(a,b, THEM, 40, 700, 190, 730);
    outtextxy(a, b, THEM);
}
// them chuyen bay moi
void themChuyenBay(DSMB& dsMB, NODECBPTR &First, CB cb, tm *tm_now, TIME time_xp){
    char TD[] = "THEM CHUYEN BAY MOI";
    char MACB[] = "MA CB";
    char NOIDI[] = "NOI DI";
    char NOIDEN[] = "NOI DEN";
    char THOIGIAN[] = "THOI GIAN";
    char SOHIEU[] = "SO HIEU";
    char ESC[] = "ESC";
    char SAVE[] = "SAVE";

    int a, b;

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    setcolor(BLACK);
    rectangle(20,160, 1480, 740);
    bar(21, 161, 1479, 739);


    setcolor(BLACK);
    rectangle(40,180, 1460, 680);

    setcolor(BLACK);
    setbkcolor(LIGHTGRAY);
    CENTER(a, b, TD, 40,200, 1460, 230);
    outtextxy(a, b, TD);
    outtextxy(300, 280, MACB);
    outtextxy(300, 380, NOIDI);
    outtextxy(830, 380, NOIDEN);
    outtextxy(300, 480, THOIGIAN);
    outtextxy(300, 580, SOHIEU);
    setfillstyle(SOLID_FILL, WHITE);
    rectangle(500, 260, 900, 310);//macb
    rectangle(500, 360, 800, 410);//ndi
    rectangle(1030,360, 1330, 410);//nden
    rectangle(500, 460, 650, 510);//ngay
    rectangle(670, 460, 820, 510);//thang
    rectangle(840, 460, 990, 510);//nam
    rectangle(1010, 460, 1160, 510);//gio
    rectangle(1180, 460, 1330, 510);//phut
    //rectangle(500,360, 900, 410);
    rectangle(500,560, 900, 610);//sohieumb


    //esc
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, LIGHTRED);
    setbkcolor(LIGHTRED);
    bar(60,200, 130, 250);
    rectangle(60,200, 130, 250);
    CENTER(a, b, ESC, 60, 200, 130,250);
    outtextxy(a, b, ESC);
    
    // save
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    setcolor(BLACK);
    setbkcolor(LIGHTGRAY);
    rectangle(1350, 610, 1440, 660);
    CENTER(a, b, SAVE, 1350, 610, 1440, 660);
    outtextxy(a, b, SAVE);


    char maCB[17] = "";
    char noiDi[17] = "";
    char noiDen[17] = "";
    char soHieuMB[17] = "";
    char ngay[3] = "";
    char thang[3] = "";
    char nam[5] = "";
    char gio[3] = "";
    char phut[3] = "";
    
    char trong[] ="";

    int chiso;

    bool testmaCB = false;
    bool testnoiDi = false;
    bool testnoiDen = false;
    bool testNgay = false;
    bool testThang = false;
    bool testNam = false; 
    bool testGio = false;
    bool testPhut = false;
    bool testSoHieuMB = false;

    while(true){
        int x = mousex();
        int y = mousey();

        while(!ismouseclick(WM_LBUTTONDOWN)){
            delay(100);
        }

        getmouseclick(WM_LBUTTONDOWN, x, y);
        if (y >= 260 && y <= 310 && x >= 500 && x <= 900){
            setfillstyle(SOLID_FILL, LIGHTGRAY);
            bar(500, 315, 1100, 340);
            khungText(500, 260, 900, 310, 16, SoVaChu, MACB, maCB, x, y);
            if (strcmp (maCB, trong) != 0){
                if (check_CB(First, maCB) == NULL){
                    strcpy(cb.maCB, maCB);
                    testmaCB = true;
                } else {
                    char tb[] = "*Ma chuyen bay da ton tai!";
                    setfillstyle(1, 7);
                    bar(500, 260+ 60, 900+ 70, 310+10);
                    outtextxy(500+10, 260+60, tb);
                    testmaCB = false;
                }
            } else testmaCB = false;
        }
        else if (y >= 360 && y <= 410 && x >= 500 && x <= 800){
            khungText(500, 360, 800, 410, 16, ChuNormal, NOIDI, noiDi, x, y);
            if (strcmp(noiDi, trong) != 0){
                strcpy(cb.noiDi, noiDi);
                testnoiDi = true;
            } else testnoiDi = false;
        }
        else if (y >= 360 && y <= 410 && x >= 1030 && x <= 1330){
            khungText(1030, 360, 1330, 410, 16, ChuNormal, NOIDEN, noiDen, x, y);
            if (strcmp(noiDen, trong) != 0){
                strcpy(cb.noiDen, noiDen);
                testnoiDen = true;
            } else testnoiDen = false;
            
        }
        else if (y >= 460 && y <= 510 && x >= 500 && x <= 990){
            bar(500, 515, 990,540);
            testNam = false;
            testThang = false;
            testNgay = false;
            if (tm_now->tm_mday >= 3 && tm_now->tm_mon + 1== 12){
                khungText(500, 460, 650, 510, 4, So, trong, nam, x, y);
                if (strcmp(nam, trong) != 0 && checkNam(nam, tm_now, 1) == true){
                    testNam = true;
                }
                while (testNam == false){
                    char tb[] = "*Nam khong hop le";
                    setfillstyle(1,7);
                    bar (500, 460+60, 650+100, 510+10);
                    outtextxy(500+10, 460+60, tb);
                    khungText(500, 460, 650, 510, 4, So, trong, nam, x, y);
                    if (strcmp(nam, trong) != 0 && checkNam(nam, tm_now, 1) == true){
                    testNam = true;
                }
                }
                setfillstyle(1,7);
                bar (500, 460+60, 650+100, 510+10);
                khungText(670, 460, 820, 510, 2, So, trong, thang, x, y);
                if (strcmp(thang, trong) != 0 && checkThang(thang, nam, tm_now, 1)){
                    testThang = true;
                }
                while(testThang == false){
                    char tb[] = "*Thang khong hop le";
                    setfillstyle(1,7);
                    bar (670, 460+60, 820+100, 510+10);
                    outtextxy(670+10, 460+60, tb);
                    khungText(670, 460, 820, 510, 2, So, trong, thang, x, y);
                    if (strcmp(thang, trong) != 0 && checkThang(thang, nam, tm_now, 1)== true){
                    testThang = true;
                }
                }
                setfillstyle(1,7);
                bar (670, 460+60, 820+100, 510+10);
                khungText(840, 460, 990, 510, 2, So, trong, ngay, x, y);
                if (strcmp(ngay, trong) != 0 && checkNgay(nam, thang, ngay, tm_now, 1)== true){
                    testNgay = true;
                }
                while(testNgay == false){
                    char tb[] = "*Ngay khong hop le";
                    setfillstyle(1,7);
                    bar (840, 460+60, 990+100, 510+10);
                    outtextxy(840+10, 460+60, tb);
                    khungText(840, 460, 990, 510, 2, So, trong, ngay, x, y);
                    if (strcmp(ngay, trong) != 0 && checkNgay(nam, thang, ngay, tm_now, 1)== true){
                        testNgay = true;
                }
                }
                setfillstyle(1,7);
                bar (840, 460+60, 990+100, 510+10);
            } else if ((tm_now->tm_mon + 1 < 12) || (tm_now->tm_mday < 3 && tm_now->tm_mon + 1 == 12)){
                khungText(500, 460, 650, 510, 4, So, trong, nam, x, y);
                if (strcmp(nam, trong) != 0 && checkNam(nam, tm_now, 2) == true){
                    testNam = true;
                }
                while (testNam == false){
                    char tb[] = "*Nam khong hop le";
                    setfillstyle(1,7);
                    bar (500, 460+60, 650+100, 510+10);
                    outtextxy(500+10, 460+60, tb);
                    khungText(500, 460, 650, 510, 4, So, trong, nam, x, y);
                    if (strcmp(nam, trong) != 0 && checkNam(nam, tm_now, 2) == true){
                        testNam = true;
                    }
                }
                setfillstyle(1,7);
                bar (500, 460+60, 650+100, 510+10);
                khungText(670, 460, 820, 510, 2, So, trong, thang, x, y);
                if (strcmp(thang, trong) != 0 && checkThang(thang, nam, tm_now, 2)){
                    testThang = true;
                }
                while(testThang == false){
                    char tb[] = "*Thang khong hop le";
                    setfillstyle(1,7);
                    bar (670, 460+60, 820+100, 510+10);
                    outtextxy(670+10, 460+60, tb);
                    khungText(670, 460, 820, 510, 2, So, trong, thang, x, y);
                    if (strcmp(thang, trong) != 0 && checkThang(thang, nam, tm_now, 2)== true){
                        testThang = true;
                    }
                }
                setfillstyle(1,7);
                bar (670, 460+60, 820+100, 510+10);
                khungText(840, 460, 990, 510, 2, So, trong, ngay, x, y);
                if (strcmp(ngay, trong) != 0 && checkNgay(nam, thang, ngay, tm_now, 2)== true){
                    testNgay = true;
                }
                while(testNgay == false){
                    char tb[] = "*Ngay khong hop le";
                    setfillstyle(1,7);
                    bar (840, 460+60, 990+100, 510+10);
                    outtextxy(840+10, 460+60, tb);
                    khungText(840, 460, 990, 510, 2, So, trong, ngay, x, y);
                    if (strcmp(ngay, trong) != 0 && checkNgay(nam, thang, ngay, tm_now, 2)== true){
                        testNgay = true;
                    }
                }
                setfillstyle(1,7);
                bar (840, 460+60, 990+100, 510+10);
            }
            cb.time_xp.nam = stoi(nam);
            cb.time_xp.thang = stoi(thang);
            cb.time_xp.ngay = stoi(ngay);
        }
        else if (y >= 460 && y <= 510 && x >= 1010 && x <= 1330){
            bar(500, 515, 990,540);
            do {
                testGio = false;
                testPhut = false;
                khungText(1010, 460, 1160, 510, 2, So, trong, gio, x, y);
                    if (strcmp(gio, trong) != 0 && (stoi(gio) > 3 && stoi(gio) <= 23)){
                        testGio = true;
                    } 
                    if (testGio == false){
                        char tb[] = "*Gio khong hop le";
                        setfillstyle(1,7);
                        bar (1010, 460 + 60, 1330, 510 + 10);
                        outtextxy(1010+10, 460+60, tb);
                    } else {
                        khungText(1180, 460, 1330, 510, 2, So, trong, phut, x, y);
                        if (strcmp(phut, trong) != 0 && (stoi(phut) >= 0 && stoi(phut) <= 59)){
                            if (checkGio(cb, gio, phut, tm_now) == true){
                                testPhut = true;
                            } else {
                                testPhut= false;
                                char tb[] = "*Khong hop le";
                                setfillstyle(1,7);
                                bar (1010, 460+60, 1330, +510+10);
                                outtextxy(1010+10, 460+60, tb);
                            }
                        } else {
                            testPhut = false;
                            while (testPhut == false && testGio == true){
                                char tb[] = "*Phut khong hop le";
                                setfillstyle(1,7);
                                bar (1180, 460 + 60, 1330, 510 + 10);
                                outtextxy(1180 + 10, 460 + 60, tb);
                                khungText(1180, 460, 1330, 510, 2, So, trong, phut, x, y);
                                if (strcmp(phut, trong) != 0 && (stoi(phut) >= 0 && stoi(phut) <= 59)){
                                    if (checkGio(cb, gio, phut, tm_now) == true){
                                        testPhut = true;
                                    } else {
                                        testPhut = false;
                                        testGio = false;
                                        char tb[] = "*Khong hop le";
                                        setfillstyle(1,7);
                                        bar (1010, 460 + 60, 1330, 510+10);
                                        outtextxy(1010 + 10, 460 + 60, tb);
                                    }
                                }
                            }
                        }
                    }
            } while (testGio == false || testPhut == false);
            cb.time_xp.gio = stoi(gio);
            cb.time_xp.phut = stoi(phut);
        }
        else if (y >= 560 && y <= 610 && x >= 500 && x <= 900){
            setfillstyle(1, 7);
            bar(500, 560+60, 1330, 610+47);
            khungText(500, 560, 900, 610, 16, SoVaChu, SOHIEU, soHieuMB, x, y);
            if ((strcmp(soHieuMB, trong) != 0)){
                strcpy(cb.soHieuMB, soHieuMB);
                if (checkMB(dsMB, cb.soHieuMB, chiso) == true){
                    if (checkPlane(First, cb.soHieuMB, cb.time_xp) == true){
                        testSoHieuMB = true;
                        setfillstyle(1, 7);
                        bar(500, 560+60, 900+70, 610+47);
                    } else {
                        setbkcolor(LIGHTGRAY);
                        char tb[] = "*May bay dang hoat dong";
                        setfillstyle(1, 7);
                        bar(500, 560+60, 900+70, 610+47);
                        outtextxy(500+10, 560+60, tb);
                        testSoHieuMB = false;
                    } 
                } else {
                    setbkcolor(LIGHTGRAY);
                    char tb[] = "*So hieu MB khong ton tai";
                    setfillstyle(1, 7);
                    bar(500, 560+60, 900+70, 610+47);
                    outtextxy(500+10, 560+60, tb);
                    testSoHieuMB = false;
                }  
            } else testSoHieuMB = false;
        }
        else if ((y >= 610 && y <= 660 && x >= 1350 && x <= 1440) && (testmaCB == true && testnoiDen == true && testnoiDi == true && testNgay == true && testThang == true && testNam == true && testGio == true && testPhut == true && testSoHieuMB == true)) {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            if (checkGio(cb, gio, phut, tm_now) == true && checkPlane(First, cb.soHieuMB, cb.time_xp)== true ){
                cb.soLuongVe = dsMB.data[chiso]->soChoNgoi;
                createTickets(dsMB, cb, chiso);
                addCB_Order(First, cb);
            break;
            }
            if (checkGio(cb, gio, phut, tm_now) == false) {
                char tb[] = "*Phai cach thoi gian thuc it nhat 2 tieng";
                setfillstyle(1, 7);
                bar(500, 515, 990,540);
                CENTER(a,b, tb, 500, 515, 990,540);
                outtextxy(a, b, tb);
            }
            if (checkPlane(First, cb.soHieuMB, cb.time_xp) == false) {
                char tb[] = "*MB dang hoat dong. Nhap so hieu khac";
                setfillstyle(1, 7);
                bar(500, 615, 1200, 640);
                outtextxy(500, 620, tb);
            }
        } 
        else if ((y >= 100 && y <= 150 && x >= 395 && x <= 730) || (y >= 100 && y <= 150 && x >= 770 && x <= 1105) || 
                (y >= 100 && y <= 150 && x >= 1145 && x <= 1480) || (y >= 200 && y <= 250 && x >= 60 && x <= 130)) {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            break;
        }

    }
}
// hieu chinh chuyen bay
void hieuChinhCB(NODECBPTR First, DSMB& dsMB, NODECBPTR& q, CB cb, tm *tm_now, TIME time_xp){
    char TD[] = "THEM CHUYEN BAY MOI";
    char MACB[] = "MA CB";
    char NOIDI[] = "NOI DI";
    char NOIDEN[] = "NOI DEN";
    char THOIGIAN[] = "THOI GIAN";
    char SOHIEU[] = "SO HIEU";
    char ESC[] = "ESC";
    char SAVE[] = "SAVE";

    int a, b;

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    setcolor(BLACK);
    rectangle(20,160, 1480, 740);
    bar(21, 161, 1479, 739);


    setcolor(BLACK);
    rectangle(40,180, 1460, 680);

    setcolor(BLACK);
    setbkcolor(LIGHTGRAY);
    CENTER(a, b, TD, 40,200, 1460, 230);
    outtextxy(a, b, TD);
    outtextxy(300, 280, MACB);
    outtextxy(300, 380, NOIDI);
    outtextxy(830, 380, NOIDEN);
    outtextxy(300, 480, THOIGIAN);
    outtextxy(300, 580, SOHIEU);
    setfillstyle(SOLID_FILL, WHITE);
    rectangle(500, 260, 900, 310);//macb
    rectangle(500, 360, 800, 410);//ndi
    rectangle(1030,360, 1330, 410);//nden
    rectangle(500, 460, 650, 510);//ngay
    rectangle(670, 460, 820, 510);//thang
    rectangle(840, 460, 990, 510);//nam
    rectangle(1010, 460, 1160, 510);//gio
    rectangle(1180, 460, 1330, 510);//phut
    //rectangle(500,360, 900, 410);
    rectangle(500,560, 900, 610);//sohieumb

    //vÃ¡ÂºÂ½ nÄ‚Âºt nhÃ¡ÂºÂ¥n esc
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, LIGHTRED);
    setbkcolor(LIGHTRED);
    bar(60,200, 130, 250);
    rectangle(60,200, 130, 250);
    CENTER(a, b, ESC, 60, 200, 130,250);
    outtextxy(a, b, ESC);
    
    // vÃ¡ÂºÂ½ nÄ‚Âºt nhÃ¡ÂºÂ¥n save
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    setcolor(BLACK);
    setbkcolor(LIGHTGRAY);
    rectangle(1350,610, 1440, 660);
    CENTER(a, b, SAVE, 1350,610, 1440, 660);
    outtextxy(a, b, SAVE);


    char maCB[17] = "";
    char noiDi[17] = "";
    char noiDen[17] = "";
    char soHieuMB[17] = "";
    char ngay[3] = "";
    char thang[3] = "";
    char nam[5] = "";
    char gio[3] = "";
    char phut[3] = "";
    
    char trong[] ="";

    int chiso;

    bool testNgay = true;
    bool testThang = true;
    bool testNam = true; 
    bool testGio = true;
    bool testPhut = true;

    outtextxy(500+10, 260+10, q->cb.maCB);
    outtextxy(500+10, 360+10, q->cb.noiDi);
    outtextxy(1030+10, 360+10, q->cb.noiDen);
    sprintf(nam, "%d%", q->cb.time_xp.nam);
    outtextxy(500+10, 460+10, nam);
    sprintf(thang, "%d%", q->cb.time_xp.thang);
    outtextxy(670+10, 460+10, thang);
    sprintf(ngay, "%d%", q->cb.time_xp.ngay);
    outtextxy(840+10, 460+10, ngay);
    sprintf(gio, "%d%", q->cb.time_xp.gio);
    outtextxy(1010+10, 460+10, gio);
    sprintf(phut, "%d%", q->cb.time_xp.phut);
    outtextxy(1180+10, 460+10, phut);
    outtextxy(500+10, 560+10, q->cb.soHieuMB);

    while(true){
        int x = mousex();
        int y = mousey();
        while(!ismouseclick(WM_LBUTTONDOWN)){
            delay(100);
        }

        getmouseclick(WM_LBUTTONDOWN, x, y);
        if (y >= 460 && y <= 510 && x >= 500 && x <= 990){
            testNam = false;
            testThang = false;
            testNgay = false;
            if (tm_now->tm_mday >= 3 && tm_now->tm_mon + 1== 12){
                khungText(500, 460, 650, 510, 4, So, trong, nam, x, y);
                if (strcmp(nam, trong) != 0 && checkNam(nam, tm_now, 1) == true){
                    testNam = true;
                }
                while (testNam == false){
                    char tb[] = "*Nam khong hop le";
                    setfillstyle(1,7);
                    bar (500, 460+60, 650+100, +510+10);
                    outtextxy(500+10, 460+60, tb);
                    khungText(500, 460, 650, 510, 4, So, trong, nam, x, y);
                    if (strcmp(nam, trong) != 0 && checkNam(nam, tm_now, 1) == true){
                    testNam = true;
                }
                }
                setfillstyle(1,7);
                bar (500, 460+60, 650+100, 510+10);
                khungText(670, 460, 820, 510, 2, So, trong, thang, x, y);
                if (strcmp(thang, trong) != 0 && checkThang(thang, nam, tm_now, 1)){
                    testThang = true;
                }
                while(testThang == false){
                    char tb[] = "*Thang khong hop le";
                    setfillstyle(1,7);
                    bar (670, 460+60, 820+100, +510+10);
                    outtextxy(670+10, 460+60, tb);
                    khungText(670, 460, 820, 510, 2, So, trong, thang, x, y);
                    if (strcmp(thang, trong) != 0 && checkThang(thang, nam, tm_now, 1)== true){
                    testThang = true;
                }
                }
                setfillstyle(1,7);
                bar (670, 460+60, 820+100, 510+10);
                khungText(840, 460, 990, 510, 2, So, trong, ngay, x, y);
                if (strcmp(ngay, trong) != 0 && checkNgay(nam, thang, ngay, tm_now, 1)== true){
                    testNgay = true;
                }
                while(testNgay == false){
                    char tb[] = "*Ngay khong hop le";
                    setfillstyle(1,7);
                    bar (840, 460+60, 990+100, 510+10);
                    outtextxy(840+10, 460+60, tb);
                    khungText(840, 460, 990, 510, 2, So, trong, ngay, x, y);
                    if (strcmp(ngay, trong) != 0 && checkNgay(nam, thang, ngay, tm_now, 1)== true){
                        testNgay = true;
                }
                }
                setfillstyle(1,7);
                bar (840, 460+60, 990+100, +510+10);
            } else if ((tm_now->tm_mon + 1 < 12) || (tm_now->tm_mday < 3 && tm_now->tm_mon + 1 == 12)){
                khungText(500, 460, 650, 510, 4, So, trong, nam, x, y);
                if (strcmp(nam, trong) != 0 && checkNam(nam, tm_now, 2) == true){
                    testNam = true;
                }
                while (testNam == false){
                    char tb[] = "*Nam khong hop le";
                    setfillstyle(1,7);
                    bar (500, 460+60, 650+100, +510+10);
                    outtextxy(500+10, 460+60, tb);
                    khungText(500, 460, 650, 510, 4, So, trong, nam, x, y);
                    if (strcmp(nam, trong) != 0 && checkNam(nam, tm_now, 2) == true){
                        testNam = true;
                    }
                }
                setfillstyle(1,7);
                bar (500, 460+60, 650+100, 510+10);
                khungText(670, 460, 820, 510, 2, So, trong, thang, x, y);
                if (strcmp(thang, trong) != 0 && checkThang(thang, nam, tm_now, 2)){
                    testThang = true;
                }
                while(testThang == false){
                    char tb[] = "*Thang khong hop le";
                    setfillstyle(1,7);
                    bar (670, 460+60, 820+100, +510+10);
                    outtextxy(670+10, 460+60, tb);
                    khungText(670, 460, 820, 510, 2, So, trong, thang, x, y);
                    if (strcmp(thang, trong) != 0 && checkThang(thang, nam, tm_now, 2)== true){
                        testThang = true;
                    }
                }
                setfillstyle(1,7);
                bar (670, 460+60, 820+100, +510+10);
                khungText(840, 460, 990, 510, 2, So, trong, ngay, x, y);
                if (strcmp(ngay, trong) != 0 && checkNgay(nam, thang, ngay, tm_now, 2)== true){
                    testNgay = true;
                }
                while(testNgay == false){
                    char tb[] = "*Ngay khong hop le";
                    setfillstyle(1,7);
                    bar (840, 460+60, 990+100, 510+10);
                    outtextxy(840+10, 460+60, tb);
                    khungText(840, 460, 990, 510, 2, So, trong, ngay, x, y);
                    if (strcmp(ngay, trong) != 0 && checkNgay(nam, thang, ngay, tm_now, 2)== true){
                        testNgay = true;
                    }
                }
                setfillstyle(1,7);
                bar (840, 460+60, 990+100, 510+10);
            }
        }
        else if (y >= 460 && y <= 510 && x >= 1010 && x <= 1330){
            do {
                testGio = false;
                testPhut = false;
                khungText(1010, 460, 1160, 510, 2, So, trong, gio, x, y);
                    if (strcmp(gio, trong) != 0 && (stoi(gio) > 3 && stoi(gio) <= 23)){
                        testGio = true;
                    } 
                    if (testGio == false){
                        char tb[] = "*Gio khong hop le";
                        setfillstyle(1,7);
                        bar (1010, 460+60, 1330, 510+10);
                        outtextxy(1010+10, 460+60, tb);
                    } else {
                        khungText(1180, 460, 1330, 510, 2, So, trong, phut, x, y);
                        if (strcmp(phut, trong) != 0 && (stoi(phut) >= 0 && stoi(phut) <= 59)){
                            if (checkGio(cb, gio, phut, tm_now) == true){
                                testPhut = true;
                            } else {
                                testPhut= false;
                                char tb[] = "*Khong hop le";
                                setfillstyle(1,7);
                                bar (1010, 460+60, 1330, +510+10);
                                outtextxy(1010+10, 460+60, tb);
                            }
                        } else {
                            testPhut = false;
                            while (testPhut == false && testGio == true){
                                char tb[] = "*Phut khong hop le";
                                setfillstyle(1,7);
                                bar (1180, 460+60, 1330, +510+10);
                                outtextxy(1180+10, 460+60, tb);
                                khungText(1180, 460, 1330, 510, 2, So, trong, phut, x, y);
                                if (strcmp(phut, trong) != 0 && (stoi(phut) >= 0 && stoi(phut) <= 59)){
                                    if (checkGio(cb, gio, phut, tm_now) == true){
                                        testPhut = true;
                                    } else {
                                        testPhut = false;
                                        testGio = false;
                                        char tb[] = "*Khong hop le";
                                        setfillstyle(1,7);
                                        bar (1010, 460+60, 1330, +510+10);
                                        outtextxy(1010+10, 460+60, tb);
                                    }
                                }
                            }
                        }
                    }
            } while (testGio == false || testPhut == false);
        }
        else if ((y >= 610 && y <= 660 && x >= 1350 && x <= 1440) && (testNgay == true && testThang == true && testNam == true && testGio == true && testPhut == true )) {
            strcpy(cb.maCB, q->cb.maCB);
            strcpy(cb.soHieuMB,  q->cb.soHieuMB);
            cb.time_xp.nam = stoi(nam);
            cb.time_xp.thang = stoi(thang);
            cb.time_xp.ngay = stoi(ngay);
            cb.time_xp.gio = stoi(gio);
            cb.time_xp.phut = stoi(phut);
            if (checkPlaneHC(First,cb) == false) {
                char tb[] = "*MB dang co chuyen bay trong thoi gian nay. Nhap thoi gian khac!";
                setfillstyle(1, 7);
                bar(500, 615, 1200, 640);
                outtextxy(500, 620, tb);
            } else {
                if (checkGio(cb, gio, phut, tm_now) == true){
                    setfillstyle(1, 7);
                    bar(870, b + 60, 1330, b + 97);
                    updateCB(q, cb);
                    break;
                } else {
                    char tb[] = "*Phai cach thoi gian thuc it nhat 2 tieng";
                    setfillstyle(1, 7);
                    bar(870, b+60, 1330, b+97);
                    outtextxy(870+10, b, tb);
                }
            }
        }
        else if ((y >= 100 && y <= 150 && x >= 395 && x <= 730) || (y >= 100 && y <= 150 && x >= 770 && x <= 1105) || 
                (y >= 100 && y <= 150 && x >= 1145 && x <= 1480) || (y >= 200 && y <= 250 && x >= 60 && x <= 130)) {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            break;
        }

    }
}
// khung in danh sach khach hang trong chuyen bay
void khungindsKHonCB (NODECBPTR q){
    char text23[65] = "DANH SACH KHACH HANG THUOC CHUYEN BAY ";
    char text24[120] = "Ngay gio khoi hanh: ";
    char text25[30] = "Noi den: ";
    char text26[] = "STT";
    char text27[] = "SO VE";
    char text28[] = "SO CMND";
    char text29[] = "HO TEN";
    char text30[] = "PHAI";
    char ESC[] = "ESC";
    int a, b;

    strcat(text23, q->cb.maCB);

    char c[6];
    sprintf(c, "%d", q->cb.time_xp.ngay);
    strcat(text24, c);
    strcat(text24, "/");

    sprintf(c, "%d", q->cb.time_xp.thang);
    strcat(text24, c);
    strcat(text24, "/");

    sprintf(c, "%d", q->cb.time_xp.nam);
    strcat(text24, c);
    strcat(text24, "  ");

    sprintf(c, "%d", q->cb.time_xp.gio);
    strcat(text24, c);
    strcat(text24, ":");

    sprintf(c, "%d", q->cb.time_xp.phut);
    strcat(text24, c);
    strcat(text24, ". ");

    strcat(text25, q->cb.noiDen);

    strcat(text24, text25);


    setfillstyle(SOLID_FILL, LIGHTGRAY);
    setcolor(BLACK);
    rectangle(20,160, 1480, 740);
    bar(21, 161, 1479, 739);

    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar(40,280,1460,330);

    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    setcolor(WHITE);
    setbkcolor(LIGHTBLUE);

    CENTER(a,b, text26, 100, 280, 200, 330);
    outtextxy(a, b, text26);

    CENTER(a,b, text27, 200, 280, 350, 330);
    outtextxy(a, b, text27);

    CENTER(a,b, text28, 350, 280, 750, 330);
    outtextxy(a, b, text28);

    outtextxy(750, 295, text29);

    CENTER(a,b, text30, 1050, 280, 1350, 330);
    outtextxy(a, b, text30);

    setbkcolor(LIGHTGRAY);
    setcolor(BLACK);
    rectangle(40,280, 1460, 680);

    int k = 0;
    for (int i = 0; i <= 7 ; i++) {
        line(40,280 + k,1460, 280 + k);
        k = k + 50;
    }

    settextstyle(BOLD_FONT, HORIZ_DIR, 3);
    setcolor(BLACK);
    setbkcolor(LIGHTGRAY);

    CENTER(a,b, text23, 40, 180, 1460, 230);
    outtextxy(a, b, text23);

    CENTER(a,b, text24, 40, 230, 1460, 280);
    outtextxy(a, b, text24);

    setcolor(BLACK);
    setfillstyle(SOLID_FILL, LIGHTRED);
    setbkcolor(LIGHTRED);
    bar(60,200, 130, 250);
    rectangle(60,200, 130, 250);
    CENTER(a, b, ESC, 60, 200, 130,250);
    outtextxy(a, b, ESC);
}
// in khach hang
void inKH(NODECBPTR q, TREE root, int trang) {
    int a, b;
    int dau = 7 * (trang - 1);
    int cuoi = dau + 7;
    int x = 50;
    int i;
    for (i = 0; i < dau; i++);
    for (i = dau; i < q->cb.soLuongVe ; i++) {
        if (q->cb.ve[i]->ttVe == DA_DAT) {
            if (dau < cuoi && dau < q->cb.soLuongDatVe) {
                TREE p = timKiemKH(root, q->cb.ve[i]->CMND);
                settextstyle(BOLD_FONT, HORIZ_DIR, 1);
                setcolor(WHITE);
                setbkcolor(LIGHTGRAY);
                char stt[4];
                sprintf(stt, "%d", dau + 1);
                CENTER(a,b, stt, 100, 280 + x, 200, 330 + x);
                outtextxy(a, b, stt);

                CENTER(a,b, q->cb.ve[i]->Ghe_so, 200, 280 + x, 350, 330 + x);
                outtextxy(a, b, q->cb.ve[i]->Ghe_so);

                CENTER(a,b, q->cb.ve[i]->CMND, 350, 280 + x, 750, 330 + x);
                outtextxy(a, b, q->cb.ve[i]->CMND);

                char HoTen[45];
                strcpy(HoTen, p->data.Ho);
                strcat(HoTen, " ");
                strcat(HoTen, p->data.Ten);
                outtextxy(740, 295 + x, HoTen);

                if (p->data.gioiTinh == true) {
                    char Nam[] = "Nam";
                    CENTER(a,b, Nam, 1050, 280 + x, 1350, 330 + x);
                    outtextxy(a, b, Nam);
                } else {
                    char Nu[] = "Nu";
                    CENTER(a,b, Nu, 1050, 280 + x, 1350, 330 + x);
                    outtextxy(a, b, Nu);
                }
            }
            dau++;
            x += 50;
        }
    }
}
//in khach hang trong chuyen bay
void indsKHonCB(NODECBPTR q, TREE root) {
    int itemsPerPage = 7;
    int currentPage = 1;
    while(true) {
        // Tổng số trang
        int numPages;
        if (q->cb.soLuongDatVe + 1 % itemsPerPage != 0 )
        {
            numPages = q->cb.soLuongDatVe / itemsPerPage + 1;
        } else {
            numPages = q->cb.soLuongDatVe / itemsPerPage;
        }
        int a, b;
        khungindsKHonCB(q);
        inKH(q, root, currentPage);
        setcolor(BLACK);
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        setbkcolor(LIGHTGRAY);
        char stt[4];
        sprintf(stt, "%d", currentPage);
        rectangle(1250, 700, 1300, 730);
        CENTER(a, b, stt, 1250, 700, 1300, 730);
        outtextxy(a,b, stt);

        // Vẽ nút điều hướng
        if (currentPage > 1) {
            char trai[] = "<";
            rectangle(1200, 700, 1250, 730);
            CENTER(a, b, trai, 1200, 700, 1250, 730);
            outtextxy(a, b, trai);
        }
        if (currentPage < numPages) {
            char phai[] = ">";
            rectangle(1300, 700, 1350, 730);
            CENTER(a, b, phai, 1300, 700, 1350, 730);
            outtextxy(a, b, phai);
        }   

        int x = mousex();
        int y = mousey();
        while (!ismouseclick(WM_LBUTTONDOWN)) {
            delay(100);
        }
        getmouseclick(WM_LBUTTONDOWN, x, y);
        if (x >= 1200 && x <= 1250 && y >= 700 && y <= 750 && currentPage > 1) {
            currentPage--;
        } else if (x >= 1300 && x <= 1350 && y >= 700 && y <= 750 && currentPage < numPages) {
            currentPage++;
        } 
        else if ((y >= 200 && y <= 250 && x >= 60 && x <= 130)) {
            break;
        }
    }
}
// khung in dach sach chuyen bay trong phan tim kiem 
void khungindsCB2 () {
    settextstyle(BOLD_FONT, HORIZ_DIR, 1);
    char text17[] = "MA CB";
    char text18[] = "NOI DI";
    char text19[] = "NOI DEN";
    char text20[] = "THOI GIAN";
    char text21[] = "VE";
    char text22[] = "TRANG THAI";
    char MAYBAY[] = "MAY BAY";
    char text31[] = "NGAY DI";
    char SEARCH[] = "SEARCH";
    int a, b;
    int x, y;

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(21, 161, 1479, 739);

    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar(40,280,1460,330);
    setcolor(BLACK);
    rectangle(40,280, 1460, 680);
    int k = 0;
    for (int i = 0; i <= 7 ; i++) {
        
        line(40,280 + k,1460, 280 + k);
        k = k + 50;
    }
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    setcolor(BLACK);
    setbkcolor(LIGHTGRAY);

    rectangle(140, 180, 420, 230);
    outtextxy(40, 195, text18);

    rectangle(530, 180, 810, 230);
    outtextxy(440, 195, text19);

    outtextxy(830, 195, text20);

    rectangle(950, 180, 1030, 230);

    rectangle(1050, 180, 1100, 230);

    rectangle(1120, 180, 1170, 230);

    rectangle(1280, 180, 1440, 230);
    CENTER(a, b, SEARCH,1280, 180, 1440, 230);
    outtextxy(a, b, SEARCH);

    settextstyle(BOLD_FONT, HORIZ_DIR, 1);
    setcolor(BLACK);
    setbkcolor(LIGHTBLUE);

    CENTER(a,b, text17, 40, 280, 130, 330);
    outtextxy(a, b, text17);

    CENTER(a,b, text18, 130, 280, 380, 330);
    outtextxy(a, b, text18);

    CENTER(a,b, text19, 380, 280, 630, 330);
    outtextxy(a, b, text19);

    CENTER(a,b, text20, 630, 280, 880, 330);
    outtextxy(a, b, text20);

    CENTER(a,b, text21, 880, 280, 970, 330);
    outtextxy(a, b, text21);

    CENTER(a,b, text22, 970, 280, 1150, 330);
    outtextxy(a, b, text22);

    CENTER(a,b, MAYBAY, 1150, 280, 1240, 330);
    outtextxy(a, b, MAYBAY);
}
// khung in danh sach khach hang trong chuyen bay tim kiem đe huy ve khach hang
void khungindsKHonCB2 (NODECBPTR q){
    char text23[65] = "DANH SACH KHACH HANG THUOC CHUYEN BAY ";
    char text24[120] = "Ngay gio khoi hanh: ";
    char text25[30] = "Noi den: ";
    char text26[] = "STT";
    char text27[] = "SO VE";
    char text28[] = "SO CMND";
    char text29[] = "HO TEN";
    char text30[] = "PHAI";
    char HUYVE[] = "HUY VE";
    char ESC[] = "ESC";
    int a, b;

    strcat(text23, q->cb.maCB);

    char c[6];
    sprintf(c, "%d", q->cb.time_xp.ngay);
    strcat(text24, c);
    strcat(text24, "/");

    sprintf(c, "%d", q->cb.time_xp.thang);
    strcat(text24, c);
    strcat(text24, "/");

    sprintf(c, "%d", q->cb.time_xp.nam);
    strcat(text24, c);
    strcat(text24, "  ");

    sprintf(c, "%d", q->cb.time_xp.gio);
    strcat(text24, c);
    strcat(text24, ":");

    sprintf(c, "%d", q->cb.time_xp.phut);
    strcat(text24, c);
    strcat(text24, ". ");

    strcat(text25, q->cb.noiDen);

    strcat(text24, text25);


    setfillstyle(SOLID_FILL, LIGHTGRAY);
    setcolor(BLACK);
    rectangle(20,160, 1480, 740);
    bar(21, 161, 1479, 739);

    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar(40,280,1460,330);

    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    setcolor(WHITE);
    setbkcolor(LIGHTBLUE);

    CENTER(a,b, text26, 100, 280, 200, 330);
    outtextxy(a, b, text26);

    CENTER(a,b, text27, 200, 280, 350, 330);
    outtextxy(a, b, text27);

    CENTER(a,b, text28, 350, 280, 750, 330);
    outtextxy(a, b, text28);

    outtextxy(750, 295 , text29);

    CENTER(a,b, text30, 1050, 280, 1350, 330);
    outtextxy(a, b, text30);

    setbkcolor(LIGHTGRAY);
    setcolor(BLACK);
    rectangle(40,280, 1460, 680);

    int k = 0;
    for (int i = 0; i <= 7 ; i++) {
        line(40,280 + k,1460, 280 + k);
        k = k + 50;
    }

    settextstyle(BOLD_FONT, HORIZ_DIR, 3);
    setcolor(BLACK);
    setbkcolor(LIGHTGRAY);

    CENTER(a,b, text23, 40, 180, 1460, 230);
    outtextxy(a, b, text23);

    CENTER(a,b, text24, 40, 230, 1460, 280);
    outtextxy(a, b, text24);

    setcolor(BLACK);
    setfillstyle(SOLID_FILL, LIGHTRED);
    setbkcolor(LIGHTRED);
    bar(60,200, 130, 250);
    rectangle(60,200, 130, 250);
    CENTER(a, b, ESC, 60, 200, 130,250);
    outtextxy(a, b, ESC);
}
// in khach hang trong muc huy ve
void inKH2(NODECBPTR q, TREE root, int trang) {
    char HUYVE[] = "HUY VE";
    int a, b;
    int x = 50;
    int i = 0;
    int dem = 0;
    for (i; dem < (trang - 1) * 7 ; i++) {
        if (q->cb.ve[i]->ttVe == DA_DAT){
            dem++;
        }
    }
    dem = 0;
    for (i; i < q->cb.soLuongVe ; i++) {
        if (q->cb.ve[i]->ttVe == DA_DAT && dem < 7 && dem < q->cb.soLuongDatVe) {
            TREE p = timKiemKH(root, q->cb.ve[i]->CMND);
            settextstyle(BOLD_FONT, HORIZ_DIR, 1);
            setcolor(WHITE);
            setbkcolor(LIGHTGRAY);
            char stt[4];
            sprintf(stt, "%d", dem + 1);
            CENTER(a,b, stt, 100, 280 + x, 200, 330 + x);
            outtextxy(a, b, stt);

            CENTER(a,b, q->cb.ve[i]->Ghe_so, 200, 280 + x, 350, 330 + x);
            outtextxy(a, b, q->cb.ve[i]->Ghe_so);

            CENTER(a,b, q->cb.ve[i]->CMND, 350, 280 + x, 750, 330 + x);
            outtextxy(a, b, q->cb.ve[i]->CMND);

            char HoTen[45];
            strcpy(HoTen, p->data.Ho);
            strcat(HoTen, " ");
            strcat(HoTen, p->data.Ten);
            outtextxy(750, 295 + x, HoTen);

            if (p->data.gioiTinh == true) {
                char Nam[] = "Nam";
                CENTER(a,b, Nam, 1050, 280 + x, 1350, 330 + x);
                outtextxy(a, b, Nam);
            } else {
                char Nu[] = "Nu";
                CENTER(a,b, Nu, 1050, 280 + x, 1350, 330 + x);
                outtextxy(a, b, Nu);
            }
            CENTER(a,b, HUYVE, 1370, 280 + x, 1440, 330 + x);
            rectangle(1370, 290 + x, 1440, 320 + x);
            outtextxy(a, b, HUYVE);
            x += 50;
            dem++;
        }
    }
}
// in khach hang trong phan huy ve
void indsKHonCB2(NODECBPTR& q, TREE root) {
    int itemsPerPage = 7;
    int currentPage = 1;
    while(true) {
        // Tổng số trang
        int numPages;
        if (q->cb.soLuongDatVe + 1 % itemsPerPage != 0 )
        {
            numPages = q->cb.soLuongDatVe / itemsPerPage + 1;
        } else {
            numPages = q->cb.soLuongDatVe / itemsPerPage;
        }
        int a, b;
        khungindsKHonCB2(q);
        setcolor(BLACK);
        setfillstyle(SOLID_FILL, LIGHTGRAY);
        setbkcolor(LIGHTGRAY);
        inKH2(q, root, currentPage);
        char stt[4];
        sprintf(stt, "%d", currentPage);
        rectangle(1250, 700, 1300, 730);
        CENTER(a, b, stt, 1250, 700, 1300, 730);
        outtextxy(a,b, stt);
        
        int dem = 0;
        int i = 0;

        for (i; dem < (currentPage - 1) * itemsPerPage && dem < q->cb.soLuongDatVe ; i++) {
            if (q->cb.ve[i]->ttVe == DA_DAT){
                dem++;
            }
        }
        int dau = dem;
        
        // Vẽ nút điều hướng
        if (currentPage > 1) {
            char trai[] = "<";
            rectangle(1200, 700, 1250, 730);
            CENTER(a, b, trai, 1200, 700, 1250, 730);
            outtextxy(a, b, trai);
        }
        if (currentPage < numPages) {
            char phai[] = ">";
            rectangle(1300, 700, 1350, 730);
            CENTER(a, b, phai, 1300, 700, 1350, 730);
            outtextxy(a, b, phai);
        }   

        int x = mousex();
        int y = mousey();
        while (!ismouseclick(WM_LBUTTONDOWN)) {
            delay(100);
        }
        getmouseclick(WM_LBUTTONDOWN, x, y);
        if (x >= 1200 && x <= 1250 && y >= 700 && y <= 750 && currentPage > 1) {
            currentPage--;
        } else if (x >= 1300 && x <= 1350 && y >= 700 && y <= 750 && currentPage < numPages) {
            currentPage++;
        } else if (y >= 340 && y <= 370 && x >= 1370 && x <= 1440 && dau + 1 <= q->cb.soLuongDatVe) {
            while (dem < dau + 1) {
                if (q->cb.ve[i]->ttVe == DA_DAT){
                    dem++;
                }
                if (dem == dau + 1){
                    i--;
                }
                i++;
            }
            HuyVE(q, i);
        }
        else if (y >= 340 + 50 && y <= 370 + 50 && x >= 1370 && x <= 1440 && dau + 2 <= q->cb.soLuongDatVe) {
            for (i ; dem < dau + 2 ; i++) {
                if (q->cb.ve[i]->ttVe == DA_DAT){
                    dem++;
                }
                if (dem == dau + 2){
                    i--;
                }
            }
            HuyVE(q, i);
        }
        else if (y >= 340 + 100 && y <= 370 + 100 && x >= 1370 && x <= 1440 && dau + 3 <= q->cb.soLuongDatVe) {
            for (i ; dem < dau + 3 ; i++) {
                if (q->cb.ve[i]->ttVe == DA_DAT){
                    dem++;
                }
                if (dem == dau + 3){
                    i--;
                }
            }
            HuyVE(q, i);
        }
        else if (y >= 340 + 150 && y <= 370 + 150 && x >= 1370 && x <= 1440  && dau + 4 <= q->cb.soLuongDatVe) {
            for (i ; dem < dau + 4 ; i++) {
                if (q->cb.ve[i]->ttVe == DA_DAT){
                    dem++;
                }
                if (dem == dau + 4){
                    i--;
                }
            }
            HuyVE(q, i);
        }
        else if (y >= 340 + 200 && y <= 370 + 200 && x >= 1370 && x <= 1440  && dau + 5 <= q->cb.soLuongDatVe) {
            for (i ; dem < dau + 5 ; i++) {
                if (q->cb.ve[i]->ttVe == DA_DAT){
                    dem++;
                }
                if (dem == dau + 5){
                    i--;
                }
            }
            HuyVE(q, i);
        }
        else if (y >= 340 + 250 && y <= 370 + 250 && x >= 1370 && x <= 1440  && dau + 6 <= q->cb.soLuongDatVe) {
            for (i ; dem < dau + 6 ; i++) {
                if (q->cb.ve[i]->ttVe == DA_DAT){
                    dem++;
                }
                if (dem == dau + 6){
                    i--;
                }
            }
            HuyVE(q, i);
        }
        else if (y >= 340 + 300 && y <= 370 + 300 && x >= 1370 && x <= 1440  && dau + 7 <= q->cb.soLuongDatVe) {
            for (i ; dem < dau + 7 ; i++) {
                if (q->cb.ve[i]->ttVe == DA_DAT){
                    dem++;
                }
                if (dem == 7){
                    i--;
                }
            }
            HuyVE(q, i);
        }
        else if ((y >= 200 && y <= 250 && x >= 60 && x <= 130)) {
            break;
        }
    }
}
// khung in dach sach khach hang
void khungindsKH() {
    char text26[] = "STT";
    char text28[] = "SO CCCD";
    char text29[] = "HO TEN";
    char text30[] = "PHAI";
    char text32[] = "NHAP CCCD";
    char SAVE[] = "SAVE";

    int a, b;
    int x, y;

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    setcolor(BLACK);
    rectangle(20,160, 1480, 740);
    bar(21, 161, 1479, 739);

    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar(40,280,1460,330);
    setcolor(BLACK);
    rectangle(40,280, 1460, 680);

    int k = 0;
    for (int i = 0; i <= 7 ; i++) {
        
        line(40,280 + k,1460, 280 + k);
        k = k + 50;
    }

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    setcolor(BLACK);
    setbkcolor(LIGHTGRAY);

    outtextxy(40, 195, text32);
    rectangle(160, 180, 420, 230);

    int LIGHTRED = RGB (255, 100, 100);
    setfillstyle(SOLID_FILL, LIGHTRED);
    bar(420, 180, 480, 230);
    rectangle(420, 180, 480, 230);
    line(435, 190, 465, 220);
    line(435, 220, 465, 190);

    setfillstyle(SOLID_FILL, LIGHTGRAY);

    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    setcolor(WHITE);
    setbkcolor(LIGHTBLUE);

    CENTER(a,b, text26, 100, 280, 200, 330);
    outtextxy(a, b, text26);

    CENTER(a,b, text28, 200, 280, 750, 330);
    outtextxy(a, b, text28);

    outtextxy(750, 295, text29);

    CENTER(a,b, text30, 1050, 280, 1350, 330);
    outtextxy(a, b, text30);

}
// in danh sach toan bo khach hang
void inalldsKH(TREE root, int currentPage, int x, int& dem, int sosanh, int dau, int cuoi) {
    setcolor(BLACK);
    rectangle(40,280, 1460, 680);
    int k = 0;
    for (int i = 0; i <= 7 ; i++) {
        
        line(40,280 + k,1460, 280 + k);
        k = k + 50;
    }
    int a, b;
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    setcolor(BLACK);
    setbkcolor(LIGHTGRAY);
    if (root != NULL) {
        inalldsKH(root->left, currentPage, x, dem, sosanh, dau, cuoi);
        if (dem >= dau && dem < cuoi) {
            settextstyle(BOLD_FONT, HORIZ_DIR, 1);
            setcolor(WHITE);
            setbkcolor(LIGHTGRAY);
            char stt[4];
            sprintf(stt, "%d", dem + 1);
            CENTER(a, b, stt, 100, 280 + x, 200, 330 + x);
            outtextxy(a, b, stt);

            CENTER(a, b, root->data.CMND, 200, 280 + x, 750, 330 + x);
            outtextxy(a, b, root->data.CMND);

            char HoTen[45];
            strcpy(HoTen, root->data.Ho);
            strcat(HoTen, " ");
            strcat(HoTen, root->data.Ten);
            outtextxy(750,295 + x, HoTen);

            if (root->data.gioiTinh == true) {
                char Nam[] = "Nam";
                CENTER(a, b, Nam, 1050, 280 + x, 1350, 330 + x);
                outtextxy(a, b, Nam);
            } else {
                char Nu[] = "Nu";
                CENTER(a, b, Nu, 1050, 280 + x, 1350, 330 + x);
                outtextxy(a, b, Nu);
            }
            x += 50;
        }
        dem++;
        if (dem == cuoi) {
            return;
        }
        inalldsKH(root->right, currentPage, x, dem, sosanh, dau, cuoi);
    }
}
// in mot khach hang
void inMotKH(TREE q, int dem){
    int a, b;
    int x = 50;
    settextstyle(BOLD_FONT, HORIZ_DIR, 1);
    setcolor(WHITE);
    setbkcolor(LIGHTGRAY);
    char stt[4];
    sprintf(stt, "%d", dem + 1);
    CENTER(a, b, stt, 100, 280 + x, 200, 330 + x);
    outtextxy(a, b, stt);

    CENTER(a, b, q->data.CMND, 200, 280 + x, 750, 330 + x);
    outtextxy(a, b, q->data.CMND);

    char HoTen[45];
    strcpy(HoTen, q->data.Ho);
    strcat(HoTen, " ");
    strcat(HoTen, q->data.Ten);
    outtextxy(750,295 + x, HoTen);

    if (q->data.gioiTinh == true) {
        char Nam[] = "Nam";
        CENTER(a, b, Nam, 1050, 280 + x, 1350, 330 + x);
        outtextxy(a, b, Nam);
    } else {
        char Nu[] = "Nu";
        CENTER(a, b, Nu, 1050, 280 + x, 1350, 330 + x);
        outtextxy(a, b, Nu);
    }
    bar(40, 381, 1461, 740);
}

// thong tin ghe
void thongtinghe() {
    char DADAT[] = "DA DAT";
    char Trong[] = "TRONG";
    char DANGCHON[] = "DANG CHON";
    setfillstyle(SOLID_FILL, LIGHTRED);
    bar(1100, 180, 1150, 230);
    rectangle(1100, 180, 1150, 230);


    setfillstyle(SOLID_FILL, WHITE);
    bar(1100, 260, 1150, 310);
    rectangle(1100, 260, 1150, 310);

    setfillstyle(SOLID_FILL, LIGHTYELLOW);
    bar(1100, 340, 1150, 390);
    rectangle(1100, 340, 1150, 390);

    setbkcolor(LIGHTGRAY);
    outtextxy(1180, 200 , DADAT);
    outtextxy(1180, 280 , Trong);
    outtextxy(1180, 360 , DANGCHON);
}
// khung nhap thong tin khach hang
void khungnhapthongtin() {
    int a, b;
    char NhapCMND[] = "CCCD";
    char Ho[] = "Ho";
    char Ten[] = "Ten";
    char Gioitinh[] = "Gioi tinh";
    char Female[] = "F";
    char Male[] = "M";
    char ESC[] = "ESC";
    char DAT[] = "DAT";

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    setbkcolor(LIGHTGRAY);
    outtextxy(60, 455 , NhapCMND);
    rectangle(150, 440, 500, 480);

    outtextxy(60, 535 , Ho);
    rectangle(150, 520, 350, 560);

    outtextxy(60, 615 , Ten);
    rectangle(150, 600, 500, 640);

    outtextxy(60, 695, Gioitinh);

    rectangle(200, 680, 250, 720);
    CENTER(a, b, Male, 200, 680, 250, 720);
    outtextxy(a, b, Male);

    rectangle(300, 680, 350, 720);
    CENTER(a, b, Female, 300, 680, 350, 720);
    outtextxy(a, b, Female);

}
// khung chon cho ghe ngoi
void khungchonchongoi(DSMB dsMB, NODECBPTR q, int k) {
    int chiso;
    checkMB(dsMB, q->cb.soHieuMB, chiso);

    int LIGHTRED = RGB (255, 100, 100);
    int LIGHTYELLOW = RGB(250, 250, 210);
    int LIGHTBLUE = RGB(173, 216, 230);
    int a, b;

    char ESC[] = "ESC";
    char DAT[] = "DAT";
    setbkcolor(LIGHTGRAY);
    rectangle(940, 670, 1040,  720);
    CENTER(a, b, DAT, 940, 670, 1040,  720);
    outtextxy(a, b, DAT);
    
    setfillstyle(SOLID_FILL, LIGHTRED);
    setbkcolor(LIGHTRED);
    bar(1360, 180 , 1460, 230);
    rectangle(1360, 180 , 1460, 230);
    CENTER(a, b, ESC, 1360, 180 ,1460, 230);
    outtextxy(a, b, ESC);

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    setcolor(BLACK);
    setbkcolor(LIGHTGRAY);

    char text33[] = "THONG TIN CHUYEN BAY";
    char thongtin[60] = "";
    char chuoi[10] = "";
    char maybay[60] = "";
    char di[] = "";

    settextstyle(BOLD_FONT, HORIZ_DIR, 3);
    outtextxy(1100, 450,text33);
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    sprintf(chuoi, "%d", q->cb.time_xp.ngay);
    strcpy(thongtin, chuoi);
    strcat(thongtin," Thg ");
    sprintf(chuoi, "%d", q->cb.time_xp.thang);
    strcat(thongtin, chuoi);
    strcat(thongtin, ", ");
    sprintf(chuoi, "%d", q->cb.time_xp.gio);
    strcat(thongtin, chuoi);
    strcat(thongtin, ":");
    if (q->cb.time_xp.phut < 10) {
        strcat(thongtin, "0");
    }
    sprintf(chuoi, "%d", q->cb.time_xp.phut);
    strcat(thongtin, chuoi);

    outtextxy(1100, 480 ,thongtin);

    strcpy(di, q->cb.noiDi);
    strcat(di, " -> ");
    strcat(di, q->cb.noiDen);
    outtextxy(1100 , 510 , di);

    outtextxy(1100 , 540 , q->cb.maCB);

    strcpy(maybay, "May bay: ");
    strcat(maybay,dsMB.data[chiso]->loai);
    outtextxy(1100, 570 ,maybay);

    int x = 0;
    int y = 0;
    int nhan;
    for (int i = 0; i < dsMB.data[chiso]->soDay; i++) {
        nhan = i * dsMB.data[chiso]->soDong;
        for (int j = nhan ; j < dsMB.data[chiso]->soDong + nhan; j++) {
            if (q->cb.ve[j]->ttVe == DA_DAT) {
                setfillstyle(SOLID_FILL, LIGHTRED);
                bar(40 + x, 180 +  y, 90 + x, 230 + y);
                setbkcolor(LIGHTRED);
            } else {
                setfillstyle(SOLID_FILL, WHITE);
                bar(40 + x, 180 +  y, 90 + x, 230 + y);
                setbkcolor(WHITE);
            }
            if (j == k) {
                setfillstyle(SOLID_FILL, LIGHTYELLOW);
                bar(40 + x, 180 +  y, 90 + x, 230 + y);
                setbkcolor(LIGHTYELLOW);
            }
            rectangle(40 + x, 180 +  y, 90 + x, 230 + y);
            CENTER(a, b, q->cb.ve[j]->Ghe_so,40 + x, 180 +  y, 90 + x, 230 + y);
            outtextxy(a,b, q->cb.ve[j]->Ghe_so);
            x = x + 50;
        }
        x = 0;
        y = y + 50;
    }
}
// chon ghe ngoi
void chonchongoi(DSMB dsMB, NODECBPTR First, NODECBPTR& q, TREE& root, KH kh) {

    setfillstyle(SOLID_FILL, LIGHTGRAY);
    setcolor(BLACK);
    rectangle(20,160, 1480, 740);
    setbkcolor(LIGHTGRAY);
    bar(21, 161, 1479, 739);

    TREE p;
    int chongoi;
    int LIGHTRED = RGB (255, 100, 100);
    int hang1 = 0;
    int hang2;
    int hang3;
    int hang4;
    int hang5;
    int chiso;
    int a, b;
    char CMND[13] = "";
    char Ho[11] = "";
    char Ten[31] = "";
    char trong[] = "";
    char Female[] = "F";
    char Male[] = "M";
    char baoloi1[] = "Khach hang da dat ve tren chuyen bay nay!";
    char baoloi2[] = "Khach hang da dat ve tren mot chuyen bay khac cung thoi gian!";
    bool checkghe = false;
    bool checkCMND = false;
    bool checkHo = false;
    bool checkTen = false;
    bool checkgioitinh;
    bool check = false;
    int k = 0;
    int h = 0;
    int nhan;
    checkMB(dsMB, q->cb.soHieuMB, chiso);
    if (2 <= dsMB.data[chiso]->soDay) {
        hang2 = hang1 + dsMB.data[chiso]->soDong;
    }
    if (3 <= dsMB.data[chiso]->soDay) {
        hang3 = hang2 + dsMB.data[chiso]->soDong;
    }
    if (4 <= dsMB.data[chiso]->soDay) {
        hang4 = hang3 + dsMB.data[chiso]->soDong;
    }
    if (5 <= dsMB.data[chiso]->soDay) {
        hang5 = hang4 + dsMB.data[chiso]->soDong;
    }
    khungchonchongoi(dsMB, q, -1);
    khungnhapthongtin();
    thongtinghe();
    while(true) {
        setbkcolor(LIGHTGRAY);
        outtextxy(160, 455, CMND);
        outtextxy(160, 535,Ho);
        outtextxy(160, 615, Ten);
        if (checkCMND == true && checkHo == true && checkTen == true) {
            if (checkgioitinh == true) {
                setfillstyle(SOLID_FILL, LIGHTRED);
                setbkcolor(LIGHTRED);
                bar(200, 680, 250, 720);
                rectangle(200, 680, 250, 720);
                CENTER(a, b, Male, 200, 680, 250, 720);
                outtextxy(a, b, Male);

                setfillstyle(SOLID_FILL, LIGHTGRAY);
                setbkcolor(LIGHTGRAY);
                bar(300, 680, 350, 720);
                rectangle(300, 680, 350, 720);
                CENTER(a, b, Female, 300, 680, 350, 720);
                outtextxy(a, b, Female);
            } 
            if (checkgioitinh == false) {
                setfillstyle(SOLID_FILL, LIGHTRED);
                setbkcolor(LIGHTRED);
                bar(300, 680, 350, 720);
                rectangle(300, 680, 350, 720);
                CENTER(a, b, Female, 300, 680, 350, 720);
                outtextxy(a, b, Female);

                setfillstyle(SOLID_FILL , LIGHTGRAY);
                setbkcolor(LIGHTGRAY);
                bar(200, 680, 250, 720);
                rectangle(200, 680, 250, 720);
                CENTER(a, b, Male, 200, 680, 250, 720);
                outtextxy(a, b, Male);
            }
        }
        int x = mousex();
        int y = mousey();
        while (!ismouseclick(WM_LBUTTONDOWN)) {
            delay(100);
        }
        getmouseclick(WM_LBUTTONDOWN, x, y);
        check = false;
        if (y >= 180 && y <= 230 && x >= 1360 && x <= 1460) {
            check = true;
            break;
        }
        if (y >= 180 && y <= 230 * dsMB.data[chiso]->soDay && x >= 40 && x <=  90 * dsMB.data[chiso]->soDong && check == false) {
            k = 0;
            for (int i = 0; i < dsMB.data[chiso]->soDay && check == false; i++) {
                nhan = i * dsMB.data[chiso]->soDong;
                for (int j = nhan ; j < dsMB.data[chiso]->soDong + nhan  && check == false; j++) {
                    if (y >= 180 + k && y <= 230 + k && x >= 40 + h && x <= 90 + h ) {
                        if (q->cb.ve[j]->ttVe == TRONG) {
                            khungchonchongoi(dsMB, q, j);
                            chongoi = j;
                            check = true;
                            checkghe = true;
                            clearmouseclick(WM_LBUTTONDOWN);
                            break;
                        }
                    }               
                    h = h + 50;
                }
                h = 0;
                k = k + 50;
            }
        }
        if (y >= 440 && y <= 480 && x >= 150 && x <= 500) {
            setfillstyle(SOLID_FILL, LIGHTGRAY);
            bar(150, 482, 1000, 520);
            khungText(150, 440, 500, 480, 12, So, trong, CMND, x, y);
            checkCMND = true;
            if (strcmp(CMND, trong) == 0) {
                checkCMND = false;
            }
            if (checkCMND == true) {
                if (timKiemKH(root, CMND) != NULL) {
                    p = timKiemKH(root, CMND);
                    if(checkCMNDonCB(CMND, q) == true) {
                        outtextxy(150, 490, baoloi1);
                        checkCMND = false;
                    }
                    if (checkCMNDALLCB(First, q, CMND) == false) {
                        outtextxy(150, 490, baoloi2);
                        checkCMND = false;
                    }
                    if (checkCMNDonCB(CMND, q) == false && checkCMNDALLCB(First, q, CMND) == true){
                        strcpy(Ho, p->data.Ho);
                        strcpy(Ten, p->data.Ten);
                        checkgioitinh = p->data.gioiTinh;
                        checkCMND = true;
                        checkHo = true;
                        checkTen = true;
                    }
                } else {
                    checkCMND = true;
                }
            }
        }
        if (y >= 520 && y <= 560 && x >= 150 && x <= 350 && checkCMND == true) {
            khungText(150, 520, 350, 560, 10, ChuNormal, trong, Ho, x, y);
            if (strcmp(Ho, trong) == 0) {checkHo = false;} else {checkHo = true;}

        }
        if (y >= 600 && y <= 640 && x >= 150 && x <= 500 && checkCMND == true) {
            khungText(150, 600, 500, 640,30, ChuNormal , trong, Ten , x, y);
            if (strcmp(Ten, trong) == 0) {checkTen = false;} 
            else {checkTen = true;}
        }
        if (y >= 680 && y <= 720 && x >= 200 && x <= 250 && checkCMND == true) {
            checkgioitinh = true;
        }
        if (y >= 680 && y <= 720 && x >= 300 && x <= 350  && checkCMND == true) {
            checkgioitinh = false;
        }
        if (y >= 670 && y <= 720 && x >= 940 && x <= 1040 &&  checkCMND == true && checkHo == true && checkTen == true && checkghe == true) {
            if (timKiemKH(root, CMND) == NULL){
                strcpy(kh.CMND, CMND);
                strcpy(kh.Ho, Ho);
                strcpy(kh.Ten, Ten);
                kh.gioiTinh = checkgioitinh;
                themKH(root,kh);
            } 
            if (timKiemKH(root, CMND) != NULL){
                p = timKiemKH(root, CMND);
                strcpy(p->data.Ho, Ho);
                strcpy(p->data.Ten, Ten);
                p->data.gioiTinh = checkgioitinh;
            }
            strcpy(q->cb.ve[chongoi]->CMND, CMND);
            q->cb.ve[chongoi]->ttVe = DA_DAT;
            q->cb.soLuongDatVe++;
            check = true;
            break;
        } 
    }
}
// main chinh
int main() {
    time_t now = time(0);
    tm* tm_now = localtime(&now);

    MB mb;
    DSMB dsMB;
    NODECBPTR First = NULL;
    Chuyen_Bay cb;
    TREE root;
    KH kh;
    VE ve;
    TIME time_xp;
    khoiTaoCay(root);


    LoadFileMB(dsMB);
    LoadFileCB(dsMB,First, cb);
    updatesolanbay(dsMB, First, tm_now);
    updatettmb(dsMB, tm_now, First);
    updatett(dsMB,First,tm_now);
    LoadFileVe(First, ve, cb);
    LoadFileKH(root, kh);

    char ten[] = "QUAN LY MAY BAY PTIT 2023";
    initwindow(1500, 765,ten);
	//mau nen
	setbkcolor(WHITE);
	floodfill(0,0, WHITE);

    int LIGHTPINK = RGB (247, 168, 184);
    int LIGHTBLUE = RGB(173, 216, 230);
    bool nhan = true;
	//"Trinh quan ly may bay
    char text[] = "TRINH QUAN LY CHUYEN BAY";
    char MAYBAY[] = "MAY BAY";
    char CHUYENBAY[] = "CHUYEN BAY";
    char HANHKHACH[] = "HANH KHACH";
    char DATHUYVE[] = "DAT VE/HUY VE";
	setcolor(BLACK);
    settextstyle(BOLD_FONT, HORIZ_DIR, 5);
    int text_width = textwidth(text); // Tính chiều rộng của chuỗi;
    // Tính toán vị trí cần vẽ chuỗi
    int a = (getmaxx() - text_width) / 2; // Tọa độ x
    int b;
    outtextxy(a, 25, text);

    setcolor(WHITE);
    settextstyle(BOLD_FONT, HORIZ_DIR, 2);

    Doimau(LIGHTPINK, LIGHTPINK, LIGHTPINK, LIGHTPINK);

	while(true){
        nhan = true;
        updatettmb(dsMB, tm_now, First);

        while (!ismouseclick(WM_LBUTTONDOWN)) {
            delay(100);
        }

		int x = mousex();
        int y = mousey();

        getmouseclick(WM_LBUTTONDOWN, x, y);
        //thao tac phan may bay
        if (y >= 100 && y <= 150 && x >= 20 && x <= 375-20 && nhan == true) {
            Doimau(LIGHTBLUE, LIGHTPINK, LIGHTPINK, LIGHTPINK);
            khungindsMB();
            int itemsPerPage = 9;

            // Tổng số trang
            int currentPage = 1;
            bool thoat = true;
            while (thoat == true) {
                int numPages;
                if (dsMB.soMB % itemsPerPage != 0 )
                {
                    numPages = dsMB.soMB / itemsPerPage + 1;
                } else {
                    numPages = dsMB.soMB / itemsPerPage;
                }
                char trong[] = "";
                // Vẽ danh sách phần tử của trang hiện tại
                int startIndex = (currentPage - 1) * itemsPerPage;
                khungindsMB();
                inMB(dsMB, currentPage, -1);
                setcolor(BLACK);
                int a, b;
                char stt[4];
                sprintf(stt, "%d", currentPage, numPages);
                rectangle(1250, 700, 1300, 730);
                CENTER(a, b, stt, 1250, 700, 1300, 730);
                outtextxy(a,b, stt);
                int i;
                int m;
                i = 9 * (currentPage - 1);
                m = i + 9;
                // Vẽ nút điều hướng
                if (currentPage > 1) {
                    char trai[] = "<";
                    rectangle(1200, 700, 1250, 730);
                    CENTER(a, b, trai, 1200, 700, 1250, 730);
                    outtextxy(a, b, trai);
                }
                if (currentPage < numPages) {
                    char phai[] = ">";
                    rectangle(1300, 700, 1350, 730);
                    CENTER(a, b, phai, 1300, 700, 1350, 730);
                    outtextxy(a, b, phai);
                }
                // Chờ sự kiện nhấn nút
                int x = mousex();
                int y = mousey();
                while (!ismouseclick(WM_LBUTTONDOWN)) {
                    delay(100);
                }
                getmouseclick(WM_LBUTTONDOWN, x, y);
                // Xử lý sự kiện
                if (x >= 1200 && x <= 1250 && y >= 700 && y <= 750 && currentPage > 1) {
                    currentPage--;
                } else if (x >= 1300 && x <= 1350 && y >= 700 && y <= 750 && currentPage < numPages) {
                    currentPage++;
                } else if (y >= 230 && y <= 280 && x >= 40 && x <= 1350 && i < dsMB.soMB) {
                    inMB(dsMB, currentPage, i);
                    bool thoat = true;
                    while(thoat == true) {
                        while (!ismouseclick(WM_LBUTTONDOWN)) {
                            delay(100);
                        }
                        getmouseclick(WM_LBUTTONDOWN, x, y);
                        if (y >= 240 && y <= 270 && x >= 1225 && x <= 1325) {
                            HIEUCHINHMB(dsMB, mb, LIGHTPINK, i, First, cb);
                            break;
                        }
                        else if (y >= 240 && y <= 270 && x >= 1345 && x <= 1445) {
                            deleteMB(dsMB,First, i);
                            break;
                        }
                        else if (y >= 230 && y <= 280 && x >= 40 && x <= 1350){
                            thoat = false;
                        }
                    }
                } else if (y >= 280 && y <= 330 && x >= 40 && x <= 1350 && i + 1 < dsMB.soMB) {
                    inMB(dsMB, currentPage, i + 1);
                    bool thoat = true;
                    while(thoat == true) {
                        while (!ismouseclick(WM_LBUTTONDOWN)) {
                            delay(100);
                        }
                        getmouseclick(WM_LBUTTONDOWN, x, y);
                        if (y >= 240 + 50 && y <= 270 + 50 && x >= 1225 && x <= 1325) {
                            HIEUCHINHMB(dsMB, mb, LIGHTPINK, i + 1, First, cb);
                            break;
                        }
                        else if (y >= 240 + 50 && y <= 270 + 50 && x >= 1345 && x <= 1445) {
                            deleteMB(dsMB,First, i + 1);
                            break;
                        }
                        else if (y >= 230 + 50 && y <= 280 + 50 && x >= 40 && x <= 1350){
                            thoat = false;
                        }

                    }
                } else if (y >= 330 && y <= 380 && x >= 40 && x <= 1350 && i + 2 < dsMB.soMB) {
                    inMB(dsMB, currentPage, i + 2);
                    bool thoat = true;
                    while(thoat == true) {
                        while (!ismouseclick(WM_LBUTTONDOWN)) {
                            delay(100);
                        }
                        getmouseclick(WM_LBUTTONDOWN, x, y);
                        if (y >= 240 + 100 && y <= 270 + 100 && x >= 1225 && x <= 1325) {
                            HIEUCHINHMB(dsMB, mb, LIGHTPINK, i + 2, First, cb);
                            break;
                        }
                        else if (y >= 240 + 100  && y <= 270 + 100  && x >= 1345 && x <= 1445) {
                            deleteMB(dsMB,First,  i + 2);
                            break;
                        }
                        else if (y >= 230 + 100 && y <= 280 + 100  && x >= 40 && x <= 1350){
                            thoat = false;
                        }

                    }
                } else if (y >= 380 && y <= 430 && x >= 40 && x <= 1350 && i + 3 < dsMB.soMB) {
                    inMB(dsMB, currentPage, i + 3);
                    bool thoat = true;
                    while(thoat == true) {
                        while (!ismouseclick(WM_LBUTTONDOWN)) {
                            delay(100);
                        }
                        getmouseclick(WM_LBUTTONDOWN, x, y);
                        if (y >= 240 + 150 && y <= 270 + 150 && x >= 1225 && x <= 1325) {
                            HIEUCHINHMB(dsMB, mb, LIGHTPINK, i + 3, First, cb);
                            break;
                        }
                        else if (y >= 240 + 150 && y <= 270 + 150 && x >= 1345 && x <= 1445) {
                            deleteMB(dsMB,First, i + 3);
                            break;
                        }
                        else if (y >= 230 + 150 && y <= 280 + 150 && x >= 40 && x <= 1350){
                            thoat = false;
                        }

                    }
                } else if (y >= 430 && y <= 480 && x >= 40 && x <= 1350 &&  i + 4 < dsMB.soMB) {
                    inMB(dsMB, currentPage, i + 4);
                    bool thoat = true;
                    while(thoat == true) {
                        while (!ismouseclick(WM_LBUTTONDOWN)) {
                            delay(100);
                        }
                        getmouseclick(WM_LBUTTONDOWN, x, y);
                        if (y >= 240 + 200 && y <= 270 + 200 && x >= 1225 && x <= 1325) {
                            HIEUCHINHMB(dsMB, mb, LIGHTPINK, i + 4, First, cb);
                            break;
                        }
                        else if (y >= 240 + 200 && y <= 270 + 200 && x >= 1345 && x <= 1445) {
                            deleteMB(dsMB,First, i + 4);
                            break;
                        }
                        else if (y >= 230 + 200 && y <= 280 + 200 && x >= 40 && x <= 1350){
                            thoat = false;
                        }

                    }
                } else if (y >= 480 && y <= 530 && x >= 40 && x <= 1350  && i + 5 < dsMB.soMB) {
                   inMB(dsMB, currentPage, i + 5);
                    bool thoat = true;
                    while(thoat == true) {
                        while (!ismouseclick(WM_LBUTTONDOWN)) {
                            delay(100);
                        }
                        getmouseclick(WM_LBUTTONDOWN, x, y);
                        if (y >= 240 + 250 && y <= 270 + 250 && x >= 1225 && x <= 1325) {
                            HIEUCHINHMB(dsMB, mb, LIGHTPINK, i + 5, First, cb);
                            break;
                        }
                        else if (y >= 240 + 250 && y <= 270 + 250 && x >= 1345 && x <= 1445) {
                            deleteMB(dsMB,First, i + 5);
                            break;
                        }
                        else if (y >= 230 + 250 && y <= 280 + 250 && x >= 40 && x <= 1350){
                            thoat = false;
                        }

                    }
                } else if (y >= 530 && y <= 580 && x >= 40 && x <= 1350 && i + 6 < dsMB.soMB) {
                    inMB(dsMB, currentPage, i + 6);
                    bool thoat = true;
                    while(thoat == true) {
                        while (!ismouseclick(WM_LBUTTONDOWN)) {
                            delay(100);
                        }
                        getmouseclick(WM_LBUTTONDOWN, x, y);
                        if (y >= 240 + 300 && y <= 270 +  300 && x >= 1225 && x <= 1325) {
                            HIEUCHINHMB(dsMB, mb, LIGHTPINK, i + 6, First, cb);
                            break;
                        }
                        else if (y >= 240 + 300 && y <= 270 +  300 && x >= 1345 && x <= 1445) {
                            deleteMB(dsMB,First, i + 6);
                            break;
                        }
                        else if (y >= 230 +  300 && y <= 280 +  300 && x >= 40 && x <= 1350){
                            thoat = false;
                        }

                    }
                } else if (y >= 580 && y <= 630 && x >= 40 && x <= 1350 && i + 7 < dsMB.soMB) {
                    inMB(dsMB, currentPage, i + 7);
                    bool thoat = true;
                    while(thoat == true) {
                        while (!ismouseclick(WM_LBUTTONDOWN)) {
                            delay(100);
                        }
                        getmouseclick(WM_LBUTTONDOWN, x, y);
                        if (y >= 240 + 350 && y <= 270 + 350 && x >= 1225 && x <= 1325) {
                            HIEUCHINHMB(dsMB, mb, LIGHTPINK, i + 7, First, cb);
                            break;
                        }
                        else if (y >= 240 + 350 && y <= 270 + 350 && x >= 1345 && x <= 1445) {
                            deleteMB(dsMB,First, i + 7);
                            break;
                        }
                        else if (y >= 230 + 350 && y <= 280 + 350 && x >= 40 && x <= 1350){
                            thoat = false;
                        }

                    }
                } else if (y >= 630 && y <= 680 && x >= 40 && x <= 1350 && i + 8 < dsMB.soMB) {
                    inMB(dsMB, currentPage, i + 8);
                    bool thoat = true;
                    while(thoat == true) {
                        while (!ismouseclick(WM_LBUTTONDOWN)) {
                            delay(100);
                        }
                        getmouseclick(WM_LBUTTONDOWN, x, y);
                        if (y >= 240 + 400 && y <= 270 + 400 && x >= 1225 && x <= 1325) {
                            HIEUCHINHMB(dsMB, mb, LIGHTPINK, i + 8, First, cb);
                            break;
                        }
                        else if (y >= 240 + 400 && y <= 270 + 400 && x >= 1345 && x <= 1445) {
                            deleteMB(dsMB,First, i + 8);
                            break;
                        }
                        else if (y >= 230 + 400 && y <= 280 + 400 && x >= 40 && x <= 1350){
                            thoat = false;
                        }
                    }
                }

                else if ((y >= 700 && y <= 730 && x >= 40 && x <= 190) && checkMBFULL(dsMB.soMB) == true) {
                    THEMMBMOI(dsMB, mb, LIGHTPINK);
                }
                else if ((y >= 700 && y <= 730 && x >= 190 && x <= 340)) {
                    DSMB q  = dsMB;
                    Quick_Sort(q.data, 0, q.soMB - 1, 1);
                    thongkeMB(q);
                }
                else if ((y >= 100 && y <= 150 && x >= 395 && x <= 730) || (y >= 100 && y <= 150 && x >= 770 && x <= 1105) || (y >= 100 && y <= 150 && x >= 1145 && x <= 1480)) {
                    thoat = false;
                    nhan = false;
                    break;
                } else if ( y >= 20 && y <= 60 && x >=1320 && x <= 1420) {
                    SaveFileMB(dsMB);
                    SaveFileCB(First);
                    SaveFileVe(First);
                    SaveFileKH(root);
                }
                else if (y >= 20 && y <= 60 && x >= 1440 && x <= 1480) {
                    giaiPhongMB(dsMB);
                    giaiphongCB(First);
                    giaiPhongKH(root);
                    closegraph();
                    return 0;
                }
                updatettmb(dsMB, tm_now, First);
            } 
        }
        // thao tac phan chuyen bay
        if (y >= 100 && y <= 150 && x >= 395 && x <= 730 && nhan == true) {
            Doimau(LIGHTPINK, LIGHTBLUE, LIGHTPINK, LIGHTPINK);

            settextstyle(BOLD_FONT, HORIZ_DIR, 2);
            setfillstyle(SOLID_FILL, LIGHTGRAY);
            setcolor(BLACK);
            rectangle(20,160, 1480, 740);
            bar(21, 161, 1479, 739);
            khungindsCB();
            bool thoat = true;
            int itemsPerPage = 9;

            int currentPage = 1;
            NODECBPTR q;
            while (thoat == true) {
                updatett(dsMB, First, tm_now);
                int sochuyenbay = 0;
                for (q = First; q != NULL; q = q->next) {
                    sochuyenbay++;
                }
                q = First;
                // Tổng số trang
                int numPages;
                if (sochuyenbay % itemsPerPage != 0 )
                {
                    numPages = sochuyenbay / itemsPerPage + 1;
                } else {
                    numPages = sochuyenbay / itemsPerPage;
                }

                int a, b;
                char stt[4];
                khungindsCB();
                inCB(First, cb, -1, currentPage);
                setcolor(BLACK);
                sprintf(stt, "%d", currentPage);
                rectangle(1250, 700, 1300, 730);
                CENTER(a, b, stt, 1250, 700, 1300, 730);
                outtextxy(a,b, stt);
                int startIdx = 9 * (currentPage - 1);
                int endIdx = startIdx + 9;
                // Di chuyen con tro den trang hien tai
                for (int idx = 0; idx < startIdx && q != NULL; idx++) {
                    q = q->next;
                }
                // Vẽ nút điều hướng
                if (currentPage > 1) {
                    char trai[] = "<";
                    rectangle(1200, 700, 1250, 730);
                    CENTER(a, b, trai, 1200, 700, 1250, 730);
                    outtextxy(a, b, trai);
                }
                if (currentPage < numPages) {
                    char phai[] = ">";
                    rectangle(1300, 700, 1350, 730);
                    CENTER(a, b, phai, 1300, 700, 1350, 730);
                    outtextxy(a, b, phai);
                }   
                // Chờ sự kiện nhấn nút
                int x = mousex();
                int y = mousey();
                while (!ismouseclick(WM_LBUTTONDOWN)) {
                    delay(100);
                }
                getmouseclick(WM_LBUTTONDOWN, x, y);
                // Xử lý sự kiện
                if (x >= 1200 && x <= 1250 && y >= 700 && y <= 750 && currentPage > 1) {
                    currentPage--;
                } else if (x >= 1300 && x <= 1350 && y >= 700 && y <= 750 && currentPage < numPages) {
                    currentPage++;
                } 
                else if (y >= 230 && y <= 280 && x >= 40 && x <= 1460 && startIdx < sochuyenbay) {
                    inCB(First, cb, startIdx ,currentPage);
                    for (int i = startIdx; i < startIdx && q != NULL; i++) {
                        q = q->next;
                    }
                    bool dung = true;
                    while(true) {

                        while (!ismouseclick(WM_LBUTTONDOWN)) {
                            delay(100);
                        }
                        getmouseclick(WM_LBUTTONDOWN, x, y);
                        if (y >= 240 && y<= 270 && x >= 1105 && x <= 1205) {
                            indsKHonCB(q, root);
                            break;
                        }
                        else if  (y >= 240 && y <= 270 && x >= 1225 && x <= 1325 && q->cb.Trang_thai != HUY_CHUYEN && q->cb.Trang_thai != HOANTAT_CB) {
                            hieuChinhCB(First, dsMB, q,cb, tm_now, time_xp);
                            break;
                        }
                        else if (y >= 240 && y <= 270 && x >= 1345 && x <= 1445) {
                            if (cancelCB(q) == true) { 
                                cancelCB(q);
                            }
                            break;
                        }
                        else if (y >= 230  && y <= 280 && x >= 40 && x <= 1460){
                            dung = false;
                            break;
                        }
                    }
                } else if (y >= 280 && y <= 330 && x >= 40 && x <= 1460 && startIdx + 1 < sochuyenbay) {
                    inCB(First, cb, startIdx + 1 ,currentPage);
                    for (int i = startIdx; i < startIdx + 1 && q != NULL; i++)
                    {
                        q = q->next;
                    }
                    bool dung = true;
                    while(true) {

                        while (!ismouseclick(WM_LBUTTONDOWN)) {
                            delay(100);
                        }
                        getmouseclick(WM_LBUTTONDOWN, x, y);
                        if (y >= 240 + 50 && y <= 270 + 50 && x >= 1105 && x <= 1205) {
                            indsKHonCB(q, root);
                            break;
                        } else if (y >= 240 + 50 && y <= 270  + 50 && x >= 1225 && x <= 1325 && q->cb.Trang_thai != HUY_CHUYEN && q->cb.Trang_thai != HOANTAT_CB) {
                            hieuChinhCB(First, dsMB, q,cb, tm_now, time_xp);
                            break;
                        } else if (y >= 240 + 50 && y <= 270 + 50 && x >= 1345 && x <= 1445) {
                            if (cancelCB(q) == true) { 
                                cancelCB(q);
                            }
                            break;
                        } else if (y >= 230 + 50 && y <= 280 + 50&& x >= 40 && x <= 1460){
                            dung = false;
                            break;
                        }
                    }
                } else if (y >= 330 && y <= 380 && x >= 40 && x <= 1460 && startIdx + 2 < sochuyenbay) {
                    inCB(First, cb, startIdx + 2 ,currentPage);
                    for (int i = startIdx; i < startIdx + 2 && q != NULL; i++)
                    {
                        q = q->next;
                    }
                    bool dung = true;
                    while(true) {

                        while (!ismouseclick(WM_LBUTTONDOWN)) {
                            delay(100);
                        }
                        getmouseclick(WM_LBUTTONDOWN, x, y);
                        if (y >= 240 + 100 && y <= 270 + 100 && x >= 1105 && x <= 1205) {
                            indsKHonCB(q, root);
                            break;
                        } else if (y >= 240 + 100 && y <= 270  + 100 && x >= 1225 && x <= 1325 && q->cb.Trang_thai != HUY_CHUYEN && q->cb.Trang_thai != HOANTAT_CB) {
                            hieuChinhCB(First, dsMB, q,cb, tm_now, time_xp);
                            break;
                        } else if (y >= 240 + 100 && y <= 270 + 100 && x >= 1345 && x <= 1445) {
                            if (cancelCB(q) == true) { 
                                cancelCB(q);
                            }
                            break;
                        } else if (y >= 230 + 100 && y <= 280 + 100 && x >= 40 && x <= 1460){
                            dung = false;
                            break;
                        }
                    }
                } else if (y >= 380 && y <= 430 && x >= 40 && x <= 1460 &&  startIdx + 3 < sochuyenbay) {
                    inCB(First, cb, startIdx + 3 ,currentPage);
                    for (int i = startIdx; i < startIdx + 3 && q != NULL; i++)
                    {
                        q = q->next;
                    }
                    bool dung = true;
                    while(true) {

                        while (!ismouseclick(WM_LBUTTONDOWN)) {
                            delay(100);
                        }
                        getmouseclick(WM_LBUTTONDOWN, x, y);
                        if (y >= 240 + 150 && y <= 270 + 150 && x >= 1105 && x <= 1205) {
                            indsKHonCB(q, root);
                            break;
                        } else if (y >= 240 + 150 && y <= 270  + 150 && x >= 1225 && x <= 1325 && q->cb.Trang_thai != HUY_CHUYEN && q->cb.Trang_thai != HOANTAT_CB) {
                            hieuChinhCB(First, dsMB, q,cb, tm_now, time_xp);
                            break;
                        } else if (y >= 240 + 150 && y <= 270 + 150 && x >= 1345 && x <= 1445) {
                            if (cancelCB(q) == true) { 
                                cancelCB(q);
                            }
                            break;
                        } else if (y >= 230 + 150 && y <= 280 + 150 && x >= 40 && x <= 1460){
                            dung = false;
                            break;
                        }
                    }
                } else if (y >= 430 && y <= 480 && x >= 40 && x <= 1460 &&  startIdx + 4 < sochuyenbay) {
                    inCB(First, cb, startIdx + 4 ,currentPage);
                    for (int i = startIdx; i < startIdx + 4 && q != NULL; i++)
                    {
                        q = q->next;
                    }
                    bool dung = true;
                    while(true) {

                        while (!ismouseclick(WM_LBUTTONDOWN)) {
                            delay(100);
                        }
                        getmouseclick(WM_LBUTTONDOWN, x, y);
                        if (y >= 240 + 200 && y <= 270 + 200 && x >= 1105 && x <= 1205) {
                            indsKHonCB(q, root);
                            break;
                        } else if (y >= 240 + 200 && y <= 270 + 200 && x >= 1225 && x <= 1325 && q->cb.Trang_thai != HUY_CHUYEN && q->cb.Trang_thai != HOANTAT_CB) {
                            hieuChinhCB(First, dsMB, q,cb, tm_now, time_xp);
                            break;
                        } else if (y >= 240 + 200 && y <= 270 + 200 && x >= 1345 && x <= 1445) {
                            if (cancelCB(q) == true) { 
                                cancelCB(q);
                            }
                            break;
                        } else if (y >= 230 + 200 && y <= 280 + 200 && x >= 40 && x <= 1460){
                            dung = false;
                            break;
                        }
                    }
                } else if (y >= 480 && y <= 530 && x >= 40 && x <= 1460 && startIdx + 5 < sochuyenbay) {
                    inCB(First, cb, startIdx + 5 ,currentPage);
                    for (int i = startIdx; i < startIdx + 5 && q != NULL; i++)
                    {
                        q = q->next;
                    }
                    bool dung = true;
                    while(true) {

                        while (!ismouseclick(WM_LBUTTONDOWN)) {
                            delay(100);
                        }
                        getmouseclick(WM_LBUTTONDOWN, x, y);
                        if (y >= 240 + 250 && y <= 270 + 250 && x >= 1105 && x <= 1205) {
                            indsKHonCB(q, root);
                            break;
                        } else if (y >= 240 + 250 && y <= 270  + 250 && x >= 1225 && x <= 1325 && q->cb.Trang_thai != HUY_CHUYEN && q->cb.Trang_thai != HOANTAT_CB) {
                            hieuChinhCB(First, dsMB, q,cb, tm_now, time_xp);
                            break;
                        } else if (y >= 240 + 250 && y <= 270 + 250 && x >= 1345 && x <= 1445) {
                            if (cancelCB(q) == true) { 
                                cancelCB(q);
                            }
                            break;
                        } else if (y >= 230 + 250 && y <= 280 + 250 && x >= 40 && x <= 1460){
                            dung = false;
                            break;
                        }
                    }
                } else if (y >= 530 && y <= 580 && x >= 40 && x <= 1460 && startIdx + 6 < sochuyenbay) {
                    inCB(First, cb, startIdx + 6 ,currentPage);
                    for (int i = startIdx; i < startIdx + 6 && q != NULL; i++)
                    {
                        q = q->next;
                    }
                    bool dung = true;
                    while(true) {

                        while (!ismouseclick(WM_LBUTTONDOWN)) {
                            delay(100);
                        }
                        getmouseclick(WM_LBUTTONDOWN, x, y);
                        if (y >= 240 + 300 && y <= 270 + 300 && x >= 1105 && x <= 1205) {
                            indsKHonCB(q, root);
                            break;
                        } else if (y >= 240 + 300 && y <= 270  + 300 && x >= 1225 && x <= 1325 && q->cb.Trang_thai != HUY_CHUYEN && q->cb.Trang_thai != HOANTAT_CB) {
                            hieuChinhCB(First, dsMB, q,cb, tm_now, time_xp);
                            break;
                        } else if (y >= 240 + 300 && y <= 270 + 300 && x >= 1345 && x <= 1445) {
                            if (cancelCB(q) == true) { 
                                cancelCB(q);
                            }
                            break;
                        } else if (y >= 230 + 300 && y <= 280 + 300 & x >= 40 && x <= 1460){
                            dung = false;
                            break;
                        }
                    }
                } else if (y >= 580 && y <= 630 && x >= 40 && x <= 1460  && startIdx + 7 < sochuyenbay) {
                    inCB(First, cb, startIdx + 7 ,currentPage);
                    for (int i = startIdx; i < startIdx + 7 && q != NULL; i++)
                    {
                        q = q->next;
                    }
                    bool dung = true;
                    while(true) {

                        while (!ismouseclick(WM_LBUTTONDOWN)) {
                            delay(100);
                        }
                        getmouseclick(WM_LBUTTONDOWN, x, y);
                        if (y >= 240 + 350 && y <= 270 + 350 && x >= 1105 && x <= 1205) {
                            indsKHonCB(q, root);
                            break;
                        } else if (y >= 240 + 350 && y <= 270  + 350 && x >= 1225 & x <= 1325 && q->cb.Trang_thai != HUY_CHUYEN && q->cb.Trang_thai != HOANTAT_CB) {
                            hieuChinhCB(First, dsMB, q,cb, tm_now, time_xp);
                            break;
                        } else if (y >= 240 + 350 && y <= 270 + 350 && x >= 1345 && x <= 1445) {
                            if (cancelCB(q) == true) { 
                                cancelCB(q);
                            }
                            break;
                        } else if (y >= 230 + 350 && y <= 280 + 350 && x >= 40 && x <= 1460){
                            dung = false;
                            break;
                        }
                    }
                } else if (y >= 630 && y <= 680 && x >= 40 && x <= 1460 && startIdx + 8 < sochuyenbay) {
                    inCB(First, cb, startIdx + 8 ,currentPage);
                    for (int i = startIdx; i < startIdx + 8 && q != NULL; i++)
                    {
                        q = q->next;
                    }
                    bool dung = true;
                    while(true) {

                        while (!ismouseclick(WM_LBUTTONDOWN)) {
                            delay(100);
                        }
                        getmouseclick(WM_LBUTTONDOWN, x, y);
                        if (y >= 240 + 400 && y <= 270 + 400 && x >= 1105 && x <= 1205) {
                            indsKHonCB(q, root);
                            break;
                        } else if (y >= 240 + 400 && y <= 270 + 400 && x >= 1225 && x <= 1325 && q->cb.Trang_thai != HUY_CHUYEN && q->cb.Trang_thai != HOANTAT_CB) {
                            hieuChinhCB(First, dsMB, q,cb, tm_now, time_xp);
                            break;
                        } else if (y >= 240 + 400 && y <= 270 + 400 && x >= 1345 && x <= 1445) {
                            if (cancelCB(q) == true) { 
                                cancelCB(q);
                            }
                            break;
                        } else if (y >= 230 + 400 && y <= 280 + 400 && x >= 40 && x <= 1460){
                            dung = false;
                            break;
                        }
                    }
                } else if ((y >= 700 && y <= 730 && x >= 40 && x <= 190)) {
                    themChuyenBay(dsMB, First, cb, tm_now, time_xp);
                } else if ((y >= 100 && y <= 150 && x >= 20 && x <= 375-20) || (y >= 100 && y <= 150 && x >= 770 && x <= 1105) || (y >= 100 && y <= 150 && x >= 1145 && x <= 1480)) {
                    thoat = false;
                    nhan = false;
                    break;
                } else if ( y >= 20 && y <= 60 && x >=1320 && x <= 1420) {
                    SaveFileMB(dsMB);
                    SaveFileCB(First);
                    SaveFileVe(First);
                    SaveFileKH(root);
                }
                else if (y >= 20 && y <= 60 && x >= 1440 && x <= 1480) {
                    giaiPhongMB(dsMB);
                    giaiphongCB(First);
                    giaiPhongKH(root);
                    closegraph();
                    return 0;
                }
            }
        }
        // thao tac phan khach hang
        if (y >= 100 && y <= 150 && x >= 770 && x <= 1105 && nhan == true) {
            Doimau(LIGHTPINK, LIGHTPINK, LIGHTBLUE, LIGHTPINK);
            settextstyle(BOLD_FONT, HORIZ_DIR, 1);
            khungindsKH();
            int itemsPerPage = 7;

            int currentPage = 1;
            bool thoat = true;
            int dem = 0;
            bool checknhap = false;
            char CMND[13] = "";
            char trong[] = "";
            TREE q;
            while (thoat == true) {
                int numPages;
                if (checknhap == false) {
                    int soKH = 0;
                Duyet_LNR(root,soKH);
                if (soKH % itemsPerPage != 0 ) {
                    numPages = soKH / itemsPerPage + 1;
                } else {
                    numPages = soKH / itemsPerPage;
                }

                int a, b;
                char stt[4];
                setfillstyle(SOLID_FILL, LIGHTGRAY);
                setcolor(BLACK);
                setbkcolor(LIGHTGRAY);
                sprintf(stt, "%d", currentPage);
                rectangle(1250, 700, 1300, 730);
                CENTER(a, b, stt, 1250, 700, 1300, 730);
                outtextxy(a,b, stt);
                }
                int dau = (currentPage - 1) * 7;
                int cuoi = dau + 7;
                int sosanh;
                int  k = 50;
                for (int i = 0; i < 7; i++) {
                    bar(101, 281 + k, 199, 329 + k);
                    bar(199, 281 + k, 749, 329 + k);
                    bar(751, 281 + k, 1049, 329 + k);
                    bar(1051, 281 + k, 1349, 329 + k);
                    k = k + 50;
                }
                if (checknhap == false) {
                    inalldsKH(root, currentPage, 50 , dem, sosanh, dau, cuoi);
                    dem = 0;
                } else {
                    bar(1200, 700, 1360, 740);
                    inMotKH(q, dem);
                    dem = 0;
                }
                
                if (currentPage > 1 && checknhap == false) {
                setcolor(BLACK);
                char trai[] = "<";
                rectangle(1200, 700, 1250, 730);
                CENTER(a, b, trai, 1200, 700, 1250, 730);
                outtextxy(a, b, trai);
                }
                if (currentPage < numPages && checknhap == false) {
                    setcolor(BLACK);
                    char phai[] = ">";
                    rectangle(1300, 700, 1350, 730);
                    CENTER(a, b, phai, 1300, 700, 1350, 730);
                    outtextxy(a, b, phai);
                }
                settextstyle(BOLD_FONT, HORIZ_DIR, 1);
                setfillstyle(SOLID_FILL, LIGHTGRAY);
                setcolor(BLACK);
                setbkcolor(LIGHTGRAY);
                int x = mousex();
                int y = mousey();
                while (!ismouseclick(WM_LBUTTONDOWN)) {
                delay(100);
                } 
                getmouseclick(WM_LBUTTONDOWN, x, y);
                if (x >= 1200 && x <= 1250 && y >= 700 && y <= 750 && currentPage > 1 && checknhap == false) {
                    currentPage--;
                } else if (x >= 1300 && x <= 1350 && y >= 700 && y <= 750 && currentPage < numPages&& checknhap == false) {
                    currentPage++;
                }// nut nhap cmnd
                else if (y >= 180 && y <= 230 && x >= 160 && x <= 420) {
                    bar(160,231, 600, 260);
                    khungText(160, 180, 420, 230,12, So, trong, CMND, x, y);
                    if (strcmp(CMND, trong) != 0) {
                        q = timKiemKH(root, CMND);
                        if (q != NULL) {
                            checknhap = true;
                        } else {
                            char baoloi[] = "*Khong tim thay khach hang";
			                outtextxy(160 + 10, 230 + 10,baoloi);
                            checknhap = false;
                        }
                    }
                } // nut xoa nhap
                else if (y >= 180 && y<= 230 && x >= 420&& x <= 480) {
                    strcpy(CMND, trong);
                    checknhap = false;
                    khungindsKH();
                }  else if ((y >= 100 && y <= 150 && x >= 20 && x <= 375-20) || (y >= 100 && y <= 150 && x >= 1145 && x <= 1480) || (y >= 100 && y <= 150 && x >= 395 && x <=730)) {
                    thoat = false;
                    nhan = false;
                    break;
                } else if ( y >= 20 && y <= 60 && x >=1320 && x <= 1420) {
                    SaveFileMB(dsMB);
                    SaveFileCB(First);
                    SaveFileVe(First);
                    SaveFileKH(root);
                }
                else if (y >= 20 && y <= 60 && x >= 1440 && x <= 1480) {
                    giaiPhongMB(dsMB);
                    giaiphongCB(First);
                    giaiPhongKH(root);
                    closegraph();
                    return 0;
                }
            }
        }
        // thao tac phan dat huy ve
        if (y >= 100 && y <= 150 && x >= 1145 && x <= 1480 && nhan == true) {
            Doimau(LIGHTPINK, LIGHTPINK, LIGHTPINK, LIGHTBLUE);
            settextstyle(BOLD_FONT, HORIZ_DIR, 1);
            khungindsCB2();
            setfillstyle(SOLID_FILL, LIGHTGRAY);
            setcolor(BLACK);
            rectangle(20,160, 1480, 740);
            bar(21, 161, 1479, 739);
            khungindsCB2();
            char TRONG[] = "";
            int a, b;

            char noidi[17] = "";
            char noiden[17] = "";
            char NAM[5] = "";
            char THANG[3] = "";
            char NGAY[3] = "";

            bool nam = false;
            bool thang = false;
            bool ngay = false;
            bool checksearch = false;
            bool testNam = false;
            bool testThang = false;
            bool testNgay = false;
            bool checkdi = false;
            bool checkden = false;

            rectangle(140, 180, 420, 230);

            // phan trang chuyen bay trong ngay
            int itemsPerPage = 7;

            int currentPage = 1;
            
            int sochuyenbay = 0;
            bool thoat = true;
            int dem = 0;
            
            NODECBPTR q;
            while (thoat == true) {
                int numPages;
                if (checksearch == true) {
                    khungindsCB2();
                    setfillstyle(SOLID_FILL, LIGHTGRAY);
                    bar(40, 251 , 1460, 271);
                    // Tổng số trang
                    if (sochuyenbay % itemsPerPage != 0 )
                    {
                        numPages = sochuyenbay / itemsPerPage + 1;
                    } else {
                        numPages = sochuyenbay / itemsPerPage;
                    }

                    int a, b;
                    char stt[4];
                    setfillstyle(SOLID_FILL, LIGHTGRAY);
                    setcolor(BLACK);
                    setbkcolor(LIGHTGRAY);
                    sprintf(stt, "%d", currentPage);
                    rectangle(1250, 700, 1300, 730);
                    CENTER(a, b, stt, 1250, 700, 1300, 730);
                    outtextxy(a,b, stt);
                    if (currentPage > 1) {
                    char trai[] = "<";
                    rectangle(1200, 700, 1250, 730);
                    CENTER(a, b, trai, 1200, 700, 1250, 730);
                    outtextxy(a, b, trai);
                    }
                    if (currentPage < numPages) {
                        char phai[] = ">";
                        rectangle(1300, 700, 1350, 730);
                        CENTER(a, b, phai, 1300, 700, 1350, 730);
                        outtextxy(a, b, phai);
                    }
                    inCBconVe(First, -1, currentPage , NGAY, THANG, NAM, noidi, noiden);
                    dem = 0;
                    for (q; q != NULL && dem < (currentPage - 1) * 7; q = q->next) {
                        if (strcmp(q->cb.noiDi, noidi) == 0 && strcmp(q->cb.noiDen, noiden) == 0
                        && q->cb.time_xp.ngay == stoi(NGAY) && q->cb.time_xp.thang == stoi(THANG) && q->cb.time_xp.nam == stoi(NAM) && (q->cb.Trang_thai == CON_VE || q->cb.Trang_thai == HET_VE)) {
                            dem++;
                        }
                    }
                    dem = (currentPage - 1) * 7;
                    if (sochuyenbay == 0) {
                        setfillstyle(SOLID_FILL, LIGHTGRAY);
                        setcolor(BLACK);
                        char baoloi[] = "*Khong co chuyen bay nao!";
                        bar(40, 251 , 1460, 271);
                        CENTER(a, b, baoloi, 40, 251 , 1460, 271);
                        outtextxy(a, b, baoloi);
                    }
                }
                settextstyle(BOLD_FONT, HORIZ_DIR, 1);
                setfillstyle(SOLID_FILL, LIGHTGRAY);
                setcolor(BLACK);
                setbkcolor(LIGHTGRAY);
                bar(141, 181, 419, 229);
                bar(531, 181, 809, 229);
                bar(951, 181, 1029, 229);
                bar(1051, 181, 1099, 229);
                bar(1121, 181, 1169, 229);
                outtextxy(1120 + 10, 180 + 15, NGAY);
                outtextxy(1050 + 10, 180 + 15, THANG);
                outtextxy(950 + 10, 180 + 15, NAM);
                outtextxy(530 + 10, 180 + 15, noiden);
                outtextxy(140 + 10, 180 + 15, noidi);
                // Chờ sự kiện nhấn nút
                int x = mousex();
                int y = mousey();
                while (!ismouseclick(WM_LBUTTONDOWN)) {
                delay(100);
                } 
                getmouseclick(WM_LBUTTONDOWN, x, y);
                if (x >= 1200 && x <= 1250 && y >= 700 && y <= 750 && currentPage > 1) {
                    currentPage--;
                } else if (x >= 1300 && x <= 1350 && y >= 700 && y <= 750 && currentPage < numPages) {
                    currentPage++;
                } else if (y >= 180 && y <= 230 && x >= 140 && x <= 420) {
                    bar(50,235, 1450, 270);
                    khungText(140, 180, 420, 230, 16, 1, TRONG, noidi, x, y);
                    rectangle(140, 180, 420, 230);
                    if (strcmp(noidi, TRONG) == 0) {
                        checkdi = false;
                    } else {
                        checkdi = true;
                        checksearch = false;
                    }
                } else if (y >= 180 && y <= 230 && x >= 530 && x <= 810) {
                    bar(50,235, 1450, 270);
                    khungText(530, 180, 810, 230, 16, 1, TRONG, noiden, x, y);
                    rectangle(530, 180, 810, 230);
                    if (strcmp(noiden, TRONG) == 0) {
                        checkden = false;
                    } else {
                        checkden = true;
                        checksearch = false;
                    }
                } else if (y >= 180 && y <= 230 && x >= 950 && x <= 1170){
                    bar(50,235, 1450, 270);
                    testNam = false;
                    testThang = false;
                    testNgay = false;
                    if (tm_now->tm_mday >= 3 && tm_now->tm_mon + 1 == 12){
                        khungText(950, 180, 1030, 230, 4, 3, TRONG, NAM, x, y);
                        rectangle(950, 180, 1030, 230);
                        if (strcmp(NAM, TRONG) != 0 && checkNam(NAM, tm_now, 1) == true){
                            testNam = true;
                        }
                        while (testNam == false){
                            char tb[] = "*Nam khong hop le";
                            setfillstyle(1,7);
                            bar (950, 180+60, 1030+100, 230+10);
                            outtextxy(950+10, 180+60, tb);
                            khungText(950, 180, 1030, 230, 4, 3, TRONG, NAM, x, y);
                            rectangle(950, 180, 1030, 230);
                            if (strcmp(NAM, TRONG) != 0 && checkNam(NAM, tm_now, 1) == true){
                            testNam = true;
                        }
                        }
                        setfillstyle(1,7);
                        bar (950, 180+60, 1030+100, 230+10);
                        khungText(1050, 180, 1100, 230, 2, 3, TRONG, THANG, x, y);
                        rectangle(1050, 180, 1100, 230);
                        if (strcmp(THANG, TRONG) != 0 && checkThang(THANG, NAM, tm_now, 1)){
                            testThang = true;
                        }
                        while(testThang == false){
                            char tb[] = "*Thang khong hop le";
                            setfillstyle(1,7);
                            bar (1050, 180+60, 1100+100, 230+10);
                            outtextxy(1050+10, 180+60, tb);
                            khungText(1050, 180, 1100, 230, 2, 3, TRONG, THANG, x, y);
                            rectangle(1050, 180, 1100, 230);
                            if (strcmp(THANG, TRONG) != 0 && checkThang(THANG, NAM, tm_now, 1)== true){
                            testThang = true;
                        }
                        }
                        setfillstyle(1,7);
                        bar (1050, 180+60, 1100+100, 230+10);
                        khungText(1120, 180, 1170, 230, 2, 3, TRONG, NGAY, x, y);
                        rectangle(1120, 180, 1170, 230);
                        if (strcmp(NGAY, TRONG) != 0 && checkNgay(NAM, THANG, NGAY, tm_now, 1)== true){
                            testNgay = true;
                        }
                        while(testNgay == false){
                            char tb[] = "*Ngay khong hop le";
                            setfillstyle(1,7);
                            bar (1120, 180+60, 1170+100, 230+10);
                            outtextxy(1120+10, 180+60, tb);
                            khungText(1120, 180, 1170, 230, 2, 3, TRONG, NGAY, x, y);
                            rectangle(1120, 180, 1170, 230);
                            if (strcmp(NGAY, TRONG) != 0 && checkNgay(NAM, THANG, NGAY, tm_now, 1)== true){
                                testNgay = true;
                        }
                        }
                        setfillstyle(1,7);
                        bar (1120, 180+60, 1170+100, 230+10);
                    } else if ((tm_now->tm_mon + 1 < 12) || (tm_now->tm_mday < 3 && tm_now->tm_mon + 1 == 12)){
                        khungText(950, 180, 1030, 230, 4, 3, TRONG, NAM, x, y);
                        rectangle(950, 180, 1030, 230);
                        if (strcmp(NAM, TRONG) != 0 && checkNam(NAM, tm_now, 2) == true){
                            testNam = true;
                        }
                        while (testNam == false){
                            char tb[] = "*Nam khong hop le";
                            setfillstyle(1,7);
                            bar (950, 180+60, 1030+100, 230+10);
                            outtextxy(950+10, 180+60, tb);
                            khungText(950, 180, 1030, 230, 4, 3, TRONG, NAM, x, y);
                            rectangle(950, 180, 1030, 230);
                            if (strcmp(NAM, TRONG) != 0 && checkNam(NAM, tm_now, 2) == true){
                                testNam = true;
                            }
                        }
                        setfillstyle(1,7);
                        bar (950, 180+60, 1030+100, 230+10);
                        khungText(1050, 180, 1100, 230, 2, 3, TRONG, THANG, x, y);
                        rectangle(1050, 180, 1100, 230);
                        if (strcmp(THANG, TRONG) != 0 && checkThang(THANG, NAM, tm_now, 2)){
                            testThang = true;
                        }
                        while(testThang == false){
                            char tb[] = "*Thang khong hop le";
                            setfillstyle(1,7);
                            bar (1050, 180+60, 1100+100, 230+10);
                            outtextxy(1050+10, 180+60, tb);
                            khungText(1050, 180, 1100, 230, 2, 3, TRONG, THANG, x, y);
                            rectangle(1050, 180, 1100, 230);
                            if (strcmp(THANG, TRONG) != 0 && checkThang(THANG, NAM, tm_now, 2)== true){
                                testThang = true;
                            }
                        }
                        setfillstyle(1,7);
                        bar (1050, 180+60, 1100+100, 230+10);
                        khungText(1120, 180, 1170, 230, 2, 3, TRONG, NGAY, x, y);
                        rectangle(1120, 180, 1170, 230);
                        if (strcmp(NGAY, TRONG) != 0 && checkNgay(NAM, THANG, NGAY, tm_now, 2)== true){
                            testNgay = true;
                        }
                        while(testNgay == false){
                            char tb[] = "*Ngay khong hop le";
                            setfillstyle(1,7);
                            bar (1120, 180+60, 1170+100, 230+10);
                            outtextxy(1120+10, 180+60, tb);
                            khungText(1120, 180, 1170, 230, 2, 3, TRONG, NGAY, x, y);
                            rectangle(1120, 180, 1170, 230);
                            if (strcmp(NGAY, TRONG) != 0 && checkNgay(NAM, THANG, NGAY, tm_now, 2)== true){
                                testNgay = true;
                            }
                        }
                        setfillstyle(1,7);
                        bar (1120, 180+60, 1170+100, 230+10);
                    }
                    checksearch = false;
                } else if (y >= 180 && y <= 230 && x >= 1280 && x <= 1440 && testNam == true && testNgay == true && testThang == true && checkdi == true && checkden == true && checksearch == false){
                    bar(50,235, 1450, 270);
                    sochuyenbay = 0;
                    for (q = First; q != NULL; q = q->next) {
                        if (strcmp(q->cb.noiDi, noidi) == 0 && strcmp(q->cb.noiDen, noiden) == 0
                            && q->cb.time_xp.ngay == stoi(NGAY) && q->cb.time_xp.thang == stoi(THANG) && q->cb.time_xp.nam == stoi(NAM) && (q->cb.Trang_thai == CON_VE || q->cb.Trang_thai == HET_VE)) {
                            sochuyenbay++;
                        }
                    }
                    checksearch = true;
                } else if (y >= 330 && y <= 380 && x >= 40 && x <= 1460 && checksearch == true && dem < sochuyenbay) {
                    inCBconVe(First, dem, currentPage , NGAY, THANG, NAM, noidi, noiden);
                    bool dung = true;
                    int k = 0;
                    q = First;
                    while (k <= dem) {
                        if (strcmp(q->cb.noiDi, noidi) == 0 && strcmp(q->cb.noiDen, noiden) == 0
                            && q->cb.time_xp.ngay == stoi(NGAY) && q->cb.time_xp.thang == stoi(THANG) && q->cb.time_xp.nam == stoi(NAM) && (q->cb.Trang_thai == CON_VE || q->cb.Trang_thai == HET_VE)) {
                                k++;
                        }
                        if (k <= dem) {
                            q = q->next;
                        }
                    }
                    while(true) {
                        while (!ismouseclick(WM_LBUTTONDOWN)) {
                            delay(100);
                        }
                        getmouseclick(WM_LBUTTONDOWN, x, y);
                        if (y >= 330 && y <= 380 && x >= 1360 && x <= 1440) {
                            indsKHonCB2(q, root);
                            khungindsCB2();
                            break;
                        } else if (y >= 330 && y <= 380 && x >= 1260 && x <= 1340 && q->cb.Trang_thai == CON_VE) {
                            chonchongoi(dsMB,First, q, root, kh);
                            khungindsCB2();
                            break;
                        } else if (y >= 330 && y <= 380 && x >= 40 && x <= 1460){
                            dung = false;
                            break;
                        }
                    }
                } else if (y >= 330 + 50 && y <= 380 + 50 && x >= 40 && x <= 1460 && checksearch == true && dem + 1 < sochuyenbay) {
                    inCBconVe(First, dem + 1, currentPage , NGAY, THANG, NAM, noidi, noiden);
                    bool dung = true;
                    int k = 0;
                    q = First;
                    while (k <= dem + 1) {
                        if (strcmp(q->cb.noiDi, noidi) == 0 && strcmp(q->cb.noiDen, noiden) == 0
                            && q->cb.time_xp.ngay == stoi(NGAY) && q->cb.time_xp.thang == stoi(THANG) && q->cb.time_xp.nam == stoi(NAM) && (q->cb.Trang_thai == CON_VE || q->cb.Trang_thai == HET_VE)) {
                                k++;
                        }
                        if (k <= dem + 1) {
                            q = q->next;
                        }
                    }
                    while(true) {

                        while (!ismouseclick(WM_LBUTTONDOWN)) {
                            delay(100);
                        }
                        getmouseclick(WM_LBUTTONDOWN, x, y);
                        if (y >= 330 + 50 && y <= 380 + 50 && x >= 1360 && x <= 1440 ) {
                            indsKHonCB2(q, root);
                            khungindsCB2();
                            break;
                        } else if (y >= 330  + 50 && y <= 380 + 50 && x >= 1260 && x <= 1340 && q->cb.Trang_thai == CON_VE) {
                            chonchongoi(dsMB, First, q, root, kh);
                            khungindsCB2();
                            break;
                        } else if (y >= 330 + 50 && y <= 380 + 50 && x >= 40 && x <= 1460){
                            dung = false;
                            break;
                        }
                    }
                } else if (y >= 330  + 100 && y <= 380 + 100 && x >= 40 && x <= 1460 && checksearch == true && dem + 2 < sochuyenbay) {
                    inCBconVe(First, dem + 2, currentPage , NGAY, THANG, NAM, noidi, noiden);
                    bool dung = true;
                    int k = 0;
                    q = First;
                    while (k <= dem + 2) {
                        if (strcmp(q->cb.noiDi, noidi) == 0 && strcmp(q->cb.noiDen, noiden) == 0
                            && q->cb.time_xp.ngay == stoi(NGAY) && q->cb.time_xp.thang == stoi(THANG) && q->cb.time_xp.nam == stoi(NAM) && (q->cb.Trang_thai == CON_VE || q->cb.Trang_thai == HET_VE)) {
                                k++;
                        }
                        if (k <= dem + 2) {
                            q = q->next;
                        }
                    }
                    while(true) {

                        while (!ismouseclick(WM_LBUTTONDOWN)) {
                            delay(100);
                        }
                        getmouseclick(WM_LBUTTONDOWN, x, y);
                        if (y >= 330 + 100 && y <= 380 + 100 && x >= 1360 && x <= 1440 ) {
                            indsKHonCB2(q, root);
                            khungindsCB2();
                            break;
                        }  else if (y >= 330 + 100 && y <= 380 + 100 && x >= 1260 && x <= 1340 && q->cb.Trang_thai == CON_VE) {
                            chonchongoi(dsMB,First, q, root, kh);
                            khungindsCB2();
                            break;
                        }else if (y >= 330 + 100 && y <= 380 + 100 && x >= 40 && x <= 1460){
                            dung = false;
                            break;
                        }
                    }
                } else if (y >= 330 + 150 && y <= 380 + 150 && x >= 40 && x <= 1460 && checksearch == true && dem + 3 < sochuyenbay) {
                    inCBconVe(First, dem + 3, currentPage , NGAY, THANG, NAM, noidi, noiden);
                    bool dung = true;
                    int k = 0;
                    q = First;
                    while (k <= dem + 3) {
                        if (strcmp(q->cb.noiDi, noidi) == 0 && strcmp(q->cb.noiDen, noiden) == 0
                            && q->cb.time_xp.ngay == stoi(NGAY) && q->cb.time_xp.thang == stoi(THANG) && q->cb.time_xp.nam == stoi(NAM) && (q->cb.Trang_thai == CON_VE || q->cb.Trang_thai == HET_VE)) {
                                k++;
                        }
                        if (k <= dem + 3) {
                            q = q->next;
                        }
                    }
                    while(true) {

                        while (!ismouseclick(WM_LBUTTONDOWN)) {
                            delay(100);
                        }
                        getmouseclick(WM_LBUTTONDOWN, x, y);
                        if (y >= 330 + 150 && y <= 380 + 150 && x >= 1360 && x <= 1440 ) {
                            indsKHonCB2(q, root);
                            khungindsCB2();
                            break;
                        } else if (y >= 330 + 150 && y <= 380 + 150 && x >= 1260 && x <= 1340 && q->cb.Trang_thai == CON_VE) {
                            chonchongoi(dsMB,First, q, root, kh);
                            khungindsCB2();
                            break;
                        }else if (y >= 330 + 150 && y <= 380 + 150  && x >= 40 && x <= 1460){
                            dung = false;
                            break;
                        }
                    }
                } else if (y >= 330 + 200 && y <= 380 + 200 && x >= 40 && x <= 1460 && checksearch == true && dem + 4 < sochuyenbay) {
                    inCBconVe(First, dem + 4, currentPage , NGAY, THANG, NAM, noidi, noiden);
                    bool dung = true;
                    int k = 0;
                    q = First;
                    while (k <= dem + 4) {
                        if (strcmp(q->cb.noiDi, noidi) == 0 && strcmp(q->cb.noiDen, noiden) == 0
                            && q->cb.time_xp.ngay == stoi(NGAY) && q->cb.time_xp.thang == stoi(THANG) && q->cb.time_xp.nam == stoi(NAM) && (q->cb.Trang_thai == CON_VE || q->cb.Trang_thai == HET_VE)) {
                                k++;
                        }
                        if (k <= dem + 4) {
                            q = q->next;
                        }
                    }
                    while(true) {

                        while (!ismouseclick(WM_LBUTTONDOWN)) {
                            delay(100);
                        }
                        getmouseclick(WM_LBUTTONDOWN, x, y);
                        if (y >= 330 + 200 && y <= 380 + 200 && x >= 1360 && x <= 1440 ) {
                            indsKHonCB2(q, root);
                            khungindsCB2();
                            break;
                        } else if (y >= 330 + 200 && y <= 380 + 200 && x >= 1260 && x <= 1340 && q->cb.Trang_thai == CON_VE) {
                            chonchongoi(dsMB,First, q, root, kh);
                            khungindsCB2();
                            break;
                        } else if (y >= 330 + 200 && y <= 380 + 200 && x >= 40 && x <= 1460){
                            dung = false;
                            break;
                        }
                    }
                } else if (y >= 330 + 250 && y <= 380 + 250 && x >= 40 && x <= 1460 && checksearch == true && dem + 5 < sochuyenbay) {
                    inCBconVe(First, dem + 5, currentPage , NGAY, THANG, NAM, noidi, noiden);
                    bool dung = true;
                    int k = 0;
                    q = First;
                    while (k <= dem + 5) {
                        if (strcmp(q->cb.noiDi, noidi) == 0 && strcmp(q->cb.noiDen, noiden) == 0
                            && q->cb.time_xp.ngay == stoi(NGAY) && q->cb.time_xp.thang == stoi(THANG) && q->cb.time_xp.nam == stoi(NAM) && (q->cb.Trang_thai == CON_VE || q->cb.Trang_thai == HET_VE)) {
                                k++;
                        }
                        if (k <= dem + 5) {
                            q = q->next;
                        }
                    }
                    while(true) {

                        while (!ismouseclick(WM_LBUTTONDOWN)) {
                            delay(100);
                        }
                        getmouseclick(WM_LBUTTONDOWN, x, y);
                        if (y >= 330 +250 && y <= 380 +250 && x >= 1360 && x <= 1440 ) {
                            indsKHonCB2(q, root);
                            khungindsCB2();
                            break;
                        } else if (y >= 330 + 250 && y <= 380 + 250 && x >= 1260 && x <= 1340 && q->cb.Trang_thai == CON_VE) {
                            chonchongoi(dsMB,First, q, root, kh);
                            khungindsCB2();
                            break;
                        }else if (y >= 330+ 250 && y <= 380 + 250 && x >= 40 && x <= 1460){
                            dung = false;
                            break;
                        }
                    }
                } else if (y >= 330 + 300 && y <= 380 + 300 && x >= 40 && x <= 1460 && checksearch == true && dem + 6 < sochuyenbay) {
                    inCBconVe(First, dem + 6, currentPage , NGAY, THANG, NAM, noidi, noiden);
                    bool dung = true;
                    int k = 0;
                    q = First;
                    while (k <= dem + 6) {
                        if (strcmp(q->cb.noiDi, noidi) == 0 && strcmp(q->cb.noiDen, noiden) == 0
                            && q->cb.time_xp.ngay == stoi(NGAY) && q->cb.time_xp.thang == stoi(THANG) && q->cb.time_xp.nam == stoi(NAM) && (q->cb.Trang_thai == CON_VE || q->cb.Trang_thai == HET_VE)) {
                                k++;
                        }
                        if (k <= dem + 6) {
                            q = q->next;
                        }
                    }
                    while(true) {
                        while (!ismouseclick(WM_LBUTTONDOWN)) {
                            delay(100);
                        }
                        getmouseclick(WM_LBUTTONDOWN, x, y);
                        if (y >= 330 + 300 && y <= 380 + 300 && x >= 1360 && x <= 1440 ) {
                            indsKHonCB2(q, root);
                            khungindsCB2();
                            break;
                        } else if (y >= 330 + 300 && y <= 380 + 300 && x >= 1260 && x <= 1340 && q->cb.Trang_thai == CON_VE) {
                            chonchongoi(dsMB,First, q, root, kh);
                            khungindsCB2();
                            break;
                        } else if (y >= 330 + 300 && y <= 380 + 300 && x >= 40 && x <= 1460){
                            dung = false;
                            break;
                        }
                    }
                } else if ((y >= 100 && y <= 150 && x >= 20 && x <= 375-20) || (y >= 100 && y <= 150 && x >= 770 && x <= 1105) || (y >= 100 && y <= 150 && x >= 395 && x <=730) ) {
                    thoat = false;
                    nhan = false;
                    break;
                } else if ( y >= 20 && y <= 60 && x >=1320 && x <= 1420) {
                    SaveFileMB(dsMB);
                    SaveFileCB(First);
                    SaveFileVe(First);
                    SaveFileKH(root);
                }
                else if (y >= 20 && y <= 60 && x >= 1440 && x <= 1480) {
                    giaiPhongMB(dsMB);
                    giaiphongCB(First);
                    giaiPhongKH(root);
                    closegraph();
                    return 0;
                }
                updatettmb(dsMB, tm_now, First);
                updatett(dsMB, First,tm_now);
            }
	    }
        // luu toan bo file
        else if ( y >= 20 && y <= 60 && x >=1320 && x <= 1420 && nhan == true) {
            SaveFileMB(dsMB);
            SaveFileCB(First);
            SaveFileVe(First);
            SaveFileKH(root);
        }
        // thoat chương trinh
        else if (y >= 20 && y <= 60 && x >= 1440 && x <= 1480 && nhan == true) {
            giaiPhongMB(dsMB);
            giaiphongCB(First);
            giaiPhongKH(root);
            closegraph();
            return 0;
        }
    }
    getch();
    closegraph();
    return 0;
}