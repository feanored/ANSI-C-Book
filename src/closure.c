#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//-------BLOCO DE CÓDIGO EQUIVALENTE AO PYTHON DA QUESTÃO--------------------//

typedef struct {
  int* val;  // Armazena ponteiros
} Func1;

int call_func1(Func1* f) {
  return *(f->val); // acessa valor armazenado no ponteiro
}

void ponteiros() {
  Func1* funcs[3];
  int i = 0;

  for (i = 0; i < 3; ++i) {
    funcs[i] = malloc(sizeof(int));
    funcs[i]->val = &i;  // armazena endereço de i
  }
  i--; // depois do for, i valeria 3

  printf("Resultados código da questão:  [");
  for (int j = 0; j < 3; j++) {
    printf("%d", call_func1(funcs[j]));
    if (j < 2) printf(", ");
    free(funcs[j]);
  }
  printf("]\n");
}

//-------BLOCO DE CÓDIGO EQUIVALENTE AO PYTHON COM CLOSURE-------------------//

typedef struct {
  int val; // Armazena valores
} Func2;

int call_func2(Func2* f) {
  return f->val;  // retorna o valor armazenado diretamente
}

void closure() {
  Func2* funcs[3];

  for (int i = 0; i < 3; ++i) {
    funcs[i] = malloc(sizeof(int));
    funcs[i]->val = i;  // Captura VALOR atual de i
  }

  printf("Resultados código com closure: [");
  for (int j = 0; j < 3; j++) {
    printf("%d", call_func2(funcs[j]));
    if (j < 2) printf(", ");
    free(funcs[j]);
  }
  printf("]\n");
}

//---------------------------------------------------------------------------//

int main() {
  setlocale(LC_ALL, "pt_br");
  ponteiros();
  closure();
  return 0;
}