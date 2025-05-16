// Fill out your copyright notice in the Description page of Project Settings.


#include "Singleton_Main.h"
#include "Inventory.h"

// Sets default values
ASingleton_Main::ASingleton_Main()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASingleton_Main::BeginPlay()
{
	Super::BeginPlay();
    
    //Create 4 Inventory
    for (int i = 0; i <= 4; i++){
        AInventory* SpawnedInventory = GetWorld()->SpawnActor<AInventory>(AInventory::StaticClass());
        if (SpawnedInventory){
        //If the Spawn succeeds, set the Spawned inventory to the local one and log the success string
        Inventory = SpawnedInventory;
        GEngine->AddOnScreenDebugMessage(1, 15.0f, FColor::Yellow,FString::Printf(TEXT("%s has been created"),*Inventory->GetName()));
        }
    }
}

// Called every frame
void ASingleton_Main::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

