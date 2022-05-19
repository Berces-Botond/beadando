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
		if(jatekter[x][y]!=1)return "foglalt";
		jatekter[x][y]=jatekos;
		jatekos*=-1;
		if(jatek_vege())return std::to_string(jatekos)+"_gyozott";
		return "szabalyos_lepes";
	}
	bool jatek_vege()
	{
		int hossz=0;
		for(size_t i=0;i<jatekter.size();i++)
			for(size_t j=0;j<jatekter[i].size();j++)
				if(jatekter[i][j]==jatekos)
				{
					hossz++;
					int x=i;
					int y=j;
					std::vector<int>v{-1,0,1,1};
					std::vector<int>w{1,1,1,0};
					for(int n=0;n<4;n++)
					{
						int a=v[n];int b=w[n];
						while( x<XX && y<YY && x>=0 && jatekter[x][y]==jatekos && hossz<5 )
						{
							x+=a;
							y+=b;
							hossz++;
						}
						if(hossz==5)return true;
					}
				}
		return false;
	}
};

#endif
