#include<iostream>
using namespace std;
class CalculateVolume{
    private :

    float length;
    float width;
    float height;


     public :

    CalculateVolume(){
      this->length=8.8;
      this->width=3.3;
      this->height=2.4;
      
    }
CalculateVolume(float val){
    this->length=val;
    this->width=val;
    this->height=val;
}
    CalculateVolume(float length,float width,float height){
      this->length=length;
      this->width=width;
      this->height=height;
    }
    void printVolume(){
        cout<<"Volume :"<<length*width*height<<endl;
    }
 

};
int getChoice(){
  cout<<"Enter 1 Volume with default value : "<<endl;
  cout<<"Enter 2 Volume with length,breath,height with same value"<<endl;
  cout<<"Enter 3 Volume with length,breath,height with different value"<<endl;
  cout<<"Enter 0 Exit : "<<endl;
  cout<<"Enter Choice :";
  int ch;
  cin>>ch;
  return ch;
 }
int main(){

int choice=0;

while((choice=getChoice())!=0){
switch(choice){
  case 1 :{
    CalculateVolume box;
    box.printVolume();
     break;
  }
  case 2 : {
    float value;
    cout<<"Enter value";
    cin>>value;
    CalculateVolume box1(value);
    box1.printVolume();
    break;
  }
  case 3 :{
      float length;
      float width;
      float height;
      cout<<"Enter length : ";
      cin>>length;
      cout<<"Enter width : ";
      cin>>width;
      cout<<"Enter height : ";
      cin>>height;
      CalculateVolume box2(length,width,height);
      box2.printVolume();
      break;
  }
  default :
   cout<<"Enter vaild input : ";  
}
}




  return 0;

}