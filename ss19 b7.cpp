#include <stdio.h>
#include <string.h>

struct sinhVien {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};

void xoaSinhVien(struct sinhVien sv[], int *n, int id) {
    int found = 0;
    for (int i = 0; i < *n; i++) {
        if (sv[i].id == id) {
            for (int j = i; j < *n - 1; j++) {
                sv[j] = sv[j + 1];
            }
            (*n)--;  
            found = 1;
            printf("Sinh vien voi ID %d da duoc xoa.\n", id);
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien voi ID %d.\n", id);
    }
}

void inDanhSach(struct sinhVien sv[], int n) {
    printf("\nThong tin tat ca sinh vien:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d\n", sv[i].id);
        printf("Ten: %s\n", sv[i].name);
        printf("Tuoi: %d\n", sv[i].age);
        printf("So dien thoai: %s\n\n", sv[i].phoneNumber);
    }
}

int main() {
    struct sinhVien sv[50] = {
        {1, "Nguyen Van A", 18, "0963852741"},
        {2, "Nguyen Van B", 19, "0357194826"},
        {3, "Le Van A", 20, "0123456789"},
        {4, "Trieu Quoc B", 69, "0696969966"},
        {5, "Tran Nguyen T", 18, "0123478965"}
    };
    int n = 5;
    
    printf("Nhap thong tin sinh vien moi:\n");
    sv[n].id = n + 1;
    printf("Nhap ten: ");  
    fgets(sv[n].name, sizeof(sv[n].name), stdin);
    sv[n].name[strcspn(sv[n].name, "\n")] = 0;  
    printf("Nhap tuoi: ");
    scanf("%d", &sv[n].age);
    fflush(stdin);
    printf("Nhap so dien thoai: ");
    fgets(sv[n].phoneNumber, sizeof(sv[n].phoneNumber), stdin);
    n++;

    
    inDanhSach(sv, n);

    int idXoa;
    printf("Nhap ID sinh vien muon xoa: ");
    scanf("%d", &idXoa);

    xoaSinhVien(sv, &n, idXoa);

    inDanhSach(sv, n);

    return 0;
}

