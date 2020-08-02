#pragma once
#include <string>
using namespace std;
class guest
{
        char username[20];
        char name[30];
        int pin;
        long long int phone_number;
        int emergency_contact;
    public:
        void register_guest();
        void update_guest();
        void view_guest();
        int get_pin();
        char* get_username();
        char* get_name();
};
