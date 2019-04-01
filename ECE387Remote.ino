
#include <IRremote.h>

int receiverPin = 5; 



IRrecv receiver(receiverPin);

decode_results results;

unsigned long key = 0;




void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  receiver.enableIRIn(); //enable the receiver to take inputs

  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  if(receiver.decode(&results)) {

    if(results.value == 0xFFFFFFFF) {
      results.value = key_value;
      Serial.println(results.value, HEX);

      switch(results.value) {

         case 0xFFE21D:
        Serial.println("Channel up was pressed");
        break;

        case 0xFFA25D:
        Serial.println("Channel down was pressed");
        break;

        case 0xFFE01F:
        Serial.println("Volume down was pressed");
        break;

        case 0xFFA857:
        Serial.println("Volume Up was pressed");
        break;

        case 0xFFC23D:
        Serial.println("Play/Pause was pressed");
        break;

        case 0xFF906F:
        Serial.println("Equalizer was pressed");
        break;

        case 0xFF9867:
        Serial.println("100+ was pressed");
        break;

        case 0xFFB04F:
        Serial.println("200+ was pressed");
        break;

        case 0xFF6897:
          Serial.println("0 was pressed");
          break; 
           
        case 0xFF30CF:
          Serial.println("1 was pressed");
          break;
          
          case 0xFF18E7:
          Serial.println("2 was pressed");
          break;
          
          case 0xFF7A85:
          Serial.println("3 was pressed");
          break;
          
          case 0xFF10EF:
          Serial.println("4 was pressed");
          break;
          
          case 0xFF38C7:
          Serial.println("5 was pressed");
          break;
          
          case 0xFF5AA5:
          Serial.println("6 was pressed");
          break;
          
          case 0xFF42BD:
          Serial.println("7 was pressed");
          break;
          
          case 0xFF4AB5:
          Serial.println("8 was pressed");
          break;
          
          case 0xFF52AD:
          Serial.println("9 was pressed");
          break;       
      }

  key_value = results.value;
  receiver.resume();

      
    }

    
  }

  

}
