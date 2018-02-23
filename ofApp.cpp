#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	ofEnableDepthTest();
	ofSetLineWidth(1.2);

	ofColor body_color;
	for (int i = 0; i < 12; i++) {

		switch (i)
		{
		case 0:
			body_color = ofColor(255, 0, 0);
			break;
		case 4:
			body_color = ofColor(0, 255, 0);
			break;
		case 8:
			body_color = ofColor(0, 0, 255);
			break;
		default:
			body_color = ofColor(255);
			break;
		}
			
		std::unique_ptr<Particle> particle(new Particle(i * 30, body_color));
		this->particles.push_back(std::move(particle));
	}
}

//--------------------------------------------------------------
void ofApp::update() {

	for (int i = 0; i < this->particles.size(); i++) {

		this->particles[i]->update();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	for (int i = 0; i < this->particles.size(); i++) {

		this->particles[i]->draw(this->particles);
	}
		
	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}