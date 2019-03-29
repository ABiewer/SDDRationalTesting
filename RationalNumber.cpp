#include "RationalNumber.h"

RationalNumber::RationalNumber(int n, int d)
{
    setNumerator(n);
    setDenominator(d);
    reduce();
}
//--
int RationalNumber::getNumerator() const
{
    return numerator;
}
//--
int RationalNumber::getDenominator() const
{
    return denominator;
}
void RationalNumber::setNumerator(int n)
{
    numerator = n;
}
//--
void RationalNumber::setDenominator(int d)
{
    if(d == 0)
    {
        throw "Divide by zero exception";
    }
    else
    {
        denominator = d;
    }
}
//--
string RationalNumber::toString()
{
    return to_string(getNumerator()) + "/" + to_string(getDenominator());
}
//--
bool RationalNumber::compareEquals(const RationalNumber& otherNum)
{
    return (getNumerator() == otherNum.getNumerator()) &&
           (getDenominator() == otherNum.getDenominator());
}
//--
void RationalNumber::setReducedNumerator(int n)
{
    reducedNumerator = n;
}
//--
void RationalNumber::setReducedDenominator(int d)
{
    reducedDenominator = d;
}
//--
int RationalNumber::getReducedNumerator()
{
    return reducedNumerator;
}
//--
int RationalNumber::getReducedDenominator()
{
    return reducedDenominator;
}
//--
void RationalNumber::reduce()
{

}