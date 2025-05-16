// Fill out your copyright notice in the Description page of Project Settings.


#include "Bloques/BloqueLadrillo.h"
//#include "Components/StaticMeshComponent.h"
//#include "Materials/MaterialInstanceDynamic.h"
//#include "Engine/Texture2D.h"


ABloqueLadrillo::ABloqueLadrillo()
{
    if (MallaBloque)
    {
        static ConstructorHelpers::FObjectFinder<UMaterial> MaterialBase(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Brick_Clay_New.M_Brick_Clay_New'"));
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

void ABloqueLadrillo::BeginPlay()
{
	Super::BeginPlay();

}
void ABloqueLadrillo::ActivarMovimiento_Implementation(){
    if(PuedeMoverse==false){
        PuedeMoverse=true;
    }else{
        PuedeMoverse=false;
    }
}

