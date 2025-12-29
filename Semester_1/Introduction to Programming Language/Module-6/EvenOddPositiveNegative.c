#include <stdio.h>
#include <math.h>
int main()
{
    int n,a,b,c,d,e;
    int even=0,odd=0,positive=0,negative=0;
    scanf("%d",&n);
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
    //for a
    if(a%2==0){
        even++;
    }else{
        odd++;
    }if(a>0){
        positive++;
    }else if(a<0){
        negative++;
    }   
    //for b
    if(b%2==0){
        even++;
    }else{
        odd++;
    }if(b>0){
        positive++;
    }else if(b<0){
        negative++;
    }   
    //for c
    if(c%2==0){
        even++;
    }else{
        odd++;
    }if(c>0){
        positive++;
    }else if(c<0){
        negative++;
    }   
    //for d
    if(d%2==0){
        even++;
    }else{
        odd++;
    }if(d>0){
        positive++;
    }else if(d<0){
        negative++;
    }   
    //for e
    if(e%2==0){
        even++;
    }else{
        odd++;
    }if(e>0){
        positive++;
    }else if(e<0){
        negative++;
    }   
    
    printf("Even: %d\n",even);
    printf("Odd: %d\n",odd);
    printf("Positive: %d\n",positive);
    printf("Negative: %d\n",negative);
    return 0;
}