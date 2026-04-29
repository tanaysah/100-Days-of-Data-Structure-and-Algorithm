#include <stdio.h>

long long mergeCount(int arr[], int temp[], int lo, int mid, int hi) {
    int i = lo, j = mid + 1, k = lo;
    long long count = 0;
    while (i <= mid && j <= hi) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else { temp[k++] = arr[j++]; count += (mid - i + 1); }
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= hi) temp[k++] = arr[j++];
    for (int x = lo; x <= hi; x++) arr[x] = temp[x];
    return count;
}

long long sortCount(int arr[], int temp[], int lo, int hi) {
    if (lo >= hi) return 0;
    int mid = lo + (hi - lo) / 2;
    long long count = 0;
    count += sortCount(arr, temp, lo, mid);
    count += sortCount(arr, temp, mid + 1, hi);
    count += mergeCount(arr, temp, lo, mid, hi);
    return count;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n], temp[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("%lld\n", sortCount(arr, temp, 0, n - 1));
    return 0;
}
