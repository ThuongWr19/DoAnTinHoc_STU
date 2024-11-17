#include "Library.h"

void show_Menu_QLNV() {
	cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "	Quan ly nhan vien\n\n";
	cout << "1. Them nhan vien vao danh sach.\n";
	cout << "2. Sua thong tin nhan vien.\n";
	cout << "3. Xoa nhan vien khoi danh sach.\n";
	cout << "4. Tim nhan vien luong cao/thap nhat.\n";
	cout << "5. Sap xep danh sach theo luong.\n";
	cout << "6. Xuat danh sach nhan vien.\n";
	cout << "7. Xuat file du lieu.\n";
	cout << "8. Doc file du lieu.\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

void menu_QLNV(nodeptr &head) {
	NhanVien nv;
	string tenNV;
	int choose;
	do {
		show_Menu_QLNV();
		cout << "Nhap lua chon: ";
		cin >> choose;
		switch (choose) {
			case 1:
				system("cls");
				nhap_NhanVien(nv);
				them_NhanVien(head, nv);
				break;
			case 2:
				system("cls");
				cin.ignore();
				cout << "Nhap ten nhan vien can sua: ";
				getline(cin, tenNV);
				if (co_NhanVien(head, tenNV) == false) {
					cout << "Khong tim thay ten!";
					break;
				}
				nv.tenNhanVien = tenNV;
				cout << "Nhap ngay sinh nhan vien (dd/mm/yyyy): ";
				getline(cin, nv.ngaySinh);
				cout << "Nhap que quan nhan vien: ";
				getline(cin, nv.queQuan);
				cout << "Nhap luong co ban: ";
				cin >> nv.luongCoBan;
				cout << "Nhap he so luong: ";
				cin >> nv.heSoLuong;

				sua_NhanVien(head, nv.tenNhanVien, nv);
				break;
			case 3:
				system("cls");
				cin.ignore();
				cout << "Nhap ten nhan vien can xoa: ";
				getline(cin, tenNV);
				if (co_NhanVien(head, tenNV) == false) {
					cout << "Khong tim thay ten!";
					break;
				}
				xoa_NhanVien(head, tenNV);
				break;
			case 4:
			{
				system("cls");
				if (!isEmpty(head)) {
					NhanVien nvluongcao = NhanVien_LuongCaoNhat(head);
					NhanVien nvluongthap = NhanVien_LuongThapNhat(head);
					cout << "Nhan vien co luong cao nhat: \n";
					output_header();
					xuat_NhanVien(nvluongcao);
					cout << "\nNhan vien co luong thap nhat: \n";
					output_header();
					xuat_NhanVien(nvluongthap);
				}
				else
					cout << "Danh sach trong!";
				break;
			}
			case 5:
				system("cls");
				if(!isEmpty(head))
				{
					int sapxep;
					cout << "\n1. Sap xep theo luong tang dan.";
					cout << "\n2. Sap xep theo luong giam dan.";
					cout << "\nNhap lua chon: ";
					cin >> sapxep;
					switch (sapxep) {
						case 1:
							system("cls");
							sapXep_DanhSachNhanVien_TangDan(head);
							cout << "Da sap xep danh sach theo luong tang dan!\n";
							xuat_DanhSachNhanVien(head);
							break;
						case 2:
							system("cls");
							sapXep_DanhSachNhanVien_GiamDan(head);
							cout << "Da sap xep danh sach theo luong giam dan!\n";
							xuat_DanhSachNhanVien(head);
							break;
					}
				}
				else
					cout << "Danh sach trong!";
				break;
			case 6:
				system("cls");
				xuat_DanhSachNhanVien(head);
				break;
			case 7:
				system("cls");
				xuatFile_NhanVien(head, "NhanVien.txt");
				break;
			case 8:
				system("cls");
				Doc_File("NhanVien.txt", head);
				break;
			default:
				cout << "Nhap sai lua chon!";
				break;
		}
	} while (choose != 0);
}