#include <stdio.h>
#include <stdlib.h>
#include <string.h>



                        //AYADI NAILA ** KHELOUFI MERIEM  -- TP ALGO VECTEURS,MATRICES,listes chainees//

// fonction qui libere lespace memoire allouer a une matrice//
void liberer(int **A,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		free(A[i]);
	}
	
	free(A);
		
}
//***********************PART1************************//

//*********** CREATION D'UNE MATRICE*************//
void creat_Mat(int **A,int N,int M)
{    
   int i,j;

    
    for (i=0;i<N;i++)
    {
    	for (j=0;j<M;j++)
    	{
    		printf("\n Donnez lelement A[%d][%d] : ",i,j);
    		scanf("%d",&A[i][j]);
		}
}
}

//************** AFFICHAGE D'UNE MATRICE *******************//
void affich_mat(int **A, int N, int M)
{
	int i,j;
	for (i=0;i<N;i++)
    {
    	for (j=0;j<M;j++)
    	{
    		printf("%d \t ",A[i][j]);

	    }
	printf("\n");

    }
}

// **************ADDITION DE DEUX MATRICES***************//
int  **add_mat (int **A, int **B,int N,int M)
{	int i,j;
	int **C;
  
    //allocation de la matrice resultante
    
     C=(int **) malloc(N*sizeof(int*));
    for (i=0; i<N; i++)
    C[i]=(int *) malloc(M*sizeof(int));
    
  printf("\n La matrice apres l'addition: \n");
  for(i = 0 ; i < N; i++)
  {
    for(j=0; j < M; j++)
    {
    
      C[i][j] = A[i][j] + B[i][j];
      printf(" %d \t",C[i][j]);
    }
    printf("\n");
}
   
   return C;

}

 // ****************SOUSTRACTION DE DEUX matrices ***********//
int  **sous_mat (int **A, int **B,int N,int M)
{	int i,j;
	int **C;
	 
	//allocation de la matrice resultante
	
	C=(int **) malloc(N*sizeof(int*));
    for (i=0; i<N; i++)
    C[i]=(int *) malloc(M*sizeof(int));
	
  printf("\n La matrice apres la soustraction\n");
  for(i = 0 ; i < N; i++)
  {
    for(j=0; j < M; j++)
    {
    
      C[i][j] = A[i][j] - B[i][j];
      printf("%d \t", C[i][j]);
    }
    printf("\n");
}
   
  return C;
}

//***************** MULTIPLICATION PAR UN NOMBRE *************//
int **mult_nbr(int **A, int X, int N, int M)
{	
   int i,j;
   
   	printf("\n Donnez un nombre entier X:");
    scanf("%d",&X);
    printf("\n la matrice apres la multiplication: \n");
for (i=0; i<N; i++)
{   
   for(j=0; j<M; j++)
      {
      	A[i][j]= X * A[i][j];
      	printf("%d \t", A[i][j]);
	  }
	  printf("\n");
}
   return A;
}

// ************ MULTIPLICATION DE DEUX MATRICES ************* //
 
  int **mult_mat(int **A, int **B,int N, int M, int P)
  
{
    int i,j,k;
    int **C;
    
    //allocation de la matrice resultante
	      C=(int **) malloc(N*sizeof(int*));
          for (i=0; i<N; i++)
          C[i]=(int *) malloc(P*sizeof(int));
  
  for(i=0;i<N;i++)
    {
        for(j=0;j<P;j++)
        {  
            C[i][j]=0;
            
            for(k=0;k<M;k++)
            {
                C[i][j] = C[i][j]+( A[i][k] * B[k][j] );
            
            }
            
	        printf("\n");
	    }
              
    }
    
     	printf("\n Le produit des deux matrices: \n");
            for(i=0;i<N;i++)
			{
               printf("\n");
               for(j=0;j<P;j++)
               {
               	   printf("  %d \t", C[i][j]);  
			   }
             printf("\n"); 
               
             
            }
    
	   return C;
}



//INVERSE MATRICE


void InverseMat(int n, int **A)
{
   int **temp;
   int j,i,k;
   temp=(int**)malloc(n*sizeof(int));
   for(i=0;i<n;i++)
 {
     temp[i]=(int*)malloc(n*sizeof(int));
     for(j=0;j<n;j++)
   {
       temp[i][j]=0;
    }
  }

   for(i=0;i<n;i++)
    {

       for( j=0;j<n;j++)
     {
         temp[i][i]=1/A[i][i];
         if(j!=i)
       {
            temp[i][j]=-A[i][j]/A[i][i];
       }
      for( k=0;k<n;k++)
     {

     if(k!=i)
     {
        temp[k][i]=A[k][i]/A[i][i];
     }
    
    if(j!=i &&k!=i)
    {
        temp[k][j]=A[k][j]-A[i][j]*A[k][i]/A[i][i];
     }
     
    }

  }
     for( i=0;i<n;i++)
      {
            for( j=0;j<n;j++)
            {
                A[i][j]=temp[i][j];
            }

       }
     }


}

    
 
