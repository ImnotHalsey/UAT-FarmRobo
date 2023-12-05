#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11);

// App to bot on 5-100ms
class infoDataProcessor {
public:
  long get_timestamp() { return 0; }
  int get_Message_ID() { return 0; }
  int get_Control_mode() { return random(0, 3); }
  int get_path_mode() { return random(0, 1); }
  int get_lights() { return random(0, 2); }
  int get_Emergency() { return random(0, 2); }
  int get_tool_type() { return random(0, 6); }};

void Option_Processor() {
  infoDataProcessor dataProcessor;  // Create an instance of the infoDataProcessor class

  if (dataProcessor.get_path_mode() == 0) {
    Serial.println("In the Tool mode");

    if (dataProcessor.get_tool_type() == 0) { // Sub Code
      Serial.println("Tool type is Furrow Blade");
      
    } else if (dataProcessor.get_tool_type() == 1) {
      Serial.println("Tool type is Tyne");
    } else if (dataProcessor.get_tool_type() == 2) {
      Serial.println("Tool type is Rotovator");
    } else if (dataProcessor.get_tool_type() == 3) {
      Serial.println("Tool type is Boom Sprayer");
    } else if (dataProcessor.get_tool_type() == 4) {
      Serial.println("Tool type is Mist Blower");
    } else if (dataProcessor.get_tool_type() == 5) {
      Serial.println("Tool type is Brushcutter");
    } else if (dataProcessor.get_tool_type() == 6) {
      Serial.println("Tool type is Trailer");
    } else {Serial.println("Tool selection out of the box");}


  } else if (dataProcessor.get_path_mode() == 1) {
    Serial.println("In the Road mode");
  } else {
    Serial.println("Out of Control");
  }
}

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  Option_Processor();
  delay(1000);
}
