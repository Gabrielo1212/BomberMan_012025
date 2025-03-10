// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

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
    UFUNCTION()
    void DestroyActorFunction();
};
