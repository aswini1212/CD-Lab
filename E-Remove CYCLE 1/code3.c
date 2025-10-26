#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int state;
    struct node *next;
};

int findalpha(char inp,int a,char alphabet[a])
{
    for(int i=0;i<a;i++)
    {
        if(alphabet[i]==inp)
        {
            return i;
        }
    }
    return -1;
}

void printtransition(int n,int a,struct node *transition[n][a])
{
    for(int i=0;i<n;i++)
    {
        
        for(int j=0;j<a;j++)
        {
            printf("{");
            struct node *head=transition[i][j];
            while(head!=NULL)
            {
                printf("q%d ",head->state);
                head=head->next;
            }
            printf("}\t");
        }
        printf("\n");
    }
}
void findclosure(int start,int state,int n,int a,struct node *transition[n][a], int e_closure[n][n],int set[n])
{
    if(set[state])
        return;
    set[state]=1;
    e_closure[start][state]=1;
    struct node *temp=transition[state][a-1];
    
        while(temp!=NULL)
        {
            findclosure(start,temp->state,n,a,transition,e_closure,set);
            temp=temp->next;
        }
    

}

void printclosure(int state,int n,int e_closure[n][n])
{
    printf("{");
    for(int k=0;k<n;k++)
    {
        if(e_closure[state][k]==1)
        {
            printf("q%d ",k);
        }
    }
    printf("}\t");
}

void main()
{
    int n,a,f;
    printf("Enter the no of states:");
    scanf("%d",&n);

    printf("Enter the no of alphabets:");
    scanf("%d",&a);

    char alphabet[a];
    printf("Enter the alphabets:");
    scanf("%s",alphabet);

    printf("Enter the no of final states:");
    scanf("%d",&f);

    int final[f];
    printf("Enter the final states:");
    for(int i=0;i<f;i++)
    {
        scanf("%d",&final[i]);
    }

    FILE *fp=fopen("eNFA.txt","r");
    char state1[3],input[3],state2[3];
    int from,index,to,end;
    struct node *transition[n][a];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<a;j++)
        {
            transition[i][j]=NULL;
        }
    }

    while((end=fscanf(fp,"%s%s%s",state1,input,state2))!=EOF)
    {
        from=state1[1]-'0';
        to=state2[1]-'0';
        index=findalpha(input[0],a,alphabet);

        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp->state=to;
        temp->next=transition[from][index];
        transition[from][index]=temp;
    }
    printtransition(n,a,transition);

    int e_closure[n][n],set[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            e_closure[i][j]=0;
            set[j]=0;
        }
        findclosure(i,i,n,a,transition,e_closure,set);
    }

    printf("States in the NFA:\n");
    for(int i=0;i<n;i++)
    {
        printclosure(i,n,e_closure);
    }

    printf("\nNFA after removing Epsilon:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<a-1;j++)
        {
            for(int l=0;l<n;l++)
            {
                set[l]=0;
            }

            for(int k=0;k<n;k++)
            {
                if(e_closure[i][k]==1)
                {
                    struct node *temp=transition[k][j];
                    while(temp!=NULL)
                    {
                        int t=temp->state;
                        for(int m=0;m<n;m++)
                        {
                            if(e_closure[t][m]==1)
                            {
                                set[m]=1;
                            }
                        }
                        temp=temp->next;
                    }
                }
            }
            printf("\n");
            printclosure(i,n,e_closure);
            printf("\t%c\t",alphabet[j]);
            printf("{");
            for(int z=0;z<n;z++)
            {
                if(set[z]==1)
                {
                    printf("q%d ",z);
                }
            }
            printf("}");
        }
        printf("\n");
    }

    int arrf[4]={0};
    int currfinal;
    for(int i=0;i<f;i++)
    {
        currfinal=final[i];
        for(int k=0;k<n;k++)
        {
        if((e_closure[k][currfinal]==1) && (arrf[k]!=1))
        {
            arrf[k]=1;
        }
        
        }
    }
    printf("The final states are:{");
    for(int i=0;i<n;i++)
    {
        if(arrf[i]==1)
        printf("q%d ",i);
    }
    printf("}\n");

fclose(fp);

}
