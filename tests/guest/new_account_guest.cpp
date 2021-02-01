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
    clear_file(file_guest);

    guest_t m;

    m = guest_t("hieutran29", "hieutran29");
    if(existed_in_file(m)) {
        failed = true;
        UT_MSG_FAILED("guest 1");
    }
    else {
        m.new_account();
        UT_MSG_OK("guest 1");
    }

    m = guest_t("hieutran", "hieutran");
    if(existed_in_file(m)) {
        failed = true;
        UT_MSG_FAILED("guest 2");
    }
    else {
        m.new_account();
        UT_MSG_OK("guest 2");
    }

    m = guest_t("hieutran29", "hieutran29");
    if(existed_in_file(m)) {
        failed = false;
        UT_MSG_OK("guest 3");
    }
    else {
        m.new_account();
        UT_MSG_FAILED("guest 3");
    }

    m = guest_t("hieu", "hieu");
    if(existed_in_file(m)) {
        failed = true;
        UT_MSG_FAILED("guest 4");
    }
    else {
        m.new_account();
        UT_MSG_OK("guest 4");
    }

    if(failed) {
        return 1;
    }
    UT_MSG_OK("Test Create New Account for Guest");
    return 0;
}