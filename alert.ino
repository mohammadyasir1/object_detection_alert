#define BLYNK_TEMPLATE_ID "TMPL3o6P_zxXB"
#define BLYNK_TEMPLATE_NAME "Object Detection"
#define BLYNK_AUTH_TOKEN "aXJvPmp-CcK9guH5Mgpu1KhMBA28cqH0"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define sensor D1
int val;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "TS_ONE_A2003";
char pass[] = "........";

void setup()
{
  pinMode(sensor, INPUT);
  // Debug console
  Serial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
  val=digitalRead(sensor);
  if(val==0){
    Blynk.logEvent("object_detection");
    //Blynk.email("mohammadyasirkmt@gmail.com", "Alert", "Object detected!");
    Serial.println("object detected!");
    delay(500);
  }
}
