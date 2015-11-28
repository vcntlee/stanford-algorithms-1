#include "MinHeap.h"
#include <iostream>
using namespace std;

MinHeap::MinHeap(int inMaxSize){
    maxSize = inMaxSize*2;
    tracker = 0;
    curSize = -1;
    minContainer = new int [maxSize];
    for (int i = 0; i < maxSize; i++)
        minContainer[i] = -1;
}

void MinHeap::swapNode(int a, int b){
    int temp = minContainer[a];
    minContainer[a] = minContainer[b];
    minContainer[b] = temp;
}

void MinHeap::insertNode(int node){
    if (tracker == 0){
        minContainer[0] = node;
        tracker++;
        curSize++;
    }
    else{
        minContainer[tracker] = node;
        insertNodeHelper(tracker);
        tracker++;
        curSize++;
    }
}

void MinHeap::insertNodeHelper(int pos){
    if (pos == 0){
        return;
    }
    else{
        if (pos % 2 == 0){
            if (minContainer[pos] < minContainer[pos/2-1]){
                swapNode(pos, pos/2-1);
                insertNodeHelper(pos/2-1);
            }
        }
        else{
            if (minContainer[pos] < minContainer[pos/2]){
                swapNode(pos, pos/2);
                insertNodeHelper(pos/2);
            }
        }
    }
}

int MinHeap::extractMin(){
    int minimum = minContainer[0];
    swapNode(0, curSize);
    minContainer[curSize] = -1;
    curSize--;
    tracker--;

    extractMinHelper(0);
    return minimum;
}

void MinHeap::extractMinHelper(int pos){
    if (minContainer[pos*2+1] == -1 && minContainer[pos*2+2] == -1){
        return;
    }
    else if (minContainer[pos*2+1] != -1 && minContainer[pos*2+2] == -1){
        if (minContainer[pos] > minContainer[pos*2+1]){
            swapNode(pos, pos*2+1);
            return;
        }
    }
    else{
        if (minContainer[pos] > minContainer[pos*2+1] || minContainer[pos] > minContainer[pos*2+2]){
            if (minContainer[pos*2+1] < minContainer[pos*2+2]){
                swapNode(pos, pos*2+1);
                extractMinHelper(pos*2+1);
            }
            else{
                swapNode(pos, pos*2+2);
                extractMinHelper(pos*2+2);
            }
        }
    }
}

void MinHeap::printMinHeap(){
    for (int i = 0; i < maxSize; i++)
        cout << minContainer[i] << " ";
    cout << endl;
}
