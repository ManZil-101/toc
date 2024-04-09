#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 100

char S[MAX_STACK_SIZE]; // stack
int tos = -1;

void Push(char ch)
{
    if (tos < MAX_STACK_SIZE - 1) {
        tos++;
        S[tos] = ch;
    } else {
        printf("Stack Overflow!\n");
    }
}

char Pop()
{
    if (tos >= 0) {
        char ch = S[tos];
        tos--;
        return ch;
    } else {
        printf("Stack Underflow!\n");
        return '\0';
    }
}

int main()
{
    char currentState = 'A';
    int i = 0;
    int flag = 1;
    char input[100], ch, chpop;

    printf("Enter a string: ");
    scanf("%s", input);

    while ((ch = input[i]) != '\0')
    {
        if (currentState == 'A')
        {
            Push(ch);
        }
        else if (currentState == 'B')
        {
            if (ch == Pop()) {
                // Popped character matches the current input character
            } else {
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

    if (tos == -1 && flag == 1 && i == strlen(input))
    {
        printf("Accepted!\n");
    }
    else
    {
        printf("Rejected!\n");
    }

    return 0;
}
