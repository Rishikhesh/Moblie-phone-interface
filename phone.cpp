#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "phone.h"
#include <fstream>

using namespace std;


void verifyPin(){
    admin a;
    int aa=0;
    int p;
    int b;
    read_admin.read((char*)&a,sizeof(admin));
    do{
        cout<<endl<<"Enter your pin: ";
        cin>>p;
        b = a.get_pin();
        if(p == b)
        {
            system("cls");
            cout<<endl<<"\t\t\t\t\t\t\tWELCOME !!!"<<a.return_name();
            cout<<endl<<endl<<"Press Enter to continue!!!";
            _getch();
            this->m.admin_menu();
            read_admin.close();
            aa = 1;
            break;
        }
        else
        {
            cout<<endl<<endl<<"Invalid pin!!!";
        }

    }while(aa==0);
}

void verifyGuestLogin(){
    guest g;
    int a=0;
    int b;
    int p;
    char *nam;
    do{
        cout<<endl<<"Enter your username: ";
        cin.ignore();
        getline(cin,un);
        cout<<endl<<"Enter your PIN: ";
        cin>>p;
        ifstream read_guest;
        read_guest.open("guest.dat",ios::in|ios::binary);
        while(!read_guest.eof() && read_guest.is_open())
        {
            read_guest.read((char*)&g,sizeof(g));
            nam = g.get_username();
            b = g.get_pin();
            if(strcmp(nam,un)==0)
            {
                if(b==p)
                    {
                        a=1;
                        break;
                    }
            }
        }
        read_guest.close();
        if(a==1)
            {
                system("cls");
                cout<<endl<<"\t\t\t\t\t\t\t\t\tWELCOME !!! "<<g.get_name();
                cout<<endl<<endl<<"Press Enter to continue!!!";
                _getch();
                this->m.guest_menu(b);
            }
        else
            cout<<endl<<"Invalid username or pin!!!";
    }while(a==0);
    
}

void phone::verify(int choice1)
{
        string un;
        switch(choice1)
        {
            case 1:
                    {
                        system("cls");
                        system("Color 5C");
                        ifstream read_admin;
                        read_admin.open("admin.dat",ios::in|ios::binary);
                        verifyPin();
                        system("cls");
                        break;
                    }
            case 2:
                {
                        system("cls");
                        system("Color 2F");
                        verifyGuestLogin();
                        system("cls");
                        break;
                    }
                default: break;
            };
}

void phone::set_pin()
{
    system("cls");
    system("Color 7D");
    ifstream checker_r;
    ofstream checker_w;
    ofstream write_admin;
    ofstream write_guest;
    checker_r.open("check.dat",ios::in|ios::binary);
    write_guest.open("guest.dat",ios::app|ios::binary);
    write_admin.open("admin.dat",ios::app|ios::binary);
    {

        cout<<"\t\t\t\t\t\t\t\t\tREGISTRATION";

        if(!checker_r.is_open())
            {
                    system("cls");
                    cout<<endl<<"\t\t\t\t\t\t\tAdministrator Registration!!!";
                    admin a ;
                    a.register_admin();
                    write_admin.write((char*)&a,sizeof(admin));
                    checker_w.open("check.dat",ios::out|ios::binary);
                    checker_w << 1;
                    cout<<endl<<"User Registered Successfully!!!"<<endl<<endl<<"Press Enter to Continue!!!";
                    _getch();
                    system("cls");
                    this->a=a;
            }
        else
            {
                    cout<<endl<<"\t\t\t\t\t\t\t\tGuest Registration!!!";
                    guest g;
                    g.register_guest();
                    write_guest.write((char*)&g,sizeof(g));
                    this->g=g;
                    cout<<endl<<"User Registered Successfully!!!"<<endl<<endl<<"Press Enter to Continue!!!";
                    _getch();
                    system("cls");

            }
    }
        write_admin.close();
        write_guest.close();
        checker_w.close();
        checker_r.close();

}


