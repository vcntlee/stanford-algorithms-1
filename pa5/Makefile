short: dijkstra_algo.o Heap.o
	g++ dijkstra_algo.o Heap.o -o short

dijkstra_algo.o: dijkstra_algo.cpp Heap.cpp
	g++ -c dijkstra_algo.cpp Heap.cpp

Heap.o: Heap.cpp
	g++ -c Heap.cpp

clean:
	rm short a.* *.out *.o
