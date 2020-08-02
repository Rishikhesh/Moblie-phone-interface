#include "menus.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

using namespace std;

void menu::admin_menu()
{
    int choice1=0,choice2=0,pos,conf=0,flag=0;
    char nam1[30],*nam2;
        do{
                system("cls");
                cout<<"\t\t\t\t\t\t\t\t\t\t\tMENU";
                cout<<endl<<"[1]:Settings"<<endl<<"[2]:Contacts"<<endl<<"[3]:Message"<<endl<<"[4]:Music"<<endl<<"[5]:LOGOUT"<<endl<<endl<<"Enter your choice:";
                cin>>choice1;
            switch(choice1)
            {
                case 1:
                        system("cls");
                        system("Color 3E");
                        do
                        {
                        cout<<"\t\t\t\t\t\t\t\t\t\tSETTINGS";
                        cout<<endl<<"[1]:Update"<<endl<<"[2]:View"<<endl<<"[3]:BACK"<<endl<<endl<<"Enter your choice: ";
                        cin>>choice2;
                        switch(choice2)
                        {
                            case 1:
                            {
                                admin a ;
                                ofstream write_admin;
                                write_admin.open("admin.dat",ios::trunc|ios::in|ios::binary);
                                a.update_admin();
                                write_admin.write((char*)&a,sizeof(admin));
                                system("cls");
                                cout<<"\t\t\t\t\t\t\tADMIN";
                                a.view_admin();
                                cout<<endl<<endl<<"Updated Successfully!!!"<<endl<<endl<<"Press Enter to Continue!!!";
                                _getch();

                                write_admin.close();
                                break;
                            }
                            case 2:
                            {
                                admin a ;

                                ifstream read_admin;
                                read_admin.open("admin.dat",ios::in|ios::binary);
                                read_admin.read((char*)&a,sizeof(admin));
                                system("cls");
                                cout<<"\t\t\t\t\t\t\tADMIN";
                                a.view_admin();
                                cout<<endl<<endl<<"Press Enter to Continue!!!";
                                _getch();

                                read_admin.close();
                                break;
                            }
                            default:break;
                        }
                        system("cls");
                        }while(choice2<3);
                        break;
            case 2:
                    system("cls");
                    system("color 5A");
                    contacts c;
                    do{
                    system("cls");
                    system("Color 7C");
                    cout<<endl<<"[1]:ADD CONTACT"<<endl<<"[2]:EDIT CONTACT"<<endl<<"[3]:SEARCH CONTACT"<<endl<<"[4]:DISPLAY CONTACTS"<<endl<<"[5]:DELETE CONTACT"<<endl<<"[6]:BACK"<<endl<<"ENTER YOUR CHOICE:";
                    cin>>choice2;
                    system("cls");
                    switch(choice2)
                    {
                    case 1:
                    {
                        c.new_contact();
                        ofstream contact;
                        contact.open("contacts.dat",ios::out|ios::binary|ios::app);
                        contact.write((char*)&c,sizeof(contacts));
                        cout<<endl<<endl<<"Contact added successfully!!!"<<endl<<endl<<"Press Enter to continue!!!";
                        _getch();
                        system("cls");
                        contact.close();
                        break;
                    }
                    case 2:
                    {
                        conf = 0;
                        fstream contact;
                        cout<<endl<<"Enter the contact name you want to edit:";
                        cin.ignore();
                        gets(nam1);
                        contact.open("contacts.dat",ios::in|ios::out|ios::binary);
                        contact.seekg(0);
                        while(contact.read((char*)&c,sizeof(contacts)) && contact.is_open())
                        {
                            pos = contact.tellg();
                            nam2 = c.return_contact();
                            if(strcmp(nam1,nam2)==0)
                            {
                                system("cls");
                                c.edit_contact();
                                contact.seekp(pos-sizeof(contacts),ios::beg);
                                contact.write((char*)&c,sizeof(contacts));
                                conf = 1;
                                break;
                            }
                        }
                        if(conf == 0)
                        {
                            cout<<endl<<"No such contact name is found!!!"<<endl<<endl<<"Press Enter to continue!!!";
                            _getch();
                        }
                        else
                        {
                            cout<<endl<<"Updated Successfully!!!"<<endl<<endl<<"Press Enter to continue!!!";
                            _getch();
                        }
                        contact.close();
                        system("cls");
                        break;
                    }
                    case 3:
                    {
                        conf = 0;
                        ifstream contact;
                        cout<<"\t\t\t\t\t\t\t\t\t\tSEARCH";
                        cout<<endl<<"Enter the contact name you want to search:";
                        cin.ignore();
                        gets(nam1);
                        contact.open("contacts.dat",ios::in|ios::binary);
                        while(contact.read((char*)&c,sizeof(contacts)) && contact.is_open())
                        {
                            nam2 = c.return_contact();
                            if(strcmp(nam1,nam2)==0)
                            {
                                cout<<endl<<"Found!!!"<<endl;
                                c.display_contact();
                                conf = 1;
                            }
                        }
                        if(conf == 0)
                        {
                            cout<<endl<<endl<<"No such contact name is found!!!"<<endl<<endl<<"Press Enter to continue!!!";
                        }
                        else
                        {
                            cout<<endl<<endl<<"Press Enter to Continue!!! ";
                        }
                        _getch();
                        system("cls");
                        contact.close();
                        break;
                    }
                    case 4:
                    {
                        conf = 0;
                        ifstream contact;
                        contact.open("contacts.dat",ios::in|ios::binary);
                        cout<<"\t\t\t\t\t\t\t\tCONTACTS";
                        while(contact.read((char*)&c,sizeof(contacts)) && contact.is_open())
                        {
                            c.display_contact();
                            cout<<endl;
                            conf = 1;
                        }
                        if(conf == 0)
                        {
                            cout<<endl<<"Your contacts is empty!!!"<<endl<<endl<<"Press Enter to continue!!!";
                        }
                        else
                        {
                            cout<<endl<<endl<<"Press Enter to continue!!!";
                        }
                        _getch();
                        system("cls");
                        contact.close();
                        break;
                    }
                    case 5:
                    {
                        ofstream w_contact;
                        ifstream r_contact;
                        conf=0;
                        flag=0;
                        r_contact.open("contacts.dat",ios::in|ios::binary);
                        w_contact.open("temp.dat",ios::out|ios::binary|ios::trunc);
                        cout<<endl<<"Enter the contact name you want to delete: ";
                        cin.ignore();
                        gets(nam1);
                        while(r_contact.read((char*)&c,sizeof(contacts)) && r_contact.is_open())
                        {
                            nam2 = c.return_contact();
                            if(strcmp(nam1,nam2) != 0)
                            {
                                w_contact.write((char*)&c,sizeof(contacts));
                                conf=1;
                            }
                            if(strcmp(nam1,nam2) == 0)
                            {
                                flag=1;
                            }
                        }
                        if(conf==0)
                        {
                            if(flag==0)
                            {

                                r_contact.close();
                                w_contact.close();
                                cout<<endl<<"No such Contact found!!! "<<endl<<endl<<"Press Enter to continue!!!";
                                _getch();
                                system("cls");
                                break;
                            }
                            else
                            {
                                r_contact.close();
                                w_contact.close();
                                remove("contacts.dat");
                                rename("temp.dat","contacts.dat");
                                cout<<endl<<endl<<"Contact deleted successfully!!!"<<endl<<endl<<"Press Enter to continue!!!";
                                _getch();
                                system("cls");
                                break;
                            }
                        }
                        else
                        {
                            if(flag==1)
                            {
                                r_contact.close();
                                w_contact.close();
                                remove("contacts.dat");
                                rename("temp.dat","contacts.dat");
                                cout<<endl<<"Contact deleted successfully!!!"<<endl<<endl<<"Press Enter to continue!!!";
                                _getch();
                                system("cls");
                                break;
                            }
                            else
                            {
                                cout<<endl<<endl<<"No such Contact found!!!"<<endl<<endl<<"Press Enter to continue!!!";
                                r_contact.close();
                                w_contact.close();
                                _getch();
                                system("cls");
                                break;
                            }
                        }
                    }
                    }
                    }while(choice2<6);
                    break;
            case 3:
                    {
                        system("cls");
                        system("Color 1A");
                        message mes;
                        do{
                        cout<<endl<<"[1]:NEW MESSAGE"<<endl<<"[2]:VIEW SENT"<<endl<<"[3]:DELETE MESSAGE"<<endl<<"[4]:BACK"<<endl<<"Enter your choice: ";
                        cin>>choice2;
                        system("cls");
                        switch(choice2){
                        case 1:
                        {
                            ofstream write_message;
                            write_message.open("messages.dat",ios::out|ios::binary|ios::app);
                            cout<<"\t\t\t\t\t\t\t\tNEW MESSAGE";
                            mes.new_message();
                            write_message.write((char*)&mes,sizeof(message));
                            write_message.close();
                            cout<<endl<<"Message Sent Successfully!!!";
                            _getch();
                            system("cls");
                            break;
                        }
                        case 2:
                        {
                            conf = 0;
                            ifstream read_message;
                            read_message.open("messages.dat",ios::in|ios::binary);
                            cout<<endl<<"\t\t\t\t\t\t\t\t\tSENT MESSAGES";
                            while(read_message.read((char*)&mes,sizeof(message)) && read_message.is_open())
                            {

                                mes.view_sent();
                                cout<<endl;
                                conf = 1;
                            }
                            if(conf == 0)
                            {
                                cout<<endl<<"EMPTY!!!";
                            }
                            cout<<endl<<endl<<"Press Enter to Continue!!!";
                            _getch();
                            system("cls");
                            read_message.close();
                            break;
                        }
                        case 3:
                        {
                            ifstream r_message;
                            ofstream w_message;
                            long long int t,tt;
                            char d[20],*dd;
                            conf = 0;
                            flag=0;
                            cout<<"\t\t\t\t\t\t\t\tDELETE";
                            cout<<endl<<"Enter the To number message to delete: ";
                            cin>>t;
                            cout<<endl<<"Enter the TO Name message to delete: ";
                            cin.ignore();
                            gets(d);
                            r_message.open("messages.dat",ios::in|ios::binary);
                            w_message.open("temp.dat",ios::out|ios::binary|ios::trunc);
                            while(r_message.read((char*)&mes,sizeof(message)) && r_message.is_open())
                            {
                                dd = mes.return_to_name();
                                tt = mes.return_to();
                                if(t != tt)
                                {
                                    if(strcmp(d,dd)!=0)
                                    {
                                        w_message.write((char*)&mes,sizeof(message));
                                        conf = 1;
                                    }
                                }
                                if(t == tt)
                                {
                                    if(strcmp(d,dd)==0)
                                    {
                                        flag=1;
                                    }
                                }

                            }
                            if(conf == 0)
                              {
                                  if(flag==0)
                                  {
                                      cout<<endl<<endl<<"No such message is available!!!"<<endl<<endl<<"Press Enter to Continue!!!";
                                      w_message.close();
                                      r_message.close();
                                      _getch();
                                      system("cls");
                                  }
                                  else
                                  {
                                      w_message.close();
                                      r_message.close();
                                      remove("messages.dat");
                                      rename("temp.dat","messages.dat");
                                      cout<<endl<<endl<<"Message deleted Successfully!!!"<<endl<<endl<<"Press Enter to Continue!!!";
                                      _getch();
                                      system("cls");
                                  }
                              }
                            else
                            {
                                if(flag==1)
                                {
                                    cout<<endl<<endl<<"Message deleted Successfully!!!"<<endl<<endl<<"Press Enter to Continue!!!";
                                    _getch();
                                    w_message.close();
                                    r_message.close();
                                    remove("messages.dat");
                                    rename("temp.dat","messages.dat");
                                    system("cls");
                                }
                                else
                                {
                                      cout<<endl<<endl<<"No such message is available"<<endl<<endl<<"Press Enter to Continue!!!";
                                      w_message.close();
                                      r_message.close();
                                      _getch();
                                      system("cls");
                                }
                            }
                            break;
                    }
                    default: break;
                    }
                    }while(choice2<4);
                    break;
                    }
            case 4:
                    {
                        music mu;
                        char mus[40];
                        do{
                        system("cls");
                        system("Color 9E");
                        cout<<"\t\t\t\t\t\t\t\t\t\t\tMUSIC";
                        cout<<endl<<"[1]:ADD SONG"<<endl<<"[2]:PLAY LIST"<<endl<<"[3]:PLAY SONG"<<endl<<"[4]:STOP SONG"<<endl<<"[5]:DELETE SONG"<<endl<<"[6]:BACK"<<endl<<endl<<"Enter your choice: ";
                        cin>>choice2;
                        system("cls");
                        switch(choice2){
                        case 1:
                        {
                            ofstream w_music;
                            cout<<"\t\t\t\t\t\t\t\t\tADD SONG";
                            w_music.open("music.dat",ios::out|ios::binary|ios::app);
                            mu.add_song();
                            cout<<endl<<"Song Added Successfully!!!"<<endl<<endl<<"Press Enter to Continue!!!";
                            _getch();
                            w_music.write((char*)&mu,sizeof(music));
                            break;
                        }
                        case 2:
                        {
                            conf = 0;
                            ifstream r_music;
                            r_music.open("music.dat",ios::in|ios::binary);
                            cout<<"\t\t\t\t\t\t\t\t\tSONG LIBRARY";
                            while(r_music.read((char*)&mu,sizeof(music)) && r_music.is_open())
                            {
                                mu.display_song();
                                cout<<endl;
                                conf =1 ;
                            }
                            if(conf == 0)
                            {
                                cout<<endl<<"Your player is empty!!!"<<endl<<endl<<"Press Enter to Continue!!!";
                            }
                            else
                            {
                                cout<<endl<<endl<<"Press Enter to Continue!!!";
                            }
                            _getch();
                            system("cls");
                            break;
                        }
                        case 3:
                        {
                            conf = 0;
                            ifstream r_music;
                            cout<<"\t\t\t\t\t\t\t\t\tMUSIC PLAYER";
                            r_music.open("music.dat",ios::in|ios::binary);
                            cout<<endl<<"Enter the song title to play: ";
                            cin.ignore();
                            gets(mus);
                            while(r_music.read((char*)&mu,sizeof(music)) && r_music.is_open())
                            {
                                if(strcmp(mus,mu.return_title())==0)
                                {
                                    mu.play_song(mus);
                                    conf = 1;
                                }
                            }
                            if(conf == 0)
                            {
                                cout<<endl<<"No such song is available!!!"<<endl<<endl<<"Press Enter to Continue!!!";
                                _getch();
                            }
                            else
                            {
                                cout<<endl<<"Song is Playing!!!"<<endl<<endl<<"Press Enter to Continue!!!";
                                _getch();
                            }
                            break;
                        }
                        case 4:
                            {
                                mu.stop_song();
                                system("cls");
                                cout<<endl<<"Song Stopped!!!"<<endl<<endl<<"Press Enter to Continue!!!";
                                _getch();
                                break;
                            }

                        case 5:
                            {
                                conf = 0;
                                char *t;
                                cout<<"\t\t\t\t\t\t\t\t\t\tREMOVE SONG";
                                cout<<endl<<"Enter the song title you want to delete: ";
                                cin.ignore();
                                gets(mus);
                                ifstream r_music;
                                ofstream w_music;
                                r_music.open("music.dat",ios::in|ios::binary);
                                w_music.open("temp.dat",ios::out|ios::app|ios::binary);
                                while(r_music.read((char*)&mu,sizeof(music)) && r_music.is_open())
                                {

                                    t = mu.return_title();
                                    if(strcmp(t,mus)!=0)
                                        {
                                            w_music.write((char*)&mu,sizeof(music));
                                            conf = 1;
                                        }
                                }
                                r_music.close();
                                w_music.close();
                                remove("music.dat");
                                rename("temp.dat","music.dat");
                                if(conf == 1)
                                    cout<<endl<<"Song Deleted Successfully!!!"<<endl<<endl<<"Press Enter to Continue!!!";
                                else
                                    cout<<endl<<"No such song found to delete!!";
                                _getch();
                                break;
                            }
                        default: break;
                    }
                    }while(choice2 < 6);
                    mu.stop_song();
                    break;
                    }
                default: break;
            }
        }while(choice1<5);
}
void menu::guest_menu(int p)
{
    int choice1,choice2,conf = 0;
    do
    {
        system("cls");
        system("Color 8A");
        cout<<"\t\t\t\t\t\t\t\t\t\tMENU";
        cout<<endl<<"[1]:Settings"<<endl<<"[2]:Music"<<endl<<"[3]:LOGOUT"<<endl<<"Enter your choice: ";
        cin>>choice1;
        system("cls");
        switch(choice1)
        {
            case 1:
                {
                    int pos;
                    do
                    {
                    system("cls");
                    cout<<"\t\t\t\t\t\t\t\t\t\tSETTINGS";
                    cout<<endl<<"[1]:Update"<<endl<<"[2]:View"<<endl<<"[3]:BACK"<<endl<<"Enter your choice: ";
                    cin>>choice2;
                    system("cls");
                    switch(choice2)
                    {
                    case 1:
                        {
                            guest g;
                            conf = 0;
                            char c[30];
                            fstream read_guest;
                            cout<<endl<<"Enter your name:";
                            cin.ignore();
                            gets(c);
                            read_guest.open("guest.dat",ios::out|ios::in|ios::binary);
                            while(!read_guest.eof() && read_guest.is_open())
                            {
                                pos = read_guest.tellg();
                                read_guest.read((char*)&g,sizeof(guest));
                                if(strcmp(g.get_name(),c)==0)
                                {
                                    system("cls");
                                    g.update_guest();
                                    read_guest.seekp(0,ios::beg);
                                    read_guest.write((char*)&g,sizeof(guest));
                                    system("cls");
                                    g.view_guest();
                                    conf = 1;
                                    read_guest.close();
                                    break;
                                }

                            }
                            if(conf == 0)
                            {
                                cout<<endl<<endl<<"Invalid Name!!!"<<endl<<endl<<"Press Enter to Continue!!!";
                            }
                            else
                            {
                                cout<<endl<<endl<<"Updated Successfully!!!"<<endl<<endl<<"Press Enter to Continue!!!";
                            }
                            _getch();
                            system("cls");
                            break;
                        }
                    case 2:
                        {
                            guest g;
                            char x[30],*b;
                            ifstream read_guest;
                            read_guest.open("guest.dat",ios::in|ios::binary);
                            cout<<"\t\t\t\t\t\t\tGUEST"<<endl;
                            cout<<endl<<"Enter your username:";
                            cin.ignore();
                            gets(x);
                            while(read_guest.read((char*)&g,sizeof(guest)))
                            {
                                b = g.get_username();
                                if(strcmp(x,b)==0)
                                g.view_guest();
                            }
                            cout<<endl<<endl<<"Press Enter To Continue!!!";
                            _getch();
                            system("cls");
                            read_guest.close();
                            break;
                        }
                    default: break;
                    }
                    }while(choice2<3);
                    system("cls");
                    break;
                }
            case 2:
                {
                    music mu;
                    char mus[40];
                    do{
                    system("cls");
                    cout<<"\t\t\t\t\t\t\t\t\tMUSIC";
                    cout<<endl<<"[1]:PLAY LIST"<<endl<<"[2]:PLAY SONG"<<endl<<"[3]:STOP SONG"<<endl<<"[4]:BACK"<<endl<<endl<<"Enter your choice: ";
                    cin>>choice2;
                    switch(choice2)
                    {
                    case 1:
                    {
                        cout<<"\t\t\t\t\t\t\t\t\tSONG LIBRARY";
                        conf = 0;
                        ifstream r_music;
                        r_music.open("music.dat",ios::in|ios::binary);
                        while(r_music.read((char*)&mu,sizeof(music)) && r_music.is_open())
                        {
                            mu.display_song();
                            cout<<endl;
                            conf = 1;
                        }
                        if(conf == 0)
                        {
                            cout<<endl<<"Empty playlist!!!"<<endl<<endl<<"Press Enter to Continue!!!";
                        }
                        else
                        {
                            cout<<endl<<endl<<"Press Enter to Continue!!!";
                        }
                        _getch();
                        system("cls");
                        break;
                    }
                    case 2:
                    {
                        conf=0;
                        ifstream r_music;
                        cout<<endl<<"\t\t\t\t\t\t\t\t\tMUSIC PLAYER";
                        r_music.open("music.dat",ios::in|ios::binary);
                        cout<<endl<<"Enter the song title to play: ";
                        cin.ignore();
                        gets(mus);
                        while(r_music.read((char*)&mu,sizeof(music)) && r_music.is_open())
                        {
                            if(strcmp(mus,mu.return_title())==0)
                            {
                                mu.play_song(mus);
                                conf = 1;
                            }
                        }
                        if(conf == 0)
                        {
                            cout<<endl<<"No such song is available!!!"<<endl<<endl<<"Press Enter to Continue!!!";
                            _getch();
                        }
                        else
                        {
                            cout<<"Song is Playing!!!"<<endl<<endl<<"Press Enter to Continue!!!";
                        }
                        system("cls");
                        break;
                    }
                    case 3:
                    {
                        mu.stop_song();
                        system("cls");
                        cout<<endl<<"Song Stopped!!!"<<endl<<endl<<"Press Enter to Continue!!!";
                        _getch();
                        break;
                    }
                    default: break;
                }
                }while(choice2 < 4);
                mu.stop_song();
                break;
            }
            default: break;
        }
        }while(choice1<3);
}
