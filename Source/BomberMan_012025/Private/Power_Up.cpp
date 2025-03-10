// Fill out your copyright notice in the Description page of Project Settings.


#include "Power_Up.h"

// Sets default values
APower_Up::APower_Up()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APower_Up::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APower_Up::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

