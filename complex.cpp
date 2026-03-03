#include <iostream>
#include <cstring>
using namespace std;

class Complex
{
	double real;
	double imag;
	public:
		Complex (double re) { real=re; imag=0;}
		Complex (double re,double im){real=re; imag=im;}
		Complex (){real =0; imag=0;}
		double get_real()const { return real;}
		double get_imag()const { return imag;}
		friend std :: ostream& operator << (std :: ostream &s, const Complex &x){ s << '(' << x.get_real() << ',' << x.get_imag() << ')' ; return s; }
		Complex operator+(Complex x)
		{
			return Complex(real+x.real,imag+x.imag);
		}
		Complex& operator+= (Complex x)
		{
			real+= x.real;
			imag+= x.imag;
			return *this;
		}
		friend std :: istream& operator >> (std :: istream &s, Complex &x) 
		{

			char str[20];
			char buf[20];
			memset(str,0,20);
			memset(buf,0,20);
			std::cin >> str;
			cout << "str="  << str<<endl;
			int i=0,j=0;
			if (str[0] == '(')
			{
				for(i=1;str[i] != ',';i++)
				{
					buf[j++] = str[i];
				}
				cout << buf << "\n";
				x.real=atof(buf);
				cout <<"real="<< atof(buf)<<"\n";
				memset(buf,0,20);
				j=0;
				i++;
				while(str[i] != ')')
				{
					cout<< str[i];
					buf[j]=str[i];
					j++;
					i++;
				}
				x.imag=atof(buf);
				cout <<"imag="<< atof(buf)<<"\n";
			}
			else
			{
				x.real=atof(str);
				x.imag=0;
			}
			return s;
		}

};

int main()
{
	Complex x(1,2.5);
	Complex y(1);
	Complex s;
	Complex *p = new Complex;
	Complex z=x+y;
	*p += 1;
	cout << z << "\n" << *p << "\n" << x << "\n";
	Complex n;
	cout << "Enter complex" << "\n";
	cin >> n;
	cout << n;
	n+=1;
	cout << n;
	return 1;
}

