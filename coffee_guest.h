#include <vector>
#include <string>

using namespace std;

struct visit {
    int day, month, year;
    string food;
    string drink;
};

class guest {


private:
    string name;
    string address;
    int age;
    visit visit_detail;
    int time_visit;
};