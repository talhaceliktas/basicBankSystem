#include <iostream>
#include <vector>
#include <Windows.h>
#include <string>
#include <limits>
#include <map>
#include "Dil.h"


//

using namespace std;

bool tcKontrol = 1;
bool hesapNoKontrol = 1;

bool hataliIslemSayaci = 1;
int maxHataliIslem = 3;
int hataliIslem = 0;

Dil secilenDil = Dil::Ingilizce;


class BankaHesap {
public:


	BankaHesap(long long int tcKimlik, double bakiye, string musteriAdi, int musteriNo)
		: tcKimlik(tcKimlik), bakiye(bakiye), musteriAdi(musteriAdi), musteriNo(musteriNo){
	}
	void hesapBilgi() {
		cout << mesajlar["hesapBilgiTC"][secilenDil] << tcKimlik << endl;
		cout << mesajlar["hesapBilgiAdSoyad"][secilenDil] << musteriAdi << endl;
		cout << mesajlar["hesapBilgiBakiye"][secilenDil] << bakiye << endl;
		cout << mesajlar["hesapBilgiMusteriNo"][secilenDil] << musteriNo << endl;
	}
	double getBakiye() {
		return bakiye;
	}
	long long int getTcKimlikNo() {
		return tcKimlik;
	}
	int getMusteriNo() {
		return musteriNo;
	}
	void addMoney(int x) {
		bakiye += x;
	}
	void subtract(int x) {
		bakiye -= x;
	}
private:
	long long int tcKimlik;
	string musteriAdi;
	double bakiye;
	int musteriNo;
};

long long int basamakSayisi(long long int sayi) {
	return to_string(sayi).length();
}

int basamakSayisiInt(int sayi) {
	return to_string(sayi).length();
}

void uyu() {
	Sleep(150);
}

void musteriEkle(vector<BankaHesap*>& banka) {
	string ad, soyad, adSoyad;
	double baslangicBak;
	long long int tcKimlik;
	int basSayi;
	static int musteriNo = 100000;
	bool hataliTC = true;
	cout << mesajlar["kullaniciTcAl"][secilenDil];
	if (tcKontrol) {
		while (hataliTC) { 

			cin >> tcKimlik;

			basSayi = basamakSayisi(tcKimlik);
			if (basSayi == 11) {
				hataliTC = false;  
			}
			else if (hataliIslemSayaci && hataliIslem == maxHataliIslem) {
			cout << mesajlar["islemAsimi"][secilenDil];
			return;
			}
			else {
				hataliIslem++;
				cout << endl << mesajlar["hataliTC"][secilenDil];
			}


		}
	}
	else {
		cin >> tcKimlik;
		hataliIslem++;
	}

	cout << mesajlar["adSoyadGir"][secilenDil];
	cin >> ad >> soyad;
	adSoyad = ad + " " + soyad;
	cout << mesajlar["baslangicBakiyeGir"][secilenDil];
	cin >> baslangicBak;
	
	banka.push_back(new BankaHesap(tcKimlik, baslangicBak, adSoyad, musteriNo));
	musteriNo++;
}

void musteriSil(vector<BankaHesap*>& banka) {
	long long int tcKimlik;
	cout << mesajlar["silinecekTcGir"][secilenDil];
	cin >> tcKimlik;

	bool bulundu = false;

	for (auto it = banka.begin(); it != banka.end();) {
		if ((*it)->getTcKimlikNo() == tcKimlik) {
			delete* it; 
			it = banka.erase(it); 
			cout << mesajlar["kullaniciBasariylaSilindi"][secilenDil];
			bulundu = true;
			break; 
		}
		else {
			++it;
		}
	}

	if (tcKontrol) {
		if (!bulundu) {
			cout << mesajlar["tcBulunamadi"][secilenDil];
		}
	}

}

void musteriListe(vector<BankaHesap*>& banka) {
	int sira = 1;
	if (banka.empty() == 0) {
		cout << mesajlar["musteriListe"][secilenDil];
		for (auto bnk : banka) {
			cout << "*-" << sira << ". Musteri" << "-*\n";
			bnk->hesapBilgi();
			cout << endl;
			sira++;
		}
	}
	else {
		cout << mesajlar["hicMusteriYok"][secilenDil];
	}
}

