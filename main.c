
/* 7 segments 
 * Author Alejandro Gomez Upegui
 */ 

//SEVEN SEGMENTS CONECTIONS
//Display a segment     -- D0 atmel port
//Display b segment	-- D1 atmel port
//Display c segment	-- D2 atmel port
//Display d segment	-- D3 atmel port
//Display e segment	-- D4 atmel port
//Display f segment	-- D5 atmel port
//Display g segment	-- D6 atmel port


#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

int a = 0;
int led[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7C, 0x7, 0x7F, 0x67, 0x00};
	
static inline void initADC0(void) {
	ADMUX |= (1 << REFS0); // Voltage de referencia capacitor externo Avcc 1uf table 24.3 248
	ADMUX &= ~(1<<MUX0); // ADC 0 seleccionado  pin 23  table ref 24.4 pag 249
	ADCSRA |= (1 << ADPS1) | (1 << ADPS0); // ADC clock prescaler /8 ref 25-5 pag 250
	ADCSRA |= (1 << ADEN); // Enable ADC Ref 24.9.2
}

int main(void) {
	int tiempo = 500;
			
	initADC0(); // Llamando el seteo de la funcion ADC0 que esta en adc.h
	
	DDRD = (0xFF); // Abriendo puertos D de salida para los leds
	DDRC |= (1<< DDC0); // Abriendo solo el Puerto DDD0
	PORTC |= (1 << PINC1);	// Se cierra la resistencia el transistor de salida se conecta
	
	while(1){
		for (int i=0; i<10; i++)
		{
			PORTD |= led[i];
			_delay_ms(tiempo);
			PORTD = led[10];
			if(i == 10){
			i=0;
			}
		}
			
	}
			
}
		
	
		
		
	
		
 
		

 



	
		
		
	

