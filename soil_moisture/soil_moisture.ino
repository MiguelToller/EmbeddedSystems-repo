#define GREEN_LED 2   // LED Azul/Verde no pino 2
#define YELLOW_LED 3  // LED Amarelo no pino 3
#define RED_LED 4     // LED Vermelho no pino 4
#define SoilSensor A0 // Sensor de umidade no pino analógico A0

// NOVOS LIMITES AJUSTADOS PARA O SEU SENSOR (Escala de ~600 a 1023)
#define DRY_THRESHOLD 900  // Acima de 900 é solo Seco (LED Vermelho)
#define WET_THRESHOLD 750  // Abaixo de 750 é solo bem Úmido (LED Azul/Verde)
                           // Entre 750 e 900 é solo Moderado (LED Amarelo)

void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);

  Serial.begin(9600); 
  delay(1000);        
}

void loop() {
  int SensorValue = analogRead(SoilSensor); 
  
  Serial.print("Soil Sensor Value: "); 
  Serial.println(SensorValue); 

  // NOVA LÓGICA DE TRÊS NÍVEIS
  if (SensorValue > 0 && SensorValue <= WET_THRESHOLD) {
    // Solo Bem Úmido (Agora aceita valores até 750)
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, LOW);
  } 
  else if (SensorValue > WET_THRESHOLD && SensorValue <= DRY_THRESHOLD) {
    // Solo Moderado (Entre 751 e 900)
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(RED_LED, LOW);
  }
  else if (SensorValue > DRY_THRESHOLD) {
    // Solo Seco (Acima de 900)
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, HIGH);
  }

  delay(1000); 
}
