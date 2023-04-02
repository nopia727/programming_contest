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
    long long n, m;
    cin >> n >> m;
    vector<long long> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    p.push_back(0);
    vector<long long> s;
    for (int i = 0; i < p.size(); i++)
    {
        for (int j = 0; j < p.size(); j++)
        {
            s.push_back(p[i] + p[j]);
        }
    }
    sort(s.begin(), s.end());

    long long res = 0;
    for (long long a : s)
    {
        auto it = upeer_bound(s.begin(), s.end(), m - a);
        if (it == s.begin())
            continue;
        --it;
        res = max(res, a + *it);
    }
    cout << res << endl;
}