%{
    #include<stdio.h>
    #include<string.h>
    char str[10][10];
    int count[10]={0};
    char currstr[10];
    int flag;
    
%}
%%
[a-zA-Z]+ {
            strcpy(currstr,yytext);
            flag=0;
            for(int k=0;k<10;k++)
            {
                if(strcmp(str[k],currstr)==0)
                {
                    count[k]++;
                    flag=1;
                }
            }
            if(flag==0)
            {
                strcpy(str[j],currstr);
                count[j]++;
                j++;
            }

          }
\n {return 0;}          
%%
int main()
{
    printf("Enter the string:");
    yylex();
    printf("The count of words are:\n");
    for(int i=0;i<10;i++)
    {
        if(count[i]!=0)
        {
            printf("%s-->%d\n",str[i],count[i]);
        }
    }
    return 0;
}
int yywrap()
{
    return 1;
}