// SamuraiArenaMod.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SamuraiArenaMod.generated.h"

UCLASS()
class ASamuraiArenaMod : public AActor
{
    GENERATED_BODY()

public:
    ASamuraiArenaMod();

protected:
    virtual void BeginPlay() override;

public:
    // Physics-focused duel settings
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float WeaponImpactForce = 900.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float StaggerDuration = 0.35f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ParryWindow = 0.18f;

    UFUNCTION(BlueprintCallable)
    void HandleWeaponCollision(
        AActor* Attacker,
        AActor* Defender,
        FVector ImpactPoint,
        FVector ImpactNormal
    );

private:
    void ApplyStagger(AActor* Defender, FVector Direction);
};