#pragma once

#define NOMINMAX

#pragma comment(lib, "rpcrt4.lib")
#include <windows.h>

#include <assert.h>
#include <chrono>
#include <fstream>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <memory>
#include <random>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

#include "json.hpp"

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_render.h"
#include "SDL_events.h"

// Engine Stuff
#include "AssetManager.h"
#include "RenderSystem.h"
#include "SceneManager.h"

#include "CollisionDetection.h"
#include "Circle.h"
#include "GameTime.h"
#include "UI.h"
#include "Scene.h"

//#include "GameEngine.h"
//#include "Entity.h"
