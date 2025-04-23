// Fill out your copyright notice in the Description page of Project Settings.


#include "Bloque.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABloque::ABloque()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    MallaBloque = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaBloque"));
    //RootComponent = MeshComp;
    MallaBloque->SetupAttachment(RootComponent);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallaBloque(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));

    if (ObjetoMallaBloque.Succeeded())
    {
        MallaBloque->SetStaticMesh(ObjetoMallaBloque.Object);

        MallaBloque->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
    }

    FloatSpeed = 5.0f;
    RotationSpeed = 3.0f;

    bPuedeMoverse = FMath::RandBool();
    TipoMovimiento = -1;
    FloatSpeed = 100.0f;
    bPuedeMoverse = false;
    DireccionMovimientoX = 1;
    DireccionMovimientoY = 1;
    DireccionMovimientoZ = 1;
}

void ABloque::BeginPlay()
{
    Super::BeginPlay();
    PosicionInicial = GetActorLocation();
}

void ABloque::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if (bPuedeMoverse)
    {
        FVector Pos = GetActorLocation();
        float Movimiento = FloatSpeed * DeltaTime;
        float RangoMax = 300.0f;
        bool AjustarDireccion = false;

        // Verificar si alcanzó el rango máximo en cualquier eje
        if (FMath::Abs(Pos.X - PosicionInicial.X) >= RangoMax && DireccionMovimientoX != 0)
        {
            DireccionMovimientoX *= -1;
            AjustarDireccion = true;
        }
        if (FMath::Abs(Pos.Y - PosicionInicial.Y) >= RangoMax && DireccionMovimientoY != 0)
        {
            DireccionMovimientoY *= -1;
            AjustarDireccion = true;
        }
        if (FMath::Abs(Pos.Z - PosicionInicial.Z) >= RangoMax && DireccionMovimientoZ != 0)
        {
            DireccionMovimientoZ *= -1;
            AjustarDireccion = true;
        }

        // Aplicar movimiento en cada eje según corresponda
        if (DireccionMovimientoX != 0)
            Pos.X += DireccionMovimientoX * Movimiento;
        if (DireccionMovimientoY != 0)
            Pos.Y += DireccionMovimientoY * Movimiento;
        if (DireccionMovimientoZ != 0)
            Pos.Z += DireccionMovimientoZ * Movimiento;

        SetActorLocation(Pos);
    }
}
