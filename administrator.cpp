#include <iostream>
#include "administrator.h"
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

void admin::register_admin()
{
    string s;
    cout<<endl<<"Fill Your Details!!!";
    cout<<endl<<endl<<"Enter Name: ";
    cin.ignore();
    gets(name);
    do{
        cout<<endl<<"Enter Phone Number(Enter 10 digits): ";
        cin>>phone_number;
        s = to_string(phone_number);
    }while(s.size()!=10);
    cout<<endl<<"Enter city: ";
    cin.ignore();
    gets(city);
    cout<<endl<<"Enter blood group: ";
    gets(blood_group);
    do{
        cout<<endl<<"Enter emergency contact(Enter 10 Digits): ";
        cin>>emergency_contact;
        s = to_string(emergency_contact);
    }while(s.size()!=10);
    cout<<endl<<"Now Set your pin: ";
    cin.ignore();
    cin>>pin;
}

void admin::update_admin()
{
    int n;
    string s;
    int p;
    while(1)
    {
        cout<<endl<<"Please Enter your Pin to modify details: ";
        cin>>p;
        if(p == pin)
        {
            system("cls");
            cout<<"\t\t\t\t\t\t\t\tUPDATION MENU";
            cout<<endl<<"[1]:Update Name"<<endl<<"[2]:Update Phone Number"<<endl<<"[3]:Update City"<<endl<<"[4]:Update Blood Group"<<endl<<"[5]:Update Emergency Contact"<<endl<<"[6]:Update PIN"<<endl<<"[7]:BACK"<<endl<<endl<<"Enter you choice: ";
            cin>>n;
            switch(n)
            {
                case 1: system("cls");
                        cout<<endl<<"Enter new name: ";
                        cin.ignore();
                        gets(name);
                        break;
                case 2: system("cls");
                        do{
                            cout<<endl<<"Enter phone number(10 Digits): ";
                            cin>>phone_number;
                            s = to_string(phone_number);
                        }while(s.size()!=10);
                        break;
                case 3: system("cls");
                        cout<<endl<<"Enter city: ";
                        cin.ignore();
                        gets(city);
                        break;
                case 4: system("cls");
                        cout<<endl<<"Enter blood group: ";
                        cin.ignore();
                        gets(blood_group);
                        break;
                case 5: system("cls");
                        do{
                            cout<<endl<<"Enter emergency contact(10 Digits): ";
                            cin>>emergency_contact;
                            s = to_string(emergency_contact);
                        }while(s.size()!=10);
                        break;
                case 6: system("cls");
                        cout<<endl<<"Enter your pin: ";
                        cin.ignore();
                        cin>>pin;
                default: break;
            };
            break;
        }
        else
        {
            cout<<endl<<"Invalid Pin";
        }
}
}

void admin::view_admin()
{
    cout<<endl<<"Name: "<< name;
    cout<<endl<<"Contact: "<<phone_number;
    cout<<endl<<"Blood Group: "<< blood_group;
    cout<<endl<<"Emergency Contact: "<<emergency_contact;
    cout<<endl<<"City: "<< city;
}

int admin::get_pin()
{
    return pin;
}

char* admin::return_name()
{
    return name;
}
