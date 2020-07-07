#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <fstream>
#include<ctime>
#include <string>
#include<cstdlib>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <map>
#include <Windows.h>

using namespace std;


const std::string currentDateTime()
{
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
	return buf;
}

int arra[8] = { 0 };
struct tm *tim;
int tD, tMo, tY, tH, tM;
/// стата вида - --- - - -Кол-во>< Название
ofstream today;/// стата вида ---- -- 



int atorever(string DD)
{
	int f = 1;
	int Se = 0;
	int bb;
	for (int i = DD.length() - 1; i >= 0; i--)
	{
		char c = DD[i];
		switch (c) {
		case '1':			bb = 1;			break;
		case '2':			bb = 2;			break;
		case '3':			bb = 3;			break;
		case '4':			bb = 4;			break;
		case '5':			bb = 5;			break;
		case '6':			bb = 6;			break;
		case '7':			bb = 7;			break;
		case '8':			bb = 8;			break;
		case '9':			bb = 9;			break;
		case '0':			bb = 0;			break;
		}
		Se += bb * f;
		f *= 10;
	}

	return Se;
}

void  changeVK()
{
	ifstream In("PythonApplication1\\id.txt");
	string S;
	getline(In, S);
	cout << "     Now Vk Id is --" << S << "\n     Pass New VkId or 0 if not\n    ( Goto Photo on VkProfile and last numbers 8-9-it is VkId of user\n     ";
	int Id;
	cin >> Id;
	if (Id) {
		ofstream Ot("PythonApplication1\\id.txt");
		Ot << Id;
	}
	system("cls");

}

string ato(int DD)
{
	if (DD == 0)
	{
		return "00";
	}
	int f = 0;
	string S = "";
	while (DD > 0)
	{

		int c = DD % 10;
		DD /= 10;
		char bb = ' ';
		switch (c) {
		case 1:			bb = '1';			break;
		case 2:			bb = '2';			break;
		case 3:			bb = '3';			break;
		case 4:			bb = '4';			break;
		case 5:			bb = '5';			break;
		case 6:			bb = '6';			break;
		case 7:			bb = '7';			break;
		case 8:			bb = '8';			break;
		case 9:			bb = '9';			break;
		case 0:			bb = '0';			break;
		}
		S += bb; f++;
	}

	string ds = "";
	if (f == 1)
	{
		ds += '0';
	}
	for (int i = S.size() - 1; i >= 0; i--)
	{
		ds += S[i];
	}
	return ds;
}

