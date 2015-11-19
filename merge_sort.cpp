#include <iostream> 
#include <vector>
#include <cmath>
using namespace std; 

struct number{

    int elt;
    int idx;

};

vector<number> conquer(vector<number> first, vector<number> second);

vector<number> divide(vector<number> ptr){
    if (ptr.size() == 1){
        return ptr; 
    }
    else{
        int mid = ptr.size() / 2;
        vector<number> a; 
        vector<number> b; 
        
        for (int i = 0; i < mid; i++){
            a.push_back(ptr.at(i)); 
        }
                
        vector<number> first = divide(a);
        
        for (int i = mid; i < ptr.size(); i++){
            b.push_back(ptr.at(i));
        }
        
        vector<number> second = divide(b);
        return conquer(first, second); 
    }
}

vector<number> conquer(vector<number> first, vector<number> second){
    int f = 0; 
    int s = 0;
    vector<number> conquer; 
    while (f < first.size() && s < second.size()){
        if (first.at(f).elt < second.at(s).elt){
            conquer.push_back(first.at(f));  
            ++f; 
        }
        else{
            conquer.push_back(second.at(s));
            ++s; 
        }
    }
    while(f < first.size()){
        conquer.push_back(first.at(f));
        ++f;
    }
    while(s < second.size()){
        conquer.push_back(second.at(s));
        ++s;
    }
    
    return conquer;
}

int binary_search(vector<number> sorted, int input){
    int lower = 0;
    int upper = sorted.size() - 1; 
    while (lower <= upper){
        int mid = (upper + lower) / 2; 
        if (input > sorted[mid].elt){
            lower = mid +1; 
        }
        else if (input < sorted[mid].elt){
            upper = mid -1; 
        }
        else{
            return sorted[mid]; 
        }
    }
    return -1789;
}

int* process_answer(vector<number> result, int target){
    if (index == -1789){
        int *answers = new int[2];   
        for (int i=result.size()-1; i > 0; --i){
            if (result[i].elt + result[i-1].elt == target){
                answers[0] = result[i].idx;
                answers[1] = result[i-1].idx;
                return answers;
            }
        }
    }
    else{
        int idx = binary_seach(result, target); 
        if (target <= result.at(idx).elt){
            for (int i = 0, j = result.end(); i > j; ++i, --j){
                if (i = j){
                    if (result[i].elt + result[i-1] == target){
                        answers[0] = result[i].idx;
                        answers[1] = result[i-1].idx;
                        return answers;
                    }
                }
                else{
                    if (result[i].elt + result[j].elt == target){
                        answers[0] = result[i].idx;
                        answers[1] = result[j].idx;
                        return answers;
                    }
                }

            }
        }
    }
}

int main(){

    vector<number> ptr;
     
    int myArray[] = {3, 6, 7, 9, 1, 2, 5, 4}; 
    int len = sizeof(myArray)/sizeof(int); 
    
    for (int i = 0; i < len; i++){
        number element; 
        element.elt = abs(myArray[i]); 
        element.idx = i+1; 
        ptr.push_back(element);
    }

    vector<number> result; 
    result = divide(ptr); 
    for (int i = 0; i < result.size(); i++){
        cout  << result.at(i).elt << "[" << result.at(i).idx << "]" << " ";
    }
    cout << endl;
    int target = 12;
    int *answers = process_answer(result, abs(target)); 
    

    return 0;
}


