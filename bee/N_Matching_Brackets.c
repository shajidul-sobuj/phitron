#include <stdio.h>
#include <string.h>

int main()
{
    char c[26];
    scanf("%[^\n]s",c);
    int sz = strlen(c);
    int counter1=0;
    int counter2=0;
    int counter3=0;
    for (int i=0;i<sz;i++) {
        if (c[i]==')') {
            counter1--;
        }else if ( c[i]=='(' ) {
            counter1++;
        }else if ( c[i]=='{' ) {
            counter2++;
        }else if ( c[i]=='}' ) {
            counter2--;
        }else if ( c[i]=='[' ) {
            counter3++;
        }else if ( c[i]==']' ) {
            counter3--;
        }

        if (counter1<0 || counter2<0 || counter3<0) {
            break;
        }
    }

    if (counter1+counter2+counter3 ==0) {
        printf("Yes\n");
    }else {
        printf("No\n");
    }
    return 0;
}