#include <iostream>
#include <vector>
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
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int w = 10000;
    vector<vector<bool>> dp(n + 1, vector<bool>(w + 1, false));
    dp[0][0] = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (!dp[i][j])
                continue;
            dp[i + 1][j] = true;
            if (j + a[i] <= w)
                dp[i + 1][j + a[i]] = true;
        }
    }
    int res = 0;
    for (int j = 0; j <= w; j++)
    {
        if (dp[n][j])
            res++;
    }
    cout << res << endl;
}