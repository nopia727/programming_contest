#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
template <class T>
void chmax(T &a, T b)
{
    if (a < b)
        a = b;
}
template <class T>
void chmin(T &a, T b)
{
    if (a > b)
        a = b;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    long long sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        a[i] += sum;
        long long amari = a[i] % b[i];
        long long d = 0;
        if (amari != 0)
            d = b[i] - amari;
        sum += d;
    }
}