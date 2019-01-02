#include <avr/io.h>

enum States
{
    Start,
    Init,
    Increment,
    Decrement,
    Reset
} state;

unsigned char button;

void tick_button()
{
    switch (state)
    { // state transitions
    case Start:
        state = Init; // initial
        break;

    case Init:
        if (PINA & 0x01)
        { // if PINA0 = 1 then transitions into Increment state
            state = Increment;
        }
        else
        {
            state = Init; // state remains at Init if else
        }
        break;

    case Increment:
        if (PINA & 0x02)
        { // if PINA1 = 1 then transitions into Decrement state
            state = Decrement;
        }
        else if (PINA & 0x04)
        {
            state = Reset;
        }
        else
        {
            state = Increment; // state remains at increment if else
        }
        break;

    case Decrement:
        if (PINA & 0x01)
        { // if PINA1 = 1 then transitions into increment state
            state = Increment;
        }
        else if (PINA & 0x04)
        {
            state = Reset;
        }
        else
        { // if else remains in decrement state
            state = Decrement;
        }
        break;

    case Reset: // Reset State goes to Initial State
        state = Init;
        break;

    default: // default state = start
        state = Start;
        break;
    }

    switch (state)
    { // state actions
    case Start:
        PORTC = 0x00; // PORTC = 0
        break;

    case Init: // PORTC = 0
        PORTC = 0x00;
        break;

    case Increment: // PORTC increments by 1
        ++PORTC;
        break;

    case Decrement: // PORTC decrements to 0 and stops at 0
        PORTC--;
        break;

    case Reset: // PORTC Resets to 0
        PORTC = 0x00;
        break;
    }
}

int main(void)
{
    DDRA = 0x00;
    PORTA = 0xFF; // Configure port A's 8 pins as inputs
    DDRC = 0xFF;
    PORTC = 0x00; // Configure port C's 8 pins as outputs,

    state = Start;
    while (1)
    {
        tick_button();
    }
    return 0;
}