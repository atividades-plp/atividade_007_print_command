/*
	Atividade 007 - Calculadora com operações de mod e potenciação
*/

%{
#define YYSTYPE double
#include "paku.tab.h" 
#include <stdlib.h>

void yyerror(char *s); 
%}

%%

[0-9]+("."[0-9]+)? 	{ yylval = atof(yytext); return NUMBER; }
[\n]				{ return EOL; }
[+]					{ return PLUS; }
[-]					{ return MINUS; }
[/]					{ return DIVIDE; }
[*]					{ return TIMES; }
[(]					{ return P_LEFT;}
[)]					{ return P_RIGHT;}
[%]					{ return MOD;}
[\^]				{ return POW;}
[[:space:]]			;
.					{ yyerror("Undefined token\n"); }

%%

int yywrap()
{
	return 1;
}

