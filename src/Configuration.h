#ifndef Configuration_h
#define Configuration_h

/*
Файл настройки доски (указать все важные настройки и параментры используя дерективы припроцессора)
*/

/*..............................................................LOCAL................................................................*/
extern const char htmlFile[] PROGMEM;

#ifndef SSID
#define SSID                                                               "CHESS-BOARD_CONFIG"             //Название точки доступа
#define PASS                                                               "admin111"                       //Пароль
#define IPADRESS                                                           192.168.0.1
#endif

#ifndef APSSID

#define APSSID                                                             "SHACMATIE"
#define APPSK                                                              "12345678"

#define APSSID1                                                            "Redmi 9"
#define APPSK1                                                             "11111111"

#define APSSID2                                                            "TP-Link_EFF4"
#define APPSK2                                                             "13197421"

//Нужно реализовать подключение к нескольким сетям не подключился к одной за timeout  подключается к следеующей

#define TIMEOUT                                                            5              // в секундах
#define INDICATOR_OF_NETWORK_STATUS                                        2
#endif

#define matrixLed                                                          5                              

/*............................................Update firmware into wifi configuration...............................................*/

#define OTAUSER                                                           ""
#define OTAPASSWORD                                                       ""
#define OTAPATH                                                           "/firmware"
#define SUBFOLDERDATA                                                     "/data"
#define SERVERPORT                                                        80

/*.............................................................sd card...............................................................*/

#define CDPIN                                                             4
#define CONFFILE                                                          "config.txt"
/*..........................................................time settings............................................................*/

//ну и так далее...

#endif