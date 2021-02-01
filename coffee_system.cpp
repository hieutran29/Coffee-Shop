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
    string username = " ", password = " ", name = " ";
    int day = 0, month = 0, year = 0;

    printf("Username: ");   cin >> username;


    manager_t log_in(username);

    bool retry = !existed_in_file(log_in);
    bool not_found = !existed_in_file(log_in);
    bool sign_up = false;
    while(retry) {
        int choice;

        printf("username ""%s"" %s\n", username.c_str(),
                        not_found ? "not found" : "existed");
        printf("1. Retry, or\n2. Sign up\n3. Quit\n");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("Re-enter username: ");  
            cin >> username;
            log_in = manager_t(username);
            
            retry = !existed_in_file(log_in);
            not_found = true;
            sign_up = false;
        }
        else if(choice == 2) {
            this->man.new_account();
            return *this;
        }
        else {
            return *this;
        }
    }

    printf("Password: ");
    cin >> password;

    log_in = manager_t(username, password);

    while(!this->man.sign_in(log_in)) {
        printf("Wrong password\n1. Re-enter password\n0. Quit\n");
        int choice;
        cin >> choice;
        if(choice == 0) {
            return *this;
        }
        printf("Password: ");
        cin >> password;
        log_in = manager_t(username, password);
    }

    this->man.access();
    return *this;
}
