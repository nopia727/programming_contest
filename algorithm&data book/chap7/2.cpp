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

using Interval = pair<int, int>;

bool cmp(const Interval &a, const Interval &b)
{
    return a.second < b.second;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> inter(n);
    for (int i = 0; i < n; i++)
    {
        cin >> inter[i].first >> inter[i].second;
        sort(inter.begin(), inter.end(), cmp);
    }
    int res = 0;
    int current_end_time = 0;
    for (int i = 0; i < n; i++)
    {
        if (inter[i].first < current_end_time)
            continue;
        ++res;
        current_end_time = inter[i].second;
    }
}