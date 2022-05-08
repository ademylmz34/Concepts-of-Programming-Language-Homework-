/**
*
* @author Adem YILMAZ adem.yilmaz10@ogr.sakarya.edu.tr
* @since 29/04/2022
* <p>
*  Dosyanın başlık dosyasi
* </p>
*/


#ifndef DOSYA_H
#define DOSYA_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include<unistd.h>
#include <windows.h>

#include "Kisi.h"


struct DOSYA{
	char* adSoyad;
	double bakiye;
	double yatirilanBakiyeOrani;
	int sansliSayi;
	int sayi;
	
	int toplamKisiSayisi;
	int sayilarDizisiUzunlugu;
	int* sayilarDizisi;
	struct KISI** kisilerDizisi;
	
	void (*kisileriAktar)(struct DOSYA*);
	void (*sayilariAktar)(struct DOSYA*);
	void (*yoket)(struct DOSYA*);
	
};
typedef struct DOSYA* Dosya;

Dosya DosyaOlustur();
void KisileriAktar(const Dosya);
void SayilariAktar(const Dosya);
int GetSatirSayisi(char*);
void DosyaYokEt(Dosya);


#endif