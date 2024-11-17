#include "Library.h"

int main() {
	SLLNode SLL_head;
	DLLNode DLL_head;
	CLLNode CLL_head;

	menu_Main(SLL_head, DLL_head, CLL_head);

	SLL_Clear(SLL_head);
	DLL_Clear(DLL_head);
	CLL_Clear(CLL_head);
	return 0;
}