
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
	  int turno; //turno en 0 quiere decir que puede jugar , turno en 1 que esta en espera por 1 turno , turno en ; espera de dos turnos
	public:
		Juego();
		 void avanzar(int);
		 void retroceder(int);
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
	     bool es_especial(int);
		 
	     
};
Juego::Juego(){
}
void Juego::avanzar(int dado){
	int pos_ant=get_posicion();
	 int nuevapos=pos_ant+dado;
	 set_nueva(nuevapos);
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
			case 59: // aqui se debera poner la si la suma es mayor que 63 restarle y set la posicion al resultado, si es igual a 63 gana, si es menor a 63 solo sumar y set una posicion nueva 
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
	}else if(get_posicion()==53){ // falta validar esta parte ademas que cuando se pase de 63 le reste las posiciones.
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
bool Juego::es_especial(int casilla){
	switch(casilla){
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
void Juego::retroceder(int casillas){
	int pos_ant=get_posicion();
	 int nuevapos=pos_ant-casillas;
set_nueva(nuevapos);
	
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
void seleccion(Jugador *&player);
int main(){
	srand(time(NULL));
	string jug1,jug2;
	int dados,tirar,jug;
	Dado *uno=new Dado();
	Dado *dos=new Dado();
	cout<<"Nombre del jugador 1"<<endl;
	getline(cin,jug1);
		fflush(stdin);
	cout<<"Nombre del jugador 2"<<endl;
		fflush(stdin);
		getline(cin,jug2);
	
	Jugador *player1=new Jugador(jug1,1); //color 1 ficha azul
	Jugador *player2=new Jugador(jug2,2); // color 2 ficha roja

 
  cout<<" "<<uno->get_dado()<<endl;
  cout<<" "<<dos->get_dado()<<endl;
 
 do{
 
  cout<<"Que jugador sera el primero en tirar ... jugador 1 presione 1, jugador 2 ... presione 2?"<<endl;
  	cin>>jug;
  	if(jug <1 or jug >2){
  		cout<<" Opcion Invalida, reingrese"<<endl;
	  }
	  if(jug==1){
	  	player1->set_turno(0);
	  	player2->set_turno(1);
	  }else if(jug==2){
	  	player2->set_turno(0);
	  	player1->set_turno(1);
	  }
  	 }while(jug <1 or jug > 2);
  
		
do{
	if(player1->get_turno()==0&&player2->get_turno()!=0){ //jugador 1 jugara si el jugador 2 no esta en turno
		cout<<"Ingrese 1 para tirar dados"<<endl;
				cin>>tirar;
				if(tirar==1){
					uno=new Dado();
					dos =new Dado();
					 dados=*uno+*dos; // poner un boton para inicializar los dados
					 player1->avanzar(dados);
					 if(player1->es_especial(player1->get_posicion())==true){ // faltara if que decrementara turno del contrario
					 				
									 seleccion(player1); //hacer lo mismo para el jugador 2
									 }else if(player1->es_especial(player1->get_posicion())==false){
					 player1->set_turno(1); // termina el turno
					 }
					 
					 
					 
					 
					 cout<<"antes  "<<player1->get_posicion()<<endl;
			}else{
					cout<<"No se han tirado los dados"<<endl;
				}
		
		
		
	}
	else if(player1->get_turno()!=0&&player2->get_turno()==0){ //jugador 2 jugara si el jugador 1 no esta en turno
			cout<<"Ingrese 1 para tirar dados"<<endl;
				cin>>tirar;
				if(tirar==1){
					uno=new Dado();
					dos =new Dado();
					 dados=*uno+*dos; 
					if(player2->es_especial(player2->get_posicion())==true){ // faltara if que decrementara turno del contrario
					 				
									 seleccion(player2); //hacer lo mismo para el jugador 2
									 }else if(player2->es_especial(player2->get_posicion())==false){
					 player2->set_turno(1); // termina el turno
					 }
					
					
					
					
					
				}else {
					cout<<"No se han tirado los dados"<<endl;
				}
		
		
		
		
		
	}
	
	
	
	
	
	
}while(player1->completo()!=true&&player2->completo()!=true);
  	
	return 0;
}
void seleccion(Jugador *&player){
	Dado *one=new Dado();
	Dado *two=new Dado();
	int dices= *one+*two;
				switch(player->get_posicion()){
		
				case 5:
				player->Oca();
				break;
			case 6:
				player->Puente();
				break;
			case 9:
				player->Oca();
				break;
			case 12:
				player->Puente();
				break;
			case 14:
				player->Oca();
				break;
			case 18:
				player->Oca();
				break;
			case 19:
				player->Posada();
				break;
			case 23:
				player->Oca();
				break;
			case 26:
				player->Dices();
				break;
			case 27:
				 player->Oca();
				break;
			case 32:
				player->Oca();
				break;
			case 36:
				player->Oca();
				break;
			case 41:
				player->Oca();
				break;
			case 42:
				player->Laberinto();
				break;
			case 45:
				player->Oca();
				break;
			case 50:
				player->Oca();
				break;
			case 53:
				player->Dices();
				break;
			case 54:
				player->Oca();
				break;
			case 56:
				player->Carcel();
				break;
			case 58:
				player->Calavera();
				break;
			case 59:
				 //aqui abra que mandar el dado y hacer un caso especial para retroceder o avanzar dependiendo hacer lo mismo en la clase
				player->Oca();
		        break;
		        		}
	
}
