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

void write_file(const vector<guest_t> &all_guests, 
                    FILE_OPERATION mode) {

    ofstream outp;
    
    if(mode == FILE_TRUNCATE) {
        outp.open(file_guest, ios::binary | ios::out | ios::trunc);
    }
    else if(mode == FILE_APPEND) {
        outp.open(file_guest, ios::binary | ios::out | ios::app);
    }

    for(const auto &g : all_guests) {
        outp.write((char *) &g, sizeof(guest_t));
    }

    outp.close();
    if(!outp.good()) {
        printf("Error writing file: %s\n", "manager_account.dat");
    }
}

vector<guest_t> get_all_guests() {

    ifstream inp(file_guest, ios::in | ios::binary);

    inp.seekg(0, ios::end);
    long fileSize = inp.tellg();
    long number_accounts = fileSize / sizeof(guest_t);
    inp.seekg(0, ios::beg);

    vector<guest_t> ret(number_accounts);
    for(int i = 0; i < number_accounts; i++) {
        inp.read((char *) &ret[i], sizeof(guest_t));
    }

    inp.close();
    
    return ret;
}


void guest_t::view_information() const {
    printf("Name: %s\n", name);
    dob.get();
    printf("\n");
    printf("%u purchases:", purchase_detail.size());
    for(unsigned i = 0; i < purchase_detail.size(); i++) {
        printf("#%d:\n", i+1);
        purchase_detail[i].get();
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
                    birth(day, month, year), vector<purchase> ()));
    *this = guest_t(username, password, birth(day, month, year), 
                        vector<purchase> ());
    return *this;
}

void guest_t::new_account(const guest_t &new_acc) const {
    write_file(vector<guest_t> (1, new_acc), FILE_APPEND);
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

    vector<guest_t> all_guests = get_all_guests();

    for(const guest_t &v : all_guests) {
        if(strcmp(v.name, sign.name) == 0 &&
            strcmp(v.password, sign.password) == 0) {
            *this = v;
            ret = true;
        }
    }
    return ret;
}

guest_t &guest_t::modify_information() {
    vector<guest_t> all_guests = get_all_guests();

    for(auto &v : all_guests) {
        if(strcmp(v.name, this->name) == 0) {
            v = *this;

            int choice;
            printf("Choose a field to change:\n");

            do {
                printf("\t1. Password: \n");
                printf("\t2. Date of birth: \n");
                printf("\t0. Quit editing\n");
                printf("Choose: ");
                cin >> choice;

                if(choice == 0) {
                    printf("Quit editing...\n");
                    break;
                }
                if(choice == 1) {
                    printf("New password: ");
                    scanf(" %s", v.password);
                }
                else if(choice == 2) {
                    printf("New date of birth (in dd/mm/yyyy):");
                    v.dob.add();
                }
            } while(choice != 0);

            *this = v;
        }
    }

    write_file(all_guests, FILE_TRUNCATE);

    return *this;
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

void guest_t::order() {
    product_t ordered;

    printf("We have:\n");
    print_product(COFFEE_DRINK);
    printf("--------\n");
    print_product(COFFEE_FOOD);

    vector<product_t> all_drinks = get_all_product(COFFEE_DRINK);
    vector<product_t> all_foods = get_all_product(COFFEE_FOOD);

    printf("Enter product you want to order: ");
    scanf(" %s", ordered.name);
    printf("Enter quantity: ");
    scanf("%u", &ordered.quantity);

    order_food_or_drink(all_drinks, ordered, COFFEE_DRINK);
    order_food_or_drink(all_foods, ordered, COFFEE_FOOD);
}


void guest_t::order_food_or_drink(vector<product_t> &src, 
                                product_t &ordered,
                                COFFEE_PRODUCT type) {

    for(auto &v : src) {
        if(strcmp(v.name, ordered.name) == 0) {
            while(v.quantity < ordered.quantity) {
                printf("Sorry. We only have %u %s left.\n",
                        v.quantity, v.name);
                printf("1. Enter new quantity\n0. Quit\n");
                int choice;
                cin >> choice;
                if(choice == 0) {
                    return;
                }
                printf("New quantity: ");
                scanf("%u", &ordered.quantity);
            }
            v.quantity -= ordered.quantity;
            break;
        }
    }

    write_file(src, type, FILE_TRUNCATE);
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
            order();
        }
        else if(choice == 0) {
            printf("Sign out...\n");
        }
    } while(choice != 0);
}