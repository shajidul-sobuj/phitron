#include <stdio.h>

int main()
{
    int r,c;
    scanf("%d %d",&r,&c);
    int a[r][c];
    for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) {
            scanf("%d",&a[i][j]);
        }
    }
    if (r==c) {
        printf("Its a Square Matrix!\n");
    }else {
        printf("Its not a square Matrix!\n");
    }
    return 0;
}


// computerclubmist@gmail.com
// mist.mcsc@gmail.com
// roboticsclub@mist.ac.bd

// Computer Club
// Cyber Security Club
// Robotics Club
