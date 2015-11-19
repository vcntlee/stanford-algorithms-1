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

};

class Heap{
    private:

        Node *container;
        int size;
        int curSize;
        int sourceV;
        

    public:

        Heap(int inSize, int curSize);
        void initHeap(int inSize, int inSourceV);

        Node extractMin();
        void extractMinHelper(int i);

        void swapNode(int l, int r);
        void insertKey(Node node);
        void insertKeyHelper(int i);

        void print();

};
        
#endif