void paraYatir(vector<BankaHesap*>& banka) {
	int hesapNo, basSayi, para;
	bool hataliHesapNo = 1;
	bool mevcutMu = 0;

	cout << mesajlar["paraYatiralacakHesap"][secilenDil];
	if (hesapNoKontrol) {
		while (hataliHesapNo) {
			cin >> hesapNo;
			if (basamakSayisiInt(hesapNo) == 6) {
				break;
			}
			else if (hataliIslemSayaci && hataliIslem == maxHataliIslem) {
				cout << mesajlar["islemAsimi"][secilenDil];
				return;
			}
			else {
				cout << mesajlar["hataliHesapNo"][secilenDil];
				hataliIslem++;
			}
		}
	}
	else {
		cin >> hesapNo;
		hataliIslem++;
	}


	for (auto bnk : banka) {
		if (bnk->getMusteriNo() == hesapNo) {
			mevcutMu = 1;
		}
	}

	if (mevcutMu) {
		for (auto it = banka.begin();it != banka.end();) {
			if ((*it)->getMusteriNo() == hesapNo) {
				cout << mesajlar["yatirilacakParaMiktariGiriniz"][secilenDil];
				cin >> para;
				(*it)->addMoney(para);
				cout << endl << hesapNo << mesajlar["noluHesap"][secilenDil] << para << mesajlar["yuklendi"][secilenDil];
				cout << mesajlar["hesabinSonBakiyesi"][secilenDil] << (*it)->getBakiye() << endl;
				break;
			}
			else {
				++it;
			}


		}
	}
	else {
		cout << mesajlar["musteriNoBulunamadi"][secilenDil];
	}

}

void paraCek(vector<BankaHesap*>& banka) {
	int hesapNo, basSayi, para;
	bool hataliHesapNo = 1;
	bool mevcutMu = 0;
	
	cout << mesajlar["hesapNoGiriniz"][secilenDil];
	if (hesapNoKontrol) {
		while (hataliHesapNo) {
			cin >> hesapNo;
			if (basamakSayisiInt(hesapNo) == 6) {
				break;
			}
			else if (hataliIslemSayaci && hataliIslem == maxHataliIslem) {
				cout << mesajlar["islemAsimi"][secilenDil];
				return;
			}
			else {
				cout << mesajlar["hataliHesapNo"][secilenDil];
			}
		}
	}
	else {
		cin >> hesapNo;
	}


	for (auto bnk : banka) {
		if (bnk->getMusteriNo() == hesapNo) {
			mevcutMu = 1;
		}
	}

	if (mevcutMu) {
		for (auto it = banka.begin();it != banka.end();) {
			if ((*it)->getMusteriNo() == hesapNo) {
				cout << mesajlar["cekilecekParaMiktari"][secilenDil];
				cin >> para;
				(*it)->subtract(para);
				cout << endl << hesapNo << mesajlar["noluHesaptan"][secilenDil] << para << mesajlar["paraCekildi"][secilenDil];
				cout << mesajlar["hesabinSonBakiyesi"][secilenDil] << (*it)->getBakiye() << endl;
				break;
			}
			else {
				++it;
			}


		}
	}
	else {
		cout << mesajlar["musteriNoBulunamadi"][secilenDil];
	}

}

