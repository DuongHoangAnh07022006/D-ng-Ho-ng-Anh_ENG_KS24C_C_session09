#include <stdio.h>

int main() {
    int arr[100];
    int currentLength;
    int position;

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

    printf("Nhap vao vi tri can xoa (0-%d): ", currentLength - 1);
    scanf("%d", &position);

    if (position < 0 || position >= currentLength) {
        printf("Vi tri khong hop le.\n");
    } else {
        for (int i = position; i < currentLength - 1; i++) {
            arr[i] = arr[i + 1];
        }
        currentLength--;

        printf("Mang sau khi xoa:\n");
        for (int i = 0; i < currentLength; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}


