// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Moneda.generated.h"

UCLASS()
class BOMBERMAN_012025_API AMoneda : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMoneda();
    
    //Declaracion de variables
    FRotator RotacionInicialMoneda;
    FRotator RotacionMoneda;
    int RotadorMoneda;
    int Direccion;
    int Vueltas;
    int Ciclos;
    float AcumuladorRotacion;
    
    //Tiempo
    float TiempoEntreVueltas;
    float TiempoUltimaVuelta;
    
    //Posicion para cambiar
    FVector posicionNueva;
    
    // Componente de malla estatica
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Componentes")
        UStaticMeshComponent* MallaMoneda;
    
    // Velocidad de rotacion
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Componentes")
        float VelocidadRotacion;
    // Angulo maximo de rotacion
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Componentes")
        float AnguloMaximoRotacion;
    
    void CambiarPosicion(FVector Posicion);
    
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
