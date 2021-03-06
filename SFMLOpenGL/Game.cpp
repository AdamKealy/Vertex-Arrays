#include <Game.h>

bool flip = false;
int current = 1;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{

}

Game::~Game() {}


float vertices[] = { -1.f,1.f,-5.f,		 1.f,1.f,-5.f,		-1.f,-1.f,-5.f,
					 1.f,-1.f,-5.f,		 1.f,-1.f,-10.f,	 -1.f,1.f,-5.f,
					 1.f,1.f,-10.f,		 1.f,-1.f,-5.f,		-1.f,1.f,-10.f,
					 -1.f,-1.f,-5.f,	-1.f,-1.f,-10.f,	 1.f,-1.f,-10.f,
					 1.f,-1.f,-10.f,	-1.f,1.f,-10.f,		 1.f,1.f,-10.f};

float colors[] = { 1.0f, 0.0f, 0.0f,	0.0f, 0.0f, 1.0f,	1.0f, 0.0f, 0.0f,
				   0.0f, 0.0f, 1.0f,	1.0f, 1.0f, 1.0f,	0.0f, 1.0f, 0.0f,
				   0.0f, 0.0f, 1.0f,	0.0f, 1.0f, 0.0f,	1.0f, 0.0f, 0.0f,
				   1.0f, 0.0f, 0.0f,	1.0f, 0.0f, 0.0f,	0.0f, 1.0f, 0.0f,
				   1.0f, 1.0f, 1.0f,	0.0f, 1.0f, 1.0f,   1.0f, 1.0f, 1.0f};

unsigned int vertex_index[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		render();
	}

}

void Game::initialize()
{
	isRunning = true;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	cout << "Update up" << endl;
}

void Game::render()
{
	cout << "Drawing" << endl;

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	glVertexPointer(3, GL_FLOAT, 0, &vertices);
	glColorPointer(3, GL_FLOAT, 0, &colors);

	Matrix3 matrix;

	if (Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		cout << "roate" << endl;
		matrix.Rotation(1);
	}
	if (Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		cout << "SCALE" << endl;
		matrix.Scale(1.1, 1.1);
	}
	if (Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		cout << "TRANSlate" << endl;
		matrix.Translate(5, 0);
	}

	glDrawElements(GL_TRIANGLE_STRIP, 15, GL_UNSIGNED_INT, &vertex_index);



	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}