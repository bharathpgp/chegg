
#include<stdio.h>
#include<string.h>

// Record structure decleration

typedef struct record {
   char name[20];
   float grade1, grade2, grade3;
} Record;

int main()
{
   /* a. Declare a new Record variable std2 */
   Record std2;

   /* b. Set the name of std2 to "David" */
   strcpy(std2.name,"David");

   /* c. Print the name of std2 to the standard output */
   printf("%s", std2.name);

   /* d. Declare a pointer named ptr to Record and make it point to std2 */
   Record *ptr = &std2;

   /* e. Use the pointer ptr to set grade1 of std2 to 77.6 using the arrow-notation */
   ptr->grade1 = 77.6;

   /* f. Use the pointer ptr and the * operator to set the grade2 of std2 to 87.3 */
   ptr->grade2 = 87.3;

   /* g. Update grade3 of std2 by reading a value into it from the standard input */
   scanf("%f", &std2.grade3);

   return 0;
}
