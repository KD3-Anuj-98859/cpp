#include<iostream>
using namespace std;
class Time{
    private :
   int hour;
   int minute;
   int second;
   public :
  Time() :hour(0),minute(0),second(0){

  }
   Time(int hour,int minute,int second) :hour(hour),minute(minute),second(second){
     
   }

   int getHour(){
    return hour;
   }
   int getMinute(){
    return minute;
   }
   int getSeconds(){
      return second;
   }
   void setHour(int hour){
    this->hour=hour;
   }
   void setMinute(int minute){
    this->minute=minute;
   }
   void setSeconds(int second){
    this->second=second;
   }
   void printTime(){
    cout<<"Hour : "<<hour<<"Minute : "<<minute<<"Seconds : "<<second<<endl;
   }
   ~Time(){
     

   }
};

  void addTime(Time *time,int size){
    int hour;
    int second;
    int minute;
      for(int i=0;i<size;i++){
         cout<<"Enter Hour : ";
         cin>>hour;
    
        cout<<"Enter Minute : ";
         cin>>minute;
    
         cout<<"Enter Second : ";
        cin>>second;
        time[i].setHour(hour);
        time[i].setMinute(minute);
        time[i].setSeconds(second);
        
    }}
    int getChoice(){
        cout<<"Enter 1 : Add Time "<<endl;
        cout<<"Enter 2 : Display All Time "<<endl;
        cout<<"Enter 3 : Display only hrs of all time objects :"<<endl;
        cout<<"Enter 0 : Exit ";
        
        int ch;
        cin>>ch;
      return ch;
    }

  


int main(){
   
   cout<<"How many object you want to create : ";
    int size;
    cin>>size;
    Time *time= new  Time[size];
    int ch;
   while((ch=getChoice())!=0){
    switch (ch)
    {
    case 1:
        addTime(time,size);
        break;
    case 2:
        for(int index=0;index<size;index++){
            time[index].printTime();
        }
       break;
    case 3:
        for(int index=0;index<size;index++){
            cout<<"Hour : "<<time[index].getHour()<<endl;
        }
    default:
       cout<<"Enter Vaild input : ";
        break;
    }

   }
     delete[]time;
     time=nullptr;
    return 0;
}