#include<stdio.h>
#include<stdlib.h>


int main(int argc, char* argv[]){
  FILE* fl=fopen(argv[1],"r");
  while(!feof(fl)){
    fputc(fgetc(fl),stdout);
  }
  fclose(fl);
  return 0;
}

//on ouvre en mode lecture fl qui sera argv[0]. ("Makefile")
//puis tant que feof(fl) (pas la fin du fichier):
//on ecrit sur la sortie standard stdout le charactere puis deplacement
//automatique du curseur
//<=>àfaire: fputc(fgetc(fl),stdout) puis à la fin (à la sortie);
//on n'oublie pas de ferme le fichier par: fclose(fl).
