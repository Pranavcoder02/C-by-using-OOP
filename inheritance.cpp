#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class person{

    private:
    string person_name;
    string cell_phone;
    string city_name;   
    
    public: 
    void getperson(){

    cout<<"Enter the person name"<<endl;
    cin>> person_name;
    
    cout<<"Enter the person phone number"<<endl;
    cin>>cell_phone;
    
    cout<<"Enter the person city name"<<endl;
    cin>>city_name;
   
    
    }
    
   //for displaying the data 
    void displaydata(){
 
       cout<<person_name<<setw(15);cout<<cell_phone<<setw(15);cout<<city_name<<setw(15);
    }
   
};



class employee:public person{

    private:
    string employee_id;
    string employee_designation;
    string salary;
    
    public:
   
    
         
  //for entering the data
    void getemployee(){
  
    cout<<"Enter the employee id"<<endl;
    cin>>  employee_id;
    
    cout<<"Enter the employee designation"<<endl;
    cin>>employee_designation;
    
    cout<<"Enter the employee salary"<<endl;
    cin>>salary;
    
     getperson();
   
    
}
    
 //displaying the data...   
  void displayemployee(){
      cout<<employee_id<<setw(15);cout<<employee_designation<<setw(15);cout<<salary<<setw(15);
      displaydata();
      
      cout<<endl;

  }
};

int main(){

 employee e;
 
 e.getemployee();
 e.displayemployee();
}
