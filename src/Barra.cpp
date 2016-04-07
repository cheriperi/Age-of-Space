#include "Barra.h"
#include "Global.h"

Barra::Barra(void)
{
}


Barra::~Barra(void)
{
}

void Barra::render()
{
	//actRecursos();
	renderRecursos();

	renderName();

	//renderOpciones();
}

void Barra::renderName()
{
	Vector2 tama�o;
	tama�o.x=gWindow.getWidth()*0.5;
	tama�o.y=25;
	nombrejugador.render(gRenderer, &tama�o, gWindow.getWidth()*0.25, 20);
}

void Barra::SetName(std::string nombre)
{
	SDL_Color color={0,0,255};
	nombrejugador.loadText(nombre, 10, color);
}

void Barra::renderRecursos()
{
	SDL_Color color={255,255,0};

	Texture energia, oro;
	energia.loadText("energia", 10, color);
	oro.loadText("oro", 10, color);

	Vector2 tama�o;
	tama�o.x=gWindow.getWidth()*0.1;
	tama�o.y=15;
	energia.render(gRenderer, &tama�o, gWindow.getWidth()*0, 10);
	oro.render(gRenderer, &tama�o, gWindow.getWidth()*0.1, 10);

}

