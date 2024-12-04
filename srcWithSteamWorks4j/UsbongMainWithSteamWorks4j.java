/*
 * Copyright 2024 Usbong
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @company: Usbong
 * @author: SYSON, MICHAEL B.
 * @date created: 20240522
 * @last updated: 20241204; from 20241203
 * @website: www.usbong.ph
 *
 */
/*
 Additional Notes:
 1) compile on Windows Machine;
	compile.bat

 2) Execute
	run.bat

 Known Issue:
 1) Problem when TILE_BASE from Background class is at the other side;
	It's not hit by plasma
	Current solution: Don't put TILE_BASE in the part of the tilemap near 0 or the MAX_TILE_MAP_WIDTH by iViewPortWidth distance;
	Reminder: currently, y or height not wrapped;

 References:
 1) https://docs.oracle.com/javase/tutorial/uiswing/painting/refining.html; last accessed: 20240622
  SwingPaintDemo4.java; last accessed: 20240622; from 20240623

 2) https://github.com/usbong/game-off-2023; last accessed: 20240623
*/

import com.codedisaster.steamworks.*;
import javax.swing.SwingUtilities;

public class UsbongMainWithSteamWorks4j {
	private static UsbongMain usbongMain;
	
	public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
				initSteamAPI(); //TODO: -reverify: this					
                
				System.out.println("initSteamAPI... Done!");
				
				//createAndShowGUI();
				usbongMain.main(null);
            }
        });
    }

	//note: .jar not available for download today (20241203)	
	//1) https://oss.sonatype.org/content/repositories/snapshots/com/code-disaster/steamworks4j/steamworks4j/1.7.1-SNAPSHOT/; 
	//last accessed: 20241203; from 20240815
	//Repository where steamworks4j-1.7.1-20180428.093430-2.jar can be downloaded
	
	//2) https://github.com/code-disaster/steamworks4j/blob/master/tests/src/main/java/com/codedisaster/steamworks/test/SteamTestApp.java;
	//last accessed: 20241204
    private static void initSteamAPI() {
		try {
			SteamAPI.loadLibraries();

	/*		
			//SteamAPI.restartAppIfNecessary();
			// doesn't make much sense here, as normally you would call this before
			// SteamAPI.init() with your (kn)own app ID
			if (SteamAPI.restartAppIfNecessary(clientUtils.getAppID())) {
				System.out.println("SteamAPI_RestartAppIfNecessary returned 'false'");
			}		
	*/			
			SteamAPI.init();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(-1);
		}		
	}	
}