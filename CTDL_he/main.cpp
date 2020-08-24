#include "xu_ly_de.h"
int main()
{
	DS_NHAN_VIEN ds_nv;
	DS_VAT_TU ds_vt;
	
	loadDSVT(ds_vt);
    loadDSNV(ds_nv);
	
	Menu();
	while (true)
	{
		RunMenu(ds_vt, ds_nv);
	}
	return 0;
}