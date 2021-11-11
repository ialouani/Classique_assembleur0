#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char* argv[]){
  float terme=1;
  int n=1;
  while(n<=128){
    terme=terme*2+1;
    printf("s_{%d}=%.2f\n",n,terme);
    n++;
  }
  float terme2=1;
  int nm=1;
  int m=0;
  while(nm<=128 && (int)terme2%2!=0){
    terme2=2*terme2+1;
    m=nm;
    nm++;
  }
  //sortie avant n<=128 car terme2%2==0.(resultant du calcul de s_{m})
  printf("-------------%d\n",m);
  //AVEC: s_{24} pair.
  //DONC: la parité cava jusqu'à m=23.
  printf("Donc la taille de la mantisse est donnée explicitement par:%d\n",m-1);
  printf("Application pour un double(double float):\n");
  double terme_a=1;
  int n2=1;
  int nm2=0;
  while((long int)terme_a %2 ==1){
    nm2=n2;
    printf("%.2lf\n",terme_a);
    terme_a =2*terme_a +1;
    n2++;
  }
  printf("\n%.2lf--%d\n\n",terme_a,n2);
  printf("%ld--%d\n\n",(long int)terme_a,(long int)terme_a %2 ==0);
  printf("la taille de la mantisse pour les valeurs de type double est:%d\n",nm2-1);//nm2-1 est telque: s_{nm2} est pair donc E(m;/double/)===nm2-1 donc 52.
  //remarque: pour avoir de bons résultats, il faut que le type casting (int)
  //se transforme en long int sinon on aurait une taille de mantisse m petite
  //car ça va dépasser les 4 Bytes de int et on va basculer du coup sur du
  //négatif donc ça peut entraîner des erreurs(déjà testé) . %ld pour long int.

  //c'est le meme que n2-2(n2-1 est nm2 le premier pair et n2 suivant à calculer
  //est stoppé car n2-1 est pair donc ne pas calculer n2 et la taille de la
  //mantisse est n2-2(===nm2) soit pour des double: 52 bits.

  
  printf("%d\n",!isfinite(2.0));//test si 2.0 est infini donc 0.
  //2.0 est fini.
  double terme_a2=1;
  int nf=1;
  int nf2=0;
  double terme_transit=1;
  while(isfinite(terme_a2)){
    nf2=nf;
    terme_transit=terme_a2;
    terme_a2=2*terme_a2+1;
    nf++;}
  //sortie: s_{nf2} est infini.
  //donc nf2-1===nf-2 est max{n::/s_{n}!==Inf/}.
  printf("%d--%.2f\n",nf2-1,pow(2,11)-1);
  printf("%lf\n",terme_transit);//représente s_{nf2-1}
  //nf2-1 vaut 1022 et on remarque normalement que s_{nf2-1}=s_{1022}!=Inf
  //avec s_{1023} Inf mais puisque m(s_{1023})!=0 alors s_{1023} est approchée
  //par la machine en Inf alors que c'est pas Inf par calcul. Donc typiquement
  //ici et de la maniere que precedemment, la valeur maximale représentable
  //sera s_{1023}!=Inf (POUR AVOIR L'EXPOSANT(!=INF|/;/|))
  //car c'est juste à s_{1024} où on aura le vrai Inf au sens de l'exposant
  //donc la valeur maximale de l'exposant en terme de nombre représentable est
  //issue de s_{1023} qui contient le 2^(1023) dans l'ecriture de IEEE754
  //=>valeur maximale de l'exposant est directement 1023.
  printf("--Cela représente le plus grand nombre float(avec une partie entiere si on s'interesse unqiuement aux nombres >=0) codé en 64 bits pouvant etre compris par la machine sans plus ou moins (en valeur absolue) s'approcher de l'infini.");
  printf("\n\n\n--------FIN EXO2.\n");
  return 0;
}
