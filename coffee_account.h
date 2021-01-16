#include <string>

#include "coffee_type.h"

class account {
    friend class manager;

private:
    std::string name, password;
    COFFEE_ROLE role;
};