#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <time.h>

using namespace std;

long long int * readFile(string fname, long long int *container){
    ifstream infile;
    infile.open(fname.c_str());

    if (infile){
        string line = "";
        int i = 0;
        while (getline(infile, line)){
            istringstream iss(line);
            long long int element; 
            iss >> element;
            container[i] = element;
            i++;
        }
    }
    infile.close();
    return container;
}

void swapped(long long int *container, int left, int right){
    long long int temp = container[left]; 
    container[left] = container[right]; 
    container[right] = temp;
}

int pivoted(long long int *container, int left, int right){
    int j = left; 
    for (int i = left; i < right; i++){
        if (container[i] <= container[right]){
            swapped(container, j, i);
            j++;
        }
    }
    swapped(container, right, j);
    return j;
}

long long int * quickSort(long long int *container, int left, int right){
    if (left >= right){
        return container;
    }
    else{
        int pivot = pivoted(container, left, right); 
        quickSort(container, left, pivot-1);
        quickSort(container, pivot+1, right);
        return container;
    }
}

bool binarySearch(long long int *container, long long int suspect, int left, int right){
    int mid = (left + right) / 2; 
    if (container[mid] == suspect)
        return true;
    else if (left >= right){
        return false;
    }
    else if (container[mid] < suspect){
        return binarySearch(container, suspect, mid+1, right);
    }
    else{
        return binarySearch(container, suspect, left, mid-1);
    }

}

int countTargets(long long int *container, int lowerRange, int upperRange, int containerSize){
    int counter = 0;
    for (int j=lowerRange; j <= upperRange; j++){
        for (int i = 0; i < containerSize; i++){
            int result = j - container[i]; 
            if (result > container[i]){
                if (binarySearch(container, result, i+1, containerSize-1)){
                    counter++;
                    break;
                }
            }
            else if (result < container[i]){
                if (binarySearch(container, result, 0, i-1)){
                    counter++;
                    break;
                }
            }
        }
        cout << "Round " << j << " done." << endl;
    }
    return counter;
}


int main(){
    clock_t t1, t2;
    t1 = clock();
    string fname = "pa6_input.txt";
    int size = 1000000;
    long long int *container = new long long int [size];

    container = readFile(fname, container); 
    container = quickSort(container, 0, size-1);

    int answer = countTargets(container, -10000, 10000, size);

    t2 = clock();
    double diff ((float)t2 - (float)t1);
    double sec = diff/CLOCKS_PER_SEC;
    double minute = sec / 60; 

    cout << "answer: " << answer << endl;
    cout << "time taken: " << minute << endl;

    return 0;
}
