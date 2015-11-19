#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

const int SIZE = 200;
class Graph{

    private:
        int numNodes;
        vector<int> vertices[SIZE];
        bool exists[SIZE];
        
    public:
        Graph(string fname){
            numNodes = SIZE; 
            ifstream infile; 
            infile.open(fname.c_str());
            string line = "";
            int i = 0;
            if (infile){
                while(getline(infile, line)){
                    istringstream is(line);
                    int vertex;
                    is >> vertex;
                    while (is >> vertex){
                        vertices[i].push_back(vertex);
                    }
                    i++;
                }
            }
            infile.close();
            for (int i = 0; i < SIZE; i++) 
                exists[i] = true;
        }

        void print(){
            for (int i=0; i < SIZE; i++){
                cout << "vertex " << i << ": ";
                for (vector<int>::iterator it = vertices[i].begin(); it != vertices[i].end(); ++it){
                    cout << *it << " ";
                }
                cout <<endl;
            }
        }

        int gen_random(int param){
            int random = rand() % param;
            return random;
        }

        void merge_vertex(int alpha, int beta){
            
            for (vector<int>::iterator it = vertices[beta].begin(); it != vertices[beta].end(); ++it){
                if (*it != alpha+1){
                                
                    vertices[alpha].push_back(*it);
                    if (exists[*it-1]){
                        vertices[*it-1].erase(remove(vertices[*it-1].begin(), vertices[*it-1].end(), beta+1), vertices[*it-1].end());
                        vertices[*it-1].push_back(alpha+1);
                    }
                }
                else{
                    vertices[alpha].erase(remove(vertices[alpha].begin(), vertices[alpha].end(), beta+1), vertices[alpha].end());
                }
            }
            exists[beta] = false;
            --numNodes;
        }

        void rm_edge(){
            int alpha = gen_random(SIZE);
            while(exists[alpha] == false){
                alpha = gen_random(SIZE);
            }
            int beta = gen_random(vertices[alpha].size());
            merge_vertex(alpha, vertices[alpha][beta]-1);
        }
        int driver(){
            while (numNodes > 2){
                rm_edge();
            }
            int i = 0;
            while (exists[i] == false){
                ++i;
            }
            return vertices[i].size();
        }
        
};

int main(){
    
    
    srand ( time(NULL) );
    //srand(12);
    
    int minimum=0;
    for (int i = 0; i < 100; i++){
        Graph g("pa3_input.txt");
        //g.print();
        int answer = g.driver();
        if (minimum == 0 || answer < minimum) 
            minimum = answer;
        cout << "round: " << i << " " << "minimum: " << minimum << endl; 
    }
    cout << "minimum is " << minimum <<endl;
}

