#include <iostream>
#include <list>
using namespace std;

class Graph {
private:
    int V;
    list<pair<int,int>> *l;

public:
    Graph (int v) {
        this->V = v;
        this->l = new list<pair<int,int>>[this->V];
    }

    void addEdge(int i, int j, int wt, bool undir=true) {
        this->l[i].push_back({j, wt});
        if (undir) this->l[j].push_back({i, wt});
    }

    void print() {
        for (int i = 0; i < this->V; i++) {
            cout << i << " : ";
            for (auto nodePair: this->l[i]) {
                cout << "(" << nodePair.first << ", " << nodePair.second << ")   "; 
            }
            cout << endl;
        }
    }
};

int main(void) {
    Graph g(3);

    g.addEdge(0,1,10);
    g.addEdge(1,2,11);
    g.addEdge(2,0,12);

    g.print();

    return 0;
}