#include<stdio.h>
#include<string.h>
#include<ctype.h>

int top = -1;
int num_trows = 6, num_tcols =7;
char stack[25];
char parsing_table[6][7][4] = { "NT","i","+","*","(",")","$",
			                    "E" ,"TX","-","-","TX","-","-",
		                    	"X","-","+TX","-","-","#","#",
		                    	"T","FY","-","-","FY","-","-",
		                    	"Y","-","#","*FY","-","#","#",
                                "F","i","-","-","(E)","-","-"
                                };

void push(char ch)
{
    stack[++top] = ch;  
}

char pop(char ch)
{
    return stack[top--];    
}

void revpush(char ch[])
{
    for(int i=strlen(ch); i>=0; i--)
        push(ch[i]);
}

int getrow(char ch)
{
    for(int i=0; i<num_trows; i++)
        if(parsing_table[i][0] == ch)
            return i;
}

int getcol(char ch)
{
    for(int i=0; i<num_tcols; i++)
        if(parsing_table[0][i] == ch)
            return i;
}


