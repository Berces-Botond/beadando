#ifndef AMOBA_HPP_INCLUDED
#define AMOBA_HPP_INCLUDED

#include<vector>
#include<string>

class amoba
{
protected:
	std::vector<std::vector<int>>jatekter;
	int jatekos;
	int XX,YY;
public:
	amoba(int xx,int yy):XX(xx),YY(yy)
	{
		jatekter=std::vector<std::vector<int>>(XX,std::vector<int>(YY,0));
		jatekos=1;
	}
	std::string tamadas(int x,int y)
	{
		if(jatekter[x][y]!=0)return "foglalt";
		jatekter[x][y]=jatekos;
		jatekos*=-1;
		if(jatek_vege())return std::to_string(-jatekos)+"_gyozott";
		if(betelt())return "betelt";
		return "szabalyos_lepes";
	}
	bool jatek_vege()
	{
		int hossz=0;
		for(size_t i=0;i<jatekter.size();i++)
			for(size_t j=0;j<jatekter[i].size();j++)
				if(jatekter[i][j]==-jatekos)
				{
					std::vector<int>v{-1,0,1,1};	//elég a 8 irányból csak 4-et tesztelni, mivel tudjuk, hogy a bal felső sarokból indulunk,
					std::vector<int>w{1,1,1,0};	//azokat az irányokat érdemes nézni, amiket ez a négy számpár leír (x szerinti és y szerinti elmozdulás)
					for(int n=0;n<4;n++)
					{
						int x=i;
						int y=j;
						int a=v[n];
						int b=w[n];
						do
						{
							x+=a;
							y+=b;
							hossz++;
						}while( x<XX && y<YY && x>=0 && jatekter[x][y]==-jatekos && hossz<5 );
						if(hossz==5)return true;
						hossz=0;
					}
				}
		return false;
	}
	bool betelt()
	{
		for(size_t i=0;i<jatekter.size();i++)
			for(size_t j=0;j<jatekter[i].size();j++)
				if(jatekter[i][j]==0)
					return false;
		return true;
	}
	void reset()
	{
		for(size_t i=0;i<jatekter.size();i++)
			for(size_t j=0;j<jatekter[i].size();j++)
				jatekter[i][j]=0;
		jatekos=1;
	}
	std::vector<std::vector<int>> get_jatekter()
	{
		return jatekter;
	}
};

#endif
