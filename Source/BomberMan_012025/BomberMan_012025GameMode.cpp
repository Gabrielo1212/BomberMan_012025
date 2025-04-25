// Copyright Epic Games, Inc. All Rights Reserved.

#include "BomberMan_012025GameMode.h"
#include "BomberMan_012025Character.h"
#include "UObject/ConstructorHelpers.h"
#include "Moneda.h"
#include "Bloque.h"
#include "BloqueBurbuja.h"
#include "BloqueAcero.h"
#include "BloqueConcreto.h"
#include "BloqueLadrillo.h"
#include "BloqueMadera.h"
#include "BloquePasto.h"
#include "BloqueArena.h"
#include "BloqueGrava.h"
#include "BloqueCobre.h"
#include "BloqueRoble.h"
#include "BloqueOro.h"
#include "Enemigo.h"
#include "EnemigoTerrestre.h"
#include "EnemigoAcuatico.h"
#include "EnemigoAereo.h"
#include "EnemigoSubterraneo.h"
#include "Kismet/GameplayStatics.h"

ABomberMan_012025GameMode::ABomberMan_012025GameMode()
{
    // set default pawn class to our Blueprinted character
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
    if (PlayerPawnBPClass.Class != NULL)
    {
        DefaultPawnClass = PlayerPawnBPClass.Class;
    }
}

void ABomberMan_012025GameMode::BeginPlay()
{
    Super::BeginPlay();

    // Recorremos la matriz para generar los bloques
    
    for (int32 fila = 0; fila < aMapaBloques.Num(); ++fila)
    {
        for (int32 columna = 0; columna < aMapaBloques[fila].Num(); ++columna)
        {
            int32 valor = aMapaBloques[fila][columna];
            // Calculamos la posiciÛn del bloque
            FVector posicionBloque = FVector(
                XInicial + columna * AnchoBloque,
                YInicial + fila * LargoBloque,
                20.0f); // Z queda en 0 (altura del bloque)
            SpawnBloque(posicionBloque, valor);
        }
    }
    
    //Declarar el array para las maderas del borde
    TArray<ABloqueMadera*> MaderasBorde;
    // Posicionar al jugador sobre un bloque de madera cercano al borde
    
    for (ABloque* Bloque : aBloques)
    {
        // Comprobar que el bloque es de madera
        if (ABloqueMadera* Madera = Cast<ABloqueMadera>(Bloque))
        {
            FVector Pos = Madera->GetActorLocation();
    
            // Verificamos si está cerca de los bordes (ajustar margen según el tamaño del laberinto)
            if (Pos.X <= XInicial + AnchoBloque || Pos.Y <= YInicial + LargoBloque || Pos.X >= XInicial + AnchoBloque * (aMapaBloques[0].Num() - 2) || Pos.Y >= YInicial + LargoBloque * (aMapaBloques.Num() - 2))
            {
                MaderasBorde.Add(Madera);
            }
            /*
            //Verificar cuantos bloques tiene al lado
            for(ABloqueMadera* BloqueMadera :MaderasBorde){
                FVector Posicion = BloqueMadera->GetActorLocation();
                for(int i = -1; i < 2; i++){
                    for(int j = -1; j < 2; j++){
                        if(Posicion+FVector()==Pos){
                            
                        }
                    }
                }
            }
             */
        }
    }
    
    if (MaderasBorde.Num() > 0)
    {
        int32 NumAleatorio  = FMath::RandRange(0, MaderasBorde.Num() - 1);
        FVector PosDestino = MaderasBorde[NumAleatorio]->GetActorLocation();
        APawn* Jugador = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
        if (Jugador)
        {
            Jugador->SetActorLocation(PosDestino + FVector(0.0f, 0.0f, 250.0f)); // Eleva al jugador un poco
        }
    }
    
    
    AsignarMovimientosAleatorios();

}

