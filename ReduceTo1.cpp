#include <iostream>
using namespace std;
const int inf = (int)1e9;

int reduceNo(int n)
{
    int q1 = inf, q2 = inf, q3 = inf;
    if (n == 1)
        return 0;
    if (n % 2 == 0)
        q1 = reduceNo(n / 2) + 1;
    if (n % 3 == 0)
        q2 = reduceNo(n / 3) + 1;
    q3 = reduceNo(n - 1) + 1;
    return min(q1, min(q2, q3));
}

int main(int argc, char const *argv[])
{
    int n, ans;
    cin >> n;
    ans = reduceNo(n);
    cout << "The number of steps to reduce the number is : " << reduceNo(n) << endl;
    return 0;
}
