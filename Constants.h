#pragma once
const unsigned int TARGET_TICKS = 60;
const unsigned int SKIP_TICKS = 1000 / TARGET_TICKS;
const unsigned int MAX_SKIP = 10;

const unsigned int MAX_SYSTEMS = 10;
const unsigned int MAX_ENTITIES = 10;
const unsigned int MAX_COMPONENTS = 10;

const float WORLD_X = 0.0f;
const float WORLD_Y = 0.0f;
const float WORLD_Z = 0.0f;

const float CAMERA_X =  0.0f;
const float CAMERA_Y =  0.0f;
const float CAMERA_Z = -40.0f;

const unsigned int DEFAULT_WIDTH = 1280;
const unsigned int DEFAULT_HEIGHT = 720;