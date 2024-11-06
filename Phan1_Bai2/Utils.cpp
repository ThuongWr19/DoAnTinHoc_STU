#include "Library.h"

bool SLL_isEmpty(SLL_ptr head) {
	return head == NULL;
}

int SLL_Length(SLL_ptr head) {
	int count = 0;
	while (head) {
		count++;
		head = head->next;
	}
	return count;
}

SLL_ptr SLL_makeNode(typeinfo data) {
	SLL_ptr new_Node = new SinglyLinkedList();
	new_Node->data = data;
	new_Node->next = NULL;
	return new_Node;
}

void SLL_Init(SLL_ptr& head) {
	head = NULL;
}

void SLL_Add_First(SLL_ptr& head, typeinfo data) {
	SLL_ptr new_SLL_Node = SLL_makeNode(data);
	if (SLL_isEmpty(head))
		head = new_SLL_Node;
	else {
		new_SLL_Node->next = head;
		head = new_SLL_Node;
	}
}

void SLL_Add_Mid(SLL_ptr& head, typeinfo data, int pos) {
	SLL_ptr new_SLL_Node = SLL_makeNode(data);
	if (SLL_isEmpty(head))
		head = new_SLL_Node;
	else {
		SLL_ptr curr = head;
		for (int i = 0; i < pos - 1 && curr->next != NULL; i++)
			curr = curr->next;
		new_SLL_Node->next = curr->next;
		curr->next = new_SLL_Node;
	}
}

void SLL_Add_Last(SLL_ptr& head, typeinfo data) {
	SLL_ptr new_SLL_Node = SLL_makeNode(data);
	if (SLL_isEmpty(head))
		head = new_SLL_Node;
	else {
		SLL_ptr curr = head;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = new_SLL_Node;
	}
}

