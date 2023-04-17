#ifndef Configuration_h
#define Configuration_h

/*
Файл настройки доски (указать все важные настройки и параментры используя дерективы припроцессора)
*/

/*..............................................................LOCAL................................................................*/
#ifndef SSID

#define SSID                                                               "CHESS-BOARD_CONFIG"             //Название точки доступа
#define PASS                                                               "admin111"                       //Пароль
#define IPADRESS                                                           192.168.0.1                      //Айпи нашего сервера в локальной сети(точка доступа)
#endif

#ifndef APSSID

#define APSSID                                                             "AndroidA78B7"
#define APPSK                                                              "fnfn7206"

#define APSSID1                                                            "Redmi9"
#define APPSK1                                                             ""

#define APSSID2                                                            "TP-Link_7B76"
#define APPSK2                                                             "78217942"

//Нужно реализовать подключение к нескольким сетям не подключился к одной за timeout  подключается к следующей

#define TIMERESPONSE                                                       1
#define TIMEOUT                                                            15              // в секундах
#define INDICATOR_OF_NETWORK_STATUS                                        2
#endif

#define NUM_LEDS                                                           67
#define matrixLed                                                          5                              

/*............................................Update firmware into wifi configuration...............................................*/

#define OTAUSER                                                           "admin"
#define OTAPASSWORD                                                       "admin"
#define OTAPATH                                                           "/firmware"
#define SUBFOLDERDATA                                                     "/data"
#define SERVERPORT                                                        80

/*.............................................................sd card...............................................................*/

#define CDPIN                                                             4
#define CONFFILE                                                          "config.txt"
/*..........................................................time settings............................................................*/

//ну и так далее...

#endif