#pragma once
#include <iostream>
using namespace std;

typedef int typeinfo;

//SLL = SingleLinkedList, SLLNode = SingleLinkedList pointer

struct SinglyLinkedList {
	typeinfo data;
	SinglyLinkedList* next;
};
typedef SinglyLinkedList* SLLNode;

SLLNode SLL_makeNode(typeinfo data);

void SLL_Init(SLLNode& head);
bool SLL_isEmpty(SLLNode head);
int SLL_Length(SLLNode head);

void SLL_Add_First(SLLNode& head, typeinfo data);
void SLL_Add_Mid(SLLNode& head, typeinfo data, int pos);
void SLL_Add_Last(SLLNode& head, typeinfo data);

void SLL_Remove_First(SLLNode& head);
void SLL_Remove_Mid(SLLNode& head, int pos);
void SLL_Remove_Last(SLLNode& head);

void SLL_Update_First(SLLNode& head,typeinfo data);
void SLL_Update_Mid(SLLNode & head, typeinfo data, int pos);
void SLL_Update_Last(SLLNode& head, typeinfo data);

void SLL_Reverse(SLLNode& head);

void SLL_Clear(SLLNode& head);

void SLL_Output_List(SLLNode head);

struct DoubleLinkedList {
	typeinfo data;
	DoubleLinkedList* next;
	DoubleLinkedList* prev;
};

typedef DoubleLinkedList* DLLNode;

DLLNode DLL_makeNode(typeinfo data);

void DLL_Init(DLLNode& head);
bool DLL_isEmpty(DLLNode head);
int DLL_Length(DLLNode head);

void DLL_Add_First(DLLNode& head, typeinfo data);
void DLL_Add_Mid(DLLNode& head, typeinfo data, int pos);
void DLL_Add_Last(DLLNode& head, typeinfo data);

void DLL_Remove_First(DLLNode& head);
void DLL_Remove_Mid(DLLNode& head, int pos);
void DLL_Remove_Last(DLLNode& head);

void DLL_Update_First(DLLNode& head, typeinfo data);
void DLL_Update_Mid(DLLNode& head, typeinfo data, int pos);
void DLL_Update_Last(DLLNode& head, typeinfo data);

void DLL_Reverse(DLLNode& head);

void DLL_Clear(DLLNode& head);

void DLL_Output_List(DLLNode head);

struct CircularLinkedList {
	typeinfo data;
	CircularLinkedList* next;
};

typedef CircularLinkedList* CLLNode;

CLLNode CLL_makeNode(typeinfo data);

void CLL_Init(CLLNode& head);
bool CLL_isEmpty(CLLNode head);
int CLL_Length(CLLNode head);

void CLL_Add_First(CLLNode& head, typeinfo data);
void CLL_Add_Mid(CLLNode& head, typeinfo data, int pos);
void CLL_Add_Last(CLLNode& head, typeinfo data);

void CLL_Remove_First(CLLNode& head);
void CLL_Remove_Mid(CLLNode& head, int pos);
void CLL_Remove_Last(CLLNode& head);

void CLL_Update_First(CLLNode& head, typeinfo data);
void CLL_Update_Mid(CLLNode& head, typeinfo data, int pos);
void CLL_Update_Last(CLLNode& head, typeinfo data);

void CLL_Reverse(CLLNode& head);

void CLL_Clear(CLLNode& head);

void CLL_Output_List(CLLNode head);

void show_Menu_Main();
void menu_Main(SLLNode& SLL_head, DLLNode& DLL_head, CLLNode& CLL_head);
void menu_SLL(SLLNode& head);
void menu_DLL(DLLNode& head);
void menu_CLL(CLLNode& head);