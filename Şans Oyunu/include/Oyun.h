/**
*
* @author Adem YILMAZ adem.yilmaz10@ogr.sakarya.edu.tr
* @since 29/04/2022
* <p>
*  Oyun dosyasının başlık dosyasi
* </p>
*/

#ifndef OYUN_H
#define OYUN_H

#include "stdio.h"
#include "stdlib.h"

#include "Dosya.h"
#include <time.h>
#include <unistd.h>
struct OYUN{
	double masaBakiye;
	Dosya dosya;
	Kisi zenginKisi;
	double kisiYatirilanBakiye;
	int kisisanslisayi;
	int elenenKisiSayisi;
	int* sayilar;
	int toplamKisiSayisi;
	int sayilarDizisiUzunlugu;

	void (*basla)(struct OYUN*);
	void (*yoket)(struct OYUN*);
	
};
typedef struct OYUN* Oyun;

Oyun OyunOlustur();
void Basla(const Oyun);
int intUzunlukAlma(int);
Kisi enZenginKisiBul(Oyun);
void yazdir(int,char*,double,double,int,int,int);
void OyunYokEt(const Oyun);


#endif