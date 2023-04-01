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

const int INF = 1 << 29;
int main()
{
    int n, k, w;
    cin >> n >> k >> w;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<long long>> dp(n + 1, vector<long long>(w + 1, INF));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            chmin(dp[i + 1][j], dp[i][j]);
            if (j - a[i] <= 0)
                chmin(dp[i + 1][j], dp[i][j - a[i]] + 1);
        }
    }
    if (dp[n][w] <= k)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}