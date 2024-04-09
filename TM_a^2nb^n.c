#include <stdio.h>
#include <conio.h>

enum states
{
   q0,
   q1,
   q2,
   q3,
   q4,q5,
   qr
};

int main()
{
   char input[100];
   enum states current_state = q0;
   int i;
   for (i = 0; i < 100; i++)
   {
      input[i] = '\0';
   }
   printf("------Lab Report by Manjil Gautam (28193/078) -------\n");
   printf("Enter string: ");
   scanf("%s", input);
   i = 0;
   while (1)
   {
      switch (current_state)
      {
      case q0:
         if (input[i] == 'a')
         {
            current_state = q1;
            input[i] = 'X';
            i++;
         }
         else if (input[i] == 'Y')
         {
            current_state = q4;
            i++;
         }
         else
            current_state = qr;
         break;
      case q1:
         if (input[i] == 'a')
         {
            current_state = q2;
            input[i] = 'X';
            i++;
         }
         else
            current_state = qr;
         break;
      case q2:
         if (input[i] == 'a' || input[i] == 'Y')
         {
            current_state = q2;
            i++;
         }
         else if (input[i] == 'b')
         {
            current_state = q3;
            input[i] = 'Y';
            i--;
         }
         else
            current_state = qr;
         break;
      case q3:
         if (input[i] == 'Y' || input[i] == 'a')
         {
            current_state = q3;
            i--;
         }
         else if (input[i] == 'X')
         {
            current_state = q0;
            i++;
         }
         else
            current_state = qr;
         break;
      case q4:
         if (input[i] == 'Y')
         {
            current_state = q4;
            i++;
         }
         else if (input[i] == '\0')
         {
            current_state = q5;
            i++;
         }
         else
            current_state = qr;
         break;
      }
      if (current_state == qr || current_state == q5)
      {
         break;
      }
   }
   if (current_state == q5)
      printf("Accepted!!");
   else
      printf("Rejected!!");
}
