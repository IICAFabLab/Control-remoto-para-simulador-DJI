//Variables para los ejes "x" y "y" del joystick izquierdo (a) y del derecho (b)
int ax= 0;
int bx= 0;
int ay= 0;
int by= 0;

//Variables de cotrol para los joysticks
bool leftA = false;
bool upA = false;
bool downA = false;
bool rightA = false;

bool leftB = false;
bool upB = false;
bool downB = false;
bool rightB = false;

//Variables para los diales izquierdo (a) y derecho(b)
int encoder0PinB = 8;
int encoder0PinALast = LOW;
int n = LOW;

long time = 0;
long time2 = 2;
int salida = 4; //declaracion de puerto y nombre
// int potenciometro = A0; // declaracion de puerto y nombre (ADC)
//float lectura; // se utiliza la variable flotante para tener una mejor lectura de numero probenientes del potenciometro

int control = 0;
int rt = 0;
int c1 = 0;
int c2 = 0;


void setup() {
 // pinMode (encoder0PinA, INPUT);
  pinMode(encoder0PinB, INPUT);//Pin 8 dial izquierdo
  Serial.begin(115200);
  pinMode(salida, OUTPUT); //buzzer pin 4
  pinMode(5, OUTPUT); //LED boton ON/OFF
  pinMode(6,INPUT); //Boton ON/OFF
  pinMode(10,INPUT); //boton cuadrado derecho
  pinMode(9,INPUT); //boton superior derecho 1
  pinMode(12, INPUT); //boton cuadrado izquierdo
  pinMode(7, OUTPUT); //LED boton retorno al origen
  pinMode(11,INPUT);//Boton retorno al origen
  time = millis();
  time2 = millis();
  attachInterrupt(digitalPinToInterrupt(2),enc1,RISING);
}

