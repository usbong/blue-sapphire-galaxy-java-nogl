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
REM @date updated: 20250708; from 20241204
REM
REM Note: faster to put necessary files inside "src" folder to solve location errors
REM go to ./src
REM javac -cp .;jinput-2.0.10.jar;jinput-2.0.10-natives-all.jar; *.java
REM OK; but jinput uses the later JDK version 17 (not JDK 1.7)
REM
REM References
REM 1) https://jvm-gaming.org/t/steamworks4j-just-starting-out-on-steam-and-have-a-few-questions/59269/4; 
REM last accessed: 20240815
REM Guide to compile and run Java app with steamworks4j (uses JDK 1.7)
REM
REM 2) https://oss.sonatype.org/content/repositories/snapshots/com/code-disaster/steamworks4j/steamworks4j/1.7.1-SNAPSHOT/; 
REM last accessed: 20240815
REM Repository where steamworks4j-1.7.1-20180428.093430-2.jar can be downloaded
REM
REM 3) https://jdk.java.net/java-se-ri/7;
REM last accessed: 20240815
REM Location where JDK 1.7 32-bit for Windows can be downloaded
REM
REM 4) https://openjdk.org/install/;
REM last accessed: 20240815
REM Steps to install JDK 1.7 32-bit on Linux
REM
REM 5) https://docs.oracle.com/javase/tutorial/deployment/jar/build.html;
REM last accessed: 20240708
REM

REM javac "./src/"*.java

REM edited by Mike, 20250708
REM javac -cp "./lib/steamworks4j-1.7.1-20180428.093430-2.jar" "./srcWithSteamWorks4j/"*.java "./src/"*.java

mkdir classes

REM "-d ." auto-puts class files in "classes" folder
javac -d . -cp "./lib/steamworks4j-1.7.1-20180428.093430-2.jar" "./srcWithSteamWorks4j/"*.java "./src/"*.java

REM added by Mike, 20250708
mkdir output

jar cmvf META-INF/MANIFEST.MF "./output/UsbongMainWithSteamWorks4j.jar" "./classes/"*.class res assets "./lib/steamworks4j-1.7.1-20180428.093430-2.jar" 

REM the main .jar file has to be in the root directory
xcopy .\output\UsbongMainWithSteamWorks4j.jar .\*.jar /y
