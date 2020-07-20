#include <mbedExt.h>
#include <IsrUtil.h>

InterruptIn in(USER_BUTTON);
Serial serial(USBTX, USBRX);
int main() {
  
  in.rise([](){
    // it's not recommended to use serial communication in ISRs, so we schedule the communication to be executed in the main loop
    IsrUtil::global()->runLater([](){
      serial.printf("This will be executed in the main loop!\n");
    });

    // or use this macro that is a shortcut for the above
    runLater([](){
      serial.printf("This as well!\n");
    });
  });

  while(1) {
    // ... do some other stuff here ... 
    
    // this will execute everything that has been scheduled in ISRs 
    IsrUtil::global()->executeAll(); // equivalent to this macro: runAllFromIsr();

    // you can also only run a limited amount of scheduled ISR callbacks in each iteration
    IsrUtil::global()->executeN(2); // equivalent to this macro: runNFromIsr(2);

    // or just one each iteration
    runOneFromIsr();
  }
}