
#include <LWiFi.h>
#include <PubSubClient.h>

int buzzerPin=2;

char ssid[] = "MakeNTU2019-A-2.4G";
char password[] = "lazy_tech";
char mqtt_server[] = "10.10.2.88";
char sub_topic[] = "makereal_button";
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
//    pinMode(buzzerPin, OUTPUT);
    setup_wifi();
    client.setServer(mqtt_server, 1883);
    client.setCallback(callback);

//Botton
    pinMode(2, INPUT);
    Serial.begin(9600);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  
  if (HIGH == digitalRead(2)) {
    Serial.println("press");
    digitalWrite(LED_BUILTIN, HIGH);
    client.publish(sub_topic, "1");
    delay(1000);
    
  } else {
    Serial.println("release");
    digitalWrite(LED_BUILTIN, LOW);
    client.publish(sub_topic, "0");
    delay(1000);
  }

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
    digitalWrite(LED_BUILTIN, HIGH);
  }else if((char)payload[0] == '0'){
    digitalWrite(LED_BUILTIN, LOW);
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

