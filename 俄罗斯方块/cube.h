#ifndef CUBE_H_
#define CUBE_H_
#include <glm/glm.hpp>
#include <glut.h>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
using namespace std;
extern int SIZE;
const glm::vec2 TYPES[7][4] = { {glm::vec2(0,0),glm::vec2(1,0),glm::vec2(2,0),glm::vec2(3,0)},
{glm::vec2(0,0),glm::vec2(0,1),glm::vec2(1,1),glm::vec2(2,1)},
{glm::vec2(0,1),glm::vec2(1,1),glm::vec2(2,1),glm::vec2(1,0)},
{glm::vec2(0,0),glm::vec2(1,0),glm::vec2(0,1),glm::vec2(1,1)},
{glm::vec2(2,0),glm::vec2(0,1),glm::vec2(1,1),glm::vec2(2,1)},
{glm::vec2(0,0),glm::vec2(1,0),glm::vec2(1,1),glm::vec2(2,1)},
{glm::vec2(0,1),glm::vec2(1,1),glm::vec2(1,0),glm::vec2(2,0)},
};
const glm::vec2 CENTER[7] = {
	glm::vec2(1,0),
	glm::vec2(0,1),
	glm::vec2(1,1),
	glm::vec2(-1,-1),
	glm::vec2(1,1),
	glm::vec2(1,1),
	glm::vec2(1,1)
};
class Cube
{

private:
	uint8_t id_current = 1;
	glm::vec2 block_current[4];
	glm::vec2 pos_current[4];
	glm::vec3 color_current=glm::vec3(255,0,0);
public:
	void setType(uint8_t id,glm::vec3 color) {
		this->id_current = id;
		for (int i = 0; i < 4; i++) {
			block_current[i] = TYPES[id][i];
		}
		color_current = color;
	}
	void display() {
		display(0, 0);
	}
	void display(short x_offset,short y_offset) {
		if (id_current == -1)return;
		glPointSize(800 / SIZE);
		glBegin(GL_POINTS);
		glColor3ub(color_current.x, color_current.y, color_current.z);
		for (int i = 0; i < 4; i++) {
		
			glVertex2f(block_current[i].x+x_offset, block_current[i].y+y_offset);
		}
		glEnd();
	}
	void rotate() {
		if (id_current != -1&&id_current!=3) {
			float mx = 0, my = 0;
			for (int i = 0; i < 4; i++) {
				mx += block_current[i].x;
				my += block_current[i].y;
			}
			mx /= 4; my /= 4;
			mx = CENTER[id_current].x;
			my = CENTER[id_current].y;
			for (int i = 0; i < 4; i++) {
				float x = block_current[i].x;
				float y = block_current[i].y;
				x -= mx; y -= my;
				float x2 = -y+mx;
				float y2 = x+my;
				block_current[i].x = floor(x2);
				block_current[i].y =floor(y2) ;

			}
		}
	}
};

#endif