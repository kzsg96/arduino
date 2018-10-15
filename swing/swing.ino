//サーボモーターを制御するためのライブラリをインクルード
#include<Servo.h>

#define WAIT      50
#define WAIT_TERM 300
#define ANG_STA 0
#define ANG_END 180
#define ANG_DIF 1

Servo servo;

unsigned char angle;
char inc;

void setup(void){  
  servo.attach(4); //デジタル4番ピンをサーボモーターの出力ピンとして設定
  servo.write(ANG_STA);

  angle = ANG_STA;
}
 
void loop(void){  
  
  servo.write(angle); 
  if (angle == ANG_END) {
    inc = -ANG_DIF;
    delay(WAIT_TERM);
  } else if (angle == ANG_STA) {
    inc = ANG_DIF;
    delay(WAIT_TERM);
  }
  angle += inc;
    delay(WAIT);  
}
