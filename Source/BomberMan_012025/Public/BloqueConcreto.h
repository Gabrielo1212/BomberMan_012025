#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BloqueConcreto.generated.h"

UCLASS()
class BOMBERMAN_012025_API ABloqueConcreto : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    ABloqueConcreto();
    UFUNCTION()
        void SpawnBloquesSeguidos(int cantidad, FVector posicionInicial, FVector distanciaEntreBloques);
protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY()
    UStaticMeshComponent* MallaBloqueConcreto;
};
