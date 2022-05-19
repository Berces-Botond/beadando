#include<vector>

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
	bool tamadas(int x,int y)
	{
		if(jatekter[x][y]!=1)return true;
		jatekter[x][y]=jatekos;
		jatekos*=-1;
		if(jatek_vege())return false;
		return true;
	}
	bool jatek_vege()
	{
		return false;
	}
};



int main(){}