string DataPlus(string D)
{
	int m = int(D[0] - '0') * 10 + int(D[1] - '0');
	int d = int(D[3] - '0') * 10 + int(D[4] - '0');
	d++;
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
		if (d == 32)
		{
			d = 1;
			m += 1;
		}
	}
	else
		if (m == 2)
		{
			if (d == 29)
			{
				d = 1;
				m += 1;
			}
		}
		else
		{
			if (d == 31)
			{
				d = 1;
				m += 1;
			}
		}

	string newdata = ato(m) + '.' + ato(d);
	return newdata;
}
void plusq(string weneed)
{
	string StartPoint = "06.18";
	int j = 0;
	while (j<123123)
	{
		if (StartPoint == weneed)
			break;
		j++;
		StartPoint = DataPlus(StartPoint);
	}
	j %= 7;
	arra[j + 1]++;
}
//// Название песни --- Count
string  Sol()
{
	ifstream din("Week.txt");
	string s2;
	getline(din,s2);
	string temp="";
	for (int i = 0; i < 8; i++)
		arra[i] = 0;
	int c = 1;
	int j;
	while (getline(din, temp))
	{
		j = 0;
		while (temp[j] != '>')
			j++;
		j++;
		string num = "";
		while (temp[j] >= '0'&&temp[j] <= '9')
		{
			num += temp[j];
			j++;
		}
		arra[c] = atorever(num);
		c++;
	}
	ifstream fin("Solo.txt", ios_base::in);
	string l;
	getline(fin, l);
	int last = 0;
	while (l[last] != '>')
		last++;
	last += 2;
	l.erase(0, last);
	string Dat = "";
	int i = 0;
	while (i<5) {
		Dat += l[i];		i++;
	}
	map <string, int > Musik;
	while (getline(fin, l))
	{
		int j = l.length() - 1;
		while (l[j] != ' ') { j--; }
		j++;
		string count = "";
		for (int i = j; i < l.length(); i++) { count += l[i]; }
		int co = atorever(count);

		j--;		j--;		j--;		j--;

		string nameS = "";

		for (int i = 0; l[i] != '-'; i++) { nameS += l[i]; }

		auto res = Musik.emplace(nameS, co);

	}

	string LastSeen = Dat;
	string PrevSeen=Dat;
	int d = 0;
	int su = 0;
	int h = 0;
	while (true)
	{

		ifstream fina("EvryDayStat\\" + Dat + ".txt");
		if (!fina.is_open())
		{
			LastSeen = PrevSeen;
			break;
		}
		PrevSeen = Dat;
		Dat = DataPlus(Dat);
		string dd;
		
		while (getline(fina, dd))
		{
			if (!d) {
				if (dd == "<C>")
				{
					getline(fina, dd);
					d = atorever(dd);
					su = d;
				}
				string songName = "";
				auto in = dd.find(' >');
				if (in != string::npos)
				{
					in = dd.find('"');
					in++;
					for (; dd[in] != '\"'; in++)
					{
						songName += dd[in];
					}
				}
				h++;
				if (songName != "") {
					auto 	it = Musik.find(songName);
					plusq(PrevSeen);
					if (it == Musik.end())
					{
						Musik.emplace(songName, 1);
					}
					else
					{
						Musik[songName]++;
					}
				}
			}
			else
			{
				d--;
			}
		}

	}
	fin.close();
	ofstream foutsolo("Solo.txt");
	ofstream foutweek("Week.txt");
	ifstream fin2("EvryDayStat\\" + PrevSeen + ".txt");

	string DD = "";
	int y = 0;
	string ds = ato(h + su - 1);
	while (getline(fin2, temp))
	{
		y++;

		if (y == 2)
			temp = ds;
		DD += temp + '\n';
	}
	ofstream fout2("EvryDayStat\\" + PrevSeen + ".txt");

	fout2 << DD;
	fout2.close();
	fin2.close();
	foutsolo << " LastUpDate -> " << PrevSeen << endl;
	foutweek << " LastUpDate -> " << PrevSeen << endl;
	foutweek << "Monday ->" + ato(arra[1]) <<endl;
	foutweek << "Tuesday ->" + ato(arra[2])<< endl;
	foutweek << "Wednesday ->" + ato(arra[3])<<endl;
	foutweek << "Thursday ->" + ato(arra[4])<< endl;
	foutweek << "Friday ->" + ato(arra[5])<<endl;
	foutweek << "Saturday ->" + ato(arra[6])<< endl;
	foutweek << "Sunday ->" + ato(arra[7]) << endl;
	auto it = Musik.begin();
	for (; it != Musik.end(); it++)
	{
		foutsolo << it->first << "--- " << it->second << endl;
	}

	string s;
	cout << "     \n";
	system("Type Week.txt");
	foutsolo.close();
	system("start Solo.txt");
	cout << "     \n\"e+ Enter \" if Ok\n     ";
	cin >> s;
	system("taskkill /f /im notepad.exe");
	system("cls");
	cout << "\n\n      Back...";
	this_thread::sleep_for(chrono::milliseconds(555));
	return "";
}
int counet = 0;

void retime()
{
	time_t tt = time(NULL);
	tim = localtime(&tt);
	tD = tim->tm_mday;
	tMo = tim->tm_mon;
	tY = tim->tm_year + 1900;
	tH = tim->tm_hour;
	tM = tim->tm_min;

}

string getinfo()
{	try{
	system("cd PythonApplication1& python PythonApplication1.py");
	}catch(...){cout<<endl<<"NoRes";}
	ifstream info;
	info.open("PythonApplication1\\text.txt");
	if (!info.is_open())
	{
		cout << "     EL";
	}
	string s;
	getline(info, s);
	return s;
}
bool doo = false;
void Start()
{
	string nameFi;
	retime();
	int isND = -1;
	string latePlayNow = "";
	while (doo)
	{
		if (isND != tD)
		{
			isND = tD;
			nameFi = "EvryDayStat\\" + ato(tMo + 1) + '.' + ato(tD) + ".txt";
			if (today.is_open())
			{
				today.close();
			}
			ifstream tody(nameFi);
			today.open(nameFi, ios_base::app);
			if (!tody.is_open())
				today << "<C>" << endl << "0\n";
			today << "Session begin ,Time == " << currentDateTime();
 			if (!today.is_open())
			{
				cout << "      cant open- - -" << nameFi << endl;
				return;
			}
		}
		
		retime();

		string PlayNow = getinfo();
		if (PlayNow >= " "&&PlayNow != latePlayNow)
		{

			if (!today.is_open())
				today.open(nameFi, ios_base::app);
			today << endl;
			string S = ato(tH) + ":" + ato(tM) + "- - >";
			today << S << '"' << PlayNow << '"';
			counet++;
			cout << S << "FNewSong!  " << counet << " - > and the song is - >" << PlayNow << endl << "          ";
			latePlayNow = PlayNow;
			today.close();
		}

		this_thread::sleep_for(chrono::milliseconds(5000));


	}
}
void cher(){
	string S;
	while (cin >> S)
	if (S == "stop")
		break;
doo = false;
}
void Start2()  
{

	cout << "         write \"stop\" - to stop     " << endl << "          ";
	doo = true;
	thread th(cher);
	th.detach();
	Start();
	cout << endl << "        \"e+Ehter \"-  if  okay\n     ";

	string s;
	cin >> s;
	system("cls");
	cout << "\n\n      Back...";
	this_thread::sleep_for(chrono::milliseconds(555));
}

