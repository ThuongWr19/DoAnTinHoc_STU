#include "Library.h"

bool SLL_isEmpty(SLLNode head) {
	return head == NULL;
}

int SLL_Length(SLLNode head) {
	int count = 0;
	while (head) {
		count++;
		head = head->next;
	}
	return count;
}

SLLNode SLL_makeNode(typeinfo data) {
	SLLNode new_Node = new SinglyLinkedList();
	new_Node->data = data;
	new_Node->next = NULL;
	return new_Node;
}

void SLL_Init(SLLNode& head) {
	head = NULL;
}

void SLL_Add_First(SLLNode& head, typeinfo data) {
	SLLNode new_SLL_Node = SLL_makeNode(data);
	if (SLL_isEmpty(head))
		head = new_SLL_Node;
	else {
		new_SLL_Node->next = head;
		head = new_SLL_Node;
	}
}

void SLL_Add_Mid(SLLNode& head, typeinfo data, int pos) {
	SLLNode new_SLL_Node = SLL_makeNode(data);
	if (SLL_isEmpty(head))
		head = new_SLL_Node;
	else {
		SLLNode curr = head;
		for (int i = 0; i < pos - 1 && curr->next != NULL; i++)
			curr = curr->next;
		new_SLL_Node->next = curr->next;
		curr->next = new_SLL_Node;
	}
}

void SLL_Add_Last(SLLNode& head, typeinfo data) {
	SLLNode new_SLL_Node = SLL_makeNode(data);
	if (SLL_isEmpty(head))
		head = new_SLL_Node;
	else {
		SLLNode curr = head;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = new_SLL_Node;
	}
}

