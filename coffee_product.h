#include <map>
#include <utility>
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

#include "file.h"

using namespace std;


enum COFFEE_PRODUCT {
    COFFEE_DRINK = 1,
    COFFEE_FOOD = 2
};


class product_t;

bool existed_in_file(const product_t &, COFFEE_PRODUCT);
void write_new_file(const vector<product_t> &, COFFEE_PRODUCT);
void print_product(COFFEE_PRODUCT);
std::vector<product_t> get_all_product(COFFEE_PRODUCT);

class product_t {
    friend class manager;
    friend bool existed_in_file(const product_t &, COFFEE_PRODUCT);
    friend void print_product(COFFEE_PRODUCT);
    friend std::vector<product_t> get_all_product(COFFEE_PRODUCT);

public:
    product_t() = default;

    product_t(const std::string &n, unsigned q, double p) : product_t() {
        strcpy(name, n.c_str());
        quantity = q;
        price = p;
    }

    /* Functions */
    void get() const {
        std::cout << name << " " << quantity << " " << price;
    }


public:
    char name[101];
    unsigned quantity;
    double price;
};