/*
 * Copyright 2020~2025 USBONG
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
 * @company: USBONG
 * @author: SYSON, MICHAEL B.
 * @date created: 20250716
 * @date updated: 20250716
 * @website: http://www.usbong.ph
 *
 * Reference:
 * 1) https://docs.microsoft.com/en-us/windows/win32/inputdev/user-input3
 * last accessed: 20250715; from 20200424
 * 
 * 2) Google: "SDL_PollEvent controller"; AI Overview
 *
 */

//TODO: -reverify: this

//edited by Mike, 20250716
//#include <SDL.h>

//reference: pagongHalang
#ifdef _WIN32 //Windows machine
	#include <SDL.h>
//	#include <SDL_image.h>
#else
	#include <SDL2/SDL.h>
//	#include <SDL2/SDL_image.h>
#endif

int main(int argc, char* argv[]) {
  SDL_Init(SDL_INIT_GAMECONTROLLER | SDL_INIT_VIDEO);
  SDL_Window* window = SDL_CreateWindow("Controller Example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

  SDL_GameController* controller = NULL;
  for (int i = 0; i < SDL_NumJoysticks(); ++i) {
    if (SDL_IsGameController(i)) {
      controller = SDL_GameControllerOpen(i);
      if (controller) {
        break;
      }
    }
  }

  SDL_Event event;
  bool running = true;

  while (running) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        running = false;
      } else if (event.type == SDL_CONTROLLERBUTTONDOWN) {
        // Handle controller button presses
        if (event.cbutton.button == SDL_CONTROLLER_BUTTON_A) {
          // A button was pressed
          //Do something
        } else if (event.cbutton.button == SDL_CONTROLLER_BUTTON_B) {
            //B button was pressed
            //Do something else
        }
      } else if (event.type == SDL_CONTROLLERAXISMOTION) {
          //Handle joystick or analog stick movement
          if (event.caxis.axis == SDL_CONTROLLER_AXIS_LEFTX) {
              //Left stick X axis motion
          }
      }
    }

    // Your game logic and rendering here

    SDL_RenderPresent(renderer);
    SDL_Delay(16); // Roughly 60 FPS
  }

  if (controller) {
    SDL_GameControllerClose(controller);
  }
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
