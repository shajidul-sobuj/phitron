#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        int el;
        int counter=0;
        scanf("%d",&el);
        for (int j=2;j<el;j++) {
            if (el%j==0) {
                counter++;
                break;
            }
        }
        if (counter!=0){
            printf("%d nao eh primo\n",el);
        }else {
            printf("%d eh primo\n",el);
        }
    }
    return 0;
}



// #include <stdio.h>
// int main() {
//     int days,n;
//     scanf("%d",&days);
//     scanf("%d",&n);
//     int ages[n];
//     for (int i=0;i<n;i++){
//         scanf("%d",&ages[i]);
//     }
//     int count = 0;
//     for (int i=0;i<n;i++){
//         for (int j=2;j<=ages[i];j++){
//             if (ages[i]%j==0 && j!=ages[i]){
//                 count++;
//                 break;
//             }
//         }
//     }
//     printf("%d %d", n-count, count);
//     return 0;
// }