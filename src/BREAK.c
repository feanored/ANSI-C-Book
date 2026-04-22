#include <stdio.h>
#ifdef _WIN64
#include <windows.h>
#endif

int main() {
  for (int i = 0; i < 1E9; i++) {
    printf("%d\n", i);
    #ifdef _WIN64
    if (GetAsyncKeyState(0x20) & 0x8000) { // tecla 'SPACE' -> keyDown (0x8000)
      printf("\n[PAUSA solicitada] Programa suspenso. Clique OK para continuar.\n");
      MessageBoxA(NULL, "Programa suspenso. Clique OK para continuar.", "PAUSA solicitada!",
        MB_ICONWARNING | MB_OK | MB_SETFOREGROUND | MB_TOPMOST);
    }
	if (GetAsyncKeyState(0x51) & 0x0001) { // tecla 'q' ou 'Q' -> keyUp (0x0001)
      printf("\n[QUIT solicitado] Programa interrompido.\n");
      MessageBoxA(NULL, "Programa interrompido. Clique OK para sair.", "QUIT solicitado!",
        MB_ICONERROR | MB_OK | MB_SETFOREGROUND | MB_TOPMOST);
      break;
    }
    #endif
  }
  return 0;
}
