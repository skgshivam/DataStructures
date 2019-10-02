// For computing fibo(40) or greater then it is taking very large amount of time
// The complexity of this algorithm is therefore

#include <iostream>
#include <time.h>
using namespace std;

int fibo(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    return fibo(n - 1) + fibo(n - 2);
}

int main(int argc, char const *argv[])
{
    clock_t start, end;
    double time_taken;
    start = clock();
    int n, ans;
    cin >> n;
    ans = fibo(n);
    cout << "The fibonacci number for " << n << " is: " << ans << endl;
    end = clock();
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("fun() took %f seconds to execute \n", time_taken);
    return 0;
}
