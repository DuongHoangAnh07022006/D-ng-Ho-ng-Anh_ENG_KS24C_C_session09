#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 100

void nhapMang(int arr[], int *n) {
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void hienThiMang(int arr[], int n) {
    printf("Các phan tu trong mang là:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void inChanVaTong(int arr[], int n) {
    int sum = 0;
    printf("Các phan tu trong mang là:\n");
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
            sum += arr[i];
        }
    }
    printf("\nTong cac phan tu chon là: %d\n", sum);
}

void timMaxMin(int arr[], int n, int *max, int *min) {
    *max = arr[0];
    *min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > *max) {
            *max = arr[i];
        }
        if (arr[i] < *min) {
            *min = arr[i];
        }
    }
}

bool laSoNguyenTo(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void inNguyenToVaTong(int arr[], int n) {
    int sum = 0;
    printf("Các phan tu la so nguyen tu trong mang là:\n");
    for (int i = 0; i < n; i++) {
        if (laSoNguyenTo(arr[i])) {
            printf("%d ", arr[i]);
            sum += arr[i];
        }
    }
    printf("\nTong các phan tu la so nguyen tu là: %d\n", sum);
}

void thongKePhanTu(int arr[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            count++;
        }
    }
    printf("So lon xuat hien cua phan tu %d trong mang là: %d\n", x, count);
}

void themPhanTu(int arr[], int *n, int pos, int value) {
    if (*n >= MAX_SIZE) {
        printf("Mang da day, không the thêm phan tu.\n");
        return;
    }
    if (pos < 0 || pos > *n) {
        printf("Vi trí không hop le.\n");
        return;
    }
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*n)++;
}

int main() {
    int arr[MAX_SIZE];
    int n = 0;
    int choice;
    int max, min, x, pos, value;

    do {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu can nhap và giá tri các phan tu\n");
        printf("2. In ra giá tri các phan tu dang quan lý\n");
        printf("3. In ra giá tri các phan tu chon và tính tong\n");
        printf("4. In ra giá tri lon nhat và nho nhat trong mang\n");
        printf("5. In ra các phan tu là so nguyên tu trong mang và tính tong\n");
        printf("6. Nhap vào mot so và thong kê trong mang có bao nhiêu phan tu dó\n");
        printf("7. Thêm mot phan tu vào vi trí cho danh\n");
        printf("8. Thoát\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMang(arr, &n);
                break;
            case 2:
                hienThiMang(arr,n);
                break;
            case 3:
			    inChanVaTong(arr, n);
				break;
			case 4:
				timMaxMin(arr, n, &max, &min);
				printf("Giá tri lon nhat trong mang là: %d\n", max);
				printf("Giá tr? nh? nh?t trong m?ng là: %d\n", min);
                break;
            case 5:
			    inNguyenToVaTong(arr, n);
			    break;
			case 6:
				printf("Nhap vào so con thong kê: ");
				scanf("%d", &x);
				thongKePhanTu(arr, n, x);
				break;
			case 7:
			    printf("Nhap vào vi trí can thêm: ");
				scanf("%d", &pos);
				printf("Nhap vào giá tri phan tu can thêm: ");
				scanf("%d", &value);
				themPhanTu(arr, &n, pos, value);
				break;
			case 8:
				printf("Thoát chuong trình.\n");
				break;
			default:
				printf("L?a ch?n không h?p l?. Vui lòng ch?n l?i.\n");
	}
} while (choice != 8);
 return 0;
}
					

