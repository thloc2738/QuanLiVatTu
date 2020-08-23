#include "xu_ly_de.h"
int main()
{
	//DS_CHI_TIET_HD *ds_cthd;
	DS_NHAN_VIEN ds_nv;
	DS_VAT_TU ds_vt;
	//HOA_DON hd;
	//HOA_DON* p = new HOA_DON;
	// ds_hd;
	//doc_file_ds_nv(ds_nv);
	/*doc_file_ds_vt(ds_vt);*/
	Doc_vattu_tu_file(ds_vt);
	//Khoi_tao_ds_hd(ds_hd);
	Doc_ds_nv_tu_file(ds_nv);
	//ds_cthd = new DS_CHI_TIET_HD[dscthd]; // new 1 lần duy nhất
	Menu();
	while (true)
	{
		RunMenu(ds_vt, ds_nv);
	}

	

	return 0;
}