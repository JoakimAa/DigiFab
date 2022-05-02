

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int thresholdUp = 400;
int thresholdDown = 250;

int solenoid = 6;
int soilPin = A0;
int soilPower = 7; 
int wateringDelay = 10;

void setup()
{
    lcd.begin(16, 2); 
    delay(500);      

    pinMode(soilPower, OUTPUT);  
    pinMode(solenoid, OUTPUT);    
    digitalWrite(soilPower, LOW); 
}

void loop()
{
   
    String DisplayWords;
    int sensorValue;
    sensorValue = readSoil();

    lcd.print("                ");
    lcd.print("                ");

    lcd.setCursor(0, 1);

    lcd.print("Moisture: ");
    lcd.print(sensorValue); 


    if (sensorValue <= thresholdDown)
    {
        digitalWrite(solenoid, HIGH);
        DisplayWords = "Watering... ";
        for (int i = 10; i > 0; i--)
        {
            lcd.setCursor(0, 0);
            lcd.print(DisplayWords + (i) + " ");
            delay(1000);
        }

        lcd.setCursor(0, 0);
        lcd.print("                 ");
        lcd.setCursor(0, 0);
        lcd.print("Done!");

    }
    else if (sensorValue >= thresholdUp)
    {

        lcd.setCursor(0, 0);

        DisplayWords = "Wet, Leave it!";
        lcd.print(DisplayWords);
    }
    else
    {
  
        lcd.setCursor(0, 0);
        lcd.print(DisplayWords);
    }

    delay(5000);
    digitalWrite(solenoid, LOW);
}

int readSoil()
{
    digitalWrite(soilPower, HIGH);
    delay(10);                    
    int val = analogRead(soilPin);
    digitalWrite(soilPower, LOW); 
    return val;                   
}
