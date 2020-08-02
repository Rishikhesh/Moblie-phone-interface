#include <iostream>
#include <windows.h>
#include "phone.h"

using namespace std;

int main()
{
    system("Color 7A");
    system("cls");
    int user_c,choice1;
    phone p;
    do{
        cout<<"\t\t\t\t\t\t\t\t\t\tLOCK SCREEN";
        cout<<endl<<"[1]:New User"<<endl<<"[2]:Login"<<endl<<"[3]:Exit"<<endl<<"Enter you choice: ";
        cin>>user_c;
        system("cls");
        switch(user_c)
        {
            case 1:
                    p.set_pin();
                    break;
            case 2: cout<<"\t\t\t\t\t\t\t\t\tLOGIN";
                    cout<<endl<<"[1]:Administrator"<<endl<<"[2]:Guest"<<endl<<"[3]:BACK"<<endl<<endl<<"Enter your choice: ";
                    cin>>choice1;
                    p.verify(choice1);
                    break;
            default: system("cls");
                    return 0;
        }
    }while(user_c != 3);
}
