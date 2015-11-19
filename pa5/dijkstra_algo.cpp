#include "Heap.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <list>

using namespace std;

const int SIZE = 201;

class Graph{
    private:
        
        int size;
        list<Node> *container; 

    public:
        Graph(string fname){
            size = SIZE;
            container = new list<Node>[size];

            ifstream infile;
            infile.open(fname.c_str());
            string line = "";

            if (infile){
                while (getline(infile, line)){
                    istringstream iss(line);
                    int vertex;
                    int v;
                    int dist;
                    iss >> vertex;
                    while(iss >> v >> dist){
                        Node edges;
                        edges.dist = dist;
                        edges.v = v;
                        container[vertex].push_back(edges);
                    }
                }
            }
        }

        void print(){
            for (int i=1; i < size; i++){
                cout << i << " ";
                list<Node>::iterator iter;
                for (iter = container[i].begin(); iter != container[i].end(); iter++){
                    cout << iter -> v << " " << iter -> dist << " ";
                }
                cout <<endl;
            }
        }
};

int main(){
    //Graph g("pa5_input.txt");
    //g.print();
    Heap h(5, 0);

    Node node1, node2, node3, node4, node5;
    node1.dist = 500; node1.v = 1;
    node2.dist = 300; node2.v = 2;
    node3.dist = 700; node3.v = 3;
    node4.dist = 280; node4.v = 4;
    node5.dist = 400; node5.v = 5;

    h.insertKey(node1);
    h.insertKey(node2);
    h.insertKey(node3);
    h.insertKey(node4);
    h.insertKey(node5);
    h.print();

    int minimum = h.extractMin();

    cout << "minimum is: " << minimum << endl;

    h.print();

}


