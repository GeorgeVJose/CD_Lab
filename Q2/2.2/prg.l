%{
	#include<stdio.h>
	#include<stdlib.h>
	int count;
%}

digit [0-9]
letter [A-Za-z]

%%
[(!#+=.;)<>"%,]
[{}]
if|else|int|char|void|main|include|stdio.h|stdlib.h|printf
"({letter}|{digit})*"
{digit}({digit}|{letter})*
%({letter})*
&{letter}

{letter}({letter}|{digit})*	printf("%s", yytext);
%%

void main()
{
	yyin = fopen("program.txt", "r");
	printf("Identifiers :\n");
	yylex();
}

