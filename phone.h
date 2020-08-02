#include "administrator.h"
#include "guest.h"
#include "menus.h"
class phone
{
    admin a;
    guest g;
    menu m;
    public:
        void set_pin();
        void verify(int pin);
};
