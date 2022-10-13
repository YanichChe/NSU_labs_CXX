#include "comparison.h"
#include <vector>
#include <iostream>

int min(int a, int b)
{
    if (a > b)
        return b;
    return a;
}

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

std::vector<int> min(std::vector<int> a, std::vector<int> b)
{

    if (a.size() == b.size())
    {
        for (int i = a.size() - 1; i >= 0; i--)
        {
            if (a[i] < b[i])
                return a;
            else
                return b;
        }
    }

    if (a.size() < b.size())
        return a;

    return b;
}

std::vector<int> max(std::vector<int> a, std::vector<int> b)
{
    if (a.size() == b.size())
    {
        for (int i = a.size() - 1; i >= 0; i--)
        {
            if (a[i] > b[i])
                return a;
            else
                return b;
        }
    }

    if (a.size() > b.size())
        return a;

    return b;
}

bool operator==(const std::vector<int> a, const std::vector<int> b)

{
    if (a.size() == b.size())
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != b[i])
            {
                return false;
            }
        }

        return true;
    }

    return false;
}
