

//#include <ESP8266WiFi.h>
//#include <WiFiClientSecure.h>

const char* ssid = "ssid";
const char* password = "password";

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


  //get request to the cloud server
  char* url = "";
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
