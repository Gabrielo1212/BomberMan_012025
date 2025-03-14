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
    // Crea un objeto ABloqueMadera
    ABloqueMadera* bloque = GetWorld()->SpawnActor<ABloqueMadera>(ABloqueMadera::StaticClass(), FVector(0.0f, 0.0f, 0), FRotator(0.0f, 0.0f, 0));
    ABloqueConcreto* bloque2 = GetWorld()->SpawnActor<ABloqueConcreto>(ABloqueConcreto::StaticClass(), FVector(0.0f, 0.0f, 0), FRotator(0.0f, 0.0f, 0));
    // Llama al método SpawnBloquesSeguidos desde el objeto bloque
    bloque->SpawnBloquesSeguidos(10, FVector(150, 150, 0), FVector(100, 0, 0));
    bloque->SpawnBloquesSeguidos(10, FVector(150, 150, 0), FVector(0, 100, 0));
    FVector posicion = FVector(0.0f, 0.0f, 0.0f);
    bloque2->SpawnBloquesPisos(35, 30, posicion, FVector(100, 0, 0));
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
