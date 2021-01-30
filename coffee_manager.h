#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>

// #include "coffee_system.h"
// #include "coffee_account.h"

using namespace std;

class manager;

#if defined _WIN32
    #define file_manager \
         "C:\\Users\\ADMIN\\OneDrive\\Code\\Coffee-Shop\\data\\manager_account.dat" 
#elif defined _linux_
    #define file_manager \
         "C:\\Users\\ADMIN\\OneDrive\\Code\\Coffee-Shop\\data\\manager_account.dat" 
         
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

    /* Functions */
    manager& assign(const manager& rhs);
    void add_drink();
    void add_food();
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