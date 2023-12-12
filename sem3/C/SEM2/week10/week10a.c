#include<stdio.h> 
#include<stdlib.h> 
#include "week10a1.h" 
int main() 
{ 
 int a[10] = {1, 3, 4, 10, 14, 29, 22, 144, 149, 240}; 
 int ele = 0, low = 0, high = 9, mid = (low + high)/2; 
 printf("\nEnter the element to be searched for: "); 
 scanf("%d", &ele); 
 search_ele(low, high, mid, a, ele, check_even); 
 search_ele(low, high, mid, a, ele, check_lessthn22); 
 return 0; 
} 