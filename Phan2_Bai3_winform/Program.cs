using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Phan2_Bai2
{
    internal static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new FormQuanLyNhanVien());
        }
    }
    [Serializable]
    class NhanVien
    {
        private string m_maNV;
        private string m_tenNV;
        private DateTime m_ngaySinh;
        private string m_queQuan;
        private double m_luongcoban;
        private double m_hesoluong;

        public NhanVien()
        {
            m_tenNV = "";
            m_ngaySinh = DateTime.Now;
            m_queQuan = "";
            m_luongcoban = 0.0;
            m_hesoluong = 0.0;
        }

        public string maNV
        {
            get { return m_maNV; }
            set { m_maNV = value; }
        }

        public string tenNV
        {
            get { return m_tenNV; }
            set { m_tenNV = value; }
        }
        public DateTime ngaySinh{
            get { return m_ngaySinh; }
            set { m_ngaySinh = value; }
        }

        public string queQuan
        {
            get { return m_queQuan; }
            set { m_queQuan = value; }
        }
        public double luongcoban
        {
            get { return m_luongcoban; }
            set { m_luongcoban = value; }
        }
        public double hesoluong
        {
            get { return m_hesoluong; }
            set { m_hesoluong = value; }
        }

        public double luong
        {
            get { return luongcoban * hesoluong; }
        }
    }

    class xulyNhanVien
    {
        Dictionary<string, NhanVien> danhsach_NV;

        public xulyNhanVien()
        {
            danhsach_NV = new Dictionary<string, NhanVien>();
        }

        public List<NhanVien> get_DSNV()
        {
            return danhsach_NV.Values.ToList();
        }

        public NhanVien tim(string maso)
        {
            try
            {
                return danhsach_NV[maso];
            }
            catch (Exception)
            {
                return null;
            }
        }

        public bool them(NhanVien nv)
        {
            if (nv == null) return false;
            try
            {
                danhsach_NV.Add(nv.maNV, nv);
                return true;
            }
            catch(Exception)
            {
                return false;
            }
        }

        public bool xoa(string maso)
        {
            try
            {
                danhsach_NV.Remove(maso);
                return true;
            }
            catch (Exception)
            {
                return false;
            }
        }

        public bool sua(NhanVien nv)
        {
            if (nv == null)
                return false;
            NhanVien x = tim(nv.maNV);
            if(x == null) return false;
            x.maNV = nv.maNV;
            x.tenNV = nv.tenNV;
            x.ngaySinh = nv.ngaySinh;
            x.queQuan = nv.queQuan;
            x.hesoluong = nv.hesoluong;
            x.luongcoban = nv.luongcoban;
            return true;
        }

        public bool docDuLieu(string tenfile)
        {
            try
            {
                FileStream fs = new FileStream(tenfile, FileMode.Open);
                BinaryFormatter bf = new BinaryFormatter();
                danhsach_NV = bf.Deserialize(fs) as Dictionary<string, NhanVien>;
                fs.Close();
                return true;
            }
            catch (Exception)
            {
                return false;
            }
        }

        public bool ghiDuLieu(string tenfile)
        {
            try
            {
                FileStream fs = new FileStream(tenfile, FileMode.Create);
                BinaryFormatter bf = new BinaryFormatter();
                bf.Serialize(fs, danhsach_NV);
                fs.Close();
                return true;
            }
            catch (Exception)
            {
                return false;
            }
        }
    }
}


