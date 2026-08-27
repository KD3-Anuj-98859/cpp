#include<iostream>
using namespace std;
class Cylinder{
    private :
    double radius;
    double height;
    static double pi;
    public :
   
   Cylinder() 
   { 
    this->radius=radius;
    this->height=height;

    }
    Cylinder(double radius,double height) : radius(radius),height(height){
    
    }
    double getRadius(){
        return this->radius;
    }
    void setRadius(double radius){
        this->radius=radius;
    }
    double getHeight(){
       return this->height;
    }
    void setHeight(double height){
         this->height=height;
    }
    void calculateVolume(){
        cout<<"Cylinder Volume : "<<pi*radius*radius*height<<endl;
    }
};
double Cylinder :: pi = 3.14;

int main(){
   Cylinder* cylinder =new Cylinder();

   cylinder->calculateVolume();
   cylinder->setHeight(2.2);
   cylinder->setRadius(3.3);
   cout<<"Height : "<<cylinder->getHeight()<<endl;
   cout<<"Radius : "<<cylinder->getRadius()<<endl;
   cylinder->calculateVolume();

   Cylinder* cylinder1=new Cylinder(2.2,3.3);

    
    cout<<"Radius :"<<cylinder1->getRadius()<<endl;
    cout<<"Height :"<<cylinder1->getHeight()<<endl;
      cylinder1->setHeight(5.2);
   cylinder1->setRadius(6.3);
   
    cout<<"Radius :"<<cylinder1->getHeight()<<endl;
    cout<<"Height :"<<cylinder1->getRadius()<<endl;
    cylinder1->calculateVolume();

   return 0;

}