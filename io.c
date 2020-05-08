/*
 * io.c - 
 */

#include <io.h>

#include <types.h>

/**************/
/** Screen  ***/
/**************/

#define NUM_COLUMNS 80
#define NUM_ROWS    25

Byte x, y=19;

/* Read a byte from 'port' */
Byte inb (unsigned short port)
{
  Byte v;

  __asm__ __volatile__ ("inb %w1,%0":"=a" (v):"Nd" (port));
  return v;
}

void printc(char c)
{
     __asm__ __volatile__ ( "movb %0, %%al; outb $0xe9" ::"a"(c));
  if (c=='\n')
  {
    x = 0;
    y=(y+1)%NUM_ROWS;
  }
  else
  {
    Word ch = (Word) (c & 0x00FF) | 0x0200;
    DWord screen = 0xb8000 + (y * NUM_COLUMNS + x) * 2;
    if (++x >= NUM_COLUMNS)
    {
      x = 0;
      y=(y+1)%NUM_ROWS;
    }
    asm("movw %0, (%1)" : : "g"(ch), "g"(screen));
  }
}

void printc_xy(Byte mx, Byte my, char c)
{
  Byte cx, cy;
  cx=x;
  cy=y;
  x=mx;
  y=my;
  printc(c);
  x=cx;
  y=cy;
}

void printk(char *string)
{
  int i;
  for (i = 0; string[i]; i++)
    printc(string[i]);
}



void internal_put_screen(char* s){
	for(int j = 0; j < 25 * 80; j+=2){
      DWord ch = (DWord) ((0x00000000 | (*(s+j+1)))<<16  ) | *(s+j) | 0x02000200;
      DWord screen = (DWord) 0xb8000 + (j) * 2;
      asm("movl %0, (%1)" : : "g"(ch), "g"(screen));
  }
}


