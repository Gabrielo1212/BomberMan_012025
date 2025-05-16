// Fill out your copyright notice in the Description page of Project Settings.


#include "Factory_Bloque.h"
#include "Engine/World.h"

// Sets default values
AFactory_Bloque::AFactory_Bloque()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFactory_Bloque::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFactory_Bloque::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

ABloque* AFactory_Bloque::CrearBloque_Implementation(TSubclassOf<ABloque> ClaseDeBloques, FVector Posicion, FRotator Rotacion)
{
    // Validar que se nos ha pasado una clase válida y que tenemos acceso al mundo
    if (!ClaseDeBloques || !GetWorld())
    {
        GEngine->AddOnScreenDebugMessage(1, 15.0f, FColor::Yellow,FString::Printf(TEXT("ABloqueFactory::CrearBloque - Clase de Bloque no válida o World nulo.")));
        return nullptr; // Retorna nulo si no se puede crear
    }
        
        // **** Aquí es donde ocurre la creación del objeto usando el tipo pasado ****
        // Utilizamos SpawnActor para crear un Actor en el mundo de Unreal Engine
    ABloque* NuevoBloque = GetWorld()->SpawnActor<ABloque>(ClaseDeBloques, Posicion, Rotacion);
    
    if (!NuevoBloque)
    {
        GEngine->AddOnScreenDebugMessage(1, 15.0f, FColor::Yellow,FString::Printf(TEXT("ABloqueFactory::CrearBloque - Fallo al crear la instancia del bloque.")));
    }

    return NuevoBloque; // Retorna el puntero al nuevo bloque (como el tipo base ABloque)
}

ABloque* AFactory_Bloque::CrearBloquePorNumero_Implementation(int tipoBloque, FVector Posicion, FRotator Rotacion)
{
    TSubclassOf<ABloque> ClaseAInstanciar = nullptr;

    switch(tipoBloque)
    {
        case 10: ClaseAInstanciar = ABloqueOro::StaticClass(); break;
        case 9: ClaseAInstanciar = ABloqueRoble::StaticClass(); break;
        case 8: ClaseAInstanciar = ABloqueCobre::StaticClass(); break;
        case 7: ClaseAInstanciar = ABloqueGrava::StaticClass(); break;
        case 6: ClaseAInstanciar = ABloqueArena::StaticClass(); break;
        case 5: ClaseAInstanciar = ABloquePasto::StaticClass(); break;
        case 4: ClaseAInstanciar = ABloqueAcero::StaticClass(); break;
        case 3: ClaseAInstanciar = ABloqueConcreto::StaticClass(); break;
        case 2: ClaseAInstanciar = ABloqueLadrillo::StaticClass(); break;
        case 1: ClaseAInstanciar = ABloqueMadera::StaticClass(); break;
        // Si hay otros tipos (como 0 para vacío/enemigo), puedes manejarlos aquí
        default:
            UE_LOG(LogTemp, Warning, TEXT("Tipo de bloque desconocido o no manejado por la fábrica: %d"), tipoBloque);
            return nullptr; // No se crea ningún bloque si el tipo no es reconocido
    }
    // Una vez que el switch ha determinado la clase, la fábrica la spawnea
    if (ClaseAInstanciar && GetWorld())
    {
        return this->CrearBloque(ClaseAInstanciar, Posicion, Rotacion);
    }
    return nullptr;
}
