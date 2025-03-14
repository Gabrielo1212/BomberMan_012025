// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Power_Up.generated.h"

UCLASS()
class BOMBERMAN_012025_API APower_Up : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APower_Up();
    UPROPERTY()
    UStaticMeshComponent* Mesh;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
