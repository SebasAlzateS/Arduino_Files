#define in1_motor1 2
#define in2_motor1 3
#define in3_motor1 4
#define in4_motor1 5

#define in1_motor2 6
#define in2_motor2 7
#define in3_motor2 8
#define in4_motor2 9

#define velocidad 1
#define dataLength 4

String inputString = "";
bool stringComplete = false;
const char separator = ',';
uint8_t data[dataLength];

uint32_t pasos_motor1;
uint8_t sentido_motor1 = 0;  // Inicializar sentido del motor 1 en 0
uint32_t grados_motor1 = 0;  // Inicializar grados del motor 1 en 0

uint32_t pasos_motor2;
uint8_t sentido_motor2 = 0;  // Inicializar sentido del motor 2 en 0
uint32_t grados_motor2 = 0;  // Inicializar grados del motor 2 en 0

void adelante(uint16_t p, uint16_t v, uint8_t motor)
{
  for (uint16_t i = 0; i < p; i++)
  {
    if (motor == 1)
    {
      sentido_horario(v, motor);
    }
    else if (motor == 2)
    {
      sentido_horario(v, motor);
    }
  }
}

void atras(uint16_t p, uint16_t v, uint8_t motor)
{
  for (uint16_t i = 0; i < p; i++)
  {
    if (motor == 1)
    {
      sentido_antihorario(v, motor);
    }
    else if (motor == 2)
    {
      sentido_antihorario(v, motor);
    }
  }
}

void sentido_horario(uint16_t v, uint8_t motor)
{
  if (motor == 1)
  {
    digitalWrite(in1_motor1, HIGH);
    digitalWrite(in2_motor1, LOW);
    digitalWrite(in3_motor1, LOW);
    digitalWrite(in4_motor1, LOW);
    delay(v);
    digitalWrite(in1_motor1, HIGH);
    digitalWrite(in2_motor1, HIGH);
    digitalWrite(in3_motor1, LOW);
    digitalWrite(in4_motor1, LOW);
    delay(v);
    digitalWrite(in1_motor1, LOW);
    digitalWrite(in2_motor1, HIGH);
    digitalWrite(in3_motor1, LOW);
    digitalWrite(in4_motor1, LOW);
    delay(v);
    digitalWrite(in1_motor1, LOW);
    digitalWrite(in2_motor1, HIGH);
    digitalWrite(in3_motor1, HIGH);
    digitalWrite(in4_motor1, LOW);
    delay(v);
    digitalWrite(in1_motor1, LOW);
    digitalWrite(in2_motor1, LOW);
    digitalWrite(in3_motor1, HIGH);
    digitalWrite(in4_motor1, LOW);
    delay(v);
    digitalWrite(in1_motor1, LOW);
    digitalWrite(in2_motor1, LOW);
    digitalWrite(in3_motor1, HIGH);
    digitalWrite(in4_motor1, HIGH);
    delay(v);
    digitalWrite(in1_motor1, LOW);
    digitalWrite(in2_motor1, LOW);
    digitalWrite(in3_motor1, LOW);
    digitalWrite(in4_motor1, HIGH);
    delay(v);
    digitalWrite(in1_motor1, HIGH);
    digitalWrite(in2_motor1, LOW);
    digitalWrite(in3_motor1, LOW);
    digitalWrite(in4_motor1, HIGH);
    delay(v);
  }
  else if (motor == 2)
  {
    digitalWrite(in1_motor2, HIGH);
    digitalWrite(in2_motor2, LOW);
    digitalWrite(in3_motor2, LOW);
    digitalWrite(in4_motor2, LOW);
    delay(v);
    digitalWrite(in1_motor2, HIGH);
    digitalWrite(in2_motor2, HIGH);
    digitalWrite(in3_motor2, LOW);
    digitalWrite(in4_motor2, LOW);
    delay(v);
    digitalWrite(in1_motor2, LOW);
    digitalWrite(in2_motor2, HIGH);
    digitalWrite(in3_motor2, LOW);
    digitalWrite(in4_motor2, LOW);
    delay(v);
    digitalWrite(in1_motor2, LOW);
    digitalWrite(in2_motor2, HIGH);
    digitalWrite(in3_motor2, HIGH);
    digitalWrite(in4_motor2, LOW);
    delay(v);
    digitalWrite(in1_motor2, LOW);
    digitalWrite(in2_motor2, LOW);
    digitalWrite(in3_motor2, HIGH);
    digitalWrite(in4_motor2, LOW);
    delay(v);
    digitalWrite(in1_motor2, LOW);
    digitalWrite(in2_motor2, LOW);
    digitalWrite(in3_motor2, HIGH);
    digitalWrite(in4_motor2, HIGH);
    delay(v);
    digitalWrite(in1_motor2, LOW);
    digitalWrite(in2_motor2, LOW);
    digitalWrite(in3_motor2, LOW);
    digitalWrite(in4_motor2, HIGH);
    delay(v);
    digitalWrite(in1_motor2, HIGH);
    digitalWrite(in2_motor2, LOW);
    digitalWrite(in3_motor2, LOW);
    digitalWrite(in4_motor2, HIGH);
    delay(v);
  }
}

