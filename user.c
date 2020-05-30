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

void test_nivell3(){
	nice(1);
	if(fork() == 0){
		nice(0);
		char buff[256] = "Fill";
		for(int i = 0; i < 10000; ++i){
			itoa(i, &buff[4]);
			write(1, buff, strlen(buff));
		}
		for(int i = 0; i < 100000; ++i) write(1, buff, strlen(buff));
		while(1);
		exit();
	}
	else{
		if(fork() == 0){
			nice(500);
			char buffAA[256] = "BUFAAA";
			for(int i = 0; i < 2; ++i)			write(1, buffAA, strlen(buffAA));
			exit();
		}
		char buff[256] = "Parent";
		while(1);
		for(int i = 0; i < 50; ++i){ // Si el nice funciona fins que el fill fa exit no hauria d'escriure
			itoa(i, &buff[6]);
			write(1, buff, strlen(buff));
		}
//		exit();
	}
}

void test_nivell2(){
//init_bakabaka();	
	nice(50);	
	char buff2[256];
	itoa(getnice(), &buff2[0]);
//	write(1, buff2, strlen(buff2));

	char *a = bakabaka_malloc();//alloc_page();
	if(fork() == 0){
		nice(2);
		char buff[256];
		itoa(getnice(), &buff[0]);
	//	for(int i = 0; i < 1e7; ++i){write(1, buff, strlen(buff));}
		exit();
	}
	else{
//		*(a + 1) = 'X'	;
		perror();
	}
//	char *a = bakabaka_malloc();//alloc_page();

	char *b = bakabaka_malloc();
	char *c = bakabaka_malloc();
	char *d = bakabaka_malloc();
	char aux[8] = {'0', '0', '0', '0', '0', '0', '0', '0'};
	addr(a+1, &aux[0]);
	write(1, aux, 8);
	*(a+1) = 'a';
	for(int i = 80; i < 25*80; ++i){ 
		*(a + i) = 'A';
		addr(&a[i], &aux[0]);
		write(1, aux, 8);
	}
	for(int i = 80; i < 25*80; ++i) *(c + i) = 'C';
	for(int i = 80; i < 25*80; ++i) *(b + i) = 'B';
	for(int i = 80; i < 25*80; ++i) *(d + i) = 'D';
	put_screen(a);
	bakabaka_free(a);
	put_screen(a);
	addr(c, &aux[0]);
	write(1, aux, 8);
	addr(b, &aux[0]);
	write(1, aux, 8);
	addr(a, &aux[0]);
	write(1, aux, 8);

}

void test_nivell1(struct pair* p){
		nice(0);
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
//	test_nivell2();  
//	test_nivell3();
	while(1) {
		test_nivell1(&p);
//		test_nivell2();
  }
}
