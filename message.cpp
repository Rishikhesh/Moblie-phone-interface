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
        getline(cin, to_name);

        cout<<endl<<"DATE (dd/mm/yyyy): ";
       getline(cin, date);

        cout<<endl<<"Content: ";
        getline(cin, content);

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

string message::return_date()
{
    return date;
}

string message::return_to_name()
{
    return to_name;
}
