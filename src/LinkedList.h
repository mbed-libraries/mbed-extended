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

#ifndef _MBED_EXT_LINKEDLIST_H_
#define _MBED_EXT_LINKEDLIST_H_

template<class T>
/**
 * A simple generic doubly linked list.
 */
class LinkedList {
    /**
    * An element inside the list
    */
    struct node
    {
        T * data;
        node * prev;
        node * next;
        node(T * t, node* p, node* n) : data(t), prev(p), next(n) {}
    };
public:
    /**
     * Constructor
     */
    LinkedList() {
        headNode = nullptr;
        tailNode = nullptr;
        numNodes = 0;
    };

    /**
     * Destructor. Frees all list elements
     */
    ~LinkedList(){
        if (numNodes > 0) {
            while (headNode){
                node* tmp(headNode);
                headNode = headNode->next;
                delete tmp;
            }

            numNodes = 0;
        }
    };

    /**
     * Inserts an element at a certain position into the list
     * @param elem the element to insert
     * @param pos the index for the new element
     */
    void insert(T * elem, int pos) {
        if (numNodes == 0) {
            // no element in list yet
            pushFront(elem);
            return;
        }
        

        node * currentNode = headNode;
        node * prevNode = nullptr;

        while (pos-- > 0) {
            prevNode = currentNode;
            currentNode = currentNode->next;
        }

        node * newNode = new node(elem, prevNode, currentNode);

        if (newNode->prev){
            newNode->prev->next = newNode;
        }else {
            headNode = newNode;
        }

        if (newNode->next){
            newNode->next->prev = newNode;
        }else{
            tailNode = newNode;
        }

        numNodes++;
    };


    /**
     * Appends an element to the end of the list
     * @param elem the element to append
     */
    void pushBack(T * elem) {
        tailNode = new node(elem, tailNode, nullptr);
        if (tailNode->prev) {
            tailNode->prev->next = tailNode;
        }

        if (numNodes == 0) {
            headNode = tailNode;
        }

        numNodes++;
    }

    /**
     * Prepends an element to the start of the list
     * @param elem the element to prepend
     */
    void pushFront(T * elem) {
        headNode = new node(elem, nullptr, headNode);
        if (headNode->next) {
            headNode->next->prev = headNode;
        }

        if (numNodes == 0) {
            tailNode = headNode;
        }

        numNodes++;
    }

    /**
     * Gets and removes the last element in the list
     * @return the last element in the list
     */
    T * popBack() {
        if (numNodes == 0) {
            return nullptr;
        }

        node* tmp(tailNode);
        T* data(tailNode->data);
        tailNode = tailNode->prev;

        if (tailNode) {
            tailNode->next = nullptr;
        }else{
            headNode = nullptr;
        }

        delete tmp;
        numNodes--;
        return data;
    }

    /**
     * Gets and removes the first element in the list
     * @return the first element in the list
     */
    T * popFront() {
        if (numNodes == 0) {
            return nullptr;
        }

        node * tmp(headNode);
        T* data(headNode->data);
        headNode = headNode->next;

        if (headNode) {
            headNode->prev = nullptr;
        }else{
            tailNode = nullptr;
        }

        delete tmp;
        numNodes--;
        return data;
    }

    /**
     * Gets the element at a certain index
     * @param pos the index
     * @return the element at index pos
     */
    T* get(int pos) {
        if (pos < 0 || pos > numNodes - 1) {
            // invalid index
            return nullptr;
        }

        node * currentNode = headNode;
        // traverse to index pos
        while (pos-- > 0){
            currentNode = currentNode->next;
        }

        return currentNode->data;
    }

    /**
     * Removes an element from the list
     * @param pos the index to remove
     * @return the removed element
     */
    T* remove(int pos) {
        if (pos < 0 || pos > numNodes - 1) {
            // invalid index
            return nullptr;
        }

        node * currentNode = headNode;

        // traverse to index pos
        while (pos-- > 0){
            currentNode = currentNode->next;
        }

        if (currentNode == headNode) {
            headNode = headNode->next;
        }

        if (currentNode->next) {
            currentNode->next->prev = currentNode->prev;
        }

        if (currentNode->prev) {
            currentNode->prev->next = currentNode->next;
        }

        T * data(currentNode->data);
        
        delete currentNode;
        numNodes--;

        return data;
    }

    /**
     * Shortcut for the get() method
     * @param pos the index
     * @return the element at index pos
     */
    T* operator [] (int pos) {return get(pos);};

    /**
     * Gets the number of element in the list
     * @return length of the list
     */
    int size() {return numNodes;};

    /**
     * Gets the first element
     * @return the fist element
     */
    T* head() {return head == nullptr ? nullptr : head->data;};

    /**
     * Gets the last element
     * @return the last element
     */
    T* tail() {return tail == nullptr ? nullptr : tail->data;};
private:
    int numNodes;
    node * headNode;
    node * tailNode;
};

#endif