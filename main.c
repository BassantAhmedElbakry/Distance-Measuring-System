/*************************************************************************************************************
 *
 * Project : Measure the distance
 *
 * File name : main.c
 *
 * Created on: ٠٩‏/١٠‏/٢٠٢٢
 *
 * Author: BASSANT AHMED
 *
 ************************************************************************************************************/

#include <avr/io.h>
#include<avr/interrupt.h>
#include"lcd.h"
#include"ultrasonic.h"

int main (void){

	SREG |= (1 << 7);

	uint8 Distance ;

	/*Initializations*/
	LCD_init();
	Ultrasonic_init();

	/*Display on LCD*/
	LCD_displayString("Distance=     cm");

	while(1){

		Distance = Ultrasonic_readDistance();/*Store the distance*/

		/*Move cursor every time to write in the same place at the LCD*/
		LCD_moveCursor(0, 10);

		/*Check the distance if it greater than or equal 100*/
		if(Distance < 100){

			/*Display the distance*/
			LCD_sendNumbers(Distance);
			LCD_moveCursor(0, 12);
			LCD_displayCharacter(' ');

		}
		else{

			/*Display the distance*/
			LCD_sendNumbers(Distance);
		}
	}

	return 0 ;
}
