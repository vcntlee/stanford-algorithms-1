#include <iostream>
#include <fstream>
#include <sstream>
#include <set>

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
    //set<int> targets;
    int counter = 0;
    for (int j=lowerRange; j <= upperRange; j++){
        for (int i = 0; i < containerSize; i++){
            int result = j - container[i]; 
            if (result > container[i]){
                if (binarySearch(container, result, i+1, containerSize-1)){
                    //targets.insert(j); 
                    counter++;
                    break;
                }
            }
            else if (result <= container[i]){
                if (binarySearch(container, result, 0, i-1)){
                    //targets.insert(j);
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
    //string fname = "pa6_input.txt";
    //int size = 1000000;
    string fname = "pa6_test_q1.txt";
    int size =20;
    long long int *container = new long long int [size];

    container = readFile(fname, container); 
    container = quickSort(container, 0, size-1);

//    for (int i = 0; i < size; i++){
//        cout << "(" << i << ", " << container[i] << ")" ;
//    }
//    cout << endl;

    int answer = countTargets(container, -10000, 10000, size);

    cout << "answer: " << answer << endl;

    return 0;
}
