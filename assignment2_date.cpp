#include<iostream>
using namespace std;
class Date{
    private :
      int day;
     int month;
     int year;
   public :
    void initDate(){
        day=0;
        month=0;
        year=0;
    }
    void printDateOnConsole(){
        cout<<"--------PrintData--------"<<endl;
        cout<<"Day   : "<<day<<endl;
        cout<<"Month : "<<month<<endl;
        cout<<"Year  : "<<year<<endl;
    }
    void acceptDateFromConsole(){
        cout<<"Enter Day : "<<endl;
        cin>>day;
        cout<<"Enter Month : "<<endl;
        cin>>month;
        cout<<"Enter Year : "<<endl;
        cin>>year;
    }
    bool isLeapYear(){
        if((year%4==0&&year%100!=0)||(year%400==0)){
            return true;
        }
        else{
            return false;
        }
    }
};
int getChoice(){
    
    cout<<"Enter 1 InitDate       "<<endl;
    cout<<"Enter 2 AcceptDate     "<<endl;
    cout<<"Enter 3 PrintDate      "<<endl;
    cout<<"Enter 4 CheckLeapYear  "<<endl;
    cout<<"Enter 0 Exit"<<endl;
    cout<<"Enter choice : "<<endl;
    int choice;
    cin>>choice;
   return choice;
}
int main(){
    Date date;
   int ch;
   while((ch=getChoice())!=0){
    switch (ch)
    {
    case 1:
        date.initDate();
        break;
    
    case 2:
       date.acceptDateFromConsole();
       break;
    case 3:
        date.printDateOnConsole();
        break;
    case 4:
       if(date.isLeapYear()){
        cout<<"leap year......"<<endl;
       }
       else{
        cout<<"not a leap year........."<<endl;
       }

    default:
        break;
    }

   }

   return 0;
}