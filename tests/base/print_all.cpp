#include <iostream>

#include <gb.h>

using namespace std;

int main() {
    ifstream inp(file_manager, ios::binary | ios::in);

    inp.seekg(0, ios::end);
    long fileSize = inp.tellg();
    long number_accounts = fileSize / sizeof(manager);
    inp.seekg(0, ios::beg);


    for(long i = 0; i < number_accounts; i++) {
        manager compare;
    
        inp.read((char *) &compare, sizeof(manager));

        compare.get();
    }
    
    return true;
}