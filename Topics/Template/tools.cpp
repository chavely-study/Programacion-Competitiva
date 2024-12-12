#include <bits/stdc++.h>
using namespace std;

struct cmp
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const
    {
        int lena = a.second - a.first;
        int lenb = b.second - b.first;
        if (lena == lenb)
            return a.first > b.first;
        return lena < lenb;
    }
};

char query(int a, int b, int c, int d)
{
    char x;
    printf("? %d %d %d %d\n", a, b, c, d);
    fflush(stdout);
    cin >> x;
    fflush(stdout);
    return x;
}

