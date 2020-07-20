/*
MIT License

Copyright (c) 2020 Steffen S.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef _MBED_EXT_QUEUE_H_
#define _MBED_EXT_QUEUE_H_

#include <LinkedList.h>

template<typename T>
/**
 * A simple generic Queue (FIFO) with configurable maximum capacity.
 */
class Queue {
public:
    /**
     * Constructor
     * @param capacity the maximum number of elements in the queue
     */
    Queue(int capacity = 256) {
        this->capacity = capacity;
    };

    /**
     * Enqueues an element in the queue
     * @param elem the element to enqueue
     * @return true if the element was enqueued, false if the queue if already full
     */
    bool enqueue(T * elem){
        if (container.size() >= capacity) {
            // no space anymore
            return false;
        }

        container.pushBack(elem);
        return true;
    };

    /**
     * Gets and removes the first element from the queue
     * @return the enqueued element
     */
    T* dequeue(){
        if (container.size() == 0) {
            // empty
            return nullptr;
        }

        return container.popFront();
    };

    /**
     * Gets whether the queue is empty
     * @return true if the queue is empty, false otherwise
     */
    bool isEmpty() {return container.size() == 0;};

    /**
     * Gets whether there is space for more elements in the queue
     * @return true if the there is is space for more elements, i.e. number of elements in queue < capacity, false if the queue is full
     */
    bool hasSpace() {return container.size() < capacity;};

    /**
     * Gets the number of elements in the queue
     * @return the number of elements in the queue
     */
    int size() {return container.size();};

    /**
     * Getter for the capacity
     * @return the maximum number of elements in the queue
     */
    int getCapacity() {return capacity;};

    /**
     * Sets the maximum number of elements in the queue
     * @param newCapacity the new capacity
     */
    void setCapacity(int newCapacity) {capacity = newCapacity;};
private:
    int capacity;
    LinkedList<T> container;
};

#endif