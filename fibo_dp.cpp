#include <iostream>
using namespace std;

int fibo(int num)
{
    int dp[1000] = {};
    dp[0] = 0;
    dp[1] = 1;
    for (int current = 2; current <= num; ++current)
        dp[current] = dp[current - 1] + dp[current - 2];
    return dp[num];
}

int main(int argc, char const *argv[])
{
    int num, ans;
    cin >> num;
    ans = fibo(num);
    cout << "The Fibonacci number for " << num << " is: " << ans << endl;
    return 0;
}
