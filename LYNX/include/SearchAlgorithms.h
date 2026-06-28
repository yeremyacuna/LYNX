#pragma once
#include <iostream>
using std::cout; using std::cin;

template <typename T>
class SearchAlgorithms {

private:
    // ============ HELPERS / BINARY SEARCH ============
    // --- Helper Binary Search --- (normal recursivo)
    static int binarySearchRecursiveHelper(T* arr, int left, int right, T target) {
        if (left > right) 
            return -1;

        int mid = left + (right - left) / 2;

        if (arr[mid] == target)      
            return mid;
        else if (arr[mid] < target)  
            return binarySearchRecursiveHelper(arr, mid + 1, right, target);
        else                          
            return binarySearchRecursiveHelper(arr, left, mid - 1, target);
    }

    // --- Helper Binary Search --- (recursivo con lambda de compare)
    template <typename Compare>
    static int binarySearchRecursiveHelper(T* arr, int left, int right, T target, Compare less) {
        if (left > right)
            return -1;

        int mid = left + (right - left) / 2;

        bool isEqual = !less(arr[mid], target) && !less(target, arr[mid]);

        if (isEqual)                 
            return mid;
        else if (less(arr[mid], target)) 
            return binarySearchRecursiveHelper(arr, mid + 1, right, target, less);
        else                              
            return binarySearchRecursiveHelper(arr, left, mid - 1, target, less);
    }

public:
    // ==================================== BINARY SEARCH ====================================
    // --- Funcion de Binary Search Iterativo --- (NORMAL) / O(log n) | O(1) 
    static int binarySearchIterative(T* arr, int n, T target) {
        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target)     
                return mid;
            else if (arr[mid] < target)  
                left = mid + 1;
            else                         
                right = mid - 1;
        }
        return -1;
    }

    // --- Funcion de Binary Search Recursivo --- (NORMAL) / O(log n) | O(log n)
    static int binarySearchRecursive(T* arr, int n, T target) {
        return binarySearchRecursiveHelper(arr, 0, n - 1, target);
    }


    // --- Funcion de Binary Search Iterativo --- (COMPARADOR LAMBDA) /  O(log n)
    template <typename Compare>
    static int binarySearchIterative(T* arr, int n, T target, Compare less) {
        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            bool isEqual = !less(arr[mid], target) && !less(target, arr[mid]);

            if (isEqual)                  
                return mid;
            else if (less(arr[mid], target)) 
                left = mid + 1;
            else                              
                right = mid - 1;
        }
        return -1;
    }

    //--- Funcion de Binary Search Recursivo --- (COMPARADOR LAMBDA) /  O(log n)
    template <typename Compare>
    static int binarySearchRecursive(T* arr, int n, T target, Compare less) {
        return binarySearchRecursiveHelper(arr, 0, n - 1, target, less);
    }



};