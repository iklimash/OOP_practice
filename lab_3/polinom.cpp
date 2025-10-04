#include "polinom.h"

using namespace std;

Polinom::Polinom(): coefficients(nullptr), roots(nullptr), degree(0){}


Polinom *Polinom::fill(number coefficientAn, number* roots, int rootsCount)
{
    Polinom* polinom = new Polinom();
    polinom->roots = roots;
    polinom->coefficients = new number [rootsCount];
    polinom->coefficients[0] = coefficientAn;
    if(rootsCount > 1){
        polinom->degree = rootsCount - 1;
        for (int i = 1; i <= polinom->degree; ++i) {
            polinom->coefficients[i] = 0;
        }
        for (int i = 0; i < polinom->degree; ++i) {
            number root = roots[i];
            for (int j = i; j >= 0; --j) {
                polinom->coefficients[j + 1] += polinom->coefficients[j];
                polinom->coefficients[j] *= root * -1;
            }
        }
        for(int i = 0; i < rootsCount / 2; i++){
            swap(polinom->coefficients[i], polinom->coefficients[rootsCount - i - 1]);
        }
    }else polinom->degree = 0;
    return polinom;
}

ostream& operator<< (ostream& os, const Polinom &polinom)
{
    os << "P(x) = ";
    if(polinom.roots == nullptr) {
        os << *(polinom.coefficients);
        return os;
    }
    if (*(polinom.coefficients) != 0){
        if(*(polinom.coefficients) != 1) os << " (" << *(polinom.coefficients) << ")x^" << polinom.degree;
        else os << "x^" << polinom.degree;
    }
    for ( int i = 1; i < polinom.degree - 1; i++ ){
        if (*(polinom.coefficients + i) != 0){
            os << " ";
            if(*(polinom.coefficients + i) > 0) os << "+ ";
            if (*(polinom.coefficients + i) != 1) os << "(" <<  *(polinom.coefficients + i) << ")x^" << polinom.degree - i;
            else os << "x^" << polinom.degree - i;
        }
    }
    if ( *(polinom.coefficients + polinom.degree - 1) != 0 ){
        if(*(polinom.coefficients + polinom.degree - 1) > 0){
            os << " + (" << *(polinom.coefficients + polinom.degree - 1) << ")x";
        }else os << " (" << *(polinom.coefficients + polinom.degree - 1) << ")x";
    }
    if ( *(polinom.coefficients + polinom.degree) != 0 ){
        if(*(polinom.coefficients + polinom.degree) > 0 ) os << " +" ;
        os << " (" << *(polinom.coefficients + polinom.degree) << ")";
    }
    return os;
}

number Polinom::valueInPoint (number point)
{
    number sum = 0;
    if (degree == 0) return *(coefficients);
    for (int i = 0; i < degree; i++)
    {
        number a = *(coefficients + i);
        number b = pow(point, degree - i);
        sum += a * b;
    }
    sum += *(coefficients + degree);
    return sum;
}























