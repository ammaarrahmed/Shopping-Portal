#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include"project.cpp"
using namespace std;
int main(){
    Inventory mainInventory;
    mainInventory.loadInventory(mainInventory,"departments.csv","items.csv");
    UserDatabase users;
    users.LoadCustomerDatabase(users,"customers.csv");
    users.LoadAdminDatabase(users,"admin.csv");
    users.LoadVendorDatabase(users,"vendor.csv");
    cash c;
    VisaCard visa;
    vector<VisaCard> visa1;
    visa.loadPaymentDatabase(visa1,"visacards.csv");
    c.loadCashRegister(c,"cash.csv");
    int globalProgramLoopVariable=0;
    int globalCustomerLoopVariable=0;
    int globalAdminLoopVariable=0;
    int globalVendorLoopVariable=0;
    ShoppingCart cart;
    order order1;
    int LoginTYPEchoice=0;
    cout<<"---Welcome to FAST Online Shopping Portal---"<<endl;
    cout<<"---What is your Login type?---"<<endl;
    cout<<"---Please Select your roles---"<<endl; 
    cout<<endl;
    cout<<"choice 1 : Customer"<<endl;
    cout<<"choice 2 : Admin"<<endl;
    cout<<"choice 3 : Vendor"<<endl;
    cout<<"ENTER CHOICE : ";
    cin>>LoginTYPEchoice;
    // customer main
    if (LoginTYPEchoice==1)
    {
        system("CLS");
        bool registeredusercheck=0;
        cout<<"---Welcome to Customer Mode---"<<endl;
        cout<<"Are you a registered person of this application? "<<endl;
        cout<<"enter '1' for YES or '0' for NO : ";
        cin>>registeredusercheck;
        if (registeredusercheck==1)
        {
            system("CLS");
            string password;
            int user_id;
            cout<<"Please enter your user id : ";
            cin>>user_id;
            cout<<"Please Enter your Password : ";
            cin>>password;
            int count=0;
            int inVariable=0;
            for (int i = 0; i <users.s.size(); i++)
            {
                if (users.s[i].getUserId()==user_id && users.s[i].getPassword()==password ){
               count++;
               inVariable=i;
                }
            }
            // customer options while loop
            int customeroptionsloopvariable=1;
            
            if(count==1){
                while(customeroptionsloopvariable==1){
                cart.PrintMenuForExistingCustomer(users.s[inVariable].getName());
                int choice1=0;
                cin>>choice1;
                if (choice1==1)
                {
                    if (cart.GetNumItemsinCart()==0)
                    {
                        system("CLS");
                        cout<<"your cart is empty, please first add items in the cart to place order !!!"<<endl;
                    }
                    else{
                        order1=order(cart.t);
                        cout<<"how would you like to pay for this order? ";
                        cout<<"choice 1 : visa card"<<endl;
                        cout<<"choice 2 : cash"<<endl;
                        cout<<"enter choice : "<<endl;
                        int paymnetchoice=-0;
                        cin>>paymnetchoice;
                        if (paymnetchoice==1)
                        {
                           int temp =visa.getPayment(visa1);
                           if(temp==1){
                              order1.printBill("VisaCard");
                           }
                           else{
                            cout<<"incorrect info!"<<endl;
                           }
                        }
                        else if(paymnetchoice==2){
                            double temp=c.getamount();
                            c.setamount(temp+cart.getCostOfCart());
                            order1.printBill("cash");
                        }
                        
                        
                    }
                    
                }
                else if(choice1==2){
                    system("CLS");
                    for (int i = 0; i <mainInventory.dept.size(); i++)
                    {
                        cout<<i+1<<" "<<mainInventory.dept[i].getName()<<endl;
                    }
                    cout<<endl<<endl;
                    cout<<"--------EXIT (90)--------HOMEPAGE (91)------------DISPLAY CART (92)"<<endl;
                    cout<<"choose : ";
                    int choosedDepartment=0;
                    cin>>choosedDepartment;
                    if(choosedDepartment==90){
                        break;
                    }
                    else if(choosedDepartment==91){

                    }
                    else if(choosedDepartment==92){

                    }
                    else{
                        system("CLS");
                        for(int i=0;i<mainInventory.dept[choosedDepartment-1].t.size();i++){
                        cout<<i<<" ";

                        mainInventory.dept[choosedDepartment-1].t[i].displayItemForCustomer();
                        cout<<endl;
                        }                       
                        cout<<"choose : ";
                        int choosedItem=0;
                        cin>>choosedItem;
                        cout<<"enter desired quantity : ";
                        int choosedQuantity=0;
                        cin>>choosedQuantity;
                        cart.AddItem(mainInventory.dept[choosedDepartment-1].t[choosedItem-1],choosedQuantity);
                        cout<<"Item added to cart successfully !"<<endl;
                    }
                    
                    
                     
                }
                 else if(choice1==3){
                    cart.PrintItemDescription();
                }
                 else if(choice1==4){
                    cout<<"enter the sku of Item you want to search or enter the name of the Item :";
                    string searchitem;
                    cin.ignore();
                    getline(cin,searchitem);
                    int searchItem_INT=stoi(searchitem);
                    for (int i = 0; i < mainInventory.dept.size(); i++)
                    {
                        for (int j = 0; j < mainInventory.dept[i].t.size(); j++)
                        {
                            if (mainInventory.dept[i].t[j].getSKU()==searchItem_INT ||mainInventory.dept[i].t[j].getNameOfItem()==searchitem)
                            {
                                mainInventory.dept[i].t[j].displayItemForCustomer();
                                cout<<"enter 1 to add this item cart : ";
                                int counttemp=0;
                                cin>>counttemp;
                                int tempQuantity=0;
                                cout<<"enter quantity : ";
                                cin>>tempQuantity;
                                if (counttemp==1)
                                {
                                     cart.AddItem(mainInventory.dept[i].t[j],tempQuantity);
                                }
                                
                            }
                            else{
                                cout<<"Item not found :( "<<endl;
                            }
                            
                        }
                        
                    }
                    
                    
                }
                 else if(choice1==5){
                    cout<<"enter the sku of Item you want to remove from cart or enter the name of the Item :";
                    string searchitem;
                    cin.ignore();
                    getline(cin,searchitem);
                    int searchItem_INT=stoi(searchitem);
                    for (int i = 0; i < mainInventory.dept.size(); i++)
                    {
                        for (int j = 0; j < mainInventory.dept[i].t.size(); j++)
                        {
                            if (mainInventory.dept[i].t[j].getSKU()==searchItem_INT ||mainInventory.dept[i].t[j].getNameOfItem()==searchitem)
                            {
                                mainInventory.dept[i].t[j].displayItemForCustomer();
                                int counttemp=0;
                                cin>>counttemp;
                                if (counttemp==1)
                                {
                                     cart.RemoveItem(mainInventory.dept[i].t[j]);
                                     cout<<"item removed successfully !"<<endl;
                                     break;
                                }
                                
                            }
                            else{
                                cout<<"Item not found :( "<<endl;
                            }
                            
                        }
                        
                    }
                }
                 else if(choice1==6){
                    cout<<"total price of the cart is : ";
                    cout<<cart.getCostOfCart();
                }
                 else if(choice1==0){
                    globalCustomerLoopVariable=1;
                }
                }
                
            }
            
            }
        
            
        }
    else if(LoginTYPEchoice==2){
     while(globalAdminLoopVariable==0){
        users.d[0].displayAdminMenu();
        int adminmenuchoice=0;
        cout<<"enter choice : ";
        cin>>adminmenuchoice;
        if (adminmenuchoice==1)
        {
          users.d[0].ADDItem(mainInventory,"items.csv");
        }
        else if(adminmenuchoice==2){
          for (int i = 0; i <mainInventory.dept.size(); i++)
          {
            for(int j=0;j<mainInventory.dept[i].t.size();j++){
             mainInventory.dept[i].t[j].displayItemForAdmin();
            }
          }
          
        }
         else if(adminmenuchoice==3){
            users.d[0].requestItemQuantity(mainInventory);
        }
         else if(adminmenuchoice==4){
            users.d[0].RemoveItem(mainInventory,"items.csv");
        }
         else if(adminmenuchoice==5){
            users.d[0].modifyItem(mainInventory);
        }
         else if(adminmenuchoice==6){
            globalAdminLoopVariable=1;
        }
        else{
            cout<<"wrong choice !!, enter again "<<endl;
        }
        
     }
    }
    else if (LoginTYPEchoice==3){
        int vendorid=0;
        cout<<"enter vendor id for login : ";
        cin>>vendorid;
        string vendorPassword;
        cout<<"enter password : ";
        cin>>vendorPassword;
        int countLoginVendorCheck=0;
        for (int i = 0; i <users.k.size(); i++)
        {
            if (vendorid==users.k[i].getUserId() && vendorPassword==users.k[i].getPassword())
            {
                countLoginVendorCheck++; 
                break;
            }
            
        }
        if (countLoginVendorCheck==1)
        {
            while(globalVendorLoopVariable==0){
                int vendormenuchoice=0;
            users.k[0].vendormenu();
            cout<<"enter choice : ";
            cin>>vendormenuchoice;
            if (vendormenuchoice==1)
            {
                system("CLS");
                users.k[0].seeInventory(mainInventory);
            }
            else if(vendormenuchoice==2){
             system("CLS");
             users.k[0].updateInventory(mainInventory);
            }
            else if(vendormenuchoice==3){
                globalVendorLoopVariable=1;
            }
              
            }
        }
        else{
            cout<<"wrong login information ! "<<endl;
        }
    }   
    else{
        cout<<"wrong choice! please enter again"<<endl;
    }
    }

    
    

