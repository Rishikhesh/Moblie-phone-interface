#include "message.h"
#include <iostream>
#include <string>

using namespace std;

void message::new_message()
{
        cout<<endl<<"TO Number: ";
        cin>>to_number;

        cout<<endl<<"TO Name: ";
        cin.ignore();
        gets(to_name);

        cout<<endl<<"DATE (dd/mm/yyyy): ";
        //cin.ignore();
        gets(date);

        cout<<endl<<"Content: ";
        //cin.ignore();
        gets(content);

}

void message::view_sent()
{
    cout<<endl<<"TO NUMBER: "<<to_number;
    cout<<endl<<"TO NAME: "<<to_name;
    cout<<endl<<"DATE: "<<date;
    cout<<endl<<"Content: "<<content;
}

long long int message::return_to()
{
    return to_number;
}

char* message::return_date()
{
    return date;
}

char* message::return_to_name()
{
    return to_name;
}
