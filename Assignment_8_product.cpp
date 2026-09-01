#include<iostream>
using namespace std;
class Product{
    int id;
    string title;
    float price;
    public:
Product():id(0),title(""),price(0.0){

}
void setId(int id){
this->id=id;
}
int getId(){
    return this->id;
}
void setTitle(string title){
   this->title=title;
}
string getTitle(){
    return this->title;
}
void setPrice(float price){
    this->price=price;
}
float getPrice(){
    return this->price;
}
virtual void accept(){
    cout<<"Enter id : ";
    cin>>this->id;
    cout<<"Enter title :";
    cin>>this->title;
    cout<<"Enter Price :";
    cin>>this->price;
}
virtual void display(){
    cout<<"Id : "<<this->id<<endl;
    cout<<"Title :"<<this->title<<endl;
    cout<<"Price :"<<this->price<<endl;
}
virtual double calculateFinalBil()=0;
};
class Book : public Product{
    private :
    string author;
    public :
    Book():author(""){

    }
  void setAuthor(string author){
   this->author=author;
  }
  string getAuthor(){
    return author;
  }
  
  void accept(){
    Product::accept();
    cout<<"Enter Author : ";
    cin>>this->author;
  }
  void display(){
    Product::display();
    cout<<"Author : "<<author<<endl;
  }
  double calculateFinalBil(){
    float discount=this->getPrice()*0.10;
    float bill =this->getPrice()-discount;
     return bill;
  }
};
class Tape : public Product{
  string artist;
  public:
  Tape():artist(""){

  }
  void setArtist(string artist){
     this->artist=artist;
  }
  string getArtist(){
    return this->artist;
  }
  void accept(){
    Product::accept();
    cout<<"Enter artist :";
    cin>>this->artist;
  }
  void display(){
    Product::display();
    cout<<"Artist : "<<this->artist<<endl;
  }
  double calculateFinalBil(){
    float discount=this->getPrice()*0.05;
    float bill =this->getPrice()-discount;
     return bill;
  }
};
int getChoice(){
    int choice;
    cout<<"1. Tape : "<<endl;
    cout<<"2. Book : "<<endl;
    cout<<"3. Bill : "<<endl;
    cout<<"4. Display : "<<endl;
    cout<<"0 Exit :"<<endl;
    cout<<"Enter Choice : ";
    cin>>choice;
    return choice;
}
int main(){
    int ch;
   Product *product[3];
   int element=0;
   double totalBill=0;
    while((ch=getChoice())!=0){
    
       switch(ch){
        case 1:{
            if(element<3){
            product[element]=new Tape();
            product[element]->accept();
             element++;
             }
            else{
                cout<<"Cart is full : "<<endl;
            }
           break;
        }
        case 2:{
            if(element<3){
            product[element]=new Book();
            product[element]->accept();
            element++;
        }else{
            cout<<"Cart is full : "<<endl;
        }
            break;
        }
        case 3:
         totalBill=0;
             cout<<"---------Bill----------"<<endl;
             for(int i=0;i<element;i++){
                totalBill+=product[i]->calculateFinalBil();
             }
             cout<<"Total Bill : "<<totalBill<<endl;
            break;
        case 4:
          for(int i=0;i<element;i++){
            cout<<"--------------"<<endl;
                product[i]->display();
            cout<<"--------------"<<endl;
            }
            break;

        default:
          break;
       }

    }
    
    for(int i=0; i<element; i++){
    delete product[i];
}

}
