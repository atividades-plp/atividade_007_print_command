/*
	Atividade 007 - Calculadora com operações de mod e potenciação
*/

%{
#define YYSTYPE double
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "src/func.h"
extern FILE* yyin;

void yyerror(char *s);
int yylex(void);
int yyparse();
%}

%token NUMBER EOL
%token PLUS MINUS DIVIDE TIMES
%token P_LEFT P_RIGHT
%token MOD
%token POW

%left PLUS MINUS
%left MOD
%left TIMES DIVIDE
%left POW
%left P_LEFT P_RIGHT

%%

STATEMENT:
	STATEMENT EXPRESSION EOL {$$ = $2; printf("%f\n", $2);}
	|
	;

EXPRESSION:
	NUMBER {$$ = $1;}
	|	EXPRESSION PLUS EXPRESSION {$$ = $1 + $3;}
	|	EXPRESSION MINUS EXPRESSION {$$ = $1 - $3;}
	|	EXPRESSION TIMES EXPRESSION {$$ = $1 * $3;}
	|	EXPRESSION DIVIDE EXPRESSION {$$ = $1 / $3;}
	|	P_LEFT EXPRESSION P_RIGHT {$$ = $2;}
	|	EXPRESSION MOD EXPRESSION {$$ = mod($1, $3);}
	|	EXPRESSION POW EXPRESSION {$$ = pow($1, $3);}
	;


%%

void yyerror(char *s)
{
	printf("Error: %s\n", s);
}

int main(int argc, char *argv[])
{
	if (argc == 1)
    {
		yyparse();
    }

	if (argc == 2)
	{
    	yyin = fopen(argv[1], "r");
		yyparse();
    }

	return 0;
}
