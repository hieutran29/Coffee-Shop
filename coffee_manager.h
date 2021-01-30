#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>

// #include "coffee_system.h"
// #include "coffee_account.h"

using namespace std;

class manager;

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

struct manager_t {
    char username[101], password[101];
    char name[101];
    birth dob;
};

class manager {

public:
    /* Constructors */
    manager() = default;

    /* Functions */
    manager& assign(const manager& rhs);
    manager& assign(const manager_t& rhs);
    void add_drink();
    void add_food();
    void access();
    bool sign_in(manager_t &);
    manager &new_account(bool & );
    void get() const {
        cout << elem.username << " " << elem.password << " " << elem.name << "\n";
        elem.dob.get();
    }

private:
    char access_menu() const;

    manager_t elem;
};