// #include <stdio.h>

// float snb()
// {
//     float b;
//     printf("nota invalida\n");
//     scanf("%f",&b);
//     if (b>=0 && b<=10) {
//         return b;
//     } else {
//         snb();
//     }
// }
// float sna()
// {
//     float a;
//     printf("nota invalida\n");
//     scanf("%f",&a);
//     if (a>=0 && a<=10) {
//         return a;
//     } else {
//         sna();
//     }
// }
// void sn()
// {
//     float a,b;
//     scanf("%f",&a);
//     if (a>=0 && a<=10) {
//         a=a;
//     } else {
//         float aa = sna();
//         a=aa;
//     }
//     scanf("%f",&b);
//     if (b>=0 && b<=10) {
//         b=b;
//     }else {
//         float bb = snb();
//         b=bb;
//     }
//     float avg=(a+b)/2;
//     printf("media = %.2f\n",avg);
// }

// int main()
// {
//     sn();
//     int x;
//     for (int i=1; ;i++) {
//         printf("novo calculo (1-sim 2-nao)\n");
//         scanf("%d",&x);
//         if (x==1) {
//             sn();
//         }else if (x==2) {
//             break;
//         }else {
//             continue;
//         }
//     }
//     return 0;
// }



#include <stdio.h>

int main()
{
    for (int i=1; i>0; ) {
        float a,b;
        int x;
        for (int j=1;j>0;j++) {
            scanf("%f",&a);
            if (a>=0 && a<=10) {
                break;
            }else {
                printf("nota invalida\n");
                continue;
            }
        }
        for (int j=1;j>0;j++) {
            scanf("%f",&b);
            if (b>=0 && b<=10) {
                break;
            }else {
                printf("nota invalida\n");
                continue;
            }
        }
        float avg = (a+b)/2;
        printf("media = %.2f\n",avg);
        for (int j=1;j>0; ) {
            printf("novo calculo (1-sim 2-nao)\n");
            scanf("%d",&x);
            if (x==1) {
                break;
            } else if (x==2) {
                break;
            } else if (x!=1 && x!=2) {
                j++;
            }
        }
        if (x==1) {
            i++;
        }else if (x==2) {
            break;
        }
 
    }
    return 0;
}