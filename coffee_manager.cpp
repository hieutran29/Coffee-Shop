#include "coffee_manager.h"

bool existed_in_file(const manager &check) {
    bool ret = false;
    
    ifstream inp(file_manager, ios::in | ios::binary);

    // count number of elements
    inp.seekg(0, ios::end);
    long fileSize = inp.tellg();
    long number_accounts = fileSize / sizeof(manager);
    inp.seekg(0, ios::beg);


    for(long i = 0; i < number_accounts; i++) {
        manager compare;
    
        inp.read((char *) &compare, sizeof(manager));

        if(strcmp(compare.username, check.username) == 0) {
            ret = true;
        }
    }
    return ret;
}


void birth::get() const {
    cout << this->day << " " << this->month
        << " " << this->year;
}

manager& manager::assign(const manager& rhs) {
    strcpy(username, rhs.username);
    strcpy(password, rhs.password);
    strcpy(name, rhs.name);
    dob.assign(rhs.dob);
    return *this;
}


void manager::new_account() {
    ofstream outp(file_manager, ios::binary | ios::out | ios::app);

    outp.write((char *) this, sizeof(manager));

    outp.close();
    if(!outp.good()) {
        printf("Error occurs in writing file\n");
    }
}

bool manager::sign_in(manager &man) {
    bool ret = false;


    ifstream inp(file_manager, ios::in | ios::binary);
    if(!inp) {
        printf("%s: No file information\n", "manager_account.dat");
        ret = false;
    }
    else {
        inp.seekg(0, ios::end);
        long fileSize = inp.tellg();
        long number_accounts = fileSize / sizeof(manager);
        inp.seekg(0, ios::beg);

        for(long i = 0; i < number_accounts; i++) {
            manager compare;

            inp.read((char *) &compare, sizeof(manager));

            if(strcmp(compare.username, man.username) == 0 &&
                strcmp(compare.password, man.password) == 0) {
                this->assign(compare);
                ret = true;
            }
        }
        
        inp.close();
        if(!inp.good()) {
            printf("Error occurs in reading file: %s\n", "manager_account.dat");
            ret = false;
        }
    }

    return ret;
}

char manager::access_menu() const {
    char choice;
    cout << "Choose 1 option\n";
    printf("1. Add drink\n");
    printf("2. Add food\n");
    printf("3. Access product's information\n");
    printf("4. Access staff's information\n");
    printf("5. Access customer's information\n");
    printf("q. Quit");
    return choice;
}

void manager::access() {
    char choice;
    do {
        do {
            // choice = access_menu();
            switch(choice) {
                if(choice == '1') {
                    add_drink();
                }
                if(choice == '2') {
                    add_food();

                }
                if(choice == '3') {
                    
                }
                if(choice == '4') {

     
                }
                if(choice == '5') {

     
                }
            }   
        } while(choice < '1' || choice > '5');
    } while(choice != 'q' || choice != 'Q');
}

