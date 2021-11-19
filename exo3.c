#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 10

void affiche(int tableau[],int len){
  int i=0;
  while(i<len){
    printf("%d\t",tableau[i]);
    i++;}
  printf("\n");
  return ;}
int somme_tab(int len, int tab[]){
  int i=0;
  int somme=0;
  while(i<len){
    somme+=tab[i];
    i++;}
  return somme;
}

int main(int argc, char* argv[]){
  printf("calcul avec methode 1 de l'expression de l'exo3:\n");
  //on doit calculer les puissances de 2 jusqu'à la puissance max N.
  /*int N=atoi(argv[1]);//passage de N via le terminal de commandes.*/
  int somme1=1;//<=>2^0
  int n=2;
  somme1+=2;
  int somme11=2;
  int somme22=3;
  while(n<=N){
    //terme numero 1 (pow(2,i=1)) à ajouter
    somme1+=2*(somme11);
    somme11=2*somme11;
    printf("---%d\t%d\n",n,somme1);
    //2*somme1 représente la prochaine puissance ici 2^1 à ajouter
    //à somme1 qui est égale à 1(2^0) au début.
    n++;//somme1 represente la valeur de la somme lorsque N=n-1 à cet étape.
    //donc si à la sortie n>N donc la derniere valeur correspond à N+1-1 qui
    //est N ce qui est correct.
  }
  int somme2=1;
  int m=2;
  somme2+=3;
  printf("---------------------------------------\n");
  while(m<=N){
    somme2+=3*(somme22);
    somme22=3*somme22;
    printf("---%d\t%d\n",m,somme2);
    m++;
  }
  printf("la 1ere somme vaut:%d\n",somme1);
  printf("la 2ieme somme vaut:%d\n",somme2);
  printf("le resultat est le suivant: %d\n",somme1*somme2);
  printf("comparaison avec le vrai résultat (somme termes suite geometrique):\n");
  double rslt1=pow(2,N+1)-1;
  double rslt2=(pow(3,N+1)-1)/2;
  printf("somme1 vaut:%.2lf\n",pow(2,N+1)-1);
  printf("somme2 vaut:%.2lf\n",(pow(3,N+1)-1)/2);
  printf("le resultat à comparer avec le precedent est :%.2lf\n",rslt1*rslt2);
  printf("------------------------------\n\n\n");
  printf("Calcul de la somme avec la méthode numéro (2):\n");
  //on a deja la valeur de somme2;
  int somme_rslt_p2=somme2;
  int rslt_final=somme_rslt_p2;
  int somme33=2;
  int nm=0;
  while(nm<N){
    rslt_final+=somme33*somme_rslt_p2;
    nm++;//en N=1 ça vaudrait rslt_final
    somme33=2*somme33;
  }
  printf("%d\n",rslt_final);
  printf("fin des 2 méthodes .\n\n\n\n");
  //calcul via somme des elements du tableau telque ce tableau en question
  //represente a chaque indice parametre la puissance de 2/3 suivant ~cet indice.
  //pour N=10 il faut en plus de 1 (2^0===3^0) (max)11 valeurs soit int t1:t2[12];
  int t1[12];
  int t2[12];
  t1[0]=1;
  t2[0]=1;
  t1[1]=2;
  t2[1]=3;
  int n1=1;
  int n2=1;
  while(n1<N){
    t1[n1+1]=2*t1[n1];
    t2[n2+1]=3*t2[n2];
      n1++;
      n2++;
  }
  affiche(t1,N+1);
  affiche(t2,N+1);
  //ça marche; actuellement on dispose des 2 tableaux t1 et t2
  //telque pour tout n<=N: 2**n===t1[n] ; 3**n===t2[n];;
  printf("la 1ere valeur doit etre:%d\n",somme_tab(N+1,t1));
  printf("la 2ieme valeur doit etre:%d\n",somme_tab(N+1,t2));
  printf("reprise de la 1ere methode:\n");
  printf("le resultat est le produit de la somme des 2 tableaux t1 et t2:%d\n",somme_tab(N+1,t1)*somme_tab(N+1,t2));
  printf("reprise de la deuxieme methode:\n");
  int somme_import=somme_tab(N+1,t2);//somme des 3^i pour 0<=i<=N.
  int somme_RSLT=0;
  int inter=1;
  int nm2=0;
  while(nm2<=N){
    somme_RSLT+=inter*somme_import;
    inter=2*inter;
    //printf("--%d\t%d\t%d\n",nm2,inter,somme_RSLT);
    //on voulait via un test voir ce qui clochait.
    nm2++;
  }
  printf("la somme résultante de la distribution en utilisant les tableaux de puissances sera la suivante:\n\t\t%d\n",somme_RSLT);
  //a voir la remarque 5 de l'exo2.(!!!)
  float somme1_a=1;
  int nf=2;
  somme1_a+=2.13;
  float somme11_a=2.13;
  float somme22_a=3.21;
  while(nf<=N){
    somme1_a+=2.13*(somme11_a);
    somme11_a=2.13*somme11_a;
    //printf("---%d\t%d\n",nf,somme1_a);
    nf++;
  }
  float somme2_a=1;
  int mf=2;
  somme2_a+=3.21;
  printf("---------------------------------------\n");
  while(mf<=N){
    somme2_a+=3.21*(somme22_a);
    somme22_a=3.21*somme22_a;
    //printf("---%d\t%d\n",mf,somme2_a);
    mf++;
  }
  printf("%.2f--%.2f\n",somme1_a,somme2_a);
  printf("rslt produit methode 1:%.2f\n",somme1_a*somme2_a);
  printf("%.2f * %.2f=%.2f\n",(float)(pow(2.13,N+1)-1)/(2.13-1),(float)(pow(3.21,N+1)-1)/(3.21-1),((float)(pow(2.13,N+1)-1)/(2.13-1)) * ((float)(pow(3.21,N+1)-1)/(3.21-1)));
  printf("%.2f--%.2f\n",(float)(pow(2.13,N+1)-1)/(2.13-1),(float)(pow(3.21,N+1)-1)/(3.21-1));
  printf("%.2f\n",3622.36*168718.20);
  printf("%d\n",33.45454545454545454545454==33.454545454545454545454548);
  //ça donne 1 car underflow (plus de 23 chiffres apres la virgule)
  //et puisque float pas double donc se limite a la comparaison
  //en virgule FLOTTANTE des 23 premiers chiffres apres la virgule..///
  return 0;
}


/*Le calcul, juste avec 2 et 3, devient faux si on rajoute quelques chiffres apres la virgule. Ils necessitent davantage de
bits dans la mantisse, et les arrondis des puissances arrivent plus vite (le nombre de bits apres la virgule augmente
de facon arithmetique à chaque produit), et dépasse les 23 bits de la mantisse flottante. Les arrondis sont différents
dans les 2 cas. Dans le premier cas, les deux nombres qu’on ajoute sont tres pres l’un de l’autre. Dans le second cas,
on va ajouter 1 ∗ 3 N avec 2 ∗ 1, ce qui cause des arrondis.*/

//explication et remarque importante:

/*Avec le calcul flottants, l’addition n’est pas commutative. L’exemple vu dans l'exercice precedent et qui servira à la comprehension du but de cet exo(exo3) donne −1 comme résultat, et non 0. La raison
est qu’on fait la somme entre des grandes et de petites valeurs, et le calcul est approché. Pour faire le bon calcul, il
faudrait parcourir la liste dans le meme sens pour l’addition et la soustraction. En général, il ne faut pas tester un
nombre flottant avec l’opérateur “==”, car les calculs sont approchés.*/


