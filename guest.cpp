#include <iostream>
#include "guest.h"
#include <stdio.h>
#include <string>

using namespace std;

void guest::register_guest()
{
    string s;
    cout<<endl<<"Enter Name: ";
    cin.ignore();
    getline(cin,name);
    do{
        cout<<endl<<"Enter Contact Number(10 Digits): ";
        cin>>phone_number;
        s = to_string(phone_number);
    }while(s.size()!=10);
    do{
        cout<<endl<<"Enter Emergency contact(10 Digits): ";
        cin>>emergency_contact;
        s = to_string(emergency_contact);
    }while(s.size()!=10);

    cout<<endl<<"Set your Username: ";
    cin.ignore();
    getline(cin,username);
    cout<<endl<<"Set your PIN: ";
    cin>>pin;
}

void guest::update_guest()
{
    int n;
    string s;
    cout<<"\t\t\t\t\t\t\t\tUPDATION MENU";
    cout<<endl<<"[1]:Update Name"<<endl<<"[2]:Update Phone Number"<<endl<<"[3]:Update Emergency Contact"<<endl<<"[4]:Update Username"<<endl<<"[5]:Update PIN"<<endl<<"[6]:Back"<<endl<<"Enter you choice: ";
    cin>>n;
    switch(n)
    {
        case 1: system("cls");
                cout<<endl<<"Enter new name: ";
                cin.ignore();
                getline(cin,name);
                    break;
        case 2: system("cls");
                cout<<endl<<"Enter new phone number(10 Digits): ";
                cin>>phone_number;
                s = to_string(phone_number);
                break;
        case 3: system("cls");
                cout<<endl<<"Enter new emergency contact(10 Digits): ";
                cin>>emergency_contact;
                s = to_string(emergency_contact);
                break;
        case 4: system("cls");
                cout<<endl<<"Enter new Username: ";
                cin.ignore();
                getline(cin,username);
                break;
        case 5: system("cls");
                cout<<endl<<"Enter your new PIN: ";
                cin>>pin;
        default:
                 break;
    };
    if((n == 2 || n == 3 ) && (s.size() != 10)){
        cout<<endl<<"The contact number you entered does not have the correct number of digits please verify and enter again";
    }
}

void guest::view_guest()
{
    cout<<endl<<"Name: "<<name;
    cout<<endl<<"Contact: "<<phone_number;
    cout<<endl<<"Emergency Contact: "<<emergency_contact;
}

int guest::get_pin()
{
    return pin;
}

string guest::get_username()
{
    return username;
}
string guest::get_name()
{
    return name;
}
