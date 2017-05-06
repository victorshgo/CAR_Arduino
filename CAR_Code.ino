#include <AFMotor.h>

// Selecionando os motores de acordo com o posicionamento na ponte H.
AF_DCMotor motor1(3);
AF_DCMotor motor2(4);

// Variável global para indicar a direção fornecida pelo app.
char direcao;

void setup() {
  // Indicando a velocidade máxima dos motores.
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  
  // Para receber as direções fornecidas atraves do módulo bluetooth.
  Serial.begin(9600);
}

// Move o carro para frente.
void car_front(){
   motor1.run(FORWARD);
   motor2.run(FORWARD);
}

// Move o carro para trás.
void car_back(){
   motor1.run(BACKWARD);
   motor2.run(BACKWARD);
}

// Move o carro para a esquerda.
void car_left(){
   motor1.run(FORWARD);
   motor2.run(BACKWARD);
}

// Move o carro para a direita.
void car_right(){
   motor1.run(BACKWARD);
   motor2.run(FORWARD);
}

// Para o carro.
void car_stop(){
   motor1.run(RELEASE);
   motor2.run(RELEASE);
}

void loop() {
  // Variável que armazena a direção fornecida pelo usuário.
  direcao = Serial.read();

  // Condições para mover o carro de acordo com a direção selecionada atraves do app.
  if(direcao == 'W'){
     car_front();
  } else if(direcao == 'S'){
     car_back();
  } else if(direcao == 'A'){
    car_left();
  } else if(direcao == 'D'){
     car_right();
  } else if(direcao == 'E'){
     car_stop();
  }
}
