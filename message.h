class message
{
        long long int to_number;
        char to_name[20];
        char content[50];
        char date[11];
    public:
        void new_message();
        void view_sent();
        long long int return_to();
        char* return_date();
        char* return_to_name();
};
