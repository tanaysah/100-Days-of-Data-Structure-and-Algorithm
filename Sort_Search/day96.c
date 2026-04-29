#include <stdio.h>

int canAllocate(int pages[], int n, int m, long long mid) {
    int students = 1;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (pages[i] > mid) return 0;
        if (sum + pages[i] > mid) { students++; sum = pages[i]; }
        else sum += pages[i];
    }
    return students <= m;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int pages[n];
    long long sum = 0, maxVal = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
        sum += pages[i];
        if (pages[i] > maxVal) maxVal = pages[i];
    }
    if (m > n) { printf("-1\n"); return 0; }
    long long lo = maxVal, hi = sum, result = sum;
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        if (canAllocate(pages, n, m, mid)) { result = mid; hi = mid - 1; }
        else lo = mid + 1;
    }
    printf("%lld\n", result);
    return 0;
}
