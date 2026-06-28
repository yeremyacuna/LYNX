#pragma once
#include <iostream>
#include <vector>
#include <functional>

using std::cout; using std::cin; using std::function; using std::vector;

template <typename T, typename Compare = bool(*)(const T&, const T&)>
class Heap {

private:

    T* data_;
    int     size_;
    int     capacity_;
    Compare greater_;

    int parentIdx(int i) const { return (i - 1) / 2; }
    int leftIdx(int i)   const { return 2 * i + 1; }
    int rightIdx(int i)  const { return 2 * i + 2; }

    void resize(int newCapacity) {
        T* newBlock = new T[newCapacity];
        for (int i = 0; i < size_; i++) newBlock[i] = data_[i];
        delete[] data_;
        data_ = newBlock;
        capacity_ = newCapacity;
    }

    void siftUp(int i) {
        while (i > 0) {
            int p = parentIdx(i);
            if (greater_(data_[i], data_[p])) {
                T tmp = data_[i]; data_[i] = data_[p]; data_[p] = tmp;
                i = p;
            }
            else break;
        }
    }

    void siftDown(int i) {
        while (true) {
            int best = i;
            int left = leftIdx(i);
            int right = rightIdx(i);
            if (left < size_ && greater_(data_[left], data_[best])) best = left;
            if (right < size_&& greater_(data_[right], data_[best])) best = right;
            if (best == i) break;
            T tmp = data_[i]; data_[i] = data_[best]; data_[best] = tmp;
            i = best;
        }
    }

public:

    Heap(int capacity = 16, Compare cmp = [](const T& a, const T& b) { return a > b; })
        : data_(new T[capacity]), size_(0), capacity_(capacity), greater_(cmp) {
    }

    ~Heap() {
        delete[] data_;
        data_ = nullptr;
    }

    void push(T value) {
        if (size_ == capacity_) resize(capacity_ * 2);
        data_[size_] = value;
        siftUp(size_);
        size_++;
    }

    void pop() {
        if (isEmpty()) { cout << "[BinaryHeap] pop() — vacío\n"; return; }
        data_[0] = data_[size_ - 1];
        size_--;
        if (size_ > 0) siftDown(0);
    }

    T peek() const {
        if (isEmpty()) { cout << "[BinaryHeap] peek() — vacío\n"; return T{}; }
        return data_[0];
    }

    void buildHeap(T* arr, int n) {
        if (n > capacity_) resize(n);
        for (int i = 0; i < n; i++) data_[i] = arr[i];
        size_ = n;
        for (int i = n / 2 - 1; i >= 0; i--) siftDown(i);
    }

    void clear() { size_ = 0; }

    bool isEmpty()     const { return size_ == 0; }
    int  getSize()      const { return size_; }
    int  getCapacity()  const { return capacity_; }

    void print() const {
        if (isEmpty()) { cout << "[ empty ]\n"; return; }
        cout << "[ ";
        for (int i = 0; i < size_; i++) {
            cout << data_[i];
            if (i < size_ - 1) cout << ", ";
        }
        cout << " ]\n";
    }

};