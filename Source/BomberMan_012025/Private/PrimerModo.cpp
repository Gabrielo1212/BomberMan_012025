// Fill out your copyright notice in the Description page of Project Settings.


#include "PrimerModo.h"
#include "Power_Up.h"
#include "BloqueMadera.h"
#include "BloqueLadrillo.h"
#include "BloqueConcreto.h"
#include "BloqueAcero.h"

void APrimerModo::BeginPlay()
{
    //Llamada al metodo de la clase padre
    Super::BeginPlay();
    //Mensaje en pantalla
    //GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red,TEXT("Actor Apareciendo"));
    //Crear la variable de posicion
    //FTransform SpawnLocation;
    //Posicion inicial
    //GetWorld()->SpawnActor<APower_Up>(APower_Up::StaticClass(), SpawnLocation);
    //Cambiar el valor de la variable
    //SpawnedActor = GetWorld()->SpawnActor<APower_Up>(APower_Up::StaticClass(), SpawnLocation);
    //Crear el temporizador
    //FTimerHandle Timer;
    //Configurar el temporizador
    //GetWorldTimerManager().SetTimer(Timer, this,&APrimerModo::DestroyActorFunction, 10);
    
    //Crear los bloques
    //ABloqueMadera* bloque01 = GetWorld()->SpawnActor<ABloqueMadera>(ABloqueMadera::StaticClass(), FVector(934.0f, 1370.0f, 100.0f), FRotator(0.0f, 0.0f, 0.0f));
    //ABloqueMadera* bloque02 = GetWorld()->SpawnActor<ABloqueMadera>(ABloqueMadera::StaticClass(), FVector(734.0f, 1370.0f, 50.0f), FRotator(0.0f, 0.0f, 0.0f));
    // Crear objetos para usar los metodos
    ABloqueMadera* bloque = GetWorld()->SpawnActor<ABloqueMadera>(ABloqueMadera::StaticClass(), FVector(300.0f, 6700.0f, 0), FRotator(0.0f, 0.0f, 0));
    ABloqueConcreto* bloque2 = GetWorld()->SpawnActor<ABloqueConcreto>(ABloqueConcreto::StaticClass(),FVector(100.0f, 6700.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
    ABloqueLadrillo* bloque3 = GetWorld()->SpawnActor<ABloqueLadrillo>(ABloqueLadrillo::StaticClass(),FVector(300.0f, 6500.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
    ABloqueAcero* bloque4 = GetWorld()->SpawnActor<ABloqueAcero>(ABloqueAcero::StaticClass(),FVector(100.0f, 6500.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
    //Llama al método SpawnBloquesMatriz desde el objeto bloque
    bloque->ABloqueMadera::SpawnBloquesMatriz(27, 16, FVector(200.0f, 200.0f, 0.0f), FVector(100, 0, 0), FVector(0, 200, 0));
    bloque->ABloqueMadera::SpawnBloquesMatriz(14, 15, FVector(200.0f, 300.0f, 0.0f), FVector(200, 0, 0), FVector(0, 200, 0));
    // Llama al método SpawnBloquesPisos desde el objeto bloque
    bloque2->ABloqueConcreto::SpawnBloquesPisos(30, 35, FVector(0.0f, 0.0f, 0.0f));
    //Muro Eje X Izquierda
    bloque3->ABloqueLadrillo::SpawnBloquesSeguidos(29, FVector(100.0f, 100.0f, 0.0f), FVector(100, 0, 0));
    //Muro Eje Y Abajo
    bloque3->ABloqueLadrillo::SpawnBloquesSeguidos(32, FVector(100.0f, 200.0f, 0.0f), FVector(0, 100, 0));
    //Muro Eje X Derecha
    bloque3->ABloqueLadrillo::SpawnBloquesSeguidos(28, FVector(200.0f, 3300.0f, 0.0f), FVector(100, 0, 0));
    //Muro Eje Y Arriba
    bloque3->ABloqueLadrillo::SpawnBloquesSeguidos(31, FVector(2900.0f, 200.0f, 0.0f), FVector(0, 100, 0));
    //Patron Mundo
    bloque3->ABloqueLadrillo::SpawnBloquesMatriz(13, 15, FVector(300.0f, 300.0f, 0.0f),FVector(200, 0, 0),FVector(0, 200, 0));
    
    
    /*
     //Metodo para destruir el actor
     void APrimerModo::DestroyActorFunction()
     {
     //Verificar que el actor exista
     if (SpawnedActor != nullptr)
     {
     }
     //Destruir el actor
     SpawnedActor->Destroy();
     }
     */
}
