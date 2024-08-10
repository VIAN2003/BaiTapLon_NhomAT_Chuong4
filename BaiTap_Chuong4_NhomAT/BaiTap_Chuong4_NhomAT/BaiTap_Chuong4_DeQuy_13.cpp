#include <stdio.h>
#include <math.h>

// Bai 1: Tinh S(n)

// Tong cac so tu nhien tu 1 den n
int tong_tu_nhien(int n) {
    return n * (n + 1) / 2;
}

// Tong cac so nghich dao tu 1 den n
double tong_nghich_dao(int n) {
    double tong = 0.0;
    for (int i = 1; i <= n; i++) {
        tong += 1.0 / i;
    }
    return tong;
}

// Tong cac tich cua cac so lien tiep tu 1 den n
int tong_tich_lien_tiep(int n) {
    int tong = 0;
    for (int i = 1; i <= n; i++) {
        tong += i * (i + 1);
    }
    return tong;
}

// Bai 2: Tim gia tri phan tu thu n cua cap so cong
int cap_so_cong(int a, int r, int n) {
    if (n == 1)
        return a;
    else
        return cap_so_cong(a, r, n - 1) + r;
}

// Bai 3: Tim gia tri phan tu thu n cua cap so nhan
double cap_so_nhan(int a, int q, int n) {
    return a * pow(q, n - 1);
}

int main() {
    int lua_chon, n, a, r, q;

    do {
        printf("\nMenu:\n");
        printf("1. Tinh S(n) = 1 + 2 + ... + n\n");
        printf("2. Tinh S(n) = 1 + 1/2 + 1/3 + ... + 1/n\n");
        printf("3. Tinh S(n) = 1*2 + 2*3 + ... + n(n+1)\n");
        printf("4. Tim phan tu thu n cua cap so cong\n");
        printf("5. Tim phan tu thu n cua cap so nhan\n");
        printf("6. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &lua_chon);

        switch (lua_chon) {
            case 1:
                printf("Nhap n: ");
                scanf("%d", &n);
                printf("S(n) = %d\n", tong_tu_nhien(n));
                break;
            case 2:
                printf("Nhap n: ");
                scanf("%d", &n);
                printf("S(n) = %f\n", tong_nghich_dao(n));
                break;
            case 3:
                printf("Nhap n: ");
                scanf("%d", &n);
                printf("S(n) = %d\n", tong_tich_lien_tiep(n));
                break;
            case 4:
                printf("Nhap so hang dau tien (a): ");
                scanf("%d", &a);
                printf("Nhap cong sai (r): ");
                scanf("%d", &r);
                printf("Nhap vi tri phan tu can tim (n): ");
                scanf("%d", &n);
                printf("Phan tu thu %d cua cap so cong la %d\n", n, cap_so_cong(a, r, n));
                break;
            case 5:
                printf("Nhap so hang dau tien (a): ");
                scanf("%d", &a);
                printf("Nhap cong boi (q): ");
                scanf("%d", &q);
                printf("Nhap vi tri phan tu can tim (n): ");
                scanf("%d", &n);
                printf("Phan tu thu %d cua cap so nhan la %f\n", n, cap_so_nhan(a, q, n));
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    } while (lua_chon != 6);

    return 0;
}

