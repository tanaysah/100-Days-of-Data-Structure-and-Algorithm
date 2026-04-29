#include <stdio.h>

int ternarySearch(int arr[], int lo, int hi, int target) {
    if (lo > hi) return -1;
    int m1 = lo + (hi - lo) / 3;
    int m2 = hi - (hi - lo) / 3;
    if (arr[m1] == target) return m1;
    if (arr[m2] == target) return m2;
    if (target < arr[m1]) return ternarySearch(arr, lo, m1 - 1, target);
    if (target > arr[m2]) return ternarySearch(arr, m2 + 1, hi, target);
    return ternarySearch(arr, m1 + 1, m2 - 1, target);
}

int main() {
    int n, target;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d", &target);
    printf("%d\n", ternarySearch(arr, 0, n - 1, target));
    return 0;
}
