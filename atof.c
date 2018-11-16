#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double _atof(char* num)
{
    if (!num || !*num)
        return 0; 
    double integerPart = 0;
    double fractionPart = 0;
    int divisorForFraction = 1;
    int sign = 1;
    int inFraction = 0;
    /*Take care of +/- sign*/
    if (*num == '-') {
        ++num;
        sign = -1;
    }
    else if (*num == '+') {
        ++num;
    }
    while (*num != '\0') {
        if (*num >= '0' && *num <= '9') {
            if (inFraction) {
                /*See how are we converting a character to integer*/
                fractionPart = fractionPart*10 + (*num - '0');
                divisorForFraction *= 10;
            } else {
                integerPart = integerPart*10 + (*num - '0');
            }
        }
        else if (*num == '.') {
            if (inFraction)
                return sign * (integerPart + fractionPart/divisorForFraction);
            else
                inFraction = 1;
        } else {
            return sign * (integerPart + fractionPart/divisorForFraction);
        }
        ++num;
    }
    return sign * (integerPart + fractionPart/divisorForFraction);
}


int main()
{
    char *x = "123.865";
    double f = _atof(x);
    printf("%f\n", f);
    return 0;
}
