#include <stdio.h>

long long sqrtFloor(long long n) {
    if (n < 2) return n;
    long long lo = 1, hi = n / 2, result = 1;
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        if (mid * mid == n) return mid;
        if (mid * mid < n) { result = mid; lo = mid + 1; }
        else hi = mid - 1;
    }
    return result;
}

int main() {
    long long n;
    scanf("%lld", &n);
    printf("%lld\n", sqrtFloor(n));
    return 0;
}
