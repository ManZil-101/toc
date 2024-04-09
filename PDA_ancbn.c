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

  int flag = 1;
  int i = 0;
  char str[100],d='y',cs, ch, chpop;
printf("------Lab Report by Manjil Gautam (28193/078) -------\n");
while(d =='y')
    {
        cs = 'A';
  printf("enter string: ");
  scanf("%s", str);
  while ((ch = str[i]) != '\0')
  {

    if (cs == 'A' && ch == 'a')
    {
      Push(ch);
      cs = 'A';
    }

    else if (cs == 'A' && ch == 'c')
    {
      cs = 'B';
    }
    else if (cs == 'B' && ch == 'b')
    {

      if (S[tos] == 'a')
      {
        chpop = Pop();
        cs = 'B';
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

  if (flag == 1 && tos == -1 && i == strlen(str))
  {
    printf("%s is Accepted!!",str);
  }

  else
  {
    printf("%s is Rejected...",str);
  }
 printf("\n do you want to continue (y/n):");
    scanf(" %c",&d);
    }
  return 0;
}
