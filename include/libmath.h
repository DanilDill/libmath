#pragma once
#include <climits>
#include <math.h>
#define DIV_BY_ZERO -1
#define OVERFLOW -2
namespace math 
{
    int add(int a, int b)
    {
        return a + b;
    }

    int sub(int a, int b)
    {
        return a - b;
    }

    int mul(int a, int b)
    {
        return a * b;
    }

    int div(int a, int b, int& err)
    {
        err = 0;
        if (b == 0 )
        {
            err = DIV_BY_ZERO;
            return 0;
        }
        return a / b;
    }

    int mod(int a, int b, int& err)
    {
        err = 0;
        if (b == 0)
        {
            err = -1;
            return 0;    /* code */
        }
        return a % b;
    }

    int pow(int a, unsigned int b, int& err)
    {
        int result = 1;
        for (unsigned int i = 0; i < b; i++)
        {
            if (abs(result) > INT_MAX / a)
            {
                err =  OVERFLOW;
                return result; 
            }

            result *= a;
        }
        return result; 
        
    }

    int factorial(unsigned int a)
    {
        static int maxFactorial = 12;
        int result = 1;
        if (result == a)
        {
            return result;
        }
        if (a > maxFactorial)
        {
            return OVERFLOW;
        }
        return a * factorial(a - 1);
    }

}