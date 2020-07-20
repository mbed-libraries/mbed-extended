#include <Led.h>

Led::Led(PinName ledPin) : DigitalOut(ledPin){
    remainingBlinks = 0;
}

void Led::on() {
    write(1);
}

void Led::off() {
    write(0);
}

void Led::toggle() {
    write(!read());
}

void Led::blink(int n, float blinkFreqHz) {
    // led off initially
    write(0);

    remainingBlinks = n;

    // TODO: implement
    blinkTicker.attach([this](){
        if (remainingBlinks > 0) {
            if (read()){
                remainingBlinks--;
            }
            write(!read());
        }else{
            blinkTicker.detach();
            isLedBlinking = false;

            // led off finally
            write(0);
        }
    }, (1/blinkFreqHz) / 2);

    isLedBlinking = true;
}

void Led::startBlinking(float blinkFreqHz) {
    setBlinking(true, blinkFreqHz);
}

void Led::stopBlinking() {
    setBlinking(false);
}

void Led::setBlinking(bool blinking, float blinkFreqHz) {
    if (blinking) {
        // start blinking
        blinkTicker.attach([this](){
            write(!read());
        }, (1/blinkFreqHz) / 2);
    }else{
        //stop blinking
        blinkTicker.detach();
        write(0);
    }

    isLedBlinking = blinking;
}

void Led::toggleBlinking() {
    setBlinking(!isLedBlinking);
}
