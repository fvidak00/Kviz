#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

FILE *f,*g;
char p[200];
char a[200];
char b[200];
char c[200];
char d[200];
int t[101];
int i,r,br=0,j;
char o;

int x;
FILE *z;

main()
{
      
      f=fopen("Pitanja.dat","r");
      g=fopen("Odgovori.dat","r");
      for (i=1;i<=63;i++)
          fscanf(g,"%d", &t[i]);

      z=fopen("br.dat","r");
      fscanf(z,"%d",&x);
      fclose(z);
      z=fopen("br.dat","w");
      x=x+1;
      fprintf(z,"%d",x);
      fclose(z);
      
      for (i=1;i<=10;i++)
      {
          r=rand()%63+1;
          r=r+x;
          if (r>63)
             r=r-63;
          j=r;
          r=(r-1)*1000;
          fseek(f,r,SEEK_SET);
          fgets(p,200,f);
          fgets(a,200,f);
          fgets(b,200,f);
          fgets(c,200,f);
          fgets(d,200,f);
          ponovno: 
          printf("\n%d.%s\nA)%s\nB)%s\nC)%s\nD)%s\n\n", i,p,a,b,c,d);
          o=getch();
          if (o=='a' || o=='A')     
          {   
              if (t[j]==1)  
                 br++;
          }
          else if (o=='b' || o=='B')     
          {   
              if (t[j]==2)  
                 br++;
          }
          else if (o=='c' || o=='C')     
          {   
              if (t[j]==3)  
                 br++;
          }
           else if (o=='d' || o=='D')     
          {   
              if (t[j]==4)  
                 br++;
          }
          else 
          {
               printf("\nPonovite upis odgovora (a,b,c,d)!");
               goto ponovno;
          }
          printf("\n\n\n\n\n");
      }
      
      if (br<=2)
         printf("Tesko da je moglo gore. (%d/10)",br);
      else if (br<=4)
              printf("Dovoljan, dva. (%d/10)",br);
      else if (br<=6)
              printf("A oko pola. (%d/10)",br);
      else if (br<=8)
              printf("Umalo pa sve. (%d/10)",br);
      else if (br<=10)
              printf("Ide tebi ovo. (%d/10)",br);
      
      fclose(f);
      fclose(g);

      if (x>=63)
      {  
         x=0;
         z=fopen("br.dat","w");
         fscanf(z,"%d",&x);
         fclose(z);
      }
      getch();
}
