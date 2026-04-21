#include <stdio.h>

#ifdef _WIN64
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif
#endif

int main() {
  for (int i = 0; i < 1E9; i++) {
    #ifdef _WIN64
    if (GetAsyncKeyState(0x13) & 0x8000) { // tecla 'Pause'
      printf("\n[PAUSE detectado] Programa suspenso. Pressione ENTER para retomar.\n");
      MessageBoxA(NULL, "Programa suspenso. Clique OK e pressione ENTER para retomar.", "Tecla PAUSE detectada!",
          MB_ICONWARNING | MB_OK | MB_SETFOREGROUND | MB_TOPMOST);
    }
    #endif
    printf("%d\n", i);

  }
  return 0;
}
