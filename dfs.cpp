#include <iostream>
#include <list>

using namespace std;

class Graph {
private:
    int V;
    list<int> *l;

public:
    Graph(int v) {
        this->V = v;
        this->l = new list<int>[this->V];
    }

    void addEdge(int i, int j, bool undir = true) {
        this->l[i].push_back(j);
        if (undir) this->l[j].push_back(i);
    }

    void print() {
        for (int i = 0; i < this->V; i++) {
            cout << i << " : ";
            for (int node: this->l[i]) {
                cout << node << ", ";
            }
            cout << endl;
        }
    }

    void dfs(int node, bool *visited) {
        visited[node] = true;
        cout << node << ", ";

        for (int nbr: this->l[node]) {
            if (!visited[nbr]) dfs(nbr, visited);
        }
    }

    void dfsHelper(int i) {
        bool *visited = new bool[this->V]{false};
        dfs(i, visited);
    }
};

int main(void) {
    Graph g(6);

    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(2,1);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(2,3);
    g.addEdge(3,5);

    g.print();

    g.dfsHelper(0);

    return 0;
}