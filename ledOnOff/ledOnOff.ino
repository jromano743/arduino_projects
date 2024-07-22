const int pin1 = 3; // Asignamos el pin 2 a la variable pin1
const int pin2 = 4; // Asignamos el pin 3 a la variable pin2
const int pin3 = 5; // Asignamos el pin 4 a la variable pin3
const int pin4 = 6; // Asignamos el pin 5 a la variable pin4

const int delayTime = 500; // Tiempo de retardo en milisegundos

void setup() {
  // Configuramos los pines como salidas
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
}

void loop() {
  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;

  for (int i = 0; i <= 15; i++) {
    digitalWrite(pin1, a);
    digitalWrite(pin2, b);
    digitalWrite(pin3, c);
    digitalWrite(pin4, d);

    // Incrementamos las variables en binario
    a += 1;
    if (a == 2) {
      a = 0;
      b += 1;
      if (b == 2) {
        b = 0;
        c += 1;
        if (c == 2) {
          c = 0;
          d += 1;
        }
      }
    }

    delay(delayTime);
  }

  bool isOn = false;
  for(int i = 0; i < 6; i++){
    digitalWrite(pin1, isOn);
    digitalWrite(pin2, isOn);
    digitalWrite(pin3, isOn);
    digitalWrite(pin4, isOn);

    isOn = !isOn;
    delay(80);
  }

  digitalWrite(pin1, 0);
  digitalWrite(pin2, 0);
  digitalWrite(pin3, 0);
  digitalWrite(pin4, 0);

  delay(1000);
}
