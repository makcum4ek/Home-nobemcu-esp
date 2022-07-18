void refreshData() {
  ///////////////////отключение//////////////////////////////////////////////////////////////////////////
  if (otkly4itvse == 1) {
    client.publish("dom/rozetka", "0");
    client.publish("dom/lustra", "0");
    client.publish("dom/svetstola", "0");
    client.publish("dom/kolonki", "0");

    otkly4itvse = 0;
  }
  /////////////////////отправка данных с контролера////////////////////////////////////////////////////////////////////////
  if (checkstat == 1) {
    checkstat = 0;
    client.publish("dom/svetstolaotpravka", String(svetstola).c_str());
    client.publish("dom/kolonkiotpravka", String(kolonki).c_str());
    client.publish("dom/rozetkaotpravka", String(rozetka).c_str());

  }
  if (kk == 0) {
    if (koncevik == 0) {
      client.publish("dom/dat4ikdveri", "1");
      kk = 1;
    }
  }
  if (kk == 1) {
    if (koncevik == 1) {
      last_time5 = millis();
      client.publish("dom/dat4ikdveri", "0");
      kk = 0;
    }
  }
  /////////////////////Таймер1/////////////////////////////////////////////////////////////
  if (timer1 >= 1) {
    if (controltimer1 == 0) {
      last_time1 = millis();
      controltimer1 = 1;
    }
    if (millis() - last_time1 > timer1) {
      if (pribor1 == "1") {
        client.publish("dom/lustra", "0");
      }
      if (pribor1 == "2") {
        client.publish("dom/svetstola", "0");
      }
      if (pribor1 == "3") {
        client.publish("dom/kolonki", "0");
      }
      if (pribor1 == "4") {
        client.publish("dom/rozetka", "0");
      }
      if (pribor1 == "5") {
        client.publish("dom/zamok", "0");
      }
      if (pribor1 == "6") {
        client.publish("dom/zamok", "1");
      }
      if (pribor1 == "7") {
        client.publish("dom/lustra", "1");
      }
      if (pribor1 == "8") {
        client.publish("dom/svetstola", "1");
      }
      if (pribor1 == "9") {
        client.publish("dom/kolonki", "1");
      }
      if (pribor1 == "10") {
        client.publish("dom/rozetka", "1");
      }
      client.publish("dom/timer1", "0");
    }
  }
  /////////////////////Таймер2//////////////////////////////////////////////
  if (timer2 >= 1) {
    if (controltimer2 == 0) {
      last_time2 = millis();
      controltimer2 = 1;
    }
    if (millis() - last_time2 > timer2) {
      if (pribor2 == "1") {
        client.publish("dom/lustra", "0");
      }
      if (pribor2 == "2") {
        client.publish("dom/svetstola", "0");
      }
      if (pribor2 == "3") {
        client.publish("dom/kolonki", "0");
      }
      if (pribor2 == "4") {
        client.publish("dom/rozetka", "0");
      }
      if (pribor2 == "5") {
        client.publish("dom/zamok", "0");
      }
      if (pribor2 == "6") {
        client.publish("dom/zamok", "1");
      }
      if (pribor2 == "7") {
        client.publish("dom/lustra", "1");
      }
      if (pribor2 == "8") {
        client.publish("dom/svetstola", "1");
      }
      if (pribor2 == "9") {
        client.publish("dom/kolonki", "1");
      }
      if (pribor2 == "10") {
        client.publish("dom/rozetka", "1");
      }
      client.publish("dom/timer2", "0");
    }
  }
  //////////////////////////////////////////////
}
