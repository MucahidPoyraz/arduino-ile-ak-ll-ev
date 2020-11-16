#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial bt(3,4);//rx tx

int redled = 13;
int greenled = 12;
int buzzer = 11;
int yellowled = 10;
int lamba = 9;
int servo = 6;
int hareket = 7;

 Servo servo;
 char data;
 char veri=2;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);//
  pinMode(yellowled,OUTPUT);
  pinMode(greenled,OUTPUT);
  pinMode(redled ,OUTPUT);
   pinMode(lamba ,OUTPUT);  
  pinMode(hareket,INPUT);
  pinMode(servo,OUTPUT);
  servo.attach(6); //servo motor 6. pine baglı turuncu kablo açı kablosu
 
  servo.write(0); // başlangız açoısı o olarak ayarlandı

  attachInterrupt(0,gazalarmAc,RISING);
  attachInterrupt(0,gazalarmKapat,FALLING);
  bt.begin(9600);
}

void loop() {
  int isik = analogRead(A0);
  int isi = analogRead(A1);
  int har = digitalRead(7); // hareket sensörü digital veri alır bu yüzden 7 ye baglı
  
  char data = bt.read(); // blutut okuyor
  char veri=data;

 
  
 
  // ekrana yazdırma işlemlemleri
  Serial.println(data);
  Serial.println(veri);
  Serial.println(isik);
  Serial.println(isi);
  Serial.println(gaz);
  delay(1000);
  

 // veri="2" ise evden çıkış yapıldıgı anlamına geliyor
 if(veri=='2'){
  while(1){
    if(veri == '1'){
      veri = '1';
      break;
    }
    digitalWrite(lamba,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    servo.write(0);

     if(har == HIGH){
     digitalWrite(12,HIGH);
     digitalWrite(13,HIGH);
     digitalWrite(9,HIGH);
 }
    else{
      digitalWrite(12,LOW);
      digitalWrite(13,LOW);
      digitalWrite(9,LOW);
 }}
  }
  
  
 // veri="1" ise eve giriş yapıldıgı anlamına geliyor
if(veri=='1'){
  while(1){
    if(veri == '2'){
      veri = '2';
      break;
    }

    if(isik>700){
    servo.write(180);
    digitalWrite(9,LOW);
  }
  else{
    servo.write(0);
    digitalWrite(9,HIGH);
  }
 
 if(isi>500){
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
 }
 else if(isi>300 && isi<700){
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
 }
 else {
  digitalWrite(11,HIGH);
  digitalWrite(10,LOW);
 }}
    

    
  }
}

 void gazalarmAc(){
   digitalWrite(12,HIGH);
   digitalWrite(13,HIGH);
  
}
void gazalarmKapat(){
   digitalWrite(12,LOW);
   digitalWrite(13,LOW);
  
}
