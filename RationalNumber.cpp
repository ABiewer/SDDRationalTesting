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
    if (d == 0)
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
bool RationalNumber::compareEquals(const RationalNumber &otherNum)
{
    return (getReducedNumerator() == otherNum.getReducedNumerator()) &&
           (getReducedDenominator() == otherNum.getReducedDenominator());
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
int RationalNumber::getReducedNumerator() const
{
    return reducedNumerator;
}
//--
int RationalNumber::getReducedDenominator() const
{
    return reducedDenominator;
}
//--
void RationalNumber::reduce()
{
    int n = getNumerator();
    int d = getDenominator();

    if(n==0){
        setReducedNumerator(0);
        setReducedDenominator(1);
    }
    else if (d % n == 0)
    {
        setReducedNumerator(1);
        setReducedDenominator(d / n);
    }

    else if (n % d == 0)
    {
        setReducedDenominator(1);
        setReducedNumerator(n / d);
    }

    else
    {
        int rn = n;
        int rd = d;
        for (int i = 2; i < rn && i < rd; i++)
        {
            if(i==1)
            {
                i = 2;
            }
            if (rn % i == 0 && rd % i == 0)
            {
                rn = rn / i;
                rd = rd / i;
                i--;
            }
        }
        setReducedDenominator(rd);
        setReducedNumerator(rn);
    }
}
//--
RationalNumber RationalNumber::add(const RationalNumber &num2) const
{
    int newDenom = getReducedDenominator() * num2.getReducedDenominator();
    int numerator1 = getReducedNumerator() * num2.getReducedDenominator();
    int numerator2 = num2.getReducedNumerator() * getReducedDenominator();

    return RationalNumber(numerator1 + numerator2, newDenom);
}