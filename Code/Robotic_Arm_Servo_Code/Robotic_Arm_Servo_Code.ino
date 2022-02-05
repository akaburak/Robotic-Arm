// servo function code
// servo rotates to a position entered by the user
// on serial monitor
// choose CARRIAGE RETURN on Serial Monitor (& 9600 baud)
// put the files USART.c and USART.h on the same directory
// as the source file

#include <avr/io.h>
#include <util/delay.h>
#include "USART.h"
#include "USART.c"

#define biryap(inbyte, loct) inbyte |=(1<<loct);
#define sifiryap(inbyte, loct) inbyte &= ~(1<<loct)

void rotate_servo(int angle, int pekistir)
{
  int t_count = angle * 1.15; //how many microseconds to count

  for (int i = 0; i < pekistir; i++) //send the position information twenty times
  {
    biryap(PORTB, PB0)
    _delay_ms(0.5);
    for (int j = 0; j < t_count ; j++)
    {
      _delay_us(9);
    }
    sifiryap(PORTB, PB0);
    _delay_ms(18.5);
  }
  // printString("\r\n Travelled to angle:");
  // printByte(angle);
}

int main (void)
{
  DDRB = 0b00000001;
  DDRD = 0;
  int angle = 0 ;
  int pekistir = 0;
  int calc_1 = 0;
  int calc_1_angle = 0;
  int fark = 0;
  int fark_abs = 0;
  PORTD |= (1 << PD2); // internal pull-up
  // not needed if external pull up is used

  PORTD |= (1 << PD4);
  PORTD |= (1 << PD6);
  initUSART();
  int old_angle = 0;
  while (1) {
    printString("\r\n Enter the angle of the servo (0-180): ");
    angle = getNumber();
    fark = angle-old_angle;
    fark_abs = abs(fark);
    printString("\r\n Angle received, travelling...");
    if (angle <= 180)
    {   
        calc_1 = (fark_abs - fark_abs%2)/2;
        for (int i=1;i<=calc_1;i++){
          
          if (fark > 0){
          calc_1_angle = old_angle + i*(fark - fark%calc_1)/calc_1;
          printString("\n calc_1_angle equals to :");
          printByte(calc_1_angle);
          pekistir = (calc_1_angle - calc_1_angle%5)/5 + 5;
          rotate_servo(calc_1_angle,2);
        }
          if (fark < 0){
          calc_1_angle = old_angle + i*(fark - fark%calc_1)/calc_1;
          printString("\n calc_1_angle equals to :");
          printByte(calc_1_angle);
          rotate_servo(calc_1_angle,2);
        }
        
        }
        old_angle = angle;
        
    }
    else
      uyari();
    

  } // infinite loop
  return 0;
}
