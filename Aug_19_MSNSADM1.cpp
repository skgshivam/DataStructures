#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int T, tc = 0;
    cin >> T;
    while(tc < T){
        int N;
        cin >> N;
        int arr[2 * N];
        for(int i = 0; i < 2 * N; i++){
            cin >> arr[i];
        }
        int max = 0;
        for(int i = 0; i < N ; i++){
            if(((2 * arr[i]) - arr[N + i]) > max){
                max = (2 * arr[i]) - arr[N + i];
            }
        }
        cout << max * 10 << "\n";
        tc++;
    }
    return 0;
}