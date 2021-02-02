#include "coffee_guest.h"

bool existed_in_file(const guest_t &check) {
    bool ret = false;
    
    ifstream inp(file_guest, ios::in | ios::binary);

    // count number of elements
    inp.seekg(0, ios::end);
    long fileSize = inp.tellg();
    long number_accounts = fileSize / sizeof(guest_t);
    inp.seekg(0, ios::beg);


    for(long i = 0; i < number_accounts; i++) {
        guest_t compare;
    
        inp.read((char *) &compare, sizeof(guest_t));

        if(strcmp(compare.name, check.name) == 0) {
            ret = true;
        }
    }
    return ret;
}


void guest_t::view_information() const {
    printf("Name: %s\n", name);
    dob.get();
    printf("\n");
    time_visit = visit_detail.size();
    printf("%u visits:", visit_detail.size());
    for(unsigned i = 1; i <= time_visit; i++) {
        printf("#%d:\n", i);
        visit_detail[i].get();
        printf("\n");
    }   
    printf("\n");
}


guest_t &guest_t::new_account() {
    string username = " ", password = " ";
    int day = 0, month = 0, year = 0;

    do {
        printf("Enter username: ");
        cin >> username;
    } while(existed_in_file(guest_t(username)));

    printf("Password: ");   cin >> password;
    printf("dd/mm/yyyy: "); scanf("%d%d%d", &day, &month, &year);

    this->new_account(guest_t(username, password, 
                    birth(day, month, year), vector<visit> (), 0));
    *this = guest_t(username, password, birth(day, month, year), 
                        vector<visit> (), 0);
    return *this;
}

void guest_t::new_account(const guest_t &new_acc) const {
    ofstream outp(file_guest, ios::binary | ios::out | ios::app);

    outp.write((char *) &new_acc, sizeof(guest_t));

    outp.close();
    if(!outp.good()) {
        printf("Error occurs in writing file\n");
    }
}

void guest_t::sign_in() {
    guest_t log_in;

    printf("Enter username: ");
    scanf(" %s", log_in.name);
    printf("Enter password: ");
    scanf(" %s", log_in.password);

    while( !sign_in(log_in) ) {
        printf("Invalid Account. Log in failed\n");
        printf("Choose 1 option:\n");
        printf("1. Retry\n2. Sign up\n0. Quit\n");

        int choice;
        printf("Your choice: ");
        cin >> choice;

        if(choice == 1) {
            printf("Enter username: ");
            scanf(" %s", log_in.name);
            printf("Enter password: ");
            scanf(" %s", log_in.password);
        }
        else if(choice == 2) {
            this->new_account();
            log_in = *this;
        }
        else if(choice == 0) {
            printf("......\n");
            return ;
        }
    }
}

bool guest_t::sign_in(const guest_t &sign) {
    bool ret = false;

    ifstream inp(file_guest, ios::in | ios::binary);
    if(!inp) {
        printf("%s: No file information\n", "guest_account.dat");
        ret = false;
    }
    else {
        inp.seekg(0, ios::end);
        long fileSize = inp.tellg();
        long number_accounts = fileSize / sizeof(guest_t);
        inp.seekg(0, ios::beg);

        for(long i = 0; i < number_accounts; i++) {
            guest_t compare;

            inp.read((char *) &compare, sizeof(guest_t));

            if(strcmp(compare.name, sign.name) == 0 &&
                strcmp(compare.password, sign.password) == 0) {
                *this = compare;
                ret = true;
            }
        }
        
        inp.close();
        if(!inp.good()) {
            printf("Error occurs in reading file: %s\n", "guests_account.dat");
            ret = false;
        }
    }

    return ret;
}

guest_t &guest_t::modify_information() {
    
}

void guest_t::operation() {
    int choice;
    do {
        cout << "\nChoose 1 option:\n";
        printf("1. View my information\n");
        printf("2. Modify my information\n");
        printf("0. Quit\n");
        printf("Your choice: ");
        cin >> choice; 

        switch(choice) {
            case 1:
                view_information();
                break;
            case 2:
                modify_information();
                break;
            case 0:
                printf(".....\n");
                break;
        }
    } while(choice != 0);
}


void guest_t::menu() {
    int choice;
    do {
        cout << "\nChoose 1 option:\n";
        printf("1. Sign in as a member\n");
        printf("2. Order food and drink\n");
        printf("0. Quit\n");
        printf("Your choice: ");
        cin >> choice;

        if(choice == 1) {
            sign_in();
            operation();
        }
        else if(choice == 2) {
            
        }
        else if(choice == 0) {
            printf("Sign out...\n");
        }
    } while(choice != 0);
}