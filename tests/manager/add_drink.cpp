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

    product_t p;
    manager  m;
    
    p = drink_1();
    m.add_drink(p);

    p = drink_2();
    m.add_drink(p);

    p = drink_3();
    m.add_drink(p);

    p = drink_4();
    m.add_drink(p);

    p = drink_5();
    m.add_drink(p);

    p = drink_6();
    m.add_drink(p);


    if(!test_drink_in_file()) {
        return 1;
    }
    UT_MSG_OK("Test add drink");
    return 0;
}