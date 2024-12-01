#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

void nhapMang(int arr[MAX_SIZE][MAX_SIZE], int *rows, int *cols) {
    printf("Nh?p s? h�ng: ");
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
    printf("C�c ph?n t? l? trong ma tr?n l�:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] % 2 != 0) {
                printf("%d ", arr[i][j]);
                sum += arr[i][j];
            }
        }
    }
    printf("\nT?ng c�c ph?n t? l? l�: %d\n", sum);
}

void inBienVaTinhTich(int arr[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int product = 1;
    printf("C�c ph?n t? tr�n du?ng bi�n c?a ma tr?n l�:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                printf("%d ", arr[i][j]);
                product *= arr[i][j];
            }
        }
    }
    printf("\nT�ch c�c ph?n t? tr�n du?ng bi�n l�: %d\n", product);
}

void inDuongCheoChinh(int arr[MAX_SIZE][MAX_SIZE], int n) {
    printf("C�c ph?n t? tr�n du?ng ch�o ch�nh c?a ma tr?n l�:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i][i]);
    }
    printf("\n");
}

void inDuongCheoPhu(int arr[MAX_SIZE][MAX_SIZE], int n) {
    printf("C�c ph?n t? tr�n du?ng ch�o ph? c?a ma tr?n l�:\n");
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
    printf("D�ng c� t?ng gi� tr? l?n nh?t l� d�ng %d v?i t?ng l� %d\n", maxRow, maxSum);
}

int main() {
    int arr[MAX_SIZE][MAX_SIZE];
    int rows = 0, cols = 0;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nh?p k�ch c? v� gi� tr? c�c ph?n t? c?a m?ng\n");
        printf("2. In gi� tr? c�c ph?n t? c?a m?ng theo ma tr?n\n");
        printf("3. In gi� tr? c�c ph?n t? l� l? v� t�nh t?ng\n");
        printf("4. In ra c�c ph?n t? n?m tr�n du?ng bi�n v� t�nh t�ch\n");
        printf("5. In ra c�c ph?n t? n?m tr�n du?ng ch�o ch�nh\n");
        printf("6. In ra c�c ph?n t? n?m tr�n du?ng ch�o ph?\n");
        printf("7. In ra d�ng c� t?ng gi� tr? c�c ph?n t? l� l?n nh?t\n");
        printf("8. Tho�t\n");
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
                printf("Tho�t chuong tr�nh.\n");
                break;
            default:
                printf("L?a ch?n kh�ng h?p l?. Vui l�ng ch?n l?i.\n");
        }
    } while (choice != 8);

    return 0;
}

