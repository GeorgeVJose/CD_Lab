#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main()
{
	FILE *fp;
	char ch, buffer[20],  keywords[4][10] = {"int", "float", "if", "else"};
	int state, i, j, flag;

	fp = fopen("prg.txt", "r");
	if(fp == NULL)
	{
		printf("Error opening file.\n");
		exit(0);
	}
	
//	while((ch=(char)fgetc(fp)) != EOF)
//		printf("%c", ch);
	
	state = 0;
	
	while(ch != EOF)
	{	
		switch(state)
		{
			case 0: ch = (char)fgetc(fp);
				if(ch == '<')
					state = 1;
				else if(ch == '>')
					state = 4;
				else if(ch == '!')
					state = 7;
//				else if(ch == '=')
//					state = 8;
				else if(isalpha(ch))
				{
					i=0;
					buffer[i]=ch;
					state = 9;
				}
				else
					printf(" ");
					
				break;
	
			case 1: ch = (char)fgetc(fp);
				if(ch == '=')
				{
					printf(" Operator:'<=' ");
					state = 0;
				}	
				else
				{
					printf(" Operator:'<' ");
					fseek(fp, -1L, SEEK_CUR);
					state = 0;
				}
				break;
	
			case 4: ch = (char)fgetc(fp);
				if(ch == '=')
				{
					printf(" Operator:'>=' ");
					state = 0;
				}
				else
				{
					printf(" Operator:'>' ");
					fseek(fp, -1L, SEEK_CUR);
					state = 0;
				}
				break;
	
			case 7: ch = (char)fgetc(fp);
				if(ch == '=')
				{
					printf(" Operator:'!=' ");
					state = 0;
				} 
				else
				{
					printf(" Unknown opeator '!' ");
					fseek(fp, -1L, SEEK_CUR);
				}
				break;
	
//			case 8: printf(" Operator:'=' ");
//				state = 0;
//				break;

			case 9: ch=(char)fgetc(fp);
				if(ch != ' ' && ch != '\n')
				{
//					printf("%c", ch);
					buffer[++i] = ch;
					state = 9;
				}
				else
				{
					buffer[++i] = '\0';
					//Compare keywords
					flag = 0;
					for(j=0;j<4;j++)
					{
						if(strcmp(keywords[j], buffer) == 0)
						{
							printf(" Keyword:'%s'", keywords[j]);
							flag = 1;
							break;
						}
					}
							
					if(flag == 0)
						printf(" Identifier:'%s'", buffer);

					strcpy(buffer, "");
					i = 0;
					state = 0;
				}
				break;
		}
	}
	printf("\n");	
}






























