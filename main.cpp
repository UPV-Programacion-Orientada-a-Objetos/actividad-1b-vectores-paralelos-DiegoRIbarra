#include <iostream>
#include <string>

//prototipos de las funciones
void buscarProducto(int a[], int, int);
void actInventario(int a[],int,int, int);
void reporte(int);
void productoCaro(float [],int);
int verificarEntrada(std::istream&);


 //declaracion global de los array
    float precio[100]={10, 18, 45, 50, 60};
    std::string producto[100]={"Manzana", "Jugo", "Pan en barra", "Cafe en grano", "Sabritas"};
    int stock[100]={50, 50, 50, 50, 50};
    int codigo[100]={230, 231, 232, 233, 234};

int main() {
    int con,aux1,aux2;
    int size;
    size=5;
    do
    {
        std::cout<<"1.-Consulta producto  2.-Actualizar inventario"<<std::endl;
        std::cout<<"3.- Generacion de Reporte  4.-Producto mas caro"<<std::endl;
        std::cout<<"0.-Salir"<<std::endl;
        std::cout<<"¿Que desea hacer?: ";
        con=verificarEntrada(std::cin);
      
        
        switch (con){
        case 1:
            std::cout<<"Ingrese el codigo del producto";
            aux1=verificarEntrada(std::cin);
            buscarProducto(codigo,size,aux1);
            break;
        case 2:
            std::cout<<"Ingrese el codigo del producto";
            aux1=verificarEntrada(std::cin);
            std::cout<<"Ingrese cantidad a actualizar stock";
            aux2=verificarEntrada(std::cin);
            actInventario(codigo,size,aux1,aux2);
            break;
        case 3:
            reporte(size);
            break;
        case 4:
            productoCaro(precio,size);
            break;
        case 0:
            std::cout<<"Saliendo...";
            break;
        default:
            std::cout<<"Ingrese una opcion valida";
            break;
        }
    } while (con!=0);    
    return 0;
}

void buscarProducto(int a[], int s, int n){
    int index=-1;
    for (int i=0; i <s; i++){
        if (a[i]==n){
            index=i;
            break;
        }
    }
    if (index!=-1){
        std::cout<<"Codigo producto: "<<n<<std::endl;
        std::cout<<"Producto: "<<producto[index]<<std::endl;
        std::cout<<"Precio Unitario: "<<precio[index]<<std::endl;
        std::cout<<"Stock: "<<stock[index]<<std::endl;
    }else{
        std::cout<<"No se encontro el producto"<<std::endl;
    }
}

int verificarEntrada(std::istream& entrada){
    int aux=0;
    entrada>>aux;
    while(entrada.fail()){
        entrada.clear();
        entrada.ignore(256,'\n');
        std::cout<<"Entrada invalida, intente de nuevo: "<<std::endl;
        entrada>>aux;
    }
    return aux;
}

void reporte(int s){
    std::cout<<"    Reporte de productos"<<std::endl;
    std::cout<<"| Codigo |"<<" Producto |"<<" Precio |"<<" Stock |"<<std::endl;
    for (int i = 0; i < s; i++)
    {
        std::cout<<"|  "<<codigo[i]<<"   |  "<<producto[i]<<"  |  "<<precio[i]<<"  |  "<<stock[i]<<"  |"<<std::endl;
    }

    std::cout<<"----- Fin de Reporte ----- "<<std::endl;
    
}

void productoCaro(float a[], int s){
    float precio=a[0];
    int index;
    for (int i = 1; i <s; i++)
    {
        if (a[i]>precio){
            precio=a[i];
            index=i;
        }
        
    }
    std::cout<<"El producto mas caro es: "<<producto[index]<<" con un precio de: "<<precio<<std::endl;
    
}

void actInventario(int a[],int s, int cod,int cant){
    bool found=false; 
    int index=-1;   
    for (int i = 0; i < s; i++){
        if (a[i]==cod){
            found=true;
            index=i;
            break;
        }
    }
    if (found){
        int ver= stock[index]+cant;
        if (ver>=0){
            stock[index]=ver;
            std::cout<<"Stock del producto "<<producto[index]<<" actualizado"<<std::endl;
            return;
        }else{
            std::cout<<"No puede ingresar valores que den stock negativo, verificalo e intenta de nuevo"<<std::endl;
            return;
        }
    }else{
        std::cout<<"Producto no encontrado ingrese un codigo valido"<<std::endl;
    }
}