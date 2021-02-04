#include "gb.h"
#include "ut.h"


bool test_food_in_file() {
    ifstream inp(file_food, ios::in | ios::binary);
    bool ret = true;

    inp.seekg(0, ios::end);
    long fileSize = inp.tellg();
    long number_accounts = fileSize / sizeof(product_t);
    inp.seekg(0, ios::beg);
    
    for(int i = 0; i < number_accounts; i++) {
        product_t get;

        inp.read((char *) &get, sizeof(product_t));

        if(strcmp(get.name, "Yogurts") == 0 && 
            (get.quantity != 150 || get.price != 1.5)) {
                ret = false;
        }
        else if(strcmp(get.name, "Donuts") == 0 && 
            (get.quantity != 250 || get.price != 1.0)) {
                ret = false;
        }
        else if(strcmp(get.name, "Ice-cream") == 0 && 
            (get.quantity != 450 || get.price != 1.5)) {
                ret = false;
        }
        else if(strcmp(get.name, "Sandwiches") == 0 && 
            (get.quantity != 1000 || get.price != 3.0)) {
                ret = false;
        }
        else if(strcmp(get.name, "Croissants") == 0 && 
            (get.quantity != 1000 || get.price != 2.5)) {
                ret = false;
        }
        else if(strcmp(get.name, "Macarons") == 0 && 
            (get.quantity != 300 || get.price != 1.5)) {
                ret = false;
        }
    }

    inp.close();
    if(!inp.good()) {
        printf("Error reading file: %s\n", "product_food.dat");
    }

    return ret;
}

int main() {
    clear_file(file_food);

    product_t p;
    manager_t  m;
    
    p = product_t("Yogurts", 150, 1.5);
    m.add_product(p, COFFEE_FOOD);

    p = product_t("Donuts", 100, 1.0);
    m.add_product(p, COFFEE_FOOD);

    p = product_t("Donuts", 150, 1.0);
    m.add_product(p, COFFEE_FOOD);

    p = product_t("Ice-cream", 450, 1.5);
    m.add_product(p, COFFEE_FOOD);

    p = product_t("Sandwiches", 500, 3.0);
    m.add_product(p, COFFEE_FOOD);

    p = product_t("Croissants", 300, 2.5);
    m.add_product(p, COFFEE_FOOD);

    p = product_t("Macarons", 300, 1.5);
    m.add_product(p, COFFEE_FOOD);

    p = product_t("Croissants", 700, 2.5);
    m.add_product(p, COFFEE_FOOD);

    p = product_t("Sandwiches", 500, 2.5);
    m.add_product(p, COFFEE_FOOD);

    if(!test_food_in_file()) {
        return 1;
    }
    UT_MSG_OK("Test add food");
    return 0;
}