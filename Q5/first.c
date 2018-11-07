#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

char production[10][10];
int num_prods;
void find_first(char);  

void main()
{
      int i,j,k;
      char ch, nonters[10];
      printf("Enter the number of productions :");
      scanf("%d", &num_prods);

      printf("Enter the productions :\n");      
      for(i=0;i<num_prods+1;i++)
            gets(production[i]);

      k=0;
      int flag;
      for(i=0;i<num_prods;i++)
      {
            if(isupper(production[i][0]))
            {
                  flag = 0;
                  for(j=0;j<k;j++)
                  {
                        if(production[i][0]==nonters[j])
                        {
                              flag=1;
                              break;
                        }
                  }
                  if(flag==0)
                        nonters[k++] = production[i][0];
            }

      }
      // printf("Enter the character to find follow: \n");
      // scanf("%c", &ch);    
      for(i=0;i<k;i++)
      {
            printf("First of %c = {",nonters[i]);
            find_first(nonters[i]);
            printf("}\n");
      }
}

void find_first(char ch)
{
      if(islower(ch))
      {
            printf("%c ",ch);
            return;
      }
      for(int i=0; i<num_prods;i++)
      {
            if(production[i][0]==ch)
            {
                  if(islower(production[i][2]))
                        printf("%c ",production[i][2]);   
                  else
                  {
                        find_first(production[i][2]);
                  }
            }
      }
}

void final_array()