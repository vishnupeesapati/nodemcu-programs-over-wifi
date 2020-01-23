

#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

const char* ssid = "pizza";
const char* password = "1234pizza";

const char* host = "175.101.12.206";
const int httpsPort = 80;




void setup() {
  pinMode(D0,INPUT_PULLUP);
  pinMode(D1,INPUT_PULLUP);
  pinMode(D3,INPUT_PULLUP);
  pinMode(D4,INPUT_PULLUP);
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


 
}
char message[]= "GET /setsensor.php?login=Vishnu1&password=Vishnu1&data=        p\r\nHost:175.101.12.206\r\nUser-Agent:Arduino\r\nConnection: close\r\n\r\n";
char data[100];
int pcount=0,spcount=0;
char choice;
void loop() {

  if(digitalRead(D0)==0)
  {
    pcount++;
  }
  else  if(digitalRead(D1)==0)
  {
    spcount++;
  }
  
  else if(digtalRead(D2)==0)
  {
   WiFiClient client;
  Serial.print("connecting to ");
  Serial.println(host);
  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    delay(500);
  message[55]='$';
  message[56]='H';
  message[57]='$';
  message[58]=48  + p/10;
  message[59]=48  + p%10;
  message[60]='$';
  message[61]=48  + sp/10;
  message[62]=48  + sp%10;
  message[63]=48  + '$';
  }
  }
  
}
//////////////////////////////
  
}
