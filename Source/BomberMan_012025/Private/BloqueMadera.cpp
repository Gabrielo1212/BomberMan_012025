// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueMadera.h"

// Sets default values
ABloqueMadera::ABloqueMadera()
{
     // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    // Crear el componente de mesh
    Mesh =CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent");
    // Establecer la mesh
    auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube\'"));
    UMaterialInterface* Material = ConstructorHelpers::FObjectFinder<UMaterialInterface>(TEXT("/Game/StarterContent/Materials/M_Wood_Floor_Walnut_Polished.M_Wood_Floor_Walnut_Polished")).Object;
    if (Material != nullptr)
    {
        Mesh->SetMaterial(0, Material);
    }
    if (MeshAsset.Object != nullptr)
    {
    Mesh->SetStaticMesh(MeshAsset.Object);
    //tamaño o escala
    Mesh->SetRelativeScale3D(FVector(1.f,1.f, 1.f));
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
