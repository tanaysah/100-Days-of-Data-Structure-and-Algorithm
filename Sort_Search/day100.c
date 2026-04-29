#include <stdio.h>
#include <limits.h>

double findMedianSortedArrays(int A[], int m, int B[], int n) {
    if (m > n) return findMedianSortedArrays(B, n, A, m);
    int lo = 0, hi = m;
    while (lo <= hi) {
        int i = lo + (hi - lo) / 2;
        int j = (m + n + 1) / 2 - i;
        int maxLeftA  = (i == 0) ? INT_MIN : A[i - 1];
        int minRightA = (i == m) ? INT_MAX : A[i];
        int maxLeftB  = (j == 0) ? INT_MIN : B[j - 1];
        int minRightB = (j == n) ? INT_MAX : B[j];
        if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
            int left  = maxLeftA  > maxLeftB  ? maxLeftA  : maxLeftB;
            int right = minRightA < minRightB ? minRightA : minRightB;
            if ((m + n) % 2 == 1) return (double)left;
            return (left + right) / 2.0;
        } else if (maxLeftA > minRightB) hi = i - 1;
        else lo = i + 1;
    }
    return 0.0;
}

int main() {
    int m, n;
    scanf("%d", &m);
    int A[m];
    for (int i = 0; i < m; i++) scanf("%d", &A[i]);
    scanf("%d", &n);
    int B[n];
    for (int i = 0; i < n; i++) scanf("%d", &B[i]);
    printf("%.5f\n", findMedianSortedArrays(A, m, B, n));
    return 0;
}
