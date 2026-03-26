#include <stdio.h>
#include <string.h>

int main()
{
    char c[26];
    scanf("%[^\n]s",c);
    int sz = strlen(c);
    int counter=0;
    for (int i=0;i<sz;i++) {
        if (c[i]==')') {
            counter--;
        }else if ( c[i]=='(' ) {
            counter++;
        }

        if (counter<0) {
            break;
        }
    }

    if (counter ==0) {
        printf("Yes\n");
    }else {
        printf("No\n");
    }
    return 0;
}