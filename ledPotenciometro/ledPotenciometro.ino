int potPin = A0;  // Pin analógico donde está conectado el potenciómetro
int ledPin = 3;   // Pin digital PWM donde está conectado el LED
int ledPin2 = 9;
int ledPin3 = 10;
int dt = 100;     // Retardo de 100 ms

void setup() {
  pinMode(potPin, INPUT);  // Configurar el pin del potenciómetro como entrada
  pinMode(ledPin, OUTPUT); // Configurar el pin del LED como salida
  pinMode(ledPin2, OUTPUT); 
  pinMode(ledPin3, OUTPUT);

  analogWrite(ledPin, 0);
  analogWrite(ledPin2, 0);
  analogWrite(ledPin3, 0);
}

void loop() {
  int analogVal = analogRead(potPin);  // Leer el valor del potenciómetro

  // Mapear el valor del potenciómetro a 0-255 para PWM
  int pwmVal = map(analogVal, 0, 1023, 0, 255);

  // Control de los pines según los rangos especificados
  if (pwmVal < 85) {
    analogWrite(ledPin, map(pwmVal, 0, 85, 0, 255));  // Encender pin1 al 100%
    analogWrite(ledPin2, 0);    // Apagar pin2
    analogWrite(ledPin3, 0);    // Apagar pin3
  } else if (pwmVal >= 85 && pwmVal < 170) {
    analogWrite(ledPin, 255);    // Apagar pin1
    analogWrite(ledPin2, map(pwmVal, 85, 170, 0, 255)); // Controlar pin2
    analogWrite(ledPin3, 0);    // Apagar pin3
  } else if (pwmVal >= 170 && pwmVal <= 255) {
    analogWrite(ledPin, 255);    // Apagar pin1
    analogWrite(ledPin2, 255);    // Apagar pin2
    analogWrite(ledPin3, map(pwmVal, 170, 255, 0, 255)); // Controlar pin3
  }

  delay(dt);  // Esperar 100 ms
}
