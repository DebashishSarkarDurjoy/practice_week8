#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

class Node {
public:
    string name;
    list<string> nbrs;

    Node(string name) {
        this->name = name;
    }
};

class Graph {
private:
    unordered_map<string, Node*> map;

public:
    Graph(vector<string> cityVector) {
        for (string name: cityVector) {
            this->map[name] = new Node(name);
        }
    }

    void addEdge(string city1, string city2, bool undir=false) {
        this->map[city1]->nbrs.push_back(city2);
        if (undir) this->map[city2]->nbrs.push_back(city1);
    }

    void print() {
        for (auto pair: this->map) {
            cout << pair.first << " : ";
            for(string city: pair.second->nbrs) {
                cout << city << ", ";
            }
            cout << endl;
        }
    }

    void showCities() {
        for (auto pair: this->map) {
            cout << pair.first << ", ";
        }
        cout << endl;
    }

};

int main(void) {
    vector<string> cityNames = {"Delhi", "London", "Paris", "New York"};

    Graph g(cityNames);

    g.showCities();

    g.addEdge("Delhi", "London");
    g.addEdge("New York", "London");
    g.addEdge("Delhi", "Paris");
    g.addEdge("Paris", "New York");

    g.print();

    return 0;
}