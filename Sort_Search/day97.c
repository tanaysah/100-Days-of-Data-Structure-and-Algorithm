#include <stdio.h>
#include <stdlib.h>

typedef struct { int val, freq; } Pair;

int cmp(const void* a, const void* b) {
    Pair* x = (Pair*)a;
    Pair* y = (Pair*)b;
    if (y->freq != x->freq) return y->freq - x->freq;
    return x->val - y->val;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    Pair pairs[n];
    int size = 0, visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        int count = 0;
        for (int j = i; j < n; j++) {
            if (arr[j] == arr[i]) { count++; visited[j] = 1; }
        }
        pairs[size].val = arr[i];
        pairs[size++].freq = count;
    }
    qsort(pairs, size, sizeof(Pair), cmp);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < pairs[i].freq; j++)
            printf("%d ", pairs[i].val);
    printf("\n");
    return 0;
}
