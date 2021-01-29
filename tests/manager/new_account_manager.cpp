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
    bool is_existed = false;
    
    test_new_accout_m1(is_existed);
    TEST_EXIST(is_existed, "manager 1");
    is_existed = false;

    test_new_accout_m2(is_existed);
    TEST_EXIST(is_existed, "manager 2");
    is_existed = false;

    test_new_accout_m3(is_existed);
    TEST_EXIST(is_existed, "manager 3");
    is_existed = false;

    test_new_accout_m4(is_existed);
    TEST_EXIST(is_existed, "manager 4");
    is_existed = false;

    if(failed) {
        return 1;
    }
    UT_MSG_OK("Test Create New Account for Manager");
    return 0;
}