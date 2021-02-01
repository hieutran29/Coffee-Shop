#include "gb.h"
#include "ut.h"


bool test_drink_in_file() {
    ifstream inp(file_drink, ios::in | ios::binary);
    bool ret = true;

    inp.seekg(0, ios::end);
    long fileSize = inp.tellg();
    long number_accounts = fileSize / sizeof(product_t);
    inp.seekg(0, ios::beg);
    
    for(int i = 0; i < number_accounts; i++) {
        product_t get;

        inp.read((char *) &get, sizeof(product_t));

        if(strcmp(get.name, "lemon_juice") == 0 && 
            (get.quantity != 200 || get.price != 1.5)) {
                ret = false;
        }
        else if(strcmp(get.name, "orange_juice") == 0 && 
            (get.quantity != 100 || get.price != 1.25)) {
                ret = false;
        }
        else if(strcmp(get.name, "watermelon_juice") == 0 && 
            (get.quantity != 500 || get.price != 2.5)) {
                ret = false;
        }
        else if(strcmp(get.name, "cappuccino") == 0 && 
            (get.quantity != 500 || get.price != 1.5)) {
                ret = false;
        }
    }

    inp.close();
    if(!inp.good()) {
        printf("Error reading file: %s\n", "product_drink.dat");
    }

    return ret;
}

int main() {
    clear_file(file_drink);

    manager_t  m;
    
    m.add_drink(product_t("lemon_juice", 50, 1.5));

    m.add_drink(product_t("orange_juice", 100, 1.25));

    m.add_drink(product_t("watermelon_juice", 250, 2.5));

    m.add_drink(product_t("cappuccino", 500, 1.5));

    m.add_drink(product_t("lemon_juice", 150, 1.5));

    m.add_drink(product_t("watermelon_juice", 250, 2.5));


    if(!test_drink_in_file()) {
        UT_MSG_FAILED("Test add drink");
        return 1;
    }
    UT_MSG_OK("Test add drink");
    return 0;
}