// Fill out your copyright notice in the Description page of Project Settings.


#include "Bloques/BloqueArena.h"

ABloqueArena::ABloqueArena()
{
    if (MallaBloque)
    {
        static ConstructorHelpers::FObjectFinder<UMaterial> MaterialBase(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Rock_Sandstone.M_Rock_Sandstone'"));
        if (MaterialBase.Succeeded())
        {
            MallaBloque->SetMaterial(0, MaterialBase.Object); // Asignar el material al slot 0
        }
    }
}

//void ABloqueLadrillo::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//}

void ABloqueArena::BeginPlay()
{
    Super::BeginPlay();

}

void ABloqueArena::ActivarMovimiento_Implementation(){
    if(PuedeMoverse==false){
        PuedeMoverse=true;
    }else{
        PuedeMoverse=false;
    }
}

