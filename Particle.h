#pragma once
#include "ofMain.h"

class Particle {
public:

	Particle(float value, ofColor body_color);
	~Particle();

	void update();
	void draw(const vector<unique_ptr<Particle>> &particles);

	ofPoint make_point(float radius, float small_radius, float deg, float small_deg);
private:

	float radius;
	float small_radius;
	float deg;
	float small_deg;
	float deg_span;
	float small_deg_span;
	float value;

	ofColor body_color;
};