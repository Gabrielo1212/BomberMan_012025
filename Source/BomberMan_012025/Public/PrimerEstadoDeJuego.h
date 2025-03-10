// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "PrimerEstadoDeJuego.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API APrimerEstadoDeJuego : public AGameState
{
    GENERATED_BODY()
    public:
    //
    APrimerEstadoDeJuego();
    //
    UFUNCTION()
    void SetScore(uint32 NewScore);
    //
    UFUNCTION()
    int32 GetScore();
    
    private:
    //
    UPROPERTY()
    int32 CurrentScore;
};