//************************PART 2*********************************//
 
 //**********transpose d'une matrice***********//
void transposee_mat (int **A, int n, int m)
{
    int i,j;
    int **c;
    
    //allouer un espace pour la matrice intermediaire//
    c=(int**) malloc(m*sizeof(int*));
    for (i=0;i<m;i++)
    c[i]=(int*) malloc(n*sizeof(int));
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        c[j][i]=A[i][j];
    }
      printf("la transposee de la matrice A est c \n ");  
      affich_mat(c,m,n);

}
 

 
 //  **********trie d'une matrice**************//
 
                          //** 1-1:tri par selection ordre croissant**//
	void trimat_selection_croi(int *t,int n)
{
	int max,i,m,posmax;
    int k=0;
	m=n;

	while(n>0)
	{    
		max=t[0];
		posmax=0;
		
		for(i=0;i<n;i++)
		{
			if(t[i]>max)
			{
			max=t[i];
			posmax=i;
		    }
		}
		
		    for(i=posmax;i<n;i++)
		    {
		    	t[i]=t[i+1];
		    
		    
			}
			t[n-1]=max;
			n--; 
			printf("\n");
			
	  //**affichage des etapes**//
	  
			printf("\n letape %d :\n",k);
			k++;
			for(i=0;i<m;i++)
			{    	
				printf("%d \t",t[i]);
			    
			}
			
		
	}
}

                             //*** 1-2:tri par selection ordre decroissant***//
  
     void trimat_selection_decroi(int *t,int n)
{  
     int min,i,m,posmin,k=0.;

	m=n;

	
	while(n>0)
	{
		min=t[0];
		posmin=0;
		for(i=0;i<n;i++)
		{
			if(t[i]<min)
			{
			min=t[i];
			posmin=i;
	     	}
		}
		    for(i=posmin;i<n;i++)
		    {
		    	t[i]=t[i+1];
		    	
			}
			t[n-1]=min;
			n--;
			printf("\n");
		    printf("\n letape %d  :\n",k);
			k++;
		    
			for(i=0;i<m;i++)
			{    	
				printf("%d \t",t[i]);
			    
			}
			
			
		
	}
	
}
 
                 //** 2-1: tri par permutation ordre croissant**//
			
void trimat_permu_croi(int *t,int n)
{  
	int i,j,k,h=0,x;

	
	for(i=0;i<n-1;i++)
	    
	{
	   for(j=i+1;j<n;j++)
		{
			if(t[j]<t[i])
			{
				x=t[i];
				t[i]=t[j];
				t[j]=x;
			}
		}
	
	
	 	printf("\n");
		    printf("\n letape %d :\n",h);
			h++;
		    
			for(k=0;k<n;k++)
			{    	
				printf("%d \t",t[k]);
			    
			}
	
	}	
}
                   
				   //** 2-2: trie par permutation ordre deccroissant**//

void trimat_permu_decroi(int *t,int n)
{  
	int i,j,k,h=0,x;
	
	for(i=0;i<n-1;i++)
	    
	{
	   for(j=i+1;j<n;j++)
		{
			if(t[j]>t[i])
			{
				x=t[i];
				t[i]=t[j];
				t[j]=x;
			}
		}
	
	
	 	printf("\n");
		    printf("\n letape %d :\n",h);
			h++;
		    
			for(k=0;k<n;k++)
			{    	
				printf("%d \t",t[k]);
			    
			}

	}
 
}
                  //** 3-1: tri par insertion croissant **//
                  
                  
 void trimat_inser_croi(int *t,int n)
{
	int x,i,j,k,h=0;

	
	for(i=1;i<n;i++)
	{
		x=t[i];
		j=i-1;
		while(j>=0 && t[j]>x)
		{
			t[j+1]=t[j];
			j--;
		}
		t[j+1]=x;
		printf("\n");
			printf("\netape %d :\n",h);
	
		    printf("\t");
			for(k=0;k<n;k++)
			{    	
				printf("%d \t",t[k]);
			    
			}	h++;
		
	}
	
}
                  
                   //** 3-1: tri par insertion decroissant **//
                  
