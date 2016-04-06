#include "ViewPort.h"


ViewPort::ViewPort(void)
{
	param.x=param.y=param.h=param.w=0;

}


ViewPort::~ViewPort(void)
{
}

//parametros
void ViewPort::SetParam(int w, int h,int x, int y)
{
	param.x=x;
	param.y=y;
	param.h=h;
	param.w=w;
}

void ViewPort::SetRel(float x, float y, float w, float h)
{
	origen.x=x;
	origen.y=y;
	tama�o.x=w;
	tama�o.y=h;

}
void ViewPort::ActParam()
{
	param.x=gWindow.getWidth()*origen.x;
	param.y=gWindow.getHeight()*origen.y;
	tama�ofin.x=param.w=gWindow.getWidth()*tama�o.x;
	tama�ofin.y=param.h=gWindow.getHeight()*tama�o.y;
	printf("nuevos param %d %d %d %d", param.x, param.y, param.w, param.h);

}
//renderizar
void ViewPort::render()
{

	SDL_RenderSetViewport( gRenderer, &param );				
	//Render texture to screen
	tex.render(gRenderer,&tama�ofin);
}
SDL_Rect ViewPort::GetParam()
{
	 return param;
}
void ViewPort::Init(int x, int y, int w, int h, std::string path)
{
	param.x=x;
	param.y=y;
	param.h=h;
	param.w=w;
	tex.load(path, gRenderer);
}
