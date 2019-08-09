#include <ESP8266WiFi.h>
#include <SPI.h>
#include <MFRC522.h>
WiFiClient client;
int port=8888;
char host[]="172.20.10.2";
charssid[]="hotspot name";
char pass[]="password";
#define RST_PIN D3 // Configurable, see typical pin layout above
#define SS_PIN D4 // Configurable, see typical pin layout above
MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance
void setup() {
Serial.begin(115200); // Initialize serial communications with the PC
SPI.begin(); // Init SPI bus
 mfrc522.PCD_Init(); // Init MFRC522
WiFi.mode(WIFI_STA);
WiFi.begin(ssid,pass);
Serial.print("Connecting");
while (WiFi.status() != WL_CONNECTED)
 {
delay(500);
Serial.print(".");
 }
 Serial.println();
 Serial.print("Connected, IP address: ");
Serial.println(WiFi.localIP());
Serial.println("Scan PICC to see UID, SAK, type, and data blocks...");
}
void loop()
{
 //Show UID on serial monitor
 String url="/";
 String content= "";
 //static int count=1;
 // Look for new cards
for(int j=1;j<=3;j++)
 {
Serial.println("Waiting for a card...");
delay(8000);
if( ! mfrc522.PICC_IsNewCardPresent())
 {
return;
 }
if( ! mfrc522.PICC_ReadCardSerial())
 {
Serial.print("Unable to read.Try Again...");
return; }
byte letter;
Serial.print("UID tag :");
for (byte i = 0; i< mfrc522.uid.size; i++)
 {
Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
Serial.print(mfrc522.uid.uidByte[i], HEX);
content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : ""));
content.concat(String(mfrc522.uid.uidByte[i], HEX));
 }
Serial.println();
content.toUpperCase();
 //Serial.println(content);
 //Serial.println(content.length());
if(content.length()<26)
 {
content.concat(":");
 }
 //Serial.println(content);
if(content.length()==26)
url+=content;
 //Serial.println(url);
if(!client.connect(host,port))
 {
Serial.println("Connection to server failed");
delay(5000);
return;
 }
 client.print("GET "+url+" HTTP/1.1/r/nHost:"+host+"\r\nConnection: keep-alive\r\n\r\n");
delay(1000);
while(client.available())
 {
 String line = client.readStringUntil('\n');
Serial.println(line);
 }}}
