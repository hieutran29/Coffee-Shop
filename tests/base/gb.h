#ifndef TESTS_BASE_H_
#define TESTS_BASE_H_

#include "coffee.h"

/*
    username: hieutran29
    password: hieutran29
    name    : hieutran29
    dob     : 29/08/2001
*/
manager_t account_m1();



/*
    username: hieu29
    password: hieu29
    name    : hieu29
    dob     : 29/08/2001
*/
manager_t account_m2();



/*
    username: hieutran29
    password: hieutran29
    name    : hieutran29
    dob     : 29/08/2001
*/
manager_t account_m3();


/*
    username: hieu
    password: hieu
    name    : hieu
    dob     : 29/08/2001
*/
manager_t account_m4();




/*-------------------------*/
/*        TEST DRINK       */
/*-------------------------*/

/*
    name: lemon_juice
    quantity: 50
    price: 1.5$
*/
product_t drink_1();


/*
    name: orange_juice
    quantity: 100
    price: 1.25$
*/
product_t drink_2();


/*
    name: watermelon_juice
    quantity: 250
    price: 2.5$
*/
product_t drink_3();


/*
    name: cappuccino
    quantity: 500
    price: 1.5$
*/
product_t drink_4();


/*
    name: lemon_juice
    quantity: 150
    price: 1.5$
*/
product_t drink_5();


/*
    name: watermelon_juice
    quantity: 250
    price: 2.5$
*/
product_t drink_6();


void clear_file(const string &file);


#endif  // TESTS_BASE_H_