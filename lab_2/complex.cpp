#include "complex.h"
#include "number.h"
#include <iostream>

TComplex::TComplex ()
{
	re = 0;
	im = 0;
}

TComplex::TComplex(double re, double im)
{
	this->re = re;
	this->im = im;
}

TComplex::TComplex(double re)
{
	this->re = re;
	im = 0;
}

double TComplex::getRe() const {
	return this->re;
}


double TComplex::getIm() const {
	return this->im;
}


double TComplex::module(TComplex* complex) {
	double a = std::pow(complex->getRe(), 2);
	double b = std::pow(complex->getIm(), 2);
	return std::pow(a + b, 0.5);
}

TComplex TComplex::operator+(TComplex& second) const
{
	return TComplex(re + second.re, im + second.im);
}

TComplex TComplex::operator-(TComplex& second) const
{
	return TComplex(re - second.re, im - second.im);
}

TComplex TComplex::operator*(TComplex& second) const
{
	double a = re * second.re - im * second.im;
	double b = re * second.im + im * second.re;
	return TComplex(a, b);
}

TComplex TComplex::operator/(TComplex& second) const
{
	double a = (re * second.re + im * second.im) / (second.re * second.re + second.im * second.im);
	double b = (im * second.re - re * second.im) / (second.re * second.re + second.im * second.im);
	return TComplex(a, b);
}

TComplex& TComplex::operator+=(TComplex second)
{
	re += second.re;
	im += second.im;
	return *this;
}

TComplex& TComplex::operator-=(TComplex second)
{
	re -= second.re;
	im -= second.im;
	return *this;
}

TComplex& TComplex::operator*=(TComplex second)
{
	double a = re * second.re - im * second.im;
	double b = re * second.im + im * second.re;
	re = a; im = b;
	return *this;
}

TComplex& TComplex::operator/=(TComplex second)
{
	double a = (re * second.re + im * second.im) / (second.re * second.re + second.im * second.im);
	double b = (im * second.re - re * second.im) / (second.re * second.re + second.im * second.im);
	re = a; im = b;
	return *this;
}

TComplex& TComplex::operator+=(double second) {
	re += second;
	return *this;
}


TComplex& TComplex::operator/=(double second) {
	double a = (re * second) / (second * second);
	double b = (second * im) / (second * second);
	re = a;
	im = b;
	return *this;
}

TComplex& TComplex::operator=(double& second)
{
	re = second;
	im = 0;
	return *this;
}

bool TComplex::operator==(TComplex& second) const
{
	if (re == second.re && im == second.im)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool TComplex::operator!=(TComplex& second) const
{
	if (re == second.re && im == second.im)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool TComplex::operator<(TComplex& second)
{
	if (re != second.re)
	{
		return re < second.re;
	}
	return im < second.im;
}

bool TComplex::operator>(TComplex& second)
{
	if (re != second.re)
	{
		return re > second.re;
	}
	return im > second.im;
}

TComplex pow(TComplex complex, double n) {
	double arg;
	if (complex.re > 0) arg = atan(complex.im / complex.re);
	else if (complex.re < 0 && complex.im >= 0) arg = 3.14 - atan(complex.im / complex.re);
	else if (complex.re < 0 && complex.im < 0) arg = -3.14 + atan(complex.im / complex.re);
	else if (complex.re == 0 && complex.im > 0) arg = 3.14 / 2;
	else arg = -3.14 / 2;
	return TComplex(std::pow(complex.module(&complex), n) * cos(arg * n),
		std::pow(complex.module(&complex), n) * sin(arg * n));
}


istream& operator>>(istream& is, TComplex& c)
{
	is >> c.re >> c.im;
	return is;
}

ostream& operator<<(ostream& os, const TComplex& c)
{
	if (c.im < 0 && c.re != 0)
	{
		os << c.re << c.im << 'i';
	}
	else if (c.im > 0 && c.re != 0)
	{
		os << c.re << '+' << c.im << 'i';
	}
	else if (c.im == 0 && c.re != 0)
	{
		os << c.re;
	}
	else if (c.im != 0 && c.re == 0)
	{
		os << c.im << 'i';
	}
	else 
	{
		os << '0';
	}
	return os;
}






