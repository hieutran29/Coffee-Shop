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
