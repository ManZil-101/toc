#include <stdio.h>
#include <string.h>

int dfa = 0;
void q0(char c)
{
	if (c == 'a')
		dfa = 1;
	else if (c == 'b')
		dfa = 0;
	else
		dfa = -1;
}

void q1(char c)
{
	if (c == 'b')
		dfa = 2;
	else if (c == 'a')
		dfa = 1;
	else
		dfa = -1;
}
void q2(char c)
{
	if (c == 'b')
		dfa = 3;
	else if (c == 'a')
		dfa = 1;
	else
		dfa = -1;
}
void qf(char c)
{
	if (c == 'a' || c == 'b')
		dfa = 3;
	else
		dfa = -1;
}

int isAccepted(char str[]) {
    dfa = 0; // Reset DFA state to initial state at the beginning
    int i, len = strlen(str);
    for (i = 0; i < len; i++) {
        if (dfa == 0)
            q0(str[i]);
        else if (dfa == 1)
            q1(str[i]);
        else if (dfa == 2)
            q2(str[i]);
        else if (dfa == 3)
            qf(str[i]);
        else
            return 0;
    }
    if (dfa == 3)
        return 1;
    else
        return 0;
}
int main()
{
	char str[100];
    char d = 'y';
	printf("------Lab Report by Manjil Gautam (28193/078) -------\n");

    while( d == 'y' )
    {

	printf("Enter any string: ");
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
