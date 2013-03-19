#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;
#define SIZE 50
int my_pal(char *);
int char_len(char *);


int main()
{
  char temp;
  char * c_str = new char[SIZE];
  char ** c_str_p;
  c_str_p = (char**)malloc(SIZE * sizeof(char*));
  for(int i = 0; i < SIZE; i++)
    c_str_p[i] = (char*) malloc(SIZE * sizeof(char));

  int pal_count = 0, pass;
  while(1){
    cout << "Please enter a string to check for a palindrom(-1 to quit): ";
    pass = 1;
    /* do{
    cin >> temp; //can you do this?
    if(pass++ != 1)*/
    while(temp=getchar()){
      if (temp == '\n' || temp == '\r') break;
      if(pass++ == 50) break;
      c_str[pass-2] = temp;
    }
    //    printf("%s\n", c_str);
    if(strcmp(c_str, "-1") == 0) break;

    if(my_pal(c_str)){
      cout << "A pal" << endl;
      strcpy(c_str_p[pal_count++], c_str);
    }
    for(int i = 0; c_str[i]; i++) c_str[i] = '\0';
    //else
    //    cout << "No pal" << endl;
  }
  cout << "Pal count: " << pal_count << endl;
  for(int i = 0; i < pal_count; i++){
    for(int j = 0; c_str_p[j]; j++)
      printf("%c", c_str_p[i][j]);
    cout << endl;
  }

  return 0;
}

int my_pal(char * str)
{
    int size = char_len(str);

    for(int i = 0, j = size-1; i <= j;)
        if(str[i++] != str[j--])
            return 0;

    return 1;
}

int char_len(char * str)
{
    int size = 0;

    while(str[size++])
        ;

    return size -1;
}
