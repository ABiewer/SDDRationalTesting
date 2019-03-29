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
private:

    void setNumerator(int n);
    void setDenominator(int d);
    void setReducedNumerator(int n);
    void setReducedDenominator(int d);
    int getReducedNumerator();
    int getReducedDenominator();
    void reduce();
    
    int numerator;
    int denominator;

    int reducedNumerator;
    int reducedDenominator;
};