void trimat_inser_decroi(int *t,int n)
{
	int x,i,j,k,h=0;

	
	for(i=1;i<n;i++)
	{
		x=t[i];
		j=i-1;
		while(j>=0 && t[j]<x)
		{
			t[j+1]=t[j];
			j--;
		}
		t[j+1]=x;
		printf("\n");
			printf("\netape %d :\n",h);
	
		    printf("\t");
			for(k=0;k<n;k++)
			{    	
				printf("%d \t",t[k]);
			    
			}	h++;
	}
	
}
                  
          //**4-1:tri par bulle croissant**//

 
 void trimat_bulle_croi(int *tab,int n)
{
	  int i,k,x,h=0,j;
	  
	  	for(j=0;j<n-1;j++)
	  	{
	  		
	  	for(i=0;i<n-1;i++)
	  	{   
	  	   
	  	   
	  		if(tab[i]>tab[i+1])
	  		{   
	  			x=tab[i];
	  			tab[i]=tab[i+1];
	  			tab[i+1]=x;
	  			
	  			
	  			printf("\n");
	  			
	  			printf(" \n letap : %d \n\n",h);
	  			printf("\t");
	  			
	  			for(k=0;k<n;k++)
	  			{
	  				   printf(" %d   \t  ",tab[k]);
				}
	  			
	  			h++; 
	            
			  }
			 
	   	  } 	
     }
		  	  
	}
	
       //**4-1:tri par bulle decroissant**//
void trimat_bulle_decroi(int *tab,int n)
{
	  int i,k,x,h=0,j;
	  	for(j=0;j<n-1;j++)
	  	{ 
	  	for(i=0;i<n-1;i++)
	  	{   
	  	 
	  	   
	  		if(tab[i]<tab[i+1])
	  		{   
	  			x=tab[i];
	  			tab[i]=tab[i+1];
	  			tab[i+1]=x;
	  			
	  			
	  			printf("\n");
	  			printf("etape : %d \n\n",h);
	  			printf("\t");
	  			for(k=0;k<n;k++)
	  			{
	  				printf("%d",tab[k]);
				  }
	  			
	  			h++; 
	            
			  }
			 
	   	}   
	 }
		  
	}
	
 
 // 3-  **********calcul du vecteur max ligne************//
 
 int *maxligne(int **A , int n , int m)
 { int i = 0,j; 
   int max ; 
   int *v;
   
   v = (int*) malloc(n*sizeof(int));
 	  
  while (i < n) 
  {  
     max=A[i][0];
    for ( j = 0; j < m; j++) 
  { 
     if (A[i][j] > max) 
    { 
      max = A[i][j]; 
    } 
  }
     v[i] = max; 
      i++;
   }
       //affichage 
       
    	for(i=0;i<n;i++)
 	 	{
 	 		printf("%d \t ",v[i]);
		}
 	return v;
}


 // 4-   **********calcul du vecteur max colonne************//
 
 int *maxcolonne(int **A , int m , int n)
 { int i,j=0; 
   int max; 
   int *v;
   
   v = (int*) malloc(m*sizeof(int));
 	  
  while (j < m) 
  { 
    max=A[0][j];
    
    for ( i = 0; i < n; i++) 
  { 
      if (A[i][j] > max) 
   { 
      max = A[i][j];
   } 
   
  }
     v[j] = max; 
      j++;
   }
     //affichage
     
    	for(j=0;j<n;j++)
 	 	{
 	 		printf("%d \t ",v[j]);
		}
 	return v;
}
 


// 5-   *********extraction d'une sous matrice*************/

/* Extraction des sous matrice B de taille K et L a  partir de la
   matrice A de dimension N et M */
void sousmatrice( int **A, int N, int M, int K, int L )
{
    int i, j, P=0, C=0;
    int **B;

    /* P est l'indice de debut de ligne d'une suite de sous matrice
       C est l'indice de debut de colones de chaque sous matrice */

    while( P <= N-K )
    {
        /* allocation de la sous matrice */
          B=(int **) malloc(K*sizeof(int));
          for (i=0; i<K; i++)
          B[i]=(int *) malloc(L*sizeof(int));

        /* remplissage de la sous matrice */
        for( i=0; i<K; i++ )
            for( j=0; j<L; j++ )
                B[i][j] = A[i+P][j+C];

        if( C < M-L )
            C++;
        else
        {
            C = 0;
            P++;
        }

        /* affichage de la sous matrice */
        printf("La sous-matrice: \n");
        affich_mat(B, K, L);

    }

}
//***************************************PART 3********************************************/

   char *text() 
  { fflush(stdin); 
  char * ch ; 
  ch=(char*)malloc(500*sizeof(char)); 
  printf("       *********** veuillez saisir  votre text************** \n\n"); 
  fflush(stdin); 
  //fgets(ch,500,stdin); 
  gets(ch); 
  return ch ; 
  } 
  
  // fonction qui calcule le nombre de mot//
  int nombre_mot(char *ch)
{   int nb,i,l;
	nb=0;  l=strlen(ch);
		   for(i=0;i<l;i++) 
		   {
		    if((ch[i] == ' ' && ch[i+1] != ' ') || ch[i+1] == '\0' ) 
			 nb++;
			}
			
			 printf("\n-cette chaine est constitue de %d mot- \n",nb); 
			 return nb;
}


  // *****construction de la matrice de mots*****//
  
 char **construit_mata(int nb, char *ch,int l) 
{ 
  char **A; 
  char *chh; 
  char *mot;
  char s[]=" ";
  int i=0; 
 
  A=(char**)malloc(nb*sizeof(char*)); 
	chh = strtok(ch, s);
  while(chh != NULL && (i<nb))
   { 
 
		 A[i]=(char*)malloc((strlen(chh))*sizeof(char));
		  strcpy(A[i],chh);
		   i=i+1; 
    	 chh = strtok(NULL, s);
	} 
	  return A; 
} 
	  
	  //*****affichage de la matrice***** //
	  
	  	void affich_mata(char **B, int nb) 
	{
	   int i; 
	   for(i=0;i<nb;i++)
	    { 
		printf(" le mot de la ligne %d est : %s \n \n ",i+1,B[i]);
		 }
	}

	  

 // **creation de la structure vecteur **//
 
  // declaration de la structure //
   // cest un vecteur d'enregistrement qui contient 2 champs//
   
 // definition d'un type liste : //
 
