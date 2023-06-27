// May bay: Dat
void bienDoi(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            str[i] = '_';
        }
    }
}
void thayDoi(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '_') {
            str[i] = ' ';
        }
    }
}
// Ham may bay
bool checkMBFULL(int soMayBay)
{
    if (soMayBay <= MAX_MAYBAY) {
        return true;
    }
    return false;
}
// kiem tra may bay co ton tai
bool checkMB(DSMB dsMB, char soHieuMB[], int& chiso)
{
    for (int i = 0; i < dsMB.soMB; i++) {
        if (strcmp(dsMB.data[i]->soHieu, soHieuMB) == 0) {
            chiso = i;
            return true;
        }
    }
    return false;
}
// kiem tra so hieu cho phan hieu chinh
bool checkMBngoaichiso(DSMB dsMB, char soHieuMB[], int& chiso)
{
    for (int i = 0; i < dsMB.soMB; i++) {
        if (strcmp(dsMB.data[i]->soHieu, soHieuMB) == 0 && i != chiso) {
            return true;
        }
    }
    return false;
}
// them may bay
void addMB(DSMB& dsMB, char soHieuMB[], char loaiMB[], int soDayMB, int soDongMB, int soChoNgoiMB, int chiso)
{
    dsMB.data[dsMB.soMB] = new MB;
    strcpy(dsMB.data[dsMB.soMB]->soHieu, soHieuMB);
    strcpy(dsMB.data[dsMB.soMB]->loai, loaiMB);
    dsMB.data[dsMB.soMB]->soDay = soDayMB;
    dsMB.data[dsMB.soMB]->soDong = soDongMB;
    dsMB.data[dsMB.soMB]->soChoNgoi = soChoNgoiMB;
    dsMB.soMB++;
}
// xoa may bay
void deleteMB(DSMB& dsMB,NODECBPTR &First, int chiso) {
    NODECBPTR q;
    for (q = First ; q != NULL; q = q->next) {
        if (q->cb.soHieuMB == dsMB.data[chiso]->soHieu) {
            if (q->cb.Trang_thai != HOANTAT_CB) {
                q->cb.Trang_thai = HUY_CHUYEN;
            }
        }
    }
    delete dsMB.data[chiso];
    for (int j = chiso; j < dsMB.soMB - 1; j++) {
        dsMB.data[j] = dsMB.data[j + 1];
    }
    dsMB.soMB--;
}
// sap xep may bay
int Partition(MB* arr[], int left, int right, int field) {
    MB* pivot = arr[left]; // Chọn pivot là phần tử đầu tiên của mảng
    int i = left + 1; // Chỉ số của phần tử đầu tiên lớn hơn pivot
    int j = right; // Chỉ số của phần tử cuối nhỏ hơn pivot

    if (field == 0) { // sap xep may bay theo so hieu
        while (i <= j) {
            // Tìm phần tử đầu tiên lớn hơn pivot và nếu phần từ đầu tiên lớn hơn thì dừng lặp
            while (i <= j && strcmp(arr[i]->soHieu, pivot->soHieu) < 0) {
                i++;
            }
            // Tìm phần tử đầu tiên nhỏ hơn pivot và nếu phần từ đầu tiên bé hơn thì dừng lặp
            while (i <= j && strcmp(arr[j]->soHieu, pivot->soHieu) > 0) {
                j--;
            }
            // Đổi chỗ hai phần tử tìm được
            if (i <= j) {
                MB* temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }
    }
    if (field == 1) { // sap xep may bay theo so lan bay cho phan thong ke
        while (i <= j) {
            // Tìm phần tử đầu tiên lớn hơn pivot và nếu phần từ đầu tiên lớn hơn thì dừng lặp
            while (i <= j && arr[i]->sl_Bay >  pivot->sl_Bay) {
                i++;
            }
            // Tìm phần tử đầu tiên nhỏ hơn pivot và nếu phần từ đầu tiên bé hơn thì dừng lặp
            while (i <= j && arr[j]->sl_Bay <  pivot->sl_Bay) {
                j--;
            }
            // Đổi chỗ hai phần tử tìm được
            if (i <= j) {
                MB* temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }
    }
    // Đưa pivot về đúng vị trí
    MB* temp = arr[left];
    arr[left] = arr[j];
    arr[j] = temp;

    return j; // Trả về chỉ số của pivot
}
void Quick_Sort(MB* arr[], int left, int right, int field) {
    if (left < right) {
        int pivot_index = Partition(arr, left, right, field); // Phân hoạch mảng và lấy chỉ số của pivot
        Quick_Sort(arr, left, pivot_index - 1, field); // Đệ quy sắp xếp các phần tử trước pivot
        Quick_Sort(arr, pivot_index + 1, right, field); // Đệ quy sắp xếp các phần tử sau pivot
    }
}
// cap nhat thong tin may bay
void UpdateMB(DSMB& dsMB, char soHieuMB[], char loaiMB[], int soDayMB, int soDongMB, int soChoNgoiMB, int chiso) {
    strcpy(dsMB.data[chiso]->soHieu, soHieuMB);
    strcpy(dsMB.data[chiso]->loai, loaiMB);
    dsMB.data[chiso]->soDay = soDayMB;
    dsMB.data[chiso]->soDong = soDongMB;
    dsMB.data[chiso]->soChoNgoi = soDayMB * soDongMB;
}
// doc may bay tu file
int LoadFileMB(DSMB &dsMB) {
    ifstream file("dsMayBay.txt");
    if (!file.is_open()) { return 0; }   
    file >> dsMB.soMB;
    file.ignore();
    for (int i = 0; i < dsMB.soMB; i++) {
        dsMB.data[i] = new MB;
        file >> dsMB.data[i]->soHieu;
        file >> dsMB.data[i]->loai;
        thayDoi(dsMB.data[i]->loai);
        file >> dsMB.data[i]->soDay;
        file >> dsMB.data[i]->soDong;
        dsMB.data[i]->soChoNgoi = dsMB.data[i]->soDay * dsMB.data[i]->soDong;
        file >> dsMB.data[i]->trangThai;
        file.ignore();
    }
    Quick_Sort(dsMB.data, 0, dsMB.soMB - 1, 0);
    file.close();
    return 1;
}
// luu file may bay
int SaveFileMB(DSMB dsMB) {
    ofstream file("dsMayBay.txt");

    if (!file.is_open()) return 0;
    char loai[41];
    file << dsMB.soMB << endl;

    for (int i = 0; i < dsMB.soMB; i++) {
        file << setw(17) << left << dsMB.data[i]->soHieu;
        strcpy(loai,dsMB.data[i]->loai);
        bienDoi(loai);
        file << setw(42) << left << loai;
        file << setw(2) << left << dsMB.data[i]->soDay;
        file << setw(3) << left << dsMB.data[i]->soDong;
        file << setw(5) << left << dsMB.data[i]->trangThai;
        file << endl;
    }
    file.close();
    return 1;
}
// cap nhat thong tin may bay theo thoi gian
void updatettmb(DSMB& dsMB, tm* tm_now, NODECBPTR First) {
    NODECBPTR q;
    int thoigian;
    for (int i = 0; i < dsMB.soMB; i++) {
        q = First;
        for(q ; q != NULL; q = q->next) {
            thoigian = (((q->cb.time_xp.gio + 2) - tm_now->tm_hour) * 60 + (q->cb.time_xp.phut - tm_now->tm_min));
            if (q->cb.Trang_thai == HOANTAT_CB && thoigian >= 0 && thoigian <= 120 && q->cb.soHieuMB == dsMB.data[i]->soHieu && q->cb.time_xp.ngay == tm_now->tm_mday && q->cb.time_xp.thang == tm_now->tm_mon && q->cb.time_xp.nam == tm_now->tm_year) {
                    dsMB.data[i]->trangThai = DANG_HOAT_DONG;
            }
            if (q->cb.Trang_thai == HOANTAT_CB && thoigian < 0 && thoigian > 120 && q->cb.soHieuMB == dsMB.data[i]->soHieu && q->cb.time_xp.ngay == tm_now->tm_mday && q->cb.time_xp.thang == tm_now->tm_mon && q->cb.time_xp.nam == tm_now->tm_year) {
                dsMB.data[i]->trangThai = KHONG_HOAT_DONG;
            }
        }
    }
}
// giai phong bo nho may bay
void giaiPhongMB(DSMB& dsMB){
    for (int i = dsMB.soMB; i >= 0; i--){
        delete dsMB.data[i];
    }
    dsMB.soMB = 0;
}
