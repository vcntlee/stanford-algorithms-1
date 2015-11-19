#include <algorithm>
#include <iostream>
#include <typeinfo>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <stack>
#define SIZE 13
using namespace std;

class Graph{
    
    private: 
        
        map <int, list<int> > outward;
        map <int, list<int> > reversed;
        bool visited[SIZE];
        vector <int> finished;
        vector <int> scc_counter;
        int counter;


    public:
        Graph(string fname){
            ifstream infile;
            infile.open(fname.c_str());
            string line = "";
            if (infile){
                while (getline(infile, line)){
                    istringstream iss(line);
                    int tail;
                    iss >> tail;
                    int edges;
                    iss >> edges;
                    outward[tail].push_back(edges);;
                    reversed[edges].push_back(tail);
                    }
            }
            infile.close();
            for (int i = 1; i < SIZE; i++) 
                visited[i] = false;
            
        }

        void print(){

            cout << "forward..." <<endl;
            for (map<int, list<int> > :: iterator it = outward.begin(); it != outward.end(); ++it){
                cout << it -> first << " ";
                for (list <int> :: const_iterator j = outward[it->first].begin(); j != outward[it->first].end(); ++j){
                    cout << *j << " ";
                }
                cout << endl;
            }
            
            cout << "reversed..." <<endl;
            
            for (map<int, list<int> >::iterator it = reversed.begin(); it != reversed.end(); ++it){
                cout << it -> first << " " ;
                for (list<int>::const_iterator jt = reversed[it->first].begin(); jt != reversed[it->first].end(); ++jt){
                    cout << *jt << " "; 
                }
                cout <<endl;
            }
            
        }

        void print_visited(){
            for (int i=1; i<SIZE; i++) cout << i << " " << visited[i] << endl;
        }
        void print_first_pass(){
            for (vector<int>::iterator it = finished.begin(); it != finished.end(); it++){
                cout << *it << " ";
            }
            cout << endl;
            
        }

        void first_pass(){
            for (int i = SIZE-1; i > 0; i--){
                if (reversed.find(i) != reversed.end()){
                    if (visited[i] == false){
                        dfs_first(i);
                    }
                }
            }
        }

        void dfs_first(int i){
            visited[i] = true;
            list<int>::const_iterator it;
            if (reversed.find(i) != reversed.end()){
                for (it = reversed[i].begin(); it != reversed[i].end(); ++it){
                    if (!visited[*it]){
                        dfs_first(*it);
                    }
                }
            }
            finished.push_back(i);
        }

        void second_pass(){
            for (int i = 1; i < SIZE; i++)
                visited[i] = false;
            
            vector<int>::iterator it;
            for (it = finished.end()-1; it >= finished.begin(); it--){
                counter = 1;
                if (visited[*it] == false){
                    dfs_second(*it);
                    scc_counter.push_back(counter);

                    
                }

            }
        }

        void dfs_second(int i){
            visited[i] = true;
            list<int> ::const_iterator it;
            for (it = outward[i].begin(); it != outward[i].end(); it++){
                if (!visited[*it]){
                    counter++;
                    dfs_second(*it);
                }
            }
        }

        void get_scc(){
            sort(scc_counter.begin(), scc_counter.end());
            vector<int>::iterator i;
            for (i = scc_counter.begin(); i != scc_counter.end(); i++){
                cout << *i << " " ;
            }
        }
            

        
};

int main(){
    string fname = "pa4_simple.txt";
    Graph g(fname);
    //g.print();
    //g.print_visited();
    g.first_pass();
    g.print_first_pass();
    g.second_pass();
    g.get_scc();
}
