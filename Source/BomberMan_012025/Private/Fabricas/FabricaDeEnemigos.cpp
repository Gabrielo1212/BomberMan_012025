// Fill out your copyright notice in the Description page of Project Settings.


#include "Fabricas/FabricaDeEnemigos.h"

// Sets default values
AFabricaDeEnemigos::AFabricaDeEnemigos()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFabricaDeEnemigos::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFabricaDeEnemigos::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AEnemigo* AFabricaDeEnemigos::CrearEnemigoPorClase_Implementation(TSubclassOf<AEnemigo> ClaseDeEnemigo, FVector Posicion, FRotator Rotacion){
    AEnemigo* Enemigo = GetWorld()->SpawnActor<AEnemigo>(ClaseDeEnemigo, Posicion, Rotacion);
    return Enemigo;
}

AEnemigo* AFabricaDeEnemigos::CrearEnemigoPorNumero_Implementation(int TipoDeEnemigo, FVector Posicion, FRotator Rotacion){
    TSubclassOf<AEnemigo> ClaseAInstanciar = nullptr;
    switch (TipoDeEnemigo){
        case 1:ClaseAInstanciar = AEnemigoAereo::StaticClass();break;
        case 2:ClaseAInstanciar = AEnemigoTerrestre::StaticClass();break;
        case 3:ClaseAInstanciar = AEnemigoAcuatico::StaticClass();break;
        case 4:ClaseAInstanciar = AEnemigoSubterraneo::StaticClass();break;
        default:{
            GEngine->AddOnScreenDebugMessage(1, 15.0f, FColor::Yellow,FString::Printf(TEXT("Tipo de enemigo desconocido o no manejado por la fábrica: %d"), TipoDeEnemigo));
            return nullptr; // No se crea ningún bloque si el tipo no es reconocido
        }
    }
    if (ClaseAInstanciar && GetWorld())
    {
        return this->CrearEnemigoPorClase(ClaseAInstanciar, Posicion, Rotacion);
    }
    return nullptr;
}

AEnemigo* AFabricaDeEnemigos::CrearEnemigoAleatoriamente_Implementation(FVector Posicion, FRotator Rotacion){
    int probabilidad=FMath::RandRange(1, 4);
    TSubclassOf<AEnemigo> ClaseAInstanciar = nullptr;
    switch (probabilidad){
        case 1:ClaseAInstanciar = AEnemigoAereo::StaticClass();break;
        case 2:ClaseAInstanciar = AEnemigoTerrestre::StaticClass();break;
        case 3:ClaseAInstanciar = AEnemigoAcuatico::StaticClass();break;
        case 4:ClaseAInstanciar = AEnemigoSubterraneo::StaticClass();break;
        default: return nullptr; break;
    }
    if (ClaseAInstanciar && GetWorld())
    {
        return this->CrearEnemigoPorClase(ClaseAInstanciar, Posicion, Rotacion);
    }
    return nullptr;
}

AEnemigo* AFabricaDeEnemigos::CrearEnemigoProbabilidad_Implementation(FVector Posicion, float ProbabilidadDeSpawnear, FRotator Rotacion){
    float probabilidad = FMath::RandRange(0.0f, 1.0f);
    if (probabilidad < ProbabilidadDeSpawnear/100)
    {
        return this->CrearEnemigoAleatoriamente(Posicion, Rotacion);
    }else{
        return nullptr;
    }
}
