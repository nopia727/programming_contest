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
    int n, w;
    cin >> n >> w;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<bool>> dp(n + 1, vector<bool>(w + 1, false));
    dp[0][0] = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (dp[i][j])
                dp[i + 1][j] = true;
            if (j - a[i] >= 0 && dp[i][j - a[i]])
                dp[i + 1][j] = true;
        }
    }
    if (dp[n][w])
        cout << 'Yes' << endl;
    else
        cout << 'No' << endl;
}