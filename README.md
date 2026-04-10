# WiFi Controlled Mini Tank

## About the Project
[cite_start]This project is a WiFi controlled mini tank[cite: 2]. [cite_start]It is fully 3D printable and does not require a special PCB[cite: 2].

## Video Tutorial
Build your own following the step-by-step guide!

[![Watch the tutorial](https://img.youtube.com/vi/2wIOvS5U6aM/0.jpg)](https://www.youtube.com/watch?v=2wIOvS5U6aM)  https://youtu.be/2wIOvS5U6aM

## Repository Structure
[cite_start]When you download and extract the repository, you will find two different folders[cite: 18, 19]:
* [cite_start]One folder is for LED control[cite: 19].
* [cite_start]The other folder contains the main code[cite: 19].

## Components List
* [cite_start]Wemos D1 mini clone[cite: 5].
* [cite_start]OLED Display[cite: 6].
* [cite_start]2 piece addressable LED[cite: 6].
* [cite_start]TP4056 Charger board[cite: 6].
* [cite_start]Li-po battery[cite: 6].
* [cite_start]Slide Switch[cite: 6].
* [cite_start]Micro Servo (broken)[cite: 6, 7].
* [cite_start]Servo horn set[cite: 7].
* [cite_start]Pin header[cite: 7].
* [cite_start]Heat Shrink tube[cite: 7].
* [cite_start]Proto board[cite: 8].
* [cite_start]M2 screws[cite: 8].
* [cite_start]DRV8833 H bridge motor driver[cite: 8].
* [cite_start]3D printed parts[cite: 8].
* [cite_start]Some wire[cite: 9].

## Hardware Notes
### Motor Modification
[cite_start]Instead of using a 360-degree endless servo which would require a voltage booster (since servos operate between 4.8 - 6.0 volts), this project uses a broken servo[cite: 10, 11]. [cite_start]The broken servo is used only for its geared reduction parts[cite: 12]. [cite_start]The broken circuit boards are extracted, and a 3.7 volt battery is enough to drive the motor directly[cite: 12].
* [cite_start]Solder two wires directly to the motor pins[cite: 13].
* [cite_start]Solder female pin headers to make it easier to use in the project[cite: 13, 14].

### Motor Driver
[cite_start]The DRV8833 H bridge motor driver is a perfect choice for this 1S battery setup[cite: 8].

## Software Setup
### Arduino IDE
* [cite_start]Download the latest version of the Arduino IDE[cite: 20]. [cite_start]This project used version 2.3.8[cite: 21].
* [cite_start]Open the main code[cite: 22].

### ESP8266 Board Installation
* [cite_start]You need ESP8266 tools to compile the code[cite: 22].
* [cite_start]Open preferences in Arduino IDE, paste the copied link, click OK, and close[cite: 24].
* [cite_start]Go to the board manager on the left side of the IDE[cite: 25].
* [cite_start]Type "esp8266" in the search bar, find it, and install[cite: 25].

### External Libraries
[cite_start]You need to install three different external libraries from the library section[cite: 26, 27]:
* [cite_start]Adafruit GFX[cite: 28].
* [cite_start]Adafruit SSD1306[cite: 28].
* [cite_start]Adafruit neopixel[cite: 28].

### Uploading the Code
* [cite_start]Go to tools and select "Wemos d1 mini clone"[cite: 29].
* [cite_start]Select the right COM port[cite: 29].
* [cite_start]Do not touch the other settings[cite: 29].
* [cite_start]Click the upload button and ensure everything is working properly once done[cite: 30].

## Assembly and 3D Printing
* [cite_start]The 3D models are published on the Cults3D page[cite: 33].
* [cite_start]When assembling, make sure not to tighten the wheels too much[cite: 35].
* [cite_start]The wheels must turn freely[cite: 35].

---

## 🤝 Support

If you found this project helpful, please consider:
* **Subscribing** to the YouTube Channel.
* Giving the video a **Like**.
* Starring this GitHub Repository!

* **YouTube:** [https://www.youtube.com/@DsnIndustries/videos]
* **Patreon:** [https://www.patreon.com/c/dsnIndustries]

Happy Making!

## Games
* **Maze Escape:** https://play.google.com/store/apps/details?id=com.DsnMechanics.MazeEscape
* **Air Hockey:** https://play.google.com/store/apps/details?id=com.DsnMechanics.AirHockey
* **Click Challenge:** https://play.google.com/store/apps/details?id=com.DsNMechanics.ClickChallenge
* **Flying Triangels:** https://play.google.com/store/apps/details?id=com.DsnMechanics.Triangle
* **SkyScrapper:** https://play.google.com/store/apps/details?id=com.DsnMechanics.SkyScraper
