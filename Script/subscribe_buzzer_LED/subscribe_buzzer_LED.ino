
#include <LWiFi.h>
#include <PubSubClient.h>

char ssid[] = "MakeNTU2019-A-2.4G";
char password[] = "lazy_tech";
char mqtt_server[] = "10.10.2.88";
char sub_topic[] = "makereal_cube";
char client_Id[] = "linkit-7697";
 
int status = WL_IDLE_STATUS;

WiFiClient mtclient;     
PubSubClient client(mtclient);
long lastMsg = 0;
char msg[50];
int value = 0;

void setup() {
    //Initialize serial and wait for port to open:
    Serial.begin(9600);
    //while (!Serial) {
         // wait for serial port to connect. Needed for native USB port only
    //}
    pinMode(2, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    setup_wifi();
    client.setServer(mqtt_server, 1883);
    client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

}


void printWifiStatus() {                     //print Wifi status
    // print the SSID of the network you're attached to:
    Serial.print("SSID: ");
    Serial.println(WiFi.SSID());

    // print your WiFi shield's IP address:
    IPAddress ip = WiFi.localIP();
    Serial.print("IP Address: ");
    Serial.println(ip);

    // print the received signal strength:
    long rssi = WiFi.RSSI();
    Serial.print("signal strength (RSSI):");
    Serial.print(rssi);
    Serial.println(" dBm");
}

void setup_wifi() {                       //setup Wifi
   // attempt to connect to Wifi network:
   Serial.print("Attempting to connect to SSID: ");
   Serial.println(ssid);
   WiFi.begin(ssid, password);
   while (WiFi.status() != WL_CONNECTED) {
     delay(500);
     Serial.print(".");
    }
    randomSeed(micros());
    Serial.println("Connected to wifi");
    printWifiStatus();
}

void callback(char* topic, byte* payload, unsigned int length) {   //MQTT sub
  Serial.print("Input Message arrived [");
  Serial.print(sub_topic);
  Serial.print("] ");
  Serial.print((char)payload[0]);
  if((char)payload[0] == '1'){
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    //if subscribe, biiii
    tone(2, 440);
    delay(1000);
        
  }else if((char)payload[0] == '0'){
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    //if did not subscribe, bibi
    tone(2, 880);
    delay(250);
    tone(2, 440);
    delay(250);
    tone(2, 880);
    delay(250);
    tone(2, 440);
    delay(250);
        
  }else{
    Serial.print("value error");
  }
  Serial.println();
}

void reconnect() {  //reconnect MQTT
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = client_Id;
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      // ... and resubscribe
      client.subscribe(sub_topic);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
