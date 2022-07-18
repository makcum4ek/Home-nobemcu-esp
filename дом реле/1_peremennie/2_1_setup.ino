WiFiClient espClient;
PubSubClient client(espClient);
void setup() {
  Serial.begin(115200);
  pinMode(svetstolaPin, OUTPUT);
  pinMode(kolonkiPin, OUTPUT);
  pinMode(pcPin, OUTPUT);
  pinMode(rozetkaPin, OUTPUT);
pinMode(dverpin, INPUT_PULLUP);
  WiFi.begin(ssid, password);
  timeClient.begin();
  client.setServer(mqtt_server, mqtt_port);
  ArduinoOTA.setHostname("Dom-rele"); // Задаем имя сетевого порта
  ArduinoOTA.setPassword((const char *)"1234"); // Задаем пароль доступа для удаленной прошивки
  ArduinoOTA.begin(); // Инициализируем OTA
}
void loop() {
  if (!client.connected())reconnect();
  client.loop();
  refreshData();
  VipolnenieOperatcii();
  Voidsdvigreg();
}
