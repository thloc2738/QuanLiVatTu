//==============chuan hoa chu===================
void chuan_hoa_chu(string& chu)
{
	// |     tU    lAnH |
	//|Tu Lanh|
	//xu ly kt dau
	while (chu[0]==' ')
	{
		chu.erase(chu.begin() + 0);
	}
	// xu ly khoan trang cuoi
	while (chu[chu.length()-1] == ' ')
	{
		chu.erase(chu.begin() + chu.length() - 1);
	}
	// xoa kt giua
	for (int i = 0; i < chu.length(); i++)
	{
		if (chu[i] == ' ' && chu[i + 1] == ' ')
		{
			chu.erase(chu.begin() + i + 1);
			i--;
		}
	}
	//chuan hoa ki tu
	if (chu[0] >= 97 && chu[0] <= 122)
	{
		chu[0] -= 32;
	}
	for (int i = 1; i < chu.length(); i++)
	{
		if (chu[i] == ' ')
		{
			i++;
			if (chu[i] >= 97 && chu[i] <= 122)
			{
				chu[i] -= 32;
			}
		}
		else
		{
			if (chu[i] >= 65 && chu[i] <= 90)
			{
				chu[i] += 32;
			}
		}
	}
}

//============== do hoa ================
void gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;
	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}
//====================== ve hcn =============================
void VeHCN(int toadoX, int toadoY, int chieudai, int chieucao, int mauSet)
{
	SetColor(mauSet);
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, toadoY);
		if (i == toadoX)
			cout << (char)218;
		else if (i == chieudai + toadoX)
			cout << (char)191;
		else
			cout << (char)196;
	}
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, chieucao + toadoY);
		if (i == toadoX)
			cout << (char)192;
		else if (i == chieudai + toadoX)
			cout << (char)217;
		else
			cout << char(196);
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(toadoX, i);
		cout << (char)179;
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(chieudai + toadoX, i);
		cout << (char)179;
	}
	SetColor(7);
}
void ToMauHCN(int toadoX, int toadoY, int chieudai, int chieucao, int mauText)
{
	textcolor(mauText);
	for (int i = toadoY + 1; i < toadoY + chieucao; i++)
	{
		for (int j = toadoX + 1; j < chieudai + toadoX; j++)
		{
			gotoXY(j, i);
			cout << " ";
		}
	}
	textcolor(7);
}

void GiaoDienMain()
{
	ShowCur(0);

	for (int i = 50; i < 90; i++)
	{
		gotoXY(i, 5);
		cout << (char)205;
	}
	textcolor(7);

	gotoXY(60, 2);
	cout << "QUAN LI VAT TU";
	textcolor(7);
}
void GiaoDienThongBao(string x)
{
	ToMauHCN(30, 10, 40, 10, 95);
	textcolor(95);
	gotoXY(31, 13);
	cout << string((39 - x.length()) / 2, ' ') + x;
	getch();
	textcolor(7);
}
string XuLyNhapMa(int lengthmax=100)
{
	string input;
	ShowCur(1);
	gotoXY(whereX(), whereY());
	while (true)
	{
		char c = getch();
		if (((c >= 48 && c <= 57) || c == '_' || (c >= 65 && c <= 90)) && input.length() < lengthmax)
		{
			input.insert(input.begin() + input.length(), c);
			cout << c;
		}
		else if (c >= 97 && c <= 122 && input.length() < lengthmax)
		{
			c = c - 32;
			input.insert(input.begin() + input.length(), c);
			cout << c;
		}
		else if (c == 8 && input.length() > 0)
		{
			input.erase(input.begin() + input.length() - 1);
			cout << "\b";
			cout << " ";
			cout << "\b";
		}
		else if (c == 27)
		{
			input.clear();
			ShowCur(0);
			return input;
		}
		else if (c == 13 && input.length() > 0)// nếu là phím enter
		{
			ShowCur(0);
			return input;
		}
	}
}
string XuLyNhapChu()
{
	string input;
	ShowCur(1);
	gotoXY(whereX(), whereY());
	while (true)
	{
		char c = getch();
		if ((c >= 48 && c <= 57) || (c >= 97 && c <= 122) || c == '_' || (c >= 65 && c <= 90) && input.length() < 6)
		{
			input.insert(input.begin() + input.length(), c);
			cout << c;
		}
		else if (c == 8 && input.length() > 0)
		{
			input.erase(input.begin() + input.length() - 1);
			cout << "\b";
			cout << " ";
			cout << "\b";
		}
		else if (c == 27)
		{
			input.clear();
			ShowCur(0);
			return input;
		}
		else if (c == 13 && input.length() > 0)// nếu là phím enter
		{
			ShowCur(0);
			return input;
		}
		else if (c == 32 && input.length() > 0 && input[input.length() - 1] != ' ')
		{
			input.insert(input.begin() + input.length(), ' ');
			cout << c;
		}
	}
}
float XuLyNhapFloat()
{
	string x = "";
	char c;
	while (true)
	{
		c = getch();
		if ((c >= 48 && c <= 57) || c == 46)
		{
			x.insert(x.begin() + x.length(), c);
			cout << c;
		}
		else if (c == 8 && x.length() > 0)
		{
			x.erase(x.begin() + x.length() - 1);
			cout << "\b";
			cout << " ";
			cout << "\b";
		}
		else if (c == 13 && x.length() > 0)// n?u là phím enter
		{
			return atof(x.c_str());

		}
	}
	return true;
}
int XuLyNhapSo()
{
	int n;
	ShowCur(1);
	gotoXY(whereX(), whereY());
	string x = "";
	char c;
	while (true)
	{
		c = getch();
		if ((c >= 48 && c <= 57))// nếu là số thì
		{
			x.insert(x.begin() + x.length(), c);
			cout << c;
		}
		else if (c == 8 && x.length() > 0)
		{
			x.erase(x.begin() + x.length() - 1);
			cout << "\b";
			cout << " ";
			cout << "\b";
		}
		else if (c == 27)
		{
			ShowCur(0);
			return -1;
		}
		else if (c == 13 && x.length() > 0)// nếu là phím enter
		{

			n = atoi(x.c_str());
			ShowCur(0);
			return n;
		}

	}
}

