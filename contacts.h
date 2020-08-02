#include <string>
using namespace std;
class contacts
{
        char name[30];
        long long int contact_number;
        char DOB[11];
        char address[40];
    public:
        void new_contact();
        void delete_contact();
        void edit_contact();
        void display_contact();
        char* return_contact();

};
