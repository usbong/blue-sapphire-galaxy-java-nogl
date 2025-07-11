/*
 * Copyright 2025 Usbong
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
 * @date created: 20250709
 * @last updated: 20250709
 * @website: www.usbong.ph
 *
 * Reference:
 * 1) Google: "c code to execute bat file"; AI Overview
 */

#include <stdio.h>
#include <stdlib.h> // Required for the system() function

int main() {
    // Specify the full path to your batch file
    // Use double backslashes for path separators in C strings
    //const char *batchFilePath = "C:\\path\\to\\your\\batchfile.bat";

    const char *batchFilePath = "runWithSteamWorks4jJarFile.bat";

    // Execute the batch file using the system() function
    // cmd /C ensures the command prompt closes after execution
    int result = system(batchFilePath);

    // Check the return value to see if the command was successful
    if (result == 0) {
        printf("Batch file executed successfully.\n");
    } else {
        printf("Error executing batch file. Return code: %d\n", result);
    }

    return 0;
}
