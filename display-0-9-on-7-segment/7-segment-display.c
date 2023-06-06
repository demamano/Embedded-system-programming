#include<reg51.h>
void main(){


unsigned char seg[10]={0xc0,0xf9,0xa4,0x99,0x92,0x82,0xf8,0x80,0x90};
unsigned char x;
unsigned int  i;
P1=0x00; //output configuration
while(1) {
	for(x=0;x<10;x++){
	P1=seg[x];
		for(i=0;i<60000;i++);
	}
}
}