void SLL_Remove_First(SLLNode& head) {
	if (SLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	else {
		SLLNode temp = head;
		head = head->next;
		free(temp);
	}
}

void SLL_Remove_Mid(SLLNode& head, int pos) {
	if (SLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	else if (pos < 0 || pos >= SLL_Length(head)) {
		cout << "Vi tri khong hop le!";
		return;
	}
	SLLNode curr = head;
	SLLNode prev = NULL;
	for (int i = 0; i < pos; i++) {
		prev = curr;
		curr = curr->next;
	}
	if (prev != NULL) {
		prev->next = curr->next;
		delete curr;
	}

}

void SLL_Remove_Last(SLLNode& head) {
	if (SLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	else {
		SLLNode curr = head;
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

void SLL_Update_First(SLLNode& head, typeinfo data) {
	if (SLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	else
		head->data = data;
}

void SLL_Update_Mid(SLLNode& head, typeinfo data, int pos) {
	if (SLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	else {
		SLLNode curr = head;
		for (int i = 0; i < pos && curr->next != NULL; i++)
			curr = curr->next;
		curr->data = data;
	}
}

void SLL_Update_Last(SLLNode& head, typeinfo data) {
	if (SLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	else {
		SLLNode curr = head;
		while (curr->next != NULL)
			curr = curr->next;
		curr->data = data;
	}
}

void SLL_Reverse(SLLNode& head) {
	if (SLL_isEmpty(head) || SLL_Length(head) == 1) {
		cout << "Danh sach trong hoac chi co 1 phan tu!";
		return;
	}
	SLLNode prev = nullptr, curr = head, next = nullptr;
	while (curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
}

void SLL_Clear(SLLNode& head) {
	if (SLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	else {
		SLLNode curr = head;
		while (curr != NULL) {
			SLLNode temp = curr;
			curr = curr->next;
			delete temp;
		}
		head = curr;
	}
}

void SLL_Output_List(SLLNode head) {
	if (SLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	SLLNode curr = head;
	while (curr != NULL) {
		cout << curr->data << " ";
		curr = curr->next;

	}
}

DLLNode DLL_makeNode(typeinfo data) {
	DLLNode new_node = new DoubleLinkedList();
	new_node->data = data;
	new_node->prev = NULL;
	new_node->next = NULL;

	return new_node;
}

void DLL_Init(DLLNode& head) {
	head = NULL;
}

bool DLL_isEmpty(DLLNode head) {
	return head == NULL ? true : false;
}

int DLL_Length(DLLNode head) {
	int count = 0;
	while (head != NULL) {
		count++;
		head = head->next;
	}
	return count;
}

void DLL_Add_First(DLLNode& head, typeinfo data) {
	DLLNode new_node = DLL_makeNode(data);
	if (DLL_isEmpty(head))
		head = new_node;
	else {
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
	}
}

void DLL_Add_Mid(DLLNode& head, typeinfo data, int pos) {
	DLLNode new_DLL_Node = DLL_makeNode(data);
	if (DLL_isEmpty(head))
		head = new_DLL_Node;
	else {
		DLLNode curr = head;
		for (int i = 0; i < pos - 1 && curr->next != NULL; i++)
			curr = curr->next;
		new_DLL_Node->next = curr->next;

		if(curr->next != NULL)
			curr->next->prev = new_DLL_Node;

		curr->next = new_DLL_Node;
		new_DLL_Node->prev = curr;
	}
}

void DLL_Add_Last(DLLNode& head, typeinfo data) {
	DLLNode new_DLL_Node = DLL_makeNode(data);
	if (DLL_isEmpty(head))
		head = new_DLL_Node;
	else {
		DLLNode curr = head;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = new_DLL_Node;
		new_DLL_Node->prev = curr;
	}
}

void DLL_Remove_First(DLLNode& head) {
	if (DLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	DLLNode curr = head, temp = curr;
	if (curr->next == NULL)
		curr = NULL;
	else {
		curr = curr->next;
		curr->prev = NULL;
	}
	delete temp;
	head = curr;
}

void DLL_Remove_Mid(DLLNode& head, int pos) {
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
	DLLNode curr = head;
	DLLNode prev = NULL;
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

void DLL_Remove_Last(DLLNode& head) {
	if (DLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	if (DLL_Length(head) == 1) {
		DLL_Remove_First(head);
		return;
	}
	DLLNode curr = head;
	while(curr->next!=NULL)
		curr = curr->next;
	DLLNode temp = curr;
	curr = curr->prev;
	free(temp);
	curr->next = NULL;
}

void DLL_Update_First(DLLNode& head, typeinfo data) {
	if (DLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	else
		head->data = data;
}

void DLL_Update_Mid(DLLNode& head, typeinfo data, int pos) {
	if (DLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	else {
		DLLNode curr = head;
		for (int i = 0; i < pos && curr->next != NULL; i++)
			curr = curr->next;
		curr->data = data;
	}
}

void DLL_Update_Last(DLLNode& head, typeinfo data) {
	if (DLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	else {
		DLLNode curr = head;
		while (curr->next != NULL)
			curr = curr->next;
		curr->data = data;
	}
}

void DLL_Reverse(DLLNode& head) {
	if (DLL_isEmpty(head) || DLL_Length(head) == 1) {
		cout << "Danh sach trong hoac chi co 1 phan tu!";
		return;
	}
	DLLNode temp = NULL;
	DLLNode curr = head;
	while (curr) {
		temp = curr->prev;
		curr->prev = curr->next;
		curr->next = temp;
		curr = curr->prev;
	}
	if (temp) 
		head = temp->prev;
}

void DLL_Clear(DLLNode& head) {
	if (DLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	else {
		DLLNode curr = head;
		while (curr != NULL) {
			DLLNode temp = curr;
			curr = curr->next;
			delete temp;
		}
		head = curr;
	}
}

void DLL_Output_List(DLLNode head) {
	if (DLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	DLLNode curr = head;
	while (curr != NULL) {
		cout << curr->data << " ";
		curr = curr->next;

	}
}

CLLNode CLL_makeNode(typeinfo data) {
	CLLNode new_node = new CircularLinkedList();
	new_node->data = data;
	new_node->next = new_node;
	return new_node;
}

void CLL_Init(CLLNode& head) {
	head = NULL;
}
bool CLL_isEmpty(CLLNode head) {
	return head == NULL ? true : false;
}
int CLL_Length(CLLNode head) {
	if (head == NULL) return 0;
	int count = 1;
	CLLNode curr = head->next;
	while (curr != head) {
		count++;
		curr = curr->next;
	}
	return count;
}

void CLL_Add_First(CLLNode& head, typeinfo data) {
	CLLNode new_node = CLL_makeNode(data);
	if (CLL_isEmpty(head)) {
		head = new_node;
		head->next = head;
	}
	else {
		CLLNode temp = head;
		while (temp->next != head)
			temp = temp->next;
		new_node->next = head;
		temp->next = new_node;
		head = new_node;
	}
}
void CLL_Add_Mid(CLLNode& head, typeinfo data, int pos) {
	if(pos == 0) {
		CLL_Add_First(head, data);
		return;
	}
	else if (pos == CLL_Length(head)) {
		CLL_Add_Last(head, data);
		return;
	}
	CLLNode new_node = CLL_makeNode(data);
	CLLNode temp = head;
	for (int i = 0; i < pos - 1; ++i)
		temp = temp->next;

	new_node->next = temp->next;
	temp->next = new_node;
}
void CLL_Add_Last(CLLNode& head, typeinfo data) {
	CLLNode new_node = CLL_makeNode(data);
	if (CLL_isEmpty(head)) {
		CLL_Add_First(head, data);
		return;
	}
	CLLNode temp = head;
	while (temp->next != head)
		temp = temp->next;
	temp->next = new_node;
	new_node->next = head;
}

void CLL_Remove_First(CLLNode& head) {
	if (CLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}

	if (CLL_Length(head) == 1) {
		delete head;
		head = NULL;
	}
	else {
		CLLNode temp = head;
		while (temp->next != head) 
			temp = temp->next;

		CLLNode node_delete = head;
		head = head->next;
		temp->next = head;
		delete node_delete;
	}
}

void CLL_Remove_Mid(CLLNode& head, int pos) {
	if (CLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	else if (CLL_Length(head) == 1) {
		CLL_Remove_First(head);
		return;
	}
	else if (pos == CLL_Length(head)) {
		CLL_Remove_Last(head);
		return;
	}
	CLLNode temp = head;
	for (int i = 0; i < pos - 1; ++i)
		temp = temp->next;

	CLLNode node_delete = temp->next;
	temp->next = node_delete->next;
	delete node_delete;
}

void CLL_Remove_Last(CLLNode& head) {
	if (CLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}

	if (CLL_Length(head) == 1) {
		delete head;
		head = NULL;
	}
	else {
		CLLNode temp = head;
		while (temp->next->next != head)
			temp = temp->next;
		
		delete temp->next;
		temp->next = head;
	}
}

void CLL_Update_First(CLLNode& head, typeinfo data) {
	if (CLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	else
		head->data = data;
}
void CLL_Update_Mid(CLLNode& head, typeinfo data, int pos) {
	if (CLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	else if (CLL_Length(head) == 1) {
		CLL_Update_First(head, data);
		return;
	}
	else if (pos == CLL_Length(head)) {
		CLL_Update_Last(head, data);
		return;
	}
	CLLNode curr = head;
	for (int i = 0; i < pos; ++i)
		curr = curr->next;
	
	curr->data = data;
}
void CLL_Update_Last(CLLNode& head, typeinfo data) {
	if (CLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	else {
		CLLNode curr = head;
		while (curr->next != head)
			curr = curr->next;

		curr->data = data;
	}
}

void CLL_Reverse(CLLNode& head) {
	if (CLL_isEmpty(head) || CLL_Length(head) == 1) {
		cout << "Danh sach trong hoac chi co 1 phan tu!";
		return;
	}

	CLLNode prev = nullptr;
	CLLNode current = head;
	CLLNode next = nullptr;
	CLLNode last = head;

	do {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	} while (current != head);

	last->next = prev;
	head = prev;
}

void CLL_Clear(CLLNode& head) {

	if (CLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}

	CLLNode curr = head->next;
	while (curr != head) {
		CLLNode node_Delete = curr;
		curr = curr->next;
		delete node_Delete;
	}
	delete head;
	head = NULL;
}

void CLL_Output_List(CLLNode head){
	if (CLL_isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	CLLNode curr = head;
	do {
		cout << curr->data << " ";
		curr = curr->next;
	} while (curr != head);
}