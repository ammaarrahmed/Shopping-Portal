#include<iostream>
#include<string>
#include<vector>
using namespace std;
class roles{
string name;
int user_id;
string password;
public:
    // Getter and Setter for 'name'
    string getName()  {
        return name;
    }

    void setName( string newName) {
        name = newName;
    }

    // Getter and Setter for 'user_id'
    int getUserId()  {
        return user_id;
    }

    void setUserId(int newUserId) {
        user_id = newUserId;
    }

    // Getter and Setter for 'password'
    string getPassword()  {
        return password;
    }

    void setPassword(string newPassword) {
        password = newPassword;
    }
};
class customer:public roles{
string email;
string address;
int phone_no;
public:
// Getter and Setter for 'address'
    string getAddress() const {
        return address;
    }

    void setAddress(const string& newAddress) {
        address = newAddress;
    }
     // Getter and Setter for 'email'
    string getEmail() const {
        return email;
    }

    void setEmail(const string& newEmail) {
        email = newEmail;
    }
    // Getter and Setter for 'phone_no'
    int getPhoneNo() const {
        return phone_no;
    }

    void setPhoneNo(int newPhoneNo) {
        phone_no = newPhoneNo;
    }
};
class department;
class Inventory{
    public:
vector<department> dept;
};
class admin:public roles{
 public:
 void seeInventory(Inventory p){
    int choice=0;
    for (int i = 0; i <p.dept.size(); i++)
    {
        cout<<i+1<<" ";
        p.dept[i].displayCategory();
        cout<<endl;
    }
    
    cout<<"enter the department you would like to view : ";
    cin>>choice;
    for(int i=0;i<p.dept[choice].t.size();i++){
    p.dept[choice].t[i].displayItemForAdmin();
    } 
 }
 void ADDItem(Inventory p){
    string deptartmentName;
    string name;
    int x;
    double sale;
    double purchase;
    int stock;
    cout<<"enter department name into which you would like to add ITEM : ";
    cin>>deptartmentName;
    cout<<"enter name of ITEM : ";
    cin>>name;
    cout<<"enter SKU of ITEM : ";
    cin>>x;
    cout<<"enter sale price of ITEM : ";
    cin>>sale;
    cout<<"enter purchase price of ITEM : ";
    cin>>purchase;
    cout<<"enter quantity in stock of ITEM : ";
    cin>>stock;
    for (int i = 0; i < p.dept.size(); i++)
    {
        
        if(deptartmentName==p.dept[i].getdepartmentName()){
            Item temp;
            temp=Item(name,x,sale,purchase,stock);
            p.dept[i].AddItem(temp);
            cout<<"ITEM ADDED SUCCESSFULLY !!"<<endl;
            break;
        
        }
    }
    

 }
 void RemoveItem(Inventory p){
    int sku=0;
    cout<<"enter Sku of item you would like to remove : ";
    cin>>sku;
    for (int i = 0; i < p.dept.size(); i++)
    {
        for(int j=0;j<p.dept[i].t.size();j++){

        
        if(sku==p.dept[i].t[j].getSKU()){
            
            p.dept[i].RemoveItem(p.dept[i].t[j]);
            cout<<"ITEM REMOVED SUCCESSFULLY !!"<<endl;
            break;
        }
        }
    }

 }
 void requestItemQuantity(Inventory p){
    int sku,quantity;
       cout<<"enter the sku of the item which you want to request from vendor: ";
       cin>>sku;
       cout<<"enter the quantity of item you want to request : ";
       cin>>quantity;
       for (int i = 0; i <p.dept.size(); i++)
       {
        for (int j = 0; j < p.dept[i].t.size(); j++)
        {
            if(p.dept[i].t[j].getSKU()==sku){
                p.dept[i].t[j].setrequestQuantity(quantity);
                break;
            }
            else{
                cout<<"error, item not found "<<endl;
            }
        }
       }
 }
 void modifyItem(Inventory p){
     int sku=0;
     cout<<"enter sku of item you want to modify : ";
     cin>>sku;
     for (int i = 0; i <p.dept.size(); i++)
     {
        for (int j = 0; j<p.dept[i].t.size(); j++)
        {
            if (p.dept[i].t[j].getSKU()==sku)
     {
       string name1;
       int x;
       double sale;
       double purchase;
       int s;
       cout<<"enter new name of item : ";
       cin>>name1;
       cout<<"enter new sku of item : ";
       cin>>x;
       cout<<"enter new sale price of item : ";
       cin>>sale;
       cout<<"enter new purchase price of item : ";
       cin>>purchase;
       cout<<"enter new stock quantity of item : ";
       cin>>s;
       p.dept[i].t[j].ModifyAnyItem(name1,x,sale,purchase,s);
       break;
     }
     else{
        cout<<"error,item not found"<<endl;
        break;
     }
        }
        
     }
     
     
 }
};
class vendor{
public:
void seeInventory(Inventory p){
    for (int i = 0; i <p.dept.size(); i++)
    {
        for (int j = 0;  j<p.dept[i].t.size(); j++)
        {
            if (p.dept[i].t[j].getrequestquantity()>0)
            {
                p.dept[i].t[j].displayItemForAdmin();
            }
            
        }
        
    }
}
void updateInventory(Inventory p){
     int sku=0,quantity=0;
     cout<<"enter the sku of item you want to update stock of : ";
     cin>>sku;
     cout<<"enter the quantity of stock you would like to add : ";
     cin>>quantity;
      for (int i = 0; i <p.dept.size(); i++)
    {
        for (int j = 0;  j<p.dept[i].t.size(); j++)
        {
            if (p.dept[i].t[j].getSKU()==sku)
            {
                int temp;
                temp=p.dept[i].t[j].getStockQuantity()+quantity;
                p.dept[i].t[j].setStockQuantity(temp);
                p.dept[i].t[j].setrequestQuantity(0);
                break;
            
            }
            
        }
        
    }
}
};
class Item{
   int SKU;
   string name;
  double sale_price,purchase_price;
  int stock_quantity;
  int cart_quantity;
  int requestQuantity;
  public:
  Item(){

  }
  Item(string name1,int x,double sale,double p,int s){
    name=name1;
SKU=x;
sale_price=sale;
purchase_price=p;
stock_quantity=s;
  }
  void setrequestQuantity(int x){
    requestQuantity=x;
  }
  int getrequestquantity(){
    return requestQuantity;
  }
  void setCartQuantity(int x){
    cart_quantity=x;
  }
  int getCartQuantity(){
    return cart_quantity;
  }
  void displayItemForCustomer(){
    cout<<"----------------------------------"<<endl;
    cout<<"NAME : "<<name<<endl;
    cout<<"SKU : "<<SKU<<endl;
    cout<<"sale price : "<<sale_price<<endl;
    cout<<"In stock : "<<stock_quantity<<endl;
    cout<<"----------------------------------"<<endl;
     
    
  }
   void displayItemForAdmin(){
    cout<<"----------------------------------"<<endl;
    cout<<"NAME : "<<name<<endl;
    cout<<"SKU : "<<SKU<<endl;
    cout<<"sale price : "<<sale_price<<endl;
    cout<<"purchase price"<<purchase_price;
    cout<<"In stock : "<<stock_quantity<<endl;
    cout<<"requested quantity from vendor : "<<requestQuantity<<endl;
    cout<<"----------------------------------"<<endl;
  }
  void setSKU(int x){
    SKU=x;
  }
  int getSKU(){
    return SKU;
  }
  void setSalePrice(double x){
    sale_price=x;
  }
  double getSalePrice(){
    return sale_price;
  }
  void setPurchasePrice(double x){
    purchase_price=x;
  }
  double getPurchasePrice(){
    return purchase_price;
  }
  void setStockQuantity(int x){
    stock_quantity=x;
  }
  int getStockQuantity(){
    return stock_quantity;
  }
  
  
  void ModifyAnyItem(string name1,int x,double sale,double p,int s){
    name=name1;
SKU=x;
sale_price=sale;
purchase_price=p;
stock_quantity=s;
  }
  
};
class department{
    string department_name;
    
