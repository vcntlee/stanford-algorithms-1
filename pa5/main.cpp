#include "Heap.h"
#include <iostream>

int main(){
    Heap h(5, 0);

    Node node1, node2, node3, node4, node5;
    node1.dist = 500; node1.v = 1;
    node2.dist = 300; node2.v = 2;
    node3.dist = 700; node3.v = 3;
    node4.dist = 280; node4.v = 4;
    node5.dist = 400; node5.v = 5;

    h.insertKey(node1);
    h.insertKey(node2);
    h.insertKey(node3);
    h.insertKey(node4);
    h.insertKey(node5);
    h.print();

    Node *c = h.getContainer();   

    for (int i = 0; i < 5; i++){
        cout << c[i].dist << " " << endl;
    }

}

