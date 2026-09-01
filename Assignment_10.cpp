#include<iostream>
using namespace std;

class Employee {
    
    int id;
    double salary;
    public :
    //static int employeCount;
    Employee(): id(0),salary(0){
       // employeCount++;
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

   virtual void accept(){
        //cout<<"Employee accept:"<<endl;
        cout<<"Enter Id : ";
        cin>>this->id;
        cout<<"Enter Salary : ";
        cin>>this->salary;
    }
  virtual void display(){
        cout<<"Employee display:"<<endl;
        cout<<"Id : "<<id<<endl;
        cout<<"Salary : "<<salary<<endl;
    }    

};
//int Employee::employeCount=0;
 
class Manager : virtual public Employee{
    
    protected :
    double bonus;
    public :
    //static int managerCount;
    Manager():bonus(0.0){
      //  managerCount++;
   //   cout<<"Manager ()"<<endl;
    }
    Manager(int id,double salary,double bonus) : bonus(bonus),Employee(id,salary){
        // managerCount++;
        //   cout<<"Manager"<<endl;
    }
    void setBonus(double bonus){
        this->bonus=bonus;
    }
    double getBonus(){
        return bonus;
    }
     void accept(){
        Employee::accept();
        acceptManager();
    }
    void display(){
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
//int Manager::managerCount=0;

class Salesman : virtual public Employee {
   
    protected :
    double commisson;
     public :
  //    static int salesManCount;
    Salesman(){
     // salesManCount++;
    }
    Salesman(int id,double salary,double commisson): Employee(id,salary),commisson(commisson){
     //  salesManCount++;
    }
    void setCommission(double commison){
        this->commisson=commison;
    }
    double getCommission(){
        return commisson;
    }
     void accept(){
       Employee::accept();
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
//int Salesman::salesManCount=0;

class SalesManager :public Manager,Salesman{
    
    public :
  //  static int salesManagerCount;
    SalesManager(){
    //   salesManagerCount++;
    }
    SalesManager(int id ,double salary,double bonus,double commision):Manager(id,salary,bonus),Salesman(id,salary,commision),Employee(id,salary){
  //    salesManagerCount++;

    }
   void accept(){
     Employee::accept();
    Manager::acceptManager();
    Salesman::acceptSalesman();
   }
   void display(){
    Employee::display();
    displayManager();
    displaySalesMan();
   }

};
class ArrayOutOfBoundException{
    private :
    string msg;
    public :
    ArrayOutOfBoundException(string msg){
       this->msg=msg;
    }
    string geMessage(){
        cout<<msg<<endl;
    }

    
};
int getChoice(){
    cout<<"1. Manager :"<<endl;
    cout<<"2. Salesman : "<<endl;
    cout<<"3. SalesManager : "<<endl;
    cout<<"4. DisplayCount : "<<endl;
    cout<<"5. Display All Managers"<<endl;
    cout<<"6. Display All Salesman :"<<endl;
    cout<<"7. Display All SalesManagers :"<<endl;
    int choice;
    cout<<"Enter Choice : "<<endl;
    cin>>choice;
   return choice;
}

int main(){

    int manager=0;
    int salesMan=0;
    int salesManager=0;

 
  Employee *emp[10];
  int element=0;
 int ch;
 while((ch=getChoice())!=0){
    switch(ch){
     case 1:{

     if(element<10){
     emp[element]=new Manager();
     emp[element]->accept();
     element++;
     
    }
    else{
        cout<<"cart is full"<<endl;
    }
     break;}
    case 2:{
    if(element<10){
    emp[element]=new Salesman();
    emp[element]->accept();
    element++;

}else{
    cout<<"Cart is a full"<<endl;
}
    break;}
    case 3:{
    if(element<10){
    emp[element]=new SalesManager();
    emp[element]->accept();
    element++;
     }
     else{
        cout<<"Cart is a full"<<endl;
     }
    break;}
    case 4 :{
      cout<<"--------------------------------"<<endl;
      int manager=0;
      int salesMan=0;
      int salesManager=0; 
      for(int i=0;i<element;i++){
        if(dynamic_cast<SalesManager*>(emp[i])){
            salesManager++;
        }
        else if(dynamic_cast<Manager*>(emp[i])){
            manager++;
        }
        else if(dynamic_cast<Salesman*>(emp[i])){
            salesMan++;
        }
        

       }
       cout<<"Manager : "<<manager<<endl;
       cout<<"SalesMan : "<<salesMan<<endl;
       cout<<"SalesManager : "<<salesManager<<endl;
    }
    break;
    case 5 :
    {
       // Tape *t = dynamic_cast<Tape*>(p);
       for(int i=0;i<element;i++){
       Manager *manager=dynamic_cast<Manager*>(emp[i]);
       if(manager!=NULL&&
           dynamic_cast<SalesManager*>(emp[i]) == NULL){
           cout<<"-----manager------"<<endl;
            emp[i]->display();
       }
    }
    break;
    }
    case 6 :
    {
        for(int i=0;i<element;i++){
            Salesman *salesman=dynamic_cast<Salesman*>(emp[i]);
            if(salesman!=NULL &&
           dynamic_cast<SalesManager*>(emp[i]) == NULL){
                cout<<"------------Salesman------"<<endl;
                emp[i]->display();
                cout<<"---------------------"<<endl;
            }
        }
        break;

    }
    case 7 :
    {
        for(int i=0;i<element;i++){
            SalesManager *salesManager=dynamic_cast<SalesManager*>(emp[i]);
            if(salesManager!=NULL){
                cout<<"---------salesmanger----------"<<endl;
                emp[i]->display();
                cout<<"---------------------"<<endl;
            }
        }
        break;
    }
    default :{
        cout<<"Enter a vaild input....";
    }
    
    }
 }





}