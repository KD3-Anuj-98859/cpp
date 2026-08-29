#include<iostream>
using namespace std;
class Date{
   private :
    int day;
    int month;
    int year;
  public :
    Date() : day(0),month(0),year(0){

   }
   Date(int day,int month,int year) : day(day),month(month),year(year){

   }
   void acceptDate(){
    cout<<"\nEnter Day : ";
    cin>>day;
    cout<<"Enter Month : ";
    cin>>month;
    cout<<"Enter Year  : ";
    cin>>year;

   }
   void showDate(){
    cout<<"Date  :  "<<day<<"-"<<month<<"-"<<year<<endl;
   }

};
class Person{
    private :
    string name;
    string address;
    Date birthDate;
    public :
    Person() : name(""),address(""),birthDate(){

    }
    Person(string name,string address,Date birthDate) : name(name),address(address),birthDate(birthDate){

    }
    Person(string name,string address,int day,int month,int year) : name(name),address(address),birthDate(day,month,year){

    }
    void acceptPerson(){
     
    
    cout<<"\nEnter  name : ";
     cin>>name;
    cout<<"\nEnter address : ";
    cin>>address;
    birthDate.acceptDate();

   }
    void printPerson(){
        cout<<"\nName of Person  :  "<<name<<endl;
        cout<<"Name of Address :  "<<address<<endl;
        birthDate.showDate();

    }
};
class Student{
    private :
    int id;
    int marks;
    string course;
    Date joiningDate;
    Date endingDate;
     public :
    Student() : id(0),marks(0){

    }
    Student(int id,int marks,string course,Date joiningDate,Date endingDate) : id(id), marks(marks),course(course),joiningDate(joiningDate),endingDate(endingDate){
        cout << "Enter Joining Date:";
    joiningDate.acceptDate();

    cout << "Enter Ending Date:";
    endingDate.acceptDate();
    }
    Student(int id,int marks,string course,int day,int month,int year,int day1,int month2,int year3) : id(id), marks(marks),course(course),joiningDate(day,month,year),endingDate(day1,month2,year3){

    }
    void acceptStudent(){
        
         cout<<"\nEnter id : ";
         cin>>id;
         cout<<"\nEnter Marks : ";
         cin>>marks;
         cout<<"\nEnter Course : ";
          cin>>course;
         cout<<"\nEnter Joining Date : ";
          joiningDate.acceptDate();
          cout<<"\nEnter Ending Date : ";
          endingDate.acceptDate();

         
        
    }
    void printStudent(){
        cout<<"\nStudent Id : "<<id<<endl;
        cout<<"Marks      : "<<marks<<endl;
        cout<<"Course     : "<<course<<endl;
        cout<<"Joining ";
        joiningDate.showDate();
        cout<<"Ending";
        endingDate.showDate();
    }
};

int main(){
    cout<<"-------------Person Manual value------------------";
   Person person1("Anuj","Adress",14,12,2055);
   person1.printPerson();
   cout<<"--------------Student Manual Value----------------";
   Student student1(101,55,"CPP",1,2,2026,2,3,2027);
   student1.printStudent();
cout<<"----------------Person Details---------------";
     Person person;
     person.acceptPerson();
     person.printPerson();
cout<<"------------------Student details---------------";
     Student student;

     student.acceptStudent();
     student.printStudent();
 
}