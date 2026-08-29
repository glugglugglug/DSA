#include "term.h"

void set_term(term_t* term, int coeff, int exp){
	term->coeff = coeff;
	term->exp = exp;
}
void disp_term(term_t* term){
	printf("%dx^%d", term->coeff, term->exp);
}

int compare_exponents(term_t* lhs, term_t* rhs){
	return lhs->exp - rhs->exp;
}
