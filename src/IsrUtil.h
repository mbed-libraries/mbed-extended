#ifndef _MBED_EXT_ISR_UTIL_H_
#define _MBED_EXT_ISR_UTIL_H_

#include <mbed.h>
#include <LinkedList.h>



/**
 * Provides means to easily decouple long running code segments from running in ISRs by executing them in the main loop. 
 */
class IsrUtil {
    /**
     * Container for the callbacks
     */
    struct isrutil_func_container {
        Callback<void()> func;
    };
public:
    /**
     * Constructor
     */
    IsrUtil() {};

    /**
     * Enqueues a function to be executed in the main loop.
     * @param func the function to be executed
     */
    void runLater(Callback<void()> func){
        isrutil_func_container * d = new isrutil_func_container;
        d->func = func;
        
        list.pushBack(d);
    };

    /**
     * Executes all enqueued ISR functions. Note: call this method in the main loop
     */
    void executeAll() {

        while (!(list.size() == 0))
        {
            isrutil_func_container * next = list.popFront();
            next->func();
            delete next;
        }
    }

    /**
     * Execute a specific amount of functions. If there are less functions enqueued than specified, all available functions are executed.
     * Note: call this method in the main loop
     * @param n maximum number of functions to execute
     */
    void executeN(int n) {
        int numExecuted = 0;
        while (!(list.size() == 0) && numExecuted < n){
            isrutil_func_container * next = list.popFront();
            next->func();
            delete next;
        }
    }

    /**
     * Gets the number of enqueued functions
     * @return the number functions waiting to be executed
     */
    int size() {
        return list.size();
    }

    /**
     * Gets the global IsrUtil instance
     * @return the global IsrUtil instance
     */
    static IsrUtil * global() {
        if (INSTANCE == nullptr) {
            INSTANCE = new IsrUtil();
        }

        return INSTANCE;
    }

private:
    inline static IsrUtil * INSTANCE;
    LinkedList<isrutil_func_container> list;
};

/* macros for easy use */

/**
 * Shortcut for equeueing a function in the global IsrUtil instance
 * @param func the function to execute
 */
#define runLater(func) IsrUtil::global()->runLater(func)

/**
 * Shortcut for executing all function in the global IsrUtil instance
 */
#define runAllFromIsr() IsrUtil::global()->executeAll()

/**
 * Shortcut for executing n functions in the global IsrUtil instance
 * @param n maximum number of functions to execute
 */
#define runNFromIsr(n) IsrUtil::global()->executeN(n)

/**
 * Shortcut for executing a single function in the global IsrUtil instance
 */
#define runOneFromIsr() IsrUtil::global()->executeN(1)

#endif