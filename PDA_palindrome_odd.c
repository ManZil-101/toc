// lab 8 :  pda implementation for palindrome(wcw^r)

#include <stdio.h>
#include <conio.h>
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
}

int main()
{
  char cs = 'A';
  int i = 0;
  int flag = 1;
  char str[100], ch, chpop;

  printf("------Lab Report by Manjil Gautam (28193/078) -------\n");
  printf("Enter string: ");
  scanf("%s", str);
  while ((ch = str[i]) != '\0')
  {

    if (cs == 'A' && (ch == 'a' || ch == 'b'))
    {
      Push(ch);
      printf("%c pushed into Stack \n", ch);
      cs = 'A';
    }

    else if (cs == 'A' && ch == 'c')
    {

      cs = 'B';
    }

    else if (cs == 'B')
    {

      if ((ch == 'b' && S[tos] == 'b') || (ch == 'a' && S[tos] == 'a'))
      {
        chpop = Pop();
        printf("%c Poped from Stack\n",ch);
      }
      else
      {
        break;
      }
    }
    else
    {
      flag = 0;
    }
    i++;
  }

  if (tos == -1 && flag == 1 && i == strlen(str))
  {
    printf("Accepted!!");
  }

  else
  {
    printf("Rejected!!");
  }

  return 0;
}
