#pragma once
#include "ctdl.h"
#include "linhtinh.h"
#include "doc_ghi_file.h"


//================================================

bool kt_trung_ma_vt(tree t, string ma)
{
	if (t == NULL)
	{
		return false;
	}
	else
	{
		if (t->ma_vt==ma)
		{
			return true;
		}
		else if (t->ma_vt > ma)
		{
			 return kt_trung_ma_vt(t->pLeft, ma);
		}
		else
		{
			return kt_trung_ma_vt(t->pRight, ma);
		}
	}
}
tree kt_trung_node(tree t, string ma)
{
	if (t == NULL)
	{
		return NULL;
	}
	else
	{
		if (t->ma_vt == ma)
		{
			return t;
		}
		else if (t->ma_vt > ma)
		{
			return kt_trung_node(t->pLeft, ma);
		}
		else
		{
			return kt_trung_node(t->pRight, ma);
		}
	}
}
void nhap_vat_tu(DS_VAT_TU & ds_vt)
{
	VAT_TU* p = khoi_tao_node_vt();
	
	
	cout << "\nNhap ma vat tu:(ESC de thoat) ";
	p->ma_vt = XuLyNhapMa();
	if (p->ma_vt == "")
	{
		return;
	}
	//p->ma_vt = XuLyNhapMa();
	if (kt_trung_ma_vt(ds_vt.TREE, p->ma_vt) == true)
	{
		do
		{
			cout << "\nMa vat tu da ton tai!, moi nhap lai: " << endl;
			cout << "\nNhap ma vat tu: ";
			p->ma_vt = XuLyNhapChu();
		} while (kt_trung_ma_vt(ds_vt.TREE, p->ma_vt) == true);
	}

	cout << "\nNhap ten vat tu: ";
	p->ten_vt = XuLyNhapChu();

	cout << "\nNhap don vi tinh: ";
	p->don_vi_tinh = XuLyNhapChu();
	cout << "\nNhap so luong ton: ";
	p->so_luong_ton = XuLyNhapFloat();
	them_1_vt(ds_vt.TREE, p);
	ds_vt.sl++;
}


//===================== xuat danh sach vat tu ====================================
void duyet_RNL(tree t)
{
	if (t != NULL)
	{
		duyet_RNL(t->pRight);
		cout << "================ vat tu =================" << endl;
		cout << "Ma vat tu: " << t->ma_vt << endl;
		cout << "Ten vat tu: " << t->ten_vt << endl;
		cout << "Don vi tinh: " << t->don_vi_tinh << endl;
		cout << "So luong ton: " << t->so_luong_ton << endl;
		duyet_RNL(t->pLeft);
	}
}
void chuyen_cay_sang_mang(tree t, VAT_TU* ds[], int& nds)
{
	if (t != NULL)
	{
		ds[nds] = new VAT_TU;
		
		//data
		ds[nds]->ma_vt = t->ma_vt; 
		ds[nds]->ten_vt = t->ten_vt;
		ds[nds]->don_vi_tinh = t->don_vi_tinh;
		ds[nds]->so_luong_ton = t->so_luong_ton;
		nds++;
		chuyen_cay_sang_mang(t->pLeft, ds, nds);
		chuyen_cay_sang_mang(t->pRight, ds, nds);

	}
}
void in_ds_vat_tu(VAT_TU* ds[], int& sl)
{
	for (int i = 0; i < sl; i++)
	{
		cout << "================ vat tu " << i << "=================" << endl;
		cout << "Ma vat tu: " << ds[i]->ma_vt << endl;
		cout << "Ten vat tu: " << ds[i]->ten_vt << endl;
		cout << "Don vi tinh: " << ds[i]->don_vi_tinh << endl;
		cout << "So luong ton: " << ds[i]->so_luong_ton << endl;
	}
}
void hoan_vi_2_vt(VAT_TU*a, VAT_TU*b)
{
	VAT_TU *temp = new VAT_TU;
	temp->ma_vt = a->ma_vt;
	temp->ten_vt = a->ten_vt;
	temp->don_vi_tinh = a->don_vi_tinh;
	temp->so_luong_ton = a->so_luong_ton;
	temp->kt = a->kt;
	//===================================
	a->ma_vt = b->ma_vt;
	a->ten_vt = b->ten_vt;
	a->don_vi_tinh = b->don_vi_tinh;
	a->so_luong_ton = b->so_luong_ton;
	a->kt = b->kt;
	//===================================
	b->ma_vt = temp->ma_vt;
	b->ten_vt = temp->ten_vt;
	b->don_vi_tinh = temp->don_vi_tinh;
	b->so_luong_ton = temp->so_luong_ton;
	b->kt = temp->kt;
	delete temp;
}
void sap_xep_vt_giam(VAT_TU* ds[], int& sl)
{
	for (int i = 0; i < sl-1; i++)
	{
		for (int j = i + 1; j < sl; j++)
		{
			if (ds[i]->ma_vt < ds[j]->ma_vt)
			{
				hoan_vi_2_vt(ds[i], ds[j]);
			}
		}
	}
}
//===================== xoa vat tu =============================
void Node_the_mang(tree& X, tree& Y)
{
	if (Y->pLeft != NULL)
	{
		Node_the_mang(X, Y->pLeft);
	}
	else
	{
		X->ma_vt = Y->ma_vt;
		X->ten_vt = Y->ten_vt;
		X->don_vi_tinh = Y->don_vi_tinh;
		X->so_luong_ton = Y->so_luong_ton;
		//X = Y;
		Y = Y->pRight;
	}
}

