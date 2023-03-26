#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> memo;

int func(int i, int w, const vector<int> &a)
{
    if (i == 0)
    {
        if (w == 0)
            return true;
        else
            return false;
    }

    if (memo[i][w] != -1)
        return memo[i][w];

    if (func(i - 1, w, a))
        return memo[i][w] = 1;
    if (func(i - 1, w - a[i - 1], a))
        return memo[i][w] = 1;

    return memo[i][w] = 0;
}

int main()
{
    int n, w;
    cin >> n >> w;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    memo.assign(n + 1, vector<int>(w + 1, -1));
    if (func(n, w, a))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}