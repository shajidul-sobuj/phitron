#include <stdio.h>

int main() {
    int N, X;
    scanf("%d %d", &N, &X);
    int a[200005];
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int L, R;
        scanf("%d %d", &L, &R);
        int ok = 0;
        for (int i = L - 1; i < R; i++) {
            if (a[i] % X == 0) {
                ok = 1;
                break;
            }
        }
        if (ok) printf("Goal\n");
        else printf("Missed\n");
    }
    return 0;
}
