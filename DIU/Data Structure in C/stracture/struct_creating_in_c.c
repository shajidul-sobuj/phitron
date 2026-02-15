#include <stdio.h>
#include <string.h>

struct student
{
    char name[100];
    int id;
    double gpa;
};

int main()
{
    struct student a;
    strcpy(a.name,"sobuj");
    a.id = 252;
    a.gpa = 1.23;

    printf("Name is: %s\n",a.name);
    printf("ID is: %d\n",a.id);
    printf("CGPA is: %.2lf\n",a.gpa);

    
    return 0;
}