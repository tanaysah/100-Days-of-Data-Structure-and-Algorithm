#include <stdio.h>

int firstOccurrence(int arr[], int n, int target) {
    int lo = 0, hi = n - 1, result = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == target) { result = mid; hi = mid - 1; }
        else if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return result;
}

int lastOccurrence(int arr[], int n, int target) {
    int lo = 0, hi = n - 1, result = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == target) { result = mid; lo = mid + 1; }
        else if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return result;
}

int main() {
    int n, target;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d", &target);
    int first = firstOccurrence(arr, n, target);
    if (first == -1) { printf("0\n"); return 0; }
    printf("%d\n", lastOccurrence(arr, n, target) - first + 1);
    return 0;
}
