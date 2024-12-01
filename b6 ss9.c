#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

void nhapMang(int arr[MAX_SIZE][MAX_SIZE], int *rows, int *cols) {
    printf("Nh?p s? hàng: ");
    scanf("%d", rows);
    printf("Nh?p s? c?t: ");
    scanf("%d", cols);
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            printf("Nh?p ph?n t? [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void hienThiMang(int arr[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Ma tr?n:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void inLeVaTong(int arr[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int sum = 0;
    printf("Các ph?n t? l? trong ma tr?n là:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] % 2 != 0) {
                printf("%d ", arr[i][j]);
                sum += arr[i][j];
            }
        }
    }
    printf("\nT?ng các ph?n t? l? là: %d\n", sum);
}

void inBienVaTinhTich(int arr[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int product = 1;
    printf("Các ph?n t? trên du?ng biên c?a ma tr?n là:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                printf("%d ", arr[i][j]);
                product *= arr[i][j];
            }
        }
    }
    printf("\nTích các ph?n t? trên du?ng biên là: %d\n", product);
}

void inDuongCheoChinh(int arr[MAX_SIZE][MAX_SIZE], int n) {
    printf("Các ph?n t? trên du?ng chéo chính c?a ma tr?n là:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i][i]);
    }
    printf("\n");
}

void inDuongCheoPhu(int arr[MAX_SIZE][MAX_SIZE], int n) {
    printf("Các ph?n t? trên du?ng chéo ph? c?a ma tr?n là:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i][n - i - 1]);
    }
    printf("\n");
}

void dongTongLonNhat(int arr[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int maxSum = 0, maxRow = 0;
    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += arr[i][j];
        }
        if (sum > maxSum) {
            maxSum = sum;
            maxRow = i;
        }
    }
    printf("Dòng có t?ng giá tr? l?n nh?t là dòng %d v?i t?ng là %d\n", maxRow, maxSum);
}

int main() {
    int arr[MAX_SIZE][MAX_SIZE];
    int rows = 0, cols = 0;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nh?p kích c? và giá tr? các ph?n t? c?a m?ng\n");
        printf("2. In giá tr? các ph?n t? c?a m?ng theo ma tr?n\n");
        printf("3. In giá tr? các ph?n t? là l? và tính t?ng\n");
        printf("4. In ra các ph?n t? n?m trên du?ng biên và tính tích\n");
        printf("5. In ra các ph?n t? n?m trên du?ng chéo chính\n");
        printf("6. In ra các ph?n t? n?m trên du?ng chéo ph?\n");
        printf("7. In ra dòng có t?ng giá tr? các ph?n t? là l?n nh?t\n");
        printf("8. Thoát\n");
        printf("L?a ch?n c?a b?n: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMang(arr, &rows, &cols);
                break;
            case 2:
                hienThiMang(arr, rows, cols);
                break;
            case 3:
                inLeVaTong(arr, rows, cols);
                break;
            case 4:
                inBienVaTinhTich(arr, rows, cols);
                break;
            case 5:
                inDuongCheoChinh(arr, rows);
                break;
            case 6:
                inDuongCheoPhu(arr, rows);
                break;
            case 7:
                dongTongLonNhat(arr, rows, cols);
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

