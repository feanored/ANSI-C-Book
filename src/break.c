#include <stdio.h>

int main() {
  for (int i = 0; i < 1E9; i++) {

    if (GetAsyncKeyState(0x13) & 0x8000) { // tecla 'Pause'
      printf("\n[PAUSE detectado] Programa suspenso. Pressione ENTER para retomar.\n");
      getchar();
    }

    printf("%d\n", i);

  }
  return 0;
}
