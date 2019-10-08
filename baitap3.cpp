#include<iostream>
#include<fstream>
using namespace std;

void LayDuLieu(string path);
void XuatDuLieu(string path, int data[]);

int m{ 0 }, n{ 0 }, Q{ 0 };
int a[10000][10000];
int q[10000][10000];
int data_out[10000];

void LayDuLieu(string path)
{
	ifstream fileInput(path);

	if (fileInput.fail())
		cout << "Fail to read";

	fileInput >> m >> n >> Q;

	for (int i{ 0 }; i < m; i++)
		for (int j{ 0 }; j < n; j++)
			fileInput >> a[i][j];
	
	for (int i{ 0 }; i < Q; i++)
		fileInput >> q[i][1] >> q[i][2] >> q[i][3] >> q[i][4];
	
	fileInput.close();
}

void XuatDuLieu(string path)
{
	ofstream fileOutput(path);

	if (fileOutput.fail())
		cout << "Fail to open";

	for (int i{ 0 }; i < Q; i++)
		fileOutput << data_out[i] << endl;
}

int KTSoNguyenTo(int so_kt)
{
	if ((so_kt == 0) || (so_kt == 1))
		return 0;
	for (int i{ 2 }; i <= sqrt(so_kt); i++)
		if (so_kt % i == 0)
			return 0;
	return 1;
}

int KT(int x1, int y1, int r, int c)
// Ham nay kiem tra khoang o r x c tat ca deu co so nguyen to hay khong
{
	cout << endl << x1 << y1 << r << c << endl;
	for (int dong{ x1 - 1 }; dong <= x1 + r - 2; dong++)
		for (int cot{ y1 - 1 }; cot <= y1 + c - 2; cot++)
			if (KTSoNguyenTo(a[dong][cot]) == 0)
				return 0;
	return 1;
}
void In(int x1, int y1, int r, int c)
// Ham nay kiem tra khoang o r x c tat ca deu co so nguyen to hay khong
{
	for (int dong{ x1 - 1 }; dong <= x1 + r - 2; dong++)
	{
		for (int cot{ y1 - 1 }; cot <= y1 + c - 2; cot++)
			cout << a[dong][cot];
		cout << endl;
	}
}

int main()
{
	string path_int = "D:/baitap/PRIMETAB.INP.txt";
	string path_out = "D:/baitap/PRIMETAB.OUT.txt";
	LayDuLieu(path_int);
	int num{ 0 };

	for (int i{ 0 }; i < Q; i++)
	{
		
	
		
		int x{ q[i][1] }, y{ q[i][2] }, r{ q[i][3] }, c{ q[i][4] };
		int kq{ 0 };

		//Cat khoang r x c tu dong x toi dong  y
		for (int dong1{ x }; dong1 <= y - r + 1; dong1++)
		{
			int cot1{ 1 };

			while ((cot1 + c - 1 <= n)  && (kq == 0))
			{
				kq = KT(dong1, cot1, r, c);
				In(dong1, cot1, r, c);
				
				cot1++;
			}

		}
		cout << kq << endl << endl;
		data_out[num] = kq;
		num++;
		XuatDuLieu(path_out);
	}

}