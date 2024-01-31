#include "circular_ring_buffer_aka_circular_queue.h"
#include <iostream>

int main() {
    // Example with integers
    circular_ring_buffer<int> intBuffer(5);

    for (int i = 1; i <= 7; ++i) {
        intBuffer.enqueue(i*10);
    }
    while (!intBuffer.is_empty()) {
        std::cout << "Dequeue: " << intBuffer.dequeue() << std::endl;
        intBuffer.print();
    }

    std::cout << "----------------------------------" << std::endl;

    // Example with doubles
    circular_ring_buffer<double> doubleBuffer(3);

    doubleBuffer.enqueue(3.14);
    doubleBuffer.enqueue(2.718);
    doubleBuffer.enqueue(1.414);

    while (!doubleBuffer.is_empty()) {
        std::cout << "Dequeue: " << doubleBuffer.dequeue() << std::endl;
    }

    return 0;
}

