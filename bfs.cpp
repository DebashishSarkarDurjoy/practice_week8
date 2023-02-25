#include <iostream>
#include <list>
#include <queue>

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

    void bfs(int start) {
        queue<int> q;
        bool *visited = new bool[this->V]{false};
        
        q.push(start);
        visited[start] = true;
        while (!q.empty()) {
            int front = q.front();
            cout << front << ", ";
            q.pop();

            for (int nbr: this->l[front]) {
                if (!visited[nbr]) {
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }
        
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

};

int main(void) {
    Graph g(7);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(5,6);
    g.addEdge(4,5);
    g.addEdge(0,4);
    g.addEdge(3,4);

    g.print();

    g.bfs(1);

    return 0;
}