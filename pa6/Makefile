mid: medianMaintanance.o MinHeap.o MaxHeap.o
	g++ medianMaintanance.o MinHeap.o MaxHeap.o -o mid
mid.o: medianMaintanance.cpp MinHeap.cpp MaxHeap.cpp
	g++ -c medianMaintance.cpp MinHeap.cpp MaxHeap.cpp

main: main.o MinHeap.o MaxHeap.o
	g++ main.o MinHeap.o MaxHeap.o -o main
main.o: main.cpp MinHeap.cpp MaxHeap.cpp
	g++ -c main.cpp MinHeap.cpp MaxHeap.cpp
MinHeap.o: MinHeap.cpp
	g++ -c MinHeap.cpp
Maxheap.o: MaxHeap.cpp
	g++ -c MaxHeap.cpp

two: twoSum.o
	g++ twoSum.o -o two
twoSum.o: twoSum.cpp
	g++ -c twoSum.cpp

clean:
	rm -rf *.out *.o two *.dSYM main
