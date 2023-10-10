#include <string>

class music
{
        string title  ;
    public:
        void add_song();
        void play_song(string);
        void stop_song();
        void delete_song();
        void display_song();
        string return_title();
};
