// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueMadera.h"
#include "BloqueAcero.h"

// Sets default values
ABloqueMadera::ABloqueMadera()
{
     // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    // Crear el componente de mesh
    MallaBloqueMadera = CreateDefaultSubobject < UStaticMeshComponent >(TEXT("MallaBloqueMadera"));
    MallaBloqueMadera->SetupAttachment(RootComponent);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallaBloqueMadera(TEXT("/Script/Engine.StaticMesh'/Game/LevelPrototyping/Meshes/SM_Cube.SM_Cube'"));

    if (ObjetoMallaBloqueMadera.Succeeded())
    {
        MallaBloqueMadera->SetStaticMesh(ObjetoMallaBloqueMadera.Object);

        MallaBloqueMadera->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
    }
    UMaterialInterface* Material = ConstructorHelpers::FObjectFinder<UMaterialInterface>(TEXT("/Game/StarterContent/Materials/M_Wood_Floor_Walnut_Polished.M_Wood_Floor_Walnut_Polished")).Object;
    if (Material != nullptr)
    {
        MallaBloqueMadera->SetMaterial(0, Material);
    }


}


// Called when the game starts or when spawned
void ABloqueMadera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABloqueMadera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ABloqueMadera::SpawnBloquesSeguidos(int cantidad, FVector posicionInicial, FVector distanciaEntreBloques)
{
    for (int i = 0; i < cantidad; i++)
    {
        // Crea un nuevo bloque de madera en la posición inicial + distancia entre bloques * i
        FVector posicion = posicionInicial + distanciaEntreBloques * i;
        ABloqueMadera* bloque = GetWorld()->SpawnActor<ABloqueMadera>(ABloqueMadera::StaticClass(), posicion, FRotator(0, 0, 0));
    }
}

void ABloqueMadera::SpawnBloquesMatriz(int numBloquesX,int numBloqueY, FVector posicionInicial,FVector distanciaX,FVector distanciaY)
{
        for (int i = 0; i < numBloquesX; i++) {
            for(int j=0;j<numBloqueY;j++){
                FVector posicion = posicionInicial + distanciaX * i + distanciaY * j;
                if (!((i == 0 || i == numBloquesX-1) && (j == 0 || j == numBloqueY-1))) {
                    // 60% de probabilidad de spawnear un bloque
                    if (FMath::RandRange(0, 1) < 0.6f) {
                        ABloqueMadera* bloque = GetWorld()->SpawnActor<ABloqueMadera>(ABloqueMadera::StaticClass(), posicion, FRotator(0, 0, 0));
                    }else if(FMath::RandRange(0, 1) < 0.3f){
                        ABloqueAcero* bloqueAcero = GetWorld()->SpawnActor<ABloqueAcero>(ABloqueAcero::StaticClass(), posicion, FRotator(0, 0, 0));
                    }
                }
            }
        }
}
