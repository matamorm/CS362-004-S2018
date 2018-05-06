#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    //utilize ascii values from 32 to 126
    //range includes values of tested characters
    char asciiValue = (rand() % (126 - 32 + 1)) + 32;

    return asciiValue;
}

char *inputString()
{
    //variables to create string
    char *str;
    int strSize = 6;

    //variables for the loop
    int i;    
    char asciiValue;

    //allocate space for the string
    str = (char *) malloc (strSize);

    //loop generates characters for string
    for (i = 0; i < strSize - 1; i ++)
    {
	//utilize ascii values from 97 to 122
	//range includes lower case letters for "reset"
	asciiValue = (rand() % (122 - 97 + 1)) + 97;
	str[i] = asciiValue;
    }

    //include 'new line' for testing
    str[strSize - 1] = '\0';

    return str;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
