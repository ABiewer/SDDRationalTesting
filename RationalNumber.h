#include <string>

using namespace std;

class RationalNumber
{
public:
    RationalNumber(int n, int d);
    int getNumerator() const;
    int getDenominator() const;
    string toString();
    bool compareEquals(const RationalNumber& otherNum);
    RationalNumber add(const RationalNumber& num2) const;
private:

    void setNumerator(int n);
    void setDenominator(int d);
    void setReducedNumerator(int n);
    void setReducedDenominator(int d);
    int getReducedNumerator() const;
    int getReducedDenominator() const;
    void reduce();
    
    int numerator;
    int denominator;

    int reducedNumerator;
    int reducedDenominator;
};