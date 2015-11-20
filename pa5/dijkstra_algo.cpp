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
        ~Graph(){
            delete[] container;
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


}


