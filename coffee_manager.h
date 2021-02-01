#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>

#include "coffee_guest.h"


class manager_t;


bool existed_in_file(const manager_t &);


class manager_t {
    friend bool existed_in_file(const manager_t &);

public:
    /* Constructors */
    manager_t() = default;

    manager_t(const string& user, const string& pass, 
            const string& n, const birth& b) : manager_t() {
        strcpy(username, user.c_str());
        strcpy(password, pass.c_str());
        strcpy(name, n.c_str());
        dob.assign(b);
    }

    manager_t(const string& user, const string& pass) : 
            manager_t(user, pass, " ", birth(0, 0, 0)) { }

    manager_t(const string& user) : 
            manager_t(user, " ", " ", birth(0, 0, 0)) { }

    /* Functions */
    manager_t& assign(const manager_t& rhs);

    void add_drink();
    void add_drink(const product_t &);

    void add_food();
    void add_food(const product_t &);

    void show_product(COFFEE_PRODUCT);
    void show_guest() const;

    void access();

    bool sign_in(manager_t &);

    manager_t &new_account();
    void new_account(const manager_t &) const;
    
    void get() const {
        printf("Name: %s\nPassword: %s\nName: %s\n", username,
                            password, name);
        dob.get();
        printf("\n");
    }

private:
    char access_menu() const;
    
    char username[101], password[101];
    char name[101];
    birth dob;
};