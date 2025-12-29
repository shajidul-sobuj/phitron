#include <stdio.h>
int main()
{
    long long int s;
    int d, w, m, y;
    int remaining_days;
    
    printf("Enter time in seconds: ");
    scanf("%lld", &s);
    
    // Convert seconds to days
    d = s / (24 * 60 * 60);
    
    // Calculate years from total days
    y = d / 365;
    remaining_days = d % 365;
    
    // Calculate months from remaining days
    m = remaining_days / 30;
    remaining_days = remaining_days % 30;
    
    // Calculate weeks from remaining days
    w = remaining_days / 7;
    remaining_days = remaining_days % 7;
    
    printf("\nEquivalent to:\n");
    printf("Years: %d\n", y);
    printf("Months: %d\n", m);
    printf("Weeks: %d\n", w);
    printf("Days: %d\n", remaining_days);
    printf("Total days: %d\n", d);
    
    return 0;
}
