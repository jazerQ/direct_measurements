#include <iostream>
#include <windows.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <math.h>
using namespace std;
float mn(std::vector<float> elements) {
	float m = 10000000;
	for (int i = 0; i < elements.size(); i++) {
		if (elements[i] < m) {
			m = elements[i];
		}
	}
	return m;
}
float mx(std::vector<float> elements) {
	float m = 0;
	for (int i = 0; i < elements.size(); i++) {
		if (elements[i] > m) {
			m = elements[i];
		}
	}
	return m;
}
int main() {
	const float t[9]{ 12.7,4.3,3.2,2.8,2.6,2.5,2.4,2.3,2.3 };
	const float v[10]{ 1.15,1.46,1.67,1.82,1.94,2.03,2.11,2.18,2.23,2.29 };
	setlocale(LC_ALL, "RUS");
	SetConsoleTitleW(L"��������� ������ 1.0.0");
	cout << "��� ��������� ������� ��� ���������� ������������, � ������ ������ �������������" << endl;
	unsigned short viborka;
	cout << "������� ���������� ����� ������� N\t" ;
	cin >> viborka;
	float your_numbers;
	float srednee;
	float sko = 0;
	vector<float> elements;
	for (int i = 0; i < viborka; i++) {
		cout << "���� �������� ��� N=" << i + 1<<"\t";
		cin >> your_numbers;
		elements.push_back(your_numbers);
	}
	sort(elements.begin(), elements.end());
	bool flag = true;
	while (flag){
		if (elements.size() == 0) {
			cout << "���� �������� �����������";
			break;
		}
		float sko_one = 0;
		float suma = 0;
		for (int i = 0; i < elements.size(); i++) {
			suma += elements[i];
		}
		srednee = suma / viborka;
		for (int i = 0; i < elements.size(); i++) {
			sko_one += pow((elements[i] - srednee), 2);
		}
		sko = sqrt(sko_one / (viborka - 1));
		

		cout << "\n�������� �� �������";
		if ((abs(mn(elements) - srednee) < (v[viborka - 3] * sko)) && (abs(mx(elements) - srednee) < (v[viborka - 3] * sko))) {
			cout << "\n�������� ���";
			flag = false;
		}
		else {
			if (abs(mn(elements) - srednee) >= (v[viborka - 3] * sko)) {
				cout << "\n��� ������\t" << elements[0];
				elements.erase(elements.begin());
				viborka -= 1;
			}
			if (abs(mx(elements) - srednee) >= (v[viborka - 3] * sko)) {
				cout << "\n ��� ������" << elements[elements.size()-1];
				elements.pop_back();
				viborka -= 1;
			}
		}
	}
	float sko_srednego;
	sko_srednego = (sko / (sqrt(elements.size())));
	float sluchainaya_pogreshnost;
	sluchainaya_pogreshnost = (t[elements.size() - 2] * sko_srednego);
	cout << "\n��� ���������� ���������� ��� ����� ����� �� ����� ������� �� �������� ������: \n������� \"0\" ���� ��� ������������\n\"1\" ���� ��� ��������\n\"2\" ���� ������ ����� ��������\n\"3\" ���� ��� ��� ���� ��������� �����������\n";
	flag = true;
	float pribor_pogreshnost;
	while (flag) {
		std::string vvod;
		cin >> vvod;
		if (vvod == "Sanya") {
			cout << "���������\n";
		}
		else if(vvod == "0") {
			float cena_deleniya;
			cout << "\n���������� ����� ���� ���� �������\t";
			cin >> cena_deleniya;
			pribor_pogreshnost = cena_deleniya / 2;
			flag = false;
		}
		else if (vvod == "1") {
			cout << "\n���������� ����� ���� ����������� ���� �������(����������� ������, ���� ������ ������� 10.344 �� ����� 0.001)\t";
			cin >> pribor_pogreshnost;
			flag = false;
		}
		else if (vvod == "2") {
			float y;
			float g;
			cout << "\n����� Y - ����� �������� ��� ������ ������� � G - ������������ ���������� �������\n";
			cout << "Y = ";
			cin >> y;
			cout << "\n";
			cout << "G = ";
			cin >> g;
			pribor_pogreshnost = (y * g) / 100;
			flag = false;
		}
		else if (vvod == "3") {
			cin >> pribor_pogreshnost;
			flag = false;
		}
		else {
			cout << "\n���������� ������� ������ �����\t";
		}
	}
	cout << "\n���� ������ ��������� ����������� = ";
	float poln_priborn_pogreshnost;
	poln_priborn_pogreshnost = sqrt(pow(sluchainaya_pogreshnost, 2) + pow(pribor_pogreshnost, 2));
	cout << poln_priborn_pogreshnost;
	cout << "\n������ ��, ������ ������������� ����������� = ";
	float otnos_pogr;
	otnos_pogr = (poln_priborn_pogreshnost / srednee) * 100;
	if (otnos_pogr < 10) {
		cout << otnos_pogr << "%\t ��� ������� �����������\n";
	}
	else {
		cout << otnos_pogr << "%\t ������� ����������� �����������\n";
	}
	cout << srednee << "��� �������\n";
	cout << sko << "sko\n";
	cout << sko_srednego << "sko sred\n";
	cout << sluchainaya_pogreshnost << "sluch pogreshnost\n";
	system("PAUSE");
	return 0;
}