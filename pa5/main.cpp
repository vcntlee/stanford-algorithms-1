#include "Heap.h"
#include <iostream>

int main(){
    Heap h(9, 1);

    Node node1, node2, node3, node4, node5, node6, node7, node8;

    //first round
    

    //second round

    //third round
    


    //************************first round
    node2.dist = 20; node1.v = 2;
    node4.dist = 80; node2.v = 4;
    node7.dist = 90; node7.v = 7;
    h.insertKey(node2);
    h.insertKey(node4);
    h.insertKey(node7);
    cout << "first before extraction:...\n";
    h.print(); cout << endl;

    h.extractMin();
    cout << "first after extraction:...\n";
    h.print(); cout << endl;


    //**************************second round
    node6.dist = 30; node6.v = 6;
    h.insertKey(node6);
    cout << "second before extraction:...\n";
    h.print(); cout << endl;

    h.extractMin();
    cout << "second after extraction:...\n";
    h.print(); cout << endl;


    //***************************third round
    node3.dist = 40; node3.v = 3;
    node4.dist = 70; node4.v = 4;
    h.insertKey(node3); 
    h.insertKey(node4);
    cout << "third before extraction:...\n";
    h.print(); cout << endl;

    h.extractMin();
    cout << "third after extraction:...\n";
    h.print(); cout << endl;



}

