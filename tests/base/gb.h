#ifndef TESTS_BASE_H_
#define TESTS_BASE_H_

#include "coffee.h"

/*
    username: hieutran29
    password: hieu1234
    name    : HieuTran
    dob     : 29/08/2001
*/
manager test_new_accout_m1(bool &is_existed);



/*
    username: hieu29
    password: hieu1234
    name    : TranHieu
    dob     : 29/08/2001
*/
manager test_new_accout_m2(bool &is_existed);



/*
    username: hieutran29
    password: hieu1234
    name    : TranTrungHieu
    dob     : 29/08/2001
*/
manager test_new_accout_m3(bool &is_existed);



/*
    username: hieu.xteen
    password: hieu1234
    name    : TranHieu
    dob     : 29/08/2001
*/
manager test_new_accout_m4(bool &is_existed);

void print_all_managers();

#endif  // TESTS_BASE_H_