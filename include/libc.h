/*
 * libc.h - macros per fer els traps amb diferents arguments
 *          definició de les crides a sistema
 */
 
#ifndef __LIBC_H__
#define __LIBC_H__

#include <stats.h>

extern int errno;

extern void* bakabaka_malloc_binning;

int write(int fd, char *buffer, int size);

void itoa(int a, char *b);

void addr(unsigned int a, char* b);

int strlen(char *a);

int get_key(char *c);

void perror();

int getpid();

int fork();

void exit();

int yield();

int get_stats(int pid, struct stats *st);

int put_screen(char s[80][25]);

int nice(int val);

void init_bakabaka();

void* bakabaka_malloc();

void bakabaka_free(void* addr);

int getnice();
#endif  /* __LIBC_H__ */
