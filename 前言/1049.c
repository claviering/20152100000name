#include<stdio.h>  
#include<math.h>  
#define PI 3.141592653  
int main()  
{  
    int m,n,i;  
    double b,c;  
    double x,y;  
    scanf("%d",&m);  
        for(i=1;i<=m;i++)  
        {  
            scanf("%lf %lf",&x,&y);  
            n=(x*x+y*y)*PI/100;  
            b=50*n-(x*x+y*y)*PI/2;  
            c=50*(n+1)-(x*x+y*y)*PI/2;  
            if(b<0&&c>0)  
                n=n+1;  
            printf("Property %d: This property will begin eroding in year %d.\n",i,n);  
              
        }  
    printf("END OF OUTPUT.");  
} 
