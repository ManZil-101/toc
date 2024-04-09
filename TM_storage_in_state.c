// Lab 16 : implementation of storage in state Turing machine that accepts String (ab*  + ba*)
#include <stdio.h>
#include <conio.h>
#define MAX 100

char tape[MAX];
struct state
{
   char cs;
   char a;
};

int main()
{
   int flag = 0;
   struct state q0;
   q0.cs = 'A';
   q0.a = '\0';
   char ch;
   int i = 0;
   printf("------Lab report by Manjil Gautam (28193/078)------\n");
   printf("Enter string: ");
   scanf("%s", tape);

   while (1)
   {

      ch = tape[i];
      if (q0.cs == 'A' && q0.a == '\0' && ch == 'a')
      {
         q0.cs = 'A';
         q0.a = 'a';
         i++;
      }

      else if (q0.cs == 'A' && q0.a == 'a' && ch == 'b')
      {
         i++;
      }
      else if (q0.cs == 'A' && q0.a == 'a' && ch == '\0')
      {
         flag = 1;
         break;
      }
      else if (q0.cs == 'A' && q0.a == '\0' && ch == 'b')
      {
         q0.cs = 'A';
         q0.a = 'b';
         i++;
      }

      else if (q0.cs == 'A' && q0.a == 'b' && ch == 'a')
      {
         i++;
      }
      else if (q0.cs == 'A' && q0.a == 'b' && ch == '\0')
      {
         flag = 1;
         break;
      }

      else
      {
         break;
      }
   }

   if (flag == 1)
   {
      printf("Accepted\n");
   }
   else
   {
      printf("Rejected\n");
   }

   return 0;
}
