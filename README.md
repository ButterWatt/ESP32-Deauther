# ESP32-Deauther
![GitHub License](https://img.shields.io/github/license/tesa-klebeband/ESP32-Deauther)
![logo](https://github.com/user-attachments/assets/4e2ac65f-1b25-4a97-822a-6a91ca71b5be)

Original repository: [tesa-klebeband/ESP32-Deauther](https://github.com/tesa-klebeband/ESP32-Deauther)

A project for the ESP32 that allows you to deauthenticate stations connected to WiFi network
# DISCLAIMER
This tool has been made for educational and testing purposes only. Any misuse or illegal activities conducted with the tool are strictly prohibited. I am **not** responsible for any consequences arising from the use of the tool, which is done at your own risk.

## Building
**I. Build with VScode and PlatformIO**

Clone [original repository](https://github.com/tesa-klebeband/ESP32-Deauther) using:

`git clone https://github.com/tesa-klebeband/ESP32-Deauther`

1) Install VScode and PlatformIO
2) Install the PlatformIO extension in vscode
3) Open the cloned folder in vscode and press the upload button

**II. Build using Github Actions**

Fork this repository (you can edit SSID and password in `include/definitions.h` for personal uses)
1) Goto `Actions` tab
2) Choose `ESP32 Full Firmware Build`
3) Run workflow and wait, it will show `esp32-flash-binaries` (it will come with 9 files)
4) Flash it with `esptool.py` (you can use other flashing tools)

**Warning: flash exact files for your ESP32 variant (like `ESP32 dev board` for example)**

## Installing directly from your Browser
Open [Tesa Klebeband's ESP32 Webflasher](https://tesa-klebeband.github.io/ESP32-Webflasher) in Chrome or Edge, select `ESP32-Deauther` and follow the listed instructions, I do not provide webflashing tool.

## Using ESP32-Deauther
The ESP32 hosts a WiFi network with the name of `ESP32-Deauther` and a password of `esp32wroom32` (if you use Webflasher). Connect to this network and type the IP of your ESP32 (typically **192.168.4.1**) into a webbrowser of a choice. You will see the following options:
* Rescan networks: Rescan and detect all WiFi networks in your area. After a successful scan, the networks are listed in the above table.
* Launch Deauth-Attack: Deauthenticates all clients connected to a network. Enter the network number from the table at the top and a reason code from the table at the bottom of the page. After that click the button and your ESP32's LED will flash when it deauthenticates a station.
* Deauth all networks: Launches a Deauth-Attack on all networks and stations with a specific reason. In order to stop this, you have to reset your ESP32 (no other way to code this since the ESP32 rapidly changes through all network channels and has to disable its AP)
* Stop Deauth-Attack: Stops an ongoing deauthentication attack
## License
All files within this repo are released under the GNU GPL V3 License as per the LICENSE file stored in the root of this repo.
