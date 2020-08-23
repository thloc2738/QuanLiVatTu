#pragma once
#include<iostream>
#include<string>
#include<cstdlib> // rand, sprand
#include<ctime>
#include<conio.h>
#include<fstream>
#define MaxNV 500
#define dscthd 20
int pointer = 7;
#pragma warning(disable:4996)
using namespace std;
//=================== Vat tu ================================== Cay nhi phann
struct VAT_TU
{
	//data
	string ma_vt;
	string ten_vt;
	string don_vi_tinh;
	float so_luong_ton;
	bool kt;//true: da dc lap hoa don, false: chua lap hoa don
	//pointer
	struct VAT_TU* pLeft;
	struct VAT_TU* pRight;
};
typedef struct VAT_TU* tree;
struct DS_VAT_TU
{
	tree TREE = NULL;
	int sl = 0;
};
//=================== Danh sach chi tiet hoa don ============== Danh sach tuyen tinh
struct CHI_TIET_HOA_DON
{
	string ma_vt;
	float so_luong;
	int don_gia;
	float VAT;//thue
	int trang_thai; //1: khach mua, 0: khach tra
};
struct DS_CHI_TIET_HD
{
	CHI_TIET_HOA_DON ds[dscthd];
	int sl=0;
};
//=================== Danh sach hoa don ======================= Danh sach lien ket don
struct Date
{
	int Ngay;
	int Thang;
	int Nam;
};
struct HOA_DON
{
	//data
	string so_hd;
	Date ngay_lap_hd;
	char loai; //X:hoa don xuat, N: hoa don nhap
	//danh sach chi tiet hoa don
	DS_CHI_TIET_HD danh_sach_chi_tiet_hd;
	//pointer
	HOA_DON* pNext;
};
struct DS_HOA_DON
{
	HOA_DON* pHead = NULL;
	HOA_DON* pTail = NULL;
	int sl = 0;
};
//=================== Danh sach nhan vien ===================== Mang con tro
struct NHAN_VIEN
{
	int ma_nv;
	string ho;
	string ten;
	string phai;
	string cmnd;
	// con tro den dshd
	DS_HOA_DON danh_sach_hd;
};

struct DS_NHAN_VIEN
{
	NHAN_VIEN* ds[MaxNV];
	int sl = 0;
};