VAT_TU* khoi_tao_node_vt()
{
	VAT_TU* p = new VAT_TU;
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}
void them_1_vt(tree& t, VAT_TU* p)
{
	if (t == NULL)
	{
		t = p;
	}
	else
	{
		if (p->ma_vt > t->ma_vt)
		{
			them_1_vt(t->pRight, p);
		}
		else if (p->ma_vt < t->ma_vt)
		{
			them_1_vt(t->pLeft, p);
		}
	}
}
//====================== xu ly ngay ======================
int ChuyenThang(string str)
{
	if (str == "Jan")
	{
		return 1;
	}
	else if (str == "Feb")
	{
		return 2;
	}
	else if (str == "Mar")
	{
		return 3;
	}
	else if (str == "Apr")
	{
		return 4;
	}
	else if (str == "May")
	{
		return 5;
	}
	else if (str == "Jun")
	{
		return 6;
	}
	else if (str == "Jul")
	{
		return 7;
	}
	else if (str == "Aug")
	{
		return 8;
	}
	else if (str == "Sep")
	{
		return 9;
	}
	else if (str == "Oct")
	{
		return 10;
	}
	else if (str == "Nov")
	{
		return 11;
	}
	else if (str == "Dec")
	{
		return 12;
	}
}
Date LayNgayHienTai()
{
	Date d;
	// tra ve date/time hien tai dua tren system hien tai
	time_t hientai = time(0);
	// chuyen doi hientai thanh dang chuoi
	char* dt = ctime(&hientai);

	string str1, str2, str3;
	//ngay
	for (int i = 8; i < 10; i++)
	{
		str1.push_back(dt[i]);
	}
	d.Ngay = atoi(str1.c_str());
	// thang
	for (int i = 4; i < 7; i++)
	{
		str2.push_back(dt[i]);
	}
	d.Thang = ChuyenThang(str2);
	//nam
	for (int i = 20; i < 24; i++)
	{
		str3.push_back(dt[i]);
	}
	d.Nam = atoi(str3.c_str());

	return d;
}
bool KTNamNhuan(int nam)
{
	if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0)
	{
		return true;
	}
	else
		return false;
}
// 1:ngay > ngay1; -1:ngay < ngay1; 0:ngay=ngay1
int SoSanhNgay(Date d1, Date d2)
{
	if (d1.Nam == d2.Nam)
	{
		if (d1.Thang == d2.Thang)
		{
			if (d1.Ngay > d2.Ngay)
			{
				return 1;
			}
			else if (d1.Ngay < d2.Ngay)
			{
				return -1;
			}
			else
				return 0;
		}
		else if (d1.Thang > d2.Thang)
		{
			return 1;
		}
		else
			return -1;
	}
	else if (d1.Nam > d2.Nam)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
int SoNgayCuaThang(int thang)
{
	if (thang == 1 || thang == 3 || thang == 5 || thang == 7 || thang == 8 || thang == 10 || thang == 12)
	{
		return 31;
	}
	else if (thang == 2)
	{
		if (KTNamNhuan)
		{
			return 29;
		}
		else
			return 28;
	}
	else
		return 30;
}
Date CongNgay(Date t, int SoNgay)
{
	Date d = t;
	d.Ngay = d.Ngay + SoNgay;
	if (d.Ngay > SoNgayCuaThang(d.Thang))
	{
		if (d.Thang == 12)
		{
			d.Thang = 1;
			d.Nam = d.Nam + 1;
		}
		else
		{
			d.Thang = d.Thang + 1;
		}
		d.Ngay = d.Ngay - SoNgayCuaThang(t.Thang);
	}
	return d;
}