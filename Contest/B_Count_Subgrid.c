#include <stdio.h>
int main() {
    int days,n;
    scanf("%d",&days);
    scanf("%d",&n);
    int ages[n];
    for (int i=0;i<n;i++){
        scanf("%d",&ages[i]);
    }
    int count = 0;
    for (int i=0;i<n;i++){
        for (int j=2;j<=ages[i];j++){
            if (ages[i]%j==0 && j!=ages[i]){
                count++;
                break;
            }
        }
    }
    printf("%d %d", n-count, count);
    return 0;
}
