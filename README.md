# How to get gcc to work again on updated macOS?

## Xcode 16.4 too big to install in macOS 12 (Monterey); shall need 20GB+ of storage space;

Found I can install an earlier version of Command Life Tools;

https://developer.apple.com/download/all/?q=command; last accessed: 20250718

> Command Line Tools for Xcode 13

> September 20, 2021

However, SDL_GameController doesn't recognize XBOX 360 controller on macOS at all; 

It seems that there's no driver, unlike in Ubuntu Linux;

# Google: "sdl xinput controller"

> AI Overview

> SDL's SDL_GameController API provides a consistent interface for interacting with various game controllers, including those that emulate XInput. XInput is a Microsoft API primarily used for Xbox 360 and later controllers on Windows, but SDL's SDL_GameController abstracts away the underlying specifics, offering a unified way to handle input from different controllers. This allows developers to write code that works with various controllers without needing to handle the unique aspects of each one. 

## Google: "SDL_PollEvent controller"

> AI Overview

> SDL_PollEvent is a function in the SDL (Simple DirectMedia Layer) library used to retrieve events from the event queue. It's a core part of handling user input and other system events in SDL applications. 

> Controller input is handled through SDL_Event structures with the type member set to SDL_CONTROLLERBUTTONDOWN, SDL_CONTROLLERBUTTONUP, SDL_CONTROLLERAXISMOTION, etc.

TODO -verify: this

> Here's a simple example (adapted from common examples):

https://github.com/usbong/blue-sapphire-galaxy-java-nogl/blob/main/inputTestSDL.cpp; last accessed: 20250716

# Test XBOX360 Controller

https://github.com/usbong/blue-sapphire-galaxy-java-nogl/blob/main/inputTest.cpp; last accessed: 20250716

No input received from XBOX360 Controller, though another controller, e.g. [Sidewinder](https://github.com/usbong/documentation/blob/a0aee194c4b8a4e7a96aa49b8477ae1333db79f8/Usbong/R%26D/Automotive/winmain.cpp#L322), could be made to work.

## --

https://github.com/walbourn/directx-sdk-samples-reworked/blob/main/XInput/SimpleController/SimpleController.cpp; last accessed: 20250716

`gcc.exe "D:\Usbong\RD\sample\SimpleController.cpp" -lgdi32 -o "D:\Usbong\RD\sample\SimpleController.exe"`

Fails using gcc (not via Visual Studio): `Xinput.h: No such file or directory`

## Similar Problem: 

https://github.com/godotengine/godot/issues/4914; last accessed: 20250716

> windows/mingw build error on latest sync #4914

> May 30, 2026

> In file included from platform\windows\os_windows.cpp:54:0:

> platform\windows\joystick.h:36:96 fatal error: xinput.h: No such file or directory

> #include <xinput.h> // on unix the file is called "xinput.h", on windows I'm sure it won't mind

## Note: mingw 64-bit for Windows: https://winlibs.com/#download-release; last accessed: 20250716

# Test the .zip of the app in another computer

https://partner.steamgames.com/apps/builds; last accessed: 20250711

1) App Admin (https://partner.steamgames.com/apps/landing/...)
2) Depots Included: Depot (https://partner.steamgames.com/apps/depotmanifest/...)

> Depot Manifest: Download depot as .ZIP

noted when running `game.exe`, "Windows protected your PC..." Warning Message

# > How to Upload a Game to Steam - Step by Step Guide: https://www.youtube.com/watch?v=gwMPvEFFomE; last accessed: 20250711; from 20250708

# > Download latest SDK: https://partner.steamgames.com/home; last accessed: 20250711

steamworks_sdk_162/sdk/tools/ContentBuilder/content/bluesapphiregalaxy_windows/<br/>
--> assets/<br/>
--> classes/<br/>
--> javapath/<br/>
--> lib/<br/>
--> res/<br/>
game.c<br/>
game.exe<br/>
runWithSteamWorks4jJarFile.bat<br/>
UsbongMainWithSteamWorks4j.jar


> Google

> AI Overview

> The "ERROR! Failed to initialize build on server (Invalid Parameter)" is a common error when uploading builds to Steamworks. It usually indicates an issue with the build configuration or the data being uploaded. The problem often stems from incorrect parameters like using the wrong AppID or BuildID, or failing to properly set the live or local parameters. 

Find the `AppID` here: https://partner.steamgames.com/apps/; last accessed: 20250711


## --

# https://learn.microsoft.com/en-us/java/openjdk/download; last accessed: 20250710

## JRE: https://adoptium.net/temurin/releases/?version=8; last accessed: 20250710

## --

# https://jvm-gaming.org/t/steam-learnings/70063/2; last accessed: 20250709

## JRE: https://www.azul.com/downloads/?os=windows&package=jre#zulu; last accessed: 20250709

# > How to Upload a Game to Steam - Step by Step Guide 

https://www.youtube.com/watch?v=gwMPvEFFomE; last accessed: 20250708
 
# Google: "Steamworks java launch"

> AI Overview

> Launching a Java application with Steamworks functionality involves configuring Steam to run your Java executable and ensuring the Steamworks API is correctly integrated.

...

> 2. Configuring Steam to Launch your Java Application:

>    Add as a Non-Steam Game:

>    The simplest method is to add your Java application as a "Non-Steam Game" within the Steam client.

>        Open Steam and navigate to "Games" > "Add a Non-Steam Game to My Library...".

>        Browse and select the java.exe (Windows) or the Java executable (macOS/Linux) that will run your application.

...

# Notes

1) https://docs.oracle.com/en/graalvm/enterprise/22/docs/reference-manual/native-image/guides/build-native-executable-from-jar/

> Build a Native Executable from a JAR File

2) https://www.graalvm.org/latest/reference-manual/native-image/

3) https://visualstudio.microsoft.com/vs/ 

# GitHub x ITCH.IO 

# [Game Off 2024: Blue Sapphire Galaxy](https://masarapmabuhay.itch.io/blue-sapphire-galaxy)

[<img src="https://github.com/usbong/game-off-2024/blob/main/notes/art/usbongYouTubeGameOff2024TitleBG.png" width="60%">
](https://masarapmabuhay.itch.io/blue-sapphire-galaxy)

This is a work of fiction created for Game Off 2024 with the theme SECRETS.

## PLAY in BROWSER (Mobile Friendly)

## [<img src="https://github.com/masarapmabuhay/game-off-2024/blob/main/notes/art/catLunge.png" width="10%">](https://masarapmabuhay.itch.io/blue-sapphire-galaxy)   

## Select Software Development Productivity Tools

1) MS Paint

2) https://www.gimp.org/

3) https://www.gbstudio.dev/

4) https://www.audacityteam.org/

5) https://www.win-rar.com

## Related link

1) https://philnits.org/

## Open Source Software License

Copyright 2024-2025 USBONG

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0
  
Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.

@company: USBONG<br/>
@author: SYSON, MICHAEL B., et al.<br/>
@website address: http://www.usbong.ph<br/>
