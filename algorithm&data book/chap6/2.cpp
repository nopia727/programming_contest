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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    auto b = a;
    sort(b.begin(), b.end());
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        res[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    }
    for (int i = 0; i < n; i++)
        cout << res[i] << endl;
}