//Hecho por Carlos Alfonso Lemus Rodezno

//programa que toma las coordenadas en los puntos x, y, z

#include <iostream> //libreria estandar obligatoria para hacer programas en consola en c/c++
#include <conio.h> //libreria necesaria para utilizar sus funciones
#include <iomanip> //libreria que nos permitira manipular los puntos decimales

using namespace std;

void error();

class cola{ // clase que sera de tipo cola, esta tiene los datos para crear y manipular una cola

    private:
    //atributos
    class Nodo{ //estructura  o tipo de dato Nodo de la clase
        public:
            int vector[3]; //vector de tipo entero que posee tres elementos que actuaran como x, y, z
            Nodo *sig; //declaracion de puntero de tipo nodo este apuntara al siguiente nodo
    };
    //declaracion de punteros del cual el primero apuntara al inicio de la cola y el segundo al final
    Nodo *raiz;
    Nodo *fondo;

    public:
        //metodos de la clase
        cola(); //Constructor de la clase cola inicializa los puntero raiz y fondo en null
        ~cola(); //destructor de la clase cola libera espacio de la memoria cuandos se destruye el objeto de la clase cola
        //metodo insertar por el cual se ingresaran los datos a la cola entre otras cosas
        void Insertar(int x, int y, int z, float *PromX,float *PromY, float *PromZ, float *n, int *MemoriaBytes);
        int  Extraer(); //metodo extraer que eliminara el primer elemento de la cola
        void Imprimir(); //metodo imprimir que imprimira los datos en los nodos de la cola
        bool Vacia(); //metodo que verifica si la cola esta vacia
};

cola::cola() //Constructor de la clase cola inicializa los puntero raiz y fondo en null
{
    /*se inicializa los puntero raiz y fondo en null esto cuando no hay ningun dato en la cola
    de manera que los punteros raiz y base almacenan una dirrecion null o lo mismo no contienen ninguna direccion
    pero se almacenara una*/
    raiz = NULL;
    fondo = NULL;
}

cola::~cola() //destructor de la clase cola libera espacio de la memoria cuandos se destruye el objeto de la clase colas
{
    Nodo *reco = raiz; //puntero reco que contendra la direccion de raiz
    Nodo *bor;
    while(reco != NULL){ //si reco es diferente de nulo, es decir que si frente no esta vacio(NULL) se ejecutara el bloque if

        bor = reco; // luego born almacenara la direccion de reco
        reco = reco->sig; //luego reco almacenara el valor del miembro puntero siguiente, de la clase nodo reco
        delete bor; /*luego se liberara el espacio de memoria que ocupa born es decir se libera el
                    espacio que ocupa raiz que contiene el primer nodo de la cola */
    }
}

//metodo insertar por el cual se ingresaran los datos a la cola entre otras cosas
void cola::Insertar(int x, int y, int z, float *PromX,float *PromY, float *PromZ, float *n, int *MemoriaBytes)
{

    Nodo *nuevo;
    nuevo = new Nodo(); //se segmenta el espacio en memoria para almacenar un nuevo nodo
    //se almacenara los valores x, y ,z en el miembro vector de 3 elementos en el nodo creado
    nuevo->vector[0] = x;
    nuevo->vector[1] = y;
    nuevo->vector[2] = z;

    *n += 1; //se le suma 1 a la variable n que servira como contador del total de nodos o elementos en la cola
    *PromX += x;
    *PromY += y;
    *PromZ += z;

    *MemoriaBytes = sizeof(class Nodo); //MemoriasBytes almacenara el tamaño del nodo en bytes

    nuevo->sig = NULL; //el miembro puntero siguiente apuntara a null

    if(Vacia()) //mientras la funcion no sea false se ejeccutara este bloque caso contrario se ejecutara el bloque else
    {
        /*raiz  y fondo alamacerara la direccion del nuevo nodo es decir ambos apuntaran al mismo nodo
        esto solo pasara cuando se ingrese el primer nodo caso contrario no*/
        raiz = nuevo;
        fondo = nuevo;
    }
    else { //mientras la funcion sea false se ejeccutara este bloque caso contrario se ejecutara el bloque if

        fondo->sig = nuevo; /*el miembro siguiente del objeto puntero fondo almacenara la direccion del nuevo nodo creado
                            simepre y cuando halla mas de un nodo o elemnto en la cola*/
        fondo = nuevo; //luego fondo almacenara la direccion del nuevo nodo siguente
    }
}

int cola::Extraer() //metodo extraer que eliminara el primer elemento de la cola
{
    if (!Vacia()) //mientras la funcion no sea false se ejeccutara este bloque caso contrario se ejecutara el bloque else
    {
        //informacion almacenara los datos del vector
        int informacion = raiz->vector[0];
        informacion = raiz->vector[1];
        informacion = raiz->vector[2];
        //el objeto puntero born de tipo Nodo almacenara la direccion de raiz es decir del primer nodo
        Nodo *bor = raiz;

        if (raiz == fondo) //si raiz y fondo son iguales, es decir si solo se encuentra un solo nodo en la cola
        {   //se inicializara raiz y fondo en NULL de nuevo si solo hay un nodo de la cola
            raiz = NULL;
            fondo = NULL;
        }
        else
        {   //Caso contrario que halla mas de un nodo raiz se desplazara a la direccion del nodo siguiente
            raiz = raiz->sig;
        }
        //se liberara el espacio de memoria de born es decir se destruira el primer nodo de la cola
        delete bor;
        return informacion; //se devolvera informacion
    }
    else //si la primera condicion if no se cumple se devuelve -1
    return -1;
}

