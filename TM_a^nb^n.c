#include <stdio.h>
#include <conio.h>

enum states
{
   q0,
   q1,
   q2,
   q3,
   q4,
   qr
};

int main()
{
   char input[100];
   enum states cs = q0;
   int i;
   for (i = 0; i < 100; i++)
   {
      input[i] = '\0';
   }
   printf("----Lab Report by Manjil Gautam (28193/078)----\n");
   printf("Enter string: ");
   scanf("%s", input);
   i = 0;
   while (1)
   {
      switch (cs)
      {
      case q0:
         if (input[i] == 'a')
         {
            cs = q1;
            input[i] = 'X';
            i++;
         }
         else if (input[i] == 'Y')
         {
            cs = q3;
            i++;
         }
         else
            cs = qr;
         break;
      case q1:
         if (input[i] == 'a' || input[i] == 'Y')
         {
            cs = q1;
            i++;
         }
         else if (input[i] == 'b')
         {
            cs = q2;
            input[i] = 'Y';
            i--;
         }
         else
            cs = qr;
         break;
      case q2:
         if (input[i] == 'Y' || input[i] == 'a')
         {
            cs = q2;
            i--;
         }
         else if (input[i] == 'X')
         {
            cs = q0;
            i++;
         }
         else
            cs = qr;
         break;
      case q3:
         if (input[i] == 'Y')
         {
            cs = q3;
            i++;
         }
         else if (input[i] == '\0')
         {
            cs = q4;
            i++;
         }
         else
            cs = qr;
         break;
      }
      if (cs == qr || cs == q4)
      {
         break;
      }
   }
   if (cs == q4)
      printf("Accepted!!");
   else
      printf("Rejected!!");
}
