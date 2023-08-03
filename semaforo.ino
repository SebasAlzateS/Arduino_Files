// Definición de pines
const int PULSADOR_1 = 2;
const int PULSADOR_2 = 3;
const int SEMAFORO_1_VERDE = 4;
const int SEMAFORO_1_AMARILLO = 5;
const int SEMAFORO_1_ROJO = 6;
const int SEMAFORO_2_VERDE = 11;
const int SEMAFORO_2_AMARILLO = 12;
const int SEMAFORO_2_ROJO = 13;

// Variables de estado
bool estado_pulsador_1 = false;
bool estado_pulsador_2 = false;
int contador_1 = 0;
int contador_2 = 0;

void setup() {
  // Inicialización de pines
  pinMode(PULSADOR_1, INPUT_PULLUP);
  pinMode(PULSADOR_2, INPUT_PULLUP);
  pinMode(SEMAFORO_1_VERDE, OUTPUT);
  pinMode(SEMAFORO_1_AMARILLO, OUTPUT);
  pinMode(SEMAFORO_1_ROJO, OUTPUT);
  pinMode(SEMAFORO_2_VERDE, OUTPUT);
  pinMode(SEMAFORO_2_AMARILLO, OUTPUT);
  pinMode(SEMAFORO_2_ROJO, OUTPUT);

  // Estado inicial
  digitalWrite(SEMAFORO_1_VERDE, HIGH);
  digitalWrite(SEMAFORO_1_AMARILLO, LOW);
  digitalWrite(SEMAFORO_1_ROJO, LOW);
  digitalWrite(SEMAFORO_2_VERDE, LOW);
  digitalWrite(SEMAFORO_2_AMARILLO, LOW);
  digitalWrite(SEMAFORO_2_ROJO, HIGH);
}

void loop() {
  // Verificación del pulsador 1
  if (digitalRead(PULSADOR_1) == LOW && !estado_pulsador_1) {
    contador_1++;
    estado_pulsador_1 = true;
    Serial.print("Contador 1: ");
    Serial.println(contador_1);
  }
  else if (digitalRead(PULSADOR_1) == HIGH) {
    estado_pulsador_1 = false;
  }

  // Verificación del pulsador 2
  if (digitalRead(PULSADOR_2) == LOW && !estado_pulsador_2) {
    contador_2++;
    estado_pulsador_2 = true;
    Serial.print("Contador 2: ");
    Serial.println(contador_2);
  }
  else if (digitalRead(PULSADOR_2) == HIGH) {
    estado_pulsador_2 = false;
  }

  // Cambio de semáforos
  if (digitalRead(SEMAFORO_1_VERDE) == HIGH && contador_1 >= 5) {
    digitalWrite(SEMAFORO_1_VERDE, LOW);
    digitalWrite(SEMAFORO_1_AMARILLO, HIGH);
    digitalWrite(SEMAFORO_2_ROJO, LOW);
    digitalWrite(SEMAFORO_2_AMARILLO, HIGH);
    delay(1000);
     digitalWrite(SEMAFORO_2_AMARILLO, LOW);
    digitalWrite(SEMAFORO_1_AMARILLO, LOW);
    digitalWrite(SEMAFORO_1_ROJO, HIGH);
    digitalWrite(SEMAFORO_2_VERDE, HIGH);
    contador_1 = 0;
  }
  else if (digitalRead(SEMAFORO_2_VERDE) == HIGH && contador_2 >= 5) {
    digitalWrite(SEMAFORO_2_VERDE, LOW);
    digitalWrite(SEMAFORO_2_AMARILLO, HIGH);
    digitalWrite(SEMAFORO_1_ROJO, LOW);
    digitalWrite(SEMAFORO_1_AMARILLO, HIGH);
    delay(1000);
    digitalWrite(SEMAFORO_1_AMARILLO, LOW);
    digitalWrite(SEMAFORO_2_AMARILLO, LOW);
    digitalWrite(SEMAFORO_2_ROJO, HIGH);
    digitalWrite(SEMAFORO_1_VERDE, HIGH);
    contador_2 = 0;
  }
}
