#include <stdio.h>
 
int main() {
 
    long long int d1,d2,h1,h2,m1,m2,s1,s2;
    long long int sd1,sd2,sd;
    printf("Enter 1st day:");
    scanf("%lld,&d1");
    scanf("%lld %lld %lld",&h1, &m1, &s1);
    printf("Enter 2nd day:");
    scanf("%lld,&d2");
    scanf("%lld %lld %lld",&h2, &m2, &s2);
    sd1=((d1*86400)+(h1*3600)+(m1*60)+s1);
    sd2=((d2*86400)+(h2*3600)+(m2*60)+s2);
    sd=sd2-sd1;
    
    printf("%lld",sd);
    long long int d,h,m,s;
    d=sd/86400;
    sd=sd-(d*86400);
    h=sd/3600;
    sd=sd-(d*3600);
    m=sd/60;
    sd=sd-(d*60);
    s=sd;
    printf("%lld dia(s)\n",d);
    printf("%lld hora(s)\n",h);
    printf("%lld minuto(s)\n",m);
    printf("%lld segundo(s)\n",s);
    
 
    return 0;
}