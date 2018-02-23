#include "Particle.h"

//--------------------------------------------------------------
Particle::Particle(float value, ofColor body_color) {

	this->radius = 230;
	this->small_radius = 50;
	this->deg = 0;
	this->small_deg = value;
	this->deg_span = 2;
	this->small_deg_span = 10;
	this->value = value;
	this->body_color = body_color;
}

//--------------------------------------------------------------
Particle::~Particle() { }

//--------------------------------------------------------------
void Particle::update() {

}

//--------------------------------------------------------------
void Particle::draw(const vector<unique_ptr<Particle>> &particles) {

	ofSetColor(this->body_color);
	
	int max = ofNoise(this->value * 0.05, ofGetFrameNum() * 0.005) * (360.f / this->deg_span);
	for (int i = 0; i < max; i++) {

		ofVec3f point_1 = make_point(this->radius, this->small_radius, this->deg - this->deg_span * i, this->small_deg - this->small_deg_span * i);
		ofVec3f point_2 = make_point(this->radius, this->small_radius, this->deg - this->deg_span * (i + 1), this->small_deg - this->small_deg_span * (i + 1));
		ofDrawLine(point_1, point_2);
	}

	ofVec3f point = make_point(this->radius, this->small_radius, this->deg - this->deg_span * max, this->small_deg - this->small_deg_span * max);
	ofDrawSphere(point, 3);
}

//--------------------------------------------------------------
ofPoint Particle::make_point(float radius, float small_radius, float deg, float small_deg) {

	float x_1 = radius * cos(deg * DEG_TO_RAD);
	float y_1 = radius * sin(deg * DEG_TO_RAD);

	float x_2 = small_radius * cos(small_deg * DEG_TO_RAD) * cos(deg * DEG_TO_RAD);
	float y_2 = small_radius * cos(small_deg * DEG_TO_RAD) * sin(deg * DEG_TO_RAD);

	float x = x_1 + x_2;
	float y = y_1 + y_2;
	float z = small_radius * sin(small_deg * DEG_TO_RAD);

	return ofPoint(x, y, z);
}