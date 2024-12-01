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
    printf("C�c phan tu trong mang l�:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void inChanVaTong(int arr[], int n) {
    int sum = 0;
    printf("C�c phan tu trong mang l�:\n");
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
            sum += arr[i];
        }
    }
    printf("\nTong cac phan tu chon l�: %d\n", sum);
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
    printf("C�c phan tu la so nguyen tu trong mang l�:\n");
    for (int i = 0; i < n; i++) {
        if (laSoNguyenTo(arr[i])) {
            printf("%d ", arr[i]);
            sum += arr[i];
        }
    }
    printf("\nTong c�c phan tu la so nguyen tu l�: %d\n", sum);
}

void thongKePhanTu(int arr[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            count++;
        }
    }
    printf("So lon xuat hien cua phan tu %d trong mang l�: %d\n", x, count);
}

void themPhanTu(int arr[], int *n, int pos, int value) {
    if (*n >= MAX_SIZE) {
        printf("Mang da day, kh�ng the th�m phan tu.\n");
        return;
    }
    if (pos < 0 || pos > *n) {
        printf("Vi tr� kh�ng hop le.\n");
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
        printf("1. Nhap so phan tu can nhap v� gi� tri c�c phan tu\n");
        printf("2. In ra gi� tri c�c phan tu dang quan l�\n");
        printf("3. In ra gi� tri c�c phan tu chon v� t�nh tong\n");
        printf("4. In ra gi� tri lon nhat v� nho nhat trong mang\n");
        printf("5. In ra c�c phan tu l� so nguy�n tu trong mang v� t�nh tong\n");
        printf("6. Nhap v�o mot so v� thong k� trong mang c� bao nhi�u phan tu d�\n");
        printf("7. Th�m mot phan tu v�o vi tr� cho danh\n");
        printf("8. Tho�t\n");
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
				printf("Gi� tri lon nhat trong mang l�: %d\n", max);
				printf("Gi� tr? nh? nh?t trong m?ng l�: %d\n", min);
                break;
            case 5:
			    inNguyenToVaTong(arr, n);
			    break;
			case 6:
				printf("Nhap v�o so con thong k�: ");
				scanf("%d", &x);
				thongKePhanTu(arr, n, x);
				break;
			case 7:
			    printf("Nhap v�o vi tr� can th�m: ");
				scanf("%d", &pos);
				printf("Nhap v�o gi� tri phan tu can th�m: ");
				scanf("%d", &value);
				themPhanTu(arr, &n, pos, value);
				break;
			case 8:
				printf("Tho�t chuong tr�nh.\n");
				break;
			default:
				printf("L?a ch?n kh�ng h?p l?. Vui l�ng ch?n l?i.\n");
	}
} while (choice != 8);
 return 0;
}
					

