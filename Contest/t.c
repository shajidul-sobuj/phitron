#include <stdio.h>
#include <string.h>
struct Student 
{
    char name[1001];
    int id;
    double cgpa;
    char address[1001];
    char number[101];
    char email[1001];

};
int main()
{
    struct Student a;
    strcpy(a.name, "Sobuj");
    a.id= 212;
    a.cgpa=1.23;
    strcpy(a.email, "shajidul.islam.sobuj@gmail.com");
    strcpy(a.number, "01580543990");
    strcpy(a.address, "Nabinagar");
    printf("%s\n%d\n%lf\n%s\n%s\n%s\n",a.name,a.id,a.cgpa,a.email,a.number,a.address);
    return 0;
}