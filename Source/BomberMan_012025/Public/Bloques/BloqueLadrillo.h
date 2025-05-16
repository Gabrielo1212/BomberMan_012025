// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bloque.h"
#include "BloqueLadrillo.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API ABloqueLadrillo : public ABloque
{
	GENERATED_BODY()
public:
	ABloqueLadrillo();
    void ActivarMovimiento_Implementation();
	//virtual void Tick(float DeltaTime) override;
	
protected:
	
	virtual void BeginPlay() override;


};
