# Reference:

1) https://adoptium.net/temurin/releases/?version=8; last accessed: 20250715; from 20250710

## Windows JRE; Temurin 8.0.452+9 - 04/20/2025

`./blue-sapphire-galaxy-java-nogl-main/javaNoGL/javapath/OpenJDK8U-jre_x64_windows_hotspot_8u452b09/jdk8u452-b09-jre/`

## Linux x64 JRE; Temurin 8.0.452+9 - 04/20/2025

`./blue-sapphire-galaxy-java-nogl-main/javaNoGL/javapath/OpenJDK8U-jre_x64_linux_hotspot_8u452b09/jdk8u452-b09-jre/`

`java.sh` in `/OpenJDK8U-jre_x64_linux_hotspot_8u452b09/jdk8u452-b09-jre/bin/java.sh` has to be permitted to be executable via, for example, `sudo chmod +x java.sh`

## macOS x64 JRE .TAR.GZ; Temurin 8.0.452+9 - 04/20/2025

`./blue-sapphire-galaxy-java-nogl-main/javaNoGL/javapath/OpenJDK8U-jre_x64_mac_hotspot_8u452b09/jdk8u452-b09-jre/`

`java.sh` in `/OpenJDK8U-jre_x64_mac_hotspot_8u452b09/jdk8u452-b09-jre/Contents/Home/bin/java.sh` has to be changed to be executable via, for example, `sudo chmod +x java.sh`

Otherwise, "No such file or directory"
