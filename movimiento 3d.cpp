#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;


int redondear(float _x);
int redondear(float _x)
{
	int _y;
	if(_x-int(_x)>0.5)
	{
		_y=int(_x)+1;
	}
	else
	{
		_y=int(_x);
	}
	return _y;
}

char dibLin(char _imag[50][50], int _x[2], int _y[2], int _i, int _w);
char dibLin(char _imag[50][50], int _x[2], int _y[2], int _i, int _w)
{
	
	int b;         //b viene de burbuja, sirve para permutar dos valores
	float h, w, z; //h= hight/altura   w=with/anchura z= es el ratio en el que la linea va subiendo o bajando (dificil de explicar)
	
	/*
	 cout<<"_x[0]: "<<_x[0]<<" _x[1]: "<<_x[1]<<endl;
	 cout<<"_y[0]: "<<_y[0]<<" _y[1]: "<<_y[1]<<endl;
	*/
	
	
	
	//cout<<"1  _x[0]: "<<_x[0]<<" _x[1]: "<<_x[1]<<endl;
	
	if(_x[0]<_x[1])   //hacemos que el mas alto sea el primero (el que tiene el valor de x mas alto, en el caso de mi forma de dibujarlo, el de mayor x es el que esta mas abajo)
	{
		//cout<<"permutar"<<endl;
		b=_x[0];
		_x[0]=_x[1];
		_x[1]=b;
		
		b=_y[0];
		_y[0]=_y[1];
		_y[1]=b;
	}
	
	
	//cout<<"2  _x[0]: "<<_x[0]<<" _x[1]: "<<_x[1]<<endl;
	//cout<<"2  _y[0]: "<<_y[0]<<" _y[1]: "<<_y[1]<<endl;
	
	
	h=_x[0]-_x[1];
	if(_y[0]<=_y[1])
	{
		w=_y[1]-_y[0];
		if(w>=h && w!=0 && h!=0)
		{
			z=(w+1)/(h+1);
		}
		else if(w<h && w!=0 && h!=0)
		{
			z=(h+1)/(w+1);
		}
		else if(w==0 || h==0)
		{
			z=0;
		}
		if(h>w)
		{
			//cout<<"a"<<endl;
			for(float x=0, y=w, c=z; x<=h; x++)
			{
				if(x>=redondear(c))
				{
					c+=z;
					if(z!=0)
					{
						y--;
					}
				}
				if(int(x+_x[1])<50 && int(x+_x[1])>=0 && int(y+_y[0])<50 && int(y+_y[0])>=0)
					_imag[int(x+_x[1])][int(y+_y[0])]='x';
			}
		}
		else
		{
			//cout<<"b"<<endl;
			for(float x=h, y=0, c=z; y<w; y++)
			{
				if(y>=redondear(c))
				{
					c+=z;
					if(z!=0)
					{
						x--;
					}
				}
				if(int(x+_x[1])<50 && int(x+_x[1])>=0 && int(y+_y[0])<50 && int(y+_y[0])>=0)
					_imag[int(x+_x[1])][int(y+_y[0])]='x';
			}
		}
	}
	else
	{
		w=_y[0]-_y[1];
		if(w>=h&&w!=0&&h!=0)
		{
			z=(w+1)/(h+1);
		}
		else if(w<h&&w!=0&&h!=0)
		{
			z=(h+1)/(w+1);
		}
		else if(w==0||h==0)
		{
			z=0;
		}
		//cout<<"h: "<<h<<" w: "<<w<<endl;
		if(h>w)
		{
			//cout<<"c"<<endl;
			for(float x=0, y=0, c=z; x<=h; x++)
			{
				if(x>=redondear(c))
				{
					c+=z;
					if(z!=0)
					{
						y++;
					}
				}
				if(int(x+_x[1])<50 && int(x+_x[1])>=0 && int(y+_y[1])<50 && int(y+_y[1])>=0)
					_imag[int(x+_x[1])][int(y+_y[1])]='x';
			}
		}
		else
		{
			//cout<<"d"<<endl;
			for(float x=0, y=0, c=z; y<w; y++)
			{
				if(y>=redondear(c))
				{
					c+=z;
					if(z!=0)
					{
						x++;
					}
				}
				if(int(x+_x[1])<50 && int(x+_x[1])>=0 && int(y+_y[1])<50 && int(y+_y[1])>=0)
					_imag[int(x+_x[1])][int(y+_y[1])]='x';
			}
		}
	}
	
	
	/*
	_imag[_x[0]][_y[0]]='o';
	_imag[_x[1]][_y[1]]='q';
	*/
	
	
	return _imag[_i][_w];
}


