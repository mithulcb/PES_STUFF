#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
#include<conio.h>
#include"mail.h"
#include<stdlib.h>
//#include"c_logs.h"

void create(char *x);//prototype
void details(char *x);
int main1();
void options();
void bill();

int main() 
{ 
    char username[15]; 
    char password[12]; 
    int i=0;
    while (i!=1){
 
    printf("Enter your emplyee name:"); 
    scanf("%s",&username); 
 
    printf("Enter your password:"); 
    scanf("%s",&password); 
 
    if(strcmp(username,"scarlet")==0){ 
        if(strcmp(password,"123")==0){ 
 
        printf("\nWelcome.Login Success!"); 
        i=1 ;
 
        }else{ 
    printf("\nwrong password\n"); 
} 
    }else if(strcmp(username,"jason")==0){ 
        if(strcmp(password,"xyz")==0){ 
 
        printf("\nWelcome.Login Success!\n"); 
        i=1 ;
 
 
        }else{ 
    printf("\nwrong password\n"); 
} 
    }else if(strcmp(username,"drake")==0){ 
        if(strcmp(password,"hello")==0){ 
 
        printf("\nWelcome.Login Success\n!"); 
        i=1 ;
 
 
        }else{ 
    printf("\nwrong password\n"); 
} 
    }
    else{ 
    printf("\nUser doesn't exist"); 
}
    }
options();
return 0; 
} 


void options(){
    int op;
    while (op!=2)
    {
    
    
    printf("\nSELECT CHOICE\n1 -> for billing\n2 -> to logout\nEnter choice:");
    scanf("%d",&op);
    if(op==1){

      main1();

    }
    }

}


int main1() {
   char op;
   char name[100]; 
   printf("HELLO,WELCOME TO XYZ STORE\nEnter customer name:");
   scanf(" %[^\n]s",name);
   printf("Welcome %s\n",name);
   printf("Is this your first time visting us?\nY/N:");
   scanf(" %c",&op);
   if (op=='y' || op=='Y')
   { 
    
      char filename[64];
      FILE *out;
      int age,cust_id,ph_no;
      char email;
      sprintf(filename, "%s.txt", name);
      out = fopen( filename, "w");
      fprintf(out,"%s\n",name);
      fclose(out);
      create(name);
      fclose(out);
      details(filename);
   }else if(op=='n' || op=='N'){
       FILE *add;
        add=fopen("Mail.txt","w");
       char filename[64],email[100];
        FILE *out;
        sprintf(filename, "%s.txt", name);
        out = fopen( filename, "r");
        char line[256];
        fgets(line,256,out);
        fgets(line,256,out);
        fgets(line,256,out);
        fgets(line,256,out);
        fputs(line,add);
        fclose(add);
        fclose(out);
        //fclose(out);
    }


bill();
}
    

void create(char *x)
{
   FILE *fp;
   fp=fopen("customer_names","a");
   fprintf(fp,"%s\n",x);
   fclose(fp);
}

void details(char *x)
{
   FILE *add;
   add=fopen("Mail.txt","w");
   FILE *out;
   FILE *fp;
   int cust_id,ph_num,count=0;
   char email[100],c;
   out = fopen(x, "a");
   fp=fopen("customer_names","r");
   for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n') 
            count = count + 1;
   fclose(fp);
   cust_id=count;
   fprintf(out,"%d\n",cust_id);
   printf("Enter customer phone number:");
   scanf("%d",&ph_num);
   fprintf(out,"%d\n",ph_num);
   printf("Enter customer email id:");
   scanf(" %[^\n]s",&email);
   fprintf(out,"%s\n",email);
   fprintf(add,"%s\n",email);
   fclose(add);
   fclose(out);
}

