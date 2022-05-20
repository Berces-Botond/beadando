#ifndef AMOBA_HPP_INCLUDED
#define AMOBA_HPP_INCLUDED

#include<vector>
#include<string>
#include<iostream>
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
		return "szabalyos_lepes";
	}
	bool jatek_vege()
	{
		int hossz=0;
		for(size_t i=0;i<jatekter.size();i++)
			for(size_t j=0;j<jatekter[i].size();j++)
				if(jatekter[i][j]==-jatekos)
				{
//					hossz++;
					std::vector<int>v{-1,0,1,1};
					std::vector<int>w{1,1,1,0};
					for(int n=0;n<4;n++)
					{
						int x=i;
						int y=j;
						int a=v[n];int b=w[n];
						do{
							x+=a;
							y+=b;
							hossz++;
							std::cout<<hossz<<std::endl;
						}while( x<XX && y<YY && x>=0 && jatekter[x][y]==-jatekos && hossz<5 );
						if(hossz==5)return true;
						hossz=0;
					}
				}
		return false;
	}
	std::vector<std::vector<int>> get_jatekter()
	{
		return jatekter;
	}
};

#endif
