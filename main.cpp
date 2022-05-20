#include"graphics.hpp"
#include"amoba.hpp"
#include<cmath>
using namespace genv;

const int xx=400;
const int yy=400;

void kor(float x0,float y0, float r)
{
	for(int x=std::max(0,(int)(x0-r));x<std::min(xx,(int)(x0+r));x++)
		for(int y=std::max(0,(int)(y0-r));y<std::min(yy,(int)(y0+r));y++)
			if(pow(x-x0,2)+pow(y-y0,2)<=pow(r,2))
				gout<<move_to(x,y)<<color(0,0,255)<<dot;
	r*=0.9;
	for(int x=std::max(0,(int)(x0-r));x<std::min(xx,(int)(x0+r));x++)
		for(int y=std::max(0,(int)(y0-r));y<std::min(yy,(int)(y0+r));y++)
			if(pow(x-x0,2)+pow(y-y0,2)<=pow(r,2))
				gout<<move_to(x,y)<<color(255,255,255)<<dot;
}
class grafikusamoba
{
protected:
	amoba* a;
	int XX,YY;
	std::vector<std::vector<int>>jatekter;
	float fx,fy;
	std::string uzenet;
public:
	grafikusamoba(int x,int y):XX(x),YY(y),fx((float)xx/XX),fy((float)yy/YY)
	{
		a=new amoba(XX,YY);
	}
	void loop()
	{
		event ev;
		while(gin >> ev && ev.keycode!=key_escape)
		{
			palyarajz();
			if(ev.button==btn_left && uzenet!="1_gyozott" && uzenet!="-1_gyozott" && uzenet!="betelt")
				uzenet=a->tamadas(ev.pos_x/(int)fx,ev.pos_y/(int)fy);
			if(uzenet=="1_gyozott")
				gout<<move_to(0,gout.cascent())<<color(255,0,0)<<text("X gyozott\nnyomj entert az uj jatekhoz");
			if(uzenet=="-1_gyozott")
				gout<<move_to(0,gout.cascent())<<color(0,0,255)<<text("O gyozott\nnyomj entert az uj jatekhoz");
			if(uzenet=="betelt")
				gout<<move_to(0,gout.cascent())<<color(0,255,0)<<text("betelt\nnyomj entert az uj jatekhoz");
			if(ev.keycode==key_enter&&(uzenet=="-1_gyozott"||uzenet=="1_gyozott"||uzenet=="betelt"))
			{
				a->reset();
				uzenet="";
			}
			gout<<refresh;
		}
	}
	void palyarajz()
	{
		gout<<move_to(0,0)<<color(255,255,255)<<box(xx,yy);
		for(int x=0;x<XX;x++)
			gout<<move_to(x*fx,0)<<color(0,0,0)<<line(0,yy);
		for(int y=0;y<YY;y++)
			gout<<move_to(0,y*fy)<<color(0,0,0)<<line(xx,0);
		jatekter=a->get_jatekter();
		for(size_t i=0;i<jatekter.size();i++)
			for(size_t j=0;j<jatekter[i].size();j++)
			{
				if(jatekter[i][j]==1)
					gout<<move_to(i*fx,j*fy)<<color(255,0,0)<<line(fx,fy)<<move(0,1-fy)<<line(-fx,fy);
				if(jatekter[i][j]==-1)
					kor((i+0.5)*fx,(j+0.5)*fy,std::min(fx*0.5,fy*0.5));
			}
	}
};

int main()
{
	gout.open(xx,yy);
	gin.timer(1);
	grafikusamoba gra(15,15);
	gra.loop();
	return 0;
}
