// Fill out your copyright notice in the Description page of Project Settings.


#include "PrimerModo.h"
#include "Power_Up.h"

void APrimerModo::BeginPlay()
{
//Llamada al metodo de la clase padre
Super::BeginPlay();
//Mensaje en pantalla
GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red,TEXT("Actor Apareciendo"));
//Crear la variable de posicion
FTransform SpawnLocation;
//Posicion inicial
GetWorld()->SpawnActor<APower_Up>(APower_Up::StaticClass(),
    SpawnLocation);
}

