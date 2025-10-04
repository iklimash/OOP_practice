#ifndef POLINOM_H
#define POLINOM_H

#include "number.h"

class Polinom
{
    number* coefficients = nullptr;
    number* roots = nullptr;\
        int degree = 0;
public:
    Polinom();

    Polinom* fill(number coefficientAn, number* roots, int rootsCount);

    number valueInPoint (number point);

    friend ostream& operator<< (ostream& os, const Polinom &polinom);
};

#endif // POLINOM_H
