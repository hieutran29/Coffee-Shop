#include <vector>
#include <string>
#include <cstring>

#include "coffee_birth.h"
#include "coffee_product.h"


class guest_t;

#if defined (_WIN32)
    #define file_guest \
         "C:\\Users\\ADMIN\\OneDrive\\Code\\Coffee-Shop\\data\\guests_account.dat" 
#elif defined (__linux__)
    #define file_guest \
         "/home/hieutran/Coding/Coffee_Project/data/guests_account.dat" 
         
#endif

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

    guest_t(const std::string &n, const string &pass, birth b) {
        strcpy(name, n.c_str());
        strcpy(password, pass.c_str());
        dob = b;
    }

    guest_t(const std::string &n, const string &pass) : guest_t(n, pass, birth(0, 0, 0)) { }

    guest_t(const std::string &n) : guest_t(n, " ", birth(0, 0, 0)) { }

    /* Functions */
    void view_information() const;

    guest_t &new_account();
    
    bool sign_in(const guest_t &);

    void order(const product_t &);

private:
    char name[101], password[101];
    birth dob;
    vector<visit> visit_detail;
    mutable unsigned time_visit = 0;
};