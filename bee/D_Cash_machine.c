#include <stdio.h>

int main() {
    int n, count = 0;
    scanf("%d", &n);

    if (n >= 500) {
        count =count + n/500;
        
    }
    if (n >= 200) {
        count += n / 200;
        n %= 200;
    }
    if (n >= 100) {
        count += n / 100;
        n %= 100;
    }
    if (n >= 50) {
        count += n / 50;
        n %= 50;
    }
    if (n >= 20) {
        count += n / 20;
        n %= 20;
    }
    if (n >= 10) {
        count += n / 10;
        n %= 10;
    }

    printf("%d", count);
    return 0;
}
