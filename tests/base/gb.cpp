#include "gb.h"
#include "ut.h"

/*
    username: hieutran29
    password: hieu1234
    name    : HieuTran
    dob     : 29/08/2001
*/
manager test_new_accout_m1(bool &is_existed) {
    manager m;
    m.new_account(is_existed);
    return m;
}

/*
    username: hieu29
    password: hieu1234
    name    : TranHieu
    dob     : 29/08/2001
*/
manager test_new_accout_m2(bool &is_existed) {
    manager m;
    m.new_account(is_existed);
    return m;
}

/*
    username: hieutran29
    password: hieu1234
    name    : TranTrungHieu
    dob     : 29/08/2001
*/
manager test_new_accout_m3(bool &is_existed) {
    manager m;
    m.new_account(is_existed);
    return m;
}

/*
    username: hieu.xteen
    password: hieu1234
    name    : TranHieu
    dob     : 29/08/2001
*/
manager test_new_accout_m4(bool &is_existed) {
    manager m;
    m.new_account(is_existed);
    return m;
}

void print_all_managers() {
    ifstream inp;
    inp.open("C:\\Users\\ADMIN\\OneDrive\\Code\\Coffee-Shop\\data\\manager_account.dat",
                    ios::in | ios::binary);

    inp.seekg(0, ios::end);
    long fileSize = inp.tellg();
    long number_accounts = fileSize / sizeof(manager_t);
    inp.seekg(0, ios::beg);


    for(int i = 0; i < number_accounts; i++) {
        manager_t get;
        inp.read((char *) &get, sizeof(manager_t));
        printf("Username: %s\n", get.username);
        printf("Password: %s\n", get.password);
        printf("Name: %s\n", get.name);
        get.dob.get();
        printf("\n\n");
    }

    inp.close();
    if(inp.bad()) {
        printf("Error occurs in reading file: %s\n", "manager_accounts.dat");
    }
}
