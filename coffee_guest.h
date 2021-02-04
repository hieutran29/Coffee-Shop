#include <vector>
#include <string>
#include <cstring>

#include "coffee_birth.h"
#include "coffee_product.h"


class guest_t;
         

struct purchase {
    friend class guest_t;
public:
    purchase() = default;

    purchase(const string &p, const unsigned &q) : purchase() {
        strcpy(product_name, p.c_str());
        quantity = q;
    }

    purchase(const string &p) : purchase(p, 0) { }

    void get() const {
        printf("\t%s: %u\n", product_name, quantity);
    }

private:
    char product_name[101];
    unsigned quantity;
};


bool existed_in_file(const guest_t &);
void write_file(const vector<guest_t> &, 
                    FILE_OPERATION);
vector<guest_t> get_all_guests();

class guest_t {
    friend bool existed_in_file(const guest_t &);
    friend void write_file(const vector<guest_t> &, 
                    FILE_OPERATION);
    friend vector<guest_t> get_all_guests();

public:
    /* Constructors */
    guest_t() = default;

    guest_t(const std::string &n, const string &pass, birth b, 
                    vector<purchase> v) {
        strcpy(name, n.c_str());
        strcpy(password, pass.c_str());
        dob = b;
        purchase_detail = v;
    }

    guest_t(const std::string &n, const string &pass) 
            : guest_t(n, pass, birth(0, 0, 0), vector<purchase> ()) { }

    guest_t(const std::string &n) 
            : guest_t(n, " ", birth(0, 0, 0), vector<purchase> ()) { }

    /* Functions */
    void menu();

    void view_information() const;

    guest_t &modify_information();

    guest_t &new_account();
    void new_account(const guest_t &) const;
    
    void sign_in();
    bool sign_in(const guest_t &);

    void order();
    void order_food_or_drink(vector<product_t> &, 
                            product_t &,
                            COFFEE_PRODUCT);

private:
    void operation();
    
    char name[101], password[101];
    birth dob;
    vector<purchase> purchase_detail;
};