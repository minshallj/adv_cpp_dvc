// jacob minshall
// names.cpp

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SIZE 50

void get_names(char * first, char * second);
void display(char * first, char * second);

int main()
{
  char *temp, *name_a, *name_b;

  name_a = (char*)malloc(sizeof(char) * SIZE);
  name_b = (char*)malloc(sizeof(char) * SIZE);

  get_names(name_a, name_b);
  display(name_a, name_b);

}

void get_names(char * first, char * second)
{
    char ch;
    int i = 0;
    while((ch = getchar()) != ',')// everything up to the comma
        first[i++] = ch;
    first[i] = '\0';
    while((ch = getchar()) == ' ')//should just be one space
        ;
    i = 0;
    second[i++] = ch; //not a space again
    while((ch = getchar()) != '\n')//until new line
        second[i++] = ch;

}

void display(char * first, char * second)
{
  if(strcmp(first, second) <= 0)
      printf("%s, %s\n", first, second);
  else
      printf("%s, %s\n", second, first);
}
