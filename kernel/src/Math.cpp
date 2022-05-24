#include<Sauce/Math.hpp>

namespace Sauce{
    Decimal_st Decimal_st::operator=(Decimal_st Other){
        WholeValue=Other.WholeValue;
        DecimalValue=Other.DecimalValue;
        return Other;
    }
    Decimal_st Decimal_st::operator+=(Decimal_st Other){
        Other.DecimalValue+=DecimalValue;
        if(Other.DecimalValue < 0){
            Other.WholeValue--;
            Other.DecimalValue=(Other.DecimalValue-Other.DecimalValue-Other.DecimalValue);
            Other.DecimalValue=10-(Other.DecimalValue%10);
        }
        Other.WholeValue+=WholeValue;

        WholeValue=Other.WholeValue;
        DecimalValue=Other.DecimalValue;
        return Other;
    }
    Decimal_st Decimal_st::operator-=(Decimal_st Other){
        Other.DecimalValue-=DecimalValue;
        if(Other.DecimalValue < 0){
            Other.WholeValue--;
            Other.DecimalValue=(Other.DecimalValue-Other.DecimalValue-Other.DecimalValue);
            Other.DecimalValue=10-(Other.DecimalValue%10);
        }
        Other.WholeValue-=WholeValue;

        WholeValue=Other.WholeValue;
        DecimalValue=Other.DecimalValue;
        return Other;
    }
    double Decimal_st::operator()(){
        double Result=(double)((int)WholeValue);
        double tmp=(double)((int)DecimalValue);
        tmp/=100;
        Result+=tmp;
        return Result;
    }
    Decimal_st Decimal_st::operator=(double Other){
        int tmpa=(int)Other;
        double tmpb = Other-((double)tmpa);
        tmpb*=100;
        WholeValue=(int64_t)tmpa;
        DecimalValue=(int64_t)((int)tmpb);
        Decimal_st Result;
        Result=(*this);
        return Result;
    }
    Decimal_st Decimal_st::operator+=(double Other){
        Decimal_st Result;
        Result=Other;
        (*this)+=Result;
        Result=(*this);
        return Result;
    }
    Decimal_st Decimal_st::operator-=(double Other){
        Decimal_st Result;
        Result=Other;
        (*this)-=Result;
        Result=(*this);
        return Result;
    }
    size_t ind(size_t X,size_t Y,size_t MaxX){
        return (X + (Y * MaxX));
    }
};