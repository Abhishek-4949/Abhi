/*
Develop a Program in C for the following operations on Strings.

a. Read a main String (STR), a Pattern String (PAT) and a Replace String (REP)
Develop a Program in C for the following operations on Strings.

b. Perform Pattern Matching Operation: Find and Replace all occurrences of PAT in
STR with REP if PAT exists in STR. Report suitable messages in case PAT does not
exist in STR


Support the program with functions for each of the above operations. Don't use Built-in
functions.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char M[200],S[30],R[30],RE[200],C[200];
    int i=0, j=0, k=0,im,is,len,in=0,l;

    printf("\nENTER THE MAIN STRING : ");
    scanf("%s",M);
    
    printf("\nENTER THE PATTERN STRING : ");
    scanf("%s",S);
    
    printf("\nENTER THE REPLACE STRING : ");
    scanf("%s",R);

    strcpy(C,M);
    for(i=0;i<(strlen(M)-strlen(S)+1);i++)
    {
        im=0;
        for(j=0;j<strlen(S);j++)
        {
            if(M[i+j]==S[j])
            {
                im++;
            }
            else
            {
                break;
            }
            if(im==strlen(S))
            {
                in++;
                for ( k = 0; k < i; k++)
                {
                    RE[k]=M[k];
                }
                is=k+strlen(S);
                RE[k]='\0';
                strcat(RE,R);
                len=strlen(RE);
                
                for(k=is,l=0;M[k]!='\0';k++,l++)
                {
                    RE[len+l]=M[k];
                }
                RE[len+l]='\0';
                strcpy(M,RE);
            }
        }
    }
    printf("\nINPUT TEXT\n");
    printf("%s\n",C);
    if(in>0)
    {
        printf("\n%d MATCHES OCCURED\nTEXT AFTER REPLACING MATCHED PATTERNS IS SHOWN BELOW\n",in);
        printf("\n%s\n",RE);
    }
    else
    {
        printf("\nPATTERN STRING NOT FOUND IN TEXT\n");
    }
    return 0;
}
