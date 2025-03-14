// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BloqueAcero.generated.h"

class UStaticMeshComponent;


UCLASS()
class BOMBERMAN_012025_API ABloqueAcero : public AActor
{
    GENERATED_BODY()

    UStaticMeshComponent* MallaBloqueAcero;
    
    
public:
    // Sets default values for this actor's properties
    ABloqueAcero();
    

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    
};
