#include <iostream>
#include <vector>
#include <algorithm>
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
    long long n;
    cin >> n;
    vector<long long> a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    long long res = 0;
    for (int j = 0; j < n; j++)
    {
        long long aj = lower_bound(a.begin(), a.end(), b[j]) - a.begin();
        long long cj = n - (upper_bound(c.begin(), c.end(), b[j]) - c.begin());
        res += aj * cj;
    }
    cout << res << endl;
}