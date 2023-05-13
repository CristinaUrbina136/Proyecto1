#ifndef HEAPPRIORITYQUEUE_H
#define HEAPPRIORITYQUEUE_H

#include <stdexcept>
#include <iostream>
#include "MinHeap.h"
#include "KVPair.h"
#include "PriorityQueue.h"

using std::runtime_error;

template <typename E>
class HeapPriorityQueue : public PriorityQueue<E> {
private:
    MinHeap<KVPair<int, E>> *heap;

public:
    HeapPriorityQueue(int max = DEFAULT_MAX_SIZE) {
        heap = new MinHeap<KVPair<int, E>>(max);
    }
    ~HeapPriorityQueue() {
        delete heap;
    }
    void insert(E element, int priority) {
        KVPair<int, E> p(priority, element);
        heap->insert(p);
    }
    E min() {
        KVPair<int, E> p = heap->first();
        return p.value;
    }
    E removeMin() {
        KVPair<int, E> p = heap->removeFirst();
        return p.value;
    }
    void clear() {
        heap->clear();
    }
    int getSize() {
        return heap->getSize();
    }
    bool isEmpty() {
        return heap->isEmpty();
    }
    void print() {
        heap->print();
    }
    void printP() {
        heap->printP();
    }
};

#endif // HEAPPRIORITYQUEUE_H
