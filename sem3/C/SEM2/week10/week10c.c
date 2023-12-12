#include<stdio.h> 
#include<string.h> 
#include<stdlib.h>
enum month 
{ 
 none,jan,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec 
} months; 
static char *monthss[] = {"Not a month","jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"}; 
static int day[] = {-1,31,28,31,30,31,30,31,31,30,31,30,31}; 
enum month translate(char *x) 
{ 
 if (strcmp(x, "jan") == 0) 
 { 
 return jan; 
 } 
 else if (strcmp(x, "feb") == 0) 
 { 
 return feb; 
 } 
 else if (strcmp(x, "mar") == 0) 
 { 
 return mar; 
 } 
 else if (strcmp(x, "apr") == 0) 
 { 
 return apr; 
 } 
 else if (strcmp(x, "may") == 0) 
 { 
 return may; 
 } 
 else if (strcmp(x, "jun") == 0) 
 { 
 return jun; 
 } 
 else if (strcmp(x, "jul") == 0) 
 { 
 return jul; 
 } 
 else if (strcmp(x, "aug") == 0) 
 { 
return aug;
 } 
 else if (strcmp(x, "sep") == 0) 
 { 
 return sep; 
 } 
 else if (strcmp(x, "oct") == 0) 
 { 
 return oct; 
 } 
 else if (strcmp(x, "nov") == 0) 
 { 
 return nov; 
 } 
 else if (strcmp(x, "dec") == 0) 
 { 
 return dec; 
 } 
 else 
 { 
 return none; 
 } 
} 
void check (int x, enum month p) 
{ 
 if ((p == none) || (x < 1) || (x > day[months])) 
 { 
 printf("\nInvalid Input.\n"); 
 exit(0); 
 } 
} 
void next(int x, enum month p) 
{ 
 if (x < day[p]) 
 { 
 printf("\nTomorrow's date is %d %s\n", x+1, monthss[p]); 
 } 
 else if ((x == day[p]) && (monthss[p] != "dec")) 
 { 
 printf("\nTomorrow's date is 1 %s\n", monthss[p+1]); 
}
 else 
 { 
 printf("\nTomorrow's date is 1 jan\n"); 
 } 
} 
int main() 
{ 
 int day; 
 char mon[4]; 
 printf("\nEnter the date: "); 
 scanf("%d%s", &day, mon); 
 months = translate(mon); 
 check(day, months); 
 next(day, months); 
 return 0; 
} 