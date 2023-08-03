#define trigPin_1 2
#define echoPin_1 3
#define trigPin_2 4
#define echoPin_2 5
#define sampleTime 100

// variables globales //
float *sensor_1 = (float*) malloc(sizeof (float) * 2);
float *sensor_2 = (float*) malloc(sizeof (float) * 2);
uint32_t lastTime= 0;

//declaración de funciones //
float *calcular_distancia (const uint8_t trigPin_x, const uint8_t echoPin_x, float S_x){
  float distancia=0.0;
  float duracion = 0.0;
  const float alpha =0.2;
  float *temp = (float*) malloc (sizeof (float) * 2);
  
  digitalWrite (trigPin_x, LOW) ;
  delayMicroseconds (2) ;
  digitalWrite (trigPin_x, HIGH);
  delayMicroseconds (10) ;
  digitalWrite (trigPin_x, LOW);
  duracion = pulseIn (echoPin_x, HIGH);
  distancia = (duracion * 0.034) /2;
  S_x = (alpha * distancia) + ((1.0 - alpha) * S_x) ;
  *temp = distancia;
  *(temp+1) = S_x;
  Serial.println(String(*temp));
  return temp;
}

// configuración de registros
void setup () {
  pinMode (trigPin_1, OUTPUT);
  pinMode (echoPin_1, INPUT);
  pinMode (trigPin_2, OUTPUT);
  pinMode (echoPin_2, INPUT);
  Serial.begin (9600) ;
}


// Programa principal //
void loop () {
  if(millis ()- lastTime >= sampleTime) {
    sensor_1= calcular_distancia(trigPin_1, echoPin_1, sensor_1[1]);
    sensor_2= calcular_distancia(trigPin_2, echoPin_2, sensor_2[1]);
    //Serial.println(String(sensor_1[0]) + ',' + String(sensor_1[1]) + ',' + String(sensor_2[0]) + ',' + String(sensor_2[1]));
    lastTime = millis();
    
  }
}
