#include <iostream>
#include <sstream>
#include <fstream>
#include <list>
#include <limits>

using namespace std;

struct Node{
    int dist;
    int v;

    bool operator==(const Node& a){
        return dist == a.dist;
    }

    bool operator!=(const Node& a){
        return (!(dist  == a.dist));
    }

    bool operator<(const Node& a){
        return dist < a.dist;
    }
    bool operator>(const Node& a){
        return a.dist < dist;
    }
    int operator+(const Node& a){
        return a.dist+dist;
    }
};


struct cheapHeap{
    int curSize;
    Node * minHeap;
};

class DijkstraSolution{

    private:
        int size;
        int sourceV;
        list<Node> *container; 
        int *results;
        cheapHeap ch; 
        

    public:
        DijkstraSolution(string fname, int inSourceV, int inSize): size(inSize), sourceV(inSourceV){
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
            results = new int[size];

            ch.curSize = size-1; 
            ch.minHeap = new Node[size];

            for (int i = 0; i < size; i++){
                results[i] = maxVal;
                ch.minHeap[i].dist = maxVal;
            }
            results[sourceV] = 0;
            ch.minHeap[sourceV].dist = 0;
            ch.minHeap[sourceV].v = sourceV;
            
        }
        

        Node findMin(){
            Node minimum;
            minimum.dist = numeric_limits<int>::max();
            minimum.v = 0;
            
            for (int i=1; i <= size; i++){
                if ((ch.minHeap[i] < minimum) && (ch.minHeap[i].dist != -1)){
                    minimum = ch.minHeap[i];
                    ch.minHeap[i].dist = -1;
                    ch.minHeap[i].v = i;
                }
            }
            ch.curSize--;
            return minimum;
        }



        int * dijkstra(){
            while (ch.curSize != 0){
                Node minimum = findMin(); 
                results[minimum.v] = minimum.dist; 

                for (list<Node>::iterator it = container[minimum.v].begin(); it != container[minimum.v].end(); it++){
                    if ((*it)+minimum < ch.minHeap[(*it).v].dist){
                        Node inserted;
                        inserted.dist = *it + minimum;
                        inserted.v = (*it).v;
                        ch.minHeap[(*it).v] = inserted;
                        
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
    DijkstraSolution ds("pa5_test2.txt", 1, 9);

    ds.dijkstra(); 
    ds.printResults();

}


