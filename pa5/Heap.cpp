#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>
#include "Heap.h"
using namespace std;

Heap::Heap(int inSize, int inCurSize){
    size = inSize;
    iter = size -1;
    curSize = inCurSize;
    container = new Node[size];

    int maxVal = numeric_limits<int>::max();
    for (int i = 0; i < size; i++){
        container[i].dist = maxVal;
        container[i].v = maxVal;
    }
}

Heap::~Heap(){
    delete[] container;
}

void Heap::initHeap(int inSize, int inSourceV){
    size = inSize;
    container = new Node[size];
    curSize = 0;
    Node node;
    node.dist = 0;
    sourceV = inSourceV;
    node.v = sourceV;
    
    insertKey(node);

    int maxVal = numeric_limits<int>::max();
    for (int i = 1; i < size; i++){
        container[i].dist = maxVal;
        container[i].v = maxVal;
    }
}

        
int Heap::extractMin(){
    Node minimum = container[0];
    cout << "iter " << iter <<endl;
    swap(container[0], container[iter]);
    container[iter].dist = numeric_limits<int>::max(); 
    cout << "c[iter] " << container[iter].dist << endl;

    extractMinHelper(0);

    iter--;

    return minimum.dist;
}

void Heap::extractMinHelper(int i){
    if (i == curSize-1) return;
    
    else if (container[i] > container[2*i+1] || container[i] > container[2*i+2]){
        if (container[2*i+1] < container[2*i+2]){
            swap(container[i], container[2*i+1]);
            extractMinHelper(2*i+1);
        }
        else{
            swap(container[i], container[2*i+2]);
            extractMinHelper(2*i+2);
        }

    }

}

void Heap::swapNode(int l, int r){
    Node temp = container[l];
    container[l] = container[r];
    container[r] = temp;
}       


void Heap::insertKey(Node node){
    if (curSize == 0){
        container[0] = node;
    }

    else{
        container[curSize] = node;
        insertKeyHelper(curSize);
    }

    curSize++;
    iter = curSize-1;

}        

void Heap::insertKeyHelper(int i){

    if (i==0){
        return;
    }

    else if (i % 2){
        if (container[i] < container[i/2]){
            swapNode(i, i/2); 
            insertKeyHelper(i/2);
        }
    }
    else{
        if (container[i] < container[i/2-1]){
            swapNode(i, i/2-1);
            insertKeyHelper(i/2-1);
        }
    }
}

void Heap::print(){
    for (int i = 0; i < size; i++)
        cout << (container[i].dist) << " ";        
    cout <<endl;
}
