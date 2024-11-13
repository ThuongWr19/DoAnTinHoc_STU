using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Phan2_Bai2
{
    public partial class FormQuanLyNhanVien : Form
    {
        private bool isAscending = true;
        xulyNhanVien xlNV;
        public FormQuanLyNhanVien()
        {
            InitializeComponent();
        }

        private void FormQuanLyNhanVien_Load(object sender, EventArgs e)
        {
            xlNV = new xulyNhanVien();
        }

        public void hienThi()
        {
            BindingSource bs = new BindingSource();
            bs.DataSource = xlNV.get_DSNV();
            dgv.DataSource = bs;
        }

        private void btnThem_Click(object sender, EventArgs e)
        {
            NhanVien new_NV = new NhanVien();
            new_NV.maNV = txtMaNV.Text;
            new_NV.tenNV = txtTenNV.Text;
            new_NV.queQuan = txtQueQuan.Text;
            new_NV.ngaySinh = dtpNgaySinh.Value;
            new_NV.hesoluong = double.Parse(txtHSL.Text);
            new_NV.luongcoban = double.Parse(txtLCB.Text);
            if(xlNV.them(new_NV) == true)
                hienThi();
            
            else
                MessageBox.Show("Thêm không thành công!");
            
        }

        private void btnSua_Click(object sender, EventArgs e)
        {
            NhanVien new_NV = new NhanVien();
            new_NV.maNV = txtMaNV.Text;
            new_NV.tenNV = txtTenNV.Text;
            new_NV.queQuan = txtQueQuan.Text;
            new_NV.ngaySinh = dtpNgaySinh.Value;
            new_NV.hesoluong = double.Parse(txtHSL.Text);
            new_NV.luongcoban = double.Parse(txtLCB.Text);
            if (xlNV.sua(new_NV) == true)
                hienThi();
            
            else
                MessageBox.Show("Sửa không thành công!");
            
        }

        private void btnXoa_Click(object sender, EventArgs e)
        {
            foreach(DataGridViewRow r in dgv.SelectedRows)
            {
                string maso = r.Cells[0].Value.ToString();
                if(xlNV.xoa(maso) == true)
                    hienThi();

                else
                   MessageBox.Show("Xóa không thành công!");
                
            }
        }

        private void btnLuongCao_Click(object sender, EventArgs e)
        {

            NhanVien nhanVienLuongCaoNhat = xlNV.get_DSNV().OrderByDescending(nv => nv.luong).FirstOrDefault();
            NhanVien nhanVienLuongThapNhat = xlNV.get_DSNV().OrderBy(nv => nv.luong).FirstOrDefault();

            if (nhanVienLuongCaoNhat != null && nhanVienLuongThapNhat != null)
            {
                MessageBox.Show($"Nhân viên có lương cao nhất:\n" +
                                $"Mã NV: {nhanVienLuongCaoNhat.maNV}, Tên: {nhanVienLuongCaoNhat.tenNV}, " +
                                $"Lương: {nhanVienLuongCaoNhat.luong}\n\n" +
                                $"Nhân viên có lương thấp nhất:\n" +
                                $"Mã NV: {nhanVienLuongThapNhat.maNV}, Tên: {nhanVienLuongThapNhat.tenNV}, " +
                                $"Lương: {nhanVienLuongThapNhat.luong}");
            }
            else
            
                MessageBox.Show("Không tìm thấy nhân viên.");
            
        }


    private void btnSapXep_Click(object sender, EventArgs e) {
            List<NhanVien> danhSachNhanVien = xlNV.get_DSNV();

            if (danhSachNhanVien == null || danhSachNhanVien.Count == 0)
            {
                MessageBox.Show("Danh sách nhân viên trống.");
                return;
            }

            if (isAscending)
            {
                List<NhanVien> dsNhanVien_TangDan = danhSachNhanVien.OrderBy(nv => nv.luong).ToList();
                dgv.DataSource = new BindingSource { DataSource = dsNhanVien_TangDan };
            }
            else
            {
                List<NhanVien> dsNhanVien_GiamDan = danhSachNhanVien.OrderByDescending(nv => nv.luong).ToList();
                dgv.DataSource = new BindingSource { DataSource = dsNhanVien_GiamDan };
            }

            isAscending = !isAscending;
        }

        private void btnDoc_Click(object sender, EventArgs e)
        {
            if(xlNV.docDuLieu("quanlynhanvien.txt") == true) {
                MessageBox.Show("Đọc dữ liệu thành công!");
                hienThi();
            }
            else
                MessageBox.Show("Lỗi khi đọc dữ liệu!.");
        }

        private void btnGhi_Click(object sender, EventArgs e)
        {
            if (xlNV.ghiDuLieu("quanlynhanvien.txt") == true)
                MessageBox.Show("Ghi dữ liệu thành công!");
            else
                MessageBox.Show("Lỗi khi ghi dữ liệu!.");
        }
    }
}
