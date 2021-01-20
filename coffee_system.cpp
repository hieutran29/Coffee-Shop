#include <coffee_system.h>

#include <iostream>

void system::sign_in_as() {
    int ret;
    do {
        cin >> ret;
        printf("Sign in as:");
        printf("\t1. Guest\n\t2. Manager\n");
    } while(ret <= 0 || ret >= 3);
    sign_in = ret;
    if(sign_in == COFFEE_MANAGER) {
        if(m.sign_in(m)) {
            m.access();
        }
        else {
            bool is_existed;
            m.new_account(is_existed);
        }
    }
}