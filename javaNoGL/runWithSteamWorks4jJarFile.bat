@echo off
REM
REM Copyright 2025 USBONG
REM 
REM Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You ' may obtain a copy of the License at
REM
REM http://www.apache.org/licenses/LICENSE-2.0
REM
REM Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, ' WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing ' permissions and limitations under the License.
REM
REM @company: USBONG
REM @author: SYSON, MICHAEL B.
REM @date created: 20240719
REM @date updated: 20250710; from 20250708
REM
REM References:
REM 1) https://jvm-gaming.org/t/steamworks4j-just-starting-out-on-steam-and-have-a-few-questions/59269/4;
REM last accessed: 20241204
REM
REM 2) https://docs.oracle.com/javase/tutorial/deployment/jar/run.html;
REM last accessed: 20250708
REM

REM edited by Mike, 20250708
REM java -cp "./src/;./srcWithSteamWorks4j;./lib/steamworks4j-1.7.1-20180428.093430-2.jar" "UsbongMainWithSteamWorks4j"

REM the main .jar file has to be in the root directory
REM OK
REM java -jar "./UsbongMainWithSteamWorks4j.jar"  

REM "./javapath/zulu24.30.11-ca-jre24.0.1-win_x64/bin/java" -jar "./UsbongMainWithSteamWorks4j.jar"  

REM "./javapath/zulu24.30.11-ca-jre24.0.1-win_x64/bin/java" --enable-native-access=ALL-UNNAMED -jar "./UsbongMainWithSteamWorks4j.jar"  

REM "./javapath/jre1.8.0_201/bin/java" -jar "./UsbongMainWithSteamWorks4j.jar"  

REM "./javapath/microsoft-jdk-21.0.7-windows-x64/jdk-21.0.7+6/bin/java" -jar "./UsbongMainWithSteamWorks4j.jar"  

REM "./javapath/microsoft-jdk-11.0.27-windows-x64/jdk-11.0.27+6/bin/java" -jar "./UsbongMainWithSteamWorks4j.jar"  

"./javapath/OpenJDK8U-jre_x64_windows_hotspot_8u452b09/jdk8u452-b09-jre/bin/java" -jar "./UsbongMainWithSteamWorks4j.jar"  

