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

const int INF = 20000000;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int min_value = INF;
    sort(b.begin(), b.end());
    b.push_back(INF);

    for (int i = 0; i < n; i++)
    {
        auto iter = lower_bound(b.begin(), b.end(), k - a[i]);
        int val = *iter;
        if (a[i] + val < min_value)
        {
            min_value = a[i] + val;
        }
    }
    cout << min_value << endl;
}