typedef struct element
{
	char info[20];
	struct element *svt;
	
}element, *pliste;

// definition de la structure ; //

typedef struct 
{
	char l1;
	char l2;
}lettre;

typedef struct 
{
	 lettre x;
	pliste tete;
	
}st;

 
// creation d'une liste en mode FIFO//

pliste creation_FIFO(pliste tete, char *ch )
{
	pliste p=NULL,q=NULL;
	int i;
 
   // on cree la tete si la liste est vide//
   
   if(tete==NULL)
   {
   	tete=(pliste)malloc(sizeof(element));
   	strcpy(tete->info, ch);
   	tete->svt=NULL;
   		 
   	
   }
	
	else
	{ 
	   	q=tete; 
	   	while(q->svt != NULL)
	   	{
	   		q=q->svt;
	   		
		}
		  p=(pliste)malloc(sizeof(element));
		  q->svt=p;
		  p->svt=NULL;
   	      strcpy(p->info, ch);

	}

	
	return tete;
}


st *creation_struct(char **A,int nb)
{ 
   st *V;
  char j,k;
  int i;
  char *ch;
  char c;
  pliste t;
	
  V=(st*)malloc(26*sizeof(st));
  
  printf(" \n creer votre structure ! \n\n");
  
  i=0;  j='a'; k='A';
  
  // initialiser toutes les listes de mots a NULL //
  while((i<26)&&(j<='z')&&(k<='Z'))
  {
  	 V[i].x.l1=j;
  	 V[i].x.l2=k;
  	 V[i].tete=NULL;
    j++;i++;k++;
  }
  
  //creation de la structure a partir de la matrice//
  int m;

   for(i=0;i<nb;i++)
   { 
    m=0; 	
   	ch=(char*)malloc(strlen(A[i])*sizeof(char));strcpy(ch,A[i]);
   		
   	  while(m<26)
   	  {  c=ch[0];
   	
   	  	if((c==V[m].x.l1)|| (c==V[m].x.l2))
   	  	{  
   	  		 V[m].tete=creation_FIFO( V[m].tete,ch);
   	  		
		}
	  m++;
	  }
   } 	
   return V;
  
}

//affichage de la structure//

void affichage_struct(st *V)
{  
    int i;
    pliste p=NULL;
	
	i=0;
	printf("     ************afiichage de la structure********** \n\n");
	
	while(i<26)
	{
		
		if(V[i].tete != NULL)
		{
				printf("  \n  %c  : \t  ", V[i].x.l1);
				p=V[i].tete;
		
		while(p!=NULL )
		{
			printf("%s -> ",p->info);
			p=p->svt; 
		}
		}
		
    	
	i++;
	}	
}

/// ajouter un mot a la structure ///

st *ajouter_mot(st *V,char *nvmot )
{
	int i;
	
   i=0;
   while(i<26)
   {
   	  if((nvmot[0]==V[i].x.l1)|| (nvmot[0]==V[i].x.l2))
   	  {
   	  	 V[i].tete=creation_FIFO(V[i].tete,nvmot);
 	  }
 	  
 	  i++;
   }
	
	return V;
}



///suppression dun mot de la liste ///

pliste supprimer(pliste tete,char *nvmot)
{
	
	pliste p,q,c;
	
	if(tete==NULL)   //cas ou la liste est vide//
	{
		printf(" \n\n cette liste est vide le mot neexiste pas.\n \n");
	}
	
    else
    { 
      //suppresions au debut//
      if(strcmp(tete->info,nvmot)==0)
	 {
		 p=tete;
		 tete=tete->svt;
		 free(p);
     }
   	 
   	 
   	  // suppression autre que le debut//
   	 else
   	 {
   	 	  p=tete;q=p->svt;
   	 	  
   	 	  while(q!=NULL)
   	 	  {  
   	 	  	  if(strcmp(q->info,nvmot)==0)
   	 	  	  {  
   	 	  	    c=q; 
   	 	  	    p->svt=q->svt;
   	 	  	    free(c);
   	 	  	 	q=p->svt;
			   }
			   
			   else
			   {
			   	p=q; q=q->svt;
			   }
			   
			}
   	 	  	  
    	}
   	 
   }
   return tete;	
	
}

