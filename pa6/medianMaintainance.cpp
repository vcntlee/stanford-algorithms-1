#include "MinHeap.h"
#include "MaxHeap.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

int * readFile(string fname, int *inputContainer){
    ifstream infile;
    infile.open(fname.c_str());

    if (infile){
        string line = "";
        int node = 0;
        int i = 0;
        while (getline(infile, line)){
            istringstream iss(line); 
            iss >> node;
            inputContainer[i] = node;
            i++;
        }
    }
    infile.close();
    return inputContainer;
}


void calcMedian(int inputSize, int *inputContainer){
    int midpoint = inputSize / 2; 
    MaxHeap hLow(midpoint);
    MinHeap hHigh(midpoint);

    for (int i = 0; i < inputSize; i++){
        if (inputContainer[i] <= midpoint ){
            hLow.insertNode(inputContainer[i]); 

            //rebalance

            if (hLow.getSize() - hHigh.getSize() == 2){
                hHigh.insertNode(hLow.extractMax());
            }
        }
        else{
            hHigh.insertNode(inputContainer[i]); 

            //rebalance

            if (hHigh.getSize() - hLow.getSize() == 2){
                hLow.insertNode(hHigh.extractMin());
            }
        }
        
        //find the median
        if ((hLow.getSize() + hHigh.getSize()) % 2 == 0){
            cout << inputContainer[i] << " -> " << (hLow.getMax() + hHigh.getMin()) / 2 << endl;
        }
        else{
            int median = 0;
            if (hLow.getSize() > hHigh.getSize()){
                median = hLow.getMax();
            }
            else{
                median = hHigh.getMin();
            } 
            cout<< inputContainer[i] << " -> " << median << endl;

        }
    }
}

void printContainer(int inputSize, int *inputContainer){
    for (int i = 0; i < inputSize; i++){
        cout << inputContainer[i] << " ";
    }
    cout << endl;
}

int main(){
    int size = 12;
    string fname = "pa6_test_q2.txt";
    int *inputContainer = new int[size];

    inputContainer = readFile(fname, inputContainer); 
    calcMedian(size, inputContainer);


}
