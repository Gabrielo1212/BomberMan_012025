// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Array>
#include "Power_Up.h"
#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "PrimerModo.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API APrimerModo : public AGameMode
{
	GENERATED_BODY()
    // Función que se llama al inicio del juego
    virtual void BeginPlay() override;
    //Actor que se va a spawnear
    UPROPERTY()
    APower_Up* SpawnedActor;
    //Funcion para destruir al actor
    //UFUNCTION()
    //void DestroyActorFunction();


    //Tarea Matriz Mapa
public:
    FVector posicionSiguienteBloque= FVector(0,0,0);
    TArray<TArray<int>> aMapaBloques = {{4,4,4,4,4,4,4,4}, {4,0,0,0,0,0,0,4}, {4,3,2,1,3,3,0,4}, {4,0,0,0,1,0,0,4}, {4,0,0,0,0,0,1,4}, {4,4,4,4,4,4,4,4}};
    TArray<class Bloque*> bloques;
    
    void SpawnBloques(FVector posicionInicialX, FVector posicionInicialY,TArray<TArray<int>>& MatrizMapa);
};
