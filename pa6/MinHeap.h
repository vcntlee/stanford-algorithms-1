#ifndef _MINHEAP_H_
#define _MINHEAP_H_

class MinHeap{
    private:
        int *minContainer;
        int maxSize;
        int tracker;
        int curSize;

    public:
        MinHeap(int inMaxSize);
        void insertNode(int node);
        void insertNodeHelper(int pos);
        int extractMin();
        void extractMinHelper(int pos);
        void swapNode(int a, int b);
        void printMinHeap();
        int getSize(); 
        int getMin();


};
#endif
