//Colding by: @guiquintero

#include<iostream>
#include<stdio.h>
#include<vector>

int calculaConflitos(std::vector<int> v);
void imprimeMatrizConflitos(int conflitos[8][8]);
void imprimeTabuleiro(std::vector<int> v);
const int tamanhoMatriz=8;


using namespace std;
int main(){
    //Insira aqui o vetor que sera testado
    vector<int> v={0,2,5,4,0,5,6,1};
    

    //Inicializa a matriz de conflitos e as variaveis auxiliares
    int conflitos[tamanhoMatriz][tamanhoMatriz], temp, menorConflito, menorConflitoAnterior=1000, linha, coluna, cont=1;

    //Executa o algoritmo hill climbing ate que nao haja mais melhora
    while (true){
        //Altera cada posicao do vetor para ver todas vizinhancas possiveis
        for (int i = 0; i < tamanhoMatriz; i++){
            //Salva o valor da posicao atual do vetor
            temp=v[i];
            for (int j = 0; j < tamanhoMatriz; j++){
                v[i]=j;
                //Calcula os conflitos para cada posicao do vetor e inseri na matriz de conflitos
                conflitos[i][j]=calculaConflitos(v);
            }
            //Volta o valor da posicao atual do vetor para o valor original
            v[i]=temp;
        }

        //Imprime o vetor do tabuleiro
        printf("%d%c Iteracao:\n\n", cont, 248);
        printf("Vetor do tabuleiro:\n");
        for (int i = 0; i < tamanhoMatriz; i++){
            printf("[%d]\t", v[i]);
        }
        printf("\n\n");

        //Imprime tabuleiro
        printf("Tabuleiro:\n");
        imprimeTabuleiro(v);

        //Procura a posicao com menor conflito
        menorConflito=1000;
        for (int i = 0; i < tamanhoMatriz; i++){
            for (int j = 0; j < tamanhoMatriz; j++){
                if(conflitos[i][j]<menorConflito){
                    menorConflito=conflitos[i][j];
                    linha=i;
                    coluna=j;
                }
            }
        }

        //Imprime matriz de conflitos
        printf("Mapa de conflitos:\n");
        imprimeMatrizConflitos(conflitos);

        //Se o menor conflito for maior ou igual ao menor conflito anterior, o algoritmo para
        if (menorConflito>=menorConflitoAnterior){
            break;
        }
        else{
            //Atualiza o valor do menor conflito anterior
            menorConflitoAnterior=menorConflito;
        }
        //Atualiza o vetor com a nova posicao que tem menor conflito
        v[linha]=coluna;

        //Incrementa o contador de iteracoes
        cont++;
    }
    return 0;
}

//Funcao para calcular o numero de conflitos de uma posicao
int calculaConflitos(vector<int> v){
    int conflitos=0;
    for (int i = 0; i < tamanhoMatriz; i++){
            for (int j = 0; j < tamanhoMatriz; j++){
                //Verifica se a posicao atual eh diferente da posicao que esta sendo comparada
                if(i!=j){
                    //Verifica se ha conflito na linha
                    if (v[i]==v[j]){
                        conflitos++;
                    }
                    //Verifica se ha conflito na diagonal
                    if(abs(v[i]-v[j])==abs(i-j)){
                        conflitos++;
                    }
                }
            }
        }
        //Retorna o numero de conflitos da posicao atual
    return conflitos;
}

//Funcao para imprimir a matriz de conflitos
void imprimeMatrizConflitos(int conflitos[tamanhoMatriz][tamanhoMatriz]){
    for (int i = 0; i < tamanhoMatriz; i++){
        for (int j = 0; j < tamanhoMatriz; j++){
           printf("[%d]\t" , conflitos[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

//Funcao para imprimir o tabuleiro
void imprimeTabuleiro(vector<int> v){
    for (int i = 0; i < tamanhoMatriz; i++){
        for (int j = 0; j < tamanhoMatriz; j++){
            if (v[i]==j){
                printf("[Q]\t");
            }
            else{
                printf("[ ]\t");
            }
        }
        printf("\n");
    }
    printf("\n");
    
}
