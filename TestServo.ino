/*

Commande de servo-moteur par impulsion

Nanomaître 2015

Le servo est connecté au pin 8 de l'arduino

*/

int periode=20000;// période entre chaque début d'impulsion en microsecondes

int pinServo=9; // variable pour le pin connecté à la commande du servo
int angle =0;

void setup() {
  Serial.begin(9600);
  pinMode(pinServo,OUTPUT);// on prépare le pin en mode OUTPUT

  digitalWrite(pinServo,LOW); // on l'initialise à l'état bas

}


//boucle principale

void loop() {

avancerParPas(10);
delay(2000);
reculerParPas(5);
}


//fonction setAngle pour envoyer les impulsions

void setAngle(int a){

  int duree=map(a,0,180,1000,2000);// on transforme l'angle en microsecondes et on stocke dans la variable duree

  //digitalWrite(pinServo,LOW);//on met le pin à l'état bas
  //delayMicroseconds(periode-duree);
   Serial.println(a);
  delay(100);
  digitalWrite(pinServo,HIGH);
  delayMicroseconds(duree);
  digitalWrite(pinServo,LOW);

}


void avancerParPas(int pas){
  while(angle < 90){
    setAngle(angle);
    angle+=pas;
  }
}

void reculerParPas(int pas){
  angle=90;
  while(angle < 180){
    setAngle(angle);
    angle+=pas;
  }
  angle =0;
}