    public:
    vector<Item> t;
    department(){

    }
    department(string p){
department_name=p;
    }
    string getdepartmentName(){
        return department_name;
    }
    void displayCategory(){
        cout<<department_name<<endl;
    }
    void AddItem(Item p){
    
        t.push_back(p);
}
void RemoveItem(Item p){
    for (int i = 0; i < t.size(); i++)
    {
         if(t[i].getSKU()==p.getSKU()){
        t.erase(t.begin()+i);
         }
    }
    
}

};
class ShoppingCart{
vector<Item> t;
int sizeOfCart;
public:
ShoppingCart(){
    sizeOfCart=0;
}

void AddItem(Item p,int quantity){
    
        t.push_back(p);
    t[t.size()].setCartQuantity(quantity);
    sizeOfCart++;
}
void RemoveItem(Item p){
    for (int i = 0; i < sizeOfCart; i++)
    {
         if(t[i].getSKU()==p.getSKU()){
        t.erase(t.begin()+i);
        sizeOfCart--;
         }
    }
}
int GetNumItemsinCart(){
    return sizeOfCart;
}
double getCostOfCart(){
    double cost=0.0;
    for (int i = 0; i <t.size(); i++)
    {
        cost=cost+(t[i].getSalePrice()*(t[i].getCartQuantity()));
    }
    
}
void PrintTotalItems(){
    if(t.size()==0){
        cout<<"\nSHOPPING CART IS EMPTY "<<endl;

    }
    else{
        cout<<" total items in cart are : "<<t.size()<<endl;
    }
}
void PrintItemDescription(){
    for (int i = 0; i < t.size(); i++)
    {
        t[i].displayItemForCustomer();
    }
    
}
void PrintMenu(){
    int choice=0;
    cout<<"choice 1 : Place order"<<endl;
    cout<<"choice 2 : Add item to cart"<<endl;
    cout<<"choice 3 : display cart items "<<endl;
    cout<<"choice 4 : search Item in cart "<<endl;
    cout<<"choice 5 : remove Item "<<endl;
    cout<<"choice 6 : total price of cart"<<endl;
    cout<<"choice 7 : exit the program"<<endl;
    cout<<"enter choice : ";
    cin>>choice;
    if(choice==1){
     
    }
    else if(choice==2){

    }
    else if(choice==3){

    }
    else if(choice==4){
        
    }
    else if(choice==5){
        
    }
    else if(choice==6){
        
    }
    else{

    }
}
};
class file{
  
};