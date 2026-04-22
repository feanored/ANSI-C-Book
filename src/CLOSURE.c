#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN64
  #define NOINLINE 
#else
  #define NOINLINE __attribute__((noinline))
#endif

//-------BLOCO DE CODIGO EQUIVALENTE AO PYTHON NATIVO--------------------//

typedef struct {
  int* val;  // Armazena ponteiros
} Func1;

static NOINLINE int call_func1(Func1* f) {
  return *(f->val); // acessa valor armazenado no ponteiro
}

static void ponteiros(Func1** funcs) {
  int i = 0;

  for (int j = 0; j < 3; ++j) {
    i = j;
    funcs[j] = (Func1*) malloc(sizeof(int*));
    if (funcs[j]) {
      funcs[j]->val = &i;  // armazena endereco de i
    }
  }
  // i = 7; // depois do for, i valeria 2
  
  printf("Interno com ponteiros: [");
  for (int j = 0; j < 3; j++) {
    printf("%d", call_func1(funcs[j]));
    if (j < 2) printf(", ");
    // free(funcs[j]);
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
  //****************************************************//
  Func1* func1[3];
  ponteiros(func1);

  printf("Externo com ponteiros: [");
  for (int j = 0; j < 3; j++) {
    printf("%d", call_func1(func1[j]));
    if (j < 2) printf(", ");
    free(func1[j]);
  }
  printf("]\n");

  //****************************************************//
  Func2* func2[3];
  closure(func2);

  printf("Externo com valores:   [");
  for (int j = 0; j < 3; j++) {
    printf("%d", call_func2(func2[j]));
    if (j < 2) printf(", ");
    free(func2[j]);
  }
  printf("]\n");

  return 0;
}


/*
--- OUTPUTS POR SO ---

- MAC: 
./CLOSURE
Interno com ponteiros: [2, 2, 2]
Externo com ponteiros: [73896, 73896, 73896]
Externo com valores:   [0, 1, 2]

- LINUX:


- WINDOWS (MSVC):


- WINDOWS (CLANG):


*/