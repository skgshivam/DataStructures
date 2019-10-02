#include <iostream>
using namespace std;

int memo[1000];

int fibo(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    if (memo[n] != -1)
        return memo[n];
    int ans = fibo(n - 1) + fibo(n - 2);
    memo[n] = ans;
    return ans;
}

int main(int argc, char const *argv[])
{
    int n, ans;
    cin >> n;
    for (int i = 0; i <= n; ++i)
    {
        memo[i] = -1; // emptying my memopad
    }
    ans = fibo(n);
    cout << "The fibonacci number for " << n << " is: " << ans << endl;
    return 0;
}
