#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//-------BLOCO DE CODIGO EQUIVALENTE AO PYTHON NATIVO--------------------//

typedef struct {
  int* val;  // Armazena ponteiros
} Func1;

static int call_func1(Func1* f) {
  return *(f->val); // acessa valor armazenado no ponteiro
}

static void ponteiros(Func1** funcs) {
  int i = 0;

  for (int j = 0; j < 3; ++j) {
    i = j;
    funcs[j] = (Func1*) malloc(sizeof(int));
    if (funcs[j]) {
      funcs[j]->val = &i;  // armazena endereço de i
    }
  }
  i = 7; // depois do for, i vale 2
  
  printf("Interno sem closure: [");
  for (int j = 0; j < 3; j++) {
    printf("%d", call_func1(funcs[j]));
    if (j < 2) printf(", ");
  }
  printf("]\n");
}


//-------BLOCO DE CODIGO EQUIVALENTE AO PYTHON COM CLOSURE-------------------//

typedef struct {
  int val; // Armazena valores
} Func2;

static int call_func2(Func2* f) {
  return f->val;  // retorna o valor armazenado diretamente
}

static void closure(Func2** funcs) {
  for (int i = 0; i < 3; ++i) {
    funcs[i] = (Func2*) malloc(sizeof(int));
    if (funcs[i]) {
      funcs[i]->val = i;  // Captura VALOR atual de i
    }
  }
}


//---------------------------------------------------------------------------//

int main() {
  setlocale(LC_ALL, "PT_br");

  Func1* func1[3];
  ponteiros(func1);

  printf("Externo sem closure: [");
  for (int j = 0; j < 3; j++) {
    printf("%d", call_func1(func1[j]));
    if (j < 2) printf(", ");
    free(func1[j]);
  }
  printf("]\n");

  //---------------------------------------------------------------------------//

  Func2* func2[3];
  closure(func2);

  printf("Externo com closure: [");
  for (int j = 0; j < 3; j++) {
    printf("%d", call_func2(func2[j]));
    if (j < 2) printf(", ");
    free(func2[j]);
  }
  printf("]\n");

  return 0;
}
