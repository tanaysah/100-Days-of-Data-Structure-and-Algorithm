#include <stdio.h>
#include <string.h>

void computeLPS(char* pat, int m, int lps[]) {
    int len = 0, i = 1;
    lps[0] = 0;
    while (i < m) {
        if (pat[i] == pat[len]) { lps[i++] = ++len; }
        else if (len) len = lps[len - 1];
        else lps[i++] = 0;
    }
}

void KMP(char* text, char* pat) {
    int n = strlen(text), m = strlen(pat);
    int lps[m], found = 0;
    computeLPS(pat, m, lps);
    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pat[j]) { i++; j++; }
        if (j == m) {
            printf("Pattern found at index %d\n", i - j);
            found = 1;
            j = lps[j - 1];
        } else if (i < n && text[i] != pat[j]) {
            if (j) j = lps[j - 1];
            else i++;
        }
    }
    if (!found) printf("Pattern not found\n");
}

int main() {
    char text[1001], pat[1001];
    scanf("%s %s", text, pat);
    KMP(text, pat);
    return 0;
}
