using namespace std;
#include "contacts.h"
#include <iostream>
#include<stdio.h>
#include <string>
#include <string.h>

void contacts::new_contact()
{
    string s;
    cout<<endl<<"Enter contact name: ";
    cin.ignore();
    gets(name);
    do{
        cout<<endl<<"Enter contact number(10 Digits): ";
        cin>>contact_number;
        s = to_string(contact_number);
    }while(s.size()!=10);
    do{
        cout<<endl<<"Enter date of birth (dd/mm/yyyy): ";
        cin>>DOB;
        //s = to_string(DOB);
    }while(strlen(DOB)!=10);
    cout<<endl<<"Enter address: ";
    cin.ignore();
    gets(address);
}

char* contacts::return_contact()
{
    return name;
}

void contacts::display_contact()
{
    cout<<endl<<"Name: "<<name;
    cout<<endl<<"Number: "<<contact_number;
    cout<<endl<<"DOB: "<<DOB;
    cout<<endl<<"Address: "<<address;
}

void contacts::edit_contact()
{
    int choice;
    string s;
    cout<<endl<<"[1]:Edit Name"<<endl<<"[2]:Edit Number"<<endl<<"[3]:Edit DOB"<<endl<<"[4]:Edit Address"<<"[5]:BACK"<<endl<<endl<<"Enter your choice: ";
    cin>>choice;
    switch(choice)
    {
        case 1: system("cls");
                cout<<endl<<"Enter new name: ";
                cin.ignore();
                gets(name);
                break;
        case 2: system("cls");
                do{
                    cout<<endl<<"Enter new number(10 Digits): ";
                    cin>>contact_number;
                    s = to_string(contact_number);
                }while(s.size()!=10);
                break;
        case 3:system("cls");
                do{
                    cout<<endl<<"Enter new DOB(dd/mm/yyyy): ";
                    cin>>DOB;
                }while(strlen(DOB)!=10);
                break;
        case 4:system("cls");
                cout<<endl<<"Enter new Address: ";
                gets(address);
                break;
        default: break;
    };
}
