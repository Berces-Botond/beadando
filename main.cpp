#include"graphics.hpp"
#include"amoba.hpp"
using namespace genv;
using namespace std;

const int xx=400;
const int yy=400;

class grafikusamoba
{
protected:
	amoba* a;
	int XX,YY;
public:
	grafikusamoba(int x,int y):XX(x),YY(y)
	{
		a=new amoba(XX,YY);
	}
	void loop()
	{
		event ev;
		while(gin >> ev && ev.keycode!=key_escape)
		{
			palyarajz();
			if(ev.button==btn_left)
				a->tamadas(0,0);
			gout<<refresh;
		}
	}
	void palyarajz()
	{
		gout<<move_to(0,0)<<color(255,255,255)<<box(xx,yy);
		float f=(float)xx/XX;
		for(int x=0;x<XX;x++)
			gout<<move_to(x*f,0)<<color(0,0,0)<<line(0,yy);
		for(int y=0;y<YY;y++)
			gout<<move_to(0,y*f)<<color(0,0,0)<<line(xx,0);
		
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
