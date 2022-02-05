// controls the speed of a DC motor
// connected to a transistor such as TIP41C
// Transistor base should be connected to PORTB0 through a resistor
// Do not forget the flyback diode

#include <avr/io.h>
#include <util/delay.h>
#include "USART.h"
#include "USART.c"

int N = 40;
void PWM_drive (int x)  ;
void PWM_drive (int x)  // function body
{
  for (int j = 0; j < 5; j++) {
    PORTB = 0b00000001;
    for (int i = 0; i < x; i++)
    {
      _delay_ms(1);
    }
    PORTB = 0b00000000;
    for (int i = 0; i < N - x; i++)
    {
      _delay_ms(1);
    }
  }  // 40 ms one loop, 40 x 5= 200 ms full function

}

int main (void)
{
  DDRB = 0b00000001;
  DDRD = 0;
  int counter = 35 ;
  PORTD |= (1 << PD2); // internal pull-up
  PORTD |= (1 << PD4);
  PORTD |= (1 << PD6);
  while (1) {

    if (bit_is_clear(PIND, PD6) && counter < 40) {
      counter++;
    }
    if (bit_is_clear(PIND, PD4) && counter > 0 ) {
      counter--;
    }
    if (bit_is_clear(PIND, PD2) )  {
      counter = 0;
      _delay_ms(20);
    }
    printString("\n counter");
    printByte(counter);
    PWM_drive(counter);
    
  }

  return 0;
}
