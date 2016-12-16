@@ -1,15 +1,387 @@
//
//  main.cpp
//  Buscaminas 4
//
//  Created by Daniel on 13/12/16.
//  Copyright © 2016 daniel. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <stdlib.h>


using namespace std;



void nstrucciones();
int random(int i, int b);
void replay();
void revelar(int x);
void limpiarscreen();
void buscaminas();
int main();


int main()
{
    
    cout << "\t\t\tBUSCAMINAS"<< endl;
    cout << "Desarrollado por Daniel Zazueta y Oscar Villarreal" << endl << endl;
    cout << "Introduzca una opcion" << endl;
    
    cout << "[1] Jugar\t\t\t" << "[2] Instrucciones" << endl << endl;
    
    int opciones;
    
    cin >> opciones;
    
    switch (opciones) {
        case 1:
            buscaminas();
            break;
            
        case 2:
            nstrucciones();
            break;
            
        default:
            break;
    }
    
    
}

void nstrucciones()
{
    cout << "1- Elija el numero de cuadros de su tablero, para continuar presione la tecla enter" << endl;
    cout << "2- Elija el numero de minas que desea que aparezcan en su tablero" << endl;
    cout << "3- Introduzca la coordenada en el eje X y presione enter para continuar" << endl;
    cout << "4- Introduzca la coordenada en el eje Y y presione enter para revelar el area del tablero" << endl << endl;
    cout << "El juego termina cuando se toca una mina" << endl;
    cout << "Ganas el juego si descubres todos los recuadros libres de minas" << endl;
    
    
    main();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
void buscaminas()
{
    
    int b;                                                                          //este numero se multiplicara por si mismo para generar tab

    
    
    cout << "Introduzca el numero de cuadros por lado" << endl;
    cin >> b;                                                                   //introduce numero para al cuadricula
    
    
    if (b == 1)                                                                     //este if impide jugar si se quiere crear una cuadricula de
        //1 x 1
    {
        cout << "No es posible jugar en un tablero de 1x1" << endl;
        replay();
    }
    
    while(b < 1 && b >= 10);
    
    int cuadricula[b][b];
    int i = 0;
    int x = 0;
    int j = 0;
    int mina = 0;
    int y = 0;
    int z;                               //minas
    int q;
    int revealed[b][b];

    do
    {
        cout << "Introduzca el numero de minas (Maximo " << ((b*b)-1) << ")" << endl;
        cin >> z;
    }
    
    while(z <= 0 && z >= ((b*b)-1));
    for(i=0;i<b;i++)
        for(j=0;j<b;j++)
            cuadricula[i][j] = 0;
    i = random(i, b);
    j = random(j, b);
    
    cout << "Generando tablero..." << endl;
    
    
    
    
    do
    {
        i+=3;
        j+=6;
        x = random(i, b);
        y = random(j, b);
        
        
        
        
        if(cuadricula[y][x] != 9)
        {
            cuadricula[y][x] = 9;
            z--;
            if((y-1) >= 0)
                
                if(cuadricula[y-1][x] != 9)
                    cuadricula[y-1][x]++;
            
            if((y-1) >= 0 && (x-1) >= 0)
                if(cuadricula[y-1][x-1] != 9)
                    cuadricula[y-1][x-1]++;
            
            
            if((x-1) >= 0)
                if(cuadricula[y][x-1] != 9)
                    cuadricula[y][x-1]++;
            
            if((y+1) < b)
                if(cuadricula[y+1][x] != 9)
                    cuadricula[y+1][x]++;
            
            
            if((y+1) < b && (x+1) < b)
                if(cuadricula[y+1][x+1] != 9)
                    cuadricula[y+1][x+1]++;
            
            if((x+1) < b)
                if(cuadricula[y][x+1] != 9)
                    cuadricula[y][x+1]++;
            
            if((y-1) >= 0 && (x+1) < b)
                if(cuadricula[y-1][x+1] != 9)
                    cuadricula[y-1][x+1]++;
            
            if((y+1) < b && (x-1) >= 0)
                if(cuadricula[y+1][x-1] != 9)
                    cuadricula[y+1][x-1]++;
        }
    }
    
    
    
    
    while(z >0);
    for(i = 0; i < b; i++)
        for(j=0;j<b;j++)
            revealed[i][j]=0;
    
    
    
    
    do
    {
        limpiarscreen();
        q = 0;
        z = 0;
        cout << "    ";
        for(i=0;i<b;i++)
            if(i < 10)
                cout<<"0" << i << " ";
            else
                cout << i << " ";
        
        
        cout << endl;
        for(i=0;i<b;i++)
        {
            
            if (i >= 10)
            {
                cout << i << " |";
                
            }
            for(j=0;j<b;j++)
            {
                
                
                if (j==0)
                {
                    if (i < 10)
                        cout << "0" << i << " |";
                    
                }
                
                
                if(revealed[i][j]==1)
                    revelar(cuadricula[i][j]);
                else
                    cout << "__|";
                if(j==(b-1))
                    cout << endl;
                if(cuadricula[i][j]!=9 && revealed[i][j]==1)
                    q++;
                if(cuadricula[i][j] == 9)
                    z++;
            }
        }
        
        
        
        
        if(q >= ((b*b) - z))
        {
            cout << "¡Ganaste!" << endl;
            mina = 1;
        }
        
        
        
        
        if(mina == 0)
        {
            cout << "Introduzca coordenada X: ";
            cin >> x;
            cout << "Introduzca coordenada Y: ";
            cin >> y;
        }
        
        
        
        if(cuadricula[y][x] == 9)
        {
            cout << "¡Tocaste una mina!" << endl;
            cout << "   ";
            for(i=0;i<b;i++)
                if (i < 10)
                {
                    cout << "0" << i << " ";
                    
                }
                else
                cout << i << " ";
            cout << endl;
            mina= 1;
            
            
            for(i=0; i<b; i++)
            {
                for(j=0;j<b;j++)
                {
                    if(j==0)
                    {
                        if (i < 10)
                        
                        cout << "0" << i << "|";
                        if ( i >= 10)
                            cout << i << "|";
                    }
                    
                    
                    if(cuadricula[i][j]==9)
                        revealed[i][j]=1;
                    if(revealed[i][j]==1)
                        revelar(cuadricula[i][j]);
                    else
                        cout << "__|";
                    
                    
                    
                    if(j==(b-1))
                        cout << endl;
                }
            }
            
        }
        if(cuadricula[y][x]==0)
        {
            revealed[y][x] = 1;
            for(i=0;i<b;i++)
            {
                for(j=0;j<b;j++)
                {
                    if(i>(y-2)&&i<(y+2))
                        if(j>(x-2)&&j<(x+2))
                            if(cuadricula[i][j]!=9)
                                revealed[i][j]=1;
                }
            }
        }
        if(cuadricula[y][x]>0 && cuadricula[y][x]<9)
            revealed[y][x] = 1;
    }
    while(mina == 0);
    if (mina == 1)
        replay();
    
}





void limpiarscreen()
{
    cout << string( 100, '\n' );
}


void revelar(int x)
{
    

    if(x == 0)
    {
        cout << " O|";
        
    }
    
    else if(x == 9)
        cout << " X|";
    
    else
        cout << " " << x <<  "|";
    
    
    
    
}

void replay()
{
    char a;
    cout << "[1] Volver a jugar    [2] Salir" << endl;
    cin >> a;
    
    
    
    switch(a)
    {
        case '1':
            main();
            break;
        case '2':
            cout << "Saliendo.." << endl;
            break;
        default:
            cout << "No existe esa opcion" << endl;
            replay();
            break;
    }
}










int random(int i, int b)
{
    long ran;
    long t = time(0);
    srand(t);
    ran = rand();
    ran >>= ran / (ran * i) + (i * 878);
    ran = ran % b;
    return ran;
}






