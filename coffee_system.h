#include <vector>
#include <map>
#include <iostream>

#include "coffee_manager.h"
#include "coffee_type.h"

using namespace std;


class system_t;

class system_t {
    friend class manager_t;

public:
    /* Constructor */
    system_t() = default;

    /* Function */
    system_t& sign_in();
    system_t& sign_in_as_manager();
    system_t& sign_in_as_guest();

private:
    manager_t man;
    guest_t guest;
};