void SLL_Remove_First(SLL_ptr& head) {
	if (SLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	else {
		SLL_ptr temp = head;
		head = head->next;
		free(temp);
	}
}

void SLL_Remove_Mid(SLL_ptr& head, int pos) {
	if (SLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	else if (pos < 0 || pos >= SLL_Length(head)) {
		cout << "Vi tri khong hop le!";
		return;
	}
	SLL_ptr curr = head;
	SLL_ptr prev = NULL;
	for (int i = 0; i < pos; i++) {
		prev = curr;
		curr = curr->next;
	}
	if (prev != NULL) {
		prev->next = curr->next;
		delete curr;
	}

}

void SLL_Remove_Last(SLL_ptr& head) {
	if (SLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	else {
		SLL_ptr curr = head;
		if (SLL_Length(curr) == 1)
			SLL_Remove_First(curr);
		else {
			while (curr->next->next != NULL)
				curr = curr->next;
			free(curr->next);
			curr->next = NULL;
		}
	}
}

void SLL_Update_First(SLL_ptr& head, typeinfo data) {
	if (SLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	else
		head->data = data;
}

void SLL_Update_Mid(SLL_ptr& head, typeinfo data, int pos) {
	if (SLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	else {
		SLL_ptr curr = head;
		for (int i = 0; i < pos && curr->next != NULL; i++)
			curr = curr->next;
		curr->data = data;
	}
}

void SLL_Update_Last(SLL_ptr& head, typeinfo data) {
	if (SLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	else {
		SLL_ptr curr = head;
		while (curr->next != NULL)
			curr = curr->next;
		curr->data = data;
	}
}

void SLL_Reverse(SLL_ptr& head) {
	SLL_ptr prev = nullptr, curr = head, next = nullptr;
	while (curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
}

void SLL_Clear(SLL_ptr& head) {
	if (SLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	else {
		SLL_ptr curr = head;
		while (curr != NULL) {
			SLL_ptr temp = curr;
			curr = curr->next;
			delete temp;
		}
		head = curr;
	}
}

void SLL_Output_List(SLL_ptr head) {
	if (SLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	SLL_ptr curr = head;
	while (curr != NULL) {
		cout << curr->data << " ";
		curr = curr->next;

	}
}

DLL_ptr DLL_makeNode(typeinfo data) {
	DLL_ptr new_node = new DoubleLinkedList();
	new_node->data = data;
	new_node->prev = NULL;
	new_node->next = NULL;

	return new_node;
}

void DLL_Init(DLL_ptr& head) {
	head = NULL;
}

bool DLL_isEmpty(DLL_ptr head) {
	return head == NULL ? true : false;
}

int DLL_Length(DLL_ptr head) {
	int count = 0;
	while (head != NULL) {
		count++;
		head = head->next;
	}
	return count;
}

void DLL_Add_First(DLL_ptr& head, typeinfo data) {
	DLL_ptr new_node = DLL_makeNode(data);
	if (DLL_isEmpty(head))
		head = new_node;
	else {
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
	}
}

void DLL_Add_Mid(DLL_ptr& head, typeinfo data, int pos) {
	DLL_ptr new_DLL_Node = DLL_makeNode(data);
	if (DLL_isEmpty(head))
		head = new_DLL_Node;
	else {
		DLL_ptr curr = head;
		for (int i = 0; i < pos - 1 && curr->next != NULL; i++)
			curr = curr->next;
		new_DLL_Node->next = curr->next;

		if(curr->next != NULL)
			curr->next->prev = new_DLL_Node;

		curr->next = new_DLL_Node;
		new_DLL_Node->prev = curr;
	}
}

void DLL_Add_Last(DLL_ptr& head, typeinfo data) {
	DLL_ptr new_DLL_Node = DLL_makeNode(data);
	if (DLL_isEmpty(head))
		head = new_DLL_Node;
	else {
		DLL_ptr curr = head;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = new_DLL_Node;
		new_DLL_Node->prev = curr;
	}
}

void DLL_Remove_First(DLL_ptr& head) {
	if (DLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	DLL_ptr curr = head, temp = curr;
	if (curr->next == NULL)
		curr = NULL;
	else {
		curr = curr->next;
		curr->prev = NULL;
	}
	delete temp;
	head = curr;
}

void DLL_Remove_Mid(DLL_ptr& head, int pos) {
	if (DLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	else if (pos < 0 || pos >= DLL_Length(head)) {
		cout << "Vi tri khong hop le!";
		return;
	}
	if (DLL_Length(head) == 1) {
		DLL_Remove_First(head);
		return;
	}
	DLL_ptr curr = head;
	DLL_ptr prev = NULL;
	for (int i = 0; i < pos; i++) {
		prev = curr;
		curr = curr->next;
	}
	if (prev != NULL) {
		prev->next = curr->next;
		prev->next->prev = prev;
		delete curr;
	}
}

void DLL_Remove_Last(DLL_ptr& head) {
	if (DLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	if (DLL_Length(head) == 1) {
		DLL_Remove_First(head);
		return;
	}
	DLL_ptr curr = head;
	while(curr->next!=NULL)
		curr = curr->next;
	DLL_ptr temp = curr;
	curr = curr->prev;
	free(temp);
	curr->next = NULL;
}

void DLL_Update_First(DLL_ptr& head, typeinfo data) {
	if (DLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	else
		head->data = data;
}

void DLL_Update_Mid(DLL_ptr& head, typeinfo data, int pos) {
	if (DLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	else {
		DLL_ptr curr = head;
		for (int i = 0; i < pos && curr->next != NULL; i++)
			curr = curr->next;
		curr->data = data;
	}
}

void DLL_Update_Last(DLL_ptr& head, typeinfo data) {
	if (DLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	else {
		DLL_ptr curr = head;
		while (curr->next != NULL)
			curr = curr->next;
		curr->data = data;
	}
}

void DLL_Reverse(DLL_ptr& head) {
	DLL_ptr temp = NULL;
	DLL_ptr curr = head;
	while (curr) {
		temp = curr->prev;
		curr->prev = curr->next;
		curr->next = temp;
		curr = curr->prev;
	}
	if (temp) 
		head = temp->prev;
}

void DLL_Clear(DLL_ptr& head) {
	if (DLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	else {
		DLL_ptr curr = head;
		while (curr != NULL) {
			DLL_ptr temp = curr;
			curr = curr->next;
			delete temp;
		}
		head = curr;
	}
}

void DLL_Output_List(DLL_ptr head) {
	if (DLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	DLL_ptr curr = head;
	while (curr != NULL) {
		cout << curr->data << " ";
		curr = curr->next;

	}
}