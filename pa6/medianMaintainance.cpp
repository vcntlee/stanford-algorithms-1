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


int calcMedian(int inputSize, int *inputContainer){
    int midpoint = inputSize / 2; 
    MaxHeap hLow(midpoint);
    MinHeap hHigh(midpoint);

    int total = 0;
    for (int i = 0; i < inputSize; i++){
        if (inputContainer[i] < hLow.getMax()){
            hLow.insertNode(inputContainer[i]); 

            //rebalance

            if (hLow.getSize() - hHigh.getSize() == 2){
                hHigh.insertNode(hLow.extractMax());
            }
        }
        else if (inputContainer[i] > hHigh.getMin() ){
            hHigh.insertNode(inputContainer[i]); 

            //rebalance

            if (hHigh.getSize() - hLow.getSize() == 2){
                hLow.insertNode(hHigh.extractMin());
            }
        }
        else{
            hLow.insertNode(inputContainer[i]); 

            //rebalance

            if (hLow.getSize() - hHigh.getSize() == 2){
                hHigh.insertNode(hLow.extractMax());
            }
        }

        
        //find the median
        if ((hLow.getSize() + hHigh.getSize()) % 2 == 0){
            //cout << inputContainer[i] << ": " << hLow.getMax() << endl;
            total += hLow.getMax();
        }
        else{
            if (hLow.getSize() > hHigh.getSize()){
                
                //cout << inputContainer[i] << ": " << hLow.getMax() << endl;
                total += hLow.getMax();
            }
            else{
                
                //cout << inputContainer[i] << ": " << hHigh.getMin() << endl;
                total += hHigh.getMin();
            } 

        }
    }
    return total;
}

void printContainer(int inputSize, int *inputContainer){
    for (int i = 0; i < inputSize; i++){
        cout << inputContainer[i] << " ";
    }
    cout << endl;
}

int main(){
    int size = 10000;
    string fname = "pa6_input2.txt";
    int *inputContainer = new int[size];

    inputContainer = readFile(fname, inputContainer); 
    int answer = calcMedian(size, inputContainer);

    cout << "total: " << answer << endl;
    cout << "answer: " << answer % size << endl;

}
