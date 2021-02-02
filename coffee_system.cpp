#include "coffee_system.h"


system_t &system_t::sign_in() {
    int choice;
    
    do {
        printf("Sign in as:");
        printf("\t1. Guest\n\t\t2. Manager\n\t\t0. Quit\n");
        cin >> choice;

        if(choice == COFFEE_MANAGER) {
            this->sign_in_as_manager();
        }
        else if(choice == COFFEE_GUEST) {

        }
        else {
            printf("Good bye");
        }
    } while(choice != 0);

    return *this;
}

system_t &system_t::sign_in_as_manager() {
    
    if(this->man.sign_in()) {
        man.access();
    }

    return *this;
}
