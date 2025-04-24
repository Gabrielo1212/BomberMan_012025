// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bloque.generated.h"

class UStaticMeshComponent;

UCLASS()
class BOMBERMAN_012025_API ABloque : public AActor
{
    GENERATED_BODY()
    
public:
    // Sets default values for this actor's properties
    ABloque();
    
    // Posici—n inicial del bloque al comenzar el juego
    FVector PosicionInicial;

    // Control de movimiento
    float Velocidad;              // Velocidad de movimiento
    bool PuedeMoverse;            // ÀDebe moverse?
    float RangoMax;                // Rango de movimiento

    // Direcciones para alternar cuando llegue a los extremos
    int DireccionMovimientoX;
    int DireccionMovimientoY;
    int DireccionMovimientoZ;

    
    // Componente de malla estatica
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Componentes")
        UStaticMeshComponent* MallaBloque;

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;
    

};
