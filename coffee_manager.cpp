#include "coffee_manager.h"

void birth::get() const {
    cout << this->day << " " << this->month
        << " " << this->year;
}

manager& manager::assign(const manager& rhs) {
    strcpy(elem.username, rhs.elem.username);
    strcpy(elem.password, rhs.elem.password);
    strcpy(elem.name, rhs.elem.name);
    elem.dob.assign(rhs.elem.dob);
    return *this;
}

manager& manager::assign(const manager_t& rhs) {
    strcpy(elem.username, rhs.username);
    strcpy(elem.password, rhs.password);
    strcpy(elem.name, rhs.name);
    elem.dob.assign(rhs.dob);
    return *this;
}


manager& manager::new_account(bool &existed_in_file) {
    manager_t new_acc;
    printf("Username: ");
    scanf(" %s", new_acc.username);
    
    existed_in_file = false;
    
    ifstream inp("C:\\Users\\ADMIN\\OneDrive\\Code\\Coffee-Shop\\data\\manager_account.dat", 
                    ios::in | ios::binary);

    // count number of elements
    inp.seekg(0, ios::end);
    long fileSize = inp.tellg();
    long number_accounts = fileSize / sizeof(manager_t);
    inp.seekg(0, ios::beg);


    for(long i = 0; i < number_accounts; i++) {
        manager_t compare;
    
        inp.read((char *) &compare, sizeof(manager_t));

        if(strcmp(compare.username, new_acc.username) == 0) {
            existed_in_file = true;
        }
    }

    inp.close();
    if(!inp.good()) {
        printf("Error occurs in reading file\n");
    }
    ofstream outp("C:\\Users\\ADMIN\\OneDrive\\Code\\Coffee-Shop\\data\\manager_account.dat",
                    ios::binary | ios::out | ios::app);
    if(!existed_in_file) {
        printf("Password: "); scanf(" %s", new_acc.password);
        printf("Name: "); scanf(" %s", new_acc.name);
        new_acc.dob.add();
        // this->assign(new_acc);

        outp.write((char *) &new_acc, sizeof(manager_t));
    }
    outp.close();
    if(!outp.good()) {
        printf("Error occurs in writing file\n");
    }
    
    this->assign(new_acc);
    return *this;
}

bool manager::sign_in(manager &m) {
    FILE * fp = fopen("data\\manager_account.dat", "rb");
    if(fp == NULL) {
        perror("Can not open file\n");
    }
    else {
        string sign_username, sign_password;
        printf("Name: "); cin >> sign_username;
        printf("\nPassword: "); cin >> sign_password;

        // count the number of accounts in the file
        fseek(fp, 0, SEEK_END);
        long fileSize = ftell(fp);
        long number_accounts = fileSize / (long) sizeof(manager);

        // go for each account, and compare them to the signed-in account
        rewind(fp);
        for(long i = 0; i < number_accounts; i++) {
            fseek(fp, i * (long) sizeof(manager), SEEK_SET);
            manager found;
            fread(&found, sizeof(manager), 1, fp);
            if(found.username == sign_username && 
                found.password == sign_password) {
                
                m.assign(found);

                fclose(fp);
                return true;
            }
        }
        printf("No account found. Please sign-up!");
    }
    fclose(fp);
    return false;
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
            choice = access_menu();
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

