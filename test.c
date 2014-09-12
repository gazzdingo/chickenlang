
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "parser.tab.h"
#include "cw1.h"
int main(int argc, char** argv) {
	createCanvas();
	yyparse();
	waitToQuit();
	return 0;

}
void yyerror (char *s) {

	fprintf (stderr, "%s\n", s);
}
