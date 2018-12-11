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
	  int turno;
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
	     bool completo();
	     void set_turno(int);
		 
	     
};
Juego::Juego(){
}
void Juego::avanzar(int dado){
	int pos_ant=Tablero::get_posicion();
	 int nuevapos=pos_ant+dado;
	 Tablero::set_nueva(nuevapos);
}
void Juego::Oca(){
	switch(get_posicion()){
			case 5:
				set_nueva(9);
				break;
			case 9:
				set_nueva(14);
				break;
			case 14:
				set_nueva(18);
				break;
			case 18:
				set_nueva(23);
				break;
			case 23:
				set_nueva(27);
				break;
			case 27:
				set_nueva(32);
				break;
			case 32:
				set_nueva(36);
				break;
			case 36:
				set_nueva(41);
				break;
			case 41:
				set_nueva(45);
				break;
			case 45:
				set_nueva(50);
				break;
			case 50:
				set_nueva(54);
				break;
			case 54:
				set_nueva(59);
				break;
			case 59:
		        break;
		
	}

}
void Juego::Puente(){
	if(get_posicion()==6||get_posicion()==12){
		set_nueva(19);
		set_turno(1);
	}
}
void Juego::Posada(){
	set_turno(1);
}
void Juego::Laberinto(){
	set_nueva(30);
}
void Juego::Carcel(){
	set_turno(1);
}
void Juego::Dices(){
	if(get_posicion()==26){
		set_nueva(26);
	}else if(get_posicion()==53){
		set_nueva(53);
	}
}
void Juego::Calavera(){
	set_nueva(1);
}
void Juego::Meta(){
	set_nueva(63);
}
int Juego::get_turno(){
	return turno;
}
void Juego::set_turno(int turn){
	turno=turn;
}
bool Juego::completo(){
	if(get_posicion()==63){
		return true;
	}
	else{
		return false;
	}
}
class Jugador : public Juego{
	friend reiniciar(Jugador *);
	private:
		string nombre;
		int ficha;
	public:
	  Jugador(string,int);
	  ~Jugador();
	  void Puntaje();		
	
};
Jugador::Jugador(string _nombre,int  _ficha){
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
	Dado *dos=new Dado();
	cout<<"Nombre del jugador 1"<<endl;
	getline(cin,jug1);
		fflush(stdin);
	cout<<"Nombre del jugador 2"<<endl;
		fflush(stdin);
		getline(cin,jug2);
	
	Jugador *player1=new Jugador(jug1,1);
	Jugador *player2=new Jugador(jug2,2);

  dados=*uno+*dos;
  cout<<" "<<uno->get_dado()<<endl;
  cout<<" "<<dos->get_dado()<<endl;
		
do{
	
}while(player1->completo()!=true&&player2->completo()!=true);
  	
	return 0;
}