void cclear()
{
	cout << "\n\n      clear 1 --- Solo+Week \n      clear 2 --- DayStata\n      clear 3 --- Solo+Week+DayStata\n      Exit --- e ";
	string f;
	cin >> f;

	if (f == "1")
	{
		remove("Solo.txt");
		remove("Week.txt");
	}
	else
	{
		if (f == "2") {
			system("rmdir /s /q EvryDayStat");
			system("MD EvryDayStat");
		}
		else {
			if (f == "3")
			{
				remove("Solo.txt");
				remove("Week.txt");
				system("rmdir /s /q EvryDayStat");
				system("MD EvryDayStat");
			}
			else
			{
				system("cls");
				cout << "\n\n      Back...";
				this_thread::sleep_for(chrono::milliseconds(555));
				system("cls");
				return ;
			}
		}
	
	}
	today.close();
	ifstream Week("Week.txt");///стата вида -----  ДеньНедели><Кол-во песен
	ifstream Solo("Solo.txt");
	if (!Solo.is_open())
	{
		ofstream Temp("Solo.txt");
		Temp << " LastUpDate -> " << ato(tMo + 1) << '.' << ato(tD) << endl;
		Temp.close();
	}
	if (!Week.is_open())
	{
		ofstream Temp("Week.txt");
		Temp << " LastUpDate -> " << ato(tMo + 1) << '.' << ato(tD) << endl;
		Temp.close();
	}
	Week.close();
	Solo.close();
	cout << "\n      \"e+Ehter \"-  if  okay\n     ";
	string s;
	cin >> s;
	system("cls");	
	cout << "\n\n      Back...";
	this_thread::sleep_for(chrono::milliseconds(555));
}	
void Settings()
{
	changeVK();
}
int main()
{
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // уста
	retime();

	ifstream Week("Week.txt");///стата вида -----  ДеньНедели><Кол-во песен
	ifstream Solo("Solo.txt");
	this_thread::sleep_for(chrono::milliseconds(222));
	cout << "     Start1.3\n";
	this_thread::sleep_for(chrono::milliseconds(555));
	if (!Solo.is_open())
	{
		ofstream Temp("Solo.txt");
		Temp << " LastUpDate -> " << ato(tMo + 1) << '.' << ato(tD) << endl;
		Temp.close();
	}

	cout << "     Start2.3\n";
	this_thread::sleep_for(chrono::milliseconds(200));
	if (!Week.is_open())
	{
		ofstream Temp("Week.txt");
		Temp << " LastUpDate -> " << ato(tMo + 1) << '.' << ato(tD) << endl;
		Temp.close();
	}

	cout << "     Start3.3\n";
	this_thread::sleep_for(chrono::milliseconds(444));
	Week.close();
	Solo.close();
	string n;
	while (true)
	{
		system("cls");
		cout << "\n\n      1  -  getInfoWhile \n      2  -  repair solo and week stata\n      3  -  Settings\n      4  -  clear \n      5  -  exit()\n" << endl << endl << "           ";
		cin >> n;
		system("cls");
		if (n <"0" || n>"6")
		{
			system("cls");
			this_thread::sleep_for(chrono::milliseconds(333));
			cout << "\n\n     Error\n";
			this_thread::sleep_for(chrono::milliseconds(333));
			system("cls");
		}
		else
		{
			if (n == "1")
				Start2();
			else if (n == "2")
				cout << Sol();
			else if (n == "3")
				Settings();
			else if (n == "4")
			{
				cclear();
			}
			else if (n == "5")
			{
				system("cls");
				cout << "\n\n      Back...";
				this_thread::sleep_for(chrono::milliseconds(555));
				return 0;
			}
		}
	}
}

