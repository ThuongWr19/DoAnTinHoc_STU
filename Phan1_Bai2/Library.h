#pragma once
#include <iostream>
using namespace std;

typedef int typeinfo;

//SLL = SingleLinkedList, SLL_ptr = SingleLinkedList pointer

struct SinglyLinkedList {
	typeinfo data;
	SinglyLinkedList* next;
};
typedef SinglyLinkedList* SLL_ptr;

SLL_ptr SLL_makeNode(typeinfo data);

void SLL_Init(SLL_ptr& head);
bool SLL_isEmpty(SLL_ptr head);
int SLL_Length(SLL_ptr head);

void SLL_Add_First(SLL_ptr& head, typeinfo data);
void SLL_Add_Mid(SLL_ptr& head, typeinfo data, int pos);
void SLL_Add_Last(SLL_ptr& head, typeinfo data);

void SLL_Remove_First(SLL_ptr& head);
void SLL_Remove_Mid(SLL_ptr& head, int pos);
void SLL_Remove_Last(SLL_ptr& head);

void SLL_Update_First(SLL_ptr& head,typeinfo data);
void SLL_Update_Mid(SLL_ptr & head, typeinfo data, int pos);
void SLL_Update_Last(SLL_ptr& head, typeinfo data);

void SLL_Reverse(SLL_ptr& head);

void SLL_Clear(SLL_ptr& head);

void SLL_Output_List(SLL_ptr head);

struct DoubleLinkedList {
	typeinfo data;
	DoubleLinkedList* next;
	DoubleLinkedList* prev;
};

typedef DoubleLinkedList* DLL_ptr;

DLL_ptr DLL_makeNode(typeinfo data);

void DLL_Init(DLL_ptr& head);
bool DLL_isEmpty(DLL_ptr head);
int DLL_Length(DLL_ptr head);

void DLL_Add_First(DLL_ptr& head, typeinfo data);
void DLL_Add_Mid(DLL_ptr& head, typeinfo data, int pos);
void DLL_Add_Last(DLL_ptr& head, typeinfo data);

void DLL_Remove_First(DLL_ptr& head);
void DLL_Remove_Mid(DLL_ptr& head, int pos);
void DLL_Remove_Last(DLL_ptr& head);

void DLL_Update_First(DLL_ptr& head, typeinfo data);
void DLL_Update_Mid(DLL_ptr& head, typeinfo data, int pos);
void DLL_Update_Last(DLL_ptr& head, typeinfo data);

void DLL_Reverse(DLL_ptr& head);

void DLL_Clear(DLL_ptr& head);

void DLL_Output_List(DLL_ptr head);

void show_Menu_Main();
void menu_Main(SLL_ptr& SLL_head, DLL_ptr& DLL_head);
void menu_SLL(SLL_ptr& head);
void menu_DLL(DLL_ptr& head);