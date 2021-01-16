#include <vector>
#include <map>

#include "coffee_manager.h"
#include "coffee_type.h"

using namespace std;

/* need pointer */
/* read CppPrimer before */


class system;

class system {
    friend class manager;

public:
    /* Function */
    ostream& get(ostream &os) {
        for(auto p : product) {
            os << p.first << " " << p.second.first
                << " " << p.second.second << '\n';
        }
        return os;
    }

    void sign_in_as();

private:
    /* variable */
    int sign_in;
    /* map from product to its quantity and its price */
    map<string, pair<long int, double>> product;
    manager m;
};