#include <reg51.h>
#define LCD_dat P2
sbit rs =P3^0;
sbit en =P3^1;

void dely(unsigned int dly);
void lcd_cmd(unsigned char ch);
void lcd_data(unsigned char ch);
void lcd_str(unsigned char *str);
void main(void)
{
	lcd_cmd(0x38);
	lcd_cmd(0x0C);
  while(1) /* infinity loop */
	{
	lcd_cmd(0x80);
	lcd_str("Welcome to AAU"); // '\0'
	lcd_cmd(0xc0);
	lcd_str("University"); // '\0'
	lcd_cmd(0x01);
	lcd_cmd(0x80);
	lcd_str("computer science faculty"); // '\0'
	lcd_cmd(0xc0);
	}
	
}
void lcd_str(unsigned char *str)
{
	unsigned int loop =0;
	for(loop =0; str[loop]!= '\0'; loop++)
	{
		lcd_data(str[loop]);
	}
}
void lcd_data(unsigned char ch)
{
	LCD_dat = ch;
	rs = 1;  // data
	en = 1;
	dely(10);
	en = 0;
}

void lcd_cmd(unsigned char ch)
{
	LCD_dat = ch;
	rs = 0;  // cmd
	en = 1;
	dely(10);
	en = 0;
}
void dely(unsigned int dly)
{
	unsigned int loop =0;
	unsigned int delay_gen =0;
	for(loop =0; loop < dly; loop++)
	for(delay_gen =0; delay_gen < 1000; delay_gen++); /* delay */
}


