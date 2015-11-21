nh: dijkstra_no_heap.o
	g++ dijkstra_no_heap.o -o nh

dijkstra_no_heap.o: dijkstra_no_heap.cpp
	g++ -c dijkstra_no_heap.cpp

short: dijkstra_algo.o Heap.o
	g++ dijkstra_algo.o Heap.o -o short

dijkstra_algo.o: dijkstra_algo.cpp Heap.cpp
	g++ -c dijkstra_algo.cpp Heap.cpp

main: main.o Heap.o
	g++ main.o Heap.o -o main

main.o: main.cpp Heap.cpp
	g++ -c main.cpp Heap.cpp

Heap.o: Heap.cpp
	g++ -c Heap.cpp

clean:
	rm short a.* *.out *.o main nh
