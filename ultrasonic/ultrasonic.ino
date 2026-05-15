#include <LiquidCrystal.h>
#include <Ultrasonic.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 

Ultrasonic ultrasonic(8, 9); 

int distancia;

void setup() {

  Serial.begin(9600);
  
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Sensor Ativo");
  
  delay(1500);
  lcd.clear();
}

void loop() {
  // Leitura da distância
  distancia = ultrasonic.read();
  
  // Exibe no monitor serial
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Exibe no LCD
  lcd.setCursor(0, 0);
  lcd.print("Distancia:");
  
  lcd.setCursor(0, 1);
  // Limpa a linha antes de escrever o novo valor para não "encavalar" números
  lcd.print("      "); 
  lcd.setCursor(0, 1);
  lcd.print(distancia);
  lcd.print(" cm");

  delay(250); // Delay menor para a leitura parecer mais "em tempo real"
}