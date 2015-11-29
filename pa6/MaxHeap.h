#ifndef _MAXHEAP_H_
#define _MAXHEAP_H_

class MaxHeap{
    private:
        int *maxContainer;
        int maxSize;
        int tracker;
        int curSize;

    public:
        MaxHeap(int inMaxSize);
        void insertNode(int node);
        void insertNodeHelper(int pos);
        int extractMax();
        void extractMaxHelper(int pos);
        void swapNode(int a, int b);
        void printMaxHeap();
        int getSize();
        int getMax();

};

#endif

