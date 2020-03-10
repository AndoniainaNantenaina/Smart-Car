#define A 500
#define B 300
#define trigPin 9            //Trig Ultrasons (sortie)
#define echoPin 10

int motor_pin1 = 2;
int motor_pin2 = 3;
int motor_pin3 = 5;
int motor_pin4 = 6;


const unsigned long MEASURE_TIMEOUT = 25000UL; // 25ms = ~8m à 340m/s
const float SOUND_SPEED = 340.0 / 1000;

void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);   //Trig est une sortie
  pinMode(echoPin, INPUT);    //Echo est une entrée
  pinMode(motor_pin1,OUTPUT);
  pinMode(motor_pin2,OUTPUT);
  pinMode(motor_pin3,OUTPUT);
  pinMode(motor_pin4,OUTPUT);
  delay(700);
}

void loop() {
 long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);               //Trig déclenché 10ms sur HIGH
  digitalWrite(trigPin, LOW);
         
  // calcul de la distance :
  duration = pulseIn(echoPin, HIGH);   // Distance proportionnelle à la durée de sortie
  distance = duration*340/(2*10000);   //Vitesse du son théorique  
  
  if(distance >= 20) {   
      digitalWrite(motor_pin1,HIGH);   //Mandroso  
      digitalWrite(motor_pin2,LOW);      
      digitalWrite(motor_pin3,LOW);
      digitalWrite(motor_pin4,HIGH);
      //delay(A);
      digitalWrite(motor_pin1,LOW);
      digitalWrite(motor_pin2,HIGH);
      digitalWrite(motor_pin3,LOW);
      digitalWrite(motor_pin4,HIGH);
      //delay(B);
    
                                   
  }
  else {             
       digitalWrite(motor_pin1,LOW);      //Mihodina rehefa misy obstacle 
       digitalWrite(motor_pin2,HIGH);
       digitalWrite(motor_pin3,HIGH);
       digitalWrite(motor_pin4,LOW);                 
      
  }
}
