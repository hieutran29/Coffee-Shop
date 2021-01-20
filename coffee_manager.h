#include <iostream>
#include <vector>
#include <string>

// #include "coffee_system.h"
// #include "coffee_account.h"

using namespace std;

class manager;
istream &read(istream &is, manager &elem);
ostream &print(ostream &os, const manager &elem);

class birth {
    friend class manager;
    friend istream &read(istream &is, manager &elem);
    friend ostream &print(ostream &os, const manager &elem);

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

private:
    void get() const;
    int day, month, year;
};

class manager {
    friend istream &read(istream &is, manager &elem);
    friend ostream &print(ostream &os, const manager &elem);

public:
    /* Constructors */
    manager() = default;

    manager(string name, birth dob,  int age) :
            name(name), dob(dob), access_history(true), access_system(true) { }

    manager(string name, birth dob) : name(name), dob(dob),
                                    access_history(true), access_system(true) { }

    manager(istream &is) : manager() { read(is, *this); }

    /* Functions */
    manager& assign(const manager& rhs);
    void add_drink();
    void add_food();
    void access();
    bool sign_in(manager&);
    manager &new_account();

private:
    char access_menu() const;

    string username, password;
    string name;
    birth dob;
    // int age;
    bool access_history;
    bool access_system;
};