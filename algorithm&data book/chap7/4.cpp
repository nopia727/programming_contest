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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        if (a[i] < b[j])
            i++;
    }
    cout << i << endl;
}