#include <stdio.h>

int findPeak(int arr[], int n) {
    int lo = 0, hi = n - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] > arr[mid + 1]) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int idx = findPeak(arr, n);
    printf("Peak element: %d at index %d\n", arr[idx], idx);
    return 0;
}
