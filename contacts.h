#include <string>
class contacts
{
        string name;
        long long int contact_number;
        string DOB;
        string address;
    public:
        void new_contact();
        void delete_contact();
        void edit_contact();
        void display_contact();
        string return_contact();

};