void cola::Imprimir()  //metodo imprimir que imprimira los datos en los nodos de la cola
{

    Nodo *reco = raiz; //el puntero reco de tipo nodo alamacena la dirrecion de raiz es decir el primer nodo

    cout<<"\n\n\t\t\t\t\t\tListado de las coordenadas .\n";

    while ( reco != NULL){ //el ciclo while se repetira mientras reco se diferente de nulo

        cout << "\n\t\t\t\t\t\tCoordenada en x: " << reco->vector[0] << endl;
        cout << "\t\t\t\t\t\tCoordenada en y: " << reco->vector[1] << endl;
        cout << "\t\t\t\t\t\tCoordenada en z: " << reco->vector[2] << endl;

        reco = reco->sig; //reco se movera al siguiente nodo mienate el miembro puntero
    }

}
bool cola::Vacia() //metodo que verifica si la cola esta vacia
{
    return (raiz == NULL) ? true : false; //si raiz es igual a null devolvera true sino false

}

int main()
{
    //declaracion de variables
    int opcion;
    int seguir;
    int x;
    int y;
    int z;
    float PromX = 0;
    float PromY = 0;
    float PromZ = 0;
    float n = 0;
    int MemoriaBytes = 0;
    int NumBytes = 0;

    bool verificar = true;

    cola *cola1 = new cola(); //Se reserva espacio en la memoria para la cola

    system("color 4F"); //funcion que agrega color al fondo y letra de la consola de comandos

        do { //ciclo do - while permite seguir en el programa y evita errores de ingreso de datos

               do { // do - while evita errores de ingreso de datos

                   system("cls"); //funcion que limpia el texto de la consola

                   //Menu de l programa
                   cout << "\n\n\n\n\t\t\t\t\t\t=========================" << endl;
                   cout << "\t\t\t\t\t\t*                       *" << endl;
                   cout << "\t\t\t\t\t\t*      Coordenadas      *" << endl;
                   cout << "\t\t\t\t\t\t*                       *" << endl;
                   cout << "\t\t\t\t\t\t=========================" << endl;

                   cout << "\n\n\t\t\t\t\t\tOpciones" << endl;
                   cout << "\t\t\t\t\t\t1.Agregar" << endl;
                   cout << "\t\t\t\t\t\t2.Mostrar" << endl;
                   cout << "\t\t\t\t\t\t3.Eliminar" << endl;
                   cout << "\t\t\t\t\t\t4.Datos" << endl;
                   cout << "\t\t\t\t\t\t5.Salir" << endl;

                   cout << "\t\t\t\t\t\tIngrese una opcion: ";
                   cin >> opcion;
                   error(); //funcion que evita la entrada de datos incorrectos


                   if(opcion == cin.fail()) //si ocurre un error de ingreso de datos mostrara un mensaje
                   {

                       cout << "\n\n\t\t\t\tSe ha ingresado un dato incorrecto, vuelva a ingresarlo" << endl;

                       getch();

                   }

               } while(opcion < 1 || opcion > 5 || opcion == cin.fail());

                switch(opcion)
                {
                    case 1:

                        do { // do - while evita errores de ingreso de datos

                            do  { // do - while evita errores de ingreso de datos

                                system("cls"); //funcion que limpia el texto de la consola

                                cout << "\n\n\n\n\t\t\t\t\t\t=========================" << endl;
                                cout << "\t\t\t\t\t\t*                       *" << endl;
                                cout << "\t\t\t\t\t\t*   Ingresa los datos   *" << endl;
                                cout << "\t\t\t\t\t\t*                       *" << endl;
                                cout << "\t\t\t\t\t\t=========================" << endl;

                                cout << "\n\n\t\t\t\t\t\tIngrese el valor de x: ";
                                cin >> x;
                                error(); //funcion que evita que se ingrese datos incorrectos

                                cout << "\n\n\t\t\t\t\t\tIngrese el valor de x: ";
                                cin >> y;
                                error(); //funcion que evita que se ingrese datos incorrectos

                                cout << "\n\n\t\t\t\t\t\tIngrese el valor de x: ";
                                cin >> z;
                                error(); //funcion que evita que se ingrese datos incorrectos


                            } while(x == cin.fail() || y == cin.fail() || z == cin.fail());


                            cout << "\n\n\t\t\t\t\tDesea seguir ingresar otra coordenada (Si = 1, No = 2): ";
                            cin >> seguir;
                            error(); //funcion que evita la entrada de datos incorrectos

                            if(seguir == cin.fail()) //si ocurre un error de ingreso de datos mostrara un mensaje
                            {

                                cout << "\n\n\t\t\t\tSe ha ingresado un dato incorrecto, vuelva a ingresarlos" << endl;

                                getch();


                            }
                            else { //si no ocurre ningun error de entrada en los datos se ejecutara esta bloque

                                //el objeto puntero accede al metodo insertar por medio del operador de seleccion
                                cola1->Insertar(x, y, z, &PromX, &PromY, &PromZ, &n, &MemoriaBytes);
                            }

                        } while(seguir == 1 || seguir != 2 || seguir == cin.fail());

                        verificar = false; /*si se ingresan datos el valor de varificar cambia a false, esto debido a
                                           que la variable se usara para comprobar que haiga elementos en la cola*/
                        getch();

                        break;

                    case 2:

                        system("cls"); //funcion que limpia el texto de la consola

                        cout << "\n\n\n\n\t\t\t\t\t\t=========================" << endl;
                        cout << "\t\t\t\t\t\t*                       *" << endl;
                        cout << "\t\t\t\t\t\t*     Mostrar Datos     *" << endl;
                        cout << "\t\t\t\t\t\t*                       *" << endl;
                        cout << "\t\t\t\t\t\t=========================" << endl;

                        //si no se ha ingresados datos verificar vale true por lo que mostrara un mensaje

                       if(verificar){

                            cout << "\n\n\t\t\t\t\t\tNo hay registros" << endl;

                        }

                        else {
                                //el objeto puntero accede al metodo imprimir por medio del operador de seleccion
                                cola1->Imprimir();

                        }

                        getch();

                        break;

                    case 3:

                        system("cls"); //funcion que limpia el texto de la consola

                        cout << "\n\n\n\n\t\t\t\t\t\t=========================" << endl;
                        cout << "\t\t\t\t\t\t*                       *" << endl;
                        cout << "\t\t\t\t\t\t*    Eliminar datos     *" << endl;
                        cout << "\t\t\t\t\t\t*                       *" << endl;
                        cout << "\t\t\t\t\t\t=========================" << endl;

                        //si no se ha ingresados datos verificar vale true por lo que mostrara un mensaje

                       if(verificar){

                            cout << "\n\n\t\t\t\t\t\tNo hay registros" << endl;

                        }

                        else {

                             do { // do - while evita errores de ingreso de datos



                                  cout << "\n\n\t\t\t\t\tSe ha Eliminado la primer coordenada correctamente" << endl;

                                  cout << "\n\n\t\t\t\t\tDesea eliminar otra coordenada (Si = 1, No = 2): ";
                                  cin >> seguir; //funcion que evita que se ingrese datos incorrectos
                                  error(); //funcion que evita la entrada de datos incorrectos

                                  //si no ocurre ningun error de entrada en los datos se ejecutara esta bloque
                                  if((seguir == 1 || seguir == 2) && seguir != cin.fail())
                                  {
                                      //el objeto puntero accede al metodo extraer por medio del operador de seleccion
                                      cola1->Extraer();
                                  }

                            } while(seguir == 1 || seguir != 2 || seguir == cin.fail());

                        }

                        getch();

                        break;

                    case 4:

                        system("cls"); //funcion que limpia el texto de la consola

                        cout << "\n\n\n\n\t\t\t\t\t\t=========================" << endl;
                        cout << "\t\t\t\t\t\t*                       *" << endl;
                        cout << "\t\t\t\t\t\t*  Datos del Programa   *" << endl;
                        cout << "\t\t\t\t\t\t*                       *" << endl;
                        cout << "\t\t\t\t\t\t=========================" << endl;


                        //si no se ha ingresados datos verificar vale true por lo que mostrara un mensaje

                       if(verificar){

                            cout << "\n\n\t\t\t\t\t\tNo hay registros" << endl;

                        }

                        else {
                                  /*NumBytes almacena la cantidad de bytes de un nodo y lo multiplica por
                                    la cantidad de nodo o elementos que hay en la cola*/
                                  NumBytes = MemoriaBytes * n;


                                cout << "\n\n\t\t\t\t\t\tLa media de x es: " << fixed << setprecision(2) << PromX/n << endl;
                                cout << "\t\t\t\t\t\tLa media de x es: " << fixed << setprecision(2) << PromY/n << endl;
                                cout << "\t\t\t\t\t\tLa media de x es: " << fixed << setprecision(2) << PromZ/n << endl;

                                cout << "\n\t\t\t\t\tEl numero de bytes que ocupa la cola en la memoria es: " << NumBytes << endl;

                        }

                        getch();

                        break;

                    case 5:
                        system("cls"); //funcion que limpia el texto de la consola

                        cout << "\n\n\n\n\t\t\t\t\t\tGracias por usar el programa" << endl;

                        break;

                }

        } while(opcion == 1 || opcion == 2 || opcion == 3 || opcion == 4);

    delete cola1;

    cin.get();
    return 0;
}

void error() //funcion que evita que se ingrese datos incorrectos
{
        //Ciclo while paraevitar datos incorrectos
        while(cin.fail()){

        //Limpia el buffer de los datos ingresados
        cin.clear();

        //Ignora los primeros 1000 caracteres o en este caso los numeros
        cin.ignore(1000,'\n');

        }
}
