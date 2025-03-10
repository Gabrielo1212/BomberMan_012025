// Fill out your copyright notice in the Description page of Project Settings.


#include "Power_Up.h"

// Sets default values
APower_Up::APower_Up()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    // Crear el componente de mesh
    Mesh =CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent");
    // Establecer la mesh
    auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/EngineMeshes/Sphere.Sphere\'"));
    if (MeshAsset.Object != nullptr)
    {
    Mesh->SetStaticMesh(MeshAsset.Object);
    // Reducir el tamaño de la malla de esfera
    Mesh->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
    }

}

// Called when the game starts or when spawned
void APower_Up::BeginPlay()
{
	Super::BeginPlay();
    SetLifeSpan(20);
}

// Called every frame
void APower_Up::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