void xoa_vt(tree &t,string ma)
{
	
	if (t == NULL)
	{
		return;
	}
	else
	{
		if (t->ma_vt > ma)
		{
			xoa_vt(t->pLeft,ma);
		}
		else if (t->ma_vt < ma)
		{
			xoa_vt(t->pRight, ma);
		}
		else
		{
			tree  X = t;
			if (t->pLeft == NULL)
			{
				t = t->pRight;
			}
			else if (t->pRight == NULL)
			{
				t = t->pLeft;
			}
			else
			{
				tree Y = t->pRight;
				Node_the_mang(X, Y);
			}
			delete X;
		}
	}

}


int kt_ma_vt(tree t, string ma)
{
	if (t == NULL)
	{
		return 0;
	}
	else
	{
		if (t->ma_vt == ma)
		{
			if (t->kt == false)
			{
				return 1;
			}
		}
		else if (t->ma_vt > ma)
		{
			kt_ma_vt(t->pLeft, ma);
		}
		else
		{
			kt_ma_vt(t->pRight, ma);
		}
	}
	return -1;
}

void hieu_chinh_1_vt(tree &t, string ma)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		if (t->ma_vt == ma)
		{
			cout << "Nhap ten vat tu: ";
			t->ten_vt = XuLyNhapChu();
			cout << "Don vi tinh: ";
			t->don_vi_tinh = XuLyNhapChu();
			/*chuan_hoa_chu(t->ten_vt);
			chuan_hoa_chu(t->don_vi_tinh);*/
		}
		else if (t->ma_vt > ma)
		{
			hieu_chinh_1_vt(t->pLeft,ma);
		}
		else if (t->ma_vt < ma)
		{
			hieu_chinh_1_vt(t->pRight,ma);
		}
	}
}
//============= them nhan vien ================
int kt_ma_nv(int a, DS_NHAN_VIEN ds_nv)
{
	for (int i = 0; i < ds_nv.sl; i++)
	{
		if (ds_nv.ds[i]->ma_nv == a)
		{
			return i;
		}
	}
	return -1;
}
void them_nhan_vien(DS_NHAN_VIEN& ds_nv)
{
	NHAN_VIEN* p = new NHAN_VIEN;
	
	cout << "\nNhap ma nhan vien: ";
	p->ma_nv = XuLyNhapSo();
	if (kt_ma_nv(p->ma_nv, ds_nv) >= 0)
	{
		do
		{
			cout << "\nMa nhan vien da ton tai!!!  Nhap lai ma nhan vien: ";
			p->ma_nv = XuLyNhapSo();
		} while (kt_ma_nv(p->ma_nv, ds_nv) >= 0);
	}
	cout << "\nNhap ho nhan vien: ";
	p->ho = XuLyNhapChu();
	cout << "\nNhap ten nhan vien: ";
	p->ten = XuLyNhapChu();
	cout << "\nNhap phai nhan vien: ";
	int phai;
	do
	{
		phai = XuLyNhapSo();
		if (phai != 1 && phai != 0)
		{
			cout << "\nThem phai khong thanh cong!!! moi nhap lai: 1: Nam; 0: Nu ";
		}
	} while (phai != 1 && phai != 0);
	if (phai == 1)
	{
		p->phai = "Nam";
	}
	else// if (phai == 0)
	{
		p->phai = "Nu";
	}
	
	cout << "\nNhap so chung minh nhan dan: ";
	p->cmnd = XuLyNhapMa(9);
	ds_nv.ds[ds_nv.sl] = p;
	ds_nv.sl++;
		
}
//=================== xuat ds nhan vien ================
void xuat_ds_nv(DS_NHAN_VIEN ds_nv)
{
	for (int i = 0; i < ds_nv.sl; i++)
	{
		cout << "\t\t================= NHAN VIEN " << i + 1 << "==================" << endl;
		cout << "Ma nhan vien: " << ds_nv.ds[i]->ma_nv << endl;
		cout << "Ho ten nhan vien: " << ds_nv.ds[i]->ho << " " << ds_nv.ds[i]->ten << endl;
		cout << "Phai nhan vien: " << ds_nv.ds[i]->phai << endl;
		cout << "So chung minh nhan dan: " << ds_nv.ds[i]->cmnd << endl;
	}
}

