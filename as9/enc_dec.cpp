#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void usage();
void crypt(FILE * fp, char ** argv);

int main(int argc, char ** argv)
{
	if(argc < 4)
		usage();

	FILE * fp = fopen(argv[1], "r");
	if(fp == NULL)
		usage();

	if(argv[3][0] != 'c' && argv[3][0] != 'd')
		usage();

	crypt(fp, argv);

	fclose(fp);

	return 0;
}

void usage()
{
	cout << "crypt <filename> <passwd> <c | d>" << endl;
	exit(1);
}

void crypt(FILE * fp, char ** argv)
{
	FILE * outf;
	int len = strlen(argv[2]), i = 0;
	char temp, *pch, *f_name = (char*)malloc(80);
	if(argv[3][0] == 'c'){
		strcat(f_name, argv[1]);
		strcat(f_name, ".crypt");
	}
	else if (argv[3][0] == 'd'){
		if((pch = strstr(argv[1], ".crypt")) != NULL)
			pch[0] = '\0';
		strcat(f_name, argv[1]);
		strcat(f_name, ".decrypt");
	}

	outf = fopen(f_name, "w");


  while(fscanf(fp, "%c", &temp) != EOF){
  	temp ^= argv[2][i++ % len];//rotates through password
  	fprintf(outf, "%c", temp);
  }

  fclose(outf);
}