void bill() {
	struct details {
		char name[20];
		int price;
		int code;
		int qty;
        int tot;
		
	};
	struct details item[50];
    char op;
	int n,i;
    int sum=0;
    FILE *in;
    in = fopen( "Message.txt", "w");
	printf("Enter number of items:");
	scanf("%d",&n);
	fflush(stdin);
	for (i=0;i<n;i++) {
		fflush(stdin);
		printf("Item name:");
		scanf("%[^\n]",item[i].name);
		fflush(stdin);
		printf("Item code:");
		scanf("%d",&item[i].code);
		fflush(stdin);
		printf("Quantity:");
		scanf("%d",&item[i].qty);
		fflush(stdin);
		printf("price:");
		scanf("%d",&item[i].price);
		fflush(stdin);
        item[i].tot=item[i].price*item[i].qty;

        
    

	}
printf("             *****  BILL *****\n");
   //fprintf(in,"             *****  BILL *****");
   printf("----------------------------------------------------------\n");
   printf("S.N.|    NAME           |   CODE   |  QUANTITY |  PRICE  |  TOTAL  |\n");
   printf("----------------------------------------------------------\n");
   //fprintf(in,"----------------------------------------------------------\n");
   //fprintf(in,"S.N.|    NAME           |   CODE   |  QUANTITY |  PRICE  |  TOTAL  |\n");
   //fprintf(in,"----------------------------------------------------------\n");
   for (i=0;i<n;i++){
      printf("%d     %-15s     %-d          %-5d       %-5d     %-5d   \n",i+1,item[i].name,item[i].code,item[i].qty,item[i].price,item[i].tot);
      //fprintf(in,"%d     %-15s     %-d          %-5d       %-5d     %-5d   \n",i+1,item[i].name,item[i].code,item[i].qty,item[i].price,item[i].tot);
      sum+=item[i].tot;}

    printf("----------------------------------------------------------\n");
    printf("TOTAL TO BE PAID IS: %d + 18%% TAX\n",sum);
    //fprintf(in,"----------------------------------------------------------\n");
    //fprintf(in,"TOTAL TO BE PAID IS: %d + 18%% TAX\n",sum);
    sum=sum+(0.18*sum);
    printf("TOTAL TO BE PAID WITH TAX IS: %d\n",sum);
    //fprintf(in,"TOTAL TO BE PAID WITH TAX IS: %d\n",sum);
	printf("Any changes to be made?\nEnter y/n:");
    char ch;
    scanf("%c",&ch);
    if(ch=='y'){
        printf("Ënter type of change\n1->To add\n2->To remove\n3->To change quantity of item\n0->No changes\n");
        int op=5;
		while (op!=0)
		{
		scanf("%d",&op);
        if(op==1){
			printf("Enter no of itmes to be added");
			int no;
			scanf("%d",&no);
			int no1=no+n;
			int j=0;
			for(n;n<no1;n++){
				fflush(stdin);
		printf("Item name:");
		scanf("%[^\n]",item[n].name);
		fflush(stdin);
		printf("Item code:");
		scanf("%d",&item[n].code);
		fflush(stdin);
		printf("Quantity:");
		scanf("%d",&item[n].qty);
		fflush(stdin);
		printf("price:");
		scanf("%d",&item[n].price);
		fflush(stdin);
        item[n].tot=item[n].price*item[n].qty;
			}	
		printf("New bill is");
		printf("             *****  BILL *****\n");
   //fprintf(in,"             *****  BILL *****");
   printf("----------------------------------------------------------\n");
   printf("S.N.|    NAME           |   CODE   |  QUANTITY |  PRICE  |  TOTAL  |\n");
   printf("----------------------------------------------------------\n");
   //fprintf(in,"----------------------------------------------------------\n");
   //fprintf(in,"S.N.|    NAME           |   CODE   |  QUANTITY |  PRICE  |  TOTAL  |\n");
   //fprintf(in,"----------------------------------------------------------\n");
   sum=0;
   for (i=0;i<no1;i++){
      printf("%d     %-15s     %-d          %-5d       %-5d     %-5d   \n",i+1,item[i].name,item[i].code,item[i].qty,item[i].price,item[i].tot);
      //fprintf(in,"%d     %-15s     %-d          %-5d       %-5d     %-5d   \n",i+1,item[i].name,item[i].code,item[i].qty,item[i].price,item[i].tot);
	  sum+=item[i].tot;}
	i+=1;
    printf("----------------------------------------------------------\n");
    printf("TOTAL TO BE PAID IS: %d + 18%% TAX\n",sum);
    //fprintf(in,"----------------------------------------------------------\n");
    //fprintf(in,"TOTAL TO BE PAID IS: %d + 18%% TAX\n",sum);
    sum=sum+(0.18*sum);
    printf("TOTAL TO BE PAID WITH TAX IS: %d\n",sum);
    //fprintf(in,"TOTAL TO BE PAID WITH TAX IS: %d\n",sum);	
	printf("Ënter type of change\n1->To add\n2->To remove\n3->To change quantity of item\n0->No changes\n");
		}
		if(op==2){
			int len=sizeof(item)/sizeof(item[0]);
			printf("Enter object to remove");
			char ob[50];
			scanf(" %[^\n]s",&ob);
			int a=0;
			for(a;a<len;a++)
			{
				if(strcmp(item[a].name,ob)==0){
					int b=a;
					for(b;b<len;b++){
						item[b]=item[b+1];
			

					}
				}
			}printf("New bill is");
		printf("             *****  BILL *****\n");
   //fprintf(in,"             *****  BILL *****");
   printf("----------------------------------------------------------\n");
   printf("S.N.|    NAME           |   CODE   |  QUANTITY |  PRICE  |  TOTAL  |\n");
   printf("----------------------------------------------------------\n");
   //fprintf(in,"----------------------------------------------------------\n");
   //fprintf(in,"S.N.|    NAME           |   CODE   |  QUANTITY |  PRICE  |  TOTAL  |\n");
   //fprintf(in,"----------------------------------------------------------\n");
   sum=0;
   n=n-1;
   for(i=0;i<n;i++){
      printf("%d     %-15s     %-d          %-5d       %-5d     %-5d   \n",i+1,item[i].name,item[i].code,item[i].qty,item[i].price,item[i].tot);
      //fprintf(in,"%d     %-15s     %-d          %-5d       %-5d     %-5d   \n",i+1,item[i].name,item[i].code,item[i].qty,item[i].price,item[i].tot);
      sum+=item[i].tot;}
	i+=1;
    printf("----------------------------------------------------------\n");
    printf("TOTAL TO BE PAID IS: %d + 18%% TAX\n",sum);
    //fprintf(in,"----------------------------------------------------------\n");
    //fprintf(in,"TOTAL TO BE PAID IS: %d + 18%% TAX\n",sum);
    sum=sum+(0.18*sum);
    printf("TOTAL TO BE PAID WITH TAX IS: %d\n",sum);
    //fprintf(in,"TOTAL TO BE PAID WITH TAX IS: %d\n",sum);	
	printf("Ënter type of change\n1->To add\n2->To remove\n3->To change quantity of item\n0->No changes\n");
	}if(op==3){
			int len=sizeof(item)/sizeof(item[0]);
			printf("Enter object to change");
			char ob[50];
			scanf(" %[^\n]s",&ob);
			int a=0;
			for(a;a<len;a++)
			{
				if(strcmp(item[a].name,ob)==0){
					int b;
					printf("Enter new value");
					scanf("%d",&b);
					item[a].qty=b;
					item[a].tot=item[a].price*item[a].qty;
					}
			}printf("New bill is");
		printf("             *****  BILL *****\n");
   //fprintf(in,"             *****  BILL *****");
   printf("----------------------------------------------------------\n");
   printf("S.N.|    NAME           |   CODE   |  QUANTITY |  PRICE  |  TOTAL  |\n");
   printf("----------------------------------------------------------\n");
   //fprintf(in,"----------------------------------------------------------\n");
   //fprintf(in,"S.N.|    NAME           |   CODE   |  QUANTITY |  PRICE  |  TOTAL  |\n");
   //fprintf(in,"----------------------------------------------------------\n");
   sum=0;
   for (i=0;i<n;i++){
      printf("%d     %-15s     %-d          %-5d       %-5d     %-5d   \n",i+1,item[i].name,item[i].code,item[i].qty,item[i].price,item[i].tot);
      //fprintf(in,"%d     %-15s     %-d          %-5d       %-5d     %-5d   \n",i+1,item[i].name,item[i].code,item[i].qty,item[i].price,item[i].tot);
	  sum+=item[i].tot;}
	i+=1;
    printf("----------------------------------------------------------\n");
    printf("TOTAL TO BE PAID IS: %d + 18%% TAX\n",sum);
    //fprintf(in,"----------------------------------------------------------\n");
    //fprintf(in,"TOTAL TO BE PAID IS: %d + 18%% TAX\n",sum);
    sum=sum+(0.18*sum);
    printf("TOTAL TO BE PAID WITH TAX IS: %d\n",sum);
    //fprintf(in,"TOTAL TO BE PAID WITH TAX IS: %d\n",sum);	
	printf("Ënter type of change\n1->To add\n2->To remove\n3->To change quantity of item\n0->No changes\n");
	}
    }
    }
    
    
    
     fprintf(in,"             *****  BILL *****\n");
	fprintf(in,"----------------------------------------------------------\n");
    fprintf(in,"S.N.|    NAME           |   CODE   |  QUANTITY |  PRICE  |  TOTAL  |\n");
    fprintf(in,"----------------------------------------------------------\n");
	sum=0;
   for (i=0;i<n;i++){
	   fprintf(in,"%d     %-15s     %-d          %-5d       %-5d     %-5d   \n",i+1,item[i].name,item[i].code,item[i].qty,item[i].price,item[i].tot);
		sum+=item[i].tot;}
	 fprintf(in,"----------------------------------------------------------\n");
     fprintf(in,"TOTAL TO BE PAID IS: %d + 18%% TAX\n",sum);
    
    printf("do you have a cupon code? y/n: \n");
    char x1;
    scanf("%s",&x1);
    if(x1=='y')
    {
        char cupon[10];
    printf("enter cupon code in capital letters: \n");
    scanf(" %[^\n]s",&cupon);
    if (strcmp(cupon,"GET20")==0)
    {
        sum=sum-0.2*sum;
        printf("The price to be paid after availing cupon code without tax is is:%d\n",sum);
        fprintf(in,"The price to be paid after availing cupon code is:%d\n",sum);
        sum=sum + 0.18*sum;
        printf("The price to be paid after availing cupon code with tax is:%d\n",sum);
        fprintf(in,"The price to be paid after availing cupon code with tax is:%d\n",sum);
    }
    else if (strcmp(cupon,"WIN40")==0)
    {
        sum=sum+0.4*sum;
        printf("The price to be paid after availing cupon code is:%d\n",sum);
        fprintf(in,"The price to be paid after availing cupon code is:%d\n",sum);
        sum=sum + 0.18*sum;
        printf("The price to be paid after availing cupon code with tax is:%d\n",sum);
        fprintf(in,"The price to be paid after availing cupon code with tax is:%d\n",sum);
    }
    

    else{ printf("cupon code is invalid");}
    
    
   
    }
     fclose(in);
    char a1[1];
     printf("do you want the bill to be mailed ?\n");
    scanf("%s",a1);
    if(a1[0]=='Y'||a1[0]=='y'){
     SendMail(0);
    }
    
    
	getch();
}