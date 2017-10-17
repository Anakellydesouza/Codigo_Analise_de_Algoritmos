#include <stdio.h>
#include <stdlib.h>

void Print_Optimal_Parens(int**, int , int );
void Matrix_Chain_Order (int , int* , int** , int**);


int main(){
    int n;
    scanf("%d", &n);

    int* p = (int*) malloc(n * sizeof(int)); //aloca vetor de n posicooes

    int i,j;
    for(i=0;i<n;i++){
            scanf("%d", &p[i]);
    }

    int** m = (int**) malloc(n*sizeof(int*));

    for(i=0;i<n;i++){

        m[i]=(int*) malloc(n * sizeof(int));
        for(j =0;j<n;j++){

            m[i][j]=0;
        }
    }
     int** s = (int**) malloc(n*sizeof(int*));

    for(i=0;i<n;i++){

        s[i]=(int*) malloc(n * sizeof(int));
        for(j =0;j<n;j++){

            s[i][j]=0;
        }
    }





    Matrix_Chain_Order(n-1,p,m,s);
    Print_Optimal_Parens(s,0,1);




return 0;

}

void Matrix_Chain_Order (int n, int* p, int** m, int** s){
    int l;
    int i;
    int j;
    int k;
    int q;
    for(l= 2;l<=n;l++){
            for(i=1; i< n-l+1; i++){

                j = i + l - 1;
                 m[i] [j] = 999999;
                    for(k=i;k<j-1;k++){
                        q = m[i] [k] + m[k + 1] [j] + p[i] - 1*p[k]*p[j];
                        if (q <m[i][j]){
                            m[i][j]=q;
                            s[i][j]=k;
                        }
                    }

            }

    }
}
void Print_Optimal_Parens(int** s, int i, int j){
    if (i == j){
        printf ("Ai");

    }
    else{
        printf ("(");
        Print_Optimal_Parens(s,i,s[i][j]);
        Print_Optimal_Parens(s,s[i][j]+1,j);
        printf(")");
    }

    }




