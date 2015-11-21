#include "Heap.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <list>

using namespace std;


class DijkstraSolution{
    private:
        
        int size;
        int sourceV;
        Heap h; 
        list<Node> *container; 
        int *results;

    public:
        DijkstraSolution(string fname, int inSourceV, int inSize): size(inSize), sourceV(inSourceV), h(size, sourceV){
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
            infile.close();
            int maxVal = numeric_limits<int>::max();
            int *results = new int[size];
            for (int i = 1; i < size; i++){
                results[i] = maxVal;
            }
            results[sourceV] = 0;
        }
        ~DijkstraSolution(){
            delete[] container;
            delete[] results;
        }

        int * dijkstra(){
            while (h.getCurSize() != 0){
                Node minimum = h.extractMin(); 
                if (minimum.dist < results[minimum.v]){
                    results[minimum.v] = minimum.dist;
                }
                for (list<Node>::iterator it = container[minimum.v].begin(); it != container[minimum.v].end(); it++){
                    Node inserted;
                    inserted.v = (*it).v;
                    inserted.dist = minimum.dist + (*it).dist;
                    h.insertKey(inserted);
                    if (minimum.dist + (*it).dist < results[(*it).v]){
                        results[(*it).v] = results[minimum.v] + (*it).dist; 
                    }
                }
            }
            return results;
        }


        void printContainer(){
            for (int i=1; i < size; i++){
                cout << i << " ";
                list<Node>::iterator iter;
                for (iter = container[i].begin(); iter != container[i].end(); iter++){
                    cout << iter -> v << " " << iter -> dist << " ";
                }
                cout <<endl;
            }
        }
        void printResults(){
            for (int i = 1; i < size; i++){
                cout << i << " -> " << results[i] << endl;
            }
        }
};

int main(){
    DijkstraSolution ds("pa5_test1.txt", 1, 8);

    ds.dijkstra(); 
    ds.printResults();

}


