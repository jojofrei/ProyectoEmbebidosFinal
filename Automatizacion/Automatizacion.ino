const int sensorpinagua = A0; //pin sensor 
float bomba;
const int tvprincipal= 2; 
const int tvdormitorio= 3;
const  int acprincipal= 4;
const int acdormitorio= 5; 
const int alarma= 6;
const int ledalarma = 7; 
int estadotvprincipal= 0;
int estadotvdormitorio = 0;
int estadoacprincipal = 0; 
int estadoacdormitorio = 0;
int estadoalarma = 0;

int gas = 8;
int redled = 9;
int greenled = 10;
String alarmaIn;

void setup() {
 // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(tvprincipal, INPUT);
  pinMode(tvdormitorio, INPUT);
  pinMode(acprincipal, INPUT);
  pinMode(acdormitorio, INPUT);
  pinMode(alarma, INPUT);
  pinMode(ledalarma, OUTPUT);
  pinMode(gas, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  bomba= analogRead(A0);
  bomba= map(bomba, 0, 1023,  0, 100); 
          
  //Sistema de Entretenimiento
    
  estadotvprincipal= digitalRead(tvprincipal); 
  if( estadotvprincipal == HIGH){
    Serial.println("TV Principal Encendida");
   }
   else{
    Serial.println("TV Principal Apagada");
   }
   
   estadotvdormitorio= digitalRead(tvdormitorio);  
   if( estadotvdormitorio == HIGH){
    Serial.println("TV Dormitorio Encendida");
   }
   else{
    Serial.println("TV Dormitorio Apagada");
   }
   
  //Sistema de Aire Acondicionado
   
  estadoacprincipal= digitalRead(acprincipal); 
  if( estadoacprincipal == HIGH ){
    Serial.println("AC Principal Encendido");
   }
   else{
    Serial.println("AC Principal Apagado");
   }
     
  estadoacdormitorio= digitalRead(acdormitorio); 
  if( estadoacdormitorio== HIGH){
    Serial.println("AC Dormitorio Encendido");
   }
   else{
    Serial.println("AC Dormitorio Apagado");
   }
 
  //Sistema de Seguridad
  
  estadoalarma = digitalRead(alarma); 
  if( estadoalarma == HIGH){
    digitalWrite(ledalarma,HIGH);
    Serial.println("Alarma Encendida");
   }
   else{
    digitalWrite(ledalarma,LOW);
    Serial.println("Alarma Apagada");
   } 
    
  //Mostrar por serial

  Serial.print("Cantidad de Agua ");
  Serial.println(bomba);
  
  //Sensor de gas

  if(digitalRead(gas)==HIGH){
    alarmaIn="1";
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
    Serial.println("Alerta Incendio Llama al 911 Urgente!!");
  }
  else{
    alarmaIn="0";
    digitalWrite(10,HIGH);
    digitalWrite(9,LOW);
    Serial.println("Alerta Incendio Todo relajado!!");
  }

  delay(2000);
}
