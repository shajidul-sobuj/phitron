#include <stdio.h>
 
int main() {
 
    int d1,d2,h1,h2,m1,m2,s1,s2;
    long long int sd1,sd2,sd;
    scanf("Dia %d", &d1);
    scanf("%d : %d : %d", &h1, &m1, &s1);
    scanf("Dia %d", &d2);  
    scanf("%d : %d : %d", &h2, &m2, &s2);

    sd1=((d1*86400)+(h1*3600)+(m1*60)+s1);
    sd2=((d2*86400)+(h2*3600)+(m2*60)+s2);
    sd=sd2-sd1;
    int d,h,m,s;
    d=sd/86400;
    sd=sd-(d*86400);
    h=sd/3600;
    sd=sd-(h*3600);
    m=sd/60;
    sd=sd-(m*60);
    s=sd;

    printf("%d dia(s)\n",d);
    printf("%d hora(s)\n",h);
    printf("%d minuto(s)\n",m);
    printf("%d segundo(s)\n",s);
    return 0;
}