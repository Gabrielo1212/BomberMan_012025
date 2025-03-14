// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueConcreto.h"

// Sets default values
ABloqueConcreto::ABloqueConcreto()
{
     // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    MallaBloqueConcreto = CreateDefaultSubobject < UStaticMeshComponent >(TEXT("MallaBloqueConcreto"));
    MallaBloqueConcreto->SetupAttachment(RootComponent);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallaBloqueConcreto(TEXT("/Script/Engine.StaticMesh'/Game/LevelPrototyping/Meshes/SM_Cube.SM_Cube'"));

    if (ObjetoMallaBloqueConcreto.Succeeded())
    {
        MallaBloqueConcreto->SetStaticMesh(ObjetoMallaBloqueConcreto.Object);

        MallaBloqueConcreto->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
    }
    UMaterialInterface* Material = ConstructorHelpers::FObjectFinder<UMaterialInterface>(TEXT("/Game/StarterContent/Materials/M_Concrete_Tiles.M_Concrete_Tiles")).Object;
    if (Material != nullptr)
    {
        MallaBloqueConcreto->SetMaterial(0, Material);
    }


}

// Called when the game starts or when spawned
void ABloqueConcreto::BeginPlay()
{
    Super::BeginPlay();

}

// Called every frame
void ABloqueConcreto::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}
void ABloqueConcreto::SpawnBloquesSeguidos(int numBloques, FVector posicionInicial, FVector direccion) {
    for (int i = 0; i < numBloques; i++) {
        FVector posicion = posicionInicial + direccion * i;
        ABloqueConcreto* bloque = GetWorld()->SpawnActor<ABloqueConcreto>(ABloqueConcreto::StaticClass(), posicion, FRotator(0, 0, 0));
    }
}

void ABloqueConcreto::SpawnBloquesPisos(int numBloquesX,int numBloqueY, FVector posicionInicial, FVector direccion)
{
        for (int i = 0; i < numBloquesX; i++) {
            for(int j=0;j<numBloqueY;j++){
                FVector direccionY = FVector(0, 100, 0);
                FVector posicion = posicionInicial + direccion * i + direccionY * j;
                ABloqueConcreto* bloque = GetWorld()->SpawnActor<ABloqueConcreto>(ABloqueConcreto::StaticClass(), posicion, FRotator(0, 0, 90));
            }
        }
    //ABloqueConcreto* bloque = GetWorld()->SpawnActor<ABloqueConcreto>(ABloqueConcreto::StaticClass(), posicion, FRotator(0, 0, 0));
    //bloque->MallaBloqueConcreto->SetRelativeScale3D(FVector(30.0f, 35.0f, 1.0f));
}
