// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bloques/Bloque.h"
#include "Bloques/BloqueBurbuja.h"
#include "Bloques/BloqueAcero.h"
#include "Bloques/BloqueConcreto.h"
#include "Bloques/BloqueLadrillo.h"
#include "Bloques/BloqueMadera.h"
#include "Bloques/BloquePasto.h"
#include "Bloques/BloqueArena.h"
#include "Bloques/BloqueGrava.h"
#include "Bloques/BloqueCobre.h"
#include "Bloques/BloqueRoble.h"
#include "Bloques/BloqueOro.h"
#include "FabricaDeBloques.generated.h"

UCLASS(Blueprintable)
//Clase abstracta
class BOMBERMAN_012025_API AFabricaDeBloques : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFabricaDeBloques();
    
    // El Método de Fábrica
    // Proporciona una interfaz para crear objetos (Bloques)
    // Recibe el tipo de Bloque (la clase concreta) a crear y la posición
    UFUNCTION(BlueprintNativeEvent, Category = "Metodos de la Fabrica")
        ABloque* CrearBloque(TSubclassOf<ABloque> ClaseDeBloques, FVector Posicion=FVector::ZeroVector, FRotator Rotacion=FRotator::ZeroRotator);
    // Proporciona una interfaz para crear objetos (Bloques)
    // Recibe el tipo de Bloque (en caso que sea con numeros) a crear y la posición
    UFUNCTION(BlueprintNativeEvent, Category = "Metodos de la Fabrica")
        ABloque* CrearBloquePorNumero(int tipoBloque, FVector Posicion=FVector::ZeroVector, FRotator Rotacion=FRotator::ZeroRotator);

    
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
