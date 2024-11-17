#include "Library.h"

float tinhLuong(NhanVien nhanVien) {
	return nhanVien.luongCoBan * nhanVien.heSoLuong;
}

bool isEmpty(nodeptr head) {
	return head == NULL ? true : false;
}

nodeptr newNode(NhanVien NhanVien) {
	nodeptr new_Node = new Node();
	new_Node->nhanVien = NhanVien;
	new_Node->next = NULL;
	return new_Node;
}

bool co_NhanVien(nodeptr head, string tenNhanVien) {
	if (isEmpty(head)) {
		return false;
	}
	nodeptr curr = head;
	while (curr != NULL) {
		if (curr->nhanVien.tenNhanVien == tenNhanVien)
			return true;
		curr = curr->next;
	}
	return false;
}

void nhap_NhanVien(NhanVien& nhanVien) {
	cin.ignore();
	cout << "Nhap ho ten nhan vien: ";
	getline(cin, nhanVien.tenNhanVien);
	cout << "Nhap ngay sinh nhan vien (dd/mm/yyyy): ";
	getline(cin, nhanVien.ngaySinh);
	cout << "Nhap que quan nhan vien: ";
	getline(cin, nhanVien.queQuan);
	cout << "Nhap luong co ban: ";
	cin >> nhanVien.luongCoBan;
	cout << "Nhap he so luong: ";
	cin >> nhanVien.heSoLuong;
}

void them_NhanVien(nodeptr& head, NhanVien nhanVien) {
	nodeptr new_Node = newNode(nhanVien);

	if (isEmpty(head)) {
		head = new_Node;
		return;
	}
	new_Node->next = head;
	head = new_Node;
}

void xoa_NhanVien(nodeptr& head, string tenNhanVien) {
	if (isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}

	nodeptr curr = head;
	nodeptr prev = NULL;
	while (curr != NULL) {
		if (curr->next->nhanVien.tenNhanVien == tenNhanVien) {
			prev = curr;
			break;
		}
		curr = curr->next;
	}
	if (prev == NULL) {
		cout << "Khong tim thay nhan vien!";
		return;
	}

	nodeptr temp = prev->next;
	prev->next = temp->next;
	delete temp;
	cout << "Da xoa " << tenNhanVien << endl;
}

void sua_NhanVien(nodeptr& head, string tenNhanVien, NhanVien nhanVien) {
	if (isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	nodeptr curr = head;
	while (curr) {
		if (curr->nhanVien.tenNhanVien == tenNhanVien) {
			curr->nhanVien = nhanVien;
			cout << "Da sua thong tin cua nhan vien: " << tenNhanVien << " thanh cong!\n";
			return;
		}
		curr = curr->next;
	}
}

NhanVien NhanVien_LuongCaoNhat(nodeptr head) {
	if (isEmpty(head)) {
		cout << "Danh sach trong!";
		return NhanVien();
	}
	nodeptr curr = head;
	nodeptr maxLuong = curr;
	while (curr) {
		if (tinhLuong(curr->nhanVien) > tinhLuong(maxLuong->nhanVien))
			maxLuong = curr;
		curr = curr->next;
	}
	return maxLuong->nhanVien;
}

NhanVien NhanVien_LuongThapNhat(nodeptr head) {
	if (isEmpty(head)) {
		cout << "Danh sach trong!";
		return NhanVien();
	}
	nodeptr curr = head;
	nodeptr maxLuong = curr;
	while (curr) {
		if (tinhLuong(curr->nhanVien) < tinhLuong(maxLuong->nhanVien))
			maxLuong = curr;
		curr = curr->next;
	}
	return maxLuong->nhanVien;
}

void sapXep_DanhSachNhanVien_TangDan(nodeptr& head) {
	if (isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	for (nodeptr i = head; i != NULL; i = i->next)
		for (nodeptr j = i->next; j != NULL; j = j->next)
			if (tinhLuong(i->nhanVien) > tinhLuong(j->nhanVien))
				swap(i->nhanVien, j->nhanVien);
}

void sapXep_DanhSachNhanVien_GiamDan(nodeptr& head) {
	if (isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	for (nodeptr i = head; i != NULL; i = i->next)
		for (nodeptr j = i->next; j != NULL; j = j->next)
			if (tinhLuong(i->nhanVien) < tinhLuong(j->nhanVien))
				swap(i->nhanVien, j->nhanVien);
}

void output_header() {
	cout << setw(28) << left
		<< "Ten";
	cout << setw(14) << left
		<< "| Ngay sinh";
	cout << setw(14) << left
		<< "| Que quan";
	cout << setw(20) << left
		<< "| Luong co ban";
	cout << setw(15) << left
		<< "| He so luong";
	cout << setw(20) << left
		<< "| Luong" << endl;
}

void xuat_NhanVien(NhanVien nhanVien) {
	cout << setw(30) << left
		<< nhanVien.tenNhanVien;
	cout << setw(14) << left
		<< nhanVien.ngaySinh;
	cout << setw(14) << left
		<< nhanVien.queQuan;
	cout << setw(20) << left
		<< fixed << setprecision(2) << nhanVien.luongCoBan;
	cout << setw(15) << left
		<< nhanVien.heSoLuong;
	cout << setw(20) << left
		<< fixed << setprecision(2) << tinhLuong(nhanVien) << endl;
}
void xuat_DanhSachNhanVien(nodeptr head) {
	if (isEmpty(head)) {
		cout << "Danh sach trong!";
		return;
	}
	cout << setw(4) << left << "STT";
	cout << "| ";
	output_header();
	int stt = 1;
	while (head != NULL) {
		cout << setw(6) << left << stt;
		xuat_NhanVien(head->nhanVien);
		stt++;
		head = head->next;
	}
}


void Doc_File(string tenfile, nodeptr& head)
{
	ifstream file(tenfile);
	if (!file.is_open()) return;

	string line;
	while (getline(file, line)) {
		NhanVien nv;
		stringstream ss(line);

		getline(ss, nv.tenNhanVien, ',');
		getline(ss, nv.ngaySinh, ',');
		getline(ss, nv.queQuan, ',');

		string temp;
		getline(ss, temp, ',');
		nv.luongCoBan = stof(temp);
		getline(ss, temp);
		nv.heSoLuong = stof(temp);

		nv.tenNhanVien = nv.tenNhanVien.substr(nv.tenNhanVien.find_first_not_of(" "));
		nv.ngaySinh = nv.ngaySinh.substr(nv.ngaySinh.find_first_not_of(" "));
		nv.queQuan = nv.queQuan.substr(nv.queQuan.find_first_not_of(" "));

		them_NhanVien(head, nv);
	}
	cout << "Da doc file du lieu!";
	file.close();
}

void xuatFile_NhanVien(nodeptr head, string tenFile) {
	ofstream file(tenFile);
	if (!file.is_open()) {
		cout << "khong the mo tep " << tenFile << endl;
		return;
	}

	nodeptr curr = head;
	while (curr != NULL) {
		file << curr->nhanVien.tenNhanVien << ", "
			<< curr->nhanVien.ngaySinh << ", "
			<< curr->nhanVien.queQuan << ", "
			<< fixed << setprecision(0) << curr->nhanVien.luongCoBan << ", "
			<< fixed << setprecision(1) << curr->nhanVien.heSoLuong << endl;
		curr = curr->next;
	}

	file.close();
	cout << "Du lieu da xuat vao tep " << tenFile << "." << endl;
}