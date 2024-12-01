#include <stdio.h>

int main() {
   
    int arr[] = {10, 20, 30, 40, 50};
    int length = sizeof(arr) / sizeof(arr[0]);
    int position, newValue;

    printf("Mang ban dau:\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Nhap vao vi tri can sua (0-%d): ", length - 1);
    scanf("%d", &position);
    printf("Nhap vao gia tri moi: ");
    scanf("%d", &newValue);

    
    if (position >= 0 && position < length) {
        arr[position] = newValue;
    } else {
        printf("Vi tri khong hop le.\n");
        return 1; 
    }

    
    printf("Mang sau khi sua:\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