int main()
{
	                        
	int verticesEnPantalla[8][2];  // verticesEnLaPantalla te dice las coordenadas de cada vertice en la pantalla (lol) los primeros [] dicen que vertice es, los segundos [] dicen si habals de x o y (x=0 y=1)
	int conexiones[12][2];         //conexiones dice cue vertices van conectadas con cuales otras, el primer [] dice si es la primera, segunda, tercera, etc conexion y el segundo [] te dice cual vertice va con cual otra (el valor de X y Y de estas vertices esta en verticesEnLaPantalla)
	int cDeVertices=8;             //cantidad de vertices en total (esta variable y la de abajo  hace que el programa sea mas flexible y facil de cambiar)
	int cDeConexiones=12;	       //cantidad de lineas            (esta variable y la de arriba hace que el programa sea mas flexible y facil de cambiar)
	
	/*
	int inclinacionH=90;              //inclinacion de las vertices horizontalmente
	int inclinacionV=90;              //inclinacion de las vertices verticalmente
	*/
	
	
	float vertices[8][3];          //vertices son las esquinas de las figuras en las 3 dimenciones (los primeros [] son  para saber que esquina es, el siguiente es para saber el valor de cada esquina [0=x, 1=y, 2=z])
	float prop;                    //prop es la proporcion entre la coordenada Y y Z de una vetice (usado en "case '4'" y "case '6'" para girar el mapa)   prop, longitud y inclinacion seran 
	float longitud;                //longitud es la hipotenusa de una vertice                      (usado en "case '4'" y "case '6'" para girar el mapa)   removidos cuando esto pase a ser
	float inclinacion;             //inclinacion de la vertice que estoy calculando                (usado en "case '4'" y "case '6'" para girar el mapa)   una funcion en vez de codigo en main
	
	
	char imag[50][50];             //imag es lo que se mostrara por pantalla mas tarde
	char mov;                      //el ultimo boton que apreto el jugador
	
	
	for(int x=0; x<50; x++)        //un for para ya darle un valor a cada parte de imag
		for(int y=0; y<50; y++)
			imag[x][y]=' ';
	
	
	// hard-coded conexiones y vertices
	conexiones[0][0]=0;
	conexiones[0][1]=1;
	
	conexiones[1][0]=1;
	conexiones[1][1]=2;
	
	conexiones[2][0]=2;
	conexiones[2][1]=3;
	
	conexiones[3][0]=3;
	conexiones[3][1]=0;
	
	conexiones[4][0]=4;
	conexiones[4][1]=5;
	
	conexiones[5][0]=5;
	conexiones[5][1]=6;
	
	conexiones[6][0]=6;
	conexiones[6][1]=7;
	
	conexiones[7][0]=7;
	conexiones[7][1]=4;
	
	conexiones[8][0]=0;
	conexiones[8][1]=4;
	
	conexiones[9][0]=1;
	conexiones[9][1]=5;
	
	conexiones[10][0]=2;
	conexiones[10][1]=6;
	
	conexiones[11][0]=3;
	conexiones[11][1]=7;
	
	
	//declarar las coordenadas de las vertices del cubo
	vertices[0][0]=-3;  //x  alto
	vertices[0][1]=-3;  //y  ancho
	vertices[0][2]=3;   //z  profundo
	
	vertices[1][0]=-3;  //x
	vertices[1][1]=-3;  //y
	vertices[1][2]=9;   //z
	
	vertices[2][0]=-3;  //x
	vertices[2][1]=3;   //y
	vertices[2][2]=9;   //z
	
	vertices[3][0]=-3;  //x
	vertices[3][1]=3;   //y
	vertices[3][2]=3;   //z
	
	vertices[4][0]=3;   //x
	vertices[4][1]=-3;  //y
	vertices[4][2]=3;   //z
	
	vertices[5][0]=3;   //x
	vertices[5][1]=-3;  //y
	vertices[5][2]=9;   //z
	
	vertices[6][0]=3;   //x
	vertices[6][1]=3;   //y
	vertices[6][2]=9;   //z
	
	vertices[7][0]=3;   //x
	vertices[7][1]=3;   //y
	vertices[7][2]=3;   //z
	
	while(1==1){
		for(int x=0; x<50; x++)  //cada loop se vuelven a dibujar todas las aristas sobre imag, esto "vacia" la variable para que esto funcione
			for(int y=0; y<50; y++)
				imag[x][y]=' ';
		
		
		
		for(int x=0; x<cDeVertices; x++){                                                //calcular cada vertice(3D) en la pantalla(2D)
			if(vertices[x][2] > 0 ){
				verticesEnPantalla[x][0]=redondear(vertices[x][0]*(1/(vertices[x][2]))*20);
				verticesEnPantalla[x][1]=redondear(vertices[x][1]*(1/(vertices[x][2]))*20);
				
			//	cout<<x<<" calculo1: "<<vertices[x][0]*(1/(vertices[x][2]))<<"  +25: "<<vertices[x][0]*(1/(vertices[x][2]))+25<<endl;
			//	cout<<x<<" calculo2: "<<vertices[x][1]*(1/(vertices[x][2]))<<"  +25: "<<vertices[x][1]*(1/(vertices[x][2]))+25<<endl;
			//	cout<<x<<" verticese posicion1: "<<verticesEnPantalla[x][0]<<endl;
			//	cout<<x<<" verticese posicion2: "<<verticesEnPantalla[x][1]<<endl<<endl<<endl;                                         
				
				if((verticesEnPantalla[x][0]+25) >= 0 && (verticesEnPantalla[x][0]+25) < 50 && (verticesEnPantalla[x][1]+25) >= 0 && (verticesEnPantalla[x][1]+25) < 50 && vertices[x][2] >= 0)
					imag[verticesEnPantalla[x][0]+25][verticesEnPantalla[x][1]+25]='V';
			}
		}
		
		
		
		
		
		
		for(int xs[2], ys[2], i=0; i<cDeConexiones; i++){                      //dibujar lineas entre vertices
			for(int x=0; x<50; x++){
				for(int y=0; y<50; y++){
					if(vertices[ conexiones[i][0] ][2] > 0 || vertices[ conexiones[i][1] ][2] > 0 ){
						// cout<<"i: "<<i<<" x: "<<x<<" y: "<<y<<endl;
						xs[0]=verticesEnPantalla[conexiones[i][0]][0]+25; //xs son los valores de x de ambas vertices
						xs[1]=verticesEnPantalla[conexiones[i][1]][0]+25;
						
						ys[0]=verticesEnPantalla[conexiones[i][0]][1]+25; //ys son los valores de y de ambas vertices
						ys[1]=verticesEnPantalla[conexiones[i][1]][1]+25;
						/* 
						cout<<"a verticesEnPantalla1x : "<<verticesEnPantalla[conexiones[i][0]] [0] +25<<"    xs1:"<<xs[0]<<endl;
						cout<<"a verticesEnPantalla2x : "<<verticesEnPantalla[conexiones[i][1]] [0] +25<<"    xs2:"<<xs[1]<<endl;
						cout<<"a verticesEnPantalla1y : "<<verticesEnPantalla[conexiones[i][0]] [1] +25<<"    ys1:"<<ys[0]<<endl;
						cout<<"a verticesEnPantalla2y : "<<verticesEnPantalla[conexiones[i][1]] [1] +25<<"    ys2:"<<ys[1]<<endl;
						*/
						imag[x][y]=dibLin(imag, xs, ys, x, y);
					}
				}
			}
		}
		
		
		
		
	//	cout<<"--------------------------------------------"<<endl;
		for(int x=0; x<50; x++){
			for(int y=0; y<50; y++)
				cout<<imag[x][y]<<" ";
			cout<<endl;
		}
	//	cout<<"--------------------------------------------"<<endl;
		
		
		/*
		
		for(int x=0; x<cDeVertices; x++){
			for(int y=0; y<3; y++)
				cout<<"vertices["<<x<<"]["<<y<<"] : "<<vertices[x][y]<<endl;
			cout<<endl;
		}
		
		
		
		for(int x=0; x<cDeVertices; x++){
			for(int y=0; y<2; y++)
				cout<<"verticesEnPantalla["<<x<<"]["<<y<<"] : "<<verticesEnPantalla[x][y]<<endl;
			cout<<endl;
		}
		
		
		*/
		
		
		mov=getch();
		switch(mov){
			case 'w':{                              //mover camara adelante
				for(int x=0; x<cDeVertices; x++){
					vertices[x][2]-=0.5;
				}
				break;
			}
			case 'a':{                              //mover camara izquierda
				for(int x=0; x<cDeVertices; x++){
					vertices[x][1]+=0.5;
				}
				break;
			}
			case 's':{                              //mover camara atras
				for(int x=0; x<cDeVertices; x++){
					vertices[x][2]+=0.5;
				}
				break;
			}
			case 'd':{                              //mover camara derecha
				for(int x=0; x<cDeVertices; x++){
					vertices[x][1]-=0.5;
				}
				break;
			}
			case 'i':{                              //inclinar camara adelante
				for(int x=0; x<cDeVertices; x++){
				//	cout << "x(for): " << x << endl;
					
					longitud = sqrt( pow( vertices[x][0], 2 ) + pow( vertices[x][2], 2 ) ); // saco la hipotenusa
					
					inclinacion = (0 - vertices[x][2]) / (0 - vertices[x][0]);// <---    y2 - y1
				//	                                                                    _________
				//	                                                                     x2 - x1
				
				//	cout << "incl: " << inclinacion <<endl;
					
					inclinacion = atan( inclinacion );
					
					vertices[x][0] = cos( inclinacion + 0.174533 );       //saco Y con la nueva inclinacion    0.174533 radianes son 10 grados
					vertices[x][2] = sin( inclinacion + 0.174533 );       //saco Z con la nueva inclinacion  
					
					if(inclinacion<0.174533){        // si haces sin() o cos() de un numero negativo te da lo mismo que si fuece positivo, aca arreglo eso
						vertices[x][0]*= -1;
						vertices[x][2]*= -1;
					}
					   
					
					vertices[x][0]*= longitud;                  //hago que las nuevas coordenadas tengan el mismo tamaño que la original
					vertices[x][2]*= longitud;
				}
				break;
			}
			case 'j':{                              //girar camara izquierda
				for(int x=0; x<cDeVertices; x++){
				//	cout << "x(for): " << x << endl;
					
					longitud = sqrt( pow( vertices[x][1], 2 ) + pow( vertices[x][2], 2 ) ); // saco la hipotenusa
					
					inclinacion = (0 - vertices[x][2]) / (0 - vertices[x][1]);// <---    y2 - y1           saco una inclinacion en pendiente, no en radianes ni grados
				//	                                                                    _________
				//	                                                                     x2 - x1
				
				//	cout << "incl: " << inclinacion <<endl;
					
					inclinacion = atan( inclinacion ); // por alguna razon arcotangente transforma pendiente en radianes
					
				//	cout << "incl tan: " << inclinacion <<endl;
					
					while(inclinacion<0){
						inclinacion+=3.14159265359;
					}
					
					while(inclinacion>3.14159265359){
						inclinacion-=3.14159265359;
					}
					
					vertices[x][1] = cos( inclinacion - 0.174533 );       //saco Y con la nueva inclinacion    0.174533 radianes son 10 grados
					vertices[x][2] = sin( inclinacion - 0.174533 );       //saco Z con la nueva inclinacion  
					/*
					if(inclinacion<0.174533){         // si haces sin() o cos() de un numero negativo te da lo mismo que si fuece positivo, aca arreglo eso
						vertices[x][1] *= -1;
						vertices[x][2] *= -1;
					}
					*/
					vertices[x][1]*= longitud;                  //hago que las nuevas coordenadas tengan el mismo tamaño que la original
					vertices[x][2]*= longitud;
				}
				//system("pause");
				break;
			}
			case 'k':{                              //inclinar camara atras
				for(int x=0; x<cDeVertices; x++){
				//	cout << "x(for): " << x << endl;
					
					longitud = sqrt( pow( vertices[x][0], 2 ) + pow( vertices[x][2], 2 ) ); // saco la hipotenusa
					
					inclinacion = (0 - vertices[x][2]) / (0 - vertices[x][0]);// <---    y2 - y1
				//	                                                                    _________
				//	                                                                     x2 - x1
				
				//	cout << "incl: " << inclinacion <<endl;
					
					inclinacion = atan( inclinacion );
					
					vertices[x][0] = cos( inclinacion - 0.174533 );       //saco Y con la nueva inclinacion    0.174533 radianes son 10 grados
					vertices[x][2] = sin( inclinacion - 0.174533 );       //saco Z con la nueva inclinacion  
					
					if(inclinacion<0.174533){        // si haces sin() o cos() de un numero negativo te da lo mismo que si fuece positivo, aca arreglo eso
						vertices[x][0]*= -1;
						vertices[x][2]*= -1;
					}
					   
					
					vertices[x][0]*= longitud;                  //hago que las nuevas coordenadas tengan el mismo tamaño que la original
					vertices[x][2]*= longitud;
				}
				break;
			}
			case 'l':{                              //girar camara derecha
				for(int x=0; x<cDeVertices; x++){
				//	cout<<"x(for): "<<x<<endl;
					longitud = sqrt( pow( vertices[x][1], 2 ) + pow( vertices[x][2], 2 ) ); // saco la hipotenusa
					
					inclinacion = (0 - vertices[x][2]) / (0 - vertices[x][1]);// <---    y2 - y1
				//	                                                                    _________
				//	                                                                     x2 - x1
				
				//	cout<< "incl: " << inclinacion << endl;
					inclinacion = atan( inclinacion );
					
					vertices[x][1] = cos( inclinacion + 0.174533);       //saco Y con la nueva inclinacion    0.174533 radianes son 10 grados
					vertices[x][2] = sin( inclinacion + 0.174533);       //saco Z con la nueva inclinacion  
					
					if(inclinacion<0.174533){        // si haces sin() o cos() de un numero negativo te da lo mismo que si fuece positivo, aca arreglo eso
						vertices[x][1]*= -1;                                   
						vertices[x][2]*= -1;
					}
					   
					
					vertices[x][1]*= longitud;                  //hago que las nuevas coordenadas tengan el mismo tamaño que la original
					vertices[x][2]*= longitud;
				}
				break;
			}
			/*
			
			case 'u':{                              //inclinar camara izquierda
				for(int x=0; x<cDeVertices; x++){
				//	cout << "x(for): " << x << endl;
					
					longitud = sqrt( pow( vertices[x][0], 2 ) + pow( vertices[x][1], 2 ) ); // saco la hipotenusa
					
					inclinacion = (0 - vertices[x][1]) / (0 - vertices[x][0]);// <---    y2 - y1
				//	                                                                    _________
				//	                                                                     x2 - x1
				
				//	cout << "incl: " << inclinacion <<endl;
					
					inclinacion = atan( inclinacion );
					
					vertices[x][0] = cos( inclinacion - 0.174533 );       //saco Y con la nueva inclinacion    0.174533 radianes son 10 grados
					vertices[x][1] = sin( inclinacion - 0.174533 );       //saco Z con la nueva inclinacion  
					
					if(inclinacion<0){        // si haces sin() o cos() de un numero negativo te da lo mismo que si fuece positivo, aca arreglo eso
						vertices[x][0]*= -1;
						vertices[x][1]*= -1;
					}
					   
					
					vertices[x][0]*= longitud;                  //hago que las nuevas coordenadas tengan el mismo tamaño que la original
					vertices[x][1]*= longitud;
				}
				break;
			}
			case 'o':{                              //inclinar camara derecha
				for(int x=0; x<cDeVertices; x++){
				//	cout << "x(for): " << x << endl;
					
					longitud = sqrt( pow( vertices[x][0], 2 ) + pow( vertices[x][1], 2 ) ); // saco la hipotenusa
					
					inclinacion = (0 - vertices[x][1]) / (0 - vertices[x][0]);// <---    y2 - y1
				//	                                                                    _________
				//	                                                                     x2 - x1
				
				//	cout << "incl: " << inclinacion <<endl;
					
					inclinacion = atan( inclinacion );
					
					vertices[x][0] = cos( inclinacion - 0.174533 );       //saco Y con la nueva inclinacion    0.174533 radianes son 10 grados
					vertices[x][1] = sin( inclinacion - 0.174533 );       //saco Z con la nueva inclinacion  
					
					if(inclinacion<0){        // si haces sin() o cos() de un numero negativo te da lo mismo que si fuece positivo, aca arreglo eso
						vertices[x][0]*= -1;
						vertices[x][1]*= -1;
					}
					   
					
					vertices[x][0]*= longitud;                  //hago que las nuevas coordenadas tengan el mismo tamaño que la original
					vertices[x][1]*= longitud;
				}
				break;
			}
			*/
		}
		
		system("cls");
		
	}
	
	
	
	return 0;
	
	
}