// Funcion para generar un bloque
void ABomberMan_012025GameMode::SpawnBloque(FVector posicionBloque, int32 tipoBloque)
{
    ABloque* BloqueGenerado = nullptr;
    AEnemigo* EnemigoGenerado = nullptr;
    AMoneda* MonedaGenerada = nullptr;

    // Elegir tipo de bloque basado en el valor
    if (tipoBloque == 10)
    {
        BloqueGenerado = GetWorld()->SpawnActor<ABloqueOro>(ABloqueOro::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
    }
    else if (tipoBloque == 9)
    {
        BloqueGenerado = GetWorld()->SpawnActor<ABloqueRoble>(ABloqueRoble::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
    }
    else if (tipoBloque == 8)
    {
        BloqueGenerado = GetWorld()->SpawnActor<ABloqueCobre>(ABloqueCobre::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
    }
    else if (tipoBloque == 7)
    {
        BloqueGenerado = GetWorld()->SpawnActor<ABloqueGrava>(ABloqueGrava::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
    }
    else if (tipoBloque == 6)
    {
        BloqueGenerado = GetWorld()->SpawnActor<ABloqueArena>(ABloqueArena::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
    }
    else if (tipoBloque == 5)
    {
        BloqueGenerado = GetWorld()->SpawnActor<ABloquePasto>(ABloquePasto::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
    }
    else if (tipoBloque == 4)
    {
        BloqueGenerado = GetWorld()->SpawnActor<ABloqueAcero>(ABloqueAcero::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
    }
    else if (tipoBloque == 3)
    {
        BloqueGenerado = GetWorld()->SpawnActor<ABloqueConcreto>(ABloqueConcreto::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
    }
    else if (tipoBloque == 2)
    {
        BloqueGenerado = GetWorld()->SpawnActor<ABloqueLadrillo>(ABloqueLadrillo::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
    }
    else if (tipoBloque == 1)
    {
        BloqueGenerado = GetWorld()->SpawnActor<ABloqueMadera>(ABloqueMadera::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
    }
    else if (tipoBloque == 0)
    {
        float probabilidad = FMath::RandRange(0.0f, 1.0f);
        if (probabilidad < 0.1f) // 10% de probabilidad de spawnear
        {
            float probabilidad2 = FMath::RandRange(0.0f, 1.0f);
            PosicionesVacias.Add(posicionBloque);
            if (probabilidad2 < 0.25f){
                EnemigoGenerado = GetWorld()->SpawnActor<AEnemigoAereo>(AEnemigoAereo::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
                PosicionesVacias.Add(posicionBloque);
            }else if (probabilidad2 < 0.5f){
                EnemigoGenerado = GetWorld()->SpawnActor<AEnemigoTerrestre>(AEnemigoTerrestre::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
                PosicionesVacias.Add(posicionBloque);
            }else if (probabilidad2 < 0.75f){
                EnemigoGenerado = GetWorld()->SpawnActor<AEnemigoAcuatico>(AEnemigoAcuatico::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
                PosicionesVacias.Add(posicionBloque);
            }else{
                EnemigoGenerado = GetWorld()->SpawnActor<AEnemigoSubterraneo>(AEnemigoSubterraneo::StaticClass(), posicionBloque, FRotator(0.0f, 0.0f, 0.0f));
                PosicionesVacias.Add(posicionBloque);
            }
        }else if(probabilidad > 0.11f && probabilidad < 0.12f){
            MonedaGenerada = GetWorld()->SpawnActor<AMoneda>(AMoneda::StaticClass(), posicionBloque + FVector(0.0f,0.0f,100.0f), FRotator(0.0f, 0.0f, 0.0f));
        }else{
            PosicionesVacias.Add(posicionBloque);
        }
    }

    // Agregar el bloque al TArray si fue generado
    if (BloqueGenerado)
    {
        // Ajustar la escala
        FVector EscalaActual = BloqueGenerado->GetActorScale3D();
        EscalaActual.Z *= 2.0f; // Aumenta la altura 2 veces
        BloqueGenerado->SetActorScale3D(EscalaActual);

        // Agregar el bloque al array aBloques
        aBloques.Add(BloqueGenerado);
    }
    if(EnemigoGenerado)
    {
        aEnemigos.Add(EnemigoGenerado);
    }
}


void ABomberMan_012025GameMode::AsignarMovimientosAleatorios()
{
    // Arrays para almacenar los diferentes tipos de bloques
    TArray<ABloque*> Ladrillos, Maderas, Aceros, Concretos, Pastos, Arenas, Gravas, Cobres, Robles, Oros;

    // Clasificar los bloques según su tipo
    for (ABloque* Bloque : aBloques)
    {
        if (Bloque->IsA(ABloqueLadrillo::StaticClass())) Ladrillos.Add(Bloque);
        else if (Bloque->IsA(ABloqueMadera::StaticClass())) Maderas.Add(Bloque);
        else if (Bloque->IsA(ABloqueAcero::StaticClass())) Aceros.Add(Bloque);
        else if (Bloque->IsA(ABloqueConcreto::StaticClass())) Concretos.Add(Bloque);
        else if (Bloque->IsA(ABloquePasto::StaticClass())) Pastos.Add(Bloque);
        else if (Bloque->IsA(ABloqueArena::StaticClass())) Arenas.Add(Bloque);
        else if (Bloque->IsA(ABloqueGrava::StaticClass())) Gravas.Add(Bloque);
        else if (Bloque->IsA(ABloqueCobre::StaticClass())) Cobres.Add(Bloque);
        else if (Bloque->IsA(ABloqueRoble::StaticClass())) Robles.Add(Bloque);
        else if (Bloque->IsA(ABloqueOro::StaticClass())) Oros.Add(Bloque);
    }

    // Función para asignar movimiento a 2 bloques aleatorios de un tipo
    auto AsignarMovimiento = [](TArray<ABloque*>& Lista, int DirX, int DirY, int DirZ, float Velocidad = 100.0f)
        {
            if (Lista.Num() >= 2)
            {
                // Mezclar el array para selección aleatoria
                for (int32 i = 0; i < Lista.Num(); i++)
                {
                    int32 j = FMath::RandRange(0, Lista.Num() - 1);
                    if (i != j)
                    {
                        Lista.Swap(i, j);
                    }
                }

                // Seleccionar los primeros 2 bloques después de mezclar
                for (int32 i = 0; i < 2 && i < Lista.Num(); i++)
                {
                    ABloque* Bloque = Lista[i];
                    Bloque->DireccionMovimientoX = DirX;
                    Bloque->DireccionMovimientoY = DirY;
                    Bloque->DireccionMovimientoZ = DirZ;
                    Bloque->Velocidad = Velocidad;
                    Bloque->PuedeMoverse = true;
                }
            }
        };

    // Asignar movimientos específicos para cada tipo de bloque
    AsignarMovimiento(Ladrillos, 1, 0, 0, 80.0f);    // Ladrillo: Eje X, Velocidad 80
    AsignarMovimiento(Maderas, 0, 1, 0, 70.0f);      // Madera: Eje Y, Velocidad 70
    AsignarMovimiento(Aceros, 0, 0, 1, 50.0f);       // Acero: Eje Z, Velocidad 50
    AsignarMovimiento(Concretos, -1, 0, 0, 60.0f);   // Concreto: Eje -X, Velocidad 60
    AsignarMovimiento(Pastos, 0, -1, 0, 120.0f);     // Pasto: Eje -Y, Velocidad 120
    AsignarMovimiento(Arenas, 0, 0, -1, 130.0f);     // Arena: Eje -Z, Velocidad 130
    AsignarMovimiento(Gravas, 1, 1, 0, 75.0f);       // Grava: Diagonal X+Y, Velocidad 75
    AsignarMovimiento(Cobres, 0, 1, 1, 65.0f);       // Cobre: Diagonal Y+Z, Velocidad 65
    AsignarMovimiento(Robles, 1, 0, 1, 85.0f);       // Roble: Diagonal X+Z, Velocidad 85
    AsignarMovimiento(Oros, -1, -1, 0, 100.0f);      // Oro: Diagonal -X-Y, Velocidad 100
}
