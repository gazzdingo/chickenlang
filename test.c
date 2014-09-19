
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "parser.tab.h"
#include "cw1.h"
#include "chicken.h"
#include "syntax.h"


struct expr_t* syntax_tree = 0;



void run(struct expr_t* syntax_tree) {


	assert(syntax_tree);

struct x_y_pos* resultXY = 0;
	switch(syntax_tree->type) {
		case CHICKEN:
		resultXY = (struct x_y_pos *)syntax_tree->input;
			drawChicken(resultXY->x,resultXY->y);
			if(syntax_tree->next != NULL){
				run(syntax_tree->next);
			}
			break;

	}
}




int main(int argc, char** argv) {
	createCanvas();
	yyparse();
	run(syntax_tree);
	// drawChicken(100,100);
	waitToQuit();
	return 0;

}
void yyerror (char *s) {

	fprintf (stderr, "%s\n", s);
}
