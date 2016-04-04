#include "Asteroid.h"

#include <cmath>
#include <iostream>

using namespace std;



Asteroid::Asteroid()
{
	sel = false;
}


Asteroid::~Asteroid()
{
}

void Asteroid::event(SDL_Event* e)
{
	int mx, my;


	//Bot�n izquierdo


	if (e->type == SDL_MOUSEBUTTONDOWN)
	{
		Vector2 size = tex.getDim();
		SDL_GetMouseState(&mx, &my);


		if((((mx >= pos.x) && (mx <= (pos.x + size.x))) && ((my >= pos.y) && (my <= (pos.y + size.y)))))
		{
			printf("dentro del cuadrado\n");
			switch(e->button.button)
			{
			case SDL_BUTTON_LEFT:
			//Debug
			printf("izq\n", pos.x, pos.y);
			select();
			break;
		
			case SDL_BUTTON_RIGHT:
			//select();
			//openMenu(gRenderer);
			//Debug
			printf("der\n");
			break;
			}
			render();
		}
		else deselect();

	}

}

void Asteroid::select()
{
	sel = true;
}

void Asteroid::deselect()
{
	sel = false;
}

void Asteroid::openMenu(SDL_Renderer* renderer)
{
	boton.tex.load("edificio.png", renderer);
	int mx, my;
	SDL_GetMouseState(&mx, &my);
	boton.tex.render(renderer, mx, my);
	printf("boton mostrado\n");
}

/*void Asteroid::move()
{
	if ((abs(cen.x - dest.x) > max_vel) || (abs(cen.y - dest.y) > max_vel)) {
		//cout << "Me tengo que mover!" << endl;
		//cout << "Estoy en " << cen.x << ", " << cen.y << endl;
		//cout << "Tengo que ir a " << dest.x << ", " << dest.y << endl;
		//cout << "Apunto a" << angle << " grados" << endl;
		//Ajuste de velocidades
		vel.x = max_vel * cos(M_PI * angle / 180);
		vel.y = max_vel * sin(M_PI * angle / 180);
		//cout << "Voy con velocidad " << vel.x << ", " << vel.y << endl;
		//Movimiento
		SetCen(cen.x + vel.x, cen.y + vel.y);
		//cout << "Me he movido a  " << cen.x << ", " << cen.y << endl;
		//system("PAUSE");
	}
	else
	{
		vel.x = 0;
		vel.y = 0;
	}
}

void Asteroid::stop()
{
	dest.x = cen.x;
	dest.y = cen.y;
	vel.x = 0;
	vel.y = 0;
}

bool Asteroid::moveTo(int x, int y)
{
	//vel.x = dir.x;
	//vel.y = dir.y;
	return false;
}*/

//Renderizado (con rotaci�n y selecci�n)
void Asteroid::render()
{
	tex.render(gRenderer,(int)pos.x,(int)pos.y);

	//Marcador de selecci�n
	if (sel == true)
	{
		SDL_Rect rec_sel;
		rec_sel.x = pos.x;
		rec_sel.y = pos.y;
		rec_sel.h = tex.getDim().x;
		rec_sel.w = tex.getDim().y;
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);;
		SDL_RenderDrawRect(gRenderer, &rec_sel);
	}
}

//Posici�n
Vector2 Asteroid::GetPos()
{
	return pos;
}

void Asteroid::SetPos(float x, float y)
{
	pos.x = x;
	pos.y = y;
	cen.x = pos.x + tex.getDim().x / 2;
	cen.y = pos.y + tex.getDim().y / 2;
}


//Centro
Vector2 Asteroid::GetCen()
{
	return cen;
}

//Cambia el centro y la posici�n
void Asteroid::SetCen(float x, float y)
{
	cen.x = x;
	cen.y = y;
	pos.x = cen.x - tex.getDim().x / 2;
	pos.y = cen.y - tex.getDim().y / 2;
}