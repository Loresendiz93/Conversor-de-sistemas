/*Programa para convertir sistemas de coordenadas; cartesianas o rectangulares, cilindricas, esfericas o cosenos directos.
Lorenzo Armando Gonzalez Resendiz 2121100496 4° A Mat. Mecatronica Area Robotica*/

#include <iostream>
#include <math.h>
#include <iomanip>
#include <windows.h>
using namespace std;

int eleccion;
float x,y,z,rdexy,rdexyz;
float alfa,alfa4,gamma4,beta4;
float grados =0.0174;
float radian=57.295;

int main (){

	system("Color 0A");
	cout<< "Bienvenidoo@ al conversor de sistemas de coordenadas"<< endl;
	cout<< "De acuerdo al siguiente listado:"<< endl;
	cout<< "1 : Sistema de coordenadas rectangular (x,y,z)"<< endl;
	cout<< "2 : Sistema de coordenadas cilindrico  (r,alfa,z)"<< endl;
	cout<< "3 : Sistema de coordenadas esferico    (r,alfa,beta) "<< endl;
	cout<< "4 : Sistema de coordenadas de cosenos directores"<< endl;
	 
	cout<< "Elige el sistema base:";cin>>eleccion;

	if (eleccion >= 1 && eleccion <= 4){
		
		switch (eleccion)
		{
			case 1:
			cout << "Elegiste el sistema de coordenadas rectangular (x,y,z)"<< endl;
			cout << "Ingresa el valor de x: " ; cin >> x;
			cout << "Ingresa el valor de y: " ; cin >> y;
			cout << "Ingresa el valor de z: " ; cin >> z;
			rdexyz = sqrt(pow(x,2)+pow(y,2)+pow(z,2));
			rdexy = sqrt(pow(x,2)+pow(y,2));
			alfa= acos(x/rdexy);
			alfa*=radian;
			beta4= acos(rdexy/z);
			beta4*=grados;
			alfa4= radian*acos(x/rdexyz);
			beta4= radian*acos(z/rdexyz);
			gamma4= radian*acos(y/rdexyz);
			if (x<0&&y<0){
				alfa+=90;
			}else if (x==0&&y<0){
				alfa+=180;
			}else if (x>0&&y<0){
				alfa+=270;
			}else if (x==0&&y==0&&z==0){
				cout << "Ingresaste un vector nulo"<<endl; 
			}else if (x==0&&y==0){
				alfa=90;
				beta4=90;
			}
			cout << "En el sistema de coordenadas cilindricas (r,alfa,z) es:("<<rdexy<<","<<alfa<<","<<z<<")" <<endl;				         
			cout << "En el sistema de coordenadas esfericas (r,alfa,beta) es:("<<rdexyz<<","<<alfa<<","<<beta4<<")" <<endl;
			cout << "En el sistema de coordenadas de cosenos directores (r,cos(alfa),cos(gamma),cos(beta) es:"<<
			endl<<"("<<rdexyz<<",cos("<<alfa4<<"),cos("<<gamma4<<"),cos("<<beta4<<")" <<endl;		
        break;
        	case 2:
        	cout << "Elegiste el sistema de coordenadas cilindrico (r,alfa,z)"<< endl;
			cout << "Ingresa el valor de r: "     ; cin >> rdexy;
			cout << "Ingresa el valor de alfa (en grados): "  ; cin >> alfa;
			cout << "Ingresa el valor de z: "     ; cin >> z;
			x=rdexy*cos(alfa*grados);
			y=rdexy*sin(alfa*grados);
			rdexyz = sqrt(pow(x,2)+pow(y,2)+pow(z,2));
			rdexy = sqrt(pow(x,2)+pow(y,2));
			alfa4= radian*acos(x/rdexyz);
			beta4= radian*acos(z/rdexyz);
			gamma4= radian*acos(y/rdexyz);
			if (x<0&&y<0){
				alfa+=90;
			}else if (x==0&&y<0){
				alfa+=180;
			}else if (x>0&&y<0){
				alfa+=270;
			}else if (x==0&&y==0&&z==0){
				cout << "Ingresaste un vector nulo"<<endl; 
			}else if (x==0&&y==0){
				alfa=90;
				beta4=90;
			}
			cout << "En el sistema de coordenadas cartesianas (x,y,z) es:("<<x<<","<<y<<","<<z<<")" <<endl;				         
			cout << "En el sistema de coordenadas esfericas (r,alfa,beta) es:("<<rdexyz<<","<<alfa<<","<<beta4<<")" <<endl;
			cout << "En el sistema de coordenadas de cosenos directores (r,cos(alfa),cos(gamma),cos(beta) es:"<<
			endl<<"("<<rdexyz<<",cos("<<alfa4<<"),cos("<<gamma4<<"),cos("<<beta4<<")" <<endl;
		break;
			case 3:
			cout << "Elegiste el sistema de coordenadas esferico (r,alfa,beta)"<< endl;
			cout << "Ingresa el valor de r: "   ; cin >> rdexyz;
			cout << "Ingresa el valor de alfa (en grados): "; cin >> alfa;
			cout << "Ingresa el valor de beta (en grados): "; cin >> beta4;
			alfa *=grados;
			beta4 *=grados;
			x = rdexyz*cos(alfa)*sin(beta4);
			y = rdexyz*sin(alfa)*sin(beta4);
			z = rdexyz*cos(beta4);
			rdexy = sqrt(pow(x,2)+pow(y,2));
			beta4= acos(rdexy/z);
			beta4*=grados;
			alfa4= radian*acos(x/rdexyz);
			beta4= radian*acos(z/rdexyz);
			gamma4= radian*acos(y/rdexyz);
			alfa /=grados;
			if (x<0&&y<0){
				alfa+=90;
			}else if (x==0&&y<0){
				alfa+=180;
			}else if (x>0&&y<0){
				alfa+=270;
			}else if (x==0&&y==0&&z==0){
				cout << "Ingresaste un vector nulo"<<endl; 
			}else if (x==0&&y==0){
				alfa=90;
				beta4=90;
			}
			cout << "En el sistema de coordenadas cilindricas (r,alfa,z) es:("<<rdexy<<","<<alfa<<","<<z<<")" <<endl;				         
			cout << "En el sistema de coordenadas cartesianas (x,y,z) es:("<<x<<","<<y<<","<<z<<")" <<endl;
            cout << "En el sistema de coordenadas de cosenos directores (r,cos(alfa),cos(gamma),cos(beta) es:"<<
			endl<<"("<<rdexyz<<",cos("<<alfa4<<"),cos("<<gamma4<<"),cos("<<beta4<<")" <<endl;
		break;
		  	case 4:
		  	cout << "Elegiste el sistema de coordenadas de cosenos directores (r,cos(alfa),cos(beta),cos(gamma))"<< endl;
		  	cout << "Ingresa el valor de r:"; cin >> rdexyz;
			cout << "Ingresa el valor de alfa  (en grados): " ; cin >> alfa4;
			cout << "Ingresa el valor de beta  (en grados): " ; cin >> beta4;
			cout << "Ingresa el valor de gamma (en grados): "; cin >> gamma4;
			alfa4*=grados;
			gamma4*=grados;
			beta4*=grados;
			x= cos(alfa4)*rdexyz;
			y= cos(gamma4)*rdexyz;
			z= cos(beta4)*rdexyz;
			rdexy = sqrt(pow(x,2)+pow(y,2));
			alfa= acos(x/rdexy);
			alfa*=radian;
			beta4/=grados;
			if (x<0&&y<0){
				alfa+=90;
			}else if (x==0&&y<0){
				alfa+=180;
			}else if (x>0&&y<0){
				alfa+=270;
			}else if (x==0&&y==0&&z==0){
				cout << "Ingresaste un vector nulo"<<endl; 
			}else if (x==0&&y==0){
				alfa=90;
				beta4=90;
			}
			cout << "En el sistema de coordenadas cartesianas (x,y,z) es:("<<x<<","<<y<<","<<z<<")" <<endl;
			cout << "En el sistema de coordenadas cilindricas (r,alfa,z) es:("<<rdexy<<","<<alfa<<","<<z<<")" <<endl;				         
			cout << "En el sistema de coordenadas esfericas (r,alfa,beta) es:("<<rdexyz<<","<<alfa<<","<<beta4<<")" <<endl;
			
		break;
		}

	}else
			cout << "Para ejecutar debias ingresar un numero valido (Entre 1 y 4) "<<endl;
			

		system ("pause");
		return 0;
}