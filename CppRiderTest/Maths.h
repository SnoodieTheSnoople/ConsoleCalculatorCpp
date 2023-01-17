#pragma once

struct Maths
{
    long Add(long x, long y)
    {
        return x + y;
    }

    long Subtract(long x, long y)
    {
        return x - y;
    }

    long Divide(long x, long y)
    {
        //NOTE: No zerodivision error thrown, handles by returning 0.
        //Improve by implementing in the future.
        return x / y;
    }

    long Multiply (long x, long y)
    {
        return x * y;
    }

    long Square(long x)
    {
        return x * x;
    }
    
    long Power(long x, long power)
    {
        long result = 0;
        for (int i = 1; i <= power; i++)
        {
            result += x * i;
        }
        return result;
    }

    long abs(long x)
    {
        if (x < 0)
        {
            return x * -1;
        }
        return x;
    }
};
