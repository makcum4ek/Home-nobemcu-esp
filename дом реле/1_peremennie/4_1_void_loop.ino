void VipolnenieOperatcii() {
  ArduinoOTA.handle(); // Всегда готовы к прошивке
  ////////////////////////////////////////////////////////////////
  timeClient.update();
  unsigned long epochTime = timeClient.getEpochTime();
  currentHour = timeClient.getHours();
  currentMinute = timeClient.getMinutes();
  currentSecond = timeClient.getSeconds();
  String weekDay = weekDays[timeClient.getDay()];
  struct tm *ptm = gmtime ((time_t *)&epochTime);
  int monthDay = ptm->tm_mday;
  int currentMonth = ptm->tm_mon + 1;
  String currentMonthName = months[currentMonth - 1];
  int currentYear = ptm->tm_year + 1900;
  currentDate = String(currentYear) + "-" + String(currentMonth) + "-" + String(monthDay);
  formattedTime = timeClient.getFormattedTime();
  if (currentMinute == 0) {
    if (currentSecond == 0) {
      int chk = DHT.read(DHT11_PIN);
    client.publish("dom/vlagy", String(DHT.humidity).c_str());
    client.publish("dom/temperature", String(DHT.temperature).c_str());
    
      }
  }
  if (millis() - last_time10 > 500) {
    last_time10 = millis();
    koncevik = digitalRead(dverpin);
  }

  /////////////////////////////////////////////////////
}
//////////////////////////////////////////////////////////////////////////////////////////////////
