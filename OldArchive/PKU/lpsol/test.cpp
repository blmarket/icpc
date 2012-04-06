#include <iostream>
#include "lp_lib.h"
#include "lp_Hash.h"

int main(void)
{
    lprec *lp;
    lp = make_lp(0,4);
    delete_lp(lp);
    return 0;
}
