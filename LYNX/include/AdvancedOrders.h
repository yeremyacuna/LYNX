#pragma once
#include <iostream>
#include <functional> 
#include "LinkedList.h"
#include "../src/Driver.h"

using std::cout; using std::cin; using std::function;

template <typename T>
class AdvancedOrders {
public:

    // Ordenamiento shell
    static void sortDriversByRating(LinkedList<Driver>* list)
    {
        int n = list->getSize();
        if (n <= 1) return;

        Driver* arr = new Driver[n];

        for (int i = 0; i < n; i++)
            arr[i] = list->get(i);

        for (int gap = n / 2; gap > 0; gap /= 2)
        {
            for (int i = gap; i < n; i++)
            {
                Driver temp = arr[i];
                int j = i;

                while (j >= gap && arr[j - gap].getRating() < temp.getRating())
                {
                    arr[j] = arr[j - gap];
                    j -= gap;
                }

                arr[j] = temp;
            }
        }

        list->clear();

        for (int i = 0; i < n; i++)
            list->pushBack(arr[i]);

        delete[] arr;
    }
};