#pragma once
#include <climits>

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
            err = -1;
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

    int pow(int a, unsigned int b)
    {
        int result = 1;
        for (unsigned int i = 0; i < b; i++)
        {
            if (result > INT_MAX / a)
            {
                return -1;
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
            return -1;
        }
        return a * factorial(a - 1);
    }

}