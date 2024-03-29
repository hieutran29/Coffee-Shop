#include "coffee_manager.h"

bool existed_in_file(const manager_t &check) {
    bool ret = false;
    
    ifstream inp(file_manager, ios::in | ios::binary);

    // count number of elements
    inp.seekg(0, ios::end);
    long fileSize = inp.tellg();
    long number_accounts = fileSize / sizeof(manager_t);
    inp.seekg(0, ios::beg);


    for(long i = 0; i < number_accounts; i++) {
        manager_t compare;
    
        inp.read((char *) &compare, sizeof(manager_t));

        if(strcmp(compare.username, check.username) == 0) {
            ret = true;
        }
    }
    return ret;
}


manager_t& manager_t::assign(const manager_t& rhs) {
    strcpy(username, rhs.username);
    strcpy(password, rhs.password);
    strcpy(name, rhs.name);
    dob.assign(rhs.dob);
    return *this;
}


manager_t &manager_t::new_account() {
    string username = " ", password = " ", name = " ";
    int day = 0, month = 0, year = 0;

    do {
        printf("Enter username: ");
        cin >> username;
    } while(existed_in_file(manager_t(username)));

    printf("Password: ");   cin >> password;
    printf("Name: ");       cin >> name;
    printf("dd/mm/yyyy: "); scanf("%d%d%d", &day, &month, &year);

    this->new_account(manager_t(username, password, name, 
                        birth(day, month, year)));
    *this = manager_t(username, password, name, 
                    birth(day, month, year));
    return *this;
}

void manager_t::new_account(const manager_t &new_acc) const {
    ofstream outp(file_manager, ios::binary | ios::out | ios::app);

    outp.write((char *) &new_acc, sizeof(manager_t));

    outp.close();
    if(!outp.good()) {
        printf("Error occurs in writing file\n");
    }
}

bool manager_t::sign_in() {
    manager_t log_in;

    printf("Enter username: ");
    scanf(" %s", log_in.username);
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
            scanf(" %s", log_in.username);
            printf("Enter password: ");
            scanf(" %s", log_in.password);
        }
        else if(choice == 2) {
            this->new_account();
            log_in = *this;
        }
        else if(choice == 0) {
            printf("......\n");
            return false;
        }
    }

    return this->sign_in(log_in);
}

bool manager_t::sign_in(manager_t &man) {
    bool ret = false;


    ifstream inp(file_manager, ios::in | ios::binary);
    if(!inp) {
        printf("%s: No file information\n", "manager_account.dat");
        ret = false;
    }
    else {
        inp.seekg(0, ios::end);
        long fileSize = inp.tellg();
        long number_accounts = fileSize / sizeof(manager_t);
        inp.seekg(0, ios::beg);

        for(long i = 0; i < number_accounts; i++) {
            manager_t compare;

            inp.read((char *) &compare, sizeof(manager_t));

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


void manager_t::add_drink() const {
    product_t new_drink;

    printf("Enter Name of Drink: ");
    scanf(" %s", new_drink.name);
    printf("Enter quantity: ");
    scanf("%u", &new_drink.quantity);
    printf("Enter price: ");
    scanf("%lf", &new_drink.price);

    add_product(new_drink, COFFEE_DRINK);
}


void manager_t::add_food() const {
    product_t new_food;

    printf("Enter Name of Food: ");
    scanf(" %s", new_food.name);
    printf("Enter quantity: ");
    scanf("%u", &new_food.quantity);
    printf("Enter price: ");
    scanf("%lf", &new_food.price);

    add_product(new_food, COFFEE_FOOD);
}

void manager_t::add_product(const product_t &product,
                            COFFEE_PRODUCT type) const {

    if(!existed_in_file(product, type)) {
        write_file(vector<product_t> (1, product), type,
                        FILE_APPEND);
    }
    else {
        vector<product_t> all_products;
        all_products = get_all_product(type);

        for(auto &v : all_products) {
            if(strcmp(v.name, product.name) == 0) {
                v.quantity += product.quantity;
            }
        }
        write_file(all_products, type, FILE_TRUNCATE);
    }
}

char manager_t::access_menu() const {
    char choice;
    cout << "\nChoose 1 option:\n";
    printf("1. Add drink\n");
    printf("2. Add food\n");
    printf("3. Access product's information\n");
    printf("4. Access customer's information\n");
    printf("0. Quit\n");
    printf("Your choice: ");
    cin >> choice;
    return choice;
}

void manager_t::access() {
    char choice;
    do {
        choice = this->access_menu();
        if(choice == '1') {
            add_drink();
        }
        else if(choice == '2') {
            add_food();
        }
        else if(choice == '3') {
            show_product(COFFEE_DRINK);
            show_product(COFFEE_FOOD);
        }
        else if(choice == '4') {
            show_guest();
        }
        else if(choice == '0') {
            printf("Sign out...\n");
        }
    } while(choice != '0');
}


void manager_t::show_product(COFFEE_PRODUCT type) {
    ifstream inp;

    if(type == COFFEE_DRINK) {
        inp.open(file_drink, ios::in | ios::binary);
    }
    else if(type == COFFEE_FOOD) {
        inp.open(file_food, ios::in | ios::binary);
    }

    inp.seekg(0, ios::end);
    long fileSize = inp.tellg();
    long number_accounts = fileSize / sizeof(product_t);
    inp.seekg(0, ios::beg);

    printf("%ld %s found:\n", number_accounts, 
                (type == COFFEE_DRINK) ? "drinks" : "foods");
    for(long i = 0; i < number_accounts; i++) {
        product_t get;

        inp.read((char *) &get, sizeof(product_t));

        get.get();
        printf("\n");
    }

    inp.close();
    if(!inp.good()) {
        printf("Error reding file: %s\n", 
            (type == COFFEE_DRINK) ? "product_drink.dat" : "product_food.dat");
    }
}

void manager_t::show_guest() const {
    ifstream inp;
    inp.open(file_guest, ios::in | ios::binary);

    inp.seekg(0, ios::end);
    long fileSize = inp.tellg();
    long number_accounts = fileSize / sizeof(guest_t);
    inp.seekg(0, ios::beg);

    printf("%ld guests found:\n", number_accounts);
    for(long i = 0; i < number_accounts; i++) {
        guest_t get;

        inp.read((char *) &get, sizeof(guest_t));

        get.view_information();
    }

    inp.close();
    if(!inp.good()) {
        printf("Error reading file: %s", "guests_account.dat");
    }
}