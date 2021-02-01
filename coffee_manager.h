#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>

#include "coffee_product.h"

using namespace std;

class manager;

#if defined (_WIN32)
    #define file_manager \
         "C:\\Users\\ADMIN\\OneDrive\\Code\\Coffee-Shop\\data\\manager_account.dat" 
#elif defined (__linux__)
    #define file_manager \
         "/home/hieutran/Coding/Coffee_Project/data/manager_account.dat" 
         
#endif

class birth {
    friend class manager;

public:
    birth() = default;

    birth(int d, int m, int y) : day(d), month(m), year(y) { }

    /* Function */
    birth& add() {
        printf("dd/mm/yyyy:");
        cin >> day >> month >> year;
        return *this;
    }

    birth& assign(const birth & b) {
        day = b.day;
        month = b.month;
        year = b.year;
        return *this;
    }
    void get() const;

private:
    
    int day, month, year;
};


bool existed_in_file(const manager &);


class manager {
    friend bool existed_in_file(const manager &);

public:
    /* Constructors */
    manager() = default;

    manager(const string& user, const string& pass, 
            const string& n, const birth& b) : manager() {
        strcpy(username, user.c_str());
        strcpy(password, pass.c_str());
        strcpy(name, n.c_str());
        dob.assign(b);
    }

    manager(const string& user, const string& pass) : 
            manager(user, pass, " ", birth(0, 0, 0)) { }

    manager(const string& user) : 
            manager(user, " ", " ", birth(0, 0, 0)) { }

    /* Functions */
    manager& assign(const manager& rhs);

    void add_drink();
    void add_drink(const product_t &);

    void add_food();
    void add_food(const product_t &);

    void show_product(COFFEE_PRODUCT);

    void access();

    bool sign_in(manager &);
    void new_account();
    
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