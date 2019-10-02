// Will take long time to run for 1000 if memoization is not used
// The complexity if O(n) as n states have to be computed.

#include <iostream>
#include <algorithm>
using namespace std;

const int inf = (int)1e9;
int memo[10000];

int reduceNo(int n)
{
    if (n == 1)
        return 0;
    if (memo[n] != -1)
        return memo[n];
    int q1 = inf, q2 = inf, q3 = inf;
    if (n % 3 == 0)
        q1 = 1 + reduceNo(n / 3);
    if (n % 2 == 0) // Cannot use else if as at one state we are checking all the other states
        q2 = 1 + reduceNo(n / 2);
    q3 = 1 + reduceNo(n - 1);
    memo[n] = min(q1, min(q2, q3)); // Memoize has to be done
    return min(q1, min(q2, q3));
}

int main(int argc, char const *argv[])
{
    int n, ans;
    cin >> n;
    fill(memo, memo + n + 1, -1); // Or can use for loop to fill the memo array
    ans = reduceNo(n);
    cout << "The number of steps required: " << ans << endl;
    return 0;
}
