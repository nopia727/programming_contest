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

using pll = pair<long long, long long>;

int main()
{
    int n;
    cin >> n;
    vector<pll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end(), [&](pll a, pll b)
         { return a.second < b.second; });

    bool ok = true;
    long long time = 0;
    for (int i = 0; i < n; i++)
    {
        time += v[i].first;
        if (time > v[i].second)
            ok = false;
    }
    if (ok)
        cout << "Yes" << endl;
    else
        cout << "no" << endl;
}