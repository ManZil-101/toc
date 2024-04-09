#include <stdio.h>
#include <string.h>

char S[100]; // stack
int tos = -1;

void Push(char ch)
{
    tos = tos + 1;
    S[tos] = ch;
}

char Pop()
{
    char ch;
    ch = S[tos];
    tos = tos - 1;
    return ch;
}

void check_string(char str[])
{
    char ss = 'z', ch, chpop;
    int i = 0;
    int flag = 1;

    while ((ch = str[i]) != '\0')
    {
        if ((ss == 'z' || ss == 'a') && ch == 'a')
        {
            Push(ch);
            printf("a pushed into Stack \n");
            ss = 'a';
        }
        else if (ss == 'a' && ch == 'b')
        {
            if (S[tos] == 'a')
            {
                chpop = Pop();
                printf("%c Popped from Stack\n", chpop);
                ss = 'a';
            }
            else
            {
                flag = 0;
                break;
            }
        }
        else
        {
            flag = 0;
            break;
        }
        i++;
    }

    if (flag == 1 && tos == -1 && i == strlen(str))
    {
        printf("Accepted");
    }
    else
    {
        printf("Rejected");
    }
}

int main()
{
    char str[100];
    char d = 'y';
    printf("------Lab Report by Manjil Gautam (28193/078)-------\n");
    while(d == 'y')
    {
    printf("Enter string: ");
    scanf("%s", str);
    check_string(str);
    printf("\n do you want to continue (y/n):");
    scanf(" %c",&d);
    }

    return 0;
}
