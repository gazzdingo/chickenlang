
	/* Prologue */
%{
#include <stdio.h>
#include "chicken.h"
#include "syntax.h"
%}
	/* Declarations section */

%defines

%union {

	int an_int;
	char *a_string;
	struct chickenVals a_chicken_val;
}

%token CHICKEN_TOKEN
%token ClEAR_TOKEN
%token <an_int>NUMBER_TOKEN
%token <*a_string> IDENTIFIER
%token OPENPA_TOKEN
%token CLOSEDPA_TOKEN
%token NEW_TOKEN
%token EQUALS_TOKEN
%token COMMA_TOKEN
%token SEMICOL_TOKEN
/*%token PLUS;
%token MINUS;
%token TIMES;
%token DIVIDE;
%token SEMICOLON;
%token EQUALS;
%token ERROR;*/

%type <a_chicken_val> chicken


%%
	/* Rules section */


program :
	expr

expr :
	chicken

value :
CHICKEN_TOKEN IDENTIFIER chicken{struct chickenVals $2 = $3;} |CHICKEN_TOKEN IDENTIFIER SEMICOL_TOKEN{struct chickenVals $2;}

chicken :
	IDENTIFIER EQUALS_TOKEN OPENPA_TOKEN NUMBER_TOKEN COMMA_TOKEN NUMBER_TOKEN CLOSEDPA_TOKEN SEMICOL_TOKEN{$1.x = $4; $1.y = $6;}|
	EQUALS_TOKEN OPENPA_TOKEN NUMBER_TOKEN COMMA_TOKEN NUMBER_TOKEN CLOSEDPA_TOKEN SEMICOL_TOKEN{$$ = inputValue(3, 5){
};}


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
