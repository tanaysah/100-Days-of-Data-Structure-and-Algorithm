#include <stdio.h>

int binarySearchRec(int arr[], int lo, int hi, int target) {
    if (lo > hi) return -1;
    int mid = lo + (hi - lo) / 2;
    if (arr[mid] == target) return mid;
    if (arr[mid] < target) return binarySearchRec(arr, mid + 1, hi, target);
    return binarySearchRec(arr, lo, mid - 1, target);
}

int main() {
    int n, target;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d", &target);
    int result = binarySearchRec(arr, 0, n - 1, target);
    if (result != -1) printf("Found at index %d\n", result);
    else printf("Not found\n");
    return 0;
}
