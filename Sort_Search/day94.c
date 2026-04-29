#include <stdio.h>

int partition(int arr[], int lo, int hi) {
    int pivot = arr[hi], i = lo - 1;
    for (int j = lo; j < hi; j++) {
        if (arr[j] <= pivot) {
            i++;
            int tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
        }
    }
    int tmp = arr[i+1]; arr[i+1] = arr[hi]; arr[hi] = tmp;
    return i + 1;
}

int quickSelect(int arr[], int lo, int hi, int k) {
    if (lo == hi) return arr[lo];
    int pi = partition(arr, lo, hi);
    if (pi == k) return arr[pi];
    if (pi < k) return quickSelect(arr, pi + 1, hi, k);
    return quickSelect(arr, lo, pi - 1, k);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("%d\n", quickSelect(arr, 0, n - 1, k - 1));
    return 0;
}
