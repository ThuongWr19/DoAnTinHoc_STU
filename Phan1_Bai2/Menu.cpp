#include "Library.h"

void show_Menu_Main() {
	cout << "1. Danh sach lien ket don\n";
	cout << "2. Danh sach lien ket doi\n";
	cout << "3. Danh sach lien ket vong\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

void menu_Main(SLLNode& SLL_head, DLLNode& DLL_head, CLLNode &CLL_head) {
	int choose;
	do{
		show_Menu_Main();
		cout << "Nhap lua chon: ";
		cin >> choose;
		switch (choose) {
			case 1:
				system("cls");
				menu_SLL(SLL_head);
				break;
			case 2:
				system("cls");
				menu_DLL(DLL_head);
				break;
			case 3:
				system("cls");
				menu_CLL(CLL_head);
				break;
			default:
				system("cls");
				cout << "Nhap sai cu phap!";
				break;
		}
	} while (choose != 0);
}

void show_Menu_SLL() {
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "\n\n       SINGLY LINKED LIST\n\n";
	cout << "1. Khoi tao danh sach\n";
	cout << "2. Them phan tu vao danh sach\n";
	cout << "3. Sua phan tu trong danh sach\n";
	cout << "4. Xoa phan tu trong danh sach\n";
	cout << "5. Dao nguoc danh sach\n";
	cout << "6. Xoa toan bo danh sach\n";
	cout << "9. Xuat danh sach\n\n";
	cout << "[-1]. Quay tro lai menu chinh\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

void menu_SLL(SLLNode& head) {
	int choose, data, pos, pos1, pos2;
	do {
		show_Menu_SLL();
		cout << "Nhap lua chon: ";
		cin >> choose;
		switch (choose) {
			case 1:
				system("cls");
				SLL_Init(head);
				break;
			case 2:
				system("cls");
				cout << "Nhap data muon them: ";
				cin >> data;
				if (SLL_isEmpty(head))
					SLL_Add_First(head, data);
				else {
					cout << "\nChon vi tri muon them (1. Dau danh sach, 2. Giua danh sach, 3. Cuoi danh sach): ";
					cin >> pos1;
					switch (pos1) {
						case 1: 
							SLL_Add_First(head, data);
							break;
						case 2:
							do {
								cout << "Nhap vi tri cu the de them vao danh sach: ";
								cin >> pos2;
								if (pos2 <= 0 || pos2 >= SLL_Length(head))
									cout << "Nhap sai vi tri!";
							} while (pos2 <= 0 && pos2 >= SLL_Length(head));
							SLL_Add_Mid(head, data, pos2);
							break;
						case 3:
							SLL_Add_Last(head, data);
							break;
						default:
							cout << "\nNhap sai cu phap!\n";
							break;
					}
				}
				break;
			case 3:
				system("cls");
				do {
					cout << "\nChon vi tri muon sua (Nhap [-1] de thoat): ";
					cin >> pos;
					if (pos == -1) break;
					else if (pos < 0 || pos >= SLL_Length(head))
						cout << "\nNhap sai vi tri!\n\n";
					else {
						int data;
						cout << "Nhap data muon sua: ";
						cin >> data;

						//Sua dau danh sach
						if (pos == 0)
							SLL_Update_First(head, data);

						//Sua cuoi danh sach
						else if (pos == SLL_Length(head) - 1)
							SLL_Update_Last(head, data);

						//Sua giua danh sach
						else 
							SLL_Update_Mid(head, data, pos);
						cout << "Da thay doi data!\n";
					}
				} while (pos != -1);
				break;
			case 4:
				system("cls");
				do {
					cout << "\nChon vi tri muon xoa (Nhap [-1] de thoat): ";
					cin >> pos;
					if (pos == -1) break;
					else if (pos < 0 || pos >= SLL_Length(head))
						cout << "\nNhap sai vi tri!\n\n";
					else {
						//Xoa dau danh sach
						if (pos == 0)
							SLL_Remove_First(head);

						//Xoa cuoi danh sach
						else if (pos == SLL_Length(head) - 1)
							SLL_Remove_Last(head);

						//Xoa giua danh sach
						else
							SLL_Remove_Mid(head, pos);
						cout << "Da xoa data khoi danh sach!\n";
					}
				} while (pos != -1);
				break;
			case 5:
				system("cls");
				if (SLL_isEmpty(head)) {
					cout << "Danh sach trong!";
					break;
				}
				SLL_Reverse(head);
				cout << "\nDanh sach lien ket sau khi dao nguoc: \n";
				SLL_Output_List(head);
				cout << "<-- DATA";
				cout << endl;
				for (int i = 0; i < SLL_Length(head); i++)
					cout << i << " ";
				cout << "<-- POS\n";
				break;
			case 6:
				system("cls");
				SLL_Clear(head);
				cout << "Da xoa danh sach!";
				break;
			case 9:
				system("cls");
				SLL_Output_List(head);
				//cout << "<-- DATA";
				cout << endl;
				for (int i = 0; i < SLL_Length(head); i++)
					cout << i << " ";
				/*cout << "<-- POS\n";*/
				break;
			case 10:
				system("cls");
				SLL_Add_First(head, 1);
				SLL_Add_Mid(head, 2, 1);
				SLL_Add_Last(head, 3);
				SLL_Add_Last(head, 4);
				cout << "Da them!";
				break;
			case -1:
				system("cls");
				return;
			default:
				system("cls");
				cout << "Nhap sai cu phap!\n";
				break;
		}
	} while (choose != 0);
}

void show_Menu_DLL() {
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "     DOUBLE LINKED LIST\n\n";
	cout << "1. Khoi tao danh sach\n";
	cout << "2. Them phan tu vao danh sach\n";
	cout << "3. Sua phan tu trong danh sach\n";
	cout << "4. Xoa phan tu trong danh sach\n";
	cout << "5. Dao nguoc danh sach\n";
	cout << "6. Xoa toan bo danh sach\n";
	cout << "9. Xuat danh sach\n\n";
	cout << "[-1]. Quay tro lai menu chinh\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

void menu_DLL(DLLNode& head) {
	int choose, data, pos, pos1, pos2;
	do {
		show_Menu_DLL();
		cout << "Nhap lua chon: ";
		cin >> choose;
		switch (choose) {
			case 1:
				system("cls");
				DLL_Init(head);
				break;
			case 2:
				system("cls");
				cout << "Nhap data muon them: ";
				cin >> data;
				if (DLL_isEmpty(head))
					DLL_Add_First(head, data);
				else {
					cout << "\nChon vi tri muon them (1. Dau danh sach, 2. Giua danh sach, 3. Cuoi danh sach): ";
					cin >> pos1;
					switch (pos1) {
						case 1:
							DLL_Add_First(head, data);
							break;
						case 2:
							do {
								cout << "Nhap vi tri cu the de them vao danh sach: ";
								cin >> pos2;
								if (pos2 <= 0 || pos2 >= DLL_Length(head))
									cout << "Nhap sai vi tri!";
							} while (pos2 <= 0 && pos2 >= DLL_Length(head));
							DLL_Add_Mid(head, data, pos2);
							break;
						case 3:
							DLL_Add_Last(head, data);
							break;
						default:
							cout << "\nNhap sai cu phap!\n";
							break;
					}
				}
				break;
			case 3:
				system("cls");
				do {
					cout << "\nChon vi tri muon sua (Nhap [-1] de thoat): ";
					cin >> pos;
					if (pos == -1) break;
					else if (pos < 0 || pos >= DLL_Length(head))
						cout << "\nNhap sai vi tri!\n\n";
					else {
						int data;
						cout << "Nhap data muon sua: ";
						cin >> data;

						//Sua dau danh sach
						if (pos == 0)
							DLL_Update_First(head, data);

						//Sua cuoi danh sach
						else if (pos == DLL_Length(head) - 1)
							DLL_Update_Last(head, data);

						//Sua giua danh sach
						else
							DLL_Update_Mid(head, data, pos);
						cout << "Da thay doi data!\n";
					}
				} while (pos != -1);
				break;
			case 4:
				system("cls");
				do {
					cout << "\nChon vi tri muon xoa (Nhap [-1] de thoat): ";
					cin >> pos;
					if (pos == -1) break;
					else if (pos < 0 || pos >= DLL_Length(head))
						cout << "\nNhap sai vi tri!\n\n";
					else {
						//Xoa dau danh sach
						if (pos == 0)
							DLL_Remove_First(head);

						//Xoa cuoi danh sach
						else if (pos == DLL_Length(head) - 1)
							DLL_Remove_Last(head);

						//Xoa giua danh sach
						else
							DLL_Remove_Mid(head, pos);
						cout << "Da xoa data khoi danh sach!\n";
					}
				} while (pos != -1);
				break;
			case 5:
				system("cls");
				if (DLL_isEmpty(head)) {
					cout << "Danh sach trong!";
					break;
				}
				DLL_Reverse(head);
				cout << "\nDanh sach lien ket sau khi dao nguoc: \n";
				DLL_Output_List(head);
				cout << "<-- DATA";
				cout << endl;
				for (int i = 0; i < DLL_Length(head); i++)
					cout << i << " ";
				cout << "<-- POS\n";
				break;
			case 6:
				system("cls");
				DLL_Clear(head);
				cout << "Da xoa danh sach!";
				break;
			case 9:
				system("cls");
				DLL_Output_List(head);
				//cout << "<-- DATA";
				cout << endl;
				for (int i = 0; i < DLL_Length(head); i++)
					cout << i << " ";
				/*cout << "<-- POS\n";*/
				break;
			case 10:
				system("cls");
				DLL_Add_First(head, 1);
				DLL_Add_Mid(head, 2, 1);
				DLL_Add_Last(head, 3);
				DLL_Add_Last(head, 4);
				cout << "Da them!";
				break;
			case -1:
				system("cls");
				return;
			default:
				system("cls");
				cout << "Nhap sai cu phap!\n";
				break;
		}
	} while (choose != 0);
}

void show_Menu_CLL() {
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "     CIRCULAR LINKED LIST\n\n";
	cout << "1. Khoi tao danh sach\n";
	cout << "2. Them phan tu vao danh sach\n";
	cout << "3. Sua phan tu trong danh sach\n";
	cout << "4. Xoa phan tu trong danh sach\n";
	cout << "5. Dao nguoc danh sach\n";
	cout << "6. Xoa toan bo danh sach\n";
	cout << "9. Xuat danh sach\n\n";
	cout << "[-1]. Quay tro lai menu chinh\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

void menu_CLL(CLLNode& head) {
	int choose, data, pos, pos1, pos2;
	do {
		show_Menu_CLL();
		cout << "Nhap lua chon: ";
		cin >> choose;
		switch (choose) {
			case 1:
				system("cls");
				CLL_Init(head);
				break;
			case 2:
				system("cls");
				cout << "Nhap data muon them: ";
				cin >> data;
				if (CLL_isEmpty(head))
					CLL_Add_First(head, data);
				else {
					cout << "\nChon vi tri muon them (1. Dau danh sach, 2. Giua danh sach, 3. Cuoi danh sach): ";
					cin >> pos1;
					switch (pos1) {
						case 1:
							CLL_Add_First(head, data);
							break;
						case 2:
							do {
								cout << "Nhap vi tri cu the de them vao danh sach: ";
								cin >> pos2;
								if (pos2 <= 0 || pos2 >= CLL_Length(head))
									cout << "Nhap sai vi tri!";
							} while (pos2 <= 0 && pos2 >= CLL_Length(head));
							CLL_Add_Mid(head, data, pos2);
							break;
						case 3:
							CLL_Add_Last(head, data);
							break;
						default:
							cout << "\nNhap sai cu phap!\n";
							break;
					}
				}
				break;
			case 3:
				system("cls");
				do {
					cout << "\nChon vi tri muon sua (Nhap [-1] de thoat): ";
					cin >> pos;
					if (pos == -1) break;
					else if (pos < 0 || pos >= CLL_Length(head))
						cout << "\nNhap sai vi tri!\n\n";
					else {
						int data;
						cout << "Nhap data muon sua: ";
						cin >> data;

						//Sua dau danh sach
						if (pos == 0)
							CLL_Update_First(head, data);

						//Sua cuoi danh sach
						else if (pos == CLL_Length(head) - 1)
							CLL_Update_Last(head, data);

						//Sua giua danh sach
						else
							CLL_Update_Mid(head, data, pos);
						cout << "Da thay doi data!\n";
					}
				} while (pos != -1);
				system("cls");
				break;
			case 4:
				system("cls");
				do {
					cout << "\nChon vi tri muon xoa (Nhap [-1] de thoat): ";
					cin >> pos;
					if (pos == -1) break;
					else if (pos < 0 || pos >= CLL_Length(head))
						cout << "\nNhap sai vi tri!\n\n";
					else {
						//Xoa dau danh sach
						if (pos == 0)
							CLL_Remove_First(head);

						//Xoa cuoi danh sach
						else if (pos == CLL_Length(head) - 1)
							CLL_Remove_Last(head);

						//Xoa giua danh sach
						else
							CLL_Remove_Mid(head, pos);
						cout << "Da xoa data khoi danh sach!\n";
					}
				} while (pos != -1);
				break;
			case 5:
				system("cls");
				if (CLL_isEmpty(head)) {
					cout << "Danh sach trong!";
					break;
				}
				CLL_Reverse(head);
				cout << "\nDanh sach lien ket sau khi dao nguoc: \n";
				CLL_Output_List(head);
				cout << "<-- DATA";
				cout << endl;
				for (int i = 0; i < CLL_Length(head); i++)
					cout << i << " ";
				cout << "<-- POS\n";
				break;
			case 6:
				system("cls");
				CLL_Clear(head);
				cout << "Da xoa danh sach!";
				break;
			case 9:
				system("cls");
				CLL_Output_List(head);
				//cout << "<-- DATA";
				cout << endl;
				for (int i = 0; i < CLL_Length(head); i++)
					cout << i << " ";
				/*cout << "<-- POS\n";*/
				break;
			case 10:
				system("cls");
				CLL_Add_First(head, 1);
				CLL_Add_Mid(head, 2, 1);
				CLL_Add_Last(head, 3);
				CLL_Add_Last(head, 4);
				cout << "Da them!";
				break;
			case -1:
				system("cls");
				return;
			default:
				system("cls");
				cout << "Nhap sai cu phap!\n";
				break;
		}
	} while (choose != 0);
}