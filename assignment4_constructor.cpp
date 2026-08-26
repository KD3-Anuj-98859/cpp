#include<iostream>
using namespace std;
class TollBooth{
    private :
    unsigned int totalpayingcar;
    unsigned int  totalunpayingcar;
     float totalAmount;


public :
    TollBooth(){
      this->totalpayingcar=0;
      this->totalunpayingcar=0.0;
      this->totalAmount=0.0;
    }
    void payingCar(){
        this->totalpayingcar++;
        this->totalAmount=this->totalAmount+0.50;
    }
    void nopayCar(){
         this->totalunpayingcar++;
    }
    void printOnConsole(){
        cout<<"Total number of paying car : "<<totalpayingcar<<endl;
        cout<<"Total number of unpaying car: "<<totalunpayingcar<<endl; 
        cout<<"Total Amount : "<<totalAmount<<endl;
    }
};
int getChoice(){
    cout<<"Enter 1 : Paying Car "<<endl;
    cout<<"Enter 2 : Unpaying Car "<<endl;
    cout<<"Enter 3 : Print Total"<<endl;
    cout<<"Enter 0 : Exit ";
    int choice;
    cout<<"Enter Choice : ";
    cin>>choice;
    return choice;
}
int main(){
TollBooth tollbooth;
int ch;
while((ch=getChoice())!=0){
   switch (ch){
    case 1:{
    tollbooth.payingCar();
    break;}
    case 2:{
    tollbooth.nopayCar();
    break;}
    case 3:{
    tollbooth.printOnConsole();
    break;}
    default :
    
    break;
   }
   
   
}

}