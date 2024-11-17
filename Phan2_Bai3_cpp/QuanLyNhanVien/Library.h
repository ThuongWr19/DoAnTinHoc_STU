#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

struct NhanVien {
	string tenNhanVien;
	string ngaySinh;
	string queQuan;
	float luongCoBan;
	float heSoLuong;
};

struct Node {
	NhanVien nhanVien;
	Node* next;
};

typedef struct Node* nodeptr;

nodeptr newNode(NhanVien NhanVien);
bool isEmpty(nodeptr head);
bool co_NhanVien(nodeptr head, string tenNhanVien);
void nhap_NhanVien(NhanVien& nhanVien);
void them_NhanVien(nodeptr& head, NhanVien nhanVien);
void xoa_NhanVien(nodeptr& head, string tenNhanVien);
void sua_NhanVien(nodeptr& head, string tenNhanVien, NhanVien nhanVien);
NhanVien NhanVien_LuongCaoNhat(nodeptr head);
NhanVien NhanVien_LuongThapNhat(nodeptr head);
void sapXep_DanhSachNhanVien_TangDan(nodeptr& head);
void sapXep_DanhSachNhanVien_GiamDan(nodeptr& head);
void output_header();
void xuat_NhanVien(NhanVien nhanVien);
void xuat_DanhSachNhanVien(nodeptr head); 
void Doc_File(string tenfile, nodeptr& head);
void xuatFile_NhanVien(nodeptr head, string tenFile);
void menu_QLNV(nodeptr& head);
//bool taoFile(const string& tenFile);
