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

void rotate_alpha_servo(int angle, int pekistir)
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
}

void rotate_beta_servo(int angle, int pekistir)
{
  int t_count = angle * 1.15; //how many microseconds to count

  for (int i = 0; i < pekistir; i++) //send the position information twenty times
  {
    biryap(PORTB, PB1)
    _delay_ms(0.5);
    for (int j = 0; j < t_count ; j++)
    {
      _delay_us(9);
    }
    sifiryap(PORTB, PB1);
    _delay_ms(18.5);
  }
}
void rotate_big_servo(int angle, int pekistir)
{
  int t_count = angle * 1.15; //how many microseconds to count

  for (int i = 0; i < pekistir; i++) //send the position information twenty times
  {
    biryap(PORTB, PB2)
    _delay_ms(0.5);
    for (int j = 0; j < t_count ; j++)
    {
      _delay_us(9);
    }
    sifiryap(PORTB, PB2);
    _delay_ms(18.5);
  }
}

int main (void)
{
  //------PORT SETUP------
  DDRB = 0b00000111;
  DDRD = 0;
  //------VARIABLE SETUP------
  int alpha_angle = 0 ;
  int beta_angle = 90 ;
  int big_angle = 90 ;
  //------PORT PULLUP------
  PORTD |= (1 << PD0); // Alpha servo down
  PORTD |= (1 << PD2); // Alpha servo up
  PORTD |= (1 << PD3); // Beta servo down
  PORTD |= (1 << PD4); // Beta servo up
  PORTD |= (1 << PD5); // Big servo
  PORTD |= (1 << PD6); // Big servo
  initUSART();
  //------STARTUP------
  for (int i=60;i<=90;i++){
    rotate_big_servo(i, 1);
  }
  for (int i=60;i<=90;i++){
    rotate_alpha_servo(90-i, 1);
  }
  for (int i=60;i<=90;i++){
    rotate_beta_servo(i, 1);
  }
//  
//    
    
  //------MAIN LOOP------
  while (1) {
    if (bit_is_clear(PIND, PD0)) {
      if (alpha_angle <= 90) {
        alpha_angle += 1;
        rotate_alpha_servo(alpha_angle, 1);
      }
    }
    if (bit_is_clear(PIND, PD2)) {
      if (alpha_angle >= 0) {
        alpha_angle -= 1;
        rotate_alpha_servo(alpha_angle, 1);
      }
    }
    if (bit_is_clear(PIND, PD2)) {
      if (beta_angle <= 90) {
        beta_angle += 1;
        rotate_alpha_servo(alpha_angle, 1);
        rotate_beta_servo(beta_angle, 1);
        
      }
    }
    if (bit_is_clear(PIND, PD0)) {
      if (beta_angle >= 0) {
        beta_angle -= 1;
        rotate_alpha_servo(alpha_angle, 1);
        rotate_beta_servo(beta_angle, 1);
        
      }
    }
    if (bit_is_clear(PIND, PD6)) {
      if (big_angle <= 90) {
        big_angle += 1;
        rotate_big_servo(big_angle, 5);
      }
    }
    if (bit_is_clear(PIND, PD5)) {
      if (big_angle >= 0) {
        big_angle -= 1;
        rotate_big_servo(big_angle, 5);
      }
    }
    
//    rotate_alpha_servo(alpha_angle, 1);
//    rotate_beta_servo(beta_angle, 1);
    

    printString("\n alpha angle");
    printByte(alpha_angle);
    printString("\n beta angle");
    printByte(beta_angle);
    printString("\n big angle");
    printByte(big_angle);
  } // infinite loop
  return 0;
}
