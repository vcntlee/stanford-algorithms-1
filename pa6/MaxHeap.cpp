#include "MaxHeap.h"
#include <iostream>
using namespace std;

MaxHeap::MaxHeap(int inMaxSize){
    maxSize = inMaxSize *2;  
    tracker = 0;
    curSize = -1;
    maxContainer = new int [maxSize]; 
    for (int i = 0; i < maxSize; i++)
        maxContainer[i] = -1;
}

void MaxHeap::swapNode(int a, int b){
    int temp = maxContainer[a]; 
    maxContainer[a] = maxContainer[b];
    maxContainer[b] = temp;
}

void MaxHeap::insertNode(int node){
    if (tracker == 0){
        maxContainer[0] = node;
        tracker++;
        curSize++; 
    }
    else{
        maxContainer[tracker] = node; 
        insertNodeHelper(tracker);
        tracker++;
        curSize++;
    }
}

void MaxHeap::insertNodeHelper(int pos){
    if (pos == 0){
        return; 
    }
    else{
        if (pos % 2 == 0){
            if (maxContainer[pos] > maxContainer[pos/2-1]){
                swapNode(pos, pos/2-1);
                insertNodeHelper(pos/2-1);
            }
        }
        else{
            if (maxContainer[pos] > maxContainer[pos/2]){
                swapNode(pos, pos/2);
                insertNodeHelper(pos/2);
            }
        }
    }
}

int MaxHeap::extractMax(){
    int maximum = maxContainer[0]; 
    swapNode(0, curSize);
    maxContainer[curSize] = -1;
    curSize--;
    tracker--;

    extractMaxHelper(0);
    return maximum;
}

void MaxHeap::extractMaxHelper(int pos){
    if (maxContainer[pos*2+1] == -1 && maxContainer[pos*2+2] == -1){
        return;
    }
    else if (maxContainer[pos*2+1] != -1 && maxContainer[pos*2+2] == -1){
        if (maxContainer[pos] < maxContainer[pos*2+1]){
            swapNode(pos, pos*2+1);
            return;
        }
    }
    else{
        if (maxContainer[pos] < maxContainer[pos*2+1] || maxContainer[pos] < maxContainer[pos*2+2]){
            if (maxContainer[pos*2+1] > maxContainer[pos*2+2]){
                swapNode(pos, pos*2+1);
                extractMaxHelper(pos*2+1);
            }
            else{
                swapNode(pos, pos*2+2);
                extractMaxHelper(pos*2+2);
            }
        }
    }
}

void MaxHeap::printMaxHeap(){
    for (int i = 0; i < maxSize; i++)
        cout << maxContainer[i] << " ";
    cout << endl;
}
