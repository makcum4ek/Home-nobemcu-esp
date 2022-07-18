void Voidsdvigreg() {
  /////////////////////
  if (k15 == 0) {
    if (vklpc == 1) {
      last_time3 = millis();
      digitalWrite(pcPin, LOW);
      k15 = 1;
    }
  }
  if (k15 == 1) {
    if (millis() - last_time3 > 500) {
      digitalWrite(pcPin, HIGH);
      vklpc = 0;
      k15 = 0;
    }
  }

  /////////1 выход сдвигового///////////////////
  digitalWrite(svetstolaPin, svetstola);
  digitalWrite(rozetkaPin, rozetka);
  digitalWrite(kolonkiPin, kolonki);

}
