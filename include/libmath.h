#pragma once
#include <math.h>

#include <climits>
#define DIV_BY_ZERO -1
#define OVERFLOW -2
namespace math
{
    int add(int a, int b, int& err)
    {
        int result;
        if (__builtin_add_overflow(a, b, &result))
        {
            err = OVERFLOW;
        }
        return result;
    }

    int sub(int a, int b, int& err)
    {
        int result;
        if(__builtin_sub_overflow(a, b, &result))
        {
            err = OVERFLOW;
        }
        return result;
    }

int mul(int a, int b,int& err)
{
    int result;
    if(__builtin_mul_overflow(a, b, &result))
    {
        err = OVERFLOW;
    }
    return result;
}

int div(int a, int b, int& err)
{
    err = 0;
    if (b == 0)
    {
        err = DIV_BY_ZERO;
        return 0;
    }
    return a / b;
}


int pow(int a, unsigned int b, int& err)
{
    int result = 1;
    for (unsigned int i = 0; i < b; i++)
    {
        if (__builtin_mul_overflow(result, a, &result))
        {
            err = OVERFLOW;
            return result;
        }
    }
    return result;
}

int factorial(unsigned int a, int& err)
{
    static int maxFactorial = 12;
    int result = 1;
    if (result == a)
    {
        return result;
    }
    if (a > maxFactorial)
    {
        err = OVERFLOW;
        return a;
    }
    return a * factorial(a - 1, err);
}

} // namespace math