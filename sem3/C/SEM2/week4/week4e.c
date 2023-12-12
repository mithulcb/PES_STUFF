#include<stdio.h>

int Prime(int n)
{
    int i;
    int count = 0;
    for (i=1;i<=n;i++){
        if (n%i==0){
            count++;
            }
        }
    if (count==2){
        return 1;
        }
    else{
    if (count>2){
      return 0;
 }
 }
}
int NextPrime(int n)
{
 int t = n+1;
 while (1){
 if (Prime(t)){
 break;
 }
 t ++;
 }
 return t;
}

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    printf("Next prime number = %d",NextPrime(n));
    return 0;
}
