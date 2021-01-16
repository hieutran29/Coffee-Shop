#include "coffee_manager.h"

void birth::get() const {
    cout << this->day << " " << this->month
        << " " << this->year;
}

istream &read(istream &is, manager &elem) {
    printf("Name: ");
    is >> elem.name;
    printf("Date of birth: dd/mm/yyyy: ");
    is >> elem.dob.day >> elem.dob.month 
        >> elem.dob.year;
    elem.access_system = true;
    elem.access_history = true;
    return is;
}

ostream &print(ostream &os, const manager &elem) {
    os << elem.name << " " << " ";
    elem.dob.get();
    return os;
}

manager& manager::new_account() {
    
}

bool manager::sign_in(manager &m) {
    FILE * fp = fopen("data\\manager_account.dat", "r");
    if(fp == NULL) {
        perror("Can not open file\n");
    }
    else {
        string sign_username, sign_password;
        printf("Name: "); cin >> sign_username;
        printf("Password: "); cin >> sign_password;

        // count the number of accounts in the file
        fseek(fp, 0, SEEK_END);
        long fileSize = ftell(fp);
        long number_accounts = fileSize / (long) sizeof(manager);

        // go for each account, and compare them to the signed-in account
        rewind(fp);
        for(int i = 0; i < number_accounts; i++) {
            fseek(fp, i * sizeof(manager), SEEK_SET);
            manager found;
            fread(&found, sizeof(manager), 1, fp);
            if(found.username == sign_username && 
                found.password == sign_password) {
                
                m.username = found.username;
                m.password = found.password;
                m.name = found.name;
                m.dob.day = found.dob.day; 
                m.dob.month = found.dob.month;
                m.dob.year = found.dob.year;

                fclose(fp);
                return true;
            }
        }
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

