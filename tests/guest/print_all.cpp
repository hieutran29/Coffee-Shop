#include <iostream>

#include <gb.h>

using namespace std;

int main() {
    ifstream inp(file_guest, ios::binary | ios::in);

    inp.seekg(0, ios::end);
    long fileSize = inp.tellg();
    long number_accounts = fileSize / sizeof(guest_t);
    inp.seekg(0, ios::beg);


    for(long i = 0; i < number_accounts; i++) {
        guest_t compare;
    
        inp.read((char *) &compare, sizeof(guest_t));

        compare.view_information();
    }

    inp.close();
    if(!inp.good()) {
        printf("Error reading file while testing");
    }
    
    return true;
}