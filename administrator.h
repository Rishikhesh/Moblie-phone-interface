#pragma once
#include <string>
class admin
{
        int pin;
        string name;
        string city;
        string blood_group;
        long long int phone_number;
        int emergency_contact;
    public:
        int get_pin();
        void admin_menu();
        void update_admin();
        void register_admin();
        void view_admin();
        string return_name();

};
