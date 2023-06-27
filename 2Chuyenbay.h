void upper1(char* str){
	for (int i = 0; i < (int)strlen(str); i++){
	    str[i] = toupper(str[i]);
    }
}
// ham khoi tao danh sach lien ket don chuyen bay
void startUp (NODECBPTR& First) { // Thanh
    First = NULL;
}

//Kiem tra danh sach chuyen bay co rong
bool Empty(NODECBPTR First) { // Thanh
    return(First == NULL ? true: false);
}

//kiem tra ma chuyen bay co ton tai
NODECBPTR check_CB(NODECBPTR First, char maCB[]) {
    NODECBPTR p = First;
    while(p != NULL) {  
        if (strcmp(p->cb.maCB, maCB) == 0) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}
// code kiem tra thoi gian
bool checkTimeonDay(TIME time_xp, tm* tm_now) { 
    if (time_xp.nam == tm_now->tm_year + 1900 && time_xp.thang == 1 + tm_now->tm_mon && time_xp.ngay == tm_now->tm_mday) {
        int minuteDiff = (time_xp.gio - tm_now->tm_hour) * 60 + time_xp.phut - tm_now->tm_min;
        if (minuteDiff >= 0) {
            return true;
        }
    }
    return false;
}
bool checkTimeALL(TIME time_xp, tm* tm_now) { 

    if ((time_xp.nam > tm_now->tm_year + 1900)|| 
    (time_xp.nam == tm_now->tm_year + 1900 && time_xp.thang > tm_now->tm_mon + 1)||
    (time_xp.nam == tm_now->tm_year + 1900 && time_xp.thang == tm_now->tm_mon + 1 && time_xp.ngay > tm_now->tm_mday)) {
        return true;
    }
    if (checkTimeonDay(time_xp,tm_now) == true) {
        return true;
    }
    return false;
}
bool checkCalendar(char nam[], char thang[], char ngay[]){ 
    if ((stoi(thang) == 1 || stoi(thang) == 3 || stoi(thang) == 5 || stoi(thang) == 7 || stoi(thang) == 8 || stoi(thang) == 10 || stoi(thang) == 12) && (stoi(ngay) >= 1 && stoi(ngay) <= 31)){
        return true;
    } else if ((stoi(thang) == 4 || stoi(thang) == 6 || stoi(thang) == 9 || stoi(thang) == 11) && (stoi(ngay) >= 1 && stoi(ngay) <= 30)){
        return true;
    } else if ((stoi(thang) == 2) && (stoi(nam) % 4 == 0) && (stoi(ngay) >= 1 && stoi(ngay) <= 29)){
        return true;
    } else if ((stoi(thang) == 2) && (stoi(nam) % 4 != 0) && (stoi(ngay) >= 1 && stoi(ngay) <= 28)){
        return true;
    } else return false;
}
bool checkNam(char nam[], tm *tm_now, int i){ 
    if (i == 1){
        if (stoi(nam) == tm_now->tm_year + 1900 || stoi(nam) == tm_now->tm_year + 1901) {
            return true;
        }
    }
    if (i == 2){
        if (stoi(nam) == tm_now->tm_year + 1900) {
            return true;
        } 
    } 
    return false;
}
bool checkThang(char thang[], char nam[], tm*tm_now, int i){ 
    if (i == 1){
        if (stoi(nam) == tm_now->tm_year+1900 && stoi(thang) == 12){
            return true;
        } 
        if (stoi(nam) == tm_now->tm_year +1901 && stoi(thang) == 1){
            return true;
        }
    } else if (i == 2){
        if (stoi(thang) == tm_now->tm_mon+1 || stoi(thang) == tm_now->tm_mon+2 ){
            return true;
        }
    } return false;
}
bool checkNgay(char nam[], char thang[], char ngay[], tm*tm_now, int i){ 
    if (i == 1){
        if(stoi(thang) == 12 && stoi(ngay) >= tm_now->tm_mday){
            return true;
        }
        if (stoi(thang) == 1 && (31 - tm_now->tm_mday + stoi(ngay))<=30){
            return true;
        }
    } else if(i==2){
        if(stoi(thang)== tm_now->tm_mon + 1 && stoi(ngay) >= tm_now->tm_mday && checkCalendar(nam, thang, ngay) == true){
            return true;
        }
        if(stoi(thang) == tm_now->tm_mon + 2){
            if ((stoi(thang) == 1 || stoi(thang) == 3 || stoi(thang) == 5 || stoi(thang) == 7 || stoi(thang) == 8 || stoi(thang) == 10 || stoi(thang) == 12) && (31 - tm_now->tm_mday + stoi(ngay)<=30)){
                return true;
            }
            if ((stoi(thang) == 4 || stoi(thang) == 6 || stoi(thang) == 9 || stoi(thang) == 11) && (30 - tm_now->tm_mday + stoi(ngay)<=30)){
                return true;
            }
            if ((stoi(thang) == 2) && (29 - tm_now->tm_mday + stoi(ngay)<=30)){
                return true;
            }
        }
    } return false;
}
bool checkGio(CB cb, char gio[], char phut[], tm* tm_now){ 
    if (cb.time_xp.nam == tm_now->tm_year + 1900 && cb.time_xp.thang == 1 + tm_now->tm_mon && cb.time_xp.ngay == tm_now->tm_mday) {
        int minuteDiff = (stoi(gio) - tm_now->tm_hour) * 60 + stoi(phut) - tm_now->tm_min;
        if (minuteDiff >= 120) {
            return true;
        }
    } else {
        if ((stoi(gio) >= 0 && stoi(gio) <= 3 && stoi(phut) >= 0 && stoi(phut) <= 59)){
            return false;
        } return true;
    }
    return false;
}
// kiem trong thoi gian truoc hai tieng va sau hai tieng cua thoi gian nhap may bay co thuc hien chuyen bay nao khong
bool checkPlane(NODECBPTR First, char soHieu[], TIME time_xp) { 
    NODECBPTR p = First;
    while(p != NULL) {  
        if (strcmp(p->cb.soHieuMB, soHieu) == 0) {  // kiểm tra xem máy bay đã được sử dụng trong thời gian này hay chưa
            if (p->cb.Trang_thai == CON_VE || p->cb.Trang_thai == HET_VE) {
                int minuteDis = 0;
                minuteDis = ((p->cb.time_xp.gio - time_xp.gio) *60 + (p->cb.time_xp.phut - time_xp.phut));
                if (minuteDis > -120 && minuteDis < 120
                    && p->cb.time_xp.ngay == time_xp.ngay
                    && p->cb.time_xp.thang == time_xp.thang
                    && p->cb.time_xp.nam == time_xp.nam ) {
                    return false;
                }
            }
        }
        p = p->next;
    }
    return true;
}
// kiem tra chuyen bay cua may bay
bool checkPlaneHC(NODECBPTR First, CB x) { 
    NODECBPTR p = First;
    while(p != NULL) {
        if (strcmp(p->cb.maCB, x.maCB) != 0 && strcmp(p->cb.soHieuMB, x.soHieuMB) == 0) {
            cout << p->cb.maCB << " ";
            int minuteDis = 0;
                minuteDis = ((p->cb.time_xp.gio - x.time_xp.gio) *60 + (p->cb.time_xp.phut - x.time_xp.phut));
                if (minuteDis > -120 && minuteDis < 120
                    && p->cb.time_xp.ngay == x.time_xp.ngay
                    && p->cb.time_xp.thang == x.time_xp.thang
                    && p->cb.time_xp.nam == x.time_xp.nam ) {
                    return false;
                }
        }
        p = p->next;
    }
    return true;
}
// them chuyen bay
void addCB_Order(NODECBPTR &First, CB x) { 
    NODECBPTR p, t, s;
    p = new nodeCB;
    p->cb = x;
    for (s = First; s != NULL && strcmp(s->cb.maCB, x.maCB) < 0; t = s,s =s->next);
    if (s == First) {
        p->next = First;
        First = p;
    } else {
        p->next = s;
        t->next = p;
    }
}
bool cancelCB(NODECBPTR& q) { 
    if (q->cb.Trang_thai != HUY_CHUYEN && q->cb.Trang_thai != HOANTAT_CB) {
        q->cb.Trang_thai = HUY_CHUYEN;
        return true;
    }
    return false;
}
void updateCB(NODECBPTR& p, CB x) { 
    p->cb.time_xp.gio = x.time_xp.gio;
    p->cb.time_xp.phut = x.time_xp.phut;
    p->cb.time_xp.ngay = x.time_xp.ngay;
    p->cb.time_xp.thang = x.time_xp.thang;
    p->cb.time_xp.nam = x.time_xp.nam;
}

void sapXepCB(NODECBPTR &First) { 
    NODECBPTR p, q, pmin;
    CB min;
    for (p = First; p->next != NULL; p = p->next) {
        min = p->cb;
        pmin = p;
        for (q = p->next; q != NULL; q = q->next) {
            if (strcmp(min.maCB, q->cb.maCB) > 0)
            {
                min = q->cb;
                pmin = q;
            }
        }
        pmin->cb = p->cb;
        p->cb = min;
    }
}
void createTickets(DSMB dsMB, CB& cb , int chiso) { 
    int veIndex = 0;
    for (int i = 0; i < dsMB.data[chiso]->soDay; i++) {
        char col = i + 'A';
        int rows = 0;
        for (int j = 0; j < dsMB.data[chiso]->soDong; j++) {
            int row = j + 1;
            cb.ve[veIndex] = new VE;
            if (row < 10) {
                cb.ve[veIndex]->Ghe_so[0] = col;
                cb.ve[veIndex]->Ghe_so[1] = '0';
                cb.ve[veIndex]->Ghe_so[2] = '0' + row;
                cb.ve[veIndex]->Ghe_so[3] = '\0';
                veIndex++;
            }
            if (row >= 10 && row < 20) {
                cb.ve[veIndex]->Ghe_so[0] = col;
                cb.ve[veIndex]->Ghe_so[1] = '1';
                cb.ve[veIndex]->Ghe_so[2] = '0' + rows;
                cb.ve[veIndex]->Ghe_so[3] = '\0';
                veIndex++;
                rows++;
            }
            if (row == 20) {
                cb.ve[veIndex]->Ghe_so[0] = col;
                cb.ve[veIndex]->Ghe_so[1] = '2';
                cb.ve[veIndex]->Ghe_so[2] = '0';
                cb.ve[veIndex]->Ghe_so[3] = '\0';
                veIndex++;
            }
        }
    }
}
NODECBPTR searchCB(NODECBPTR First, CB x, NODECBPTR& Firsts) { 
    NODECBPTR p = First;
    while (p != NULL) {
        if (p->cb.time_xp.ngay == x.time_xp.ngay && p->cb.time_xp.thang == x.time_xp.thang 
            && p->cb.time_xp.nam == x.time_xp.nam && strcmp(p->cb.noiDen, x.noiDen) == 0 && p->cb.soLuongVe != p->cb.soLuongDatVe) {
            NODECBPTR k, t, s;
            k = new nodeCB;
            k->cb = p->cb;
            k->next = NULL;
            if (Firsts == NULL) {
                Firsts = k;
            } else {
                t = Firsts;
                while (t->next != NULL) {
                    t = t->next;
                }
                t->next = k;
            }
        }
        p = p->next;
    }
    return Firsts;
}

int LoadFileCB(DSMB dsMB, NODECBPTR &First, CB& cb) { 
    ifstream file("dsChuyenBay.txt");
    if (!file.is_open()) {
        return 0;
    }
    NODECBPTR p = First;
    while (file >> cb.maCB) {
        int chiso;
        file >> cb.noiDi; thayDoi(cb.noiDi);
        file >> cb.noiDen; thayDoi(cb.noiDen);
        file >> cb.time_xp.gio; file >> cb.time_xp.phut;
        file >> cb.time_xp.ngay; file >> cb.time_xp.thang; file >> cb.time_xp.nam;
        file >> cb.soHieuMB; 
        file >> cb.soLuongVe; file >> cb.soLuongDatVe;
        file >> cb.Trang_thai;
        checkMB(dsMB, cb.soHieuMB, chiso);
        createTickets(dsMB, cb, chiso);
        addCB_Order(First, cb);
        file.ignore();
    }
    file.close();
    return 1;
}
int LoadFileVe(NODECBPTR& First, VE ve, CB cb) { 
    ifstream file("dsVeChuyenBay.txt");
    if (!file.is_open()) {
        return 0;
    }
    NODECBPTR q;
    while(file >> cb.maCB) { 
        q = check_CB(First, cb.maCB);
        for (int j = 0; j < q->cb.soLuongDatVe; j++){
            file >> ve.Ghe_so;
            for (int i = 0; i < q->cb.soLuongVe; i++) {
                if (strcmp(q->cb.ve[i]->Ghe_so, ve.Ghe_so ) == 0 ) {
                    file >> q->cb.ve[i]->CMND;
                    q->cb.ve[i]->ttVe = DA_DAT;
                }
            }
            file.ignore();
        }
    }
    return 1;
}
int SaveFileCB(NODECBPTR &First) { 
    ofstream file("dsChuyenBay.txt");
    char noidi[16];
    char noiden[16];
    if (!file.is_open()) return 0;

    NODECBPTR p;

    for (p = First; p != NULL; p = p->next) {
        file << setw(16) << left << p->cb.maCB;
        strcpy(noidi,p->cb.noiDi);
        bienDoi(noidi);
        file << setw(16) << left << noidi;
        strcpy(noiden,p->cb.noiDen);
        bienDoi(noiden);
        file << setw(16) << left << noiden;
        file << setw(3)  << left << p->cb.time_xp.gio;
        file << setw(3)  << left << p->cb.time_xp.phut;
        file << setw(3)  << left << p->cb.time_xp.ngay;
        file << setw(3)  << left << p->cb.time_xp.thang;
        file << setw(5) << left << p->cb.time_xp.nam;
        file << setw(16)  << left << p->cb.soHieuMB;
        file << setw(4)  << left << p->cb.soLuongVe;
        file << setw(4)  << left << p->cb.soLuongDatVe;
        file << setw(4) << left << p->cb.Trang_thai;
        file << endl;
    }
    file.close();
    return 1;
}

int SaveFileVe(NODECBPTR& First) {
    ofstream file("dsVeChuyenBay.txt");

    if (!file.is_open()) return 0;
    NODECBPTR p;
    for (p = First; p != NULL; p = p->next) {
        file << p->cb.maCB;
        file << endl;
        for (int i = 0; i < p->cb.soLuongVe; i++){
            if (p->cb.ve[i]->ttVe == DA_DAT) {
                file << setw(4) << left << p->cb.ve[i]->Ghe_so;
                file << setw(13) << left << p->cb.ve[i]->CMND;
                file << endl;
            }
        }
    }
    return 1;
}
void updatesolanbay(DSMB& dsMB, NODECBPTR &First, tm* tm_now) {
    int thoigian;
    int chiso;
    NODECBPTR p = First;
    while(p != NULL) {
        if (p->cb.Trang_thai == HOANTAT_CB) {
            checkMB(dsMB,p->cb.soHieuMB,chiso);
            dsMB.data[chiso]->sl_Bay++;
        }
        p = p->next;
    }
}
void updatett(DSMB& dsMB, NODECBPTR &First, tm* tm_now) { 
    int chiso;
    NODECBPTR p = First;
    while(p != NULL) {
        for (int i = 0; i < dsMB.soMB; i++)
        if (checkMB(dsMB, p->cb.soHieuMB, chiso) == false && p->cb.Trang_thai != HOANTAT_CB) {
            p->cb.Trang_thai = HUY_CHUYEN;
        }
        if (p->cb.Trang_thai == CON_VE && p->cb.soLuongVe == p->cb.soLuongDatVe) {
            p->cb.Trang_thai = HET_VE;
        }
        if (checkTimeALL(p->cb.time_xp,tm_now) == false && p->cb.Trang_thai != HOANTAT_CB && p->cb.soLuongDatVe == 0) {
            p->cb.Trang_thai = HUY_CHUYEN;
        }
        if (checkTimeALL(p->cb.time_xp,tm_now) == false && p->cb.Trang_thai != HUY_CHUYEN && p->cb.soLuongDatVe > 0) {
            p->cb.Trang_thai = HOANTAT_CB;
        }
        if (p->cb.Trang_thai == HET_VE && p->cb.soLuongVe > p->cb.soLuongDatVe) {
            p->cb.Trang_thai = CON_VE;        }
        p = p->next;
    }
}
bool checkcbonMB(DSMB dsMB, NODECBPTR First, int chiso) { 
    NODECBPTR p = First;
    while(p != NULL) {
        if (strcmp(p->cb.soHieuMB, dsMB.data[chiso]->soHieu) == 0 && (p->cb.Trang_thai == CON_VE || p->cb.Trang_thai == HET_VE) && p->cb.soLuongDatVe != 0) {
            return false;
        }
        p = p->next;
    }
    return true;
}
// cap nhat thong tin cua cac chuyen bay khi may bay hieu chinh 
void updatehcmb(DSMB& dsMB, NODECBPTR& First, int chiso, char soHieuMB[],char soHieuCu[], CB cb){ 
    NODECBPTR p = First;
    while(p != NULL) {
        if (strcmp(p->cb.soHieuMB, soHieuCu) == 0 && p->cb.Trang_thai == CON_VE && p->cb.soLuongDatVe == 0) {
            cout << p->cb.maCB << " ";
            cb = p->cb;
            strcpy(cb.soHieuMB, dsMB.data[chiso]->soHieu);
            cb.soLuongVe = dsMB.data[chiso]->soChoNgoi;
            createTickets(dsMB, cb , chiso);
            p->cb = cb;
        }
        p = p->next;
    }
}
//Huy ve
void HuyVE(NODECBPTR& p, int i) { 
    p->cb.ve[i]->CMND[0] = '\0';
    p->cb.ve[i]->ttVe = TRONG;
    p->cb.soLuongDatVe--;
}
// giai phong bo nho
void giaiphongCB(NODECBPTR& First){ 
    NODECBPTR q;
    while(First != NULL) {
        q = First;
        First = First->next;
        delete q;
    }
}
// kiem tra khach hang co dat ve cung thoi gian voi chuyen bay khac khong 
bool checkCMNDALLCB(NODECBPTR First, NODECBPTR q, char CMND[]) {
    NODECBPTR p = First;
    while(p != NULL) {
        if (strcmp(p->cb.maCB, q->cb.maCB) != 0 && (p->cb.Trang_thai == CON_VE || p->cb.Trang_thai == HET_VE)) {
            cout << p->cb.maCB << " ";
            int minuteDis = 0;
                minuteDis = ((p->cb.time_xp.gio - q->cb.time_xp.gio) *60 + (p->cb.time_xp.phut - q->cb.time_xp.phut));
                if (minuteDis > -120 && minuteDis < 120
                    && p->cb.time_xp.ngay == q->cb.time_xp.ngay
                    && p->cb.time_xp.thang == q->cb.time_xp.thang
                    && p->cb.time_xp.nam == q->cb.time_xp.nam ) {
                        for(int i = 0; i < p->cb.soLuongVe; i++) {
                            if (strcmp(p->cb.ve[i]->CMND, CMND) == 0) {
                                return false;
                            }
                        }
                }
        }
        p = p->next;
    }
    return true;

}