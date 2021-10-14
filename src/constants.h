#pragma once

constexpr double VFOV = 45.0;
constexpr double ASPECT_RATIO = 16.0 / 9.0;

constexpr int IMAGE_HEIGHT = 540;
constexpr int IMAGE_WIDTH = static_cast<int>(ASPECT_RATIO * IMAGE_HEIGHT);

constexpr int SAMPLES_PER_PIXEL = 100;
constexpr int MAX_DEPTH = 50;

constexpr int NUM_THREADS = 4;