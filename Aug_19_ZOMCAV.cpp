#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int T, tc = 0, N, input;
    cin >> T;
    while(tc < T){
        cin >> N;
        vector <int> C(N), H(N), output(N);
        for(int i = 0; i < N; i++){
            cin >> input;
            C[i] = input;
        }
        for(int i = 0; i < N; i++){
            cin >> input;
            H[i] = input;
        }
        for(int i = 0; i < N; i++){
            for(int j = i - C[i]; j <= i + C[i] ; j++){
                if(j >=0 && j < N){
                    output[j]++;
                }
            }
        }
        sort(output.begin(), output.end());
        sort(H.begin(), H.end());
        if(H == output)
            cout << "YES\n";
        else
            cout << "NO\n";
        tc++;
    }
    return 0;
}
