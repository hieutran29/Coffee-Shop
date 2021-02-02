#include "ut.h"
#include "gb.h"

bool failed = false;

void test_1() {
    bool ret;
    guest_t sign_in;

    guest_t m("hieutran", "hieutran");
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
    guest_t sign_in;

    guest_t m("hieu29", "hieu");
    ret = sign_in.sign_in(m);

    if(ret) {
        failed = true;
    }

    if(ret) {
        UT_MSG_FAILED("Manager 2");
    }  
    else {
        UT_MSG_OK("Manager 2");
    }
}

void test_3() {
    bool ret;
    guest_t sign_in;

    guest_t m("hieutran29", "hieutran29");
    ret = sign_in.sign_in(m);

    if(!ret) {
        failed = true;
    }

    if(!ret) {
        UT_MSG_FAILED("Manager 3");
    }
    else {
        UT_MSG_OK("Manager 3");
    }
}

int main() {
    test_1();
    printf("\n");

    test_2();
    printf("\n");

    test_3();
    printf("\n");

    if(failed) {
        UT_MSG_FAILED("Test Sign In for Guest");
        return 1;
    }
    UT_MSG_OK("Test Sign In for Guest");
    return 0;
}