// Bot To APP --> Mode 50-100ms communication
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11);
int t= 0;
void setup() {
    Serial.begin(9600);
    mySerial.begin(9600);
}

// Class for all communication processing ...
class SensorDataProcessor {
public:
    int get_timestamp() { return 1; }
    int get_Message_ID() { return random(0, 2); }
    int get_Control_mode() { return random(0, 3); }
    int get_path_mode() { return random(0, 2); }
    int get_lights() { return random(0, 2); }
    int get_Emergency() { return random(0, 2); }
    int get_tool_type() { return random(0, 7); }

    void ArrayMaker(int* results) {
        // Store results in the array
        results[0] = get_timestamp();
        results[1] = get_Message_ID();
        results[2] = get_Control_mode();
        results[3] = get_path_mode();
        results[4] = get_lights();
        results[5] = get_Emergency();
        results[6] = get_tool_type();
    }
};


class CommunicationProcessor {
public:
    void HomePage(int* results) {
        if (results[0]) { Serial.print("TimeStamp: "); Serial.println(results[0]); } else {Serial.println("Timestamp Error");}

        if (results[1] == 0) { Serial.print("MessageID 0: Having First Block code "); Serial.println(results[1]);
            if (results[2]) { Serial.print("Control Mode: "); Serial.println(results[2]); }
            if (results[3] == 1) {Serial.println("Tool Mode function activated!");} else {Serial.print("Path Mode: "); Serial.println(results[3]);}
            if (results[4]) { Serial.print("Lights: "); Serial.println(results[4]); }
            if (results[5]) { Serial.print("Emergency: "); Serial.println(results[5]); }
            if (results[6]) { Serial.print("Tool Type: "); Serial.println(results[6]); }

        } else if (results[1] == 1) { Serial.print("MessageID 1: Having Second Block code! "); Serial.println(results[1]);  // To enter into this selection can we add code to satisfy the Tool mode activated .?
        
        // Your new code is here 
            if (results[2]) { 
                if (results[2] == 1 ){ Serial.println("Selected Tool is Ferro Blade");}
                else if (results[2] == 2 ){ Serial.println("Selected Tool is Tyne");}
                else if (results[2] == 3 ){ Serial.println("Selected Tool is Rotavator");}
                else if (results[2] == 4 ){ Serial.println("Selected Tool is Boom Sprayer");}
                else if (results[2] == 5 ){ Serial.println("Selected Tool is Mist Blower");}
                else if (results[2] == 6 ){ Serial.println("Selected Tool is Brush Cutter");}
                else if (results[2] == 7 ){ Serial.println("Selected Tool is Trailer");}
                else { Serial.println("Tool selection out of the BOX");}}
            
            if (results[3]) {
              if (results[3] == 1 ){ Serial.println("Selected crop is Chilli");}
              else if (results[3] == 2 ){ Serial.println("Selected crop is Cotton");}
              else if (results[3] == 3 ){ Serial.println("Selected crop is Tobacco");}
              else if (results[3] == 4 ){ Serial.println("Selected crop is Sugarcane");}
              else { Serial.println("Selected crop is Other than the support");}}

            if (results[4]) {
              if (results[4] == 1 ){ Serial.println("Selected crop Age is 1 Month");}
              else if (results[4] == 2 ){ Serial.println("Selected crop Age is 2 Months");}
              else if (results[4] == 2 ){ Serial.println("Selected crop Age is 3 Months");}}

            if (results[5]) {
              if (results[5] == 1 ){ Serial.println("Selected Row Spacing is 18 Inches");}
              else if (results[5] == 2 ){ Serial.println("Selected Row Spacing is 20 Inches");}
              else if (results[5] == 3 ){ Serial.println("Selected Row Spacing is 23 Inches");}}
        
        }
    }
};



void loop() {
    SensorDataProcessor dataProcessor;
    CommunicationProcessor communicationProcessor;
    
    int results[7];
    dataProcessor.ArrayMaker(results);
    communicationProcessor.HomePage(results);
    
    delay(2000);
}


//  Expected output 

// case 1 

//   15:38:22.156 -> TimeStamp: 1
//   15:38:22.188 -> MessageID 1: Came to Second Block! 1

// case 2
//   15:38:26.223 -> TimeStamp: 1
//   15:38:26.223 -> MessageID 0: 0
//   15:38:26.223 -> Control Mode: 2
//   15:38:26.256 -> Tool Mode function activated!
//   15:38:26.288 -> Lights: 1
//   15:38:26.288 -> Emergency: 1
//   15:38:26.331 -> Tool Type: 4
