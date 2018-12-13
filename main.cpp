#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<fstream>
#include<ctime>
//poner global el archivo en la funcion de cada objeto editarlo y al final cerrar el archivo
using namespace std;

class Dado // La clase dado genera numeros aleatorios en los dados, ademas se sobrecarga para generar dos dados.
{   
	private:
		int dice;
	public:
		Dado();
	    ~Dado();
	    int get_dado();
		int operator +(Dado segundo);    
		     
};

Dado::Dado()
{
	dice = 1 + rand() % 6;
}

Dado::~Dado()
{
	
}

int Dado::get_dado()
{
	return dice;
}

int  Dado::operator +(Dado segundo)
{
	int suma;
	suma=dice+segundo.dice;
	return suma;
}

class Tablero // La clase tablero contiene la posicion en la que se encuentra el jugador.
{ 
	private:
		int posicion;
	public: 
		Tablero();
		void set_nueva(int);
		int get_posicion();
};

Tablero::Tablero()
{
	posicion = 1;	
}

void Tablero:: set_nueva(int nuev)
{
	int temp = 63;
	posicion = nuev;
	if (posicion > 63)
	{
		temp = posicion - temp;
		posicion = 63 - temp ;
	}
}

int Tablero::get_posicion()
{
	return posicion;
}

class Jugador;

void seleccion(Jugador *&player, Jugador *&player2);

class Casilla_Especial : public Tablero //La clase casilla especial define cuales son las casillas especiales para despues redefinirlas en la clase juego.
{
	public:
		virtual void Oca(Jugador *&player2) = 0;
		virtual void Puente(Jugador *&player2) = 0;
		virtual void Posada(Jugador *&player2) = 0;
		virtual void Laberinto() = 0;
		virtual void Carcel(Jugador *&player2) = 0;
		virtual void Dices() = 0;
		virtual void Calavera() = 0;
		virtual void Meta() = 0;	
};

class Jugador : public Casilla_Especial
{
	private:
		string nombre;
		int turno;
		int ficha;
	public:
		Jugador(string,int);
		~Jugador();
		void Puntaje();	
		friend void reiniciar(Jugador *&player1, Jugador *&player2);
		Jugador();
		void avanzar(int);
		void retroceder(int);
		void Oca(Jugador *&player2);
		void Puente(Jugador *&player2);
	    void Posada(Jugador *&player2);
		void Laberinto();
		void Carcel(Jugador *&player2);
		void Dices();
		void Calavera();
	 	void Meta();	
	    int get_turno();
	    bool completo();
	    void set_turno(int);
	    bool es_especial(int);
		inline string getname ()
		{
			return nombre;
		}
};

Jugador::Jugador(string _nombre, int  _ficha)
{
	nombre = _nombre;
	ficha = _ficha;
}

void Jugador::avanzar(int dado)
{
	int pos_ant = get_posicion();
	int nuevapos = pos_ant + dado;
	set_nueva (nuevapos);
}

void Jugador::Oca(Jugador *&player2)
{
	switch(get_posicion())
	{
		case 5:
			set_nueva(9);
			set_turno(0);
			player2 -> set_turno (1);
		break;
		
		case 9:
			set_nueva(14);
			set_turno(0);
			player2 -> set_turno (1);
		break;
		
		case 14:
			set_nueva(18);
			set_turno(0);
			player2 -> set_turno (1);
		break;
		
		case 18:
			set_nueva(23);
			set_turno(0);
			player2 -> set_turno (1);
		break;
		
		case 23:
			set_nueva(27);
			set_turno(0);
			player2 -> set_turno (1);
		break;
		
		case 27:
			set_nueva(32);
			set_turno(0);
			player2 -> set_turno (1);
		break;
		
		case 32:
			set_nueva(36);
			set_turno(0);
			player2 -> set_turno (1);
		break;
		
		case 36:
			set_nueva(41);
			set_turno(0);
			player2 -> set_turno (1);
		break;
		
		case 41:
			set_nueva(45);
			set_turno(0);
			player2 -> set_turno (1);
		break;
		
		case 45:
			set_nueva(50);
			set_turno(0);
			player2 -> set_turno (1);
		break;
	
		case 50:
			set_nueva(54);
			set_turno(0);
			player2 -> set_turno (1);
		break;
			
		case 54:
			set_nueva(59);
			set_turno(0);
			player2 -> set_turno (1);
		break;
	
		case 59:
			set_turno(0);
			player2 -> set_turno (1);
			// aqui se debera poner la si la suma es mayor que 63 restarle y set la posicion al resultado, si es igual a 63 gana, si es menor a 63 solo sumar y 
			// set una posicion nueva 
		break;
	}
}

void Jugador::Puente(Jugador *&player2)
{
	set_nueva(19);
	set_turno(2);
	player2 -> set_turno (0);
}

void Jugador::Posada(Jugador *&player2) //Posada: Casilla 19. Si se cae en esta casilla se pierde un turno.
{
	set_turno(2);
	player2 -> set_turno (0);
}

