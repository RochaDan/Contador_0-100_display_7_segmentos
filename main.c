/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                     Programação em C18 - PIC18F4520                     *
 *                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *     VERSÃO : 1.0                                                        *
 *     DATA : 24-11-2022                                                   *
 *     PROGRAMMER : Danillo Rocha                                           *
 *                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <p18f4520.h>
#include <stdlib.h>
#include <stdio.h>
#pragma config OSC = HS // configura oscilador
#pragma config PWRT = ON // configura temporizador de inicialização
#pragma config WDT = OFF // desliga o watch dog timer

#pragma config LVP = OFF // desliga a progamação em baixa tensão (3.3v)

#include <delays.h>

void main(){
	
	unsigned int countB;
	unsigned int countC;
	unsigned int countD;

	TRISB = 0b00000000; // Define o dados da porta B como saida
	PORTB = 0b00000000; // Zera os resultados da porta B
	LATB =  0b00000000; // Zera os flip flops da porta B

	TRISC = 0b00000000; // Define o dados da porta C como saida
	PORTC = 0b00000000; // Zera os resultados da porta C
	LATB =  0b00000000; // Zera os flip flops da porta C
	
	TRISD = 0b00000000; // Define o dados da porta D como saida
	PORTD = 0b00000000; // Zera os resultados da porta D
	LATD =  0b00000000; // Zera os flip flops da porta D

	ADCON1 = 0b00001111; //Define as portas como digital
	
	while(1){
		
		for(countD = 0; countD <= 1; countD++){ // laço bit2
			Delay10KTCYx(15);
			if(countD == 1){
				PORTD = 0b00000001;
				Delay10KTCYx(500);
				return;
			}
			
			for(countC = 0; countC <= 9; countC++){ // laço bit1
				Delay10KTCYx(50);
				
				switch(countC){
					case 1:
						PORTC = 0b00000001;	// 1
						break;
					case 2:
						PORTC = 0b00000010;	// 2
						break;
					case 3:
						PORTC = 0b00000011;	// 3
						break;
					case 4:
						PORTC = 0b00000100;	// 4
						break;
					case 5:
						PORTC = 0b00000101;	// 5
						break;
					case 6:
						PORTC = 0b00000110;	// 6
						break;
					case 7:
						PORTC = 0b00000111;	// 7
						break;
					case 8:
						PORTC = 0b00001000;	// 8
						break;
					case 9:
						PORTC = 0b00001001;	// 9
						break;

				} // end switch
				
				
				for(countB = 1; countB <= 9; countB++){ // laço bit0
					Delay10KTCYx(200);
					
					switch(countB){
						case 1:
							PORTB = 0b00000001;	// 1
							break;
						case 2:
							PORTB = 0b00000010;	// 2
							break;
						case 3:
							PORTB = 0b00000011;	// 3
							break;
						case 4:
							PORTB = 0b00000100;	// 4
							break;
						case 5:
							PORTB = 0b00000101;	// 5
							break;
						case 6:
							PORTB = 0b00000110;	// 6
							break;
						case 7:
							PORTB = 0b00000111;	// 7
							break;
						case 8:
							PORTB = 0b00001000;	// 8
							break;
						case 9:
							PORTB = 0b00001001;	// 9
							Delay10KTCYx(250);
							
							if(PORTC != 0b00001001){ // condicao para nao mudar o contador quando PORTC = 9
								PORTC = countC + 1;
							} else {
								//PORTB = countB + 1;	
								PORTC = 0b00000000; // Zera
							}
							
							PORTB = 0b00000000; // zera
							continue;
							
					} // end switch
					
				} // bit0
				
			} // bit1
			
		} // bit2	
		
	} // while
	
} // main
