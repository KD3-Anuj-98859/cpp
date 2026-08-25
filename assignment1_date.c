#include<stdio.h>
struct Date{
    int day;
    int month;
    int year;
};
void initDate(struct Date* ptrDate){
     ptrDate->day=0;
    ptrDate->month=0;
    ptrDate->year=0; 
}
void printDateOnConsole(struct Date* ptrDate){
    printf("--------PrintData--------\n");
     printf("day = %d\n",ptrDate->day);
     printf("month = %d\n",ptrDate->month);
     printf("Year = %d\n",ptrDate->year);
}
void acceptDateFromConsole(struct Date* ptrDate){
    printf("Enter day : ");
    scanf("%d",&ptrDate->day);
    printf("Enter month : ");
    scanf("%d",&ptrDate->month);
    printf("Enter year : ");
    scanf("%d",&ptrDate->year);
}
int getChoice(){
    printf("Enter 1 : Init Date\n");
    printf("Enter 2 : Accept Date\n");
    printf("Enter 3 : Print Date\n");
    printf("Enter 0 : Exit");
int ch;
    printf("\nEnter choice :");
scanf("%d",&ch);
return ch;
}
int main(){
  struct Date date;
  struct Date *ptr=&date;
  int ch;
  while((ch=getChoice())!=0){
    switch (ch)
    {
    case 1:
       initDate(&date);
        break;
    case 2:
    acceptDateFromConsole(ptr); 
    break;
    case 3:
    printDateOnConsole(ptr);
    break;
    default:

        break;
    }
  
  }
}