#include <iostream>

#include <gb.h>

using namespace std;

int main(int argc, char * argv[]) {
    if(argc == 1) {
        perror("No file information");
        return 1;
    }

    string file;
    unsigned size;

    if(strcmp(argv[1], "manager_account.dat") == 0) {
        file = file_manager;
        size = sizeof(manager_t);
    }
    else if(strcmp(argv[1], "guest_account.dat") == 0) {
        file = file_guest;
        size = sizeof(guest_t);
    }
    else if(strcmp(argv[1], "product_drink.dat") == 0) {
        file = file_drink;
        size = sizeof(product_t);
    }
    else if(strcmp(argv[1], "product_food.dat") == 0) {
        file = file_food;
        size = sizeof(product_t);
    }

    else {
        perror("File not found");
        return 1;
    }

    ifstream inp(file, ios::binary | ios::in);

    inp.seekg(0, ios::end);
    long fileSize = inp.tellg();
    long number_accounts = fileSize / (long) size;
    inp.seekg(0, ios::beg);

    printf("%s:\n", argv[1]);
    if(strcmp(argv[1], "manager_account.dat") == 0) {
        for(long i = 0; i < number_accounts; i++) {
            manager_t compare;
        
            inp.read((char *) &compare, size);

            compare.get();
        }
    }
    if(strcmp(argv[1], "guest_account.dat") == 0) {
        for(long i = 0; i < number_accounts; i++) {
            guest_t compare;
        
            inp.read((char *) &compare, size);

            compare.view_information();
        }
    }
    else if(strcmp(argv[1], "product_drink.dat") == 0 ||
            strcmp(argv[1], "product_food.dat") == 0) {
        for(long i = 0; i < number_accounts; i++) {
            product_t compare;
        
            inp.read((char *) &compare, size);

            compare.get();
        }
    }

    inp.close();
    if(!inp.good()) {
        printf("Error reading file while testing");
    }

    return true;
}