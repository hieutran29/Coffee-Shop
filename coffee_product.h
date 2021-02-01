#include <map>
#include <utility>
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;


enum COFFEE_PRODUCT {
    COFFEE_DRINK = 1,
    COFFEE_FOOD = 2
};


#if defined (_WIN32)
    #define file_drink \
        "C:\\Users\\ADMIN\\OneDrive\\Code\\Coffee-Shop\\data\\product_drink.dat"
    #define file_food \
        "C:\\Users\\ADMIN\\OneDrive\\Code\\Coffee-Shop\\data\\product_food.dat"     
#elif defined (__linux__)
    #define file_drink \
        "/home/hieutran/Coding/Coffee_Project/data/product_drink.dat" 
    #define file_food \
        "/home/hieutran/Coding/Coffee_Project/data/product_food.dat" 
#endif

class product_t;

bool existed_in_file(const product_t &, COFFEE_PRODUCT);

class product_t {
    friend class manager;
    friend bool existed_in_file(const product_t &, COFFEE_PRODUCT);

public:
    product_t() = default;

    product_t(const std::string &n, unsigned q, double p) : product_t() {
        strcpy(name, n.c_str());
        quantity = q;
        price = p;
    }

    /* Functions */
    void get() {
        cout << name << " " << quantity << " " << price << endl;
    }

public:
    char name[101];
    unsigned quantity;
    double price;
};