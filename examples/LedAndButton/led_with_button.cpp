#include <mbedExt.h>
#include <Button.h>
#include <Led.h>

Button button(USER_BUTTON, FALL_TO_RISE);
Led led(LED1);
int main() {
  // blink 5 times when the program is started
  led.blink(5);

  button.onClick([](){
    // toggle the continuous blinking on button click
    led.toggleBlinking();
  });

  while(1) {
    sleep();
  }
}