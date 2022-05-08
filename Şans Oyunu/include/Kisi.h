/**
*
* @author Adem YILMAZ adem.yilmaz10@ogr.sakarya.edu.tr
* @since 29/04/2022
* <p>
*  Kişi başlık dosyasi
* </p>
*/
#ifndef KISI_H
#define KISI_H

#include "stdio.h"
#include "stdlib.h"

struct KISI{
	char *adSoyad;
	double bakiye;
	double yatirilanBakiyeOrani;
	int sayi;
	
	
	void (*yoket)(struct KISI*);
};
typedef struct KISI* Kisi;

Kisi kisiOlustur(char*,double,double,int);
void KisiYokEt(const Kisi);


#endif