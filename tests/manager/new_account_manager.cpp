#include "ut.h"
#include "gb.h"


#define TEST_EXIST(arg, msg) \
    do {    \
        if((arg)) { \
            UT_MSG_OK(msg);  \
        }   \
        else {  \
            UT_MSG_FAILED(msg);  \
        }   \
    } while (0)



int main() {
    printf("fdjsal;\n");
    bool is_existed = false;
    manager m;
    
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

    return 0;
}