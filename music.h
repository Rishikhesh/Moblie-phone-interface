#include <string>
using namespace std;

class music
{
        char title[40]  ;
    public:
        void add_song();
        void play_song(char []);
        void stop_song();
        void delete_song();
        void display_song();
        char* return_title();
};
