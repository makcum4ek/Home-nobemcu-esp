#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ArduinoOTA.h> // Библиотека для OTA-прошивки
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <SPI.h>
#include <SD.h>
#include <dht11.h>
dht11 DHT;


WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 10800, 60000); // ТАЙМЗОНА(в сек.)  соединение 1 раз/минута
//WДень недели
String weekDays[7] = {"Воскресенье", "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота"};

//Название месяца
String months[12] = {"Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"};

// Wi-Fi
const char* ssid = "название вайфая";
const char* password = "пароль от вайфая";
// MQTT
const char* mqtt_server = "beebotte.com";
const char* mqtt_user = "получите ключь на сайте beebotte.com ";
const char* mqtt_password = "";
const int mqtt_port = 1883;
#define rozetkaPin D0
#define svetstolaPin D3
#define kolonkiPin  D4
#define pcPin D5
#define DHT11_PIN D6
#define dverpin  D7
#define CSpin  15
// ** MOSI - pin cd1
// ** MISO - pin cd0
// ** CLK - pin clk
// ** CS - pin cmd D8 15
bool k15,koncevik,kk, svetstola = 1, kolonki = 1, rozetka = 1, vklpc, checkstat;
String currentDate ;
String formattedTime;
int timeoff;
int timeon;
int odinrazstarte;

int kolsms;
int controltimer1;
int timer1;
long last_time1;
String pribor1;

int controltimer2;
int timer2;
long last_time2;
String pribor2;

boolean otkly4itvse;

long last_time3,last_time10,last_time5;
int currentHour ;
int currentMinute ;
int currentSecond;
///////////////////podpiskana/////////////////////////////////////////////////
const String podpiskanasvetstola = "dom/svetstola";
const String podpiskanakolonki = "dom/kolonki";//подписка на топики (получене инфы)/////
const String podpiskanarozetka = "dom/rozetka";
const String podpiskanavklpc = "dom/vklpc";
const String podpiskanatimer1 = "dom/timer1";
const String podpiskanapribor1 = "dom/pribor1";
const String podpiskanatimer2 = "dom/timer2";
const String podpiskanapribor2 = "dom/pribor2";
const String podpiskanaotkly4itvse = "dom/otkly4itvse";
