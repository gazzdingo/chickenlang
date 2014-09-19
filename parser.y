
	/* Prologue */
%{
#include <stdio.h>
#include <strings.h>
#include "chicken.h"
#include "syntax.h"

extern struct expr_t* syntax_tree;

%}
	/* Declarations section */

%defines

%union {

	int an_int;
	char* a_string;
	struct expr_t* exptT;
	struct x_y_pos* xYPos;
}

%token CHICKEN_TOKEN
%token ClEAR_TOKEN
%token <an_int>NUMBER_TOKEN
%token <a_string> IDENTIFIER
%token OPENPA_TOKEN
%token CLOSEDPA_TOKEN
%token NEW_TOKEN
%token EQUALS_TOKEN
%token COMMA_TOKEN
%token SEMICOL_TOKEN
%token END


%type <xYPos> chicken
%type <xYPos> chickenValues
%type <a_string> assert
%type <xYPos> value
%type <exptT> expr


%%
	/* Rules section */


program :
	expr{syntax_tree = $1;}

expr :
	|
	CHICKEN_TOKEN IDENTIFIER value expr{$$= build_expr_t(CHICKEN,$2,$3,$4);}|
	IDENTIFIER chicken expr

value :
 chicken {$$ = $1;} |
 SEMICOL_TOKEN

chicken :
	EQUALS_TOKEN chickenValues SEMICOL_TOKEN {$$ = $2;}


chickenValues:
	OPENPA_TOKEN NUMBER_TOKEN COMMA_TOKEN NUMBER_TOKEN CLOSEDPA_TOKEN{$$ = build_x_y_pos($2, $4);}


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
