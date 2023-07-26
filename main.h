#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/**
  * struct specifiers - Struct to store specifiers pointers
  *
  * @specifier: which  specifier
  *
  * @f: The function pointer
  */

typedef struct specifiers
{
	char *specifier;
	int (*f)(va_list args);
} spc_dt;


int _write(char c);
int _printf(const char *z, ...);

int specifierS(va_list args);
int specifierC(va_list args);
int stringprint(const char *format, va_list args);
int specifierchecker(char format, va_list args);
int badspec(char prev_format, char format, int count);
int specifierDI(va_list args);
void intrec(int a);
int binarycalc(va_list args);
void binaryrec(int a);
int specheck(char type);


#endif
