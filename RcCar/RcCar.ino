#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_NeoPixel.h>

const char* ssid = "DsnRc";
const char* password = "12345678";

#define IN1 D3  // Left Motor A
#define IN2 D4  // Left Motor B
#define IN3 D7  // Right Motor A
#define IN4 D6  // Right Motor B
#define LED_PIN D5

ESP8266WebServer server(80);
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Adafruit_NeoPixel strip(2, LED_PIN, NEO_GRB + NEO_KHZ800);

enum CarState { STOPPED,
                FORWARD,
                BACKWARD,
                LEFT,
                RIGHT };
CarState currentState = STOPPED;

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no">
  <title>WiFi Car Controller</title>
  <style>
    body { font-family: Arial; text-align: center; background-color: #222; color: white; margin-top: 50px;}
    .btn { background-color: #4CAF50; border: none; color: white; padding: 25px 40px; font-size: 24px; border-radius: 10px; margin: 10px; user-select: none; touch-action: manipulation;}
    .btn:active { background-color: #3e8e41; }
    .row { display: flex; justify-content: center; }
  </style>
</head>
<body>
  <h1>Car Control</h1>
  <div class="row"><button class="btn" ontouchstart="cmd('forward')" ontouchend="cmd('stop')" onmousedown="cmd('forward')" onmouseup="cmd('stop')">Forward</button></div>
  <div class="row">
    <button class="btn" ontouchstart="cmd('left')" ontouchend="cmd('stop')" onmousedown="cmd('left')" onmouseup="cmd('stop')">Left</button>
    <button class="btn" ontouchstart="cmd('right')" ontouchend="cmd('stop')" onmousedown="cmd('right')" onmouseup="cmd('stop')">Right</button>
  </div>
  <div class="row"><button class="btn" ontouchstart="cmd('backward')" ontouchend="cmd('stop')" onmousedown="cmd('backward')" onmouseup="cmd('stop')">Backward</button></div>
  <script>
    function cmd(action) { fetch('/' + action); }
  </script>
</body>
</html>
)rawliteral";

void setup() {
  Serial.begin(115200);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  stopMotors();

  strip.begin();
  strip.show();

  Wire.begin(D2, D1);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
  }
  display.clearDisplay();
  display.setTextColor(WHITE);

  WiFi.softAP(ssid, password);

  Serial.println("");
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", []() {
    server.send(200, "text/html", index_html);
  });
  server.on("/forward", []() {
    setCarState(FORWARD);
    server.send(200, "text/plain", "ok");
  });
  server.on("/backward", []() {
    setCarState(BACKWARD);
    server.send(200, "text/plain", "ok");
  });
  server.on("/left", []() {
    setCarState(LEFT);
    server.send(200, "text/plain", "ok");
  });
  server.on("/right", []() {
    setCarState(RIGHT);
    server.send(200, "text/plain", "ok");
  });
  server.on("/stop", []() {
    setCarState(STOPPED);
    server.send(200, "text/plain", "ok");
  });

  server.begin();
  updateFaceAndLEDs();
}

void loop() {
  server.handleClient();
}

void setCarState(CarState newState) {
  if (currentState == newState) return;
  currentState = newState;

  switch (currentState) {
    case FORWARD:
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      break;
    case BACKWARD:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      break;
    case LEFT:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      break;
    case RIGHT:
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      break;
    case STOPPED:
      stopMotors();
      break;
  }
  updateFaceAndLEDs();
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void updateFaceAndLEDs() {
  display.clearDisplay();

  switch (currentState) {
    case STOPPED:
      display.fillCircle(35, 25, 8, WHITE);
      display.fillCircle(93, 25, 8, WHITE);
      display.drawLine(40, 50, 88, 50, WHITE);
      setLEDs(0, 255, 0);
      break;

    case FORWARD:
      display.fillCircle(35, 25, 10, WHITE);
      display.fillCircle(93, 25, 10, WHITE);
      display.fillCircle(64, 45, 8, WHITE);
      setLEDs(0, 0, 255);
      break;

    case BACKWARD:
      display.drawCircle(35, 25, 10, WHITE);
      display.drawCircle(93, 25, 10, WHITE);
      display.drawCircle(64, 45, 12, WHITE);
      setLEDs(255, 0, 0);
      break;

    case LEFT:
      display.fillCircle(25, 25, 8, WHITE);
      display.fillCircle(83, 25, 8, WHITE);
      display.drawLine(40, 50, 88, 45, WHITE);
      setLEDs(255, 255, 0);
      break;

    case RIGHT:
      display.fillCircle(45, 25, 8, WHITE);
      display.fillCircle(103, 25, 8, WHITE);
      display.drawLine(40, 45, 88, 50, WHITE);
      setLEDs(255, 255, 0);
      break;
  }
  display.display();
}

void setLEDs(int r, int g, int b) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(r, g, b));
  }
  strip.show();
}