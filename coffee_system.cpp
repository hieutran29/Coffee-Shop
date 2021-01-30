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
        manager_t log_in;
        if(man.sign_in(log_in)) {
            man.access();
        }
        else {
            bool is_existed;
            man.new_account(is_existed);
        }
    }
}