void enc1(){
  if(control == 5){
  
    if (digitalRead(encoder0PinB) == LOW) {
      //encoder0Pos--;
      Serial.println("gu");
    } else {
      //encoder0Pos++;
      Serial.println("gd");
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(String(control)+" , "+String(millis()-time));
  if (control>3&&control<9){
    digitalWrite(5,HIGH);
  }else{
    digitalWrite(5,LOW);
  }
  
  
  if(control==0 && digitalRead(6)){ //oprimen boton on
    control = 1;
    delay(50);
  }
  if(control==1 && !digitalRead(6)){ //sueltan boton on
    time = millis();
    control = 2;
    delay(50);
  }
  if(control==2 && digitalRead(6)){
    control = 3;
    delay(50);
    time = millis();
  }
  if(control==3 && !digitalRead(6)){
    control = 0;
    delay(50);
  }
//--------------------------------------------------------
      if(control==4 && !digitalRead(6)){
        control = 5;
        delay(50);
      }
  if(control==5 && digitalRead(6)){
    control = 6;
    delay(50);
    tone (salida, 1800,80);
  }
  if(control==6 && !digitalRead(6)){
    time = millis();
    delay(50);
    control = 7;
  }
  if(control==7 && digitalRead(6)){
    control = 8;
    delay(50);
    time = millis();
    tone (salida, 1800,80);
    
  }
    if(control==8 && !digitalRead(6)){
      control = 5;
      delay(50);
    }
  if(control==9 && !digitalRead(6)){
    control = 0;
    delay(50);
  }

  if(millis()-time>2000){
    
    switch (control)  {
    
    case 2:
      control = 0;
      break;
    
    case 3:
      tone (salida, 1750,150); //De aquí borrar el "300" si se quiere un tono continuo
      delay(150);// Borrar esta línea completa si se quiere un tono continuo
      tone (salida, 1250,150); //De aquí borrar el "300" si se quiere un tono continuo
      delay(150);
      tone (salida, 2550,150); 
      control = 4;
      break;
    
    

    case 7:
      control = 5;
      break;

    case 8:
      control = 9;
      tone (salida, 2550,150); //De aquí borrar el "300" si se quiere un tono continuo
      delay(150);// Borrar esta línea completa si se quiere un tono continuo
      tone (salida, 1250,150); //De aquí borrar el "300" si se quiere un tono continuo
      delay(150);
      tone (salida, 1750,150); //De aquí borrar el "300" si se quiere un tono continuo
    
      break;

    default:
      break;
        // code to be executed if
        // expression doesn't match any constant
    }
  }

  if(control == 5){
    if(rt==0){
      digitalWrite(7,LOW);
    }
    if(rt==0 && digitalRead(11)){
      rt = 1;
      time2 = millis();
      digitalWrite(7,HIGH);
      tone (salida, 2550,100);
      delay(50);
      
    }
    if(rt==1 && !digitalRead(11)){
      rt = 0;
      digitalWrite(7,LOW);
      delay(50);
    }
    //Serial.println(c1);
    if(c1==0 && digitalRead(10)){
      c1 = 1;
      Serial.println("c1");
      delay(50);
      
    }
    if(c1==1 && !digitalRead(10)){
      c1 = 0;
      delay(50);
    }

    if(c2==0 && digitalRead(12)){
      c2 = 1;
      Serial.println("c2");
      delay(50);
      
    }
    if(c2==1 && !digitalRead(12)){
      c2 = 0;
      delay(50);
    }


    if(millis()-time2>2000){
      switch (rt)  {
        case 1:
        rt = 2;
        digitalWrite(7,LOW);
        delay(200);
        digitalWrite(7,HIGH);
        tone (salida, 2550,100);
        delay(200);
        digitalWrite(7,LOW);
        delay(200);
        digitalWrite(7,HIGH);
        tone (salida, 2550,100);
        delay(200);
        digitalWrite(7,LOW);
        Serial.println("return");
        break;

        case 2:
        rt = 0;
        break;

      default:
        break;
      }
    }

    //Serial.println(rt);

    ax = analogRead(A0);
    ay = analogRead(A1);
    bx = analogRead(A2);
    by = analogRead(A3);

    // Serial.print("ax: ");
    // Serial.println(ax);

    // Serial.print("ay: ");
    // Serial.println(ay);

    // Serial.print("bx: ");
    // Serial.println(bx);

    // Serial.print("by: ");
    // Serial.println(by);

    if(ax < 300 && !leftA){
      Serial.println("l0");
      leftA = true;
    }
    if(ax > 700 && !rightA){
      Serial.println("r0");  
      rightA = true;
    }
    if(ay < 300 && !downA){
      Serial.println("u0");
      downA = true;
    }
    if(ay > 700 && !upA){
      Serial.println("d0");
      upA = true;
    }

    if(ax > 300 && leftA){
      Serial.println("nl0");
      leftA = false;
    }
    if(ax < 700&& rightA){
      Serial.println("nr0");  
      rightA = false;
    }
    if(ay > 300 && downA){
      Serial.println("nu0");
      downA = false;
    }
    if(ay < 700 && upA){
      Serial.println("nd0");
      upA = false;
    }


  //...........................................

    if(bx < 300 && !leftB){
      Serial.println("l1");
      leftB = true;
    }
    if(bx > 700 && !rightB){
      Serial.println("r1");  
      rightB = true;
    }
    if(by < 300 && !downB){
      Serial.println("u1");
      downB = true;
    }
    if(by > 700 && !upB){
      Serial.println("d1");
      upB = true;
    }

    if(bx > 300 && leftB){
      Serial.println("nl1");
      leftB = false;
    }
    if(bx < 700 && rightB){
      Serial.println("nr1");  
      rightB = false;
    }
    if(by > 300 && downB){
      Serial.println("nu1");
      downB = false;
    }
    if(by < 700 && upB){
      Serial.println("nd1");
      upB = false;
    }
  }
  delay(20);
}
