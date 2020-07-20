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

#ifndef _MBED_EXT_LED_H_
#define _MBED_EXT_LED_H_

#include <mbed.h>

#define DEFAULT_LED_BLINK_FREQ 1.0f // 1Hz

/**
 * Driver for an LED
 */
class Led : DigitalOut
{
public:
    /**
     * Constructor
     * @param ledPin the pin the LED in connected to
     */
    Led(PinName ledPin);

    /**
     * Toggles the LED
     */
    void toggle();

    /**
     * Sets the LED on (IO pin HIGH)
     */
    void on();

    /**
     * Sets the LED off (IO pin LOW)
     */
    void off();

    /**
     * Blinks the LED the specified amount of times with the specified frequency
     * @param n number of times to blink the LED
     * @param blinkFreqHz frequency for the LED blinking in hertz
     */
    void blink(int n, float blinkFreqHz = DEFAULT_LED_BLINK_FREQ);

    /**
     * Starts blinking the LED with the specified frequency
     * @param blinkFreqHz frequency for the LED blinking in hertz
     */
    void startBlinking(float blinkFreqHz = DEFAULT_LED_BLINK_FREQ);

    /**
     * Stops blinking the LED
     */
    void stopBlinking();

    /**
     * Sets the LED blinking state
     * @param blinking true to set the LED blinking, false to stop blinking the LED
     * @param blinkFreqHz frequency for the LED blinking in hertz. Ignored when parameter blinking is false
     */
    void setBlinking(bool blinking, float blinkFreqHz = DEFAULT_LED_BLINK_FREQ);

    /**
     * Toggles whether the LED is blinking
     */
    void toggleBlinking();

    /**
     * Gets whether the LED is blinking
     * @return true if the LED is blinking, false otherwise
     */
    bool isBlinking() { return isLedBlinking; };

private:
    int remainingBlinks;
    bool isLedBlinking;
    LowPowerTicker blinkTicker;
};

#endif
