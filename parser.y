
	/* Prologue */
%{
#include <stdio.h>
#include "chicken.h"
%}
	/* Declarations section */

%defines

%union {

	int an_int;
	char *a_string;
}

%token CHICKEN_TOKEN
%token ClEAR_TOKEN
%token <an_int>NUMBER_TOKEN
%token <*a_string> IDENTIFIER
%token OPENPA_TOKEN
%token CLOSEDPA_TOKEN
%token PLUS;
%token MINUS;
%token TIMES;
%token DIVIDE;
%token SEMICOLON;
%token EQUALS;
%token ERROR;

%%
	/* Rules section */


program :
	expr

expr :
	chicken

chicken :
	CHICKEN_TOKEN OPENPA_TOKEN NUMBER_TOKEN NUMBER_TOKEN CLOSEDPA_TOKEN{drawChicken($3,$4);}

/*intvalue :
	chicken

equation :
	equation TIMES values |
	equation DIVIDE values |
	equation PLUS values |
	equation MINUS values |
	values;


values :
	OPEN_PAR equation CLOSE_PAR {$$ = $2} |
	NUMBER { $$ = $1; }*/


%%
