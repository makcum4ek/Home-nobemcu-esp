void reconnect() {
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.mode(WIFI_STA);
    Serial.println("wifi");

  }
  if (WiFi.status() == WL_CONNECTED) {
    if (!client.connected()) {
      Serial.print("Attempting MQTT connection...");
      String clientId = "Komnotarele";
      if (client.connect(clientId.c_str(), mqtt_user, mqtt_password) ) {
        Serial.println("connected");
        //////////////////////////
        client.subscribe("dom/#");
        ///////////////////////////
      }
    }
    if (client.connected()) {
      ///////////////////////////////////////////////////////////////////
      if (odinrazstarte == 0) {
        client.setCallback(callback);
        odinrazstarte = 1;
        client.publish("dom/rozetkaotpravka", "0");
        client.publish("dom/svetstolaotpravka", "0");
        client.publish("dom/kolonkiotpravka", "0");
        /////////////////////////////////////////////////////////////////
      }
    }
  }
}
