// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueAcero.h"

// Sets default values
ABloqueAcero::ABloqueAcero()
{
     // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    
    MallaBloqueAcero = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaBloqueAcero"));
    MallaBloqueAcero->SetupAttachment(RootComponent);


    static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallaBloqueAcero(TEXT("/Script/Engine.StaticMesh'/Game/LevelPrototyping/Meshes/SM_Cube.SM_Cube'"));

    if (ObjetoMallaBloqueAcero.Succeeded())
    {
        MallaBloqueAcero->SetStaticMesh(ObjetoMallaBloqueAcero.Object);

        MallaBloqueAcero->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
    }
    UMaterialInterface* Material = ConstructorHelpers::FObjectFinder<UMaterialInterface>(TEXT("/Game/StarterContent/Materials/M_Metal_Burnished_Steel.M_Metal_Burnished_Steel")).Object;
    if (Material != nullptr)
    {
        MallaBloqueAcero->SetMaterial(0, Material);
    }




}
    
    

// Called when the game starts or when spawned
void ABloqueAcero::BeginPlay()
{
    Super::BeginPlay();
    
}

// Called every frame
void ABloqueAcero::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);



}
