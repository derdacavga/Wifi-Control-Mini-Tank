# WiFi Controlled Mini Tank

## About the Project
This project is a WiFi controlled mini tank. It is fully 3D printable and does not require a special PCB.

## Video Tutorial
Build your own following the step-by-step guide!

[![Watch the tutorial](https://img.youtube.com/vi/2wIOvS5U6aM/0.jpg)](https://www.youtube.com/watch?v=2wIOvS5U6aM)  https://youtu.be/2wIOvS5U6aM

## Repository Structure
When you download and extract the repository, you will find two different folders.
* One folder is for LED control.
* The other folder contains the main code.

## Components List
* Wemos D1 mini clone.
* OLED Display.
* 2 piece addressable LED. Ws2812b
* TP4056 Charger board.
* Li-po battery.
* Slide Switch.  10.5*5.5
* Micro Servo (broken).
* Servo horn set.
* Pin header.
* Heat Shrink tube.
* Proto board.
* M2 screws. 12 piece 6mm, 2 piece 4mm
* M3 Screws. 2 piece 12mm
* DRV8833 H bridge motor driver.
* 3D printed parts. Link: https://cults3d.com/en/3d-model/game/rc-tank-mini-car-arduino-based
* Some wire.

## Hardware Notes
### Motor Modification
Instead of using a 360-degree endless servo which would require a voltage booster (since servos operate between 4.8 - 6.0 volts), this project uses a broken servo. The broken servo is used only for its geared reduction parts. The broken circuit boards are extracted, and a 3.7 volt battery is enough to drive the motor directly.
* Solder two wires directly to the motor pins.
* Solder female pin headers to make it easier to use in the project.

### Motor Driver
The DRV8833 H bridge motor driver is a perfect choice for this 1S battery setup.

## Software Setup
### Arduino IDE
* ]Download the latest version of the Arduino IDE . This project used version 2.3.8 .
* Open the main code .

### ESP8266 Board Installation
* You need ESP8266 tools to compile the code .
* Open preferences in Arduino IDE, paste the copied link, click OK, and close .
* Go to the board manager on the left side of the IDE .
* Type "esp8266" in the search bar, find it, and install .

### External Libraries
 You need to install three different external libraries from the library section[cite: 26, 27]:
* Adafruit GFX .
* Adafruit SSD1306 .
* Adafruit neopixel .

### Uploading the Code
* Go to tools and select "Wemos d1 mini clone" .
* Select the right COM port .
* Do not touch the other settings .
* Click the upload button and ensure everything is working properly once done .

## Assembly and 3D Printing
* The 3D models are published on the Cults3D page .
* When assembling, make sure not to tighten the wheels too much .
* The wheels must turn freely .

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
