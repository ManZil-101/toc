#include <stdio.h>
#include <string.h>

int dfa = 0;
void q0(char c)
{
    if (c == 'w')
        dfa = 1;
    else if (c == 'f')
        dfa = 6;
    else
        dfa = -1;
}

void q1(char c)
{
    if (c == 'h')
        dfa = 2;
    else
        dfa = -1;
}
void q2(char c)
{
    if (c == 'i')
        dfa = 3;
    else
        dfa = -1;
}
void q3(char c)
{
    if (c == 'l')
        dfa = 4;
    else
        dfa = -1;
}
void q4(char c)
{
    if (c == 'e')
        dfa = 5;
    else
        dfa = -1;
}
void q5(char c)
{
    dfa = -1;
}
void q6(char c)
{
    if (c == 'o')
        dfa = 7;
    else
        dfa = -1;
}
void q7(char c)
{
    if (c == 'r')
        dfa = 5;
    else
        dfa = -1;
}

int isAccepted(char str[])
{
    dfa =0;
    int i, len = strlen(str);
    for (i = 0; i < len; i++)
    {
        if (dfa == 0)
            q0(str[i]);
        else if (dfa == 1)
            q1(str[i]);
        else if (dfa == 2)
            q2(str[i]);
        else if (dfa == 3)
            q3(str[i]);
        else if (dfa == 4)
            q4(str[i]);
        else if (dfa == 6)
            q6(str[i]);
        else if (dfa == 7)
            q7(str[i]);
        else if (dfa == 5)
            q5(str[i]);
        else
            return 0;
    }

    if (dfa == 5)
        return 1;
    else
        return 0;
}

int main()
{
	char str[100];
    char d = 'y';
	printf("------Lab Report by Manjil Gautam (28193/078) -------\n");
    printf("DFA that accepts 'while' and 'for' keyword.\n");
    while( d == 'y' )
    {

	printf("Enter string: ");
	scanf("%s", str);
	if (isAccepted(str))
		printf("Accepted");
	else
		printf("Not Accepted");
    printf("\n do you want to continue (y/n):");
    scanf(" %c",&d);
    }

	return 0;
}
