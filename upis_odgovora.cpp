#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

FILE *g;
int t;

main()
{
      g=fopen("Odgovori.dat","a+");
      scanf("%d",&t);
      fprintf(g,"%d\n", t);
      fclose(g);
}
