// Fill out your copyright notice in the Description page of Project Settings.


#include "Bloques/BloqueBurbuja.h"

ABloqueBurbuja::ABloqueBurbuja()
{
    if (MallaBloque)
    {
        static ConstructorHelpers::FObjectFinder<UMaterial> MaterialBase(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Basic_Floor.M_Basic_Floor'"));

        if (MaterialBase.Succeeded())
        {
            MallaBloque->SetMaterial(0, MaterialBase.Object); // Asignar el material al slot 0
        }
    }
}

void ABloqueBurbuja::ActivarMovimiento_Implementation(){
    if(PuedeMoverse==false){
        PuedeMoverse=true;
    }else{
        PuedeMoverse=false;
    }
}
