#include<stdio.h>
int main()
{
  int dt = 1, month = 1, year = 2020,flag = 0;
  printf("\nEnter the date : ");
  scanf("%d",&dt);
  printf("\nEnter the month : ");
  scanf("%d",&month);
  printf("\nEnter the year : ");
  scanf("%d",&year);
  if(month == 2)
  {
    if(year % 4 == 0)
    {
     if(year % 100 == 0)
     {
      if(year % 400 == 0)
      {
        if(dt >= 1 && dt < 29)
        {
          dt += 1;
        }
        else if(dt == 29)
        {
          dt = 1;
          month += 1;
        }
        else
        {
          flag = 1;
          printf ("\nEnter valid date");
        }
      }
      else
     {
     if(dt >= 1 && dt < 28)
     {
       dt += 1;
     }
     else if(dt == 28)
        {
          dt = 1;
          month += 1;
        }
     else
     {
       flag = 1;
       printf ("\nEnter valid date");
     }
    }
   }
   else
   {
     if(dt >= 1 && dt < 29)
     {
       dt += 1;
     }
     else if(dt == 29)
        {
          dt = 1;
          month += 1;
        }
     else
     {
       flag = 1;
       printf ("\nEnter valid date");
     }
    }
  }
  else
   {
     if(dt >= 1 && dt < 28)
     {
       dt += 1;
     }
     else if(dt == 28)
        {
          dt = 1;
          month += 1;
        }
     else
     {
       flag = 1;
       printf ("\nEnter valid date");
     }
    }
   }
  
else if(month == 1 || month == 3)
{
  if(dt >= 1 && dt < 31)
  {
     dt += 1;
  }
  else if(dt == 31)
  {
    dt = 1;
    month += 1;
  }
  else
  {
     flag = 1;
     printf ("\nEnter valid date");
  }
}
else if(month == 5 || month == 7)
{
  if(dt >= 1 && dt < 31)
  {
     dt += 1;
  }
  else if(dt == 31)
  {
    dt = 1;
    month += 1;
  }
  else
  {
     flag = 1;
     printf ("\nEnter valid date");
  }
}
else if(month == 8 || month == 10)
{
  if(dt >= 1 && dt < 31)
  {
     dt += 1;
  }
  else if(dt == 31)
  {
    dt = 1;
    month += 1;
  }
  else
  {
     flag = 1;
     printf ("\nEnter valid date");
  }
}
else if(month == 12 && (year >= 2000 && year <= 2030))
{
  if(dt >= 1 && dt < 31)
  {
     dt += 1;
  }
  else if(dt == 31)
  {
    dt = 1;
    month = 1;
    year += 1;
  }
  else
  {
     flag = 1;
     printf ("\nEnter valid date");
  }
}
else if(month == 4 || month == 6)
{
  if(dt >= 1 && dt < 30)
  {
     dt += 1;
  }
  else if(dt == 30)
  {
   dt = 1;
   month += 1;
  }
  else
  {
     flag = 1;
     printf ("\nEnter valid date");
  }
}
else if(month == 9 || month == 11)
{
  if(dt >= 1 && dt < 30)
  {
     dt += 1;
  }
  else if(dt == 30)
  {
   dt = 1;
   month += 1;
   }
  else
  {
     flag = 1;
     printf ("\nEnter valid date");
  }
}
if(flag == 0)
{
  printf("\nThe next date is : %d/%d/%d", dt, month, year);
}
}
