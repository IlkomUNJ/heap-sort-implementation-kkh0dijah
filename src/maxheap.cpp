#include <iostream>
#include <vector>

using namespace std;

void maxHeapify(vector<int>& A, int heap_size, int i) { 
    int largest = i; 
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap_size && A[left] > A[largest]) {
        largest = left;
    }

    if (right < heap_size && A[right] > A[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(A[i], A[largest]);  
        maxHeapify(A, heap_size, largest);
    }
}

void buildMaxHeap(vector<int>& A) { 
    int n = A.size();
    
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(A, n, i);
    }
}

void printHeap(const vector<int>& A) { 
    for (int val : A) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> A = {5, 6, 7, 11, 12, 13};

    cout << "Original array: ";
    printHeap(A);

    buildMaxHeap(A);

    cout << "Max Heap: ";
    printHeap(A);

    return 0;
}
