int dont=1,yes=0,inc=0;
char readf[32]={0};
int dummy=0,dumv=0;
char clr[3]={'c','l','e'};//clear
char hom[3]={'h','o','m'};//home
char set[3]={'s','e','t'};//set cursor
char pri[3]={'p','r','i'};//print on lcd
char cur[3]={'c','u','r'};//cursor on
char noc[3]={'n','o','c'};//no cursor
char bli[3]={'b','l','i'};//blink
char nob[3]={'n','o','b'};//no blink
char dis[3]={'d','i','s'};//diplay on
char nod[3]={'n','o','d'};//display off
char sdl[3]={'s','d','l'};//scroll display left
char sdr[3]={'s','d','r'};//scroll display right
char ltr[3]={'l','t','r'};//left to right
char rtl[3]={'r','t','l'};//right to left
char aut[3]={'a','u','t'};//auto scroll
char noa[3]={'n','o','a'};// no auto scroll
char bau[3]={'b','a','u'};//baud rate
char bac[3]={'b','a','c'};//back light 
char num[3]={'n','u','m'};//for variables
char tocheck[3]={0};

#include <LiquidCrystal.h>
#include <EEPROM.h>
LiquidCrystal lcd(12,11,14,15,16,17);

void setup()
{
  pinMode(5,OUTPUT);
  analogWrite(5,0);
// digitalWrite(5,LOW);
  dummy=EEPROM.read(5);
  if(dummy==1)
  Serial.begin(1200);
  if(dummy==2)
  Serial.begin(2400);
  if(dummy==4)
  Serial.begin(4800);
  if(dummy==9)
  Serial.begin(9600);
  if(dummy==0)
  Serial.begin(9600);
  dummy=0;
  lcd.begin(16,2);
  lcd.print("testing ");
  delay(2000);
  //digitalWrite(5,HIGH);
  analogWrite(5,255);
  delay(2000);
//  analogWrite(5,100);
//  delay(2000);
//  analogWrite(5,150);
//  delay(2000);
//  analogWrite(5,210);
//  delay(4000);
  lcd.clear();
}

void loop()
{
  if(Serial.available()>0)
  {
    readf[inc]=Serial.read();
    
    if(readf[0]=='$')
    dont=0;
  
    if(readf[inc]=='/')
    {
      dummy=inc;
    }
    
    dumv=inc-dummy;
    
    if(dumv==1)
    {
      if(readf[inc]=='n')
      {
        gopera();
        dont=1;
        for(inc=0;inc<32;inc++)
        readf[inc]='0';
        inc=0;
        dumv=0;
        dummy=0;
      }
    }
    
    if(dont==0)
    inc++;
  }
}

void gopera(void)
{
  int i=0,j=0;
  
 for(i=2;i<5;i++)
 {
   tocheck[j]=readf[i];
   j++;
 }
 
 
// for(j=0;j<3;j++)
// Serial.print(tocheck[j]);
// Serial.println(" ");
 
 i=j=0;
 
 for(j=0;j<3;j++)
 if(tocheck[j]==clr[j])
 {
   i++;
   if(i==3)
   callclr();
 }
 
 i=0;
 for(j=0;j<3;j++)
 if(tocheck[j]==hom[j])
 {
   i++;
   if(i==3)
   callhome();
 }
 
 i=0;
 for(j=0;j<3;j++)
 if(tocheck[j]==set[j])
 {
   i++;
   if(i==3)
   setcur();
 }
 
 i=0;
 for(j=0;j<3;j++)
 if(tocheck[j]==pri[j])
 {
   i++;
   if(i==3)
   calprint();
 }
 
 i=0;
 for(j=0;j<3;j++)
 if(tocheck[j]==cur[j])
 {
   i++;
   if(i==3)
   cursoron();
 }
 
 i=0;
 for(j=0;j<3;j++)
 if(tocheck[j]==noc[j])
 {
   i++;
   if(i==3)
   nocursor();
 }
 
 i=0;
 for(j=0;j<3;j++)
 if(tocheck[j]==bli[j])
 {
   i++;
   if(i==3)
   blinkon();
 }
 
 i=0;
 for(j=0;j<3;j++)
 if(tocheck[j]==nob[j])
 {
   i++;
   if(i==3)
   blinkoff();
 }
 
 i=0;
 for(j=0;j<3;j++)
 if(tocheck[j]==dis[j])
 {
   i++;
   if(i==3)
   dison();
 }
 
 i=0;
 for(j=0;j<3;j++)
 if(tocheck[j]==nod[j])
 {
   i++;
   if(i==3)
   nodis();
 }
 

  i=0;
 for(j=0;j<3;j++)
 if(tocheck[j]==sdl[j])
 {
   i++;
   if(i==3)
   scrdisl();
 }
 
  i=0;
 for(j=0;j<3;j++)
 if(tocheck[j]==sdr[j])
 {
   i++;
   if(i==3)
   scrdisr();
 }
 
   i=0;
 for(j=0;j<3;j++)
 if(tocheck[j]==ltr[j])
 {
   i++;
   if(i==3)
   lftrht();
 }
 
  i=0;
 for(j=0;j<3;j++)
 if(tocheck[j]==rtl[j])
 {
   i++;
   if(i==3)
   rhtlft();
 }
 
 i=0;
 for(j=0;j<3;j++)
 if(tocheck[j]==aut[j])
 {
   i++;
   if(i==3)
   autoscr();
 }
 
 i=0;
 for(j=0;j<3;j++)
 if(tocheck[j]==noa[j])
 {
   i++;
   if(i==3)
   noautoscr();
 }
 
 i=0;
 for(j=0;j<3;j++)
 if(tocheck[j]==bau[j])
 {
   i++;
   if(i==3)
   baudchange();
 }
 
 i=0;
 for(j=0;j<3;j++)
 if(tocheck[j]==bac[j])
 {
   i++;
   if(i==3)
   backlight();
 }
 
  i=0;
 for(j=0;j<3;j++)
 if(tocheck[j]==num[j])
 {
   i++;
   if(i==3)
   dispnumber();
 }
 
}

