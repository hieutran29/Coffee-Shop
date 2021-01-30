#include "ut.h"
#include "gb.h"

bool failed = false;

void test_1() {
    bool ret;
    manager sign_in;

    manager_t m;
    strcpy(m.username, "hieutran");
    strcpy(m.password, "hieutran");
    ret = sign_in.sign_in(m);
    if(!ret) {
        failed = true;
    }

    if(!ret) {
        UT_MSG_FAILED("Manager 1");
    }  
    else {
        UT_MSG_OK("Manager 1");
    }
}

void test_2() {
    bool ret;
    manager sign_in;

    manager_t m;
    strcpy(m.username, "hieu29");
    strcpy(m.password, "hieu");
    ret = sign_in.sign_in(m);
    if(!ret) {
        failed = true;
    }

    if(!ret) {
        UT_MSG_FAILED("Manager 2");
    }  
    else {
        UT_MSG_OK("Manager 2");
    }
}

int main() {
    test_1();
    printf("\n");

    test_2();
    printf("\n");

    if(failed) {
        UT_MSG_FAILED("Test Sign In for Manager");
        return 1;
    }
    UT_MSG_OK("Test Sign In for Manager");
    return 0;
}