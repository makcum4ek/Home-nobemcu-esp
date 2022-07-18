void callback(char* topic, byte* payload, unsigned int length) {
  String data_pay;
  for (int i = 0; i < length; i++) {
    data_pay += String((char)payload[i]);
  }
  kolsms++;
  if (!SD.begin(CSpin)) {
    SD.begin(CSpin);
    Serial.println("Карта не подключена");
  }
  else {
    File file = SD.open("/data.txt", FILE_WRITE);
    if (file.print(kolsms)) {
      file.print("   ");
      file.print(currentDate);
      file.print("   ");
      file.print(formattedTime);
      file.print("   ");
      file.print(topic);
      file.print("   ");
      file.println(data_pay);
      file.close();
    }
  else {      
    Serial.println("Файл не записан");
  }

  }

  if ( String(topic) == podpiskanasvetstola) {
    if (data_pay == "0") svetstola = 1;
    if (data_pay == "1") svetstola = 0;
    client.publish("dom/svetstolaotpravka", String(svetstola).c_str());
  }
  if ( String(topic) == podpiskanakolonki) {
    if (data_pay == "0") kolonki = 1;
    if (data_pay == "1") kolonki = 0;
    client.publish("dom/kolonkiotpravka", String(kolonki).c_str());
  }
  if ( String(topic) == podpiskanarozetka) {
    if (data_pay == "0") rozetka = 1;
    if (data_pay == "1") rozetka = 0;
    client.publish("dom/rozetkaotpravka", String(rozetka).c_str());
  }
  if ( String(topic) == podpiskanavklpc) {
    if (data_pay == "5") vklpc = 1;
  }

  
  if ( String(topic) == "dom/checkstat") {
    if (data_pay == "1") checkstat = 1;
  }
  if ( String(topic) == podpiskanatimer1) {
    timer1 = 0;
    controltimer1 = 0;
    for (int i = 0; String(i) != data_pay; i++) {
      timer1 = timer1 + 1;
    }
    timer1 = timer1 * 60000;
  }
  if ( String(topic) == podpiskanapribor1) {
    pribor1 = data_pay;
  }
  if ( String(topic) == podpiskanatimer2) {
    timer2 = 0;
    controltimer2 = 0;
    for (int i = 0; String(i) != data_pay; i++) {
      timer2 = timer2 + 1;
    }
    timer2 = timer2 * 60000;
  }
  if ( String(topic) == podpiskanapribor2) {
    pribor2 = data_pay;
  }
  if ( String(topic) == podpiskanaotkly4itvse) {
    if (data_pay == "1") otkly4itvse = 1;

  }

}
