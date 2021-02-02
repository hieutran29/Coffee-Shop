#include <vector>
#include <string>
#include <cstring>

#include "coffee_birth.h"
#include "coffee_product.h"


class guest_t;
         

struct visit {

    friend class guest_t;

    void get() const {
        printf("\tdd/mm/yyyy: %d/%d/%d\n", day, month, year);
        printf("\tFood order: %s\n", food);
        printf("\tDrink order: %s", drink);
    }

private:
    int day, month, year;
    char food[101], drink[101];
};


bool existed_in_file(const guest_t &);

class guest_t {
    friend bool existed_in_file(const guest_t &);

public:
    /* Constructors */
    guest_t() = default;

    guest_t(const std::string &n, const string &pass, birth b, 
                    vector<visit> v, unsigned t) {
        strcpy(name, n.c_str());
        strcpy(password, pass.c_str());
        dob = b;
        visit_detail = v;
        time_visit = t;
    }

    guest_t(const std::string &n, const string &pass) 
            : guest_t(n, pass, birth(0, 0, 0), vector<visit> (), 0) { }

    guest_t(const std::string &n) 
            : guest_t(n, " ", birth(0, 0, 0), vector<visit> (), 0) { }

    /* Functions */
    void menu();

    void view_information() const;

    guest_t &modify_information();

    guest_t &new_account();
    void new_account(const guest_t &) const;
    
    void sign_in();
    bool sign_in(const guest_t &);

    void order();

private:
    void operation();
    
    char name[101], password[101];
    birth dob;
    vector<visit> visit_detail;
    mutable unsigned time_visit = 0;
};