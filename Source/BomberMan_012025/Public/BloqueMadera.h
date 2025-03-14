// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BloqueMadera.generated.h"

UCLASS()
class BOMBERMAN_012025_API ABloqueMadera : public AActor
{
	GENERATED_BODY()
    UStaticMeshComponent* MallaBloqueMadera;
	
public:	
	// Sets default values for this actor's properties
	ABloqueMadera();
    UPROPERTY()
    UStaticMeshComponent* Mesh;
    UFUNCTION()
        void SpawnBloquesSeguidos(int cantidad, FVector posicionInicial, FVector distanciaEntreBloques);
    UFUNCTION()
        void SpawnBloquesMatriz(int numBloquesX,int numBloqueY, FVector posicionInicial,FVector distanciaX,FVector distanciaY);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
