// Rafael Bonfim Zacco

/*
Sua  tarefa  será  construir  um  código  capaz de  somar,  item  a  item,  todos os  inteiros  entre  1  e 1.000.000. Existe, pelo menos uma fórmula matemática que pode ser usada para validar o resultado. 

Contudo, você deverá criar uma fila, armazenar este inteiros nesta fila, depois percorrer a fila somando estes valores. A tarefa é para exercitar o uso de algoritmos, não da matemática.  

Atenção: use a mesma plataforma que usou no Trabalho 1 – pilhas. 

Seu  objetivo  será  medir  o  tempo  para  inserção  de  1.000.000  milhão  de  inteiros  em  uma estrutura de dados, o tempo para percorrer e somar 1.000.000 de inteiros em uma estrutura de dados, e o  tempo para garantir que um determinado  inteiro  já está na  fila (busca). Finalmente você deverá medir estes tempos percorrendo a fila em dois sentidos. De cima para baixo e de baixo para cima. 

Seu resultado será a média dos tempos gastos para as operações citadas acima em, no mímino 50 operações de cada tipo. As saídas apresentadas devem seguir o seguinte padrão: operação: tempo conforme pode ser visto no exemplo a seguir:  

Preenchimento da Fila: 1.234s 

Programas cuja saída tenham linhas que não sejam relativas as operações realizadas ou que não apresentem a formatação correta sofrerão um demérito na nota. 

Para resolver esta tarefa você poderá usar as linguagens Python, Java, C ou C++ de acordo com a  sua  preferência.  A  tarefa  deverá  ser  entregue  no  ambiente  virtual  de  aprendizagem  conforme  as instruções constante neste documento. 

Lembre-se: uma estrutura de dados consiste em uma definição de estrutura de memória, e dos métodos,  ou  funções  para  trabalhar  com  esta  estrutura.  No  mínimo  teremos  que  ter  métodos  para escrever,  ler,  remover  e buscar  valores  na  fila.  Programas  que  realizem  as  tarefas  necessárias  sem  a definição da estrutura de dados serão zerados.
*/

#include <stdio.h>
#include <stdbool.h>
#include <time.h>

int const tamanho = 1000000;
int fila[tamanho];
int primeiro, ultimo;

void criarFila() {
  primeiro = 0;
  ultimo = -1;
}

bool filaVazia() {
  if (primeiro>ultimo){
    return true;
  }
  else
    return false;
}

bool filaCheia() {
  if (ultimo == tamanho-1){
    return true;
  }
  else
    return false;
}

bool escreverFila(int valor) {
  if (filaCheia()){
    return false;
  }
  else{
    ultimo++;;
    fila[ultimo] = valor;   
    return true;
  }
}

bool removerFila() {
  if (filaVazia()){
    return false;
  }
  else{
    primeiro++;
    return true;
  }
}

bool lerFila() {
  if (filaVazia()) {
    return true;
  }
  else {
    printf("Primeiro da fila: %d\n",fila[primeiro]);
  }
}

bool buscarFila() {
  int i;

    for(i=1;i<1000000;i++){
        if (fila[i] != i+1){
            printf("Valor não está no local certo");
        }
    }
    for(i=999999;i>=0;i--){
        if (fila[i] != i+1){
            printf("Valor não está no local certo");
        }
    }
}

int main() {

  int i, j;
  double media, soma;
  double media_parcial = 0;
  clock_t tictac;
  
  criarFila();
  
/*
  escreverFila(2);
  escreverFila(8);
  escreverFila(7);
  lerFila(); // é para sair 2
  removerFila();
  escreverFila(5);
  lerFila(); // é para sair 8
  removerFila();
  removerFila();
  lerFila(); // é para sair 5
  removerFila();
  lerFila(); // é para sair nada
*/

  for (j=0 ; j<=50 ; j++){
        tictac = clock();
        for (i=1 ; i<=1000000 ; i++){
            escreverFila(i);
        }
        tictac = clock() - tictac;
        media_parcial = media_parcial + ((double)tictac)/CLOCKS_PER_SEC;

        for (i=1 ; i<=1000000 ; i++){
            removerFila();
        }
    }
    media = media_parcial/50;
    printf("Preenchimento da Fila: %fs",media);

  for (j=0 ; j<=50 ; j++){
    soma = 0;
    tictac = clock();
    for (i=0 ; i<1000000 ; i++){
        soma += fila[i];
    }
    tictac = clock() - tictac;
    media_parcial = media_parcial + ((double)tictac)/CLOCKS_PER_SEC;
  }
  media = media_parcial/50;
  printf("\nPercorrer e somar: %fs",media);

  for (j=0 ; j<=50 ; j++){
    tictac = clock();
    buscarFila();
    tictac = clock() - tictac;
    media_parcial = media_parcial + ((double)tictac)/CLOCKS_PER_SEC;
  }
  media = media_parcial/50;
  printf("\nBuscar valores: %fs",media);
  
  return 0;
}