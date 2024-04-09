#include <stdio.h>
#include <conio.h>

enum states
{
   q0,
   q1,
   q2,
   q3,
   q4,
   q5,
   q6,
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
   printf("------Lab Report by Manjil Gautam (28193/078)-------\n");
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
            input[i] = '\0';
            i++;
         }
         else if (input[i] == 'b')
         {
            cs = q4;
            input[i] = '\0';
            i++;
         }
         else if (input[i] == '\0')
         {
            cs = q6;
            i++;
         }
         else
            cs = qr;
         break;
      case q1:
         if (input[i] == 'a' || input[i] == 'b')
         {
            cs = q1;
            i++;
         }
         else if (input[i] == '\0')
         {
            cs = q2;
            i--;
         }
         else
            cs = qr;
         break;
      case q2:
         if (input[i] == 'a')
         {
            cs = q3;
            input[i] = '\0';
            i--;
         }
         else if (input[i] == '\0')
         {
            cs = q6;
            i++;
         }
         else
            cs = qr;
         break;
      case q3:
         if (input[i] == 'a' || input[i] == 'b')
         {
            cs = q3;
            i--;
         }
         else if (input[i] == '\0')
         {
            cs = q0;
            i++;
         }
         else
            cs = qr;
         break;
      case q4:
         if (input[i] == 'a' || input[i] == 'b')
         {
            cs = q4;
            i++;
         }
         else if (input[i] == '\0')
         {
            cs = q5;
            i--;
         }
         else
            cs = qr;
         break;
      case q5:
         if (input[i] == 'b')
         {
            cs = q3;
            input[i] = '\0';
            i--;
         }
         else if (input[i] == '\0')
         {
            cs = q6;
            i++;
         }
         else
            cs = qr;
         break;
      }
      if (cs == qr || cs == q6)
      {
         break;
      }
   }
   if (cs == q6)
      printf("Accepted!!");
   else
      printf("Rejected!!");
}
