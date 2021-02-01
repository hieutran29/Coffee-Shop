#include "coffee_product.h"



bool existed_drink_in_file(const product_t &check) {
    bool ret;
    ifstream inp;

    inp.open(file_drink, ios::in | ios::binary);

    inp.seekg(0, ios::end);
    long fileSize = inp.tellg();
    long number_accounts = fileSize / sizeof(product_t);
    inp.seekg(0, ios::beg);

    for(long i = 0; i < number_accounts; i++) {
        product_t get;

        inp.read((char *) &get, sizeof(product_t));

        if(strcmp(get.name, check.name) == 0) {
            ret = true;
        }
    }

    inp.close();
    if(!inp.good()) {
        printf("Error reding file: %s\n", "product_drink.dat");
    }

    return ret;
}


bool existed_food_in_file(const product_t &check) {
    bool ret;
    ifstream inp;

    inp.open(file_food, ios::in | ios::binary);

    inp.seekg(0, ios::end);
    long fileSize = inp.tellg();
    long number_accounts = fileSize / sizeof(product_t);
    inp.seekg(0, ios::beg);

    for(long i = 0; i < number_accounts; i++) {
        product_t get;

        inp.read((char *) &get, sizeof(product_t));

        if(strcmp(get.name, check.name) == 0) {
            ret = true;
        }
    }

    inp.close();
    if(!inp.good()) {
        printf("Error reding file: %s\n", "product_food.dat");
    }

    return ret;
}