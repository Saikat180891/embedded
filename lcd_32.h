void lcd_init();
void dis_cmd(char cmd_value);
void dis_data(char data_value);
void lcdcmd(char cmdout);
void lcddata(char dataout);
void lcd_string(unsigned char *disp);
void lcd_num(unsigned int i);
void lcd_xy(unsigned char x,unsigned char y);
