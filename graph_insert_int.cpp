#include<iostream>
#include<list>
using namespace std;

template <typename T>
class Graph{
    int V;
    list<T> *l;     
public:
    Graph(int v){
        V = v;
        l = new list<T>[v];
    }
    
    void addEdge(T a, T b, bidir = True){
        l[a].push_back(b);
        if(bidir){
            l[b].push_back(a);
        }
    }

    void printAdjList(){
        for(auto i:l){
            cout << 
        }
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
