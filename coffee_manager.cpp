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

bool manager_t::sign_in(manager_t &man) {
    bool ret = false;


    ifstream inp(file_manager, ios::in | ios::binary);
    if(!inp) {
        printf("%s: No file information\n", "manager_t_account.dat");
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
            printf("Error occurs in reading file: %s\n", "manager_t_account.dat");
            ret = false;
        }
    }

    return ret;
}


void manager_t::add_drink() {
    product_t new_drink;

    printf("Enter Name of Drink: ");
    scanf(" %s", new_drink.name);
    printf("Enter quantity: ");
    scanf("%u", &new_drink.quantity);
    printf("Enter price: ");
    scanf("%lf", &new_drink.price);

    add_drink(new_drink);
}

void manager_t::add_drink(const product_t &drink) {
    if(!existed_in_file(drink, COFFEE_DRINK)) {
        ofstream outp(file_drink, ios::binary | ios::out | ios::app);

        outp.write((char *) &drink, sizeof(product_t));

        outp.close();
        if(!outp.good()) {
            printf("Error occurs in writing file\n");
        }
    }
    else {
        ifstream inp(file_drink, ios::in | ios::binary);

        inp.seekg(0, ios::end);
        long fileSize = inp.tellg();
        long number_accounts = fileSize / sizeof(product_t);
        inp.seekg(0, ios::beg);
        
        vector<product_t> product; 
        for(int i = 0; i < number_accounts; i++) {
            product_t get;

            inp.read((char *) &get, sizeof(product_t));

            if(strcmp(get.name, drink.name) == 0) {
                get.quantity += drink.quantity;
            }

            product.push_back(get);
        }

        inp.close();
        if(!inp.good()) {
            printf("Error reading file: %s\n", "product_drink.dat");
        }

        ofstream outp(file_drink, ios::out | ios::binary | ios::trunc);
        for(const product_t &p : product) {
            outp.write((char *) &p, sizeof(product_t));
        }

        outp.close();
        if(!outp.good()) {
            printf("Error writing file");
        }
    }
}


void manager_t::add_food() {
    product_t new_food;

    printf("Enter Name of Food: ");
    scanf(" %s", new_food.name);
    printf("Enter quantity: ");
    scanf("%u", &new_food.quantity);
    printf("Enter price: ");
    scanf("%lf", &new_food.price);

    add_food(new_food);
}

void manager_t::add_food(const product_t &food) {
    if(!existed_in_file(food, COFFEE_FOOD)) {
        ofstream outp(file_food, ios::binary | ios::out | ios::app);

        outp.write((char *) &food, sizeof(product_t));

        outp.close();
        if(!outp.good()) {
            printf("Error occurs in writing file\n");
        }
    }
    else {
        ifstream inp(file_food, ios::in | ios::binary);

        inp.seekg(0, ios::end);
        long fileSize = inp.tellg();
        long number_accounts = fileSize / sizeof(product_t);
        inp.seekg(0, ios::beg);
        
        vector<product_t> product; 
        for(int i = 0; i < number_accounts; i++) {
            product_t get;

            inp.read((char *) &get, sizeof(product_t));

            if(strcmp(get.name, food.name) == 0) {
                get.quantity += food.quantity;
            }

            product.push_back(get);
        }

        inp.close();
        if(!inp.good()) {
            printf("Error reading file: %s\n", "product_food.dat");
        }

        ofstream outp(file_food, ios::out | ios::binary | ios::trunc);
        for(const product_t &p : product) {
            outp.write((char *) &p, sizeof(product_t));
        }

        outp.close();
        if(!outp.good()) {
            printf("Error writing file");
        }
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

    printf("%ld %s found:\n", number_accounts, (type == COFFEE_DRINK) ? "drinks" : "foods");
    for(long i = 0; i < number_accounts; i++) {
        product_t get;

        inp.read((char *) &get, sizeof(product_t));

        get.get();
    }

    inp.close();
    if(!inp.good()) {
        printf("Error reding file: %s\n", (type == COFFEE_DRINK) ? "product_drink.dat" : "product_food.dat");
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