void sentido_antihorario(uint16_t v, uint8_t motor)
{
  if (motor == 1)
  {
    digitalWrite(in4_motor1, HIGH);
    digitalWrite(in3_motor1, LOW);
    digitalWrite(in2_motor1, LOW);
    digitalWrite(in1_motor1, LOW);
    delay(v);
    digitalWrite(in4_motor1, HIGH);
    digitalWrite(in3_motor1, HIGH);
    digitalWrite(in2_motor1, LOW);
    digitalWrite(in1_motor1, LOW);
    delay(v);
    digitalWrite(in4_motor1, LOW);
    digitalWrite(in3_motor1, HIGH);
    digitalWrite(in2_motor1, LOW);
    digitalWrite(in1_motor1, LOW);
    delay(v);
    digitalWrite(in4_motor1, LOW);
    digitalWrite(in3_motor1, HIGH);
    digitalWrite(in2_motor1, HIGH);
    digitalWrite(in1_motor1, LOW);
    delay(v);
    digitalWrite(in4_motor1, LOW);
    digitalWrite(in3_motor1, LOW);
    digitalWrite(in2_motor1, HIGH);
    digitalWrite(in1_motor1, LOW);
    delay(v);
    digitalWrite(in4_motor1, LOW);
    digitalWrite(in3_motor1, LOW);
    digitalWrite(in2_motor1, HIGH);
    digitalWrite(in1_motor1, HIGH);
    delay(v);
    digitalWrite(in4_motor1, LOW);
    digitalWrite(in3_motor1, LOW);
    digitalWrite(in2_motor1, LOW);
    digitalWrite(in1_motor1, HIGH);
    delay(v);
    digitalWrite(in4_motor1, HIGH);
    digitalWrite(in3_motor1, LOW);
    digitalWrite(in2_motor1, LOW);
    digitalWrite(in1_motor1, HIGH);
    delay(v);
  }
  else if (motor == 2)
  {
    digitalWrite(in4_motor2, HIGH);
    digitalWrite(in3_motor2, LOW);
    digitalWrite(in2_motor2, LOW);
    digitalWrite(in1_motor2, LOW);
    delay(v);
    digitalWrite(in4_motor2, HIGH);
    digitalWrite(in3_motor2, HIGH);
    digitalWrite(in2_motor2, LOW);
    digitalWrite(in1_motor2, LOW);
    delay(v);
    digitalWrite(in4_motor2, LOW);
    digitalWrite(in3_motor2, HIGH);
    digitalWrite(in2_motor2, LOW);
    digitalWrite(in1_motor2, LOW);
    delay(v);
    digitalWrite(in4_motor2, LOW);
    digitalWrite(in3_motor2, HIGH);
    digitalWrite(in2_motor2, HIGH);
    digitalWrite(in1_motor2, LOW);
    delay(v);
    digitalWrite(in4_motor2, LOW);
    digitalWrite(in3_motor2, LOW);
    digitalWrite(in2_motor2, HIGH);
    digitalWrite(in1_motor2, LOW);
    delay(v);
    digitalWrite(in4_motor2, LOW);
    digitalWrite(in3_motor2, LOW);
    digitalWrite(in2_motor2, HIGH);
    digitalWrite(in1_motor2, HIGH);
    delay(v);
    digitalWrite(in4_motor2, LOW);
    digitalWrite(in3_motor2, LOW);
    digitalWrite(in2_motor2, LOW);
    digitalWrite(in1_motor2, HIGH);
    delay(v);
    digitalWrite(in4_motor2, HIGH);
    digitalWrite(in3_motor2, LOW);
    digitalWrite(in2_motor2, LOW);
    digitalWrite(in1_motor2, HIGH);
    delay(v);
  }
}

