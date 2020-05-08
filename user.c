#include <libc.h>

char buff[24];

int pid;

char s[25][80];

struct pair{
  int x;
  int y;
 };

void up(struct pair* p){
  if(p -> y > 0) --p -> y;
}

void down(struct pair* p){
  if(p -> y < 24)  ++p -> y;       
}

void left(struct pair* p){
        if(p -> x > 0) -- p->x;
        }

void right(struct pair* p){
        if(p->x < 79) ++ p->x;
}

int __attribute__ ((__section__(".text.main")))
  main(void)
{
    /* Next line, tries to move value 0 to CR3 register. This register is a privileged one, and so it will raise an exception */
     /* __asm__ __volatile__ ("mov %0, %%cr3"::"r" (0) ); */

  for(int i = 0; i < 25; ++i){
		for(int j = 0; j < 80; ++j){
			s[i][j] = ' ';
		}
	}
  struct pair p;
  p.x = 0;
  p.y = 0;
//	put_screen(&s[0][0]);
  while(1) {
	
    struct pair pp = p;
    char c = 0;
    get_key(&c);
    switch(c){
      case '8':
        up(&p);
        break;
      case '6':
        right(&p);
        break;
      case '4':
        left(&p);
        break;
      case '2':
        down(&p);
        break;
    }
    if(c){
      s[pp.y][pp.x] = ' ';
      s[p.y][p.x]= 'A';
      put_screen(s);
    }
   
		//put_screen(&s[0][0]); 
  }
}
