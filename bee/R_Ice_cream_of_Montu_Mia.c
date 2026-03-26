#include <stdio.h>

int main()
{
    int pm;
    scanf("%d",&pm);
    int t1,t2,t3;
    scanf("%d %d %d",&t1,&t2,&t3);
    
    if (pm-t1>=10) {
        printf("Yes :-D\n");
    }else if (pm-t2>=10) {
        printf("Yes :-D\n");
    }else if (pm-t3>=10) {
        printf("Yes :-D\n");
    }else {
        printf("No :-(\n");
    }
    return 0;
}