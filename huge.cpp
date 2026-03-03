#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int ndigits=20;
const int ndecimal=10;

class huge{
	char sign;
	char integral[ndigits];
	char decimal[ndecimal];
	public:
		char get_sign() const { return sign; }
		const char* get_integral() const { return integral; }
		const char* get_decimal() const { return decimal; }
		huge(){
			sign = '+';
			for(int i=0;i<ndigits;i++)
				integral[i]='0';
			integral[ndigits-1]='\0';
			for(int i=0;i<ndecimal;i++)
				decimal[i]='0';
			decimal[ndecimal-1]='\0';
		}
		huge(double x){
			char buf[30];
			sprintf(buf,"%f",x);
//			printf("buf=%s\n",buf);
			sign = '+';
			int i=0,j=0;
			while(buf[i] != '.')
			{
				integral[i]=buf[i];
				i++;
			}
			i++;
			//buf[i]='.';
			while(buf[i]!='\0')
			{
				decimal[j]=buf[i];
				j++;
				i++;
			}
		}
		friend std :: ostream& operator << (std :: ostream &s, const huge &x){ s  << x.get_sign() << x.get_integral() << '.' << x.get_decimal() ; return s; }
		friend std :: istream& operator >> (std :: istream &s, huge &x)
		{
			char buf[30];
			memset(buf,0,30);
			cin >> buf;
			x.sign = '+';
                        int i=0,j=0;
			printf("buf=%s\n",buf);
                        while(buf[i] != '.')
                        {
				printf("buf[%d]=%c\n", i,buf[i]);
                                x.integral[i]=buf[i];
                                i++;
                        }
                        i++;
			printf("%s\n",x.integral);
                        while(buf[i]!='\0')
                        {
                                x.decimal[j]=buf[i];
				printf("buf[%d]=%c\n", i,buf[i]);
                                j++;
                                i++;
                        }
			printf("%s\n",x.decimal);
			return s;
			

		}	

};


int main()
{
	huge x;
	cin>>x;
	huge y;
	cout << x << endl;
	cout << y << endl;

}
