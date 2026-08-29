#ifndef TERM_H
#define TERM_H

#include <stdio.h>

struct term{
	int coeff;
	int exp;
};
typedef struct term term_t;

void set_term(term_t*, int, int);
void disp_term(term_t*);

int compare_exponents(term_t*, term_t*);

#endif