void callclr(void)
{
  //Serial.println("clear function");
  lcd.clear();
}

void callhome(void)
{
 //Serial.println("home function");
  lcd.home();
}

void setcur(void)
{
  int c='0',r='0';
  char c1='0';
  //Serial.println("setcursor function");
  c=readf[13];
  r=readf[15];
  c=c-48;//decimal value for 0 is 48
  r=r-48;
  if(c>9)
  {
    c1=readf[13];
    if((c1=='A')||(c1=='a'))
    c=10;
    if((c1=='B')||(c1=='b'))
    c=11;
    if((c1=='C')||(c1=='c'))
    c=12;
    if((c1=='D')||(c1=='d'))
    c=13;
    if((c1=='E')||(c1=='e'))
    c=14;
    if((c1=='F')||(c1=='f'))
    c=15;
  }
  lcd.setCursor(c,r);
}

void calprint(void)
{
  int i1=0,j1=0;
  char disp[16]={0};
//  Serial.println("print function");
  for(i1=8;i1<24;i1++)
  {
    disp[j1]=readf[i1];
    j1++;
  }
  
//  Serial.print(disp[j1]);
//  Serial.println(" ");
  for(j1=0;j1<15;)
  {
    if(disp[j1]!='/')
    {
      lcd.print(disp[j1]);
      j1++;
    }
    else
    {
      j1++;
      if(disp[j1]=='n')
      j1=16;
      else
      {
        j1--;
        lcd.print(disp[j1]);
        j1++;
      }
    }
  }
  
}

void cursoron(void)
{
  //Serial.println("cursoron function");
  lcd.cursor();
}

void nocursor(void)
{
  //Serial.println("nocursor function");
  lcd.noCursor();
}

void blinkon(void)
{
  //Serial.println("blinkon function");
  lcd.blink();
}

void blinkoff(void)
{
  //Serial.println("blinkoff function");
  lcd.noBlink();
}

void dison(void)
{
  //Serial.println("display on function");
  lcd.display();
}

void nodis(void)
{
  //Serial.println("display off function");
  lcd.noDisplay();
}


void scrdisl(void)
{
  int repea=0;
  //Serial.println("scroll display left function");
  for(repea=0;repea<16;repea++)
  {
   lcd.scrollDisplayLeft();
   delay(250);
  }
}

void scrdisr(void)
{
  //Serial.println("scroll display right function");
  int repea1=0;
  for(repea1=0;repea1<16;repea1++)
  {
   lcd.scrollDisplayRight();
   delay(250);
  }
}

void lftrht(void)
{
  //Serial.println(" left 2 right function");
  lcd.leftToRight();
}

void rhtlft(void)
{
  //Serial.println("right 2 left function");
  lcd.rightToLeft();
}

void autoscr(void)
{
  //Serial.println("auto scroll function");
  lcd.autoscroll();
}

void noautoscr(void)
{
  //Serial.println("no auto scroll function");
  lcd.noAutoscroll();
}

void baudchange(void)
{
  //Serial.println("baud rate change function");
  int budrte=0;
  budrte=readf[12];
  budrte=budrte-48;
  EEPROM.write(5,budrte);
}

void backlight(void)
{
  //Serial.println("backlight on/off");
  if(readf[14]=='f')
  analogWrite(5,0);
  if(readf[14]=='n')
  analogWrite(5,255);
}

void dispnumber(void)
{
//  Serial.println("i am at disp num");
   int i1=6;//starting of data
  
  while(readf[i1]!='/')
  {
    lcd.print(readf[i1]);
    i1++;
    if(i1==11)//max of 6 numbers
    break;
  }
  
}
