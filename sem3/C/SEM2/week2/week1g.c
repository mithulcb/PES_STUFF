#include<stdio.h>
#include<math.h>

int main(){
    double a,b,c;
    double r1,r2,d,rP,iP;
    printf("enter the co-efficients for a quadratic equation:");
    scanf("%lf,%lf,%lf",&a,&b,&c);
    d =b*b-4*a*c;
    if (d>0) {
        r1 = (-b + sqrt(d)) / (2 * a);
        r2 = (-b - sqrt(d)) / (2 * a);
        printf("root1 = %f and root2 = %f", r1, r2);
    }else if(d==0){
        r1=r2 =-b/(2 * a);
        printf("root1 = root2 = %f;",r1);
    }else{
        rP = -b / (2 * a);
        iP = sqrt(-d) / (2 * a);
        printf("root1 = %f+%lfi and root2 = %f-%fi",rP,iP,rP,iP);
    }

}