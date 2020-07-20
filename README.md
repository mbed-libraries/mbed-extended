# Mbed Extended
The Mbed Extended library provides general useful utility classes to make your life even easier.

In order to use the basic features including macros, vectors and byte / bit manipulation, just include `mbedExt.h`  in your file. This internally already includes  `mbed.h`, so you do not have to include it yourself.

```cpp
#include <mbedExt.h>
```

Everything else has to be included manually.

## Features
- I2C Helper
- Arduino like Macros
- Macros for byte / bit manipulation
- Helper for handling ISRs
- Datastructures
	- Queue
	- (Doubly) Linked list
	- Vectors (2D, 3D, 4D)
- LED driver
- Button driver
- Debounced input

### I2CUtil
 The `I2CUtil` class provides a way to simplify communication using the I2C master interface. It allows reading and writing specific registers or bits inside these registers with a single method call. The method names and functionality is inspired by the [i2cdevlib](https://github.com/jrowberg/i2cdevlib) for Arduino.  
 Note the they are *not* directly replaceable. Especially the way the bit manipulation is implemented  is handled differently.  

It can be used by including the `I2CUtil.h` file. All methods of the `I2CUtil` class are static and their names together with the documentation should be pretty self explanatory.

### Macros
 There are several macros defined which mimic some useful functions that are available in the Arduino framework
 
 - `map` which maps a value from an input range to an output range. Note that this version, in contrast to the Arduino one,  also supports `float` ranges.
 - `constrain` which  constrains a value between a given min and max value
 - binary `min` and `max` that work for every datatype that is compatible with the `<` operator
 
 There are also Arduino-like constants defined for `HIGH` and `LOW`.
 
 Everything is defined withing the `ExtMacros.h` file which is already included in the `mbedExt.h` file. You can, of course also include it separately.
 
###  Bytes
 The `Bytes.h`file provides various macros for byte and bit manipulation. 
 
 - Set, clear, read, write and toggel a certain bit
 - All the bitwise operations
 - Combining multiple bytes into another data type, e.g. two `uint8_t` into a single `uint16_t`
 - Casting unsigned to signed integers
 
   Everything is defined withing the `Bytes.h` file which is already included in the `mbedExt.h` file. You can, of course also include it separately.
   
### IsrUtil
The `IsrUtil` class provides a way to keep long-running tasks to be executed in an ISR. For example you want to print some text using the serial interface when a button is pressed. When the button is pressed an ISR is called where you can add code but it is not recommended to do things like serial communication in ISRs as this will block everything else as long as the ISR is handled.  
In order to solve this problem you usually want to just set a flag in the ISR and execute the long-running code in the main loop if the flag is set. As this is quite a common task which creates some overhead if you are using multiple ISRs, the `IsrUtil` class provides an easy way to simplify this.  
Long-running operation such as serial communication can be queued in for of a `Callback` which then is dequeued and executed in the main loop without the need for any flags.

#### Usage
Everything is defined withing the `IsrUtil.h` file which is already included in the `mbedExt.h` file. You can, of course also include it separately.

The `IsrUtil` class has a static method `global()` which return a global instance which is what you want in most cases, otherwise you can create an instance yourself.

The `IsrUtil` class provides a `runLater` method which takes a `Callback` that contains the code you want to be executed in the main loop. You call this method in the ISR.

```cpp

void onISR(){
	IsrUtil::global()->runLater([](){
      		// code to be executed in the main loop
    });
    	
	// or use this macro that is a shortcut for the above
	runLater([](){
		// code to be executed in the main loop
	});
}

```

Note that you can use lambda expression syntax to define the `Callback`.

In your main loop you have to call the the `executeAll()` method of the `IsrUtil` class somewhere in order to execute the queued `Callback`
```cpp
// setup part

while(1){
	// main loop
	// ... do other stuff here...
	
	IsrUtil::global()->executeAll(); 
	// or
	runAllFromIsr();
}
```

That's it.


### Datastructures
   There are some some common datastructures already implemented in the library.
   
#### Vectors
There    are structs for 2 to 4 dimensional vectors defined in the `Vector.h` file. Additionally there are also common vector operations like length or scalar multiplication defined as macros.

Everything is defined withing the `IsrUtil.h` file which is already included in the `mbedExt.h` file. You can, of course also include it separately.

#### Linked List
A generic doubly linked list is implemented in `LinkedList.h`. It provides the usual operation such as insert, remove, get etc. and, as it work using pointers should have a pretty good performance.

#### Queue
A generic Queue (FIFO) is implemented in `LinkedList.h`. Apart from the enqueue and dequeue operations, the queue also supports a maximum capacity that can be set.

### Additional Drivers
There a couple of driver for common components included that make the life a little easier and development faster.

- **LED**: Simple driver for an LED that supports blinking the LED a predefined amount of times are continuously at a specific frequency. Everything without using delays, so its non-blocking.
- **DebouncedIn**: A digital input that is debounced. Useful for buttons, end switches, etc.
- **Button**: Driver for a simple push button. ISR can be registered for different click types (click, double click, long click). 
 