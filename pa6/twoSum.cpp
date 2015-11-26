#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

long long * readFile(string fname, long long *container){
    ifstream infile;
    infile.open(fname.c_str());

    if (infile){
        string line = "";
        int i = 0;
        while (getline(infile, line)){
            istringstream iss(line);
            long long element; 
            iss >> element;
            container[i] = element;
            i++;
        }
    }
    infile.close();
    return container;
}

void swapped(long long *container, int left, int right){
    long long temp = container[left]; 
    container[left] = container[right]; 
    container[right] = temp;
}

int pivoted(long long *container, int left, int right){
    int j = left; 
    for (int i = left; i < right; i++){
        if (container[j] > container[i]){
            swapped(container, j, i);
            j++;
        }
    }
    swapped(container, right, j);
    return j;
}

long long * quickSort(long long *container, int left, int right){
    if (left == right){
        return container;
    }
    else{
        int pivot = pivoted(container, left, right); 
        quickSort(container, left, pivot-1);
        quickSort(container, pivot+1, right);
        return container;
    }
}

int main(){
    string fname = "100.txt";
    int size = 100;
    //long long *container = new long long [1000000];
    long long *container = new long long [size];

    container = readFile(fname, container); 
    container = quickSort(container, 0, size-1);

    for (int i = 0; i < size; i++){
        cout << container[i] << endl;
    }
    return 0;
}
