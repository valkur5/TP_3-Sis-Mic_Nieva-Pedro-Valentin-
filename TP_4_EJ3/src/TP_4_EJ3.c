/*=============================================================================
 * Author: Pedro Valentin Nieva <valentin9702@gmail.com>
 * Date: 2022/06/20
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "TP_4_EJ3.h"
#include "sapi.h"

/*=====[Definición de prototipo de funciones]==============================*/
void tecla1();
void tecla2();
void tecla3();
void tecla4();
void UartRx();
/*=====[Definición de variables globales]==============================*/
int tecla=0;
bool_t T1=false,T2=false,T3=false,T4=false;
typedef enum commandsEnum {
COMMAND_LED1_TOGGLE='a',
COMMAND_LED2_TOGGLE='s',
COMMAND_LED3_TOGGLE='d',
COMMAND_LED4_TOGGLE='f'
} commands_t;
/*=====[Main function, program entry point after power on or reset]==========*/

int main( void )
{
   // ----- Setup -----------------------------------
   boardInit();
   uartConfig(UART_USB, 115200 ); //inicializamos la UART del puerto usb de la placa

   // ----- Repeat for ever -------------------------
   while( true ) {
	   tecla1();
	   tecla2();
	   tecla3();
	   tecla4();
	   UartRx();
   }

   // YOU NEVER REACH HERE, because this program runs directly or on a
   // microcontroller and is not called by any Operating System, as in the 
   // case of a PC program.
   return 0;
}
void UartRx(){
	uint8_t uartCharRx = uartRxRead(UART_USB);
	switch(uartCharRx){
		case COMMAND_LED1_TOGGLE:
			gpioToggle(LEDR);
			break;
		case COMMAND_LED2_TOGGLE:
			gpioToggle(LED1);
			break;
		case COMMAND_LED3_TOGGLE:
			gpioToggle(LED2);
			break;
		case COMMAND_LED4_TOGGLE:
			gpioToggle(LED3);
			break;
	}
}

void tecla1(){
	if(gpioRead(TEC1)!= true){
		for(int i=0;i<2000000;i++); //Debouce del botón
		if(gpioRead(TEC1)!= true && T1==false){ //Si la tecla está verdaderamente presionada y el led está apagado, ingreso al if
		   T1=true;//indicamos que el led está encendido
		   uartWriteString( UART_USB, "Tecla apretada: TEC1 \n" ); //Enviamos mensaje indicando que la tecla fue preisonada

		}
   }else if(gpioRead(TEC1)==true && T1==true){ //Si la tecla no está presionada y el led está encendido, ingresa a este if
	   T1=false; //Indicamos que el led está apagado
	   uartWriteString( UART_USB, "Tecla liberada: TEC1 \n" );//Enviamos mensaje indicando que la tecla fue liberada
   }
}
void tecla2(){
	if(gpioRead(TEC2)!= true){
		for(int i=0;i<2000000;i++);
		if(gpioRead(TEC2)!= true && T2==false){
		   T2=true;
		   uartWriteString( UART_USB, "Tecla apretada: TEC2 \n" );
		}
   }else if(gpioRead(TEC2)==true && T2==true){
	   T2=false;
	   uartWriteString( UART_USB, "Tecla liberada: TEC2 \n" );
   }
}
void tecla3(){
	if(gpioRead(TEC3)!= true){
		for(int i=0;i<2000000;i++);
		if(gpioRead(TEC3)!= true && T3==false){
		   T3=true;
		   uartWriteString( UART_USB, "Tecla apretada: TEC3 \n" );
		}
   }else if(gpioRead(TEC3)==true && T3==true){
	   T3=false;
	   uartWriteString( UART_USB, "Tecla liberada: TEC3 \n" );
   }
}
void tecla4(){
	if(gpioRead(TEC4)!= true){
		for(int i=0;i<2000000;i++);
		if(gpioRead(TEC4)!= true && T4==false){
		   T4=true;
		   uartWriteString( UART_USB, "Tecla apretada: TEC4 \n" );
		}
   }else if(gpioRead(TEC4)==true && T4==true){
	   T4=false;
	   uartWriteString( UART_USB, "Tecla liberada: TEC4 \n" );
   }
}
