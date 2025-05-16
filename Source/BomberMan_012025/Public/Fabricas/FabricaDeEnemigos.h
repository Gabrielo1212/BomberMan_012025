// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemigos/Enemigo.h"
#include "Enemigos/EnemigoTerrestre.h"
#include "Enemigos/EnemigoAcuatico.h"
#include "Enemigos/EnemigoAereo.h"
#include "Enemigos/EnemigoSubterraneo.h"
#include "FabricaDeEnemigos.generated.h"

UCLASS(Blueprintable)
class BOMBERMAN_012025_API AFabricaDeEnemigos : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFabricaDeEnemigos();
    
    UFUNCTION(BlueprintNativeEvent, Category = "Funciones")
    AEnemigo* CrearEnemigoPorClase(TSubclassOf<AEnemigo> ClaseDeEnemigo, FVector Posicion=FVector::ZeroVector, FRotator Rotacion=FRotator::ZeroRotator);
    
    UFUNCTION(BlueprintNativeEvent, Category = "Funciones")
    AEnemigo* CrearEnemigoPorNumero(int TipoDeEnemigo, FVector Posicion=FVector::ZeroVector, FRotator Rotacion=FRotator::ZeroRotator);
    
    UFUNCTION(BlueprintNativeEvent, Category = "Funciones")
    AEnemigo* CrearEnemigoAleatoriamente(FVector Posicion=FVector::ZeroVector, FRotator Rotacion=FRotator::ZeroRotator);
    
    UFUNCTION(BlueprintNativeEvent, Category = "Funciones")
    AEnemigo* CrearEnemigoProbabilidad(FVector Posicion=FVector::ZeroVector, float ProbalidadDeSpawnear=0.1f, FRotator Rotacion=FRotator::ZeroRotator);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
