#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

FILE *f;
struct pitanja
{
       char p[200];
       char a[200];
       char b[200];
       char c[200];
       char d[200];       
}q;
int i;

main()
{
      f=fopen("Pitanja.dat","a+");
      gets(q.p);
      gets(q.a);
      gets(q.b);
      gets(q.c);
      gets(q.d);
      fwrite(&q,sizeof(struct pitanja),1,f);
      fclose(f);
}
