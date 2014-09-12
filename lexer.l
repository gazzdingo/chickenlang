
    /* Some options */

%option header-file="lexer.h"
%option outfile="lexer.c"
%option noyywrap

    /* Definitions section */

%{
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "parser.tab.h"

/* Function to strip quotes from string literals */
/*char* strip_quotes(char *);*/
%}

%%

    /* Rules section */
chicken                                 return CHICKEN_TOKEN;
clear                                   return ClEAR_TOKEN;
new                                     return NEW_TOKEN;
[a-zA-Z][a-zA-Z0-9_]*			       yylval.a_string = strdup(yytext); return IDENTIFIER;
(0|([1-9][0-9]*))					   yylval.an_int = atoi(yytext); return NUMBER_TOKEN;
[(]                                     return OPENPA_TOKEN;
[)]                                     return CLOSEDPA_TOKEN;
[=]                                     return EQUALS_TOKEN;
[,]                                     return COMMA_TOKEN;
[;]                                     return SEMICOL_TOKEN;


[ \t\n]+							/* Skip whitespace */


%%


/*char *strip_quotes(char *text) {

	assert(strlen(text) >=  2);
		// Overwrite closing quote
	text[strlen(text) - 1] = '\0';
		// Start copy from offset of 1
	return strdup(text + 1);
}*/
