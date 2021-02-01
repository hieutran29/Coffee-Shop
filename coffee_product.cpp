#include "coffee_product.h"


bool existed_in_file(const product_t &check, COFFEE_PRODUCT type) {
    bool ret;
    ifstream inp;

    if(type == COFFEE_DRINK) {
        inp.open(file_drink, ios::in | ios::binary);
    }
    else if(type == COFFEE_FOOD) {
        inp.open(file_food, ios::in | ios::binary);
    }

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
        printf("Error reding file: %s\n", (type == COFFEE_DRINK) ? "product_drink.dat" : "product_food.dat");
    }

    return ret;
}