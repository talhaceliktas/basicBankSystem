#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
#include <string>
#include <limits>
#include <map>
using namespace std;

enum class Dil {
	Turkce,
	Ingilizce
};

map<string, map<Dil, string>> mesajlar = {
	{"hesapBilgiTC", {
		{Dil::Turkce, "Musterinin TC kimlik No'su: "},
		{Dil::Ingilizce, "Customer's ID Number: "}
	}},
	{"hesapBilgiAdSoyad", {
		{Dil::Turkce, "Musterinin Adi-Soyadi: "},
		{Dil::Ingilizce, "Customer's Full Name: "}
	}},
	{"hesapBilgiBakiye", {
		{Dil::Turkce, "Musterinin Bakiyesi: "},
		{Dil::Ingilizce, "Customer's Balance: "}
	}},
	{"hesapBilgiMusteriNo", {
		{Dil::Turkce, "Musteri Numarasi: "},
		{Dil::Ingilizce, "Customer Number: "}
	}},
	{"kullaniciTcAl", {
	{Dil::Turkce, "Musterinin TC Kimlik No'sunu giriniz: "},
	{Dil::Ingilizce, "Enter the Customer's ID Number: "}
	}},
	{"islemAsimi", {
	{Dil::Turkce, "Cok fazla hatali islem yapildi, ana menuye donuluyor..."},
	{Dil::Ingilizce, "Too many incorrect attempts made, returning to the main menu..."}
	}},
	{"hataliTC", {
	{Dil::Turkce, "Hatali giris yaptiniz! Lutfen 11 basamakli bir TC giriniz: "},
	{Dil::Ingilizce, "Invalid entry! Please enter an 11-digit ID number: "}
	}},
	{"adSoyadGir", {
	{Dil::Turkce, "Musterinin Adini - Soyadini giriniz: "},
	{Dil::Ingilizce, "Enter the Customer's First and Last Name: "}
	}},
	{"baslangicBakiyeGir", {
	{Dil::Turkce, "Musterinin baslangic bakiyesini giriniz: "},
	{Dil::Ingilizce, "Enter the customer's initial balance: "}
	}},
	{"silinecekTcGir", {
	{Dil::Turkce, "Silmek istediginiz kullanicinin TC Kimlik No'sunu giriniz: "},
	{Dil::Ingilizce, "Enter the TC ID number of the user you want to delete: "}
	}},
	{"kullaniciBasariylaSilindi", {
	{Dil::Turkce, "Kullanici basariyla silindi.\n"},
	{Dil::Ingilizce, "User successfully deleted.\n"}
	}},
	{"tcBulunamadi", {
	{Dil::Turkce, "Hata: Belirtilen TC Kimlik No'suna sahip musteri bulunamadi!\n"},
	{Dil::Ingilizce, "Error: No customer found with the specified TC Identity Number!\n"}
	}},
	{"musteriListe", {
	{Dil::Turkce, "---Musteri Listesi---\n\n"},
	{Dil::Ingilizce, "--- Customer List---\n\n"}
	}},
	{"hicMusteriYok", {
	{Dil::Turkce, "Kayitli musteri bulunamadi."},
	{Dil::Ingilizce, "No registered customers found."}
	}},
	{"paraYatiralacakHesap", {
	{Dil::Turkce, "\nPara yatirmak istediginiz hesabin numarasini giriniz: "},
	{Dil::Ingilizce, "\nPlease enter the account number for the deposit: "}
	}},
	{"hataliHesapNo", {
	{Dil::Turkce, "\nHatali hesap numarasi girdiniz! Lutfen 6 basamakli bir hesap no giriniz: "},
	{Dil::Ingilizce, "\nYou entered an invalid account number!Please enter a 6 - digit account number: "}
	}},
	{"yatirilacakParaMiktariGiriniz", {
	{Dil::Turkce, "Lutfen yuklemek istediginiz para miktarini giriniz: "},
	{Dil::Ingilizce, "Please enter the amount of money you want to deposit: "}
	}},
	{"noluHesap", {
	{Dil::Turkce, "'no lu hesaba "},
	{Dil::Ingilizce, "NO account "}
	}},
	{"yuklendi", {
	{Dil::Turkce, "TL yuklendi.\n"},
	{Dil::Ingilizce, "$ has been deposited.\n"}
	}},
	{"hesabinSonBakiyesi", {
	{Dil::Turkce, "Hesabin son bakiyesi: "},
	{Dil::Ingilizce, "The account's final balance: "}
	}},
	{"musteriNoBulunamadi", {
	{Dil::Turkce, "Girdiginiz musteri numarasiyla uyusan kullanici bulunamadi!\n"},
	{Dil::Ingilizce, "No user found with the entered customer number!\n"}
	}},
	{"hesapNoGiriniz", {
	{Dil::Turkce, "Para cekmek istediginiz hesabin numarasini giriniz: "},
	{Dil::Ingilizce, "Please enter the account number for the withdrawal: "}
	}},
	{"cekilecekParaMiktari", {
	{Dil::Turkce, "Lutfen cekmek istediginiz para miktarini giriniz: "},
	{Dil::Ingilizce, "Please enter the amount of money you want to withdraw: "}
	}},
	{"noluHesaptan", {
	{Dil::Turkce, "'no lu hesaptan "},
	{Dil::Ingilizce, "from the account with the number "}
	}},
	{"paraCekildi", {
	{Dil::Turkce, "TL cekildi.\n"},
	{Dil::Ingilizce, "$ amount in dollars has been withdrawn.\n"}
	}},
	{"tcKontrolu", {
	{Dil::Turkce, "\n1. TC kimlik Dogrulu Kontrolu = "},
	{Dil::Ingilizce, "\n1. TC identity verification ="}
	}},
	{"acik", {
	{Dil::Turkce, " ACIK"},
	{Dil::Ingilizce, " ON"}
	}},
	{ "kapali", {
	{Dil::Turkce, " KAPALI"},
	{Dil::Ingilizce, " OFF"}
	}},
	{"hesapKontrolu", {
	{Dil::Turkce, "\n2. Hesap No Dogrulu Kontrolu = "},
	{Dil::Ingilizce, "\n2. Account number validity check ="}
	}},
	{"islemKontrolu", {
	{Dil::Turkce, "\n3. Hatali Islem Sayaci = "},
	{Dil::Ingilizce, "\n3. Invalid transaction counter = "}
	}},
	{"sinirGiris", {
	{Dil::Turkce, " Sinir Giris = "},
	{Dil::Ingilizce, " Limit Entry = "}
	}},
	{"degistirilecekAyar", {
	{Dil::Turkce, "\nLutfen Degistirmek Isteginiz Ayari Tuslayin, Menu'ye donmek icin 4 girin: "},
	{Dil::Ingilizce, "\nPlease press the option for the setting you want to change, or press 4 to return to the menu: "}
	}},
	{ "tcDogrulayiciyiAcKapat", {
	{Dil::Turkce, "\nTC kimlik Dogrulugu Kontrolu'nu\n1.AC\n2.KAPAT\nYapmak istediginiz islemi giriniz: "},
	{Dil::Ingilizce, "\nTC Identity Validation Control\n1. TURN ON\n2. TURN OFF\nEnter the operation you want to perform: "}
	}},
	{"tcDogrulayiciZatenAcik", {
	{Dil::Turkce, "\nTC Kimlik Kontrolu zaten acik!"},
	{Dil::Ingilizce, "\nTC Identity Validation is already enabled!"}
	}},
	{"tcDogrulayiciAcildi", {
	{Dil::Turkce, "\nTC Kimlik Kontrolu basariyla acildi.\n"},
	{Dil::Ingilizce, "\nTC Identity Validation successfully enabled.\n"}
	}},
	{ "tcDogrulayiciZatenKapali", {
	{Dil::Turkce, "\nTC Kimlik Kontrolu zaten kapali!"},
	{Dil::Ingilizce, "\nTC Identity Validation is already disabled!"}
	} },
	{ "tcDogrulayiciKapatildi", {
	{Dil::Turkce, "\nTC Kimlik Kontrolu basariyla kapatildi.\n"},
	{Dil::Ingilizce, "\nTC Identity Validation has been successfully disabled.\n"}
	} },

	{ "hesapDogruluguAcKapat", {
	{Dil::Turkce, "\nHesap Dogrulugu Kontrolu'nu\n1.AC\n2.KAPAT\nYapmak istediginiz islemi giriniz: "},
	{Dil::Ingilizce, "\nAccount Validation\n1. ENABLE\n2. DISABLE\nEnter the operation you want to perform: "}
	} },
	{ "hesapDogruluguZatenAcik", {
	{Dil::Turkce, "\nHesap Dogrulugu Kontrolu zaten acik!"},
	{Dil::Ingilizce, "\nAccount Validation is already enabled!"}
	} },
	{ "hesapDogruluguAcildi", {
	{Dil::Turkce, "\nHesap Dogrulugu Kontrolu basariyla acildi.\n"},
	{Dil::Ingilizce, "\nAccount Validation has been successfully enabled.\n"}
	} },
	{ "hesapDogruluguZatenKapali", {
	{Dil::Turkce, "\nHesap Dogrulugu Kontrolu zaten kapali!"},
	{Dil::Ingilizce, "\nAccount Validation is already disabled!"}
	} },
	{ "hesapDogruluguKapatildi", {
	{Dil::Turkce, "\nHesap Dogrulugu Kontrolu basariyla kapatildi.\n"},
	{Dil::Ingilizce, "\nAccount Validation has been successfully disabled.\n"}
	} },

	{ "hataliIslemAcKapat", {
	{Dil::Turkce, "\nHatali Islem Sayaci'ni\n1.AC\n2.KAPAT\n3.Hatali Islem Limitini Belirle\nYapmak istediginiz islemi giriniz: "},
	{Dil::Ingilizce, "\nError Operation Counter\n1. ENABLE\n2. DISABLE\n3. Set Error Operation Limit\nEnter the operation you want to perform: "}
	} },
	{ "hataliIslemZatenAcik", {
	{Dil::Turkce, "\nHatali Islem Sayaci zaten acik!"},
	{Dil::Ingilizce, "\nError operation counter is already enabled!"}
	} },
	{ "hataliIslemAcildi", {
	{Dil::Turkce, "\nHatali Islem Sayaci basariyla acildi.\n"},
	{Dil::Ingilizce, "\nThe error operation counter has been successfully enabled.\n"}
	} },
	{ "hataliIslemZatenKapali", {
	{Dil::Turkce, "\nHatali Islem Sayaci zaten kapali!"},
	{Dil::Ingilizce, "\nThe error operation counter is already off!"}
	} },
	{ "hataliIslemKapatildi", {
	{Dil::Turkce, "\nHatali Islem Sayaci basariyla kapatildi.\n"},
	{Dil::Ingilizce, "\nThe error operation counter has been successfully closed.\n"}
	} },

	{ "onceSayaciAc", {
	{Dil::Turkce, "\nLutfen Once Hatali Islem Sayacini Aciniz!"},
	{Dil::Ingilizce, "\nPlease enable the error operation counter first!"}
	} },

	{ "yeniHataliIslemLimiti", {
	{Dil::Turkce, "Lutfen yeni hatali islem limitini belirleyiniz: "},
	{Dil::Ingilizce, "Please specify the new error operation limit:"}
	} },
	{ "hataliIslemLimitiA", {
	{Dil::Turkce, "Hatali islem limiti "},
	{Dil::Ingilizce, "Error operation limit "}
	} },
	{ "hataliIslemLimitiB", {
	{Dil::Turkce, "	olarak guncellendi."},
	{Dil::Ingilizce, " has been updated."}
	} },

	{ "hataliIslemGirildi", {
	{Dil::Turkce, "Hatali Islem girdiniz!"},
	{Dil::Ingilizce, "You entered an invalid operation!"}
	} },

	{"menu1", {
	{Dil::Turkce, "1. Musteri Ekle\n"},
	{Dil::Ingilizce, "1. Add Customer\n"}
	}},
	{ "menu2", {
	{Dil::Turkce, "2. Musteri Sil\n"},
	{Dil::Ingilizce, "2. Delete Customer\n"}
	} },
	{ "menu3", {
	{Dil::Turkce, "3. Musteri Listesi\n"},
	{Dil::Ingilizce, "3. Customer List\n"}
	} },
	{ "menu4", {
	{Dil::Turkce, "4. Para Islemleri\n"},
	{Dil::Ingilizce, "4. Money Transactions\n"}
	} },
	{ "menu5", {
	{Dil::Turkce, "5. Sistem Ayarlari\n"},
	{Dil::Ingilizce, "5. System Settings\n"}
	} },
	{ "menu6", {
	{Dil::Turkce, "6. Cikis\n"},
	{Dil::Ingilizce, "6. Exit\n"}
	} },
	{ "menu7", {
	{Dil::Turkce, "Lutfen Yapmak Istediginiz Islemi Tuslayiniz: "},
	{Dil::Ingilizce, "Please press the key for the action you want to perform: "}
	} },

	{ "paraCekMenu1", {
	{Dil::Turkce, "Para Islemleri\n"},
	{Dil::Ingilizce, "Money Transactions\n"}
	} },
	{ "paraCekMenu2", {
	{Dil::Turkce, "-	 1.Para Yatirma\n"},
	{Dil::Ingilizce, "-		1. Deposit Money\n"}
	} },
	{ "paraCekMenu3", {
	{Dil::Turkce, "-	 2.Para Cekme\n"},
	{Dil::Ingilizce, "-		2. Withdraw Money\n"}
	} },
	{ "paraCekMenu4", {
	{Dil::Turkce, "-	 3.Baska hesaba transfer\n"},
	{Dil::Ingilizce, "-		3. Transfer to Another Account\n"}
	} },
	{ "paraCekMenu5", {
	{Dil::Turkce, "-	 4.Ana Menu\n"},
	{Dil::Ingilizce, "-		4. Main Menu\n"}
	} },

	{ "programdanCikiliyor", {
	{Dil::Turkce, "Programdan cikis yapiliyor..."},
	{Dil::Ingilizce, "Exiting the program..."}
	} },

	{ "gonderenHesapAlis", {
	{Dil::Turkce, "Lutfen gonderen hesap no'sunu giris yapin: "},
	{Dil::Ingilizce, "Please enter the sender account number: "}
	} },
	{ "gonderenHesapBulunamadi", {
	{Dil::Turkce, "Gonderen hesap no bulunamadi! Lutfen Tekrar giris yapiniz: "},
	{Dil::Ingilizce, "Sender account number not found! Please try again: "}
	} },

	{ "aliciHesapAlis", {
	{Dil::Turkce, "Lutfen alici hesap no'sunu giris yapin: "},
	{Dil::Ingilizce, "Please enter the recipient account number: "}
	} },
	{ "aliciHesapBulunamadi", {
	{Dil::Turkce, "Alici hesap no bulunamadi! Lutfen Tekrar giris yapiniz: "},
	{Dil::Ingilizce, "Recipient account number not found! Please try again: "}
	} },

	{ "gonderilecekMiktarGirin", {
	{Dil::Turkce, "Gonderilicek olan para miktarini giriniz: "},
	{Dil::Ingilizce, "Please enter the amount to be transferred: "}
	} },

	{ "bakiyeYetersiz", {
	{Dil::Turkce, "Bakiye islem icin yetersizdir! Bakiyeniz = "},
	{Dil::Ingilizce, "Insufficient balance for the transaction! Your balance = "}
	} },

	{ "transfer1", {
	{Dil::Turkce, "'musteri nolu kisiye "},
	{Dil::Ingilizce, "To the customer with account number "}
	} },
	{ "transfer2", {
	{Dil::Turkce, " tarafindan "},
	{Dil::Ingilizce, " by "}
	} },
	{ "transfer3", {
	{Dil::Turkce, " TL gonderildi"},
	{Dil::Ingilizce, "$ has been sent."}
	} },

};
