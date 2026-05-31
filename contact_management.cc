#include <bits/stdc++.h>
using namespace std;


// define class contact
class contact
{
public:
    string name;
    long long number;
    string email;
    string address;
    string dob;
    string college;


    contact(string na , long long num, string e, string add, string db,string co )
    {
    name = na;
    number = num;
    email = e;
    address =  add;
    dob = db;
    college =  co;
    }


};

// define sorting condition
bool nameSort(contact p , contact q )
{
    return p.name < q.name;
}

//display contacts 
void display(vector<contact>& contactsBook)
{
for(int i = 0 ; i < contactsBook.size() ; i++)
        {   cout<<"\n==================================================================\n\n";
            cout<<"NAME     :    "<<contactsBook[i].name<<"\n";
            cout<<"CONTACT  :    "<<contactsBook[i].number<<"\n";   
            cout<<"EMAIL    :    "<<contactsBook[i].email<<"\n";  
            cout<<"ADDRESS  :    "<<contactsBook[i].address<<"\n";
            cout<<"DOB      :    "<<contactsBook[i].dob<<"\n";   
            cout<<"COLLEGE  :    "<<contactsBook[i].college<<"\n"; 
        }
        cout<<"\n==================================================================\n";
}




int main()
{
    int choice;
    vector<contact> contactsBook = {
    { "z" , 9121312311 ,"123123@gmail.com" ,"India" ,"10/1/2001" , "MANIT"},
    { "a" , 9123423412 ,"234234@gmail.com" ,"India" ,"20/2/2002" , "MNNIT"},
    { "s" , 9136936913 ,"369369@gmail.com" ,"India" ,"30/3/2003" , "IITB"},
    { "A" , 9178978914 ,"789789@gmail.com" ,"India" ,"10/4/2004" , "MIT"},
    { "Z" , 9145645615 ,"456456@gmail.com" ,"India" ,"20/6/2005" , "MITS"},
    };

    // variable 
    
    //adding
    string name1;
    string email1;
    string address1;
    string dob1;
    string college1;
    long long number1;

    //searching
    string search;
    int start ;
    int end ;
    int found;
    int mid;
    int bookSize;
    
    //deleting
    string del;
    int index ;

    //edit
    string edit;
    

    //design

    cout<<" _______________________________________________________________\n";
    cout<<"|                                                               |\n";
    cout<<"|                           CONTACT LIST                        |\n";
    cout<<"|_______________________________________________________________|\n\n";

    cout<<"             _____________________________________\n";
    cout<<"            |                                     |\n";
    cout<<"            |    1. VIEW FULL CONTACT LIST        |\n";
    cout<<"            |    2. ADD CONTACT                   |\n";
    cout<<"            |    3. SEARCH CONTACT                |\n";
    cout<<"            |    4. EDIT CONTACT                  |\n";
    cout<<"            |    5. DELETE CONTACT                |\n";
    cout<<"            |    6. EXIT                          |\n";
    cout<<"            |_____________________________________|\n\n";

    cout<<"=================================================================\n\n";
    cout<<"                 ENTER A CHOICE 1 to 6 :    ";
    cin>>choice;
    cout<<"\n";



    // main loop

    while(choice != 6)
    {
        switch(choice)
        {
            //view

            case 1 : 
            display(contactsBook);
            break;


            //adding
            
            case 2:
            cout<<"\n==================================================================\n\n";
            cin.ignore(); 
            cout<<"NAME     :    "; getline(cin ,name1);  
            cout<<"CONTACT  :    "; cin>>number1;
            cin.ignore(); 
            cout<<"EMAIL    :    "; getline(cin ,email1);      
            cout<<"ADDRESS  :    "; getline(cin ,address1);  
            cout<<"DOB      :    "; getline(cin ,dob1);  
            cout<<"COLLEGE  :    "; getline(cin ,college1);  

            contactsBook.emplace_back(contact(name1, number1 , email1, address1 , dob1 , college1));

            cout<<"\n==================================================================\n";
            break;


            //search

            case 3:
            cout<<"SEARCH NAME :      "; 
            cin.ignore();
            getline(cin , search);

            bookSize = contactsBook.size();
            start = 0 ;
            end = bookSize - 1;
            found = 0 ;

            while(start <= end)
            {
                mid = (start + end )/2;

                if(contactsBook[mid].name == search)
                {cout<<"\n==================================================================\n\n";
                cout<<"NAME     :    "<<contactsBook[mid].name<<"\n";
                cout<<"CONTACT  :    "<<contactsBook[mid].number<<"\n";   
                cout<<"EMAIL    :    "<<contactsBook[mid].email<<"\n";  
                cout<<"ADDRESS  :    "<<contactsBook[mid].address<<"\n";
                cout<<"DOB      :    "<<contactsBook[mid].dob<<"\n";   
                cout<<"COLLEGE  :    "<<contactsBook[mid].college<<"\n"; 
                cout<<"\n==================================================================\n";
                found = 1;
                break;}

                else if(contactsBook[mid].name > search)
                end =  end - 1;

                else if(contactsBook[mid].name < search)
                start = start + 1;

            }

            if(found == 0)
            cout<< "Not Found";
            break;


            //edit

            case 4 :
            cout<<"EDIT CONTACT : ";
            cin.ignore();
            getline(cin , edit);
                
            bookSize = contactsBook.size();
            start = 0 ;
            end = bookSize -1;
            found = 0;
            for(start ; start <= end ; )
            {
                mid = (start + end )/2;

                if(contactsBook[mid].name == edit)
                {index = mid;
                found = 1;
                break;}


                else if(contactsBook[mid].name > edit)
                end =  end - 1;

                else 
                start = start + 1;

            }
            if(found == 0)
            {cout<< "Not Found";
            break;}
            else
            {   cout<< "ENTER NEW NAME      :     "; 
                getline(cin, contactsBook[index].name);

                cout<< "ENTER NEW NUMBER    :     ";
                cin>>contactsBook[index].number;

                cin.ignore(); 

                cout<< "ENTER NEW EMAIL     :     ";
                getline(cin, contactsBook[index].email);

                cout<< "ENTER NEW ADDRESS   :     ";
                getline(cin, contactsBook[index].address);

                cout<< "ENTER NEW DOB       :     ";
                getline(cin, contactsBook[index].dob);

                cout<< "ENTER NEW COLLEGE   :     ";
                getline(cin, contactsBook[index].college);

            }
            break;



            //delete

            case 5:
            cout<<"DELETE NAME :      "; 
            cin.ignore();
            getline(cin , del);

            bookSize = contactsBook.size();
            start = 0 ;
            end = bookSize - 1;
            found = 0 ;
            index = 1;

            while(start <= end)
            {
                mid = (start + end )/2;

                if(contactsBook[mid].name == del)
                {index = mid;
                found = 1;
                break;}

                else if(contactsBook[mid].name > del)
                end =  end - 1;

                else if(contactsBook[mid].name < del)
                start = start + 1;

            }

            if(found == 0)
            {cout<< "NOT FOUND";
            break;}
            else
            {   contactsBook.erase(contactsBook.begin() + index);
                cout<<"\n***********CONTACT DELETED SUCCESSFULLY*************";}            
            break;

            //default

            default:
            cout<<"\n\n!!!!!!!!!!!!!!     ENTER CORRECT CHOICE        !!!!!!!!!!!!!!!!!!";

        }


    //sorting and updating 
    sort(contactsBook.begin() , contactsBook.end() , nameSort);
    cout<<"\n\n=================================================================\n\n";
    cout<<"                 ENTER A CHOICE 1 to 6 :    ";
    cin>>choice;

    }
}