#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int T, tc = 0;
    long N, K;
    cin >> T;
    while(tc < T){
        cin >> N >> K;
        if(N % (K * K) == 0)
            cout << "NO" << "\n";
        else
            cout << "YES" << "\n";
        tc++;
    }
    return 0;
}