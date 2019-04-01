#define PIEZO1 A0
#define PIEZO2 A1
#define DelayTime 200

unsigned long lastTime1 = 0;
unsigned long lastTime2 = 0;

unsigned long curTime1;
unsigned long curTime2;

int sensor1;
int sensor2;

//---------------------interrupt function---------------------------------
//------------------------ set up -----------------------------------------
void setup() {
  Serial.begin(9600);
}
//--------------------------- loop ---------------------------------------------------------
void loop() {
  
  
  sensor1 = analogRead(PIEZO1);
  sensor2 = analogRead(PIEZO2);

  curTime1 = millis();
  curTime2 = curTime1;
  
  if(sensor1 > 0 && (curTime1 - lastTime1) > DelayTime ){
    Serial.println("쿵");
    lastTime1 = millis();
  }
  
  if(sensor2 > 0 && (curTime2 - lastTime2) > DelayTime ){
    Serial.println("짝");
    lastTime2 = millis();
  }
  
}
