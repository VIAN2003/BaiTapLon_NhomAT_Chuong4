#include <stdio.h>
#include <stdlib.h>

// Bài 7.1: Tính số hạng thứ n của dãy A_n
int calculateA7_1(int n) {
    if (n == 0) return 1;
    if (n == 1) return 0;
    if (n == 2) return -1;
    return 2 * calculateA7_1(n - 1) - 3 * calculateA7_1(n - 2) - calculateA7_1(n - 3);
}

// Bài 7.2: Tính số hạng thứ n của dãy A_n
int calculateA7_2(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 3;
    return 2 * calculateA7_2(n - 3) + calculateA7_2(n - 2) - 3 * calculateA7_2(n - 1);
}

// Bài 8: Tính hàm f(n)
int calculateF8(int n) {
    if (n == 1) return 1;
    if (n % 2 == 0) return 2 * calculateF8(n / 2);
    return 2 * calculateF8(n / 2) + 3 * calculateF8(n / 2 + 1);
}

// Bài 10: Tìm kiếm nhị phân bằng đệ quy
int binarySearch(int a[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x) return mid;
        if (a[mid] > x) return binarySearch(a, left, mid - 1, x);
        return binarySearch(a, mid + 1, right, x);
    }
    return -1;
}

// Bài 11: Xuất dãy Fibonacci
void fibonacci(int n) {
    int f1 = 1, f2 = 1, fn;
    printf("Fibonacci sequence: ");
    if (n >= 1) printf("%d ", f1);
    if (n >= 2) printf("%d ", f2);
    for (int i = 3; i <= n; i++) {
        fn = f1 + f2;
        printf("%d ", fn);
        f1 = f2;
        f2 = fn;
    }
    printf("\n");
}

// Bài 12: Tìm số Fibonacci lớn nhất nhỏ hơn n
int largestFibonacciLessThanN(int n) {
    int f1 = 1, f2 = 1, fn = f1 + f2;
    while (fn < n) {
        f1 = f2;
        f2 = fn;
        fn = f1 + f2;
    }
    return f2;
}

// Bài 13: Tính số hạng thứ n của hai dãy
void calculateA13(int n, int* xn, int* yn) {
    if (n == 0) {
        *xn = 1;
        *yn = 0;
    }
    else {
        int xn1, yn1;
        calculateA13(n - 1, &xn1, &yn1);
        *xn = xn1 + yn1;
        *yn = 3 * xn1 + 2 * yn1;
    }
}

// Bài 14: Tính An
int calculateA14(int n, int a[]) {
    if (n == 1) return a[0] = 1;
    a[n - 1] = n * calculateA14(n - 1, a);
    for (int i = 0; i < n - 1; i++) {
        a[n - 1] += n * a[i];
    }
    return a[n - 1];
}

// Bài 15: Tính Yn
int calculateY15(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 3;
    return calculateY15(n - 1) + 2 * calculateY15(n - 2) + 3 * calculateY15(n - 3);
}

// Bài 16: Tính Xn
int calculateX16(int n) {
    if (n == 1 || n == 2) return 1;
    return calculateX16(n - 1) + (n - 1) * calculateX16(n - 2);
}

// Hiển thị menu
void displayMenu() {
    printf("Menu:\n");
    printf("1. Bai 7.1: Tinh so hang thu n cua day A_n\n");
    printf("2. Bai 7.2: Tinh so hang thu n cua day A_n\n");
    printf("3. Bai 8: Tinh ham f(n)\n");
    printf("4. Bai 10: Tim kiem nhi phan bang de quy\n");
    printf("5. Bai 11: Xuat day Fibonacci\n");
    printf("6. Bai 12: Tim so Fibonacci lon nhat nho hon n\n");
    printf("7. Bai 13: Tinh so hang thu n cua hai day\n");
    printf("8. Bai 14: Tinh An\n");
    printf("9. Bai 15: Tinh Yn\n");
    printf("10. Bai 16: Tinh Xn\n");
    printf("11. Exit\n");
    printf("Chon: ");
}

int main() {
    int choice, n, x, result, size;
    int xn, yn;
    int* arr = NULL; // Khai báo biến nhưng không khởi tạo
    int* a = NULL; // Khai báo biến nhưng không khởi tạo

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Nhap n: ");
            scanf("%d", &n);
            result = calculateA7_1(n);
            printf("A_%d = %d\n", n, result);
            break;

        case 2:
            printf("Nhap n: ");
            scanf("%d", &n);
            result = calculateA7_2(n);
            printf("A_%d = %d\n", n, result);
            break;

        case 3:
            printf("Nhap n: ");
            scanf("%d", &n);
            result = calculateF8(n);
            printf("f(%d) = %d\n", n, result);
            break;

        case 4:
            printf("Nhap kich thuoc mang: ");
            scanf("%d", &size);
            arr = (int*)malloc(size * sizeof(int)); // Khởi tạo biến
            printf("Nhap cac phan tu cua mang: ");
            for (int i = 0; i < size; i++) {
                scanf("%d", &arr[i]);
            }
            printf("Nhap gia tri can tim: ");
            scanf("%d", &x);
            result = binarySearch(arr, 0, size - 1, x);
            if (result != -1) {
                printf("Gia tri %d duoc tim thay tai vi tri %d\n", x, result);
            }
            else {
                printf("Gia tri %d khong đuoc tim thay\n", x);
            }
            free(arr); // Giải phóng bộ nhớ
            arr = NULL; // Đặt con trỏ về NULL
            break;

        case 5:
            printf("Nhap n: ");
            scanf("%d", &n);
            fibonacci(n);
            break;

        case 6:
            printf("Nhap n: ");
            scanf("%d", &n);
            result = largestFibonacciLessThanN(n);
            printf("So Fibonacci lon nhat nho hon %d la %d\n", n, result);
            break;

        case 7:
            printf("Nhap n: ");
            scanf("%d", &n);
            calculateA13(n, &xn, &yn);
            printf("x_%d = %d, y_%d = %d\n", n, xn, n, yn);
            break;

        case 8:
            printf("Nhap n: ");
            scanf("%d", &n);
            a = (int*)malloc(n * sizeof(int)); // Khởi tạo biến
            result = calculateA14(n, a);
            printf("A_%d = %d\n", n, result);
            free(a); // Giải phóng bộ nhớ
            a = NULL; // Đặt con trỏ về NULL
            break;

        case 9:
            printf("Nhap n: ");
            scanf("%d", &n);
            result = calculateY15(n);
            printf("Y_%d = %d\n", n, result);
            break;

        case 10:
            printf("Nhap n: ");
            scanf("%d", &n);
            result = calculateX16(n);
            printf("X_%d = %d\n", n, result);
            break;

        case 11:
            printf("Thoat chuong trinh.\n");
            exit(0);
            break;

        default:
            printf("Lua chon khong hop le, vui long chon lai.\n");
        }
    }

    return 0;
}
