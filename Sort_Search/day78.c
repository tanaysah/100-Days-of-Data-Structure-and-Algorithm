#include <stdio.h>
#include <string.h>

void countingSort(int arr[], int n, int maxVal) {
    int count[maxVal + 1];
    memset(count, 0, (maxVal + 1) * sizeof(int));
    for (int i = 0; i < n; i++) count[arr[i]]++;
    int k = 0;
    for (int i = 0; i <= maxVal; i++)
        while (count[i]--) arr[k++] = i;
}

int main() {
    int n, maxVal;
    scanf("%d %d", &n, &maxVal);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    countingSort(arr, n, maxVal);
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}
