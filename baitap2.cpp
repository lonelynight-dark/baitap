#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

void LayDuLieu(string path);
void XuatDuLieu(string path,int data);

int n{ 0 };
int t{ 0 };
int x[10000];

void LayDuLieu(string path)
{
	ifstream fileInput(path);

	if (fileInput.fail())
	{
		cout << "Fail to read!";
	}
	fileInput >> n >> t;

	int i{ 0 };
	while (!fileInput.eof())
	{
		fileInput >> x[i];
		i++;
	}


	fileInput.close();
}

void XuatDuLieu(string path, int data)
{
	ofstream fileOutput(path);

	if (fileOutput.fail())
		cout << "Fail to open";

	fileOutput << data;
	fileOutput.close();
}

int main()
{
	string path_int = "D:/baitap/TRASH.INP.txt";
	string path_out = "D:/baitap/TRASH.OUT.txt";
	LayDuLieu(path_int);

	int so_cach{ 0 };
	for (int i{ 0 }; i < n; i++)
	{
		
		if (x[i] <= t)
		{
			int sum{ x[i] };
			so_cach += 1;
			cout << x[i] << "\t";
			int j{ i + 1 };
			while ((sum + x[j] <= t) && (j < n))
			{
				cout << x[j] << "\t";
				sum += x[j];
				so_cach += 1;
				j++;
			}

			cout << "\n" << so_cach << endl << sum << endl;
		}
	}
	cout << so_cach << endl;
	XuatDuLieu(path_out, so_cach);

}