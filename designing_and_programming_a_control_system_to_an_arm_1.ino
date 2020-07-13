
#include <Keypad.h>
int Ll=40,L2=45,CHECK;
float ANG1, ANG2 ,ANGL1, ANGL2,X,Y,ALLANG=50,INVANG;

#include <Servo.h>
Servo motor1 ;
Servo motor2 ;




char hexakeys[4][3]=
{{'1','2','3'},{'4','5','6'},{'7','8','9'},{' ','9',' '}};

byte rows [4]={A2 ,A3 , A4, A5};
byte cols [3]={5,6,7};
Keypad userINPUTS = Keypad( ' ',rows,cols,4,3);


#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  motor1.attach(7);
  motor2.attach(6);

  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop() {
  int ANGL11,ANGL12,ANGL1,
     ANGL21,ANGL22,ANGL2;
      int X1l=0,X12=0,X
    ,Y11,Y12,Y;
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
  lcd.clear(); //clear word on led
   CHECK=forwaORinver();

   if (CHECK==1) {
     int ANGL11,ANGL12,ANGL1,
     ANGL21,ANGL22,ANGL2;
     
  lcd.clear();
lcd.print ("Enter anlgle 1");
while (ANGL11==0) {ANGL11=userINPUTS.getKey();} //wait user to enter first number of Q1
lcd.setCursor (0,1);
ANGL11=ANGL1-48; // CONVERT THE Number From ASCII
lcd.print(ANGL11);    
while (ANGL12==0) {ANGL12=userINPUTS.getKey();} //wait user to enter second number of Q1
delay (500);
ANGL2=ANGL21*10+ANGL22; 
forward(); // CallING forward function
}
  else{
    int ANGL12,ANGL11;
ANGL12=ANGL12-48;
lcd. print (ANGL12);
delay (500);
ANGL1=ANGL11*10+ANGL12; 
lcd.clear();
lcd.print ("Enter anlgle 2");
while (ANGL21==0) {ANGL21=userINPUTS.getKey();} //wait user to enter first number of Q1
lcd.setCursor (0,1);
ANGL21=ANGL21-48; // CONVERT THE Number From ASCII
lcd.print(ANGL21);    
while (ANGL22==0) {ANGL22=userINPUTS.getKey();} //wait user to enter second number of Q1
ANGL22=ANGL22-48;
lcd. print (ANGL22);
  int X1l,X12,X
    ,Y11,Y12,Y;
 
lcd.clear();
lcd.print ("Enter value of X. postion");
while (X1l==0) {X11=userINPUTS.getKey();}
X1l=X1l-48;
lcd.setCursor (0,1);
lcd. print (1l);
while (X12==0) {X12=userINPUTS.getKey();}
X12=X12-48;
lcd. print (X12);
delay (500);
X=1l*10+X12;
lcd.clear();
lcd.print ("Enter value of Y");
while (Y1l==0) 
{Y1l=userINPUTS.getKey();}
Y1l=Y1l-48;
lcd.setCursor (0,1);
lcd. print (Y1l);
while (Y12==0)
{Y12=userINPUTS.getKey();}
Y12=Y12-48;
lcd. print (Y12);
delay (500);
Y=Y1l*10+Y12;
invers(); //call invers function

  }
}


int forwaORinver(){
// THE function to let the user choose type of control the arm forward/inverse kineme
char IND=0;
motol.write (0);
moto2.write (0);
lcd.clear();
lcd.print ("Press 1 FOR forward ");
lcd. setCursor (0,1);
lcd.print ("or 2 FOR Inverse");
while (IND==0)
{ IND = userINPUTS.getKey();}
IND=IND-48;
if (IND==1) {
lcd.clear();
lcd.print ("Forward Kinematic");
lcd. setCursor (0,1);
lcd.print (1);
delay (2000);
return 1;}
else if (IND==2) {
lcd.clear();
lcd.print ("Inverse Kinemitic");
lcd. setCursor (0,1);
lcd.print (2);
delay (2000);
return 2;}
  else 
    {
lcd.clear();
    lcd.print ("TRY again only 1 ,2 ");}
    
}

void forward () {
//this function to calculate Q1 &Q2
motol.write (ANGL1);
moto2.write (ANGL2);
lcd.clear();
ANG1=ANGL1*PI/180;//Degree to radian
ANG2=ANGL2*PI/180;: //Degree to radian
X=(L1*cos (ANG1) ) + (L2* cos (ANG1+ANG2));
Y=(L1*sin(ANG1))+(L2*sin(ANG1+ANG2));
lcd.print ("The postion of the end effector");
lcd.setCurser(5, 1);
lcd.print(":");
lcd.setCurser(0, 1);
lcd. print (X);
lcd.setCurser(6, 1);
lcd.print (Y);
Serial.print ("ANG1");
Serial.println(ql);
Serial.print ("ANG2");
Serial.println(q2);
delay (7000);

}
    
    

void invers() {
// this fuction to determine  end effector of arm depending on value of x, y
lcd.clear();
INVANG= (pow (X, 2) tpow (X, 2) -pow (L1, 2) -pow (L2, 2) ) / (2*L1*L2);
ANGL2=acos (INVANG);
ANG2=ANGL2*180/PI;
ANG1=ALLANG-ANG2;
lcd.print ("Angle of Arm:");
lcd.setCurser (0,1);
lcd. print ("ANG1=");
lcd.print (ANG1);
cd.setCurseor (0,1);
lcd. print ("&");
lcd.setCurser (9,1);
lcd. print ("ANG2=");
lcd.print (ANG2);
Serial.print(ANG1);
motol.write(ANG1);
moto2.write(ANG2);
delay (7000);

}
    
    
    
 
