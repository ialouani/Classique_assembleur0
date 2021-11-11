#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char* argv[]){
  char a=0;
  char b;
  while(a>=0){b=a;a++;}
  printf("intervalle valeurs représentbales pour le type CHAR:");
  printf("[%d;%d]\n",a,b);
  printf("verification:\n");
  printf("%f\n",pow(2,7)-1);
  printf("intervalle valeurs représentbales pour le type SHORT:");
  short c=0;
  short d;
  while(c>=0){d=c;c++;}
  printf("[%d;%d]\n",c,d);
  printf("verification:\n");
  printf("%f\n",pow(2,15)-1);
  printf("intervalle valeurs représentbales pour le type INT:");
  int e=0;
  int f;
  while(e>=0){f=e;e++;}
  printf("[%d;%d]\n",e,f);
  printf("verification:\n");
  printf("%f\n",pow(2,31)-1);
  unsigned char g=0;
  g++;
  unsigned char h;
  while(g!=0){h=g;g++;}
  printf("intervalle valeurs représentbales pour le type UNSIGNED CHAR:");
  printf("[%d;%d]\n",g,h);//a vaut zéro ici.
  printf("verification valeur maximale d'un unsigned char:\n");
  printf("%f\n",pow(2,8)-1);
  printf("TEST SUIVANT:..\n");
  char x=120;
  printf("valeur de x a cet etape: %d\n",x);
  x=x+120;
  printf("valeur de x a cet etape: %d\n",x);
  x=x-75;
  printf("valeur de x a cet etape: %d\n",x);
  x=x-87;
  printf("valeur de x a cet etape: %d\n",x);
  return 0; 
}
