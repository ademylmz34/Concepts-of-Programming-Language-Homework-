/**
*
* @author Adem YILMAZ adem.yilmaz10@ogr.sakarya.edu.tr
* @since 29/04/2022
* <p>
*  Test
* </p>
*/


#include "Oyun.h"

int main(){
	Oyun oyun= OyunOlustur();
	oyun->basla(oyun);
	oyun->yoket(oyun);
	return 0;
}