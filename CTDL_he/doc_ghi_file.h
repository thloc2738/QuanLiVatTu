#pragma once
#include "ctdl.h"
#include "xu_ly_de.h"
#include"linhtinh.h"
//=============== khoi  tao danh sach hoa don ==================
void Khoi_tao_ds_hd(DS_HOA_DON& ds_hd)
{
	ds_hd.pHead = ds_hd.pTail = NULL;
	//ds_hd.pTail = NULL;
}
//================= them hoa don vao cuoi =======================
void them_hd_vao_cuoi(DS_HOA_DON& ds_hd, HOA_DON* p)
{
	if (ds_hd.pHead == NULL)
	{
		ds_hd.pHead = ds_hd.pTail = p;
	}
	else
	{
		ds_hd.pTail->pNext = p;
		ds_hd.pTail = p;
	}
	ds_hd.sl++;
}
//================== doc file ds vat tu ================
void Luu_vattu(tree t, fstream& file) // save vat tu
{
	file << t->ma_vt <<',' << t->ten_vt <<',' << t->so_luong_ton << ',' << t->don_vi_tinh << endl;
	//file << t->kt << endl;
}

void Ghi_vattu_vao_file(tree t, fstream& file)
{
	if (t != NULL)
	{
		Luu_vattu(t, file);
		Ghi_vattu_vao_file(t->pLeft, file);
		Ghi_vattu_vao_file(t->pRight, file);
	}
}


void Luu_ds_vattu_vao_file(DS_VAT_TU &ds_vt)
{

	fstream outFile;
	outFile.open("DSVT.txt", ios::out);
	if (outFile.is_open())
	{

		outFile << ds_vt.sl++ << endl;
		Ghi_vattu_vao_file(ds_vt.TREE, outFile);
	}
	else
	{
		cout << "KET NOI VOI FILE DSHK THAT BAI! ";
	}
	outFile.close();
}

void Doc_vattu_tu_file(DS_VAT_TU &ds_vt)
{
	fstream inFile;
	
	int n;

	inFile.open("DSVT.txt", ios::in);
	if (inFile.is_open())
	{
		inFile >> ds_vt.sl;
		inFile.ignore();
		for (int i = 0; i <ds_vt.sl; i++)
		{
			tree ma = khoi_tao_node_vt();
			getline(inFile, ma->ma_vt,',');
			getline(inFile, ma->ten_vt, ',');
			getline(inFile, ma->don_vi_tinh, ',' );
			inFile >> ma->so_luong_ton;
			//inFile.ignore();
			//inFile >> ma->kt;
			inFile.ignore();
			them_1_vt(ds_vt.TREE, ma);
			//InsertMaterialToTree(t, ma);
		}
	}
	else {
		cout << "KET NOI VOI FILE DSHK THAT BAI! ";
	}

	inFile.close();
}
//=============================================
void doc_file_ds_vt(DS_VAT_TU &ds_vt)
{
	ifstream filein;
	filein.open("ds_vt.txt", ios_base::in);
	filein >> ds_vt.sl;
	filein.ignore();
	for (int i = 0; i < ds_vt.sl; i++)
	{
		VAT_TU* x = khoi_tao_node_vt();
		getline(filein, x->ma_vt, ',');
		getline(filein, x->ten_vt, ',');
		getline(filein, x->don_vi_tinh, ',');
		filein >> x->so_luong_ton;
		//filein.ignore();
		//filein >> x->kt;
		filein.ignore();
		them_1_vt(ds_vt.TREE,x);
	}
	filein.close();
}
// ---------------------- DOC GHI FILE NHAN VIEN
void Luu_nv_vao_file(NHAN_VIEN *nv, fstream& file)
{
	file << nv->ma_nv << ',' << nv->ho << ',' << nv->ten << ',' << nv->phai << ',' << nv->cmnd << endl;

	file << nv->danh_sach_hd.sl << endl;
	for (HOA_DON* p = nv->danh_sach_hd.pHead; p != NULL; p = p->pNext)
	{
		file <<p->so_hd << ',' << p->ngay_lap_hd.Ngay << ',' << p->ngay_lap_hd.Thang << ',' << p->ngay_lap_hd.Nam << ',' << p->loai << endl;
		file << p->danh_sach_chi_tiet_hd.sl << endl;
		for (int i =0;i<p->danh_sach_chi_tiet_hd.sl;i++)
		{
			file << p->danh_sach_chi_tiet_hd.ds[i].ma_vt << ',' << p->danh_sach_chi_tiet_hd.ds[i].so_luong << ',' << p->danh_sach_chi_tiet_hd.ds[i].don_gia << ',' << p->danh_sach_chi_tiet_hd.ds[i].VAT << ',' << p->danh_sach_chi_tiet_hd.ds[i].trang_thai << endl;
		}
	}
}

void Luu_ds_nv_vao_file(DS_NHAN_VIEN &ds_nv)
{
	fstream outFile;
	outFile.open("DSNV.txt", ios::out);
	if (outFile.is_open())
	{
		outFile << ds_nv.sl << endl;
		for (int i = 0; i < ds_nv.sl; i++)
		{
			Luu_nv_vao_file(ds_nv.ds[i], outFile);
		}
	}
	else
	{

		cout << "KET NOI VOI FILE THAT BAI! ";
	}

	outFile.close();
}
//==================================
void Doc_ds_nv_tu_file (DS_NHAN_VIEN &ds_nv)
{
	fstream inFile;

	int sl_NV, sl_HD, sl_CTHD;

	inFile.open("DSNV.txt", ios::in);

	if (inFile.is_open())
	{
		string temp;
		inFile >> sl_NV;

		for (int i = 0; i < sl_NV; i++)
		{
			ds_nv.ds[i] = new NHAN_VIEN;

			inFile >> ds_nv.ds[i]->ma_nv;
			getline(inFile, temp);
			getline(inFile,ds_nv.ds[i]->ho, ',');
			getline(inFile,ds_nv.ds[i]->ten, ',');
			inFile >> ds_nv.ds[i]->phai;
			inFile.ignore();
			getline(inFile, ds_nv.ds[i]->cmnd, ',');
			inFile >> sl_HD;

			Khoi_tao_ds_hd(ds_nv.ds[i]->danh_sach_hd);

			HOA_DON* hdon = new HOA_DON;
			for (int j = 0; j < sl_HD; j++)
			{
				getline(inFile, temp);
				getline(inFile, hdon->so_hd, ',');

				inFile >> hdon->ngay_lap_hd.Ngay;
				inFile >> hdon->ngay_lap_hd.Thang;
				inFile >> hdon->ngay_lap_hd.Nam;
				getline(inFile, temp);
				inFile >> hdon->loai;


				
				inFile >> sl_CTHD;

				for (int k = 0; k < sl_CTHD; k++)
				{
					getline(inFile, temp);
					getline(inFile, hdon->danh_sach_chi_tiet_hd.ds[k].ma_vt, ',');
					inFile >> hdon->danh_sach_chi_tiet_hd.ds[k].so_luong;
					inFile >> hdon->danh_sach_chi_tiet_hd.ds[k].don_gia;
					inFile >> hdon->danh_sach_chi_tiet_hd.ds[k].VAT;
					inFile >> hdon->danh_sach_chi_tiet_hd.ds[k].trang_thai;
					hdon->danh_sach_chi_tiet_hd.sl++;
				}

				them_hd_vao_cuoi(ds_nv.ds[i]->danh_sach_hd, hdon);
			}
			ds_nv.sl++;
		}
	}

	inFile.close();
}

