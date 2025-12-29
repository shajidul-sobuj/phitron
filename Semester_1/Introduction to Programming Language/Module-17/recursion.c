#include <stdio.h>
void hello()
{
    printf("Hello\n");
    hello();
}
int main()
{
    printf("Hi\n");
    hello();
    return 0;
}


// same function ke, mne function nijeke call korle take recursion bole nothing else
//