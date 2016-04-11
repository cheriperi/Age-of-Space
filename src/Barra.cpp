#include "Barra.h"
#include "Global.h"
#include <sstream>

Barra::Barra(void)
{
}


Barra::~Barra(void)
{
}

void Barra::render(std::stringstream recursos[])
{
	//actRecursos();
	renderRecursos(recursos);

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

void Barra::renderRecursos(std::stringstream recursos[])
{
	SDL_Color color={255,255,0};

	//iconos del oro y la energia
	Texture energia, oro;
	Texture energiaVal, oroVal;
	energia.load("Energy.png", gRenderer);
	oro.load("gold.png", gRenderer);

	//tama�o de los iconos
	Vector2 tama�oiconos;
	Vector2 tama�otexto;
	tama�oiconos.x=30;
	tama�oiconos.y=30;
	tama�otexto.x=60;
	tama�otexto.y=30;

	energia.render(gRenderer, &tama�oiconos, 120);
	oro.render(gRenderer, &tama�oiconos, 10);
	oroVal.render(gRenderer, &tama�otexto, 50);
	cout<<"imprimiendo valores";


	energiaVal.loadText(recursos[0].str(), 10, color);
	energiaVal.render(gRenderer, &tama�otexto, 150);

	oroVal.loadText(recursos[1].str(), 10, color);
	oroVal.render(gRenderer, &tama�otexto, 50);
}

void Barra::setRecursos(std::stringstream recursos[])
{
	SDL_Color color={255,255,0};

	oroVal.loadText(recursos[0].str(), 10, color);
	cout<<recursos[0].str().c_str()<<'\n';
	//energiaVal.loadText(recursos[1].str().c_str(), 10, color);
	energiaVal.loadText("energia", 10, color);
}