void hesabaTransfer(vector<BankaHesap*>& banka) {
	int gonderen, alici, miktar = 0;
	bool  hataliHesapNo = 1;
	bool gonderenHesapVarMi = 0;
	bool aliciHesapVarMi = 0;
	int gonderenHesapNo = 0;

	cout << mesajlar["gonderenHesapAlis"][secilenDil];
	if (hesapNoKontrol) {
		while (hataliHesapNo) {
			cin >> gonderen;
			if (basamakSayisiInt(gonderen) == 6) {
				break;
			}
			else if (hataliIslemSayaci && hataliIslem == maxHataliIslem) {
				cout << mesajlar["islemAsimi"][secilenDil];
				return;
			}
			else {
				cout << mesajlar["hataliHesapNo"][secilenDil];
			}
		}
	}
	else {
		cin >> gonderen;
	}

	for (auto bnk : banka) {
		if (bnk->getMusteriNo() == gonderen) {
			gonderenHesapVarMi = 1;
		}
	}

	if (gonderenHesapVarMi == 0) {
		for (auto bnk : banka) {
			while (gonderenHesapVarMi == 0) {
				if (hataliIslemSayaci && hataliIslem == maxHataliIslem) {
					cout << mesajlar["islemAsimi"][secilenDil];
					return;
				}
				cout << mesajlar["gonderenHesapBulunamadi"][secilenDil];
				cin >> gonderen;
				if (bnk->getMusteriNo() == gonderen) {
					gonderenHesapVarMi = 1;
				}
				else {
					if (hataliIslem) {
						hataliIslemSayaci++;
					}
				}

			}

		}
	}

	
	cout << mesajlar["aliciHesapAlis"][secilenDil];
	if (hesapNoKontrol) {
		while (hataliHesapNo) {
			cin >> alici;
			if (basamakSayisiInt(alici) == 6) {
				break;
			}
			else if (hataliIslemSayaci && hataliIslem == maxHataliIslem) {
				cout << mesajlar["islemAsimi"][secilenDil];
				return;
			}
			else {
				cout << mesajlar["hataliHesapNo"][secilenDil];
			}
		}
	}
	else {
		cin >> alici;
	}

	for (auto bnk : banka) {
		if (bnk->getMusteriNo() == alici) {
			aliciHesapVarMi = 1;
		}
	}

	if (aliciHesapVarMi == 0) {
		for (auto bnk : banka) {
			while (aliciHesapVarMi == 0) {
				if (hataliIslemSayaci && hataliIslem == maxHataliIslem) {
					cout << mesajlar["islemAsimi"][secilenDil];
					return;
				}
				cout << mesajlar["aliciHesapBulunamadi"][secilenDil];
				cin >> alici;
				if (bnk->getMusteriNo() == alici) {
					aliciHesapVarMi = 1;
				}
				else {
					if (hataliIslem) {
						hataliIslemSayaci++;
					}
				}

			}

		}
	}

	cout << mesajlar["gonderilecekMiktarGirin"][secilenDil];

	for (auto it = banka.begin();it != banka.end();) {
		if ((*it)->getMusteriNo() == gonderen) {
			cin >> miktar;
			if ((*it)->getBakiye() < miktar) {
				cout << mesajlar["bakiyeYetersiz"][secilenDil] << (*it)->getBakiye() << endl;
				return;
			}
			else {
				(*it)->subtract(miktar);
				gonderenHesapNo = (*it)->getMusteriNo();
			}

			break;
		}
		else {
			++it;
		}
	}

	for (auto it = banka.begin();it != banka.end();) {
		if ((*it)->getMusteriNo() == alici) {
			(*it)->addMoney(miktar);
			cout << endl << (*it)->getMusteriNo() << mesajlar["transfer1"][secilenDil] << gonderenHesapNo << mesajlar["transfer2"][secilenDil] << miktar << mesajlar["transfer3"][secilenDil];
			return;
		}
	}
}

void ayarlar() {
	char islem;
	cout << mesajlar["tcKontrolu"][secilenDil];
	if (tcKontrol) {
		cout << mesajlar["acik"][secilenDil];
	}
	else {
		cout << mesajlar["kapali"][secilenDil];
	}
	cout << mesajlar["hesapKontrolu"][secilenDil];
	if (hesapNoKontrol) {
		cout << mesajlar["acik"][secilenDil];
	}
	else {
		cout << mesajlar["kapali"][secilenDil];
	}
	cout << mesajlar["islemKontrolu"][secilenDil];
	if (hataliIslemSayaci) {
		cout << mesajlar["acik"][secilenDil];
	}
	else {
		cout << mesajlar["kapali"][secilenDil];
	}
	cout << mesajlar["sinirGiris"][secilenDil] << maxHataliIslem << endl;
	cout << mesajlar["degistirilecekAyar"][secilenDil];
	cin >> islem;
	
		switch (islem) {
		case '1':
			cout << mesajlar["tcDogrulayiciyiAcKapat"][secilenDil];
			cin >> islem;
			if (islem == '1') {
				if (tcKontrol == 1) {
					cout << mesajlar["tcDogrulayiciZatenAcik"][secilenDil];
				}
				else {
					tcKontrol = 1;
					cout << mesajlar["tcDogrulayiciAcildi"][secilenDil];
				}
			}
			if (islem == '2') {
				if (tcKontrol == 0) {
					cout << mesajlar["tcDogrulayiciZatenKapali"][secilenDil];
				}
				else {
					tcKontrol = 0;
					cout << mesajlar["tcDogrulayiciKapatildi"][secilenDil];
				}
			}
		break;
		case '2':
			cout << mesajlar["hesapDogruluguAcKapat"][secilenDil];
			cin >> islem;
			if (islem == '1') {
				if (hesapNoKontrol == 1) {
					cout << mesajlar["hesapDogruluguZatenAcik"][secilenDil];
				}
				else {
					hesapNoKontrol = 1;
					cout << mesajlar["hesapDogruluguAcildi"][secilenDil];
				}
			}
			if (islem == '2') {
				if (hesapNoKontrol == 0) {
					cout << mesajlar["hesapDogruluguZatenKapali"][secilenDil];
				}
				else {
					hesapNoKontrol = 0;
					cout << mesajlar["hesapDogruluguKapatildi"][secilenDil];
				}
			}
			break;
		case '3':
			cout << mesajlar["hataliIslemAcKapat"][secilenDil];
			cin >> islem;
			if (islem == '1') {
				if (hataliIslemSayaci == 1) {
					cout << mesajlar["hataliIslemZatenAcik"][secilenDil];
				}
				else {
					hataliIslemSayaci = 1;
					cout << mesajlar["hataliIslemAcildi"][secilenDil];
				}
			}
			if (islem == '2') {
				if (hataliIslemSayaci == 0) {
					cout << mesajlar["hataliIslemZatenKapali"][secilenDil];
				}
				else {
					hataliIslemSayaci = 0;
					cout << mesajlar["hataliIslemKapatildi"][secilenDil];
				}
			}
			if (islem == '3') {
				if (hataliIslemSayaci == 0) {
					cout << mesajlar["onceSayaciAc"][secilenDil];
				}
				else {
					int hataliIslem;
					cout << mesajlar["yeniHataliIslemLimiti"][secilenDil];
					cin >> hataliIslem;
					maxHataliIslem = hataliIslem;
					cout << mesajlar["hataliIslemLimitiA"][secilenDil] << maxHataliIslem << mesajlar["hataliIslemLimitiB"][secilenDil];
				}
			}
			break;
		case '4':
			break;
		default:
			cout << mesajlar["hataliIslemGirildi"][secilenDil];
		}
}

