// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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
#include "Factory_Bloque.generated.h"

UCLASS()
//Clase abstracta
class BOMBERMAN_012025_API AFactory_Bloque : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFactory_Bloque();
    
    
    //Puntero a la fabrica
    UPROPERTY()
    AFactory_Bloque* MiFabricaDeBloques;
    // El Método de Fábrica
    // Proporciona una interfaz para crear objetos (Bloques)
    // Recibe el tipo de Bloque (la clase concreta) a crear y la posición
    UFUNCTION(BlueprintNativeEvent, Category = "Metodos de la Fabrica")
        ABloque* CrearBloque(TSubclassOf<ABloque> ClaseDeBloques, FVector Posicion=FVector::ZeroVector, FRotator Rotacion=FRotator::ZeroRotator);
    
    UFUNCTION(BlueprintNativeEvent, Category = "Metodos de la Fabrica")
        ABloque* CrearBloquePorNumero(int tipoBloque, FVector Posicion=FVector::ZeroVector, FRotator Rotacion=FRotator::ZeroRotator);

    
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
