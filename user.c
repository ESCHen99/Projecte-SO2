#include <libc.h>

char buff[24];

int pid;

char s[25][80];

struct pair{
  int x;
  int y;
 };

void up(struct pair* p){
  if(p -> y > 1) --p -> y;
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


void test_nivell2(){

	int* a = alloc_page();
	for(int i = 0; i < 25*80; ++i) a[i] = i%10 + '0';
	put_screen(a);
}

void test_nivell1(struct pair* p){
	  struct pair pp = *p;
    char c = 0;
    get_key(&c);
    switch(c){
      case '8':
        up(p);
        break;
      case '6':
        right(p);
        break;
      case '4':
        left(p);
        break;
      case '2':
        down(p);
        break;
    }
    if(c){
      s[pp.y][pp.x] = ' ';
      s[p->y][p->x]= 'A';
    }
   
		put_screen(&s[0][0]); 

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
	s[0][0] = 'f';
	s[0][1] = 'p';
	s[0][2] = 's';
	s[0][3] = ':';
	s[0][4] = ' '; 
  struct pair p;
  p.x = 0;
  p.y = 1;

	put_screen(&s[0][0]);
  while(1) {
//	test_nivell1(&p);
		test_nivell2();
    }
}
