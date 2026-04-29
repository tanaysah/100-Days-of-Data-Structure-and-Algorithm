#include <stdio.h>
#include <stdlib.h>

typedef struct Node { float val; struct Node* next; } Node;

void insertSorted(Node** bucket, float val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val; node->next = NULL;
    if (!*bucket || (*bucket)->val > val) { node->next = *bucket; *bucket = node; return; }
    Node* curr = *bucket;
    while (curr->next && curr->next->val <= val) curr = curr->next;
    node->next = curr->next;
    curr->next = node;
}

void bucketSort(float arr[], int n) {
    Node* buckets[n];
    for (int i = 0; i < n; i++) buckets[i] = NULL;
    for (int i = 0; i < n; i++) insertSorted(&buckets[(int)(n * arr[i])], arr[i]);
    int k = 0;
    for (int i = 0; i < n; i++) {
        Node* curr = buckets[i];
        while (curr) { arr[k++] = curr->val; Node* tmp = curr; curr = curr->next; free(tmp); }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    float arr[n];
    for (int i = 0; i < n; i++) scanf("%f", &arr[i]);
    bucketSort(arr, n);
    for (int i = 0; i < n; i++) printf("%.2f ", arr[i]);
    return 0;
}
