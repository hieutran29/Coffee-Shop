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


void manager::add_drink() {
    product_t new_drink;

    printf("Enter Name of Drink: ");
    scanf(" %s", new_drink.name);
    printf("Enter quantity: ");
    scanf("%u", &new_drink.quantity);
    printf("Enter price: ");
    scanf("%lf", &new_drink.price);

    add_drink(new_drink);
}

void manager::add_drink(const product_t &drink) {
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


void manager::add_food() {
    product_t new_food;

    printf("Enter Name of Food: ");
    scanf(" %s", new_food.name);
    printf("Enter quantity: ");
    scanf("%u", &new_food.quantity);
    printf("Enter price: ");
    scanf("%lf", &new_food.price);

    add_drink(new_food);
}

void manager::add_food(const product_t &food) {
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

char manager::access_menu() const {
    char choice;
    cout << "\nChoose 1 option:\n";
    printf("1. Add drink\n");
    printf("2. Add food\n");
    printf("3. Access product's information\n");
    printf("4. Access customer's information\n");
    printf("0. Quit\n");
    cin >> choice;
    return choice;
}

void manager::access() {
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
            
        }
        else if(choice == '0') {
            printf("Sign out...\n");
        }
    } while(choice != '0');
}


void manager::show_product(COFFEE_PRODUCT type) {
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