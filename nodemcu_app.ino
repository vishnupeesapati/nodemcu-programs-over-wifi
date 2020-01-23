/*
 *  HTTP over TLS (HTTPS) example sketch
 *
 *  This example demonstrates how to use
 *  WiFiClientSecure class to access HTTPS API.
 *  We fetch and display the status of
 *  esp8266/Arduino project continuous integration
 *  build.
 *
 *  Limitations:
 *    only RSA certificates
 *    no support of Perfect Forward Secrecy (PFS)
 *    TLSv1.2 is supported since version 2.4.0-rc1
 *
 *  Created by Ivan Grokhotkov, 2015.
 *  This example is in public domain.
 */

//#include <ESP8266WiFi.h>
//#include <WiFiClientSecure.h>

const char* ssid = "Ananda-nilayam";
const char* password = "gayathri#9";

const char* host = "175.101.12.206";
const int httpsPort = 80;

//const char* host = "";
//const int httpsPort = ;

// Use web browser to view and copy
// SHA1 fingerprint of the certificate
int tp=D6,ep=D7;
int duration;
long int time()
{
  digitalWrite(tp,LOW);
  delay(2);
  digitalWrite(tp,HIGH);
  delay(2);
  digitalWrite(tp,LOW);
  duration = pulseIn(ep,HIGH,3000);
  if(duration==0)
  duration=3000;
  return duration;
}
long int range()
{
  
  return(time()/29/2);
}

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.print("connecting to ");
  Serial.println(ssid);
//  WiFi.mode(WIFI_STA);
 // WiFi.begin(ssid, password);
 // while (WiFi.status() != WL_CONNECTED) {
 //   delay(500);
 //   Serial.print(".");
 // }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
 // Serial.println(WiFi.localIP());
  pinMode(13,INPUT_PULLUP);
  pinMode(tp,OUTPUT);
  pinMode(ep,INPUT);

  // Use WiFiClientSecure class to create TLS connection
 
}
char data[100];
int count;
char choice;
void loop() {
  // WiFiClient client;
 // Serial.print("connecting to ");
 // Serial.println(host);
 // if (!client.connect(host, httpsPort)) {
 //   Serial.println("connection failed");
 //   delay(500);
 // }


  
  char* url = "GET /setsensor.php?login=Vishnu1&password=Vishnu1&data=p\r\nHost:175.101.12.206\r\nUser-Agent:Arduino\r\nConnection: close\r\n\r\n";
  url[55] = 48 + range()/10;
  if(url[55] == '5')
  url[55] = '!';
  Serial.print("requesting URL: ");
  Serial.println(url);
 // Serial.println("request sent");
 // client.print(url);

delay(2000);  


//Serial.write(data);

//////////////////////////////
  
}
