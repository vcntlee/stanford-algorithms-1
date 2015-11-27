mid: medianMaintanance.o minHeap.o maxHeap.o
	g++ medianMaintanance.o minHeap.o maxHeap.o -o mid
mid.o: medianMaintanance.cpp minHeap.cpp maxHeap.cpp
	g++ -c medianMaintance.cpp minHeap.cpp maxHeap.cpp -o mid.o

main: main.o minHeap.o maxHeap.o
	g++ main.o minHeap.o maxHeap.o -o main
main.o: main.cpp minHeap.cpp maxHeap.cpp
	g++ -c main.cpp minHeap.cpp maxHeap.cpp -o main.o
minHeap.o: minHeap.cpp
	g++ -c minHeap.cpp -o minHeap.o
maxheap.o: maxHeap.cpp
	g++ -c maxHeap.cpp -o maxHeap.o

two: twoSum.o
	g++ twoSum.o -o two
twoSum.o: twoSum.cpp
	g++ -c twoSum.cpp -o twoSum.o

clean:
	rm -rf *.out *.o two *.dSYM 

