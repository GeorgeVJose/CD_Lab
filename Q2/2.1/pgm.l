%{
	#include<stdio.h>
	#include<stdlib.h>
%}

%%
0(10|01)* {printf("Valid String\n");}	
.* 	{printf("Invalid String\n");}
%%

void main()
{
	yylex();
}

