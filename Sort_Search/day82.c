#include <stdio.h>

void sort012(int arr[], int n) {
    int lo = 0, mid = 0, hi = n - 1;
    while (mid <= hi) {
        if (arr[mid] == 0) {
            int tmp = arr[lo]; arr[lo] = arr[mid]; arr[mid] = tmp;
            lo++; mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else {
            int tmp = arr[mid]; arr[mid] = arr[hi]; arr[hi] = tmp;
            hi--;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    sort012(arr, n);
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}
