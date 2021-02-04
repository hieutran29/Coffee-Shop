#include "coffee_product.h"


bool existed_in_file(const product_t &check, COFFEE_PRODUCT type) {
    ifstream inp;

    if(type == COFFEE_DRINK) {
        inp.open(file_drink, ios::in | ios::binary);
    }
    else if(type == COFFEE_FOOD) {
        inp.open(file_food, ios::in | ios::binary);
    }

    vector<product_t> all_products = get_all_product(type);

    for(const auto &v : all_products) {
        if(strcmp(v.name, check.name) == 0) {
            return true;
        }
    }
    
    return false;
}

void print_product(COFFEE_PRODUCT type) {
    ifstream inp;
    if(type == COFFEE_DRINK) {
        inp.open(file_drink, ios::in | ios::binary);
    }
    else if(type == COFFEE_FOOD) {
        inp.open(file_food, ios::in | ios::binary);
    }

    inp.seekg(0, ios::end);
    long fileSize = inp.tellg();
    long number_products = fileSize / (long) sizeof(product_t);
    inp.seekg(0, ios::beg);

    for(int i = 0; i < number_products; i++) {
        product_t get;
        inp.read((char *) &get, sizeof(product_t));
        printf("%s %lf", get.name, get.price);
        printf("\n");
    }   

    inp.close();
    if(!inp.good()) {
        printf("Error reading file to print products");
    } 
}

void write_file(const vector<product_t> &src, 
                COFFEE_PRODUCT type,
                FILE_OPERATION mode) {
    ofstream outp;

    if(type == COFFEE_DRINK) {
        outp.open(file_drink, ios::out | ios::binary | 
                    (mode == FILE_TRUNCATE ? ios::trunc : ios::app));
    }
    else if(type == COFFEE_FOOD) {
        outp.open(file_food, ios::in | ios::binary |
                    (mode == FILE_TRUNCATE ? ios::trunc : ios::app));
    }

    for(const auto &v : src) {
        outp.write((char *) &v, sizeof(product_t));
    }

    outp.close();
    if(!outp.good()) {
        printf("Error reding file: %s\n", (type == COFFEE_DRINK) ? 
                        "product_drink.dat" : "product_food.dat");
    }
}

vector<product_t> get_all_product(COFFEE_PRODUCT type) {

    vector<product_t> ret;

    ifstream inp;
    if(type == COFFEE_DRINK) {
        inp.open(file_drink, ios::in | ios::binary);
    }
    else if(type == COFFEE_FOOD) {
        inp.open(file_food, ios::in | ios::binary);
    }

    inp.seekg(0, ios::end);
    long fileSize = inp.tellg();
    long number_products = fileSize / (long) sizeof(product_t);
    inp.seekg(0, ios::beg);

    for(int i = 0; i < number_products; i++) {
        product_t get;
        inp.read((char *) &get, sizeof(product_t));
        ret.push_back(get);
    }

    inp.close();
    if(!inp.good()) {
        printf("Error reading file to get all drinks");
    }

    return ret;
}