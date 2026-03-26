#include <stdio.h>
int main()
{
    int marks;
    printf("Enter a marks\n");

    while (scanf("%d",&marks)<0 && scanf("%d",&marks)>100 )
    {
        printf("Enter a valid number\n");
    }
    // for ( ; ; ) {
    //     if (marks <0 && marks >100) {
            
    //     }else {
    //         break;
    //     }
    // }
    if (marks<30 && marks>=0) {printf("C\n");}
    else if (marks >= 30 && marks <70) {printf("B\n");}
    else if (marks>= 70 && marks <90){printf("A\n");}
    else if (marks>= 90 && marks<100 ) {printf("A+\n");}
    else  {printf("Enter a valid number\n");}
 
    return 0;
}