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

#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

const char* ssid = "ravi";
const char* password = "ravi1234";

const char* host = "175.101.12.206";
const int httpsPort = 80;

//const char* host = "";
//const int httpsPort = ;

// Use web browser to view and copy
// SHA1 fingerprint of the certificate


void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.print("connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  pinMode(13,OUTPUT);

  // Use WiFiClientSecure class to create TLS connection
 
}
char data[100];
int count;
char choice;
void loop() {
   WiFiClient client;
  Serial.print("connecting to ");
  Serial.println(host);
  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    delay(500);
  }


  //get request to the server
  char* url = "";
  Serial.print("requesting URL: ");
  Serial.println(url);
  Serial.println("request sent");
  client.print(url);

delay(500);  
while(client.available())
{
data[count++] = client.read();
//Serial.println(data[count]);

}

//Serial.write(data);
count=0;

while(data[count++]!='$');
choice = data[count+2];

Serial.print("choice = ");
Serial.println(choice);

if(choice=='1')
digitalWrite(13,HIGH);
else if(choice == '0')
digitalWrite(13,LOW);
else if(choice=='3')
digitalWrite(13,HIGH);
else if(choice == '2')
digitalWrite(13,LOW);
delay(2000);

//////////////////////////////
  
}
