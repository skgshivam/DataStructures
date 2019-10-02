// for  2,3,5,1,4 => 50
// for 1,4,2,3 => 29

#include <iostream>
using namespace std;
int cnt = 0;

int wineProfit(int arr[], int beg, int end, int year)
{
    cnt++;
    if (beg > end)
        return 0;
    int q1 = arr[beg] * year + wineProfit(arr, beg + 1, end, year + 1);
    int q2 = arr[end] * year + wineProfit(arr, beg, end - 1, year + 1);
    return max(q1, q2);
}

int main(int argc, char const *argv[])
{
    int n, arr[1000];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout << "The maximum profit that we can achieve is :" << wineProfit(arr, 0, n - 1, 1) << endl;
    cout << "The number of times the function is called :" << cnt << endl; // Just for checking if memoization gives better result or not
    return 0;
}
