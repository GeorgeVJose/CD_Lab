#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int top = -1;
int num_trows = 6, num_tcols =7;
int ip_ptr = 0;
char stack[25];
char str[20];
char cur_ip, cur_stack;
char parsing_table[6][7][3] = { "NT","i","+","*","(",")","$",
			                    "E" ,"TX","-","-","TX","-","-",
		                    	"X","-","+TX","-","-","#","#",
		                    	"T","FY","-","-","FY","-","-",
		                    	"Y","-","#","*FY","-","#","#",
                                "F","i","-","-","(E)","-","-"
                                };

void push(char ch)
{
    // printf("\nPushing %c into stack.\n", ch);
    stack[++top] = ch;  
}

char pop()
{
    return stack[top--];
}

void revpush(char ch[])
{
    for(int i=strlen(ch)-1; i>=0; i--)
        push(ch[i]);
}

int getrow(char ch)
{
    for(int i=0; i<num_trows; i++)
        if(parsing_table[i][0][0] == ch)
            return i;
}

int getcol(char ch)
{
    for(int i=0; i<num_tcols; i++)
        if(parsing_table[0][i][0] == ch)
            return i;
}

void main()
{
    // Initialize stack
    push('$');
    push('E');

    printf("Enter the input string: ");
    scanf("%s", str);

    while(top != -1)
    {
        cur_ip = str[ip_ptr];
        cur_stack = pop();

        // Check Terminal
        if(cur_stack >= 'a' && cur_stack <= 'z' || 
            cur_stack == '(' || cur_stack == ')' ||  
            cur_stack == '+' || cur_stack == '-'  ||
            cur_stack == '*' || cur_stack == '/')
        {
            // printf("Terminal..");
            if(cur_ip == cur_stack)
            {
                printf("%c matched.\n", cur_ip);
                ip_ptr++;
            }
            else if(cur_stack == 'i' && (cur_ip >= 'a' && cur_ip <= 'z'))
            {
                printf("\n%c Matched.\n", cur_ip);
                ip_ptr++;
            }
            else
            {
                printf("\nInvalid Match. Stack: %c, Input: %c\n",cur_stack, cur_ip);
                exit(0);
            }
        }

        else
        {
            if(cur_ip >= 'a' && cur_ip <= 'z')
             cur_ip = 'i';
            // row = current stack top, col = current input symbol
            int row = getrow(cur_stack);
            int col = getcol(cur_ip);

            printf("\nRule: %c --> %s\n", parsing_table[row][0][0], parsing_table[row][col]);

            if(parsing_table[row][col][0] != '-')
            {
                if(strlen(parsing_table[row][col]) > 1)
                    revpush(parsing_table[row][col]);
                else if(parsing_table[row][col][0] != '#')
                    push(parsing_table[row][col][0]);
            }   
            else
            {
                printf("\nParsing Table entry not found.\n");
                exit(0);    
            }
        }
        if(str[ip_ptr] == '$')
        {
            printf("\n String Accepted.\n");
            exit(0);
        }

    }

}

