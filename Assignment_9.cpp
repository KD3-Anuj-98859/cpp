#include<iostream>
using namespace std;
class Employee {
    int id;
    double salary;
    public :
    Employee(): id(0),salary(0){
      //cout<<"Employe()";
    }
    Employee(int id,double salary):id(id),salary(salary){
       //cout<<"Employee(parameter)"<<endl;
    }
    void setId(int id){
        this->id=id;
    }
    int getId(){
        return id;
    }
    void setSalary(double salary){
        this->salary=salary;
    }
    double getSalary(){
        return salary;
    }

   void accecpt(){
        cout<<"Employee accept:"<<endl;
        cout<<"Enter Id : ";
        cin>>this->id;
        cout<<"Enter Salary : ";
        cin>>this->salary;
    }
  void display(){
        cout<<"Employee display:"<<endl;
        cout<<"Id : "<<id<<endl;
        cout<<"Salary : "<<salary<<endl;
    }    

};
class Manager : virtual public Employee{
    protected :
    double bonus;
    public :
    Manager():bonus(0.0){
   //   cout<<"Manager ()"<<endl;
    }
    Manager(int id,double salary,double bonus) : bonus(bonus),Employee(id,salary){
    //   cout<<"Manager"<<endl;
    }
    void setBonus(double bonus){
        this->bonus=bonus;
    }
    double getBonus(){
        return bonus;
    }
     void accept(){
        Employee::accecpt();
        acceptManager();
    }
    virtual void display(){
       Employee::display();
       displayManager();

    }
    protected :
    void acceptManager(){
        cout<<"Enter Bonus: ";
        cin>>bonus;
        
    }
    void displayManager(){
        cout<<"Bonus : "<< bonus<<endl;
    }

};
class Salesman : virtual public Employee {
    protected :
    double commisson;
     public :
    Salesman(){

    }
    Salesman(int id,double salary,double commisson): Employee(id,salary),commisson(commisson){
       cout<<"SalesMan : "<<endl;
    }
    void setCommission(double commison){
        this->commisson=commison;
    }
    double getCommission(){
        return commisson;
    }
     void accecpt(){
       Employee::accecpt();
        acceptSalesman();
     }
     void display(){
         Employee::display();
         displaySalesMan();
     }
     protected:
     void acceptSalesman(){
        cout<<"Enter Commision : ";
        cin>>commisson;
    
     }
     void displaySalesMan(){
       cout<<"Commision : "<<commisson<<endl;
     }
};
class SalesManager :public Manager,Salesman{
    public :
    SalesManager(){

    }
    SalesManager(int id ,double salary,double bonus,double commision):Manager(id,salary,bonus),Salesman(id,salary,commision),Employee(id,salary){
      cout<<"salesManager"<<endl;

    }
   void accecpt(){
     Employee::accecpt();
    Manager::acceptManager();
    Salesman::acceptSalesman();
   }
   void display(){
    Employee::display();
    displayManager();
    displaySalesMan();
   }

};

int main(){


 SalesManager salesmanager;
 salesmanager.accecpt();
 salesmanager.display();
}