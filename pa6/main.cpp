#include "maxheap.h"
#include "MaxHeap.h"
#include <iostream>

using namespace std;

int main(){
    MaxHeap maxheap(10);
    maxheap.insertNode(8);
    maxheap.insertNode(3);
    maxheap.insertNode(10);
    maxheap.insertNode(4);
    maxheap.insertNode(20);
    maxheap.insertNode(7);
    maxheap.insertNode(15);
    maxheap.insertNode(9);
    maxheap.insertNode(19);
    maxheap.insertNode(1);

    maxheap.printMaxHeap();

    for (int i = 0; i < 10; i++){
        int maximum = maxheap.extractMax();
        cout << "max " << maximum << endl;
        cout << "size " << maxheap.getSize() << endl;
        maxheap.printMaxHeap();
    }


}
