#include <stdio.h>
void fn (int star)
{
    if (star==0) {
        return;
    }
    for (int i=1;i<=star;i++) {
        printf("*");
    }
    printf("\n");
    fn(star-1);

}
int main()
{
    int n;
    scanf("%d",&n);
    char x;
    
    fn(n);
    return 0;
}