void menu(vector<BankaHesap*>& banka) {
	char islem;
	hataliIslem = 0;
	cout << endl << mesajlar["menu1"][secilenDil];
	uyu();
	cout << mesajlar["menu2"][secilenDil];
	uyu();
	cout << mesajlar["menu3"][secilenDil];
	uyu();
	cout << mesajlar["menu4"][secilenDil];
	uyu();
	cout << mesajlar["menu5"][secilenDil];
	uyu();
	cout << mesajlar["menu6"][secilenDil];
	uyu();
	cout << mesajlar["menu7"][secilenDil];
	uyu();
	cin >> islem;

	switch (islem) {
	case '1':
		cout << endl;
		musteriEkle(banka);
		break;
	case '2':
		cout << endl;
		musteriSil(banka);
		break;
	case '3':
		cout << endl;
		musteriListe(banka);
		break;
	case '4':

		cout << endl;
		cout << mesajlar["paraCekMenu1"][secilenDil];
			cout << mesajlar["paraCekMenu2"][secilenDil];
			uyu();
			cout << mesajlar["paraCekMenu3"][secilenDil];
			uyu();
			cout << mesajlar["paraCekMenu4"][secilenDil];
			uyu();
			cout << mesajlar["paraCekMenu5"][secilenDil];
			uyu();
			cout << mesajlar["menu7"][secilenDil];
			cin >> islem;
				
			switch (islem) {
			case '1':
				paraYatir(banka);
				break;
			case '2':
				paraCek(banka);
				break;
			case '3':
				hesabaTransfer(banka);
				break;
			case '4':
				break;
			default:
				cout << mesajlar["hataliIslemGirildi"][secilenDil];
			}
			break;
	case '5':
		cout << endl;
		for (int i = 0;i < 10;i++) {
			cout << "* ";
			uyu();
		}
		cout << endl;
		ayarlar();
			
		break;
	case '6':
		cout << endl << mesajlar["programdanCikiliyor"][secilenDil];
		for (auto hesap : banka) {
			delete hesap;
		}
		exit(0);
		break;
	default:
		cout << mesajlar["hataliIslemGirildi"][secilenDil];
	}
	
}

int main() {
	vector<BankaHesap*> banka;

	char dilSecimi;
	cout << "Dil Secimi Yapiniz\n1.Turkce\n2.Ingilizce\nDil Seciminizi giriniz: ";
	cin >> dilSecimi;
	
	switch (dilSecimi) {
	case '1':
		secilenDil = Dil::Turkce;
		break;

	case '2':
		secilenDil = Dil::Ingilizce;
	}

	while (true) {
		menu(banka);
	}

	for (auto hesap : banka) {
		delete hesap;
	}
}
