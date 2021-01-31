#include <vector>
#include <map>
#include <iostream>

#include "coffee_manager.h"
#include "coffee_type.h"

using namespace std;

/* need pointer */
/* read CppPrimer before */


class system_t;

class system_t {
    friend class manager;

public:
    /* Constructor */
    system_t() = default;

    /* Function */
    system_t& sign_in();
    system_t& sign_in_as_manager();

private:
    /* map from product to its quantity and its price */
    map<string, pair<long int, double>> product;
    manager man;
};