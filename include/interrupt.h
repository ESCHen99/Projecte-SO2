/*
 * interrupt.h - Definició de les diferents rutines de tractament d'exepcions
 */

#ifndef __INTERRUPT_H__
#define __INTERRUPT_H__

#include <types.h>

#define KEY_BUFF_SIZE 50 
#define IDT_ENTRIES 256

char key[KEY_BUFF_SIZE];
int head;
int tail;

extern Gate idt[IDT_ENTRIES];
extern Register idtR;

void setInterruptHandler(int vector, void (*handler)(), int maxAccessibleFromPL);
void setTrapHandler(int vector, void (*handler)(), int maxAccessibleFromPL);

void setIdt();

unsigned int putscreen;
int tick; 

#endif  /* __INTERRUPT_H__ */
