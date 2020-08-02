#pragma once
#include <string>
using namespace std;
class admin
{
        int pin;
        char name[30];
        char city[20];
        char blood_group[5];
        long long int phone_number;
        int emergency_contact;
    public:
        int get_pin();
        void admin_menu();
        void update_admin();
        void register_admin();
        void view_admin();
        char* return_name();

};
