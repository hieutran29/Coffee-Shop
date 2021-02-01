#include "gb.h"
#include "ut.h"

/*
    username: hieutran29
    password: hieutran29
    name    : hieutran29
    dob     : 29/08/2001
*/
manager_t account_m1() {
    manager_t m("hieutran29", "hieutran29", "hieutran29", 
                birth(29, 8, 2001));
    return m;
}

/*
    username: hieu29
    password: hieu29
    name    : hieu29
    dob     : 29/08/2001
*/
manager_t account_m2() {
    manager_t m("hieu29", "hieu29", "hieu29",
                birth(29, 8, 2001));
    return m;
}

/*
    username: hieutran29
    password: hieutran29
    name    : hieutran29
    dob     : 29/08/2001
*/
manager_t account_m3() {
    manager_t m("hieutran29", "hieutran29", "hieutran29", 
                birth(29, 8, 2001));
    return m;
}

/*
    username: hieu
    password: hieu
    name    : hieu
    dob     : 29/08/2001
*/
manager_t account_m4() {
    manager_t m("hieu", "hieu", "hieu", 
                birth(29, 8, 2001));
    return m;
}



/*-------------------------*/
/*        TEST DRINK       */
/*-------------------------*/

/*
    name: lemon_juice
    quantity: 50
    price: 1.5$
*/
product_t drink_1() {
    return product_t("lemon_juice", 50, 1.5);
}


/*
    name: orange_juice
    quantity: 100
    price: 1.25$
*/
product_t drink_2() {
    return product_t("orange_juice", 100, 1.25);
}


/*
    name: watermelon_juice
    quantity: 250
    price: 2.5$
*/
product_t drink_3() {
    return product_t("watermelon_juice", 250, 2.5);
}


/*
    name: cappuccino
    quantity: 500
    price: 1.5$
*/
product_t drink_4() {
    return product_t("cappuccino", 500, 1.5);
}


/*
    name: lemon_juice
    quantity: 150
    price: 1.5$
*/
product_t drink_5() {
    return product_t("lemon_juice", 150, 1.5);
}


/*
    name: watermelon_juice
    quantity: 250
    price: 2.5$
*/
product_t drink_6() {
    return product_t("watermelon_juice", 250, 2.5);
}


void clear_file(const string &file) {
    ofstream outp(file, ios::out | ios::trunc);
    outp.close();
}