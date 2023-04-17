//This is is just a helper program to get the assembly program started
//
void start();

#include <stdio.h>
#include "pico/stdlib.h"

void turnOn();
void turnOff();
void flushBuffer();
void inputChar(char input);
void inputToBuffer(char character);
void processEvents();


char top_of_buffer = 0;
char input_buffer[24];


int main(){
    
    { //Initialise I/O
    stdio_init_all(); 
	
    // initialise GPIO (Green LED connected to pin 25)
    gpio_init(25);
    gpio_set_dir(25, GPIO_OUT);
	}	
	
    
	char userChar;
    while(1){ //Main Loop 
		
		scanf("%c", &userChar);
		inputChar(userChar);
		
		
    }
}


void getCommand(char *buffer, int inputLength){	//STUB

	/*
	for(int = 0; i < sizeof(inputLength); i++)
		if(strcmp (buffer, commandList[0])){
				
		}
	*/	
}


void inputChar(char input_char){
	
	switch(input_char){
		case 8: //delete
			printf("\b \b");
			top_of_buffer--;
			break;
		case 13: //return
			printf("\n");
			getCommand(input_buffer, top_of_buffer);
			flushBuffer();
			break;
		default: //all else
			printf("%c", input_char);
			input_buffer[top_of_buffer] = input_char;
			top_of_buffer++;	
	}
	
	if (top_of_buffer == 255){
		flushBuffer();
		printf(" buffer underflow \n");
	}
	else if(top_of_buffer >= (int)sizeof(input_buffer)){
		printf("%i", top_of_buffer);
		flushBuffer();
		printf("buffer overflow \n");	
		
	}
}
//-------------

void flushBuffer(){
	top_of_buffer = 0;
}


void turnOn()
{
	gpio_put(25, 1); // Set pin 25 to high
	printf("LED ON!\n");
	
}
void turnOff()
{
	gpio_put(25, 0); // Set pin 25 to high
	printf("LED OFF\n");
	
}
/*
gpio_put(25, 1); // Set pin 25 to high
printf("LED ON!\n");
sleep_ms(1000); // 0.5s delay

gpio_put(25, 0); // Set pin 25 to low
printf("LED OFF!\n");
sleep_ms(1000); // 0.5s delay
*/


/*
struct _commmand_{
	char *name;
}typedef commandStruct

*commandStruct newCommand(char *name)
{
  Object* p = malloc(sizeof(Object));
  p->id = id;
  p->value = value;
  return p;
}

Object* Object_new(int id, int value) { 
  Object* p = malloc(sizeof(Object));
  p->id = id;
  p->value = value;
  return p;
}


struct _command_ *commandList[]= 
	{
		
	};
*/