void serialEvent()
{
  while (Serial.available())
  {
    char inChar = (char)Serial.read();
    inputString += inChar;
    if (inChar == '-')
    {
      stringComplete = true;
    }
  }
}

void setup()
{
  pinMode(in1_motor1, OUTPUT);
  pinMode(in2_motor1, OUTPUT);
  pinMode(in3_motor1, OUTPUT);
  pinMode(in4_motor1, OUTPUT);

  pinMode(in1_motor2, OUTPUT);
  pinMode(in2_motor2, OUTPUT);
  pinMode(in3_motor2, OUTPUT);
  pinMode(in4_motor2, OUTPUT);

  Serial.begin(9600);
}


void loop()
{
  if (stringComplete)
  {
    for (uint8_t i = 0; i < dataLength; i++)
    {
      uint8_t index = inputString.indexOf(separator);
      data[i] = inputString.substring(0, index).toInt();
      inputString = inputString.substring(index + 1);
    }

    uint8_t nuevo_grados_motor1 = data[0];
    uint8_t nuevo_grados_motor2 = data[1];
    
    int8_t diferencia_motor1 = nuevo_grados_motor1 - grados_motor1;
    int8_t diferencia_motor2 = nuevo_grados_motor2 - grados_motor2;


    if (diferencia_motor1 > 0)
    {
      sentido_motor1 = 1;
      nuevo_grados_motor1 = diferencia_motor1;
    }
    else if (diferencia_motor1 < 0)
    {
      sentido_motor1 = 2;
      diferencia_motor1 = -diferencia_motor1;
      nuevo_grados_motor1 = diferencia_motor1;  // Ajustar el nuevo ángulo para evitar errores acumulativos
    }
    
    if (diferencia_motor2 > 0)
    {
      sentido_motor2 = 1;
      nuevo_grados_motor2 = diferencia_motor2;
    }
    else if (diferencia_motor2 < 0)
    {
      sentido_motor2 = 2;
      diferencia_motor2 = -diferencia_motor2;
      nuevo_grados_motor2 = diferencia_motor2;  // Ajustar el nuevo ángulo para evitar errores acumulativos
    }

    grados_motor1 = nuevo_grados_motor1;
    grados_motor2 = nuevo_grados_motor2;
    
    inputString = "";
    stringComplete = false;
  }
  
  pasos_motor1 = (grados_motor1 * 512) / 360;
  pasos_motor2 = (grados_motor2 * 512) / 360;

  if (sentido_motor1 == 2)
  {
    Serial.println("Motor 1 - Sentido: antihorario,Grados: " + String(grados_motor1));
    adelante(pasos_motor1, velocidad, 1);
    sentido_motor1 = 0;

  }
  else if (sentido_motor1 == 1)
  {
    Serial.println("Motor 1 - Sentido: horario, Grados: " + String(grados_motor1));
    atras(pasos_motor1, velocidad, 1);
    sentido_motor1 = 0;

  }
  
  if (sentido_motor2 == 2)
  {
    Serial.println("Motor 2 - Sentido: antihorario, Grados: " + String(grados_motor2));
    adelante(pasos_motor2, velocidad, 2);
    sentido_motor2 = 0;

  }
  else if (sentido_motor2 == 1)
  {
    Serial.println("Motor 2 - Sentido: horario, Grados: " + String(grados_motor2));
    atras(pasos_motor2, velocidad, 2);
    sentido_motor2 = 0;

  }

}
