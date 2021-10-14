#include <array>
#include <chrono>
#include <iostream>
#include <thread>

#include "camera.h"
#include "constants.h"
#include "dielectric.h"
#include "image.h"
#include "lambertian.h"
#include "metal.h"
#include "random.h"
#include "ray.h"
#include "sphere_list.h"
#include "vec3.h"

void worker(Image& im, const Camera& cam, const SphereList& scene, int id)
{
	// Cast rays
	int start = (IMAGE_HEIGHT / NUM_THREADS) * id;
	int end = (id != NUM_THREADS - 1) ? (IMAGE_HEIGHT / NUM_THREADS) * (id + 1) : IMAGE_HEIGHT;
	for (int row = start; row < end; row++) {
		for (int col = 0; col < IMAGE_WIDTH; col++) {
			Colour pixel_colour(0.0, 0.0, 0.0);
			for (int samples = 0; samples < SAMPLES_PER_PIXEL; samples++) {
				double u = static_cast<double>(col + Random::RandomDouble()) / (static_cast<double>(IMAGE_WIDTH) - 1);
				double v = static_cast<double>(row + Random::RandomDouble()) / (static_cast<double>(IMAGE_HEIGHT) - 1);

				pixel_colour += cam.GetRay(u, v).GetColour(scene, MAX_DEPTH);
			}
			pixel_colour /= SAMPLES_PER_PIXEL;
			im.SetPixel(col, row, pixel_colour.GammaCorrected());
		}
	}
}

int main()
{
	auto start = std::chrono::high_resolution_clock::now();

	// Create image buffer
	Image im(IMAGE_HEIGHT, IMAGE_WIDTH);

	// Create camera
	Camera cam(Vec3(0, 0, 1), Vec3(0, 0, -1), Vec3(0, 1, 0), VFOV, ASPECT_RATIO);

	// Create materials
	Lambertian ground(Colour(0.8, 0.8, 0.8));
	Lambertian centre(Colour(0.1, 0.2, 0.5));
	Dielectric left(1.5);
	Metal right(Colour(0.8, 0.6, 0.2), 0.0);

	// Create scene
	SphereList scene;
	scene.Add(Sphere(Vec3(0.0, -100.5, -1.0), 100.0, ground));
	scene.Add(Sphere(Vec3(0.0, 0.0, -1.0), 0.5, centre));
	scene.Add(Sphere(Vec3(-1.0, 0.0, -1.0), 0.5, left));
	scene.Add(Sphere(Vec3(1.0, 0.0, -1.0), 0.5, right));

	// Assign a chunk of data to a thread
	std::array<std::thread, NUM_THREADS> threads;
	for (int id = 0; id < NUM_THREADS; id++)
		threads[id] = std::thread(worker, std::ref(im), std::ref(cam), std::ref(scene), id);

	for (auto& thread : threads)
		thread.join();

	im.SaveImage("image.ppm");

	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start);
	std::cout << "Elapsed time: " << duration.count() << "ms";

	return 0;
}