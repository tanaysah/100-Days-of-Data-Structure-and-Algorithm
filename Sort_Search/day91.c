#include <stdio.h>

int interpolationSearch(int arr[], int n, int target) {
    int lo = 0, hi = n - 1;
    while (lo <= hi && target >= arr[lo] && target <= arr[hi]) {
        if (lo == hi) return (arr[lo] == target) ? lo : -1;
        int pos = lo + ((long long)(target - arr[lo]) * (hi - lo)) / (arr[hi] - arr[lo]);
        if (arr[pos] == target) return pos;
        if (arr[pos] < target) lo = pos + 1;
        else hi = pos - 1;
    }
    return -1;
}

int main() {
    int n, target;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d", &target);
    printf("%d\n", interpolationSearch(arr, n, target));
    return 0;
}
