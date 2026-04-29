#include <stdio.h>
#include <math.h>

int jumpSearch(int arr[], int n, int target) {
    int step = (int)sqrt(n);
    int prev = 0;
    while (arr[(step < n ? step : n) - 1] < target) {
        prev = step;
        step += (int)sqrt(n);
        if (prev >= n) return -1;
    }
    while (arr[prev] < target) {
        prev++;
        if (prev == (step < n ? step : n)) return -1;
    }
    return (arr[prev] == target) ? prev : -1;
}

int main() {
    int n, target;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d", &target);
    printf("%d\n", jumpSearch(arr, n, target));
    return 0;
}
