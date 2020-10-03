#include<iostream>
#include<stack>
using namespace std;

int main(){
 int a;
 cin >> a;
 stack<int> s;
 int data;
 for(int i=0;i<a;i++){
 cin >> data;
 s.push(data);
 }
 for(int i=0;i<a;i++){
  cout << s.top();
  s.top();
 }
 return 0;
 }
