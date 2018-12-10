#include<iostream>
#include<time.h>
#include<stdlib.h>
//poner global el archivo en la funcion de cada objeto editarlo y al final cerrar el archivo
using namespace std;
class Dado{   // La clase dado genera numeros aleatorios en los dados, ademas se sobrecarga para generar dos dados.
	private:
		int dice;
	public:
		Dado();
	    ~Dado();
	       int get_dado();
		   int operator +(Dado segundo);    
		     
};
Dado::Dado(){
		dice=1+rand()%(6);
}
Dado::~Dado(){
	
}
int Dado::get_dado(){
	return dice;
}
int  Dado::operator +(Dado segundo){
	int suma;
	suma=dice+segundo.dice;
	return suma;
}
class Tablero{ // La clase tablero contiene la posicion en la que se encuentra el jugador.
	private:
		int posicion;
	public: 
	Tablero();
	void set_nueva(int);
	int get_posicion();
};
Tablero::Tablero(){
	posicion=0;
	
}
void Tablero:: set_nueva(int nuev){
	posicion=nuev;
}
int Tablero::get_posicion(){
	return posicion;
}
class Casilla_Especial : public Tablero{ //La clase casilla especial define cuales son las casillas especiales para despues redefinirlas en la clase juego.
			public:
				virtual void Oca()=0;
				virtual void Puente()=0;
				virtual void Posada()=0;
				virtual void Laberinto()=0;
				virtual void Carcel()=0;
				virtual void Dices()=0;
				virtual void Calavera()=0;
				virtual void Meta()=0;	
};
class Juego : public Casilla_Especial{
	private:
	  bool turno;
	public:
		Juego();
		 void avanzar(int);
		 void Oca();
		 void Puente();
	     void Posada();
		 void Laberinto();
		 void Carcel();
		 void Dices();
		 void Calavera();
	 	 void Meta();	
	     int get_turno();
	     void set_turno(bool);
		 
	     
};
Juego::Juego(){
}
void Juego::avanzar(int dado){
	int pos_ant=Tablero::get_posicion();
	 int nuevapos=pos_ant+dado;
	 Tablero::set_nueva(nuevapos);
}
void Juego::Oca(){
	
	
	
}
void Juego::Puente(){
	if(get_posicion()==6||get_posicion()==12){
		set_nueva(19);
		
	}
}
void Juego::Posada(){
	set_turno(false);
}
void Juego::Laberinto(){
	
}
void Juego::Carcel(){
	
}
void Juego::Dices(){
	
}
void Juego::Calavera(){
	
}
void Juego::Meta(){
	
}
int Juego::get_turno(){
	return turno;
}
void Juego::set_turno(bool turn){
	turno=turn;
}
class Jugador : public Juego{
	friend reiniciar(Jugador *);
	private:
		string nombre;
		bool ficha;
	public:
	  Jugador(string,bool);
	  ~Jugador();
	  void Puntaje();		
	
};
Jugador::Jugador(string _nombre,bool _ficha){
	nombre=_nombre;
	ficha=ficha;
}
Jugador::~Jugador(){
}

int main(){
	srand(time(NULL));
	string jug1,jug2;
	int dados;
	Dado *uno=new Dado();
	Dado *segundo=new Dado();
	cout<<"Nombre del jugador 1"<<endl;
	getline(cin,jug1);
		fflush(stdin);
	cout<<"Nombre del jugador 2"<<endl;
		fflush(stdin);
		getline(cin,jug2);
	
	Jugador *player1=new Jugador(jug1,true);
	Jugador *plyaer2=new Jugador(jug2,false);

  dados=*uno+*segundo;
  cout<<" "<<uno->get_dado()<<endl;
  cout<<" "<<segundo->get_dado()<<endl;
  	 cout<<""<<dados;
	return 0;
}
