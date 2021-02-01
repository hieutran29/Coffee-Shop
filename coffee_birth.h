#include <iostream>

class birth {
    friend class manager;

public:
    birth() = default;

    birth(int d, int m, int y) : day(d), month(m), year(y) { }

    /* Function */
    birth& add() {
        printf("dd/mm/yyyy:");
        std::cin >> day >> month >> year;
        return *this;
    }

    birth& assign(const birth & b) {
        day = b.day;
        month = b.month;
        year = b.year;
        return *this;
    }
    void get() const {
        printf("dob: ");
        std::cout << this->day << "/" << this->month
            << "/" << this->year;
    }

private:
    
    int day, month, year;
};