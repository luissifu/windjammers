#include "Game.h"

void Game::draw() {
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < mesh.getPolygonsQty(); i++)
	{
		polygon p = mesh.getPolygon(i);
		vertex a = mesh.getVertex(p.a);
		vertex b = mesh.getVertex(p.b);
		vertex c = mesh.getVertex(p.c);

		glVertex3f(a.x, a.y, a.z);
		glVertex3f(b.x, b.y, b.z);
		glVertex3f(c.x, c.y, c.z);
	}
	glEnd();

	SDL_GL_SwapWindow(window);
}