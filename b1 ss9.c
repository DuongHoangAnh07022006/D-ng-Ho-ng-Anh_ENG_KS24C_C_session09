#include <stdio.h>

int main() {
    int arr[100];
    int currentLength;
    int value, position;

    printf("Nhap vao so phan tu cua mang: ");
    scanf("%d", &currentLength);

    for (int i = 0; i < currentLength; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Mang ban dau:\n");
    for (int i = 0; i < currentLength; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Nhap vao gia tri phan tu can them: ");
    scanf("%d", &value);
    printf("Nhap vao vi tri can them (0-%d): ", currentLength);
    scanf("%d", &position);

    if (position < 0 || position > currentLength) {
        printf("Vi tri khong hop le.\n");
    } else {
        for (int i = currentLength; i > position; i--) {
            arr[i] = arr[i - 1];
        }
        arr[position] = value;
        currentLength++;

        printf("Mang sau khi them:\n");
        for (int i = 0; i < currentLength; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}

