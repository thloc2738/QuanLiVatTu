void themHDVaoCuoi(DS_HOA_DON& dsHD, HOA_DON* p)
{
	if (dsHD.pHead == NULL)
	{
		dsHD.pHead = dsHD.pTail = p;
	}
	else
	{
		dsHD.pTail->pNext = p;
		dsHD.pTail = p;
	}
}

void loadDSVT(DS_VAT_TU &dsVT)
{
	fstream inFile;
	inFile.open("DSVT.txt", ios::in);

	if (inFile.is_open())
	{
		inFile >> dsVT.sl;
		inFile.ignore();
		for (int i = 0; i <dsVT.sl; i++)
		{
			tree ma = khoi_tao_node_vt();
			getline(inFile, ma->ma_vt,',');
			getline(inFile, ma->ten_vt, ',');
			getline(inFile, ma->don_vi_tinh, ',' );
			inFile >> ma->so_luong_ton;
			inFile.ignore();
			them_1_vt(dsVT.TREE, ma);
		}
	}
	else {
		cout << "KET NOI VOI FILE DSHK THAT BAI! ";
	}

	inFile.close();
}
void loadDSNV(DS_NHAN_VIEN& dsNV)
{
	fstream inFile;
	inFile.open("DSNV.txt", ios::in);

	if (inFile.is_open())
	{
		inFile >> dsNV.sl;
		inFile.ignore();

		for (int i = 0; i < dsNV.sl; i++)
		{
			dsNV.ds[i] = new NHAN_VIEN;

			inFile >> dsNV.ds[i]->ma_nv;
			inFile.ignore();
			getline(inFile, dsNV.ds[i]->ho, ',');
			getline(inFile, dsNV.ds[i]->ten, ',');
			getline(inFile, dsNV.ds[i]->phai, ',');
			getline(inFile, dsNV.ds[i]->cmnd, ',');
			inFile >> dsNV.ds[i]->danh_sach_hd.sl;
			inFile.ignore();

			dsNV.ds[i]->danh_sach_hd.pHead = NULL;
			dsNV.ds[i]->danh_sach_hd.pTail = NULL;

			for (int j = 0; j < dsNV.ds[i]->danh_sach_hd.sl; j++)
			{
				HOA_DON* hdon = new HOA_DON;
				hdon->pNext = NULL;

				getline(inFile, hdon->so_hd, ',');
				inFile >> hdon->ngay_lap_hd.Ngay;
				inFile.ignore();
				inFile >> hdon->ngay_lap_hd.Thang;
				inFile.ignore();
				inFile >> hdon->ngay_lap_hd.Nam;
				inFile.ignore();
				inFile >> hdon->loai;
				inFile.ignore();
				inFile >> hdon->danh_sach_chi_tiet_hd.sl;
				inFile.ignore();

				for (int k = 0; k < hdon->danh_sach_chi_tiet_hd.sl; k++)
				{
					getline(inFile, hdon->danh_sach_chi_tiet_hd.ds[k].ma_vt,',');
					inFile >> hdon->danh_sach_chi_tiet_hd.ds[k].so_luong;
					inFile.ignore();
					inFile >> hdon->danh_sach_chi_tiet_hd.ds[k].don_gia;
					inFile.ignore();
					inFile >> hdon->danh_sach_chi_tiet_hd.ds[k].VAT;
					inFile.ignore();	
					inFile >> hdon->danh_sach_chi_tiet_hd.ds[k].trang_thai;
					inFile.ignore();
				}

				themHDVaoCuoi(dsNV.ds[i]->danh_sach_hd, hdon);
			}
		}
	}

	inFile.close();
}

void xuLySaveDSVT(tree root, ofstream &outFile)
{
	if (root == NULL)
	{
		return;
	}

	outFile << root->ma_vt << "," << root->ten_vt << "," << root->don_vi_tinh << "," << root->so_luong_ton << endl;
	xuLySaveDSVT(root->pLeft, outFile);
	xuLySaveDSVT(root->pRight, outFile);
}
void saveDSVT(DS_VAT_TU dsVT)
{
	ofstream outFile;
	outFile.open("DSVT.txt", ios::out);

	outFile << dsVT.sl<<endl;
	xuLySaveDSVT(dsVT.TREE, outFile);

	outFile.close();
}
void saveDSNV(DS_NHAN_VIEN dsNV)
{
	ofstream outFile;
	outFile.open("DSNV.txt", ios::out);
	outFile << dsNV.sl<<endl;

	for (int i = 0; i < dsNV.sl; i++)
	{
		outFile << dsNV.ds[i]->ma_nv<<","<<dsNV.ds[i]->ho << "," 
			<< dsNV.ds[i]->ten << "," << dsNV.ds[i]->phai << "," 
			<< dsNV.ds[i]->cmnd << "," << dsNV.ds[i]->danh_sach_hd.sl<<endl;
		
		for (HOA_DON *k=dsNV.ds[i]->danh_sach_hd.pHead;k!=NULL;k=k->pNext)
		{
			outFile << k->so_hd << "," 
				<< k->ngay_lap_hd.Ngay << "/" << k->ngay_lap_hd.Thang << "/" << k->ngay_lap_hd.Nam << ","
				<< k->loai << "," << k->danh_sach_chi_tiet_hd.sl<<endl;
			
			for (int j = 0; j < k->danh_sach_chi_tiet_hd.sl ; j++)
			{
				outFile << k->danh_sach_chi_tiet_hd.ds[i].ma_vt << ","
					<< k->danh_sach_chi_tiet_hd.ds[j].so_luong << ","
					<< k->danh_sach_chi_tiet_hd.ds[j].don_gia << ","
					<< k->danh_sach_chi_tiet_hd.ds[j].VAT << ","
					<< k->danh_sach_chi_tiet_hd.ds[j].trang_thai << endl;
			}
		}
	}
	outFile.close();
}
