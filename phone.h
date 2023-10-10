#include "administrator.h"
#include "guest.h" 
#include "menus.h"
class phone
{
    admin a;
    guest g;
    [[no_unique_address]] menu m; 
    public:
        void set_pin();
        void verify(int pin);
};