void Jugador::Laberinto()
{
	set_nueva(30);
}

void Jugador::Carcel(Jugador *&player2)
{
	set_turno(3);
	player2 -> set_turno (0);
}

void Jugador::Dices()
{
	if(get_posicion() == 26)
	{
		set_nueva(26);
	}
	else if (get_posicion() == 53) // falta validar esta parte ademas que cuando se pase de 63 le reste las posiciones. ESTO YA SE IMPLEMENTO EN set_nueva
	{
		set_nueva(53);
	}
}
void Jugador::Calavera()
{
	set_nueva(1);
}

void Jugador::Meta()
{
	set_nueva(63);
}

int Jugador::get_turno()
{
	return turno;
}

void Jugador::set_turno(int turn)
{
	turno=turn;
}

bool Jugador::completo()
{
	if (get_posicion() == 63)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Jugador::es_especial(int casilla)
{
	switch(casilla)
	{
		case 5:
			return true;
		break;
	
		case 6:
			return true;
		break;
		
		case 9:
			return true;
		break;
	
		case 12:
			return true;
		break;
	
		case 14:
			return true;
		break;
		
		case 18:
			return true;
		break;
	
		case 19:
			return true;
		break;
			
		case 23:
			return true;
		break;
		
		case 26:
			return true;
		break;
			
		case 27:
			return true;
		break;
			
		case 32:
			return true;
		break;
			
		case 36:
			return true;
		break;
			
		case 41:
			return true;
		break;
			
		case 42:
			return true;
		break;
			
		case 45:
			return true;
		break;
		
		case 50:
			return true;
		break;
			
		case 53:
			return true;
		break;
			
		case 54:
			return true;
		break;
			
		case 56:
			return true;
		break;
			
		case 58:
			return true;
		break;
			
		case 59:
			return true;
		break;
		    
		default: 
			return false;
    	break;
	}
}

void Jugador::retroceder(int casillas)
{
	int pos_ant = get_posicion();
	int nuevapos = pos_ant - casillas;
	set_nueva (nuevapos);
}

Jugador::~Jugador()
{
	nombre = " ";
	turno = 0;
	ficha = 0;
}

int main()
{
	ofstream records;
	std::time_t t = std::time(0);   // obtener fecha de hoy
    std::tm* now = std::localtime(&t);
	
	
	srand(time(NULL));
	string jug1,jug2;
	int dados,tirar,jug,tmp,tmp2;
	Jugador *player1, *player2;
	do
	{
		cout << "Nombre del jugador 1" << endl;
		fflush(stdin);
		getline(cin,jug1);
		cout << "Nombre del jugador 2" << endl;
		fflush(stdin);
		getline(cin,jug2);
		player1 = new Jugador(jug1,1); //color 1 ficha azul
		player2 = new Jugador(jug2,2); // color 2 ficha roja
		player1 -> set_turno (0);
		player2 -> set_turno (1);
		Dado *uno=new Dado();
		Dado *dos=new Dado();
  		cout << " " << uno -> get_dado() << endl;
  		cout << " " << dos -> get_dado() << endl;
		cout << player1 -> get_posicion() << " " << player2 -> get_posicion() << endl;
		do
		{
			if(player1->get_turno() == 0 && player2 -> get_turno() != 0) //jugador 1 jugara si el jugador 2 no esta en turno
			{
				cout<<"Ingrese 1 para tirar dados " << player1 -> getname() << endl;
				cin>>tirar;
				if(tirar==1)
				{
					uno=new Dado();
					dos =new Dado();
					dados = *uno + *dos; // poner un boton para inicializar los dados
					cout << player1 -> getname() << " Ah sacado " << dados << " Su posicion actual es " << player1 -> get_posicion();
					player1 -> avanzar (dados);
					if(player1 -> es_especial (player1 -> get_posicion() ) == true) // faltara if que decrementara turno del contrario
					{ 
						cout << " Es una posicion especial";
						seleccion(player1, player2); //hacer lo mismo para el jugador 2
					}
					else if (player2 -> get_turno() == 1)
					{
						player1->set_turno(1); // termina el turno
						player2 -> set_turno (0);
					}
				
					cout << " Termina en la posicion " << player1 -> get_posicion() << endl;
				}
				else
				{
					cout<<"No se han tirado los dados"<<endl;
				}
				if (player2 -> get_turno () > 1)
				{
					cout << "Reduce turno" << player2 -> get_turno ();
					tmp = player2 -> get_turno ();
					tmp --;
					player2 -> set_turno (tmp);
				}
			cout << endl;
			}
			else if (player1->get_turno() != 0 && player2->get_turno() == 0) //jugador 2 jugara si el jugador 1 no esta en turno
			{ 
				cout<<"Ingrese 1 para tirar dados " << player2 -> getname() << endl;
				cin>>tirar;
				if(tirar==1)
				{
					uno=new Dado();
					dos =new Dado();
					dados= *uno + *dos; 
					cout << player2 -> getname() << " Ah sacado " << dados   << " Su posicion actual es " << player2 -> get_posicion();
					player2 -> avanzar (dados);
					if (player2->es_especial(player2->get_posicion())==true) // faltara if que decrementara turno del contrario
					{
						cout << " Es una posicion especial";
						seleccion(player2, player1); //hacer lo mismo para el jugador 2
					}
					else if (player1 -> get_turno() == 1)
					{
						player1->set_turno(0); // termina el turno
						player2 -> set_turno (1);
					}
					cout << " Termina en la posicion " << player2 -> get_posicion() << endl;
				}
				
				else 
				{
					cout<<"No se han tirado los dados"<<endl;
				}	
				if (player1 -> get_turno () > 1)
				{
					cout << "Reduce turno" << player1 -> get_turno ();
					tmp = player1 -> get_turno ();
					tmp --;
					player1 -> set_turno (tmp);
				}
				cout << endl;
			}
		}while (player1 -> completo() != true && player2 -> completo() != true);
		cout << "Juego terminado ";
		if (player1 -> completo() == true)
		{//abrir aqui el archivo y poner los nombres
		   records.open("Records.txt",ios::app);
		   	if(records.fail()){
		   		cout<<"Error de archivo"<<endl;
			   }
			   records<<"Ganador -> "<<player1->getname()<<" - "<<" Fecha de juego: "<<" - "<<(now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-'<<  now->tm_mday<<endl;
			   records<<"Segundo Lugar -> "<<player2->getname()<<" - "<<" Fecha de juego: "<<" - "<<(now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-'<<  now->tm_mday<<endl;
			   records.close();
		
			cout << player1 -> getname();
		}
		if (player2 -> completo() == true)
		{
			records.open("Records.txt",ios::app);
		   	if(records.fail()){
		   		cout<<"Error de archivo"<<endl;
			   }
			   records<<"Ganador -> "<<player2->getname()<<" - "<<" Fecha de juego: "<<" - "<<(now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-'<<  now->tm_mday<<endl;
			   records<<"Segundo Lugar -> "<<player1->getname()<<" - "<<" Fecha de juego: "<<" - "<<(now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-'<<  now->tm_mday<<endl;
			   records.close();
			cout << player2 -> getname();
		}
		cout << " a ganado, ¿Quieren volver a jugar?" << endl << "01 - Si" << endl << "Otro - No" << endl;
		cin >> tmp2;
		if (tmp2 == 1)
		{
			player1->set_turno(0);
			player2 -> set_turno (1);
			reiniciar (player1, player2);
		}
	} while (tmp2 == 1);
	player1 -> ~Jugador ();
	player2 -> ~Jugador ();
	return 0;
}

void seleccion(Jugador *&player1, Jugador *&player2)
{
	Dado *one=new Dado();
	Dado *two=new Dado();
	int dices= *one+*two;
	switch (player1->get_posicion())
	{
		case 5:
			player1 ->Oca(player2);
			cout << " La Oca ";
		break;

		case 6:
			player1->Puente(player2);
			cout << " El puente " << endl;
		break;
	
		case 9:
			player1->Oca(player2);
			cout << " La Oca ";
		break;
	
		case 12:
			player1->Puente(player2);
			cout << " El puente ";
		break;
	
		case 14:
			player1->Oca(player2);
			cout << " La Oca ";
		break;
	
		case 18:
			player1->Oca(player2);
			cout << " La Oca ";
		break;
			
		case 19:
			player1->Posada(player2);
			cout << " La Posada " << endl;
		break;
	
		case 23:
			player1->Oca(player2);
			cout << " La Oca ";
		break;
			
		case 26:
			player1->Dices();
			cout << " Los dados ";
		break;
			
		case 27:
			player1->Oca(player2);
			cout << " La Oca ";
		break;
		
		case 32:
			player1->Oca(player2);
			cout << " La Oca ";
		break;

		case 36:
			player1->Oca(player2);
			cout << " La Oca ";
		break;
		
		case 41:
			player1->Oca(player2);
			cout << " La Oca ";
		break;
		
		case 42:
			player1->Laberinto();
			cout << " El laberinto ";
		break;
			
		case 45:
			player1->Oca(player2);
			cout << " La Oca ";
		break;
		
		case 50:
			player1->Oca(player2);
			cout << " La Oca ";
		break;
	
		case 53:
			player1->Dices();
			cout << " Los dados ";
		break;
			
		case 54:
			player1->Oca(player2);
			cout << " La Oca ";
		break;
				
		case 56:
			player1->Carcel(player2);
			cout << " La Carcel ";
		break;
		
		case 58:
			player1->Calavera();
			cout << " La Calavera ";
		break;
		
		case 59:
			player1->Oca(player2);
			cout << " La Oca ";
		break;
	}
}

void reiniciar(Jugador *&player1, Jugador *&player2)
{
	player1 -> set_nueva (1);
	player2 -> set_nueva (1);
}