//// suppression dun mot donnee////

st *supp_mot(st *V,char *nvmot )
{
	int i;
	
	 i=0;
   while(i<26)
   {
   	  if((nvmot[0]==V[i].x.l1)|| (nvmot[0]==V[i].x.l2))   
   	  {
   	  	 V[i].tete=supprimer(V[i].tete,nvmot);
 	  }
 	  i++;
   }
	
	return V;
	
}


  
//**************************************     PROGRAMME PRINCIPALE     **********************************************//

int main() 
{	//declaration //
	int choix ,num , ord , met ;
	
       //representation du menu
       
        printf("\n\n          ************************** Programme principal ***************************\n\n");
	    printf("\n\n                            BIENVENUE !   :D        \n\n ");
        printf("               - VEUILLEZ CHOISIR UNE OPTION DU MENU CI-DESSOUS -      \n");
        printf("\n                1- Operations arithmitiques sur les matrices.   \n");
        printf("\n                2- Autres operations sur les matrices.    \n");
        printf("\n                3- Chaines de caracteres et listes chainees.   \n");
        printf("\n                4- Quitter.     \n");
        do
		{
	    printf("\n               -ENTREZ VOTRE CHOIX:  ");
        scanf("%d", &choix);

	    if	((choix<1) ||(choix>4))
	      printf("\n                OUPS, il n'y a pas ce nombre dans le menu!  :(  \n");
		
	    }while((choix<1) ||(choix>4));
	
                    // Operations arithmetiques sur les matrices//

	if(choix==1)   	
	{  
	   	    // declaration des donnees //
	   	int**A;
	   	int**B;
	   	int**C;
	   	int M,N,i,X,P;

	// **creation de la 1ere matrice**//
       printf("\n Donner le nombre des lignes de la matrice A:	 ");
       scanf("%d",&N);
       printf("\n Donner le nombre des colonnes de la matrice A : ");
       scanf("%d",&M);     
    	printf("\n");
    	
	 // **allocation dynamique de la matrice**//
	  	A=(int **) malloc(N*sizeof(int*));
        for (i=0; i<N; i++)
        A[i]=(int *) malloc(M*sizeof(int));
         

     creat_Mat(A,N, M);
     affich_mat(A, N, M);
    

	    system("pause"); system("cls");
	    
	    printf("                    -Choisissez une operation -     \n");

        printf("\n                 1-  Somme de deux matrices.      \n\n");
        printf("\n                 2-  Difference de deux matrice .    \n\n");
        printf("\n                 3- Multiplication d'une matrice par un nombre.     \n\n");
        printf("\n                 4- Produit de deux matrices.     \n\n");
        printf("\n                 5- Inverse d'une matrice.     \n\n");
        do
		{
	    printf("\n                 ENTREZ VOTRE CHOIX:    "); 
        scanf("%d", &num);

	    if	((num<1) ||(num>5))
	      printf("\n             OUPS, il n'y a pas ce nombre dans le menu! :(   \n");
		
	    }while((num<1) ||(num>5));
	    
	        //cas de l'addition
	    
	    if(num==1)  	
	    {
	    	//allocation de la deuxieme matrice                
				
		/* On considere que les matrices A et B possedent les memes dimensions sinon on pourrait pas  effectuer l'addition */ 	
			 												  
	    	    B=(int **) malloc(N*sizeof(int*));
               for (i=0; i<N; i++)
               B[i]=(int *) malloc(M*sizeof(int));
               
               creat_Mat(B,N, M);
               affich_mat(B, N, M);
		       C=add_mat(A,B,N,M);  
		       
		       liberer(B,N); liberer(C,N);
		        
   
        
        }
        
            //cas de la soustraction
            
        if(num==2)
	    {
	    	//allocation de la deuxieme matrice
	    	                                                         
	    		/* On considere que les matrices A et B possedent les memes dimensions sinon on pourrait pas  effectuer l'addition et la soustraction */ 	

	    	    B=(int **) malloc(N*sizeof(int*));
                for (i=0; i<N; i++)
                B[i]=(int *) malloc(M*sizeof(int));
                
                creat_Mat(B,N, M);
                affich_mat(B, N, M);
                C=sous_mat(A,B,N,M);
                liberer(B,N);liberer(C,N);
        }
        
           // cas de la multiplication d'une matrice par un nombre
           
        if (num==3)
        {
           A=mult_nbr(A, X,  N, M);  
		}
		
		// cas de la multiplication d'une matrice par une autre matrice
		
		if(num==4)
		{
			  printf("\n Donnez le nombre de colonne de la deuxieme matrice : \n");
			   /*Le nombre de ligne de B doit etre egal au nombre de colonne de A pour effectuer la multiplication*/
              scanf("%d",&P); 
              
              B=(int **) malloc(M*sizeof(int*));
              for (i=0; i<M; i++)
              B[i]=(int *) malloc(P*sizeof(int));
               
              creat_Mat(B,M,P);
              affich_mat(B,M,P);
              C=mult_mat(A, B, N, M, P); 
              liberer(B,N); liberer(C,N);
			     
		}
		
		//cas de l'inverse d'une matrice
		if(num==5)
		{
		if (N != M)
			{		printf("\n\n ON PEUT PAS VOUS DONNER L'INVERSE car N!=M \n\n");
		     exit;
		    }
	
		else {
			printf(" \n La matrice inverse:\n\n");
			//On appelle la fonction qui retourne la matrice inverse
		     
             }	
             	InverseMat( N, A);
              affich_mat(A,N,N);
              liberer(A,N);
		}

	    
     }
      
	 	                   //*******  autres operations sur les matrices**********//
							
							 
	  if(choix==2)
	  {      int**A;
	         int *T;
	         int M,N,k,i,j,L,K;

	  	 	//creation de la  matrice **allocation dynamique de la matrice**//
  	
       	printf("\n Donner le nombre des lignes de la matrice A :");
        scanf("%d",&N);
        printf("\n Donner le nombre des colonnes de la matrice A : ");
        scanf("%d",&M);     
	    printf("\n"); 
	    
	    	A=(int **) malloc(N*sizeof(int*));
            for (i=0; i<N; i++)
            A[i]=(int *) malloc(M*sizeof(int));
         
        creat_Mat(A,N, M);
        affich_mat(A, N, M);
       
        system("pause"); system("cls");
        
        printf("                  -   choisissez une operation  -         \n\n");
         printf(" \n                  1- Transposee dune matrice        \n \n ");
         printf(" \n                  2- Tri d'une matrice     \n\n");
         printf(" \n                  3- Calcul du vecteur Maxligne       \n\n ");
         printf(" \n                  4- Calcul du vecteur Maxcolonne   \n\n ");
         printf(" \n                  5- Extraction de sous-matrices      \n\n ");
          
        do
		{
	    printf(" \n\n                   ENTREZ VOTRE CHOIX:   ");
        scanf("%d", &num);

	    if	((num<1) ||(num>5))
	      printf("\n                  OUPS, il n'y a pas ce nombre dans le menu! :(  \n");
		
	    }while((num<1) ||(num>5));
     
      // cas de la transposee d'une matrice //
      
       
	    if(num==1)
	    {    
		      printf("\n La matrice A avant la modification: \n ");
	          affich_mat(A,N,M);
	    	  printf("\n La matrice apres la modification: \n ");
	    	  transposee_mat(A,N,M);
	    	
		}
	
	  // cas du tri d'une matrice 
	  
    	
	  if(num==2)
	  {    
	        /*on copie tous les elements de la mtrice dans un tableau intermedaire de taille N*M,  allouer dynamiquement le tableau */ 
	        T=(int *) malloc(N*M* sizeof(int));
	        k=0;
		 for (i=0;i<N;i++)
		  {    
			for(j=0;j<M;j++)
			{
			  T[k]=A[i][j];
			  k++;
			}
	      }  
	         system("pause");
	        
	  	    printf(" \n                   -Veuillez choisir une methode de tri-    \n\n");
	   	    printf("\n                   1-tri par selection    \n\n");
	        printf("\n                   2-tri par permutation    \n\n");
	        printf("\n                   3-tri  par insertion   \n\n");
	        printf("\n                   4-tri par bulle     \n\n");
	        
	   	do
	   	  { 
	   	  	printf("  \n                Choisissez une methode :");
	   	  	scanf("%d",&met);
	   	  	
	   	 if((met<1)||(met>4))
	   	   printf("\n\n                  Il n'y a que 4 methodes de tri! :D \n\n");
	   	  	
		   }while((met<1)||(met>4)); 
	     }
	   

	                        //*****trie par selection *****//
	     if(met==1)
	     {
	     	printf("\n\n                    -veuillez choisir l'ordre du tri-   \n\n");
	        printf("\n                    1- ordre coissant  \n\n");
	        printf("\n                    2- ordre decroissant  \n\n");
	       
	       do{
	       	  printf("\n\n                    ENTREZ VOTRE CHOIX :");
	       	  scanf("%d",&ord);
	       	  if((ord<1)||(ord>2))
	       	     printf(" \n\n                Il y a 2 ordres! :)  \n\n");
	       	
		     }while((ord<1)||(ord>2));
		     
		      printf("\n\n La matrice avant le tri: \n\n");
	         affich_mat(A,N,M);
		   
		   if(ord==1) //tri par selection ordre croissant //
		   {
		   	   trimat_selection_croi(T,N*M);
		   	  	//remplir la matrice apres le tri//
			    k=0;
				for(i=0;i<M;i++)
				{ for(j=0;j<M;j++)
				  {
				
					A[i][j]=T[k];
					k++;
				   }
				}
					  printf("\n La matrice apres le tri: \n ");
		              affich_mat(A,N,M);
		   }
		   
		   
		    if(ord==2) //tri par selection ordre decroissant //
		   {
		   	   trimat_selection_decroi(T,N*M);
		   	  	//remplir la matrice apres le tri//
			    k=0;
				for(i=0;i<N;i++)
				{ for(j=0;j<M;j++)
				  {
				
					A[i][j]=T[k];
					k++;
				   }
				}
					  printf(" \n La matrice apres le tri: \n ");
		              affich_mat(A,N,M);
		    }
		   
		 }
		 
		         //*****trie par permutation *****//
		   if(met==2)
	    {
	     	printf("\n                    -Veuillez choisir l'ordre du tri-  \n\n");
	        printf("\n                    1- ordre coissant\n\n");
	        printf("\n                    2- ordre decroissant\n");
	       
	       do{
	       	  printf(" \n\n                   ENTREZ VOTRE CHOIX:   ");
	       	  scanf("%d",&ord);
	       	  if((ord<1)||(ord>2))
	       	     printf(" \n\n                Il y a  2 ordres! :)    \n");
	       	
		   }while((ord<1)||(ord>2));
		   
		      printf("\n\n La matrice avant le tri: \n\n");
	          affich_mat(A,N,M);
		   
		   if(ord==1) //tri par permutation ordre croissant //
		   {
		   	   trimat_permu_croi(T,N*M);
		   	  	//remplir la matrice apres le tri//
			    k=0;
				for(i=0;i<N;i++)
				{ for(j=0;j<M;j++)
				  {
				
					A[i][j]=T[k];
					k++;
				   }
				}
					  printf("\n La matrice apres le tri:   \n ");
		              affich_mat(A,N,M);
		   }
		   
		   
		    if(ord==2) //tri par permutation ordre decroissant //
		   {
		   	   trimat_permu_decroi(T,N*M);
		   	  	//remplir la matrice apres le tri//
			    k=0;
				for(i=0;i<N;i++)
				{ for(j=0;j<M;j++)
				  {
				
					A[i][j]=T[k];
					k++;
				   }
				}
					  printf(" \n La matrice apres le tri:\n ");
		              affich_mat(A,N,M);
		    }
		    
		
		}
		            //*****trie par insertion *****//
	       if(met==3)
	     {
	     	printf("\n                    -Veuillez choisir l'ordre du tri-  \n");
	        printf("\n                    1- ordre coissant\n\n");
	        printf("\n                    2- ordre decroissant\n");
	       
	       do{
	       	  printf(" \n\n                  ENTREZ VOTRE CHOIX:");
	       	  scanf("%d",&ord);
	       	  if((ord<1)||(ord>2))
	       	     printf(" \n\n               Il y a 2 ordres! :) \n\n");
	       	
		   }while((ord<1)||(ord>2));
		   
		       printf("\n\n La matrice avant le tri: \n\n");
	           affich_mat(A,N,M);
		   
		   if(ord==1) //tri par permutation ordre croissant //
		   {
		   	   trimat_inser_croi(T,N*M);
		   	  	//remplir la matrice apres le tri//
			    k=0;
				for(i=0;i<N;i++)
				{ for(j=0;j<M;j++)
				  {
				
					A[i][j]=T[k];
					k++;
				   }
				}
					  printf(" \n La matrice apres le tri: \n ");
		              affich_mat(A,N,M);
		   }
		   
		   
		    if(ord==2) //tri par insertion  ordre decroissant //
		   {
		   	   trimat_inser_decroi(T,N*M);
		   	  	//remplir la matrice apres le tri//
			    k=0;
				for(i=0;i<N;i++)
				{ for(j=0;j<M;j++)
				  {
				
					A[i][j]=T[k];
					k++;
				   }
				}
					  printf(" \n La matrice apres le tri: \n ");
		              affich_mat(A,N,M);
		    }
		
		    
     	}
		            //*****trie a bulle *****//
	       if(met==4)
	     {
	     	printf("\n                    -Veuillez choisir lordre du tri-  \n\n");
	        printf("\n                    1- ordre coissant    \n\n");
	        printf("\n                    2- ordre decroissant   \n\n");
	       
	       do{
	       	  printf("                   ENTREZ VOTRE CHOIX :\n\n");
	       	  scanf("%d",&ord);
	       	  if((ord<1)||(ord>2))
	       	     printf("                Il y a 2 ordres! :)  \n");
	       	
		   }while((ord<1)||(ord>2));
		   
		        printf("\n\n La matrice avant le tri: \n\n");
	            affich_mat(A,N,M);
		   
		   if(ord==1) //tri a bulle ordre croissant //
		   {
		   	   trimat_bulle_croi(T,N*M);
		   	  	//remplir la matrice apres le tri//
			    k=0;
				for(i=0;i<N;i++)
				{ for(j=0;j<M;j++)
				  {
				
					A[i][j]=T[k];
					k++;
				   }
				}
					  printf(" \n La matrice apres le tri : \n ");
		              affich_mat(A,N,M);
	       }
		   
		   
		    if(ord==2) //tri a bulle ordre decroissant //
		   {
		   	   trimat_bulle_decroi(T,N*M);
		   	  	//remplir la matrice apres le tri//
			    k=0;
				for(i=0;i<N;i++)
				{ for(j=0;j<M;j++)
				  {
				
					A[i][j]=T[k];
					k++;
				   }
				}
					  printf(" \n La matrice apres le tri: \n ");
		              affich_mat(A,N,M);
		    }
		    
	  	  }
	  	   
	  	   // vecteur max ligne //
	  	   
	  	  if(num==3)
		 {
			  printf("\n Le vecteur max ligne: \n ");
	  	  	  T=maxligne(A,N,M);
	  	  }
	  	  
	    // vecteur max colonne //
	    
	    if(num==4)
	  	  {  
			  printf("\n Le vecteur Max Colonne: \n ");
	  	  	  T=maxcolonne(A,N,M);
	  	  }
	  	  
	  	  
	   // extraction d'une sous matrice 
	    if(num==5)
	    {
	    	
        printf("\n Donnez le nombre de ligne de la sous-matrice que vous souhaitez extraire: \n\n");
        scanf("%d",&K);
        printf("\n Donnez le nombre de colonne de la sous-matrice que vous souhaitez extraire: \n\n");
        scanf("%d",&L);
	    sousmatrice(A, N, M, K,  L );
	    	
		}
		
		free(T);liberer(A,N);
    } 
    
   
     
    if (choix==3)
    {
    	//declaration
    	int nb,l,i;
    	char *ch;
    	char **A;
    	char nvmot[20];
    	st *V;
    	
    	//menu// 
		 system("cls");
    	
    	printf("                      \n\n -voici le menu -     \n\n");     
		printf("\n                 1-  Saisie du texte.      \n\n");
        printf("\n                 2-  Creation de la matrice de mots .    \n\n");
        printf("\n                 3- Affichage de la matrice.     \n\n");
        printf("\n                 4- Creation de la structure de listes.     \n\n");
        printf("\n                 5- Affichage de la structure.     \n\n");
        printf("\n                6- Ajout dun mot.     \n\n");
        printf("\n                 7- Suppression dun mot.     \n\n");
       
     	fflush(stdin); 
		ch=text(); 
		fflush(stdin); 
		l=strlen(ch);
		printf("\n \n La taille de ce text est : %d \n\n ",l);  
		puts(ch);
		fflush(stdin); 
		nb = nombre_mot(ch);
	    A=construit_mata(nb, ch,l) ;
	 	    
	    affich_mata(A,nb);   
	    
	    V=creation_struct(A, nb);
	 	 
	    affichage_struct(V);
	   		
	   		
	   	printf(" \n\n***choisissez lune des deux operations***\n\n");
	   	printf("    1: ajuter un mot a la structure precedente \n\n");
	   	printf("    2: supprimer un mot de la structure precedente \n\n");
	   	
	   	 do
		{
	    printf(" \n\n            ENTREZ VOTRE CHOIX:   ");
        scanf("%d", &num);

	    if	((num<1) ||(num>2))
	      printf("\n                  OUPS, il n'y a pas ce nombre dans le menu! :(  \n");
		
	    }while((num<1) ||(num>2));
	    
	    
	    if(num==1)
	    {
	    	printf("    \n ***donner le mot que vous voulez ajouter***\n");
	    	fflush(stdin);
	    	gets(nvmot);
	    	fflush(stdin);
	    	V=ajouter_mot(V,nvmot);
	    	affichage_struct(V);
	    	
		}
		 
		 if(num==2)
	    {
	    	printf("    \n ***donner le mot que vous voulez supprimer***\n");
	    	fflush(stdin);
	    	gets(nvmot);
	    	fflush(stdin);
	    	V=supp_mot(V,nvmot);
	    	affichage_struct(V);
	    	
		}
		 
    }
	if(choix==4)
	{
		printf("\n\n            OH, Vous allez nous quitter trop tot :'(  ! \n\n");
		exit ;
	}
	
    
	return 0;
}
