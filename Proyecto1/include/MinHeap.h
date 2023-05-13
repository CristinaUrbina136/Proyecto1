#ifndef MINHEAP_H
#define MINHEAP_H

#define DEFAULT_MAX_SIZE 1024

#include <stdexcept>
#include <iostream>

using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
class MinHeap {
private:
    E *elements;
    int max;
    int size;

    void siftUp(int pos) {
        while (pos != 0 && elements[pos] < elements[parent(pos)]) {
            swap(pos, parent(pos));
            pos = parent(pos);
        }
    }
    void siftDown(int pos) {
        while (!isLeaf(pos) && elements[greaterChild(pos)] < elements[pos]) {
            int gChild = greaterChild(pos);
            swap(pos, gChild);
            pos = gChild;
        }
    }
    int parent(int pos) {
        return (pos - 1) / 2;
    }
    int leftChild(int pos) {
        return 2 * pos + 1;
    }
    int rightChild(int pos) {
        return 2 * pos + 2;
    }
    void swap(int pos1, int pos2) {
        E temp = elements[pos1];
        elements[pos1] = elements[pos2];
        elements[pos2] = temp;
    }
    bool isLeaf(int pos) {
        return leftChild(pos) >= size;
    }
    int greaterChild(int pos) {
        if (rightChild(pos) >= size ||
            elements[leftChild(pos)] < elements[rightChild(pos)])
            return leftChild(pos);
        return rightChild(pos);
    }

public:
    MinHeap(int max = DEFAULT_MAX_SIZE) {
        if (max < 1)
            throw runtime_error("Invalid size.");
        elements = new E[max];
        this->max = max;
        size = 0;
    }
    ~MinHeap() {
        delete [] elements;
    }
    void insert(E element) {
        if (size == max)
            throw runtime_error("Heap is full.");
        elements[size] = element;
        siftUp(size);
        size++;
    }
    E first() {
        if (size == 0)
            throw runtime_error("Heap is empty.");
        return elements[0];
    }
    E removeFirst() {
        if (size == 0)
            throw runtime_error("Heap is empty.");
        return remove(0);
    }
    E remove(int pos) {
        if (size == 0)
            throw runtime_error("Heap is empty.");
        if (pos < 0 || pos >= size)
            throw runtime_error("Index out of bounds.");
        swap(pos, size - 1);
        size--;
        siftDown(pos);
        return elements[size];
    }
    void clear() {
        size = 0;
    }
    bool isEmpty() {
        return size == 0;
    }
    int getSize() {
        return size;
    }
    void print() {
        cout << "[ ";
        for (int i = 0; i < size; i++)
            cout << elements[i] << " ";
        cout << "]" << endl;
    }
    void printP() {
        cout << "[ ";
        for (int i = 0; i < size; i++)
            //cout << *(elements[i]) << " ";
        cout << "]" << endl;
    }
};

#endif // MINHEAP_H
