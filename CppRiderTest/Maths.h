#pragma once

class Maths
{
public:
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
        //NOTE: No zerodivision error thrown, returns 0.
        //Improve by implementing in the future.
        return x / y;
    }

    long Multiply (long x, long y)
    {
        return x * y;
    }

    long Power(long x)
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
        return x - x - x;
    }
};