//================ sap xep danh sach nhan vien ============
void hoan_vi_2_nv(NHAN_VIEN  *a, NHAN_VIEN *b)
{
	NHAN_VIEN* tam = new NHAN_VIEN;
	tam->ma_nv = a->ma_nv;
	tam->ho = a->ho;
	tam->ten = a->ten;
	tam->phai = a->phai;
	tam->cmnd = a->cmnd;
	tam->danh_sach_hd = a->danh_sach_hd;
	//-------------------
	a->ma_nv = b->ma_nv;
	a->ho = b->ho;
	a->ten = b->ten;
	a->phai = b->phai;
	a->cmnd = b->cmnd;
	a->danh_sach_hd = b->danh_sach_hd;
	//------------------
	b->ma_nv = tam->ma_nv;
	b->ho = tam->ho;
	b->ten = tam->ten;
	b->phai = tam->phai;
	b->cmnd = tam->cmnd;
	b->danh_sach_hd = tam->danh_sach_hd;
	delete tam;
}
void sap_xep_ds_nv(DS_NHAN_VIEN& ds_nv)
{
	for (int i = 0; i < ds_nv.sl - 1; i++)
	{
		for (int j = i + 1; j < ds_nv.sl ; j++)
		{

			if (ds_nv.ds[i]->ten + ds_nv.ds[i]->ho >= ds_nv.ds[j]->ten + ds_nv.ds[j]->ho)
			{
				
					hoan_vi_2_nv(ds_nv.ds[i], ds_nv.ds[j]);
			}
		}
	}
}


//============================== xoa nhan vien ================================
void xoa_nhan_vien(DS_NHAN_VIEN& ds_nv)
{
	int a;
	cout << "Nhap ma nhan vien: ";
	cin >> a;
	//========================
	int vt = kt_ma_nv(a, ds_nv);
	//============ xoa ============
	//dời
	if (vt < 0)
	{
		cout << "Nhan vien khong ton tai";
		system("pause");
	}
	else
	{
		for (int i = vt; i < ds_nv.sl - 1; i++)
		{
			ds_nv.ds[i]->ma_nv = ds_nv.ds[i + 1]->ma_nv;
			ds_nv.ds[i]->ho = ds_nv.ds[i + 1]->ho;
			ds_nv.ds[i]->ten = ds_nv.ds[i + 1]->ten;
			ds_nv.ds[i]->phai = ds_nv.ds[i + 1]->phai;
			ds_nv.ds[i]->cmnd = ds_nv.ds[i + 1]->cmnd;

		}
		//giam so luong
		NHAN_VIEN* temp = ds_nv.ds[ds_nv.sl - 1];
		ds_nv.sl--;
		cout << "Da xoa thanh cong!" << endl;
		system("pause");
	}
	
}

//===================== hieu chinh nhan vien =================
void hieu_chinh__nv(DS_NHAN_VIEN& ds_nv)
{
	int phai;
	int a;
	cout << "Nhap ma nhan vien can hieu chinh: ";
	cin>>a;
	int vt = kt_ma_nv(a, ds_nv);
	if (vt < 0)
	{
		cout << "Ma khong ton tai" << endl;
	}
	else
	{
		//================ hieu chinh ================
		cout << "\nNhap ho nhan vien: ";
		ds_nv.ds[vt]->ho = XuLyNhapChu();
		cout << "\nNhap ten nhan vien: ";
		ds_nv.ds[vt]->ten = XuLyNhapChu();
		cout << "\nNhap phai nhan vien: ";
		do
		{
			phai = XuLyNhapSo();
			if (phai != 0 && phai != 1)
			{
				cout << "\nPhai khong ton tai!!! Nhap lai phai: 1: Nam, 0: Nu ";
			}
		} while (phai != 0 && phai != 1);
		if (phai == 1)
		{
			ds_nv.ds[vt]->phai = "Nam";
		}
		else //if (phai == 0)
		{
			ds_nv.ds[vt]->phai = "Nu";
		}
		
		//ds_nv.ds[vt]->phai = XuLyNhapChu();
		cout << "\nNhap so chung minh nhan dan: ";
		ds_nv.ds[vt]->cmnd = XuLyNhapMa(9);
		
		cout << "\nDa thay doi thong tin nhan vien!" << endl;
		system("pause");
	}
}



