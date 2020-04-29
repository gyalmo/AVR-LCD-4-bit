#include<avr/io.h>
#include<util/delay.h>
void trigger();
void display(unsigned char ch);
void cmd(unsigned char ch);
int main(void) 
{ DDRD=0xff;
  cmd(0x02);
  cmd(0x28);
  cmd(0x0f);
  cmd(0x80);
  unsigned char line_1[]="ABC DE";
  unsigned char line_2[]="Fbcdefghijk";
  for(unsigned int i=0,j=0;line_1[i]!='\0'||line_2[j]!='\0';) 
    { if(line_1[i]!='\0') 
       { cmd(0x85+i);
         display(line_1[i]);
         i++;
       }
      if(line_2[j]!='\0') 
       { cmd(0xc3+j);
         display(line_2[j]);
         j++;
       }
    }
  while(1);
}
void cmd(unsigned char ch)
{ PORTD=ch&0xf0;
  trigger();
  PORTD=ch<<4;
  trigger();
}
void display(unsigned char ch)
{ PORTD=(ch&0xf0)|1;
  trigger();
  PORTD=(ch<<4)|1;
  trigger();
}
void trigger()
{ PORTD|=(1<<2);
  _delay_ms(1);
  PORTD&=~(1<<2);
}

