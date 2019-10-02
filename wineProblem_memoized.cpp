#include <iostream>
using namespace std;

int cnt = 0;
int memo[100][100];

int wineProblem(int arr[], int begin, int end, int year)
{
    cnt ++;
    if (memo[begin][end] != -1)
        return memo[begin][end];
    if (begin > end)
        return 0;
    int ans1 = arr[begin] * year + wineProblem(arr, begin + 1, end, year + 1);
    int ans2 = arr[end] * year + wineProblem(arr, begin, end - 1, year + 1);
    memo[begin][end] =  max(ans1, ans2);
    return max(ans1, ans2);
}

int main(int argc, char const *argv[])
{
    int arr[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    for (int i = 0; i < 100; ++i)
        for (int j = 0; j < 100; ++j)
            memo[i][j] = -1;
    cout << "The maximum profit that we can make " << wineProblem(arr, 0, n - 1, 1) << endl;
    cout << "The number of times this function is called " << cnt << endl;
    return 0;
}
