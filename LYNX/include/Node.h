#pragma once

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T _data) {
        data = _data;
        next = nullptr;
    }

    Node(T _data, Node<T>* _next = nullptr) {
        next = _next;
        this->data = _data;
    }
};