#include <WiFi.h>
#include <esp_wifi.h>
#include "types.h"
#include "web_interface.h"
#include "deauth.h"
#include "definitions.h"
#define buzzerPin 26
int melody[] = {
  659, 587, 370, 415, 554, 494, 294, 330,
  494, 440, 277, 330, 440
};

int duration[] = {
  125, 125, 250, 250, 250, 250, 250, 250,
  250, 250, 250, 250, 250
};

int len = sizeof(melody) / sizeof(melody[0]);
void playTone(int freq, int duration) {
  if (freq == 0) {        // nghỉ (rest)
    delay(duration);
    return;
  }
  ledcSetup(0, freq, 10);   // channel 0, freq Hz, 10-bit
  ledcAttachPin(buzzerPin, 0);
  ledcWriteTone(0, freq);
  delay(duration);
  ledcWriteTone(0, 0);      // tắt
}

void playMelody(int* melody, int* duration, int len) {
  for (int i = 0; i < len; i++) {
    playTone(melody[i], duration[i]);
    delay(duration[i] * 0.3);   // nghỉ giữa các nốt
  }
  ledcDetachPin(buzzerPin);
}

int curr_channel = 1;

void setup() {
  playMelody(melody, duration, len);
#ifdef SERIAL_DEBUG
  Serial.begin(115200);
#endif
#ifdef LED
  pinMode(LED, OUTPUT);
#endif

  WiFi.mode(WIFI_MODE_AP);
  WiFi.softAP(AP_SSID, AP_PASS);

  start_web_interface();
}

void loop() {
  if (deauth_type == DEAUTH_TYPE_ALL) {
    if (curr_channel > CHANNEL_MAX) curr_channel = 1;
    esp_wifi_set_channel(curr_channel, WIFI_SECOND_CHAN_NONE);
    curr_channel++;
    delay(10);
  } else {
    web_interface_handle_client();
  }
}
