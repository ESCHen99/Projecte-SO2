/*
 * libc.c 
 */

#include <libc.h>

#include <types.h>


int errno;


char get_char(unsigned int i){
	if(i > 9) return i - 10 + 'A';
	return i+'0';
}

void inner_addr(unsigned int a, char* b, int i){
	if(a < 16) b[i] = get_char(a);
	else{
		inner_addr(a/16, b, i - 1);
		b[i] = get_char(a%16);
	}
}


void addr(unsigned int a, char* b){
	inner_addr(a, b, 7);
}

void itoa(int a, char *b)
{
  int i, i1;
  char c;
  
  if (a==0) { b[0]='0'; b[1]=0; return ;}
  
  i=0;
  while (a>0)
  {
    b[i]=(a%10)+'0';
    a=a/10;
    i++;
  }
  
  for (i1=0; i1<i/2; i1++)
  {
    c=b[i1];
    b[i1]=b[i-i1-1];
    b[i-i1-1]=c;
  }
  b[i]=0;
}

int strlen(char *a)
{
  int i;
  
  i=0;
  
  while (a[i]!=0) i++;
  
  return i;
}

void perror()
{
  char buffer[256];

  itoa(errno, buffer);

  write(1, buffer, strlen(buffer));
}

// PRE: bakabaka_malloc_binning is not NULL
void* bakabaka_malloc_pop_front(){
  void* aux = bakabaka_malloc_binning;
	bakabaka_malloc_binning = (void*) *((int*) aux); // binning to next of the frame
	return aux;
}

void init_bakabaka(){
	bakabaka_malloc_binning = 'M';
}

void* bakabaka_malloc(){
	//No recycled memmory
	if(bakabaka_malloc_binning == NULL){
		void* frame = alloc_page(); // Allocate a page 4096 bytes
		// Screen 80*25 bytes = 2000 bytes one page can have 2 Screens
		bakabaka_malloc_push(frame + 2000);
		return frame;	
	}
	else{
		//Recycling memmory
		return bakabaka_malloc_pop_front();
	}
}

void bakabaka_malloc_push(void* addr){
	*((int*) addr) = bakabaka_malloc_binning;
	bakabaka_malloc_binning = addr;
}

// Faltaria fer free de pàgines
void bakabaka_free(void* addr){
	bakabaka_malloc_push(addr);
}