//====================== lap hoa don ====================
NHAN_VIEN* kt_trung_ma_nv(DS_NHAN_VIEN ds_nv, int ma)
{
	for (int i = 0; i < ds_nv.sl; i++)
	{
		if (ds_nv.ds[i]->ma_nv == ma)
		{
			return ds_nv.ds[i];
		}
	}
	return NULL;
}

//void Khoi_tao_ds_hd(DS_HOA_DON &ds_hd)
//{
//	ds_hd.pHead = ds_hd.pTail  = NULL;
//	//ds_hd.pTail = NULL;
//}
HOA_DON* khoi_tao_node_hd(HOA_DON &hd)
{
	HOA_DON* p = new HOA_DON;
	if (p == NULL)
	{
		cout << "Khong du bo nho cap phat !!!";
		return NULL;
	}
	p->so_hd = hd.so_hd;
	p->ngay_lap_hd = hd.ngay_lap_hd;
	p->loai = hd.loai;
	p->danh_sach_chi_tiet_hd = hd.danh_sach_chi_tiet_hd;
	p->pNext = NULL;
	return p;
}
//void them_hd_vao_cuoi(DS_HOA_DON& ds_hd, HOA_DON* p)
//{
//	if (ds_hd.pHead == NULL)
//	{
//		ds_hd.pHead = ds_hd.pTail = p;
//	}
//	else
//	{
//		ds_hd.pTail->pNext = p;
//		ds_hd.pTail = p;
//	}
//	ds_hd.sl++;
//}
bool ktra_ma(string a, string b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void xoa_ds_cthd(DS_CHI_TIET_HD &ds_cthd, string ma)
{
	
	for (int i = 0; i < ds_cthd.sl; i++)
	{
		if (ds_cthd.ds[i].ma_vt== ma)
		{
			for (int j = i; j < ds_cthd.sl-1; j++)
			{
				ds_cthd.ds[j].ma_vt = ds_cthd.ds[j + 1].ma_vt;
				ds_cthd.ds[j].so_luong = ds_cthd.ds[j + 1].so_luong;
				ds_cthd.ds[j].don_gia = ds_cthd.ds[j + 1].don_gia;
				ds_cthd.ds[j].VAT = ds_cthd.ds[j + 1].VAT;
				ds_cthd.ds[j].trang_thai = ds_cthd.ds[j + 1].trang_thai;
			}
			ds_cthd.sl--;
		}
	}
}

CHI_TIET_HOA_DON* ktr_cthd(DS_CHI_TIET_HD *ds_cthd, string macthd)
{
	CHI_TIET_HOA_DON* cthd = new CHI_TIET_HOA_DON;
	for (int i = 0; i < ds_cthd->sl; i++)
	{
		if (ds_cthd->ds[i].ma_vt == macthd)
		{
			*cthd = ds_cthd->ds[i];
		}
	}
	return NULL;
}

float ktra_soluongton(DS_VAT_TU ds_vt, DS_CHI_TIET_HD *ds_cthd)
{
	for (int i = 0; i < ds_cthd->sl; i++)
	{
		if (ktra_ma(ds_vt.TREE->ma_vt, ds_cthd->ds[i].ma_vt) == true)
		{
			return ds_vt.TREE->so_luong_ton;
		}
	}
}

tree getNodeVT(tree root,string maVT)
{
	if (root == NULL)
	{
		return NULL;
	}


	if (root->ma_vt == maVT)
	{
		return root;
	}
	else if (root->ma_vt < maVT)
	{
		return getNodeVT(root->pRight, maVT);
	}
	else
	{
		return getNodeVT(root->pLeft, maVT);
	}
}

void nhapCTHD(DS_VAT_TU &dsVT, DS_CHI_TIET_HD &dsCTHD, char loai)
{
	tree nodeVT=NULL;
	string maVT;
	//while (true)
	{
		cout << "\nNhap Ma VT: ";
		maVT = XuLyNhapMa();
		cout << endl;
		if (maVT == "")
		{
			return;
		}
		nodeVT = getNodeVT(dsVT.TREE, maVT);
		if (nodeVT == NULL)
		{
			cout << "Ma VT Khong Ton Tai";
			getch();
		}
		else
		{
			dsCTHD.ds[dsCTHD.sl].ma_vt = maVT;
			cout << "Nhap So Luong: ";
			dsCTHD.ds[dsCTHD.sl].so_luong = XuLyNhapFloat();
			cout << endl;

			if (loai == 'X')
			{
				nodeVT->so_luong_ton -= dsCTHD.ds[dsCTHD.sl].so_luong;
			}
			else
				nodeVT->so_luong_ton += dsCTHD.ds[dsCTHD.sl].so_luong;
			cout << "Nhap don gia: ";
			dsCTHD.ds[dsCTHD.sl].don_gia = XuLyNhapSo();
			cout << "\nNhap thue VAT: ";
			dsCTHD.ds[dsCTHD.sl].VAT = XuLyNhapSo();
			dsCTHD.ds[dsCTHD.sl].trang_thai = 1;
			dsCTHD.sl++;

		}
		
	}
}
void xoaCTHD(DS_VAT_TU& dsVT, DS_CHI_TIET_HD& dsCTHD, char loai)
{
	tree nodeVT = NULL;
	string maVT;
	//while (true)
	{
		cout << "Nhap Ma VT: ";
		maVT = XuLyNhapMa();
		if (maVT == "")
		{
			return;
		}
		nodeVT = getNodeVT(dsVT.TREE, maVT);
		if (nodeVT == NULL)
		{
			cout << "Ma VT Khong Ton Tai";
			getch();
		}
		else
		{
			for (int j = 0; j < dsCTHD.sl; j++)
			{
				if (dsCTHD.ds[j].ma_vt == maVT)
				{
					if (loai == 'X')
					{
						nodeVT->so_luong_ton += dsCTHD.ds[j].so_luong;
					}
					else
						nodeVT->so_luong_ton -= dsCTHD.ds[j].so_luong;



					for (int k = j; k < dsCTHD.sl - 1; k++)
					{
						dsCTHD.ds[k] = dsCTHD.ds[k + 1];
					}
					dsCTHD.sl--;
				}
			}
		}

		
	}
}
bool ktr_sohd(DS_NHAN_VIEN dsNV, string ma)
{
	for (int i =0;i<dsNV.sl;i++)
	{
		for (HOA_DON* k = dsNV.ds[i]->danh_sach_hd.pHead; k != NULL; k = k->pNext)
		{
			if (k->so_hd == ma)
			{
				return true;
			}
		}
	}
	return false;
}
bool kiem_tra_trung_ma_hd(DS_HOA_DON dsHD, string ma)
{
	//int dem = 0;
	for (HOA_DON* k = dsHD.pHead; k != NULL; k = k->pNext)
	{
		//++dem;
		if (k->so_hd == ma)
		{
			return true;
		}
	}
	return false;
}
void nhap_hoa_don(DS_NHAN_VIEN& ds_nv, DS_VAT_TU &dsVT)
{

	bool ktsohd;
	int manvlaphd;
	HOA_DON* p = new HOA_DON;
	//=========================== nhan vien lap hoa don ====================
	NHAN_VIEN* tam;
	do
	{
		cout << "Nhap ma nhan vien lap hoa don: ";
		manvlaphd = XuLyNhapSo();
		tam = kt_trung_ma_nv(ds_nv, manvlaphd);
		if (tam == NULL)
		{
			cout << "\nMa nhan vien khong ton tai!!" << endl;
		}
	}	while (tam == NULL);
	int loaihd;
	do
	{
		cout << "\nNhap loai hoa don lap: ";
		cout << "\n1: Lap hoa don nhap, 0: Lap hoa don xuat: ";
		loaihd = XuLyNhapSo();
		if (loaihd != 1 && loaihd != 0)
		{
			cout << "\nLoai hoa don khong ton tai!!! Nhap lai loai hoa don: 1: Nhap, 0: Xuat ";
		}
	} while (loaihd != 1 && loaihd != 0);
	if (loaihd == 1)
	{
		p->loai = 'N';
	}
	else
	{
		p->loai = 'X';
	}
		
	
	//========================== nhap hoa don ===========================
	do
	{
		cout << "\nNhap so hoa don: ";
		p->so_hd = XuLyNhapMa(20);
		//================== kiem tra so hoa don nhap vao da co nhan vien nao lap chua =========================
		ktsohd = ktr_sohd(ds_nv, p->so_hd);
		if (ktsohd == true)
		{
			cout << "\nSo hoa don da ton tai!" << endl;
		}
	} while (ktsohd == true);
	
	cout << "\nNgay lap hoa don: ";
	cout << " Ngay: ";
	p->ngay_lap_hd.Ngay = XuLyNhapSo();
	cout << " Thang: ";
	p->ngay_lap_hd.Thang = XuLyNhapSo();
	cout << " Nam: ";
	p->ngay_lap_hd.Nam = XuLyNhapSo();
	

	p->danh_sach_chi_tiet_hd.sl++;
	p->pNext = NULL;

	int luachon = 0;
	while (true)
	{
		system("cls");
		cout << "1. Nhap CTHD" << endl;
		cout << "2. Xoa CTHD"<<endl;
		cout << "3. Thoat" << endl;
		cout << "Chon: " << endl;
		luachon= XuLyNhapSo();

		switch (luachon)
		{
		case 1:
			nhapCTHD(dsVT, p->danh_sach_chi_tiet_hd, p->loai);
			break;
		case 2:
			xoaCTHD(dsVT, p->danh_sach_chi_tiet_hd, p->loai);
			break;
		case 3:
			them_hd_vao_cuoi(tam->danh_sach_hd, p);
			return;
		default:
			cout << "Input invalid";
			break;
		}
	}
}



void xuat_hoa_don(DS_NHAN_VIEN ds_nv)
{
	for (int i = 0; i < ds_nv.sl; i++)
	{
		cout << "\n================= NHAN VIEN " << i+ 1 << " =================" << endl;
		for (HOA_DON* k = ds_nv.ds[i]->danh_sach_hd.pHead; k !=NULL; k = k->pNext)
		{
			cout << "\n================= HOA DON " << k->so_hd << " =================" << endl;
			cout << "So hoa don: " << k->so_hd << endl;
			cout << "Ngay lap hoa don: " << k->ngay_lap_hd.Ngay << "/" << k->ngay_lap_hd.Thang << "/" << k->ngay_lap_hd.Nam << endl;
			cout << "Loai hoa don: " << k->loai << endl;
			for (int j = 0; j < k->danh_sach_chi_tiet_hd.sl; j++)
			{
				cout << "=============== Vat tu " << j + 1 << " =======================" << endl;
				cout << "Ma vat tu: " << k->danh_sach_chi_tiet_hd.ds[j].ma_vt << endl;
				cout << "So luong: " << k->danh_sach_chi_tiet_hd.ds[j].so_luong << endl;
				cout << "Don gia: " << k->danh_sach_chi_tiet_hd.ds[j].don_gia << endl;
				cout << "Phan tram VAT: " << k->danh_sach_chi_tiet_hd.ds[j].VAT << endl;
				cout << "Trang thai: " << k->danh_sach_chi_tiet_hd.ds[j].trang_thai << endl;
			}

		}
	}
}

void tra_hoadon(DS_NHAN_VIEN ds_nv, DS_VAT_TU ds_vt)
{
	bool kt = false;
	string ma;
	string mavttra;
	cout << "Nhap ma hoa don: ";
	ma = XuLyNhapMa();
	int dem = 0;
	//int j = 0;
	Date date_tra, ngaytra;
	tree vtu;
	for (int i = 0; i < ds_nv.sl; i++)
	{
		for (HOA_DON* k = ds_nv.ds[i]->danh_sach_hd.pHead; k != NULL; k = k->pNext)
		{
			
			if (k->so_hd == ma)
			{
				if (k->loai == 'X')
				{
					kt = true;
					//cout << "\n================= HOA DON " << k->so_hd << " =================" << endl;
					//cout << "So hoa don: " << k->so_hd << endl;
					//cout << "Ngay lap hoa don: " << k->ngay_lap_hd.Ngay << "/" << k->ngay_lap_hd.Thang << "/" << k->ngay_lap_hd.Nam << endl;
					//cout << "Loai hoa don: " << k->loai << endl;
					for (int i = 0; i < k->danh_sach_chi_tiet_hd.sl; i++)
					{
						cout << "\n=============== Vat tu " << i + 1 << " =======================" << endl;
						cout << "Ma vat tu: " << k->danh_sach_chi_tiet_hd.ds[i].ma_vt << endl;
						cout << "So luong: " << k->danh_sach_chi_tiet_hd.ds[i].so_luong << endl;
						cout << "Don gia: " << k->danh_sach_chi_tiet_hd.ds[i].don_gia << endl;
						cout << "Phan tram VAT: " << k->danh_sach_chi_tiet_hd.ds[i].VAT << endl;
						cout << "Trang thai: " << k->danh_sach_chi_tiet_hd.ds[i].trang_thai << endl;
					}
					while (true)
					{
						float soluong;
						cout << "Nhap ma vat tu can tra: (esc de thoat!): ";
						mavttra = XuLyNhapChu();
						if (mavttra == "")
						{
							return;
						}
						vtu = kt_trung_node(ds_vt.TREE, mavttra);
						for (int i = 0; i < k->danh_sach_chi_tiet_hd.sl; i++)
						{
							if (vtu->ma_vt == k->danh_sach_chi_tiet_hd.ds[i].ma_vt)
							{
								cout << "\nMa vat tu: " << k->danh_sach_chi_tiet_hd.ds[i].ma_vt;
								date_tra = CongNgay(k->ngay_lap_hd, 3);
								cout << "\nNhap ngay tra vat tu: ";
								cout << "Ngay: "; ngaytra.Ngay = XuLyNhapSo();
								cout << "Thang: "; ngaytra.Thang = XuLyNhapSo();
								cout << "Nam: "; ngaytra.Nam = XuLyNhapSo();
								if (SoSanhNgay(ngaytra, date_tra) >= 1)
								{
									cout << "\nQua han thoi gian cho tra hang! chi duoc tra hang trong vong 3 ngay!";
								}
								else
								{
									cout << "\nTen vat tu: " << vtu->ten_vt;
									cout << "\nNhap so luong cua vat tu can tra: ";
									soluong = XuLyNhapFloat();// so luong khach tra
									if (k->danh_sach_chi_tiet_hd.ds[i].so_luong >= soluong)
									{
										k->danh_sach_chi_tiet_hd.ds[i].trang_thai = 0;
										vtu->so_luong_ton += soluong;
										k->danh_sach_chi_tiet_hd.ds[i].so_luong -= soluong;
									}
									else if (k->danh_sach_chi_tiet_hd.ds[i].so_luong < soluong)
									{
										cout << "\nSo luong tra nhieu hon so luong xuat kho!";
										do
										{
											cout << "\nNhap so luong cua vat tu can tra: ";
											soluong = XuLyNhapFloat();
										} while (k->danh_sach_chi_tiet_hd.ds[i].so_luong < soluong);
										k->danh_sach_chi_tiet_hd.ds[i].trang_thai = 0;
										vtu->so_luong_ton += soluong;
										k->danh_sach_chi_tiet_hd.ds[i].so_luong -= soluong;

									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	if (kt == false)
	{
		cout << "So hoa don khong ton tai";
		//return;
	}
}
void xuat_hoa_don_theo_sohd(DS_NHAN_VIEN ds_nv)
{
	bool kt = false;
	string ma;
	cout << "Nhap ma hoa don: ";
	ma = XuLyNhapMa();
	
	for (int i = 0; i < ds_nv.sl; i++)
	{
		cout << "\n================= NHAN VIEN " << i+1 << " =================" << endl;
		for (HOA_DON* k = ds_nv.ds[i]->danh_sach_hd.pHead; k != NULL; k = k->pNext)
		{
			if (k->so_hd == ma)
			{
				kt = true;
				cout << "\n================= HOA DON " << k->so_hd << " =================" << endl;
				cout << "So hoa don: " << k->so_hd << endl;
				cout << "Ngay lap hoa don: " << k->ngay_lap_hd.Ngay << "/" << k->ngay_lap_hd.Thang << "/" << k->ngay_lap_hd.Nam << endl;
				cout << "Loai hoa don: " << k->loai << endl;
				for (int i = 0; i < k->danh_sach_chi_tiet_hd.sl; i++)
				{
					cout << "=============== Vat tu " << i + 1 << " =======================" << endl;
					cout << "Ma vat tu: " << k->danh_sach_chi_tiet_hd.ds[i].ma_vt << endl;
					cout << "So luong: " << k->danh_sach_chi_tiet_hd.ds[i].so_luong << endl;
					cout << "Don gia: " << k->danh_sach_chi_tiet_hd.ds[i].don_gia << endl;
					cout << "Phan tram VAT: " << k->danh_sach_chi_tiet_hd.ds[i].VAT << endl;
					cout << "Trang thai: " << k->danh_sach_chi_tiet_hd.ds[i].trang_thai << endl;
				}
			}
			

		}
	}
	if (kt == false)
	{
		cout << "So hoa don khong ton tai";
		//return;
	}
		
}


// Menu
string strMNMain[] = {
	" 1.  Nhap Vat Tu                      ",
	" 2.  In Danh Sach Vat Tu Theo Danh Sach Giam Dan",
	" 3.  Xoa Vat Tu                       ",
	" 4.  Hieu Chinh vat tu                ",
	" 5.  Them Nhan Vien                   ",
	" 6.  In Danh Sach Nhan Vien           ",
	" 7.  Xoa Nhan Vien                    ",
	" 8.  Hieu Chinh Nhan Vien             ",
	" 9.  Nhap hoa don                     ",
	" 10. Xuat hoa don                     ",
	" 11. Xuat hoa don theo ma hoa don     ",
	" 12. Tra hoa don                      ",
	//" 13. Xuat danh sach chi tiet hoa don  ",
	/*" 15. In danh sach mon hoc             ",
	" 16. Dang ky lop tin chi              ",
	" 17. Huy Lop                          ",
	" 18. Nhap diem                        ",
	" 19. In bang diem mon hoc             ",
	" 20. In diem trung binh               ",
	" 21. In diem tong ket                 ",*/
	" 0.  Ket thuc chuong trinh            "
};

void Menu()
{
	//textcolor(240);
	int j = 7;
	for (int i = 0; i < sizeof(strMNMain) / sizeof(*strMNMain); i++)
	{
		gotoXY(50, j++);
		cout << strMNMain[i];
	}
}
void RunMenu(DS_VAT_TU& ds_vt, DS_NHAN_VIEN& ds_nv)/* HOA_DON *hd,DS_HOA_DON &ds_hd, DS_CHI_TIET_HD* ds_cthd)*/
{
	//=================== khai bao bien ==============

	//=================== load file ==================	

	if (kbhit())
	{
		char c = getch();
		if (c == -32)
		{
			c = getch();
			if (c == 72)
			{
				if (pointer == 7)
				{
					Menu();
					pointer = 7 - 1 + sizeof(strMNMain) / sizeof(*strMNMain);
				}
				else
				{
					Menu();
					pointer--;
				}
			}
			else if (c == 80) // mã ascii mui tên xu?ng
			{
				if (pointer == 7 - 1 + sizeof(strMNMain) / sizeof(*strMNMain))
				{
					Menu();
					pointer = 7;
				}
				else
				{
					Menu();
					pointer++;
				}
			}
		}
		else if (c == 13)
		{
			system("cls");

			switch (pointer)
			{
			case 7:
			{
				nhap_vat_tu(ds_vt);
				break;
			}

			case 8:
			{
				VAT_TU* ds[100];
				int nds = 0;
				//duyet_RNL(ds_vt.TREE);
				chuyen_cay_sang_mang(ds_vt.TREE, ds, nds);
				sap_xep_vt_giam(ds, nds);
				in_ds_vat_tu(ds, nds);
				system("pause");
				break;
			}

			case 9:
			{
				cout << "Neu vat tu da duoc lap hoa don thi khong the xoa. " << endl;
				string ma;
				cout << "Nhap ma vat tu: ";
				ma = XuLyNhapMa();
				//=======================================
				if (kt_trung_ma_vt(ds_vt.TREE, ma) == true)
				{
					xoa_vt(ds_vt.TREE, ma);
					GiaoDienThongBao("Xoa thanh cong!!!");
				}
				else
				{
					GiaoDienThongBao("ma vat tu khong ton tai !!!");
				}
				break;
			}
			case 10:
			{
				string mavt;
				cout << "Nhap ma vat tu: ";
				getline(cin, mavt);
				if (kt_trung_ma_vt(ds_vt.TREE, mavt) == 1)
				{
					hieu_chinh_1_vt(ds_vt.TREE, mavt);
					cout << "Hieu chinh vat tu thanh cong!" << endl;
					system("pause");
				}
				else
				{
					cout << "Ma vat tu khong ton tai!" << endl;
					system("pause");
				}
				break;
			}
			case 11:
			{
				if (ds_nv.sl == MaxNV)
				{
					cout << "Them khong Thanh Cong! data day" << endl;
					system("pause");
				}
				else
				{
					them_nhan_vien(ds_nv);
					break;
				}
			}
			case 12:
			{
				//nhan_vien* ds[MaxNV];
				sap_xep_ds_nv(ds_nv);
				xuat_ds_nv(ds_nv);
				system("pause");
				break;
			}
			case 13:
			{
				if (ds_nv.sl == 0)
				{
					cout << "Xoa khong Thanh Cong! data rong" << endl;
				}
				else
				{
					xoa_nhan_vien(ds_nv);
				}
				break;
			}
			case 14:
			{
				if (ds_nv.sl == 0)
				{
					cout << "Data rong!" << endl;
				}
				else
				{
					hieu_chinh__nv(ds_nv);
				}
				break;
			}
			case 15:
			{
				nhap_hoa_don(ds_nv,ds_vt); // truyền danh sách vào để lấy giá trị trả về, tại vì trong hàm này nó thêm vào danh sách
				//xuat_hoa_don(ds_hd, ds_vt, ds_cthd,n); // truyền danh sách sau khi chạy hàm nhập vào để xuất
				system("pause");
				break;
			}
			case 16:
			{
				xuat_hoa_don(ds_nv);
				system("pause");
				break;
			}
			case 17:
			{
				xuat_hoa_don_theo_sohd(ds_nv);
				system("pause");
				break;
			}
			case 18:
			{
				tra_hoadon(ds_nv, ds_vt);
				system("pause");
				break;
			}
			case 20:
			{
				//xuat_dscthd(ds_cthd);
				system("pause");
				break;
			}
			case 19:
			{
				Luu_ds_nv_vao_file(ds_nv);
				Luu_ds_vattu_vao_file(ds_vt);
				exit(0);
			}
			}
			system("cls");
			GiaoDienMain();
			Menu();
		}
	}
	ShowCur(0);
	// to mau 
	textcolor(180);
	gotoXY(50, pointer);
	cout << strMNMain[pointer - 7];
	textcolor(7);
}