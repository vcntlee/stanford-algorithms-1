#ifndef _HEAP_H_
#define _HEAP_H_

#include <iostream>
#include <vector>
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
    bool operator+(const Node& a){
        return a.dist+dist;
    }

};

class Heap{
    private:

        Node *container;
        int size;
        int curSize;
        int sourceV;
        int iter;
        
    public:

        Heap(int inSize, int sourceV);
        ~Heap();
        void initHeap(int inSize, int inSourceV);
        int getCurSize();
        Node extractMin();
        void extractMinHelper(int i);
        void swapNode(int l, int r);
        void insertKey(Node node);
        void insertKeyHelper(int i);
        Node *getContainer();

        void print();

};
        
#endif
