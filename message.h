#include <string>
class message
{ 
        long long int to_number;
        string to_name;
        string content;
        string date;
    public:
        void new_message();
        void view_sent();
        long long int return_to();
        string return_date();
        string return_to_name();
};
