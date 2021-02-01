#include "ut.h"
#include "gb.h"

bool failed = false;

#define TEST_EXIST(arg, msg) \
    do {    \
        if((arg)) { \
            UT_MSG_FAILED(msg);  \
            failed = true; \
        }   \
        else {  \
            UT_MSG_OK(msg);  \
        }   \
    } while (0)



int main() {
    clear_file(file_manager);

    manager m;

    m = account_m1();
    if(existed_in_file(m)) {
        failed = true;
        UT_MSG_FAILED("Manager 1");
    }
    else {
        m.new_account();
        UT_MSG_OK("Manager 1");
    }

    m = account_m2();
    if(existed_in_file(m)) {
        failed = true;
        UT_MSG_FAILED("Manager 2");
    }
    else {
        m.new_account();
        UT_MSG_OK("Manager 2");
    }

    m = account_m3();
    if(existed_in_file(m)) {
        failed = false;
        UT_MSG_OK("Manager 3");
    }
    else {
        m.new_account();
        UT_MSG_FAILED("Manager 3");
    }

    m = account_m4();
    if(existed_in_file(m)) {
        failed = true;
        UT_MSG_FAILED("Manager 4");
    }
    else {
        m.new_account();
        UT_MSG_OK("Manager 4");
    }

    if(failed) {
        return 1;
    }
    UT_MSG_OK("Test Create New Account for Manager");
    return 0;
}