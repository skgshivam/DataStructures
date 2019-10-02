#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    int arr[n], pre_dp[n], cur_sum, total = 0;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        pre_dp[i] = 1;
        // cur_dp[i] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        int cur_sum = 0;
        int sum_prev_j_minus_1 = 0;
        for (int j = 0; j < n; j++)
        {
            pre_dp[j] = cur_sum + (j != 0 ? pre_dp[j - 1] : 0);
            cur_sum = pre_dp[i];
            cout << pre_dp[j] << ",";
        }
        cout << endl;
        total += (sum_prev_j_minus_1 % 1000000007);
    }
    cout << total << endl;
    return 0;
}
