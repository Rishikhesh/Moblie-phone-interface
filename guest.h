#pragma once
#include <string>
class guest
{
        string username;
        string name;
        int pin;
        long long int phone_number;
        int emergency_contact;
    public:
        void register_guest();
        void update_guest();
        void view_guest();
        int get_pin();
        string get_username();
        string get_name();
};
