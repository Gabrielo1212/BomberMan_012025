// Fill out your copyright notice in the Description page of Project Settings.


#include "Moneda.h"
#include "../BomberMan_012025GameMode.h"

// Sets default values
AMoneda::AMoneda()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    // Crear el componente de mesh
    MallaMoneda = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaBloque"));
    //
    RootComponent=MallaMoneda;
    MallaMoneda->SetupAttachment(RootComponent);
    // Colocar el mesh
    static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallaMoneda(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Ediciones/Moneda.Moneda'"));

    if (ObjetoMallaMoneda.Succeeded())
    {
        MallaMoneda->SetStaticMesh(ObjetoMallaMoneda.Object);
    }
    
    // Configuraciones
    AnguloMaximoRotacion = 180.0f;
    VelocidadRotacion = 100.0f;
    Direccion = 1;
    Vueltas = 0;
    Ciclos = 0;

}

// Called when the game starts or when spawned
void AMoneda::BeginPlay()
{
	Super::BeginPlay();
    RotacionInicialMoneda = GetActorRotation();
    RotadorMoneda = round(FMath::RandRange(0,1));
    
    // Agrega un temporizador para evitar detecciones múltiples
    TiempoEntreVueltas = 3.0f; // tiempo en segundos entre vueltas completadas
    TiempoUltimaVuelta = 0.0f;
    posicionNueva=GetActorLocation();
    AcumuladorRotacion = 0.0f;
}

// Called every frame
void AMoneda::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    RotacionMoneda = GetActorRotation();
    float Movimiento = VelocidadRotacion * DeltaTime;
    if ((RotacionMoneda.Pitch <= AnguloMaximoRotacion && RotacionMoneda.Pitch >= AnguloMaximoRotacion-20)||
        (RotacionMoneda.Yaw <= AnguloMaximoRotacion && RotacionMoneda.Yaw >= AnguloMaximoRotacion -20)||
        (RotacionMoneda.Roll <= AnguloMaximoRotacion && RotacionMoneda.Roll >= AnguloMaximoRotacion -20))
    {
        if (GetWorld()->GetTimeSeconds() - TiempoUltimaVuelta >= TiempoEntreVueltas)
        {
            Vueltas++;
            TiempoUltimaVuelta = GetWorld()->GetTimeSeconds();
        }
        if(Vueltas==3){
            Direccion *= -1;
            Vueltas = 0;
            Ciclos++;
        }
    }
    if (Ciclos >= 2)
    {
        ABomberMan_012025GameMode* GameMode = GetWorld()->GetAuthGameMode<ABomberMan_012025GameMode>();
        if (GameMode)
        {
            if (GameMode->PosicionesVacias.Num() > 0)
            {
                GameMode->PosicionesVacias.Add(GetActorLocation());
                FVector NuevaPosicion = GameMode->PosicionesVacias[FMath::RandRange(0, GameMode->PosicionesVacias.Num() - 1)];
                CambiarPosicion(NuevaPosicion);
                GameMode->PosicionesVacias.Remove(NuevaPosicion);
            }
            Ciclos = 0;
        }
    }
    
        // Aplicar movimiento en cada eje segun corresponda
    if (RotadorMoneda == 0){
        AcumuladorRotacion+= Direccion * Movimiento;
        RotacionMoneda.Pitch= AcumuladorRotacion;
        SetActorRotation(FRotator(RotacionMoneda.Pitch,0.0f,0.0f));
    }
    if (RotadorMoneda == 1){
        RotacionMoneda.Yaw += Direccion * Movimiento;
        SetActorRotation(RotacionMoneda);
    }
}

void AMoneda::CambiarPosicion(FVector Posicion){
    SetActorLocation(Posicion+FVector(0,0,100));
    Ciclos=0;
}

