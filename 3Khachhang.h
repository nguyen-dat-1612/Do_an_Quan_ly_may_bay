//Khach hang: Huyen
string checkgt(bool GT) {
    if (GT == true) {
        return "Nam";
    }
    return "Nu";
}
bool CD(string gioitinh) {
    if (gioitinh == "Nam" || gioitinh == "nam" || gioitinh == "NAM") {
        return true;
    }
    return false;
}
int Empty(TREE root) {
    if (root == NULL) {
        return 0;
    }
    return 1;
}
// khoi tao cay nhi phan
void khoiTaoCay(TREE &root) {
    root = NULL;
}

void upper(char str[]){
	for (int i = 0; i < (int)strlen(str); i++){
	    str[i] = toupper(str[i]);
    }
}

int chuyenDoiSN(char *cmnd){
    int temp = 0;
    for (int i = 0; i < (int)strlen(cmnd); i++){
        temp = temp*10 + (cmnd[i]-'0');
    } return temp;
}
// them kh
void themKH(TREE& root, KH x){
    if(root == NULL){
        TREE p = new nodeKH;
        p->data = x;
        p->left = NULL;
        p->right = NULL;
        root = p;
        
    }
    else if (chuyenDoiSN(root->data.CMND) > chuyenDoiSN(x.CMND)) {
        themKH(root->left, x); // tăng số lượng khách hàng của nút cha sau khi thêm vào khách hàng
    }
    else if (chuyenDoiSN(root->data.CMND) < chuyenDoiSN(x.CMND)) {
        themKH(root->right, x); // tăng số lượng khách hàng của nút cha sau khi thêm vào khách hàng
    }
}
//dem so kh co trong cay
void Duyet_LNR(TREE root,int& soKH) {//Xuất các phần tử từ bé đến lớn
    if (root != NULL) {
        Duyet_LNR(root->left, soKH);
        soKH++;
        Duyet_LNR(root->right, soKH);
    }
}
// tim kiem khach hang
TREE timKiemKH(TREE &root, char* cmnd){
    if (root == NULL || chuyenDoiSN(root->data.CMND) == chuyenDoiSN(cmnd)) return root;
    else if (chuyenDoiSN(root->data.CMND) > chuyenDoiSN(cmnd)) return timKiemKH(root->left, cmnd);
    else return timKiemKH(root->right, cmnd);
}
// check khach hang co trong chuyen bay
bool checkCMNDonCB(char CMND[], NODECBPTR q){
    for (int i = 0; i < q->cb.soLuongVe; i++)
    {
        if (q->cb.ve[i]->ttVe == DA_DAT)
        {
            if (strcmp(CMND, q->cb.ve[i]->CMND) == 0){
                return true;
            }
        }
    }
    return false;
}
// doc file khach hang
int LoadFileKH(TREE& root, KH& kh) {
    ifstream file("dsKhachHang.txt");
    
    if (!file.is_open()) { return 0; }
    char gioitinh[4];
    while (file >> kh.CMND){
        file >> kh.Ho;
        thayDoi(kh.Ho);
        upper(kh.Ho);
        file >> kh.Ten;
        thayDoi(kh.Ten);
        upper(kh.Ten);
        file >> gioitinh;
        kh.gioiTinh = CD(gioitinh);
        themKH(root, kh); // thêm nút mới vào cây
        file.ignore();
    }
    file.close();
    return 1;
}
// luu file khach hang
int writeFile(TREE root, ofstream& file) {
    if (root == NULL) return 0;
    writeFile(root->left, file);
    char Ho[10];
    char Ten[30];
    file << setw(13) << left << root->data.CMND;
    strcpy(Ho,root->data.Ho);
    bienDoi(Ho);
    file << setw(13) << left << Ho;
    strcpy(Ten,root->data.Ten);
    bienDoi(Ho);
    bienDoi(Ten);
    file << setw(32) << left << Ten;
    file << setw(4) << left << checkgt(root->data.gioiTinh);
    file << endl;
    writeFile(root->right, file);

    return 1;
}

int SaveFileKH(TREE root) {
    ofstream file("dsKhachHang.txt");

    if (!file.is_open()) return 0;

    writeFile(root, file);
    file.close();

    return 1;
}
// giai phong bo nho 
void giaiPhongKH(TREE& root) {
    if (root == NULL) {
        return;
    }
    giaiPhongKH(root->left);
    giaiPhongKH(root->right);